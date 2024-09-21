# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces

# Include and library paths
INCLUDES = -I include/
LIBS = -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

# Source and output
SRC = src/main.c
OUT = game.exe

# Default rule
all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(INCLUDES) $(LIBS)

clean:
	rm -f $(OUT)
