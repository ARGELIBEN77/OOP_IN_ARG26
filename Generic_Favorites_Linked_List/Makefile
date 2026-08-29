CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/favorites_list_demo
TEST_TARGET := bin/favorites_list_tests
SOURCES := src/main.cpp src/Song.cpp
TEST_SOURCES := tests/test_favorites_list.cpp src/Song.cpp
HEADERS := include/FavoritesList.hpp include/Algorithms.hpp include/Song.hpp include/SongPredicates.hpp

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TEST_TARGET): $(TEST_SOURCES) $(HEADERS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	$(RM) -r bin
