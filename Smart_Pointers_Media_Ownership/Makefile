CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/smart_pointer_demo
TEST_TARGET := bin/smart_pointer_tests
COMMON_SOURCES := src/MediaItem.cpp src/Song.cpp src/MediaLibrary.cpp src/Playlist.cpp
SOURCES := src/main.cpp $(COMMON_SOURCES)
TEST_SOURCES := tests/test_smart_pointers.cpp $(COMMON_SOURCES)
HEADERS := include/MediaItem.hpp include/Song.hpp include/MediaLibrary.hpp include/Playlist.hpp

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
