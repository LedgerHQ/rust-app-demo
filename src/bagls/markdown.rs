
pub struct Flow<'a> {
  source: &'a str,
  page_count: u8
}

pub struct FlowSourceIterator<'a> {
  source: &'a str,
  page: u8,  // The page in which we want to iterate
  lines_iterator: core::str::Lines<'a>,
  ended: bool
}

const FLOW_MAX_PAGE_COUNT: usize = 16;

/// Calculate the number of page in a given markdown.
/// * `source` - Markdown code.
fn compute_page_count(source: &str) -> u8 {
  let mut result: u8 = 1;
  for line in source.lines() {
    if line == "---" {
      assert!(result < u8::max_value());
      result += 1;
    }
  }
  result
}

impl Flow<'_> {
  pub fn new<'a>(source: &'a str) -> Flow<'a> {
    Flow {
      source: source,
      page_count: compute_page_count(source)
    }
  }

  pub fn lines_in_page<'a>(&'a self, page: u8)
  -> FlowSourceIterator<'a> {
    FlowSourceIterator::new(self.source, page)
  }

  pub fn page_count(self) -> u8 {
    self.page_count
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

  const test_md: &str = concat!(
    "page 0 line 0\n",
    "page 0 line 1\n",
    "---\n",
    "page 1 line 0\n",
    "page 1 line 1\n",
    "---\n",
    "page 2 line 0\n",
    "page 2 line 1\n",
    "page 2 line 2\n",
  );

  #[test]
  fn test_source_flow_iterator() {
    let flow = Flow::new(test_md);
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

  #[test]
  fn test_page_count() {
    assert_eq!(Flow::new(test_md).page_count, 3);
    assert_eq!(Flow::new("").page_count, 1);
    assert_eq!(Flow::new("---").page_count, 2);
    assert_eq!(Flow::new("---\n---").page_count, 3);
  }

  #[test]
  #[should_panic]
  fn test_too_many_pages() {
    Flow::new(&"---\nhello\n".repeat(255)[..]); // 256 pages
  }

  #[test]
  fn test_max_pages() {
    Flow::new(&"---\nhello\n".repeat(254)[..]); // 255 pages
  }
}

