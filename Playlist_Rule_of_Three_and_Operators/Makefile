CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/playlist_demo
TEST_TARGET := bin/playlist_tests
COMMON_SOURCES := src/Song.cpp src/Playlist.cpp
SOURCES := src/main.cpp $(COMMON_SOURCES)
TEST_SOURCES := tests/test_playlist.cpp $(COMMON_SOURCES)

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)
	@echo "All Playlist tests passed."

clean:
	$(RM) -r bin
