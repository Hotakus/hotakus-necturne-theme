# Heading 1
## Heading 2
### Heading 3
#### Heading 4
##### Heading 5
###### Heading 6

---

Inline styles: **bold** __bold__ *italic* _italic_ ~~strikethrough~~ `code` ==highlight== .

> Blockquote line 1.
> Blockquote line 2.
>
> > Nested blockquote.

---

- Unordered list
  - Nested item
  - Another nested
- Back to level 1

1. Ordered list
2. Second item
   1. Nested ordered
   2. Nested

- [ ] Task incomplete
- [x] Task complete

---

| Left | Center | Right |
|:-----|:------:|------:|
| a    | b      | c     |
| 1    | 2      | 3     |

---

```python
from dataclasses import dataclass

@dataclass
class User:
    id: int
    name: str
    active: bool = True

    def greet(self) -> str:
        return f"Hello, {self.name}!"
```

```cpp
template <typename T>
auto clamp(T val, T lo, T hi) -> T {
    if (val < lo) return lo;
    if (val > hi) return hi;
    return val;
}
```

```bash
#!/bin/bash
set -e
echo "Hello, world"
```

---

Inline HTML: <kbd>Ctrl</kbd> + <kbd>S</kbd>

---

[Link text](https://example.com)

![Image alt](https://placehold.co/200x100/2c2c2c/b8b8b8?text=Nocturne)

Auto-link: https://github.com

---

Horizontal rule above.
---
Horizontal rule below.

Footnote reference[^1].

[^1]: This is a footnote.

---

- [ ] Headings
- [x] Bold / Italic / Strikethrough
- [x] Blockquotes (now italic)
- [x] Lists (ordered, unordered, task)
- [x] Table
- [x] Code blocks (Python, C++, Shell)
- [x] Links & Images
- [x] Horizontal rules
- [x] Footnotes
