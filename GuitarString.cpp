// copyright Kim Douglas 2015
#include <SFML/Audio.hpp>
#include <cmath>
#include "GuitarString.hpp"

const int SAMPLING_RATE = 44100;

// ============================================================ con/destructors
GuitarString::GuitarString(double frequency) {
	_n = ceil(SAMPLING_RATE/frequency);
	_rb = new RingBuffer(_n);

	while (_rb->isFull() == false) {
		_rb->enqueue(0);
	}

}

GuitarString::GuitarString(std::vector<sf::Int16> init) {
	_rb = new RingBuffer(init.size());

	std::vector<sf::Int16>::iterator it;
	for (it = init.begin(); it != init.end(); ++it) {
		_rb->enqueue(*it);
	}
}

GuitarString::~GuitarString() {
	delete _rb;
}

// ================================================================== accessors
sf::Int16 GuitarString::sample() {
	return _rb->peek();
}

int GuitarString::time() {
	return _t;
}

// =================================================================== mutators
void GuitarString::pluck() {
	while (_rb->isEmpty() != true) {
		_rb->dequeue();
	}

	for (int i = 0; i < _n; i++) {
		_rb->enqueue((sf::Int16)(rand() & 0xffff));
	}
}

void GuitarString::tic() {
	sf::Int16 first = _rb->dequeue();
	sf::Int16 second = _rb->peek();

	sf::Int16 decayed = 0.996 * (first + second) / 2.0;
	_rb->enqueue(decayed);
	_t++;
}









