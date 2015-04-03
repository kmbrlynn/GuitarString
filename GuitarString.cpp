// copyright Kim Douglas 2015
#include <SFML/Audio.hpp>
#include <cmath>
#include "GuitarString.hpp"

const int SAMPLING_RATE = 44100;

// ============================================================ con/destructors
GuitarString::GuitarString(double frequency) {
	_n = ceil(SAMPLING_RATE/frequency);


}

GuitarString::GuitarString(std::vector<sf::Int16>) {

}

GuitarString::~GuitarString() {
	delete _rb;
}

// ================================================================== accessors
sf::Int16 GuitarString::sample() {

}

int GuitarString::time() {

}

// =================================================================== mutators
void GuitarString::pluck() {

}

void GuitarString::tic() {

}









