CC=g++
CFLAGS=-Werror -Wpedantic -Wall -std=c++17
LDFLAGS=-lgtest -lgtest_main -lpthread

SOURCE_DIRECTORIES = src src/obj src/Skills src/dungeon src/combat_system src/all_characters src/all_characters/hero/mage rogue warrior
SOURCES = $(wildcard src/**/*.cpp) main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE=test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) *.mk



