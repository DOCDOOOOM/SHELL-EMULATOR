# ⚡ SHELL-EMULATOR
# A GUI-Based Shell Emulator (SDL2)

It is a **custom shell emulator** built using **C++**, **SDL2**, and **SDL_ttf** that simulates a terminal inside a clean, responsive graphical user interface. It combines real shell power with GUI design to deliver a minimalist yet powerful terminal experience on Windows.

---

## 🖼 Features

✅ **Graphical Terminal Interface**  using SDL2  
✅ **Real-time Command Input**  with live rendering  
✅ **Supports Windows Shell Commands**  - `dir`, `echo`, `ipconfig`, etc.  
✅ **Command Output Display**  with scroll-like interface  
✅ **Clean Font Rendering**  using SDL2_ttf  
✅ **History Tracking**  (internally)  
✅ **Works on Windows**  using MinGW-w64 toolchain

---

## 🔧 Tech Stack

- 💻 **C++17**
- 🧱 **SDL2** for graphics and input
- 🅰️ **SDL2_ttf** for font rendering
- 🛠️ **MinGW-w64** for compilation on Windows
- 🧰 **Makefile** for easy building

---


## 📂 Folder Structure

```
SHELL/
├── assets/                # Fonts & UI resources
├── Makefile               # Build instructions
├── SDL2.dll               # SDL2 runtime
├── SDL2_ttf.dll           # Font rendering runtime
├── gui.cpp                # GUI rendering & input
├── gui.h                  # GUI rendering & input
├── main.cpp               # Program entry point
├── shell.cpp              # Command execution logic
├── shell.h                # Command execution logic
├── shell.exe              # Final executable
├── LICENSE                # Project license
└── README.md              # Project info & usage

```


---

## 🚀 Getting Started

### 📦 Requirements

- **SDL2**  development libraries
- **SDL2_ttf**  development libraries
- **MinGW-w64**  (64-bit)
- A  **Font.ttf**  file  (already included)

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

