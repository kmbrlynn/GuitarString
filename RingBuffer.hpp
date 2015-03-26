// copyright Kim Douglas 2015
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
	bool _full, _empty;
	std::vector<int16_t> _buffer;

};
