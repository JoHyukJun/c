CC = gcc

# 공통 헤더
INCLUDE_DIR = ./include
INCLUDE_DIRS = $(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))

CFLAGS = -Wall -g -I$(INCLUDE_DIR)

# 컴파일할 대상들
TARGETS = main 

# 각 타겟별 소스
mqmon: main.c
	$(CC) $(CFLAGS) -o mqmon main.c

# all 빌드
all: $(TARGETS)

# clean
clean:
	rm -f $(TARGETS) *.o
