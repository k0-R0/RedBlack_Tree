CC := gcc
CFLAGS := -Wextra -Wall
TARGET := RBTree
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

.PHONY : all clean debug

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

debug : CFLAGS += -g 
debug : $(TARGET)

clean : 
	rm -rf $(OBJS) $(TARGET)
