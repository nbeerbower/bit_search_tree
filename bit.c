#include "bit.h"

uint8_t bit_at(byte_t byte, uint8_t i) {
	byte_t temp = (byte >> (7-i));
	return (temp & 0x01);
}
