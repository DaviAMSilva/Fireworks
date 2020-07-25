TARGET	= Fireworks
SOURCE	= $(wildcard *.c)
INCLUDE	= $(wildcard *.h)

.PHONY: all

all: $(TARGET)

$(TARGET): $(SOURCE) $(INCLUDE)
	gcc $(SOURCE) -lncurses -lm -o $@