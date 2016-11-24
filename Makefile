CC = /usr/bin/g++-5
OUT = -o bin/run

SRC = src/file/*.cpp \
      src/render/*.cpp \
      src/tiles/*.cpp \
      src/common/*.cpp

MAIN = main.cpp

_FLAGS_ = --std=c++11 -lGLU -lGL -lglut

build :
	$(CC) $(SRC) $(MAIN) $(OUT) $(_FLAGS_)

.PHONY : build
