CXX = g++


CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = main

SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean