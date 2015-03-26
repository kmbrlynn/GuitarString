// copyright Kim Douglas 2015
#include <vector>
#include "RingBuffer.hpp"

// ============================================================ con/destructors
RingBuffer::RingBuffer(int capacity) :
	_first(0), _size(0), _capacity(capacity) {
    
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
	int last = (_first + _size-1) % _buffer._capacity;
	
/*	_buffer.at(_last) = x;
	_last++;
	
	// if _last falls off the end, wrap it around
	if (_last > _capacity)
		_last = 0;
*/
}


int16_t RingBuffer::dequeue() {
	int16_t dequeued = _buffer.at(_first);
	_first = (_first+1) % _buffer._capacity;

/*	int16_t dequeued = _buffer.at(_first);
	_first++;

	// if _first falls off the end, wrap it around
	if (_first > _capacity)
		_first = 0;

	return dequeued;
*/
	return dequeued;
}

int16_t RingBuffer::peek() {

}


