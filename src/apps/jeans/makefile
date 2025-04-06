CC = gcc

# 공통 헤더
INCLUDE_DIR = ./include
INCLUDE_DIRS = $(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))

CFLAGS = -Wall -g -I$(INCLUDE_DIR)

# 컴파일할 대상들
TARGETS = jeansl \
	      jeanssvc \
		  client

# 각 타겟별 소스
client: client.c
	$(CC) $(CFLAGS) -o client client.c

jenasl: jeansl.c
	$(CC) $(CFLAGS) -o jeansl jeansl.c

jeanssvc: jeanssvc.c
	$(CC) $(CFLAGS) -o jeanssvc jeanssvc.c

# all 빌드
all: $(TARGETS)

# clean
clean:
	rm -f $(TARGETS) *.o
