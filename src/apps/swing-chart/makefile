CC = gcc
OUT = swing-chart
INCLUDE_DIR = ./include

# Find all subdirectories in INCLUDE_DIR
INCLUDE_DIRS = $(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))

SRC_DIR = ./
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

CFLAGS = `pkg-config --cflags gtk4 cairo` -Wall -Wextra -O2 -I$(INCLUDE_DIR)
LDFLAGS = `pkg-config --libs gtk4 cairo`

all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(CFLAGS) -o $(OUT) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(OUT)
