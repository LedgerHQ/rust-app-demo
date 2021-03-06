DEPRECATED: Now obsolete in favour of [this new demo](https://github.com/LedgerHQ/rust-app) that uses an improved structure and a Rust UI.


# Rust bindings to the SDK and app

Hybrid of Ledger's SDK that will allow incrementally replacing parts of the C SDK with safer Rust code.

This project allows you to develop an app for Nano S in Rust.

## Installation

Installation requires adding a toolchain to your Rust installation, and both Clang and arm-none-eabi-gcc.
The minimum required rustc version is 1.40.0.

- `rustup target add thumbv6m-none-eabi`
- install [Clang](http://releases.llvm.org/download.html).
- install an [ARM GCC toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

## Building

You can build on either Windows or Linux with a simple `cargo build` or `cargo build --release`

If you want to use a specific SDK (once you have generated the bindings), use:
`export BOLOS_SDK=/path/to/sdk/; cargo build`

By default, the SDK available as a submodule in this project will be used if `BOLOS_SDK` is not specified.

## Testing

One can for example use [speculos](https://github.com/LedgerHQ/speculos)

`cargo run` defaults to running speculos on the generated binary with the appropriate flags, if `speculos.py` is in your `PATH`.

On a real device, you can use the loading script `load.py`.

There is a small test script that sends some of the available commands in `test/test_cmds.py`

## Generating the bindings 

Pregenerated bindings to the sdk as a subrepo are already available for this project (in `./src/bindings.rs`).

If you want to use another SDK, you can use `bindgen`: 

`cargo install bindgen`

Those can be generated by copy-pasting `wrapper.h` in the root of this directory to the root of the SDK, and then using the following command :

`TARGET=thumbv6m-none-eabi bindgen wrapper.h --use-core --no-prepend-enum-name --no-doc-comments --with-derive-default --no-derive-debug --ctypes-prefix=cty -- -fshort-enums -Ilib_ux/include -I. > bindings.rs`

Then, copy `bindings.rs` into the `src` folder of this project.

Note that `wrapper.h` contains flag definitions that might not match with your expected app configuration. You can change those before generating the bindings.

## What's next

The goal would be to reduce the C part as much as possible, and make every feature of the C SDK easily available in Rust. This means taking care of some macros that are not exported in the bindings.

There are some parts that could be simplified in `build.rs` also.

Lots of code could be reused from this great project: [Rust BOLOS 3rd party SDK](https://github.com/roosmaa/bolos-rs) by @roosmaa which unfortunately does not seem to be functioning or maintained. 
