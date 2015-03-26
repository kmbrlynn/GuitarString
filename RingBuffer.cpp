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

// ========================================================= accessors/mutators
int RingBuffer::size() {
	//return the number of elements in the ring

}

bool RingBuffer::isEmpty() {


}

bool RingBuffer::isFull() {


}

void RingBuffer::enqueue(int16_t x) {
	_buffer.at(_last) = x;
	_last++;
	
	// if _last falls off the end, wrap it around
	if (_last > _capacity-1) {
		_last = 0;

		// if this has happened and first/last indices match, it's full
		if (_first == 0) _full = true;
		else _full = false;
	}
}

int16_t RingBuffer::dequeue() {
	int16_t dequeued = _buffer.at(_first);
	_first++;

	// if _first falls off the end, wrap it around
	if (_first > _capacity-1)
		_first = 0;

		// if this has happened and first/last indices match, it's empty
		if (_last == 0) _empty = true;
		else _empty = false;

	return dequeued;
}

int16_t RingBuffer::peek() {

}


