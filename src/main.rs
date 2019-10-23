#![no_std]
#![no_main]
#![feature(asm)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![feature(const_fn)]

pub mod bagls;
pub mod bindings;
pub mod io;
pub mod ui;
use bindings::*;

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_: &PanicInfo) -> ! {
    loop {}
}


// Example crypto call
fn sha256(m: &[u8]) -> [u8; 32] {
    let mut out = [0u8; 32];
    unsafe {
        cx_hash_sha256(m.as_ptr(), m.len() as u32, out.as_mut_ptr(), 32);
    }
    out
}

#[no_mangle]
extern "C" fn sample_main() {
    let mut tx = 0u16;
    let mut flags = 0u8;

    loop {
        let mut rx = tx;
        tx = 0;

        rx = io::io_exch(flags, rx);
        flags = 0;

        if rx == 0 {
            tx = io::set_status_word(tx, io::StatusWords::NothingReceived);
            continue;
        }

        let (cla, ins) = io::get_cla_ins();

        if cla != 0x80 {
            tx = io::set_status_word(tx, io::StatusWords::BadCLA);
            continue;
        }

        tx = match ins {
            0x00 => {
                flags |= IO_RESET_AFTER_REPLIED as u8;
                io::set_status_word(tx, io::StatusWords::OK)
            },
            0x01 => io::set_status_word(tx, io::StatusWords::OK),
            0x02 => {
                tx = rx;
                io::set_status_word(tx, io::StatusWords::OK)
            },
            0x03 => {
                let len = unsafe{ u16::from_le_bytes([G_io_apdu_buffer[2], G_io_apdu_buffer[3]]) };
                let buf: &[u8] = unsafe{ &G_io_apdu_buffer[4..len as usize] };
                let out = sha256(buf);

                for (i, e) in out.iter().enumerate() {
                    unsafe { G_io_apdu_buffer[i] = *e };
                }
                io::set_status_word(32, io::StatusWords::OK)
            },
            0xff => {
                unsafe { os_sched_exit(0) };
                0
            },
            _ => io::set_status_word(tx, io::StatusWords::Unknown),
        };
    }
}


// Below is a sketch for a Rusty 'main'
// with failed attempts included

// #[link_section = ".boot"]
// #[no_mangle]
// pub extern "C" fn _start() -> ! {
//    let mut my_context: try_context_s = try_context_s {
//         jmp_buf: [0u32; 10],
//         previous: &mut try_context_s::default(),
//         ex: 0
//     };

//     unsafe {
//         asm!("cpsie i");
//         // ux_init(&mut ux);
//         os_boot();
//     }

//     // my_context.jmp_buf =
//     // let jmp_buf_tr = unsafe{ core::mem::transmute::<&mut[u32;10], &mut[i8;40]>(&mut (*my_context).jmp_buf) };
//     // let jmp_buf_tr = core::mem::transmute::<&mut[u32;10], &mut[u8;40]>(&mut my_context.jmp_buf);
//     // let res = unsafe{ setjmp(jmp_buf_tr.as_mut_ptr()) };
//     let res = unsafe{ setjmp(my_context.jmp_buf.as_mut_ptr()) };

//     if res == 0
//     {
//         unsafe {
//             // my_context.previous = try_context_set(my_context);
//             my_context.previous = try_context_set(&mut my_context);

//             io_seproxyhal_init();

//             USB_power(0);
//             USB_power(1);

//             // ui_idle(&mut ux);
//             ui_c_idle();
//         }
//         sample_main();
//     } else {
//        io::set_status_word(0, io::StatusWords::InternalError);
//        io::io_exch(0, 2);
//     }
//     unsafe{ os_sched_exit(1) };
//     loop{};
// }
