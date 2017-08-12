CC=g++
CFLAGS=-s
BINDIR =/usr/games
TARGET =casino
casino: main.cpp gamble.hpp gamble.h
		$(CC) -s main.cpp gamble.hpp gamble.h -o casino
install:
		install -D -s $(TARGET) $(BINDIR)/$(TARGET)
uninstall:
		-rm $(BINDIR)/$(TARGET)
