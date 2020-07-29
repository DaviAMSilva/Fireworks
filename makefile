CC = gcc

ODIR   = build
TARGET = Fireworks
LIBS   = -lncurses

SOURCE 	= $(wildcard *.c)
OBJECT  = $(patsubst %.c, $(ODIR)/%.o, $(SOURCE))
INCLUDE	= $(wildcard *.h)

.PHONY: all clean

all: $(TARGET)

$(ODIR)/%.o: %.c $(INCLUDE) | $(ODIR)
	$(CC) $< -c -o $@ $(LIBS)

$(TARGET): $(OBJECT) $(INCLUDE)
	$(CC) $^ -o $@ $(LIBS)

$(ODIR):
	mkdir -p $@

clean: | $(ODIR)
	rm -f $(ODIR)/*.o