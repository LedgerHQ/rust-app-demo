
pub struct Flow<'a> {
  source: &'a str,
  page_count: u8
}

pub struct PageLineIterator<'a> {
  lines_iterator: core::str::Lines<'a>,
  ended: bool
}

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
  -> PageLineIterator<'a> {
    PageLineIterator::new(self.source, page)
  }

  pub fn page_count(self) -> u8 {
    self.page_count
  }
}

impl PageLineIterator<'_> {
  /// * `source` - Markdown source
  /// * `page` - The page we want to iterate
  pub fn new<'a>(source: &'a str, page: u8) -> PageLineIterator<'a> {
    // Initialize the line iterator and find the start of the page.
    let mut fsi = PageLineIterator {
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

impl<'a> Iterator for PageLineIterator<'a> {
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

  const TEST_MD: &str = concat!(
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
    let flow = Flow::new(TEST_MD);
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
    assert_eq!(Flow::new(TEST_MD).page_count, 3);
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

