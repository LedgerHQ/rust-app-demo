use crate::bindings::*;

#[no_mangle]
pub static mut G_io_seproxyhal_spi_buffer: &[u8] = &[0; 128];

#[derive(Copy, Clone)]
pub enum StatusWords {
    OK = 0x9000,
    NothingReceived = 0x6982,
    BadCLA = 0x6e00,
    Unknown = 0x6d00,
    InternalError = 0x77aa,
}

pub fn io_exch(flags: u8, length: u16) -> u16 {
    unsafe{ io_exchange(flags, length) }
}

pub fn set_status_word(current_length: u16, sw: StatusWords) -> u16 {
    unsafe{ 
        G_io_apdu_buffer[current_length as usize] = ((sw as u16) >> 8) as u8;
        G_io_apdu_buffer[(current_length+1) as usize] = sw as u8;
    }
    current_length + 2
}


pub fn get_cla_ins() -> (u8, u8) {
    (unsafe{G_io_apdu_buffer[0]}, unsafe{G_io_apdu_buffer[1]})
}


#[no_mangle]
pub extern "C" fn io_exchange_al(channel: u8, tx_len: u16) -> u16 {
    if channel == CHANNEL_SPI as u8 {
        if tx_len != 0 {
            // SDK 1.5 
            // unsafe{ io_seproxyhal_spi_send(G_io_apdu_buffer.as_ptr(), tx_len) };
            unsafe{ io_seph_recv(G_io_apdu_buffer.as_mut_ptr(), tx_len, 0) };
            return 1
        } else {
            // SDK 1.5 
            // return unsafe{ io_seproxyhal_spi_recv(G_io_apdu_buffer.as_mut_ptr(), 256, 0) }
            return unsafe{ io_seph_recv(G_io_apdu_buffer.as_mut_ptr(), 256, 0) }
        }
    } else {
        return 0
    }
}

