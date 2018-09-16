typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef unsigned int wchar_t;
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
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
struct tc_sha256_state_struct {
	unsigned int iv[((32)/4)];
	uint64_t bits_hashed;
	uint8_t leftover[(64)];
	size_t leftover_offset;
};
typedef struct tc_sha256_state_struct *TCSha256State_t;
int tc_sha256_init(TCSha256State_t s);
int tc_sha256_update (TCSha256State_t s, const uint8_t *data, size_t datalen);
int tc_sha256_final(uint8_t *digest, TCSha256State_t s);
unsigned int _copy(uint8_t *to, unsigned int to_len,
		const uint8_t *from, unsigned int from_len);
void _set(void *to, uint8_t val, unsigned int len);
uint8_t _double_byte(uint8_t a);
int _compare(const uint8_t *a, const uint8_t *b, size_t size);
static void compress(unsigned int *iv, const uint8_t *data);
int tc_sha256_init(TCSha256State_t s)
{
	if (s == (TCSha256State_t) 0) {
		return 0;
	}
	_set((uint8_t *) s, 0x00, sizeof(*s));
	s->iv[0] = 0x6a09e667;
	s->iv[1] = 0xbb67ae85;
	s->iv[2] = 0x3c6ef372;
	s->iv[3] = 0xa54ff53a;
	s->iv[4] = 0x510e527f;
	s->iv[5] = 0x9b05688c;
	s->iv[6] = 0x1f83d9ab;
	s->iv[7] = 0x5be0cd19;
	return 1;
}
int tc_sha256_update(TCSha256State_t s, const uint8_t *data, size_t datalen)
{
	if (s == (TCSha256State_t) 0 ||
			data == (void *) 0) {
		return 0;
	} else if (datalen == 0) {
		return 1;
	}
	while (datalen-- > 0) {
		s->leftover[s->leftover_offset++] = *(data++);
		if (s->leftover_offset >= (64)) {
			compress(s->iv, s->leftover);
			s->leftover_offset = 0;
			s->bits_hashed += ((64) << 3);
		}
	}
	return 1;
}
int tc_sha256_final(uint8_t *digest, TCSha256State_t s)
{
	unsigned int i;
	if (digest == (uint8_t *) 0 ||
			s == (TCSha256State_t) 0) {
		return 0;
	}
	s->bits_hashed += (s->leftover_offset << 3);
	s->leftover[s->leftover_offset++] = 0x80;
	if (s->leftover_offset > (sizeof(s->leftover) - 8)) {
		_set(s->leftover + s->leftover_offset, 0x00,
				sizeof(s->leftover) - s->leftover_offset);
		compress(s->iv, s->leftover);
		s->leftover_offset = 0;
	}
	_set(s->leftover + s->leftover_offset, 0x00,
			sizeof(s->leftover) - 8 - s->leftover_offset);
	s->leftover[sizeof(s->leftover) - 1] = (uint8_t)(s->bits_hashed);
	s->leftover[sizeof(s->leftover) - 2] = (uint8_t)(s->bits_hashed >> 8);
	s->leftover[sizeof(s->leftover) - 3] = (uint8_t)(s->bits_hashed >> 16);
	s->leftover[sizeof(s->leftover) - 4] = (uint8_t)(s->bits_hashed >> 24);
	s->leftover[sizeof(s->leftover) - 5] = (uint8_t)(s->bits_hashed >> 32);
	s->leftover[sizeof(s->leftover) - 6] = (uint8_t)(s->bits_hashed >> 40);
	s->leftover[sizeof(s->leftover) - 7] = (uint8_t)(s->bits_hashed >> 48);
	s->leftover[sizeof(s->leftover) - 8] = (uint8_t)(s->bits_hashed >> 56);
	compress(s->iv, s->leftover);
	for (i = 0; i < ((32)/4); ++i) {
		unsigned int t = *((unsigned int *) &s->iv[i]);
		*digest++ = (uint8_t)(t >> 24);
		*digest++ = (uint8_t)(t >> 16);
		*digest++ = (uint8_t)(t >> 8);
		*digest++ = (uint8_t)(t);
	}
	_set(s, 0, sizeof(*s));
	return 1;
}
static const unsigned int k256[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
static inline unsigned int ROTR(unsigned int a, unsigned int n)
{
	return (((a) >> n) | ((a) << (32 - n)));
}
static inline unsigned int BigEndian(const uint8_t **c)
{
	unsigned int n = 0;
	n = (((unsigned int)(*((*c)++))) << 24);
	n |= ((unsigned int)(*((*c)++)) << 16);
	n |= ((unsigned int)(*((*c)++)) << 8);
	n |= ((unsigned int)(*((*c)++)));
	return n;
}
static void compress(unsigned int *iv, const uint8_t *data)
{
	unsigned int a, b, c, d, e, f, g, h;
	unsigned int s0, s1;
	unsigned int t1, t2;
	unsigned int work_space[16];
	unsigned int n;
	unsigned int i;
	a = iv[0]; b = iv[1]; c = iv[2]; d = iv[3];
	e = iv[4]; f = iv[5]; g = iv[6]; h = iv[7];
	for (i = 0; i < 16; ++i) {
		n = BigEndian(&data);
		t1 = work_space[i] = n;
		t1 += h + (ROTR((e), 6) ^ ROTR((e), 11) ^ ROTR((e), 25)) + (((e) & (f)) ^ ((~(e)) & (g))) + k256[i];
		t2 = (ROTR((a), 2) ^ ROTR((a), 13) ^ ROTR((a), 22)) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
		h = g; g = f; f = e; e = d + t1;
		d = c; c = b; b = a; a = t1 + t2;
	}
	for ( ; i < 64; ++i) {
		s0 = work_space[(i+1)&0x0f];
		s0 = (ROTR((s0), 7) ^ ROTR((s0), 18) ^ ((s0) >> 3));
		s1 = work_space[(i+14)&0x0f];
		s1 = (ROTR((s1), 17) ^ ROTR((s1), 19) ^ ((s1) >> 10));
		t1 = work_space[i&0xf] += s0 + s1 + work_space[(i+9)&0xf];
		t1 += h + (ROTR((e), 6) ^ ROTR((e), 11) ^ ROTR((e), 25)) + (((e) & (f)) ^ ((~(e)) & (g))) + k256[i];
		t2 = (ROTR((a), 2) ^ ROTR((a), 13) ^ ROTR((a), 22)) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
		h = g; g = f; f = e; e = d + t1;
		d = c; c = b; b = a; a = t1 + t2;
	}
	iv[0] += a; iv[1] += b; iv[2] += c; iv[3] += d;
	iv[4] += e; iv[5] += f; iv[6] += g; iv[7] += h;
}
