# SHELL-EMULATOR
# ⚡ A GUI-Based Shell Emulator (SDL2)

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
├── assets/                # Contains font files and other resources (like preview.png or fonts)
├── Makefile               # Build script using MinGW (compile all .cpp files)
├── SDL2.dll               # SDL2 runtime library required for execution
├── SDL2_ttf.dll           # SDL2_ttf runtime for rendering fonts
├── gui.cpp                # Handles rendering GUI, input box, and terminal display
├── gui.h                  # Header file for GUI functions and state
├── main.cpp               # Entry point: initializes SDL and starts GUI loop
├── shell.cpp              # Executes commands via _popen and returns output
├── shell.h                # Header for shell command execution logic
├── shell.exe              # Final compiled SDL shell executable
├── *.o                    # Object files generated during compilation
├── LICENSE                # License file (MIT, GPL, etc.)
└── README.md              # Project description, instructions, features, and credits

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

