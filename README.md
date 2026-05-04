<h1 align="center">Hotakus's Nocturne</h1>

<p align="center">
  <img src="https://img.shields.io/github/v/release/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=4fc3f7&label=Version" alt="Version">
  <img src="https://img.shields.io/badge/VS%20Code-%5E1.60.0-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" alt="VS Code">
  <img src="https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge" alt="License">
  <img src="https://img.shields.io/badge/Theme-Dark-2c2c2c?style=for-the-badge" alt="Theme">
  <img src="https://img.shields.io/github/stars/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=ffa726" alt="Stars">
</p>

<p align="center"><em>一个暗色 VS Code 主题，低对比度配色 + 语义高亮，看代码不累。</em></p>

<img src="assets/整体界面展示.png" alt="整体界面" />

---

## ✨ 特性

- **低对比度暗色** — 背景 `#2c2c2c`，前景 `#b8b8b8`，长时间编码不刺眼
- **语义高亮** — 15 个语义 Token 覆盖类、函数、参数、属性、装饰器等，全部对齐 TextMate 配色
- **17 色分层次色板** — 变量、类型、命名空间、标点、字符串各有独立色系
- **策略性斜体** — 声明型关键字、修饰符、泛型参数、装饰器斜体，流程控制直立
- **工作台完整美化** — 侧边栏、标签页、终端、Git 装饰、Diff 视图、调试工具栏、断点指示器
- **Git 低存在感配色** — SCM 面板和 Diff 差异视图低透明度着色
- **260+ 条 Token 规则** — 覆盖 15+ 种语言

## 🎨 色板

| 角色 | 色值 | 对比度 |
|------|------|--------|
| 正文 | `#b8b8b8` | 7.04:1 |
| 类型 / 类名 | `#eaab7c` 暖琥珀 | 7.06:1 |
| 函数 / 方法 | `#8ab0b8` 青蓝 | 5.5:1 |
| 变量 / 属性 | `#d09090` 尘玫红 | 4.7:1 |
| 声明关键字 | `#8e8eaa` 紫灰 + 斜体 | 4.2:1 |
| 字符串 | `#6a8a80` 暗鼠尾 | 3.6:1 |
| 原始类型 | `#7a9a90` 冷鼠尾 | ~4.5:1 |
| 命名空间 | `#c0a068` 暗琥珀 | ~5:1 |
| 标点 | `#9a9a9a` 暗灰 | ~4:1 |
| 注释 | `#585858` 极暗灰 + 斜体 | 2.0:1 |

## 📦 安装

```bash
code --install-extension hotakus.hotakus
```

或 `Ctrl+Shift+X` 搜索 **Hotakus's Nocturne**。

也可从 [Releases](https://github.com/Hotakus/hotakus-necturne-theme/releases) 下载 `.vsix` 手动安装。

## 🌐 语言覆盖

| 语言 | 文件 | 特色着色 |
|------|------|---------|
| TypeScript | `example/typescript.ts` | 泛型、装饰器、类型守卫 |
| JavaScript | `example/javascript.js` | 类、Promise、解构 |
| C | `example/c_lang.c` | 宏、预处理器、指针 |
| C++ | `example/cpp.cpp` | 模板、RAII、concepts |
| Python | `example/python.py` | 装饰器、async、dataclass |
| Rust | `example/rust.rs` | trait、生命周期、enum |
| Go | `example/go.go` | goroutine、channel、interface |
| Java | `example/java.java` | 泛型、lambda、stream |
| HTML | `example/index.html` | 语义标签、属性 |
| CSS | `example/styles.css` | 自定义属性、伪类、函数 |
| JSON | `example/config.json` | 嵌套对象、数组 |
| YAML | `example/config.yaml` | 锚点、别名、多行 |
| Markdown | `example/markdown.md` | 表格、代码块、引用 |
| SVG | `example/sample.svg` | 形状、渐变、路径 |
| Shell | `example/script.sh` | 变量、函数、heredoc |

## 🖼️ Git & Diff

<img src="assets/git相关.png" alt="Git 界面" />

---

<p align="center">
  <sub>English README <a href="./README.en.md">here</a> | MIT © Hotakus</sub>
</p>
