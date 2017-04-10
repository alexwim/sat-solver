TARGET = sat
CXX = g++
CPPFLAGS = -Wall
BIN_DIR = ./bin
SRC_DIR = ./source

.PHONY: default all clean

default: $(BIN_DIR)/$(TARGET)
all: default

OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))
HEADERS = $(wildcard $(SRC_DIR)/*.h)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CPPFLAGS) -o $@

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(BIN_DIR)/$(TARGET)
