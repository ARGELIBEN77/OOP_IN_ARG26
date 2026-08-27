CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET := bin/store_demo
TEST_TARGET := bin/store_tests
COMMON_SOURCES := src/Product.cpp src/CartItem.cpp src/ProductCatalog.cpp src/ShoppingCart.cpp
SOURCES := src/main.cpp $(COMMON_SOURCES)
TEST_SOURCES := tests/test_store.cpp $(COMMON_SOURCES)

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
	@echo "All Product Catalog and Shopping Cart tests passed."

clean:
	$(RM) -r bin
