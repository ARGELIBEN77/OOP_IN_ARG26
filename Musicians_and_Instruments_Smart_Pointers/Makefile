CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/musicians_demo
TEST_TARGET := bin/musicians_tests
COMMON_SOURCES := src/Instrument.cpp src/Musician.cpp src/Ensemble.cpp
SOURCES := src/main.cpp $(COMMON_SOURCES)
TEST_SOURCES := tests/test_musicians.cpp $(COMMON_SOURCES)
HEADERS := include/Instrument.hpp include/Musician.hpp include/Ensemble.hpp \
	include/UniquePointer.hpp include/SharedPointer.hpp

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
