#pragma once

#include <stdint.h>

// See https://www.best-microcontroller-projects.com/rotary-encoder.html
// I actually have another better encoder driver but it I wrote it for a company and it is considered proprietary and I'm not allowed to post it publicly
// However, this gives me a perfect test case; using someone else's rotary encoder algorithm with unity to test it out

typedef struct {
	uint8_t position; // arbitrarily limit to 256 values
	// Internal
	uint8_t store; // TODO use better names than this
	uint16_t prevNextCode;
} RotaryEncoder;

void RotaryEncoderInit(RotaryEncoder *encoder);
void RotaryEncoderISR(RotaryEncoder *encoder, uint8_t encA, uint8_t encB);
