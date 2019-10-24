use crate::bindings::*;

const FULL: u32 = 0xffffff;
pub const ICON_CROSS: u8 = BAGL_GLYPH_ICON_CROSS as u8;
pub const ICON_CHECK: u8 = BAGL_GLYPH_ICON_CHECK as u8;

#[derive(Copy, Clone)]
pub struct Rect {
  pub pos: (u16,u16),
  pub dims: (u16,u16),
  pub colors: (u32, u32), 
  pub fill: bool,
  pub userid: u8
}

pub struct Button {}

pub struct Label {
}

pub struct LabelLine {
  pub pos: (i16, i16),
  pub dims: (u16, u16)
}

pub struct Line {}

pub struct Icon {
  pub pos: (i16, i16),
  pub glyph_id: u8
}

pub struct Circle {}

pub enum Bagl {
  BUTTON(Button),
  LABEL(Label),
  LABELLINE(LabelLine),
  RECT(Rect),
  LINE(Line),
  ICON(Icon),
  CIRCLE(Circle),
}

impl Button {
  pub const fn new() -> Button {
    Button {}
  }
}

impl Label {
  pub const fn new() -> Label {
    Label {}
  }
}

impl LabelLine {
  pub const fn new() -> LabelLine {
    LabelLine {
      pos: (0, 0),
      dims: (0, 0)
    }
  }
}

impl Rect {
  pub const fn new() -> Rect {
    Rect {pos: (32-5, 64-5), dims: (10,10), colors: (FULL, 0), fill:true, userid:0}
  }

  pub const fn  pos(self, x: u16, y: u16) -> Rect {
    Rect {pos: (x,y), ..self}
  }

  pub const fn  colors(self, fg: u32, bg: u32) -> Rect {
    Rect {colors: (fg,bg), ..self}
  }
  pub const fn  dims(self, w: u16, h: u16) -> Rect {
    Rect {dims: (w,h), ..self}
  }
  pub const fn  userid(self, id: u8) -> Rect {
    Rect {userid: id, ..self}
  }
}

impl Line {
  fn new() -> Line {
    Line {}
  }
}

impl Icon {
  fn new() -> Icon {
    Icon {
      pos: (0, 0),
      glyph_id: 0
    }
  }
}

impl Circle {
  fn new() -> Circle {
    Circle {}
  }
}

// impl From<Bagl> for bagl_element_t {
//   bagl_element_t {
// }

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
        fgcolor: FULL,
        bgcolor: 0,
        font_id: 0,
        icon_id: 0,
      },
      text: core::ptr::null(),
    }
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
        fgcolor: FULL,
        bgcolor: 0,
        font_id: BAGL_FONT_OPEN_SANS_REGULAR_11px as u16 | BAGL_FONT_ALIGNMENT_CENTER as u16,
        icon_id: 0,
      },
      // text: labelline.text.as_ptr(),  FIXME
      text: core::ptr::null(),
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
        fgcolor: FULL,
        bgcolor: 0,
        font_id: 0,
        icon_id: icon.glyph_id,
      },
      text: core::ptr::null(),
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
