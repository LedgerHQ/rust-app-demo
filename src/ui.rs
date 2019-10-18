use crate::bindings::*;

impl ux_flow_step_t {
  const fn new_nn(val: &ux_layout_nn_params_t) -> Self {
    ux_flow_step_t {
            init: Some(ux_layout_nn_init),
            params: val as *const _ as *const core::ffi::c_void,
            validate_flow: core::ptr::null(),
            error_flow: core::ptr::null()
    }
  }
}

impl ux_layout_nn_params_t {
  const fn new(s1: &str, s2: &str) -> Self {
    ux_layout_nn_params_t {
      line1: s1.as_ptr(),
      line2: s2.as_ptr()
    }
  }
}

// This macro generates a const 'nn' type flow step
// and takes care of adding a null terminator
// CString should be used for this but is not 
// available in no_std for this target.
macro_rules! nn_step {
  ($s1:expr , $s2:expr) => {
    ux_flow_step_t::new_nn(&ux_layout_nn_params_t::new(concat!($s1, "\0"), concat!($s2, "\0")))
  };
}

#[no_mangle]
pub extern "C" fn ui_rs_idle()
{
  const steps: [*const ux_flow_step_t;4] = [
    &nn_step!("This App", "is in Rust"),
    &nn_step!("and this is", "a 'flow' menu"),
    &nn_step!("introduced in", "SDK 1.6"),
    0xffffffffu32 as *const ux_flow_step_t // FLOW_END_STEP
  ];
  
  unsafe {
      if G_ux.stack_count == 0 {
          ux_stack_push();
      }
      ux_flow_init(0, steps.as_ptr(), core::ptr::null()); 
  }
}
