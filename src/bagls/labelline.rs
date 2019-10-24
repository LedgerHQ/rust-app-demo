use crate::bindings::*;

#[derive(Copy, Clone)]
pub struct LabelLine {
  pub pos: (i16, i16),
  pub dims: (u16, u16),
  pub text: &'static str
}

impl LabelLine {
  pub const fn new() -> LabelLine {
    LabelLine {
      pos: (32, 0),
      dims: (10, 10),
      text: "Test Str\0"
    }
  }

  pub const fn pos(self, x: i16, y: i16) -> LabelLine {
    LabelLine {pos: (x,y), ..self}
  }
  pub const fn dims(self, w: u16, h: u16) -> LabelLine {
    LabelLine {dims: (w,h), ..self}
  }
}

impl From<LabelLine> for bagl_element_t {
  fn from(labelline: LabelLine) -> bagl_element_t {
    bagl_element_t {
      component: bagl_component_t {
        type_: BAGL_LABELINE,
        userid: 0,  // FIXME
        x: labelline.pos.0,
        y: labelline.pos.1,
        width: labelline.dims.0,
        height: labelline.dims.1,
        stroke: 0,
        radius: 0,
        fill: 0,
        fgcolor: 0xffffffu32,
        bgcolor: 0,
        font_id: BAGL_FONT_OPEN_SANS_REGULAR_11px as u16 | BAGL_FONT_ALIGNMENT_CENTER as u16,
        icon_id: 0,
      },
      text: labelline.text.as_ptr(), // FIXME
    }
  }
}