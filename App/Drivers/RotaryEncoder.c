#include <Drivers/RotaryEncoder.h>

static uint8_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

void RotaryEncoderInit(RotaryEncoder *encoder)
{
	encoder->position = 0;
	encoder->prevNextCode = 0;
	encoder->store = 0;
}

void RotaryEncoderISR(RotaryEncoder *encoder, uint8_t encA, uint8_t encB)
{
	encoder->prevNextCode <<= 2;
	if (encA) {
		encoder->prevNextCode |= 0x02;
	}
	if (encB) {
		encoder->prevNextCode |= 0x01;
	}
	encoder->prevNextCode &= 0x0f;

	if (rot_enc_table[encoder->prevNextCode]) {
		encoder->store <<= 4;
		encoder->store |= encoder->prevNextCode;
		if ((encoder->store & 0xff) == 0x2b) {
			encoder->position--;
		}
		else if ((encoder->store & 0xff) == 0x17) {
			encoder->position++;
		}
	}
}
