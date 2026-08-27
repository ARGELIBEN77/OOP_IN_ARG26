CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/song_class_demo
BEFORE_TARGET := bin/procedural_song_demo
TEST_TARGET := bin/song_tests

.PHONY: all run before compare test clean

all: $(TARGET)

$(TARGET): src/main.cpp src/Song.cpp include/Song.hpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) src/main.cpp src/Song.cpp -o $(TARGET)

$(BEFORE_TARGET): examples/ProceduralSong.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) examples/ProceduralSong.cpp -o $(BEFORE_TARGET)

run: $(TARGET)
	./$(TARGET)

before: $(BEFORE_TARGET)
	./$(BEFORE_TARGET)

compare: before run

$(TEST_TARGET): tests/test_song.cpp src/Song.cpp include/Song.hpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) tests/test_song.cpp src/Song.cpp -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)
	@echo "All Song class tests passed."

clean:
	$(RM) -r bin
