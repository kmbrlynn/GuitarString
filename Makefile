CC = g++
CFLAGS = -Wall -Werror -ansi -pendantic -g

all: ps5a

ps5a: test.o RingBuffer.o
	$(CC) $(FLAGS) -o ps5a test.o RingBuffer.o -lboost_unit_test_framework

test.o: test.cpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c test.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c RingBuffer.cpp

clean:
	rm -rf ps5a *.o *.~
