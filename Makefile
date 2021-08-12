.PHONY: all

CC = cc

CXX = c++

C_FLAGS = -Wall

LIB_LUA = -llua5.4 -lreadline

LIB_LUA_OLD = -llua5.3

LUA_INTERPRETER = lua5.4

LUA_C_LIBRARY = -shared -fPIC
all:
	$(CC) lxkinit.c $(C_FLAGS) $(LIB_LUA) -shared -o ./obj/lxkinit.o
	$(CC) laccess.c $(C_FLAGS) $(LIB_LUA) $(LUA_C_LIBRARY) -o ./obj/lkuxFS.so