CC = g++
CFLAGS = -Wall -Werror -ansi -pendantic -g

all: GuitarHero

GuitarHero: GuitarHero.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GuitarHero GuitarHero.o GuitarString.o RingBuffer.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# ============================================================================== tests
GuitarHeroLite: GuitarHeroLite.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GuitarHeroLite GuitarHeroLite.o GuitarString.o RingBuffer.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

GStest: GStest.o GuitarString.o RingBuffer.o
	$(CC) $(FLAGS) -o GStest GStest.o GuitarString.o RingBuffer.o -lboost_unit_test_framework

# ============================================================================ objects
GuitarHero.o: GuitarHero.cpp GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarHero.cpp

GuitarHeroLite.o: GuitarHeroLite.cpp GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarHeroLite.cpp

GStest.o: GStest.cpp GuitarString.cpp RingBuffer.cpp
	$(CC) $(FLAGS) -c GStest.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(FLAGS) -c RingBuffer.cpp

clean:
	rm -rf GuitarHero GStest GuitarHeroLite *.o *.~
