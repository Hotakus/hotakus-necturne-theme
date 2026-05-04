<h1 align="center">Hotakus's Nocturne</h1>

<p align="center">
  <img src="https://img.shields.io/github/v/release/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=4fc3f7&label=Version" alt="Version">
  <img src="https://img.shields.io/badge/VS%20Code-%5E1.60.0-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" alt="VS Code">
  <img src="https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge" alt="License">
  <img src="https://img.shields.io/badge/Theme-Dark-2c2c2c?style=for-the-badge" alt="Theme">
  <img src="https://img.shields.io/github/stars/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=ffa726" alt="Stars">
</p>

<p align="center"><em>A dark VS Code theme with low-contrast colors and semantic highlighting — easy on the eyes.</em></p>

<img src="assets/整体界面展示.png" alt="Overview" />

---

## ✨ Features

- **Low-contrast dark background** — `#2c2c2c` / `#b8b8b8`, comfortable for hours
- **Semantic highlighting** — 15 tokens for classes, functions, parameters, decorators, all aligned with TextMate
- **17-color layered palette** — variables, types, namespaces, punctuation, strings each get distinct hues
- **Strategic italics** — only for declarations, modifiers, type parameters, and decorators; flow control stays upright
- **Full workbench styling** — sidebar, tabs, terminal, Git decorations, Diff view, Debug toolbar, breakpoints
- **Low-profile Git** — muted SCM panel and subtle diff backgrounds
- **260+ token rules** across 15+ languages

## 🎨 Color Palette

| Role | Hex | Contrast |
|------|-----|----------|
| Text | `#b8b8b8` | 7.04:1 |
| Types / Classes | `#eaab7c` warm amber | 7.06:1 |
| Functions / Methods | `#8ab0b8` teal | 5.5:1 |
| Variables / Properties | `#d09090` dusty rose | 4.7:1 |
| Storage keywords | `#8e8eaa` muted purple + italic | 4.2:1 |
| Strings | `#6a8a80` muted sage | 3.6:1 |
| Primitives | `#7a9a90` cool sage | ~4.5:1 |
| Namespaces | `#c0a068` dark amber | ~5:1 |
| Punctuation | `#9a9a9a` dim gray | ~4:1 |
| Comments | `#585858` very dim gray + italic | 2.0:1 |

## 📦 Install

```bash
code --install-extension hotakus.hotakus
```

Or search **Hotakus's Nocturne** in Extensions (`Ctrl+Shift+X`).

Manual install via `.vsix` from [Releases](https://github.com/Hotakus/hotakus-necturne-theme/releases).

## 🌐 Languages

| Language | File | Highlights |
|----------|------|-----------|
| TypeScript | `example/typescript.ts` | Generics, decorators, type guards |
| JavaScript | `example/javascript.js` | Classes, Promise, destructuring |
| C | `example/c_lang.c` | Macros, preprocessor, pointers |
| C++ | `example/cpp.cpp` | Templates, RAII, concepts |
| Python | `example/python.py` | Decorators, async, dataclass |
| Rust | `example/rust.rs` | Traits, lifetimes, enums |
| Go | `example/go.go` | Goroutines, channels, interface |
| Java | `example/java.java` | Generics, lambda, stream |
| HTML | `example/index.html` | Semantic tags, attributes |
| CSS | `example/styles.css` | Custom props, pseudo, functions |
| JSON | `example/config.json` | Nested objects, arrays |
| YAML | `example/config.yaml` | Anchors, aliases, multiline |
| Markdown | `example/markdown.md` | Tables, code blocks, quote |
| SVG | `example/sample.svg` | Shapes, gradients, paths |
| Shell | `example/script.sh` | Variables, functions, heredoc |

## 🖼️ Git & Diff

<img src="assets/git相关.png" alt="Git view" />

---

<p align="center">
  <sub>Chinese README <a href="./README.md">here</a> | MIT © Hotakus</sub>
</p>
