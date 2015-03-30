// copyright Kim Douglas 2015
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RingBufferConstructor) {
    // normal constructor
    BOOST_REQUIRE_NO_THROW(RingBuffer(100));

    // this should fail
    BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RingBufferEnqueue_dequeue) {
    RingBuffer rb(100);

    rb.enqueue(2);
    rb.enqueue(1);
    rb.enqueue(0);

    BOOST_REQUIRE(rb.dequeue() == 2);
    BOOST_REQUIRE(rb.dequeue() == 1);
    BOOST_REQUIRE(rb.dequeue() == 0);

    BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RingBuffer_peek) {
    RingBuffer rb(3);

    rb.enqueue(2);
    rb.dequeue();
  
    BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
}




