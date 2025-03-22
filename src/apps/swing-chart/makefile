CC = gcc
CFLAGS = `pkg-config --cflags gtk4 cairo`
LDFLAGS = `pkg-config --libs gtk4 cairo`
OUT = swing-chart

SRC_DIR = ./
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(CFLAGS) -o $(OUT) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(OUT)
