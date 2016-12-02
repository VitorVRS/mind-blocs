CC = /usr/bin/g++
OUT = -o bin/run

SRC = src/file/*.cpp \
      src/render/*.cpp \
      src/tiles/*.cpp \
      src/common/*.cpp \
      src/screen/*.cpp \
      src/*.cpp

MAIN = main.cpp

_FLAGS_ = -g --std=c++11 -lGLU -lGL -lglfw

build :
	$(CC) $(SRC) $(MAIN) $(OUT) $(_FLAGS_)

.PHONY : build
