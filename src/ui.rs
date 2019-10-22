use crate::bindings::*;

const FLOW_STEP_END: *const ux_flow_step_t = 0xffffffffu32 as *const ux_flow_step_t;

impl ux_layout_nn_params_t {
  const fn new(s1: &str, s2: &str) -> Self {
    ux_layout_nn_params_t {
      line1: s1.as_ptr(),
      line2: s2.as_ptr(),
    }
  }
}

impl ux_flow_step_t {

  const fn new_nn(val: &ux_layout_nn_params_t) -> Self {
    ux_flow_step_t {
      init: Some(ux_layout_nn_init),
      params: val as *const _ as *const core::ffi::c_void,
      validate_flow: core::ptr::null(),
      error_flow: core::ptr::null(),
    }
  }

  const fn new_nn_cb(val: &ux_layout_nn_params_t, validation_flow: *const *const ux_flow_step_t) -> Self {
    ux_flow_step_t {
      init: Some(ux_layout_nn_init),
      params: val as *const _ as *const core::ffi::c_void,
      validate_flow: validation_flow as *const *const ux_flow_step_t,
      error_flow: core::ptr::null(),
    }
  }
}
// Most macros are here to reduce the redundant 
// typing associated with 'const' s.
// 'const' are preferable for ux declarations
// as they are pinned to the flash memory
// and thus avoid the strange us of 'PIC()'
// necessary when dealing with stack addresses

// This macro generates a const 'nn' type flow step
// and takes care of adding a null terminator
// CString should be used for this but is not
// available in no_std for this target.
macro_rules! nn_step {
  ($s1:expr , $s2:expr) => {
    ux_flow_step_t::new_nn(&ux_layout_nn_params_t::new(
      concat!($s1, "\0"),
      concat!($s2, "\0"),
    ))
  };
}

// Declares a 'const' 
macro_rules! cb_step {
  ($name:ident, $func:expr) => {
    const $name : ux_flow_step_t = ux_flow_step_t {
      init: Some($func),
      params: core::ptr::null(),
      validate_flow: core::ptr::null(),
      error_flow: core::ptr::null(),
    };
  };
}

macro_rules! nn_cb_step {
  ($s1:expr, $s2:expr, $cbstep:expr) => {
    ux_flow_step_t::new_nn_cb(
      &ux_layout_nn_params_t::new(concat!($s1, "\0"), concat!($s2, "\0")),
      $cbstep as *const *const ux_flow_step_t,
    )
  };
}

unsafe extern "C" fn sched_exit(_status: u32) {
  os_sched_exit(1);
}

#[no_mangle]
pub extern "C" fn ui_rs_idle() {
  cb_step!(exit_cb, sched_exit); 

  const exit_step: [*const ux_flow_step_t;2] = [&exit_cb, FLOW_STEP_END];

  const steps: [*const ux_flow_step_t;5] = [
      &nn_step!("This App", "is in Rust"),
      &nn_step!("and this is", "a 'flow' menu"),
      &nn_step!("introduced in", "SDK 1.6   "),
      &nn_cb_step!("", "Quit", &exit_step),
      FLOW_STEP_END
    ];

  unsafe {
    if G_ux.stack_count == 0 {
      ux_stack_push();
    }
    ux_flow_init(0, steps.as_ptr(), core::ptr::null());
  }
}
