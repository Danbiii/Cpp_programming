CC = g++
TARGET = pushbox
SOURCES = screen.cpp\
	map.cpp\
	pushBox.cpp

LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
