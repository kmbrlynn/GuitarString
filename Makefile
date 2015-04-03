CC = g++
CFLAGS = -Wall -Werror -ansi -pendantic -g

all: GuitarHero

GuitarHero: GuitarHeroLite.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GuitarHero GuitarHeroLite.o GuitarString.o RingBuffer.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

GuitarHeroLite.o: GuitarHeroLite.cpp GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarHeroLite.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c RingBuffer.cpp

clean:
	rm -rf GuitarHero *.o *.~
