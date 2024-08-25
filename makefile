# Define variables for directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Define target executable name
TARGET = $(BIN_DIR)/program

# Define source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR) # Create the bin directory if it doesn't exist
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # Create the obj directory if it doesn't exist
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean

