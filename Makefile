# Makefile

# Compilers
GCC = gcc
EMCC = emcc

# GCC Compiler flags
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces
# EMCC Compiler flags
WEB_FLAGS = -target=wasm32 -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_STACK=64MB -s INITIAL_MEMORY=128MB -s ASSERTIONS -DPLATFORM_WEB

# Include and libraries paths
INCLUDES = -I ./include/
LIBS = -L lib/win_64 -lraylib -lopengl32 -lgdi32 -lwinmm
WEB_LIBS = -L ./lib/webassembly/ -lraylib

# Source and output
SRC = ./src/main.c
OUT = builds/windows/game.exe
WEB_OUT = ./builds/web/game.html

# Default rule
all: windows web
	
windows:
	$(GCC) $(SRC) -o $(OUT) $(CFLAGS) $(INCLUDES) $(LIBS)
web:
	$(EMCC) $(SRC) -o $(WEB_OUT) $(INCLUDES) $(WEB_LIBS) $(WEB_FLAGS)
clean:
	rm -f $(OUT) $(WEB_OUT)