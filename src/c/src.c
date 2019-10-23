#include "os.h"
#include "os_io_seproxyhal.h"
#include "stdint.h"

uint8_t G_io_seproxyhal_spi_buffer[128];

// Yup...
size_t strlen(const char * str) {
  char * s = str;
  unsigned short len = 0;
  while (*s++)
    len++;
  return len;
}

unsigned int pic_internal(unsigned int link_address) __attribute__((naked));

#ifdef _GCC_
unsigned int pic_internal(unsigned int link_address) 
{
  // compute the delta offset between LinkMemAddr & ExecMemAddr
  __asm volatile ("mov r2, pc\n");          // r2 = 0x109004
  __asm volatile ("ldr r1, =pic_internal\n");        // r1 = 0xC0D00001
  __asm volatile ("add r1, r1, #3\n");     // r1 = 0xC0D00004
  __asm volatile ("sub r1, r1, r2\n");     // r1 = 0xC0BF7000 (delta between load and exec address)

  // adjust value of the given parameter
  __asm volatile ("sub r0, r0, r1\n");     // r0 = 0xC0D0C244 => r0 = 0x115244
  __asm volatile ("bx lr\n");
}
#else
unsigned int pic_internal(unsigned int link_address) 
{
  // compute the delta offset between LinkMemAddr & ExecMemAddr
  __asm volatile ("mov r2, pc\n");          // r2 = 0x109004
  __asm volatile ("ldr r1, =pic_internal\n");        // r1 = 0xC0D00001
  __asm volatile ("adds r1, r1, #3\n");     // r1 = 0xC0D00004
  __asm volatile ("subs r1, r1, r2\n");     // r1 = 0xC0BF7000 (delta between load and exec address)

  // adjust value of the given parameter
  __asm volatile ("subs r0, r0, r1\n");     // r0 = 0xC0D0C244 => r0 = 0x115244
  __asm volatile ("bx lr\n");
}
#endif

unsigned char io_event(unsigned char channel) {
    // nothing done with the event, throw an error on the transport layer if
    // needed

    // can't have more than one tag in the reply, not supported yet.
    switch (G_io_seproxyhal_spi_buffer[0]) {
    case SEPROXYHAL_TAG_FINGER_EVENT:
        UX_FINGER_EVENT(G_io_seproxyhal_spi_buffer);
        break;

    case SEPROXYHAL_TAG_BUTTON_PUSH_EVENT: // for Nano S
        UX_BUTTON_PUSH_EVENT(G_io_seproxyhal_spi_buffer);
        break;

    case SEPROXYHAL_TAG_DISPLAY_PROCESSED_EVENT:
        if (UX_DISPLAYED()) {
            // TODO perform actions after all screen elements have been
            // displayed
        } else {
            UX_DISPLAYED_EVENT();
        }
        break;

    // unknown events are acknowledged
    default:
        break;
    }

    // close the event if not done previously (by a display or whatever)
    if (!io_seproxyhal_spi_is_status_sent()) {
        io_seproxyhal_general_status();
    }

    // command has been processed, DO NOT reset the current APDU transport
    return 1;
}

void io_seproxyhal_display(const bagl_element_t *element) {
    io_seproxyhal_display_default((bagl_element_t *)element);
}

ux_state_t G_ux;
bolos_ux_params_t G_ux_params;

extern void ui_rs_idle();
extern void sample_main();

// __attribute__((section(".boot"))) int main(void) {
int c_main(void) {
  // exit critical section
  __asm volatile("cpsie i");

  // ensure exception will work as planned
  os_boot();
  for(;;) {
    UX_INIT();

    BEGIN_TRY {
      TRY {
      
        //start communication with MCU
        io_seproxyhal_init();

        USB_power(0);
        USB_power(1);
  
        //set up initial screen
        ui_rs_idle();

        sample_main();
      }
      CATCH(EXCEPTION_IO_RESET) {
                // reset IO and UX
        continue;
      }
      CATCH_ALL {
        break;
      }
      FINALLY {
      }
    }
    END_TRY;
  }
//   app_exit();
    return 0;
}