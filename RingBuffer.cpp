// copyright Kim Douglas 2015
#include "RingBuffer.hpp"

// ============================================================ con/destructors
RingBuffer::RingBuffer(int capacity) : _capacity(capacity) {
	_first = 5;

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


}

int16_t RingBuffer::dequeue() {
	_first--;
	return _first;

}

int16_t RingBuffer::peek() {

}


