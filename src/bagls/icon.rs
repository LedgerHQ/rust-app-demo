use crate::bindings::*;
use crate::bagls::ICON_CHECK;

#[derive(Copy, Clone)]
pub struct Icon {
  pub pos: (i16, i16),
  pub glyph_id: u8
}

impl Icon {
  pub const fn new() -> Icon {
    Icon {
      pos: (12, 12),
      glyph_id: ICON_CHECK 
    }
  }
}

impl From<Icon> for bagl_element_t {
  fn from(icon: Icon) -> bagl_element_t {
    bagl_element_t {
      component: bagl_component_t {
        type_: BAGL_ICON,
        userid: 0,
        x: icon.pos.0,
        y: icon.pos.1,
        width: 0,
        height: 0,
        stroke: 0,
        radius: 0,
        fill: 0,
        fgcolor: 0xffffffu32,
        bgcolor: 0,
        font_id: 0,
        icon_id: icon.glyph_id,
      },
      text: core::ptr::null(),
    }
  }
}