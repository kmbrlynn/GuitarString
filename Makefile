CC = g++
CFLAGS = -Wall -Werror -ansi -pendantic -g

all: GuitarHero

GStest: GStest.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GStest GStest.o GuitarString.o RingBuffer.o -lboost_unit_test_framework

GuitarHero: GuitarHero.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GuitarHero GuitarHero.o GuitarString.o RingBuffer.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

GStest.o: GStest.cpp GuitarString.cpp RingBuffer.cpp
	$(CC) $(FLAGS) -c GStest.cpp

GuitarHero.o: GuitarHero.cpp GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarHero.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c RingBuffer.cpp

clean:
	rm -rf GuitarHero GStest *.o *.~
