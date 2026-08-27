CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/sorted_catalog_demo
TEST_TARGET := bin/sorted_catalog_tests
SOURCES := src/main.cpp src/Song.cpp
TEST_SOURCES := tests/test_sorted_catalog.cpp src/Song.cpp

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(SOURCES) include/Song.hpp include/SortedCatalog.hpp include/Algorithms.hpp include/SongFunctors.hpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TEST_TARGET): $(TEST_SOURCES) include/Song.hpp include/SortedCatalog.hpp include/Algorithms.hpp include/SongFunctors.hpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	$(RM) -r bin
