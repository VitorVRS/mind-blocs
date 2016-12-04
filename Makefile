CC = /usr/bin/g++
OUT = -o bin/run

SRC = src/file/*.cpp \
      src/render/*.cpp \
      src/tiles/*.cpp \
      src/common/*.cpp \
      src/screen/*.cpp \
      src/*.cpp

MAIN = main.cpp

_FLAGS_ = --std=c++11 -lGLU -lGL -lglfw3 -lGLC

build :
	$(CC) $(SRC) $(MAIN) $(OUT) $(_FLAGS_)

.PHONY : build
