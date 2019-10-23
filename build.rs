extern crate cc;
use std::env;
use std::fs::File;
use std::process::Command;
use std::io::Write;
use std::path::Path;

fn main() {
    let bolos_sdk = env::var("BOLOS_SDK").unwrap_or("./nanosdk_1.6/".to_string());
    let gcc_toolchain = env::var("GCC_PATH").expect("Please specify a valid GCC toolchain in your GCC_PATH environment variable");

    #[cfg(windows)]
    let output = Command::new("python").arg(&format!("./{}/icon3.py", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_down.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_left.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_right.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_up.gif", bolos_sdk))
                          .arg("--glyphcfile")
                          .output()
                          .expect("failed"); 

    #[cfg(unix)]
    let output = Command::new(&format!("./{}/icon3.py", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_down.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_left.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_right.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_up.gif", bolos_sdk))
                          .arg("--glyphcfile")
                          .output()
                          .expect("failed"); 

    let main_path = format!("{}/lib_ux/glyphs/", bolos_sdk);
    let dest_path = Path::new(&main_path);
    let mut f = File::create(&dest_path.join("glyphs.c")).unwrap();

    f.write_all(&output.stdout).unwrap();

    println!("{:?}", output.stderr);

    let output = Command::new("python").arg(&format!("{}/icon3.py", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_down.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_left.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_right.gif", bolos_sdk))
                          .arg(&format!("{}/lib_ux/glyphs/icon_up.gif", bolos_sdk))
                          .arg("--glyphcheader")
                          .output()
                          .expect("failed"); 
     
    let dest_path = Path::new(&main_path);
    let mut f = File::create(&dest_path.join("glyphs.h")).unwrap();
    f.write_all(&output.stdout).unwrap();
 
    println!("{:?}", output.stderr);
    assert!(output.status.success());

    cc::Build::new()
        .compiler("clang")
        .archiver("arm-none-eabi-gcc-ar")
        .target("thumbv6m-none-eabi")
        .file("./src/c/src.c")
        .file("./src/c/sjlj.s")
        .file(format!("{}/src/os.c", bolos_sdk))
        .file(format!("{}/src/os_printf.c", bolos_sdk))
        .file(format!("{}/src/os_io_seproxyhal.c", bolos_sdk))
        .file(format!("{}/src/os_io_usb.c", bolos_sdk))
        .file(format!("{}/src/pic.c", bolos_sdk))
        .file(format!("{}/src/syscalls.c", bolos_sdk))
        .file(format!("{}/src/tcr.c", bolos_sdk))
        .file(format!("{}/lib_ux/src/ux_flow_engine.c", bolos_sdk))
        .file(format!("{}/lib_ux/src/ux_stack.c", bolos_sdk))
        .file(format!("{}/lib_ux/src/ux_menulist.c", bolos_sdk))
        .file(format!("{}/lib_ux/src/ux_layout_nn.c", bolos_sdk))
        .file(format!("{}/lib_ux/src/ux_layout_bb.c", bolos_sdk))
        .file(format!("{}/lib_ux/src/ux_layout_utils.c", bolos_sdk))

        // Other files need to be added, e.g. for other ux layouts

        .file(format!("{}/lib_ux/glyphs/glyphs.c", bolos_sdk))
        .file(format!("{}/lib_stusb/usbd_conf.c", bolos_sdk))
        .file(format!("{}/lib_stusb/STM32_USB_Device_Library/Core/Src/usbd_core.c", bolos_sdk))
        .file(format!("{}/lib_stusb/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c", bolos_sdk))
        .file(format!("{}/lib_stusb/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c", bolos_sdk))
        .file(format!("{}/lib_stusb_impl/usbd_impl.c", bolos_sdk))
        .file(format!("{}/lib_stusb/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.c", bolos_sdk))

        // The following flags should be the same as in wrapper
        //TODO : try to get rid of the flags in wrapper.h by using
        //      bindgen from within build.rs 
        .define("ST31", None)
        .define("IO_HID_EP_LENGTH", Some("64"))
        .define("USB_SEGMENT_SIZE", Some("64"))
        .define("TARGET_NAME", Some("TARGET_NANOS"))
        .define("UI_NANO_S", None)
        .define("OS_IO_SEPROXYHAL", None)
        .define("HAVE_BAGL", None)
        .define("HAVE_SPRINTF", None)
        .define("HAVE_PRINTF", None)
        .define("PRINTF", "screen_printf")
        .define("HAVE_IO_USB", None)
        .define("HAVE_L4_USBLIB", None)
        .define("HAVE_USB_APDU", None)
        .define("HAVE_UX_FLOW", None)
        .define("IO_USB_MAX_ENDPOINTS", Some("6"))
        .define("IO_SEPROXYHAL_BUFFER_SIZE_B", Some("128"))

        .include(format!("{}/arm-none-eabi/include", gcc_toolchain))

        .include(format!("{}/include", bolos_sdk))
        .include(format!("{}/lib_ux/", bolos_sdk))
        .include(format!("{}/lib_ux/glyphs", bolos_sdk))
        .include(format!("{}/lib_ux/include", bolos_sdk))
        .include(format!("{}/lib_stusb", bolos_sdk))
        .include(format!("{}/lib_stusb_impl", bolos_sdk))
        .include(format!("{}/lib_stusb/STM32_USB_Device_Library/Core/Inc", bolos_sdk))
        .include(format!("{}/lib_stusb/STM32_USB_Device_Library/Class/HID/Inc", bolos_sdk))

        // More or less same flags as in the
        // C SDK Makefile.defines
        .no_default_flags(true)
        .pic(true)
        .flag("--target=thumbv6m-none-eabi")
        .flag("-fomit-frame-pointer")
        .flag("-momit-leaf-frame-pointer")
        .flag("-mcpu=cortex-m0")
        .flag("-fno-common")
        .flag("-fdata-sections")
        .flag("-ffunction-sections")
        .flag("-mtune=cortex-m0")
        .flag("-mthumb")
        .flag("-fropi")
        .flag("-fno-jump-tables")
        .flag("-fno-builtin")
        .flag("-fshort-enums")
        .flag("-mno-unaligned-access")

        // Lots of warning deactivation to avoid
        // being spammed by the C SDK
        .flag("-Wno-unused-parameter")
        .flag("-Wno-implicit-fallthrough")
        .flag("-Wno-sign-compare")
        .flag("-Wno-unknown-pragmas")
        .flag("-Wno-unknown-attributes")
        .flag("-Wno-missing-declarations")
        .flag("-Wno-unused-command-line-argument")
        .flag("-Wno-pointer-sign")
        .flag("-Wno-implicit-function-declaration")
        .flag("-Wno-tautological-pointer-compare")
        .flag("-Wno-incompatible-pointer-types-discards-qualifiers")
        .flag("-Wno-duplicate-decl-specifier")
        .flag("-Wno-#warnings")
        .flag("-Wno-int-conversion")

        .compile("rust-app");
}
