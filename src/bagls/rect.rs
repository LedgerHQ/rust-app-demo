use crate::bindings::*;

#[derive(Copy, Clone)]
pub struct Rect {
  pub pos: (u16,u16),
  pub dims: (u16,u16),
  pub colors: (u32, u32), 
  pub fill: bool,
  pub userid: u8
}

impl Rect {
  pub const fn new() -> Rect {
    Rect {pos: (32-5, 64-5), dims: (10,10), colors: (0xffffffu32, 0), fill:false, userid:0}
  }
  pub const fn pos(self, x: u16, y: u16) -> Rect {
    Rect {pos: (x,y), ..self}
  }
  pub const fn colors(self, fg: u32, bg: u32) -> Rect {
    Rect {colors: (fg,bg), ..self}
  }
  pub const fn dims(self, w: u16, h: u16) -> Rect {
    Rect {dims: (w,h), ..self}
  }
  pub const fn fill(self, x: bool) -> Rect {
    Rect {fill: x, ..self}
  }
  pub const fn userid(self, id: u8) -> Rect {
    Rect {userid: id, ..self}
  }
}

impl From<Rect> for bagl_element_t {
  fn from(rect: Rect) -> bagl_element_t {
    bagl_element_t {
      component: bagl_component_t {
        type_: BAGL_RECTANGLE,
        userid: 0,  // FIXME
        x: 0,
        y: 0,
        width: rect.dims.0,
        height: rect.dims.1,
        stroke: 0,
        radius: 0,
        fill: rect.fill as u8,
        fgcolor: 0xffffffu32,
        bgcolor: 0,
        font_id: 0,
        icon_id: 0,
      },
      text: core::ptr::null(),
    }
  }
}