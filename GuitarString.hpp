// copyright Kim Douglas 2015
#ifndef GUITAR_STRING_H
#define GUITAR_STRING_H
#include <SFML/Audio.hpp>
#include "RingBuffer.hpp"

class GuitarString {
 public:
 	GuitarString(double frequency);
	GuitarString(std::vector<sf::Int16> init);
	~GuitarString();

	sf::Int16 sample();
	int time();

	void pluck();
	void tic();

 private:
	RingBuffer* _rb;
	int _n, _t;
};

#endif
