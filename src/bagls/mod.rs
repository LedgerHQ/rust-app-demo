pub mod button;
pub mod circle;
pub mod icon;
pub mod label;
pub mod labelline;
pub mod line;
pub mod rect;

use crate::bindings::*;
use button::*;
use circle::*;
use icon::*;
use label::*;
use labelline::*;
use line::*;
use rect::*;

// const FULL: u32 = 0xffffff;
pub const ICON_CROSS: u8 = BAGL_GLYPH_ICON_CROSS as u8;
pub const ICON_CHECK: u8 = BAGL_GLYPH_ICON_CHECK as u8;

#[derive(Copy, Clone)]
pub enum Bagl {
  BUTTON(Button),
  LABEL(Label),
  LABELLINE(LabelLine),
  RECT(Rect),
  LINE(Line),
  ICON(Icon),
  CIRCLE(Circle),
}

impl From<Bagl> for bagl_element_t {
  fn from(x: Bagl) -> bagl_element_t {
    match x {
      // Bagl::LABEL(y) => bagl_element_t::from(y),
      Bagl::LABELLINE(y) => bagl_element_t::from(y),
      Bagl::RECT(y) => bagl_element_t::from(y),
      // Bagl::LINE(y) => bagl_element_t::from(y),
      Bagl::ICON(y) => bagl_element_t::from(y),
      // Bagl::CIRCLE(y) => bagl_element_t::from(y),
      _ => bagl_element_t::default()
    }
  }
}



// fn ui_idle(uxx: &mut ux_state_t) {
//   // UX_DISPLAY(bagl_ui_sample_nanos, NULL);

//   const bagl_ui_sample_nanos: &[Bagl] = &[
//     Bagl::rectangle((128, 32), BAGL_FILL),
//     Bagl::labelline("Hello World\0", 1, (0, 12), (128, 32)),
//     Bagl::icon(bagls::ICON_CROSS, (3, 12), (7, 7)),
//     Bagl::icon(bagls::ICON_CHECK, (117, 13), (8, 6)),
//   ];
//   uxx.elements = &bagl_ui_sample_nanos[0];
//   uxx.elements_count = bagl_ui_sample_nanos.len() as u32;
//   uxx.button_push_handler = Some(bagl_ui_sample_nanos_button);
//   uxx.elements_preprocessor = None;
//   uxx.params.ux_id = BOLOS_UX_WAKE_UP; // UX_WAKE_UP();
//   uxx.params.len = 0;

//   unsafe{
//       uxx.params.len = os_ux(&mut uxx.params);
//       ux_check_status(uxx.params.len);
//       io_seproxyhal_init_ux(); // UX_REDISPLAY() UX_REDISPLAY_INDEX(0)
//       io_seproxyhal_init_button();
//   }

//   uxx.elements_current = 0;
//   if uxx.params.len != BOLOS_UX_IGNORE && uxx.params.len != BOLOS_UX_CONTINUE
//   {   //UX_DISPLAY_NEXT_ELEMENT();
//     //   while uxx.elements_current < uxx.elements_count && unsafe{ io_seproxyhal_spi_is_status_sent() } == 0
//     //   {
//     //       let element = &bagl_ui_sample_nanos[uxx.elements_current as usize];
//     //       unsafe{ io_seproxyhal_display(element) };
//     //       uxx.elements_current += 1;
//     //   }

//     for e in bagl_ui_sample_nanos {
//         unsafe{ io_seproxyhal_display(e) };
//     }
//   }
// }
