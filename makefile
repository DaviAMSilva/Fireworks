TARGET	= Fireworks
SOURCE	= $(wildcard *.c)
INCLUDE	= $(wildcard *.h)
LIBS    = -lncurses

.PHONY: all

all: $(TARGET)

$(TARGET): $(SOURCE) $(INCLUDE)
	gcc $(SOURCE) $(INCLUDE) $(LIBS) -o $@