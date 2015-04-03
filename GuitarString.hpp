// copyright Kim Douglas 2015
#include <SFML/Audio.hpp>
#include "RingBuffer.hpp"

class GuitarString {
 public:
 	GuitarString(double frequency);
	GuitarString(std::vector<sf::Int16> init);
	
	void pluck();
	void tic();

	sf::Int16 sample();
	int time();

 private:
	RingBuffer* _rb;
	int _n;
};
