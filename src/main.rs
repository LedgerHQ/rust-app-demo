#![no_std]
#![no_main]
#![feature(asm)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![feature(const_fn)]

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


#[no_mangle]
extern "C" {
    fn c_main();
}

#[link_section = ".boot"]
#[no_mangle]
pub extern "C" fn _start() -> ! {
    // Main is in C until the try_context can be set properly
    // from Rust
    unsafe { c_main() };
    unsafe { os_sched_exit(1) };
    loop {}
}
