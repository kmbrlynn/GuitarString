CC = g++
CFLAGS = -Wall -Werror -ansi -pendantic -g

all: GuitarHero

GStest: GStest.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GStest GStest.o GuitarString.o RingBuffer.o -lboost_unit_test_framework

GuitarHero: GuitarHeroLite.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GuitarHero GuitarHeroLite.o GuitarString.o RingBuffer.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

GStest.o: GStest.cpp GuitarString.cpp RingBuffer.cpp
	$(CC) $(FLAGS) -c GStest.cpp

GuitarHeroLite.o: GuitarHeroLite.cpp GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarHeroLite.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c RingBuffer.cpp

clean:
	rm -rf GuitarHero GStest *.o *.~
