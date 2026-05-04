<h1 align="center">Hotakus's Nocturne</h1>

<p align="center">
  <img src="https://img.shields.io/github/v/release/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=4fc3f7&label=Version" alt="Version">
  <img src="https://img.shields.io/badge/VS%20Code-%5E1.60.0-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" alt="VS Code">
  <img src="https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge" alt="License">
  <img src="https://img.shields.io/badge/Theme-Dark-2c2c2c?style=for-the-badge" alt="Theme">
  <img src="https://img.shields.io/github/stars/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=ffa726" alt="Stars">
</p>

<p align="center"><em>一款为深夜编码者精心打磨的暗色主题 —— 柔和对比度、语义高亮、不伤眼的配色，陪伴你度过每一个编码之夜。</em></p>

<p align="center">「好的代码，值得一个温柔的夜晚。」</p>

---

## ✨ 特性

- **深邃温暖的暗色背景**（`#2c2c2c`）—— 长时间编码不刺眼
- **语义高亮**（Semantic Highlighting）—— 基于 VS Code 语义 Token API，提供更丰富的语法着色
- **241 条手动调校的 Token 着色规则** —— 覆盖关键字、类型、函数、变量、字符串等全方位
- **平衡的对比度** —— 前景色 `#b8b8b8`，清晰但不尖锐
- **克制的点缀色** —— 珊瑚标点、琥珀参数、青色函数、淡紫类型
- **完整的工作台美化** —— 侧边栏、标签页、终端、Git 装饰、Peek View、建议提示框、调试工具栏全部覆盖
- **语言专项优化** —— Python、Rust、Haskell 等语言有针对性着色规则

## 🎨 配色板

| 角色 | 色值 | 预览 |
|------|------|------|
| 编辑器背景 | `#2c2c2c` | ![#2c2c2c](https://placehold.co/12x12/2c2c2c/2c2c2c) |
| 编辑器前景 | `#b8b8b8` | ![#b8b8b8](https://placehold.co/12x12/b8b8b8/b8b8b8) |
| 关键字 | `#eaab7c` 暖琥珀 | ![#eaab7c](https://placehold.co/12x12/eaab7c/eaab7c) |
| 函数 / 标准库 | `#a6d5e8` 柔青 | ![#a6d5e8](https://placehold.co/12x12/a6d5e8/a6d5e8) |
| 字符串 | `#b9b9b9` 银灰 | ![#b9b9b9](https://placehold.co/12x12/b9b9b9/b9b9b9) |
| 类型 / 类 | `#cd9cb3` 淡紫灰 | ![#cd9cb3](https://placehold.co/12x12/cd9cb3/cd9cb3) |
| 标点符号 | `#e87d77` 珊瑚红 | ![#e87d77](https://placehold.co/12x12/e87d77/e87d77) |
| 注释 | `#7b7b7b` 暗灰 | ![#7b7b7b](https://placehold.co/12x12/7b7b7b/7b7b7b) |
| 错误 / 删除 | `#f48771` 柔红 | ![#f48771](https://placehold.co/12x12/f48771/f48771) |
| 新增 / Git Added | `#81b88b` 鼠尾绿 | ![#81b88b](https://placehold.co/12x12/81b88b/81b88b) |

## 📦 安装

### VS Code 扩展市场

```bash
code --install-extension hotakus.hotakus
```

或在扩展视图（`Ctrl+Shift+X`）中搜索 **「Hotakus's Nocturne」**。

### 手动安装（.vsix）

1. 从 [Releases](https://github.com/Hotakus/hotakus-necturne-theme/releases) 下载 `hotakus-*.vsix`
2. 打开 VS Code，`Ctrl+Shift+P` → 运行 **「Extensions: Install from VSIX…」**
3. 选择下载的文件即可

### 从源码安装

```bash
git clone https://github.com/Hotakus/hotakus-necturne-theme.git
cp -r hotakus-necturne-theme ~/.vscode/extensions/hotakus
# 重启 VS Code
```

## 🚀 启用

安装后，切换到主题：

1. `Ctrl+K Ctrl+T`（或 `Ctrl+Shift+P` → **「首选项: 颜色主题」**）
2. 选择 **「Hotakus's Nocturne」**

---

## ⚙️ 推荐设置

以下设置与本主题搭配效果最佳：

```json
{
  "editor.fontFamily": "'Maple Mono SC NF', 'Cascadia Code', 'Fira Code', monospace",
  "editor.fontLigatures": true,
  "editor.fontSize": 16,
  "editor.lineHeight": 1.6,
  "editor.cursorBlinking": "smooth",
  "workbench.iconTheme": "material-icon-theme"
}
```

## 🌐 支持的语言

主题包含以下语言的显式着色规则：

- **Python** — `self` 参数、魔法变量、分隔符
- **Rust** — 生命周期、标准库函数、泛型
- **Haskell** — 泛型类型、存储类型
- **Unison** — 标点、运算符

此外，通用的 Token scope 也覆盖了 **JavaScript、TypeScript、C/C++、Go、Java、C#、JSON、YAML、Markdown、HTML、CSS** 等众多语言。

## 📝 开发

```bash
# 打包 .vsix
npx @vscode/vsce package

# 本地安装测试
code --install-extension hotakus-1.0.0.vsix
```

---

<p align="center">
  <sub>基于原始主题深度定制 · 专为夜间编码美学重新雕琢</sub>
  <br>
  <sub>English README <a href="./README.en.md">here</a> | MIT © Hotakus</sub>
</p>
