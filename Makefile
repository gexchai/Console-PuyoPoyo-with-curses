PROGRAM = puyo
BIN_DIR = bin
TARGET = $(BIN_DIR)/$(PROGRAM)

## compiler ##
CC = g++

## src ##
SRC_DIR   = src
SRC_FILE  = main.cpp
SRC_FILE += Keypad.cpp Screen.cpp
SRC_FILE += Game.cpp
SRC_FILE += Scene.cpp PlayScene.cpp TitleScene.cpp ConfigScene.cpp
SRC_FILE += Field.cpp PlayField.cpp ScoreField.cpp NextField.cpp TitleField.cpp
SRC_FILE += Puyo.cpp PuyoPair.cpp PuyoFloat.cpp
SRCS      = $(SRC_FILE:%=$(SRC_DIR)/%)

## obj ##
OBJ_DIR  = obj
OBJ_FILE = $(SRC_FILE:%.cpp=%.o)
OBJS     = $(OBJ_FILE:%=$(OBJ_DIR)/%)
#DIRS     = $(OBJ_DIR) $(BIN_DIR)

# header path
INCLUDE_DIR = include

# compile option
CFLAGS = -Wall -g
LFLAGS = -L/usr/lib -lcurses -ltermcap

all: $(TARGET)

$(TARGET): $(OBJS) #$(BIN_DIR)
	mkdir -p $(BIN_DIR)
	$(CC)  $(LFLAGS) -I./$(INCLUDE_DIR) -o $@ $^ #$(OBJS)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp #$(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	$(CC)  $(CFLAGS) -I./$(INCLUDE_DIR) -o $@ -c $<

#$(BIN_DIR):
#	mkdir -p $(BIN_DIR)

#$(OBJ_DIR):
#	mkdir -p $(OBJ_DIR)

run:
	./$(TARGET)

debug:
	gdb ./$(TARGET)

clean:
	rm -r $(OBJ_DIR)
	rm -r $(BIN_DIR)
