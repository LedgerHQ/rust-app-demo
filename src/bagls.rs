use crate::bindings::*;

pub type Bagl = bagl_element_t;

const FULL: u32 = 0xffffff;
pub const ICON_CROSS: u8 = BAGL_GLYPH_ICON_CROSS as u8;
pub const ICON_CHECK: u8 = BAGL_GLYPH_ICON_CHECK as u8;

impl Bagl {
  // Instead of initializing everything, we'd rather use
  // ..Default::default(), but as this is a const fn, 
  // it is not allowed
  pub const fn rectangle(dims: (u16, u16), fill: u32) -> Bagl {
    Bagl { 
      component : bagl_component_t { 
        type_:  BAGL_RECTANGLE,
        userid: 0,
        x: 0, y:0,
        width: dims.0,
        height: dims.1,
        stroke:0,
        radius:0,
        fill: fill as u8,
        fgcolor: 0,
        bgcolor: FULL,
        font_id: 0,
        icon_id: 0,
      },
      text: "".as_ptr()
    }
  }

  pub const fn labelline(text: &str, userid: u8, pos: (i16, i16), dims: (u16, u16)) -> Bagl {
    Bagl { 
      component : bagl_component_t { 
        type_:  BAGL_LABELINE,
        userid: userid,
        x: pos.0,
        y: pos.1,
        width: dims.0,
        height: dims.1,
        stroke: 0,
        radius: 0,
        fill: 0,
        fgcolor: FULL, 
        bgcolor: 0, 
        font_id: BAGL_FONT_OPEN_SANS_REGULAR_11px as u16 | BAGL_FONT_ALIGNMENT_CENTER as u16, 
        icon_id: 0,
      },
      text: text.as_ptr()
    }
  }
  
  pub const fn icon(icon: u8, pos: (i16,i16), dims: (u16,u16)) -> Bagl {
    Bagl { 
      component : bagl_component_t { 
        type_:  BAGL_ICON,
        userid: 0,
        x: pos.0,
        y: pos.1,
        width: dims.0,
        height: dims.1,
        stroke:0,
        radius:0,
        fill: 0,
        fgcolor: FULL,
        bgcolor: 0,
        font_id: 0,
        icon_id: icon,
      },
      text: "".as_ptr()
    }
  }
}