// copyright Kim Douglas 2015
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include "RingBuffer.hpp"

std::string capacity_error = "constructor: capacity must be greater than 0";
std::string enqueue_error = "enqueue: cannot enque to a full buffer";
std::string dequeue_error = "dequeue: cannot dequeue from an empty buffer";
std::string peek_error = "peek: cannot peek at an empty buffer";

// ============================================================ con/destructors
RingBuffer::RingBuffer(int capacity) {
    if (capacity < 1)
        throw
            std::invalid_argument(capacity_error);

    _first = 0;
    _last = 0;
    _full = false;
    _capacity = capacity;
    _buffer.resize(_capacity);
}

RingBuffer::~RingBuffer() {
}

// ================================================================== accessors
int RingBuffer::size() {
    if (_full == false) return 0;
    if (_full == true) return _capacity;
    if (_last > _first) return _last - _first;

    if (_first > _last) {
        int end_chunk = _capacity - _first;
        int beginning_chunk = _last;
        return end_chunk + beginning_chunk;
    }
}

bool RingBuffer::isEmpty() {
    if (_first == _last && _full == false) return true;
    else
        return false;
}

bool RingBuffer::isFull() {
    if (_first == _last && _full == true) return true;
    else
        return false;
}

int16_t RingBuffer::peek() {
    if (isEmpty())
        throw
            std::runtime_error(peek_error);
    else
        return _buffer.at(_first);
}

// =================================================================== mutators
void RingBuffer::enqueue(int16_t x) {
    if (isFull())
        throw
            std::runtime_error(enqueue_error);

    _buffer.at(_last) = x;
    _last++;

    // if _last falls off the end, wrap it around
    if (_last == _capacity)
        _last = 0;

    // if _last and _first are the same after enqueueing, it's full
    if (_last == _first)
        _full = true;
}

int16_t RingBuffer::dequeue() {
    if (isEmpty())
        throw
            std::runtime_error(dequeue_error);

    int16_t dequeued = _buffer.at(_first);
    _first++;

    // if _first falls off the end, wrap it around
    if (_first == _capacity)
        _first = 0;

    // if _first and _last are the same after dequeuing, it's empty
    if (_first == _last)
        _full = false;

    return dequeued;
}
