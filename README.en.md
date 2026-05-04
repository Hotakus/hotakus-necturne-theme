<h1 align="center">Hotakus's Nocturne</h1>

<p align="center">
  <img src="https://img.shields.io/github/v/release/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=4fc3f7&label=Version" alt="Version">
  <img src="https://img.shields.io/badge/VS%20Code-%5E1.60.0-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" alt="VS Code">
  <img src="https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge" alt="License">
  <img src="https://img.shields.io/badge/Theme-Dark-2c2c2c?style=for-the-badge" alt="Theme">
  <img src="https://img.shields.io/github/stars/Hotakus/hotakus-necturne-theme?style=for-the-badge&color=ffa726" alt="Stars">
</p>

<p align="center"><em>A refined dark theme for nocturnal coders — meticulously tuned contrast, semantic highlighting, and a palette that soothes the eyes during late-night sessions.</em></p>

<p align="center">「Good code deserves a good night.」</p>

---

## Features

- **Deep, warm dark background** (`#2c2c2c`) — easy on the eyes for hours of coding
- **Semantic highlighting** enabled — richer token differentiation powered by VS Code's semantic tokens API
- **241 hand-tuned token color rules** — coverage across keywords, types, functions, variables, strings, and more
- **Balanced contrast** — foreground text at `#b8b8b8` with clear but not harsh distinction
- **Subtle accent colors** — coral punctuations, amber parameters, teal functions, lavender types
- **Full workbench styling** — sidebar, tabs, terminal, git decorations, Peek View, Suggest widget, Debug toolbar all themed
- **Language-specific refinements** — Python, Rust, Haskell, and more with targeted scopes

## Color Palette

| Role | Hex | Preview |
|------|-----|---------|
| Editor Background | `#2c2c2c` | ![#2c2c2c](https://placehold.co/12x12/2c2c2c/2c2c2c) |
| Editor Foreground | `#b8b8b8` | ![#b8b8b8](https://placehold.co/12x12/b8b8b8/b8b8b8) |
| Keywords | `#eaab7c` (warm amber) | ![#eaab7c](https://placehold.co/12x12/eaab7c/eaab7c) |
| Functions / Stdlib | `#a6d5e8` (soft teal) | ![#a6d5e8](https://placehold.co/12x12/a6d5e8/a6d5e8) |
| Strings | `#b9b9b9` (silver) | ![#b9b9b9](https://placehold.co/12x12/b9b9b9/b9b9b9) |
| Types / Classes | `#cd9cb3` (dusty lavender) | ![#cd9cb3](https://placehold.co/12x12/cd9cb3/cd9cb3) |
| Punctuation | `#e87d77` (muted coral) | ![#e87d77](https://placehold.co/12x12/e87d77/e87d77) |
| Comments | `#7b7b7b` (dim gray) | ![#7b7b7b](https://placehold.co/12x12/7b7b7b/7b7b7b) |
| Errors / Deletions | `#f48771` (soft red) | ![#f48771](https://placehold.co/12x12/f48771/f48771) |
| Additions / Git Added | `#81b88b` (sage green) | ![#81b88b](https://placehold.co/12x12/81b88b/81b88b) |

## Installation

### VS Code Marketplace *(coming soon)*

```bash
code --install-extension hotakus.hotakus
```

Or search for **"Hotakus's Nocturne"** in the Extensions view (`Ctrl+Shift+X`).

### Manual (via `.vsix`)

1. Download `hotakus-*.vsix` from [Releases](https://github.com/your-repo/releases)
2. Open VS Code, press `Ctrl+Shift+P`, run **"Extensions: Install from VSIX…"**
3. Select the downloaded file

### From Source

```bash
git clone <repo-url>
cp -r hotakus ~/.vscode/extensions/hotakus
# Restart VS Code
```

## Activation

After installation, activate the theme:

1. `Ctrl+K Ctrl+T` (or `Ctrl+Shift+P` → **"Preferences: Color Theme"**)
2. Select **"Hotakus's Nocturne"**

---

## Recommended Settings

These complement the theme nicely:

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

## Supported Languages

The theme includes explicit token rules for:

- Python (self params, magic variables, separators)
- Rust (lifetimes, stdlib functions, generics)
- Haskell (generic types, storage types)
- Unison (punctuation, operators)
- …plus generic scopes covering **JavaScript, TypeScript, C/C++, Go, Java, C#, JSON, YAML, Markdown, HTML, CSS** and many more.

## Credits

Based on and heavily customized from an original theme. Re-sculpted for the nocturne aesthetic — darker backgrounds, softer highlights, and warmer accents.

## License

MIT © Hotakus
