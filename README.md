# SHELL-EMULATOR
# ⚡ A GUI-Based Shell Emulator (SDL2)

It is a **custom shell emulator** built using **C++**, **SDL2**, and **SDL_ttf** that simulates a terminal inside a clean, responsive graphical user interface. It combines real shell power with GUI design to deliver a minimalist yet powerful terminal experience on Windows.

---

## 🖼 Features

✅ **Graphical Terminal Interface** using SDL2  
✅ **Real-time Command Input** with live rendering  
✅ **Supports Windows Shell Commands** (`dir`, `echo`, `ipconfig`, etc.)  
✅ **Command Output Display** with scroll-like interface  
✅ **Clean Font Rendering** using SDL2_ttf  
✅ **History Tracking** (internally)  
✅ **Works on Windows** using MinGW-w64 toolchain

---

## 🔧 Tech Stack

- 💻 **C++17**
- 🧱 **SDL2** for graphics and input
- 🅰️ **SDL2_ttf** for font rendering
- 🛠️ **MinGW-w64** for compilation on Windows
- 🧰 **Makefile** for easy building

---

## 🖥 Preview

> ![Shell Screenshot](assets/preview.png)  
*(Add a screenshot here showing command input/output in your GUI window)*

---

## 📂 Folder Structure
/SHELL
├── main.cpp              // SDL entry point + loop
├── shell.cpp             // Shell logic (parsing, executing)
├── gui.cpp               // GUI rendering, input handling
├── gui.h
├── shell.h
├── Makefile              // Or tasks.json / .vscode for VS Code
└── assets/
    └── font.ttf          // Font file for SDL_ttf



---

## 🚀 Getting Started

### 📦 Requirements

- SDL2 development libraries
- SDL2_ttf development libraries
- MinGW-w64 (64-bit)
- A monospace `.ttf` font (already included)

---

### ⚙️ Build Instructions

```bash
# Clone this repo
git clone https://github.com/yourusername/ShellForge.git
cd ShellForge

# Build using Makefile
mingw32-make

# Run the shell
./shell_gui.exe

