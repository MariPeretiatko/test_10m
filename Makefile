CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -Werror -fsanitize=address
LDFLAGS=-lstdc++

TARGET=test
SOURCES=test.cpp
OBJECTS=$(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)
