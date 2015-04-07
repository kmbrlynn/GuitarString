// copyright Kim Douglas 2015
#ifndef RING_BUF_H
#define RING_BUF_H
#include <stdint.h>
#include <vector>

class RingBuffer {
 public:
    explicit RingBuffer(int capacity);
    ~RingBuffer();
    int size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();

 private:
    int _first, _last, _capacity;
    bool _full;  // false = empty
    std::vector<int16_t> _buffer;
};

#endif
