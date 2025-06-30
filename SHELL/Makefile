# === CONFIGURATION ===

SDL2_PATH = C:/Libs/SDL2-2.28.5/x86_64-w64-mingw32
SDL2_TTF_PATH = C:/Libs/SDL2_ttf-2.20.2/x86_64-w64-mingw32

INCLUDES = -I$(SDL2_PATH)/include/SDL2 -I$(SDL2_TTF_PATH)/include/SDL2
LIBS = -L$(SDL2_PATH)/lib -L$(SDL2_TTF_PATH)/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf


# Source and output
SRCS = main.cpp gui.cpp shell.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = shell.exe

# Compiler
CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -Wall -std=c++17 $(INCLUDES)

# === BUILD RULES ===

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q *.o *.exe 2>nul

