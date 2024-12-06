# Compiler
CC = gcc

# Directories
SRC_DIR = ./
BUILD_DIR = build
LIB_DIR = ../libobj
INCLUDE_DIR = include

# Target library name
LIB_NAME = j
LIB_SHARED = $(LIB_DIR)/lib$(LIB_NAME).so

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Compiler flags
CFLAGS = -Wall -Wextra -O2 -fPIC -I$(INCLUDE_DIR)
LDFLAGS = -shared

# Default target
all: $(LIB_SHARED)

# Build the shared library
$(LIB_SHARED): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

# Phony targets
.PHONY: all clean
