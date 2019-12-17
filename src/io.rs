use crate::bindings::*;
use core::ops::{Index, IndexMut};

#[derive(Copy, Clone)]
pub enum StatusWords {
    OK = 0x9000,
    NothingReceived = 0x6982,
    BadCLA = 0x6e00,
    Unknown = 0x6d00,
    InternalError = 0x77aa,
}

#[derive(Copy, Clone)]
pub struct Comm {
    pub apduBuffer: [u8; 260],
    pub rx: usize,
    pub tx: usize,
}

impl Comm {
    pub fn new() -> Comm {
       Comm { apduBuffer: [0u8; 260], rx: 0, tx: 0 } 
    }

    pub fn io_exch(&mut self, flags: u8) {
        let apdu_buf = apdu_buffer_t {
                            buf: self.apduBuffer.as_mut_ptr(),
                            len: self.apduBuffer.len() as u16
                    };
        self.rx = unsafe{ io_exchange(flags, apdu_buf, self.tx as u16) } as usize;
        self.tx = 0;
    }

    pub fn set_status_word(&mut self, sw: StatusWords) {
        self.apduBuffer[self.tx] = ((sw as u16) >> 8) as u8;
        self.apduBuffer[self.tx + 1] = sw as u8;
        self.tx += 2;
    }

    pub fn get_cla_ins(&self) -> (u8, u8) {
        (self.apduBuffer[0], self.apduBuffer[1])
    }

    pub fn get(&self, start: usize, end: usize) -> &[u8] {
        &self.apduBuffer[start..end]
    }
}

impl Index<usize> for Comm {
    type Output = u8;
    fn index(&self, idx: usize) -> &Self::Output {
        &self.apduBuffer[idx]
    }
}

impl IndexMut<usize> for Comm {
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        self.tx += 1;
        &mut self.apduBuffer[idx]
    }
}

#[no_mangle]
pub extern "C" fn io_exchange_al(channel: u8, tx_len: u16, apdubuf: apdu_buffer_t) -> u16 {
    if channel == CHANNEL_SPI as u8 {
        if tx_len != 0 {
            unsafe{ io_seph_recv(apdubuf.buf, tx_len, 0) };
            return 1
        } else {
            return unsafe{ io_seph_recv(apdubuf.buf, 256, 0) };
        }
    } else {
        return 0;
    }
}
