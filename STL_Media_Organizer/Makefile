CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude

.PHONY: all run test clean

all: demo

demo: src/main.cpp include/Track.hpp include/MediaOrganizer.hpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o demo

tests_runner: tests/test.cpp include/Track.hpp include/MediaOrganizer.hpp
	$(CXX) $(CXXFLAGS) tests/test.cpp -o tests_runner

run: demo
	./demo

test: tests_runner
	./tests_runner

clean:
	rm -f demo tests_runner
