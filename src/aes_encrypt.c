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
typedef struct tc_aes_key_sched_struct {
	unsigned int words[(4)*((10)+1)];
} *TCAesKeySched_t;
int tc_aes128_set_encrypt_key(TCAesKeySched_t s, const uint8_t *k);
int tc_aes_encrypt(uint8_t *out, const uint8_t *in,
		const TCAesKeySched_t s);
int tc_aes128_set_decrypt_key(TCAesKeySched_t s, const uint8_t *k);
int tc_aes_decrypt(uint8_t *out, const uint8_t *in,
		const TCAesKeySched_t s);
typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef unsigned int wchar_t;
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
unsigned int _copy(uint8_t *to, unsigned int to_len,
		const uint8_t *from, unsigned int from_len);
void _set(void *to, uint8_t val, unsigned int len);
uint8_t _double_byte(uint8_t a);
int _compare(const uint8_t *a, const uint8_t *b, size_t size);
static const uint8_t sbox[256] = {
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b,
	0xfe, 0xd7, 0xab, 0x76, 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
	0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, 0xb7, 0xfd, 0x93, 0x26,
	0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2,
	0xeb, 0x27, 0xb2, 0x75, 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
	0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, 0x53, 0xd1, 0x00, 0xed,
	0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f,
	0x50, 0x3c, 0x9f, 0xa8, 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
	0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, 0xcd, 0x0c, 0x13, 0xec,
	0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14,
	0xde, 0x5e, 0x0b, 0xdb, 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
	0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, 0xe7, 0xc8, 0x37, 0x6d,
	0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f,
	0x4b, 0xbd, 0x8b, 0x8a, 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
	0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, 0xe1, 0xf8, 0x98, 0x11,
	0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f,
	0xb0, 0x54, 0xbb, 0x16
};
static inline unsigned int rotword(unsigned int a)
{
	return (((a) >> 24)|((a) << 8));
}
int tc_aes128_set_encrypt_key(TCAesKeySched_t s, const uint8_t *k)
{
	const unsigned int rconst[11] = {
		0x00000000, 0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000,
		0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000
	};
	unsigned int i;
	unsigned int t;
	if (s == (TCAesKeySched_t) 0) {
		return 0;
	} else if (k == (const uint8_t *) 0) {
		return 0;
	}
	for (i = 0; i < (4); ++i) {
		s->words[i] = (k[(4)*i]<<24) | (k[(4)*i+1]<<16) |
			(k[(4)*i+2]<<8) | (k[(4)*i+3]);
	}
	for (; i < ((4) * ((10) + 1)); ++i) {
		t = s->words[i-1];
		if ((i % (4)) == 0) {
			t = ((sbox[((rotword(t)) >> (24))&0xff] << (24))|(sbox[((rotword(t)) >> (16))&0xff] << (16))|(sbox[((rotword(t)) >> (8))&0xff] << (8))|(sbox[((rotword(t)) >> (0))&0xff] << (0))) ^ rconst[i/(4)];
		}
		s->words[i] = s->words[i-(4)] ^ t;
	}
	return 1;
}
static inline void add_round_key(uint8_t *s, const unsigned int *k)
{
	s[0] ^= (uint8_t)(k[0] >> 24); s[1] ^= (uint8_t)(k[0] >> 16);
	s[2] ^= (uint8_t)(k[0] >> 8); s[3] ^= (uint8_t)(k[0]);
	s[4] ^= (uint8_t)(k[1] >> 24); s[5] ^= (uint8_t)(k[1] >> 16);
	s[6] ^= (uint8_t)(k[1] >> 8); s[7] ^= (uint8_t)(k[1]);
	s[8] ^= (uint8_t)(k[2] >> 24); s[9] ^= (uint8_t)(k[2] >> 16);
	s[10] ^= (uint8_t)(k[2] >> 8); s[11] ^= (uint8_t)(k[2]);
	s[12] ^= (uint8_t)(k[3] >> 24); s[13] ^= (uint8_t)(k[3] >> 16);
	s[14] ^= (uint8_t)(k[3] >> 8); s[15] ^= (uint8_t)(k[3]);
}
static inline void sub_bytes(uint8_t *s)
{
	unsigned int i;
	for (i = 0; i < ((4) * (4)); ++i) {
		s[i] = sbox[s[i]];
	}
}
static inline void mult_row_column(uint8_t *out, const uint8_t *in)
{
	out[0] = _double_byte(in[0]) ^ (_double_byte(in[1])^(in[1])) ^ in[2] ^ in[3];
	out[1] = in[0] ^ _double_byte(in[1]) ^ (_double_byte(in[2])^(in[2])) ^ in[3];
	out[2] = in[0] ^ in[1] ^ _double_byte(in[2]) ^ (_double_byte(in[3])^(in[3]));
	out[3] = (_double_byte(in[0])^(in[0])) ^ in[1] ^ in[2] ^ _double_byte(in[3]);
}
static inline void mix_columns(uint8_t *s)
{
	uint8_t t[(4)*(4)];
	mult_row_column(t, s);
	mult_row_column(&t[(4)], s+(4));
	mult_row_column(&t[2 * (4)], s + (2 * (4)));
	mult_row_column(&t[3 * (4)], s + (3 * (4)));
	(void) _copy(s, sizeof(t), t, sizeof(t));
}
static inline void shift_rows(uint8_t *s)
{
	uint8_t t[(4) * (4)];
	t[0] = s[0]; t[1] = s[5]; t[2] = s[10]; t[3] = s[15];
	t[4] = s[4]; t[5] = s[9]; t[6] = s[14]; t[7] = s[3];
	t[8] = s[8]; t[9] = s[13]; t[10] = s[2]; t[11] = s[7];
	t[12] = s[12]; t[13] = s[1]; t[14] = s[6]; t[15] = s[11];
	(void) _copy(s, sizeof(t), t, sizeof(t));
}
int tc_aes_encrypt(uint8_t *out, const uint8_t *in, const TCAesKeySched_t s)
{
	uint8_t state[(4)*(4)];
	unsigned int i;
	if (out == (uint8_t *) 0) {
		return 0;
	} else if (in == (const uint8_t *) 0) {
		return 0;
	} else if (s == (TCAesKeySched_t) 0) {
		return 0;
	}
	(void)_copy(state, sizeof(state), in, sizeof(state));
	add_round_key(state, s->words);
	for (i = 0; i < ((10) - 1); ++i) {
		sub_bytes(state);
		shift_rows(state);
		mix_columns(state);
		add_round_key(state, s->words + (4)*(i+1));
	}
	sub_bytes(state);
	shift_rows(state);
	add_round_key(state, s->words + (4)*(i+1));
	(void)_copy(out, sizeof(state), state, sizeof(state));
	_set(state, 0x00, sizeof(state));
	return 1;
}
