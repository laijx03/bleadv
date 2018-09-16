typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef short unsigned int __uint16_t;
typedef long int __int32_t;
typedef long unsigned int __uint32_t;
typedef long long int __int64_t;
typedef long long unsigned int __uint64_t;
typedef signed char __int_least8_t;
typedef unsigned char __uint_least8_t;
typedef short int __int_least16_t;
typedef short unsigned int __uint_least16_t;
typedef long int __int_least32_t;
typedef long unsigned int __uint_least32_t;
typedef long long int __int_least64_t;
typedef long long unsigned int __uint_least64_t;
typedef int __intptr_t;
typedef unsigned int __uintptr_t;
typedef __int8_t int8_t ;
typedef __uint8_t uint8_t ;
typedef __int16_t int16_t ;
typedef __uint16_t uint16_t ;
typedef __int32_t int32_t ;
typedef __uint32_t uint32_t ;
typedef __int64_t int64_t ;
typedef __uint64_t uint64_t ;
typedef __intptr_t intptr_t;
typedef __uintptr_t uintptr_t;
typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;
typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;
typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
typedef int int_fast8_t;
typedef unsigned int uint_fast8_t;
typedef int int_fast16_t;
typedef unsigned int uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef long long int int_fast64_t;
typedef long long unsigned int uint_fast64_t;
typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
uint16_t utils_crc16(uint8_t *buf, uint32_t length);
uint32_t utils_crc32(uint8_t *buf, uint32_t length);
uint16_t utils_crc16(uint8_t *buf, uint32_t length)
{
	int i;
	unsigned short shift = 0xFFFF, data = 0, val = 0;
	for (i = 0; i < length; i++) {
		if ((i % 8) == 0) {
			data = (*buf++) << 8;
		}
		val = shift ^ data;
		shift = shift << 1;
		data = data << 1;
		if (val & 0x8000) {
			shift = shift ^ 0x1021;
		}
	}
	return shift;
}
uint32_t utils_crc32(uint8_t *buf, uint32_t length)
{
	uint8_t i;
	uint32_t crc = 0xFFFFFFFF;
	while (length--) {
		crc ^= (uint32_t) (*buf++) << 24;
		for (i = 0; i < 8; ++i) {
			if (crc & 0x80000000) {
				crc = (crc << 1) ^ 0x04C11DB7;
			} else {
				crc <<= 1;
			}
		}
	}
	return crc;
}
