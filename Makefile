CC = g++
CFLAGS = -g -Wall
TARGET   = ./build/login

login:	login.cpp
	$(CC) login.cpp -o $(TARGET)
