CC = g++

CFLAGS= -g -std=c++11 -Wall -O2

TARGET = main

SRCS := $(wildcard *.cpp)  

OBJS := $(patsubst %cpp, %o, $(SRCS))  

all: $(TARGET)  

$(TARGET): $(OBJS)  
	$(CC) $(CFLAGS) -o $@ $^
	rm *.o

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

clean:  
	rm -f *.o $(TARGET) 
