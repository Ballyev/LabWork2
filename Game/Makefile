CC = g++
CXXFLAGS = -Werror -Wpedantic -Wall -std=c++17 -pthread -I/usr/include
LDFLAGS_TEST = -pthread /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a -lpthread

SRC_DIRS = \
    src \
    src/obj \
    src/Skills \
    src/dungeon \
    src/all_characters \
    src/all_characters/hero \
    src/all_characters/hero/mage \
    src/all_characters/hero/rogue \
    src/all_characters/hero/warrior \
    src/BattleSystem \
    src/Enemy

SOURCES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
OBJECTS = $(SOURCES:.cpp=.o)

MAIN_SRC = main.cpp
TEST_SRC = tests/tests.cpp

MAIN_OBJ = main.o
TEST_OBJ = tests/tests.o

EXEC_GAME = game
EXEC_TEST = run_tests

all: $(EXEC_GAME)

$(EXEC_GAME): $(OBJECTS) $(MAIN_OBJ)
	$(CC) $(CXXFLAGS) $^ -o $@

$(EXEC_TEST): $(OBJECTS) $(TEST_OBJ)
	$(CC) $(CXXFLAGS) $^ -o $@ $(LDFLAGS_TEST)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

main.o: $(MAIN_SRC)
	$(CC) $(CXXFLAGS) -c $(MAIN_SRC) -o $@

tests.o: $(TEST_SRC)
	$(CC) $(CXXFLAGS) -c $(TEST_SRC) -o $@

test: $(EXEC_TEST)
	./$(EXEC_TEST)

run: $(EXEC_GAME)
	./$(EXEC_GAME)

clean:
	rm -rf $(EXEC_GAME) $(EXEC_TEST) $(OBJECTS) $(MAIN_OBJ) $(TEST_OBJ) *.o