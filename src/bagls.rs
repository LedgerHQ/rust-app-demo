use crate::bindings::*;

pub type Bagl = bagl_element_t;

const FULL: u32 = 0xffffff;
pub const ICON_CROSS: u8 = BAGL_GLYPH_ICON_CROSS as u8;
pub const ICON_CHECK: u8 = BAGL_GLYPH_ICON_CHECK as u8;

pub trait BaglTrait {
  fn new() -> Self;
  fn pos(self, x: u16, y: u16) -> Self;
  fn colors(self, fg: u32, bg: u32) -> Self;
  fn dims(self, w: u16, h: u16) -> Self;
  fn userid(self, id: u8) -> Self;
}

pub struct Rect {
  pub pos: (u16,u16),
  pub dims: (u16,u16),
  pub colors: (u32, u32), 
  pub fill: bool,
  pub userid: u8
}

impl BaglTrait for Rect {
  fn new() -> Rect {
    Rect {pos: (32-5, 64-5), dims: (10,10), colors: (FULL, 0), fill:true, userid:0}
  }

  fn pos(self, x: u16, y: u16) -> Rect {
    Rect {pos: (x,y), ..self}
  }

  fn colors(self, fg: u32, bg: u32) -> Rect {
    Rect {colors: (fg,bg), ..self}
  }
  fn dims(self, w: u16, h: u16) -> Rect {
    Rect {dims: (w,h), ..self}
  }
  fn userid(self, id: u8) -> Rect {
    Rect {userid: id, ..self}
  }
}

impl From<Rect> for Bagl {
  fn from(rect: Rect)-> Bagl {
    Bagl { 
      component : bagl_component_t { 
        type_:  BAGL_RECTANGLE,
        userid: 0,
        x: 0, y:0,
        width: rect.dims.0,
        height: rect.dims.1,
        stroke:0,
        radius:0,
        fill: rect.fill as u8,
        fgcolor: FULL,
        bgcolor: 0,
        font_id: 0,
        icon_id: 0,
      },
      text: core::ptr::null() 
    }
  }
}

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
      text: core::ptr::null() 
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
      text: core::ptr::null() 
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