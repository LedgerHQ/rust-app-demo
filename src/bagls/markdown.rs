
pub struct Flow<'a> {
  pub source: &'a str
}

pub struct FlowSourceIterator<'a> {
  source: &'a str,
  page: u8,  // The page in which we want to iterate
  lines_iterator: core::str::Lines<'a>,
  ended: bool
}

const FLOW_MAX_PAGE_COUNT: usize = 16;

impl Flow<'_> {
  pub fn new<'a>(source: &'a str) -> Flow<'a> {
    Flow {
      source: source
    }
  }

  pub fn lines_in_page<'a>(&'a self, page: u8)
  -> FlowSourceIterator<'a> {
    FlowSourceIterator::new(self.source, page)
  }
}

impl FlowSourceIterator<'_> {
  /// * `source` - Markdown source
  /// * `page` - The page we want to iterate
  pub fn new<'a>(source: &'a str, page: u8) -> FlowSourceIterator<'a> {
    // Initialize the line iterator and find the start of the page.
    let mut fsi = FlowSourceIterator {
        source: source,
        page: page,
        lines_iterator: source.lines(),
        ended: false };
    let mut actual_page: u8 = 0;
    loop {
      if actual_page >= page {
        break;
      }
      let n = fsi.lines_iterator.next();
      match n {
        Some(v) => {
          if v == "---" {
            actual_page += 1;
          }
        },
        None => { fsi.ended = true; }
      }
    }
    fsi
  }
}

impl<'a> Iterator for FlowSourceIterator<'a> {
  type Item = &'a str;

  fn next(&mut self) -> Option<&'a str> {
    if self.ended {
      None
    } else {
      match self.lines_iterator.next() {
        Some(v) => {
          if v == "---" {
            None
          } else {
            Some(v)
          }
        },
        None => None
      }
    }
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_source_flow_iterator() {
    let flow = Flow::new(
      concat!(
        "page 0 line 0\n",
        "page 0 line 1\n",
        "---\n",
        "page 1 line 0\n",
        "page 1 line 1\n",
        "---\n",
        "page 2 line 0\n",
        "page 2 line 1\n",
        "page 2 line 2\n",
      )
    );
    assert_eq!(
      flow.lines_in_page(0).collect::<Vec<&str>>(),
      ["page 0 line 0", "page 0 line 1"]
    );
    assert_eq!(
      flow.lines_in_page(1).collect::<Vec<&str>>(),
      ["page 1 line 0", "page 1 line 1"]
    );
    assert_eq!(
      flow.lines_in_page(2).collect::<Vec<&str>>(),
      ["page 2 line 0", "page 2 line 1", "page 2 line 2"]
    );
  }
}

