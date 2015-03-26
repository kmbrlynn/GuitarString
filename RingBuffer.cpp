// copyright Kim Douglas 2015
#include <vector>
#include "RingBuffer.hpp"

// ============================================================ con/destructors
RingBuffer::RingBuffer(int capacity) :
	_first(0), _last(0), _capacity(capacity) {
    
	_buffer.resize(_capacity);
}

RingBuffer::~RingBuffer() {

}

// ================================================================== accessors
int RingBuffer::size() {
	if (_empty == true) return 0;
	if (_full == true) return _capacity;
	
	if (_last > _first)
		return _last - _first;
	if (_first > _last)
		return 
}

bool RingBuffer::isEmpty() {
	return _empty;
}

bool RingBuffer::isFull() {
	return _full;
}

int16_t RingBuffer::peek() {
	return _first;
}

// =================================================================== mutators
void RingBuffer::enqueue(int16_t x) {
	_buffer.at(_last) = x;
	_last++;
	
	// if _last falls off the end, wrap it around
	if (_last == _capacity)
		_last = 0;
	
	// if _last and _first are the same after enqueueing, it's full
	if (_last == _first) _full = true;
	else _full = false;
}

int16_t RingBuffer::dequeue() {
	int16_t dequeued = _buffer.at(_first);
	_first++;

	// if _first falls off the end, wrap it around
	if (_first == _capacity)
		_first = 0;

	// if _first and _last are the same after dequeuing, it's empty
	if (_first == _last) _empty = true;
	else _empty = false;

	return dequeued;
}
