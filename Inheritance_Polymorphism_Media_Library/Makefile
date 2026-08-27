CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/media_library_demo
TEST_TARGET := bin/media_library_tests
COMMON_SOURCES := src/MediaItem.cpp src/Song.cpp src/PodcastEpisode.cpp src/Audiobook.cpp src/MusicLibrary.cpp
SOURCES := src/main.cpp $(COMMON_SOURCES)
TEST_SOURCES := tests/test_media_library.cpp $(COMMON_SOURCES)

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
	@echo "All inheritance and polymorphism tests passed."

clean:
	$(RM) -r bin
