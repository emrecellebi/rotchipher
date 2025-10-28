@echo off

set CFLAGS=-Wall -Wextra -std=c11 -pedantic
set SRC_DIR=./src/*.cpp
set INC_DIR=-I ./include
set LIB_DIR=-L ./lib
set LIB_ARGS=

g++ -g -c %SRC_DIR% %INC_DIR%
g++ %CFLAGS% -o ./bin/rotchipher.exe *.o %LIB_DIR% %LIB_ARGS%

del *.o