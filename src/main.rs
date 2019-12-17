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

/// In case of runtime problems,
/// return an internal error and exit
/// the app
#[panic_handler]
fn panic(_: &PanicInfo) -> ! {
    let mut comm = io::Comm::new();
    comm.set_status_word(io::StatusWords::InternalError);
    comm.io_exch(0);
    unsafe { os_sched_exit(1) };
    loop {}
}


/// Example crypto call
/// safe (?) wrapper
fn sha256(m: &[u8]) -> [u8; 32] {
    let mut out = [0u8; 32];
    unsafe {
        cx_hash_sha256(m.as_ptr(), m.len() as u32, out.as_mut_ptr(), 32);
    }
    out
}

#[no_mangle]
extern "C" fn sample_main() {
    let mut comm = io::Comm::new();
    let mut flags = 0u8;

    loop {
        comm.io_exch(flags);
        flags = 0;

        if comm.rx == 0 {
            comm.set_status_word(io::StatusWords::NothingReceived);
            continue;
        }

        let (cla, ins) = comm.get_cla_ins();

        if cla != 0x80 {
            comm.set_status_word(io::StatusWords::BadCLA);
            continue;
        }

        match ins {
            0x00 => {
                flags |= IO_RESET_AFTER_REPLIED as u8;
                comm.set_status_word(io::StatusWords::OK)
            },
            0x01 => comm.set_status_word(io::StatusWords::OK),
            0x02 => {
                comm.tx = comm.rx;
                comm.set_status_word(io::StatusWords::OK)
            },
            0x03 => {
                let len = u16::from_le_bytes([comm[2], comm[3]]) as usize;
                let out = sha256(&comm.get(4, len));
                
                for (i, e) in out.iter().enumerate() {
                    comm[i] = *e;
                }
                comm.set_status_word(io::StatusWords::OK)
            },
            0xff => {unsafe { os_sched_exit(0) };},
            _ => comm.set_status_word(io::StatusWords::Unknown),
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
