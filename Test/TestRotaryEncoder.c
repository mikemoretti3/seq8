#include "unity.h"
#include "Drivers/RotaryEncoder.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void testRotaryEncoderDriver(void)
{
    // TODO this should have way more complete test cases than the simple stuff done here; like testing actual real world scenarios with what a noisy encoder would produce
    RotaryEncoder encoder;
    RotaryEncoderInit(&encoder);
    TEST_ASSERT_EQUAL(0, encoder.position);

    // TODO ok, I guess I didn't quite properly understand the original algorithm; I forgot that the encoder position only changes at 0x2b and 0x17
    // I've already spent way too much time and brain power trying to come up with what I thought would be proper tests/responses on an exercise whose code I don't plan to use anyway.  TBD later if ever.

    // Current state: 0000
    RotaryEncoderISR(&encoder,0,0);
    // New state: 0000 invalid - no move
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Current state: 0000
    RotaryEncoderISR(&encoder,1,1);
    // New state: 0011 invalid - no move
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Current state: 0011
    RotaryEncoderISR(&encoder,0,0);
    // New state: 1100 invalid - no move
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Current state: 1100
    RotaryEncoderISR(&encoder,1,1);
    // New state: 1111 invalid - no move
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Current state: 1111
    RotaryEncoderISR(&encoder,1,1);
    // New state: 1111 invalid - no move
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Current state: 1111
    RotaryEncoderISR(&encoder,1,0);
    // New state: 1110 move cw
    TEST_ASSERT_EQUAL(1, encoder.position);

    // Current state: 1110
    RotaryEncoderISR(&encoder,1,0);
    // New state: 1010 invalid - no move
    TEST_ASSERT_EQUAL(1, encoder.position);

    // Current state: 1010
    RotaryEncoderISR(&encoder,1,0);
    // New state: 1010 invalid - no move
    TEST_ASSERT_EQUAL(1, encoder.position);

    // Current state: 1010
    RotaryEncoderISR(&encoder,0,0);
    // New state: 1000 move cw
    TEST_ASSERT_EQUAL(2, encoder.position);

    // Current state: 1000
    RotaryEncoderISR(&encoder,0,1);
    // New state: 0001 cw
    TEST_ASSERT_EQUAL(3, encoder.position);

    // Current state: 0001
    RotaryEncoderISR(&encoder,0,1);
    // New state: 0101 invalid - no move
    TEST_ASSERT_EQUAL(3, encoder.position);

    // Current state: 0101
    RotaryEncoderISR(&encoder,0,1);
    // New state: 0101 invalid - no move
    TEST_ASSERT_EQUAL(3, encoder.position);

    // Current state: 0101
    RotaryEncoderISR(&encoder,1,0);
    // New state: 0110 invalid - no move
    TEST_ASSERT_EQUAL(3, encoder.position);

    // Current state: 0110
    RotaryEncoderISR(&encoder,1,1);
    // New state: 1011 ccw
    TEST_ASSERT_EQUAL(2, encoder.position);

    // Current state: 1011
    RotaryEncoderISR(&encoder,0,1);
    // New state: 1101 ccw
    TEST_ASSERT_EQUAL(1, encoder.position);

    // Current state: 1101
    RotaryEncoderISR(&encoder,0,0);
    // New state: 0100 ccw
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Current state: 0100
    RotaryEncoderISR(&encoder,1,0);
    // New state: 0010 ccw
    TEST_ASSERT_EQUAL(255, encoder.position);

    // Current state: 0010
    RotaryEncoderISR(&encoder,0,1);
    // New state: 1001 invalid - no move
    TEST_ASSERT_EQUAL(255, encoder.position);

    // Current state: 1001
    RotaryEncoderISR(&encoder,1,1);
    // New state: 0111 cw
    TEST_ASSERT_EQUAL(0, encoder.position);

    // Final state: 0111
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testRotaryEncoderDriver);
	return UNITY_END();
}
