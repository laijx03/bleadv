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
typedef struct tc_cmac_struct {
	uint8_t iv[((4)*(4))];
	uint8_t K1[((4)*(4))];
	uint8_t K2[((4)*(4))];
	uint8_t leftover[((4)*(4))];
	unsigned int keyid;
	unsigned int leftover_offset;
	TCAesKeySched_t sched;
	uint64_t countdown;
} *TCCmacState_t;
int tc_cmac_setup(TCCmacState_t s, const uint8_t *key,
		TCAesKeySched_t sched);
int tc_cmac_erase(TCCmacState_t s);
int tc_cmac_init(TCCmacState_t s);
int tc_cmac_update(TCCmacState_t s, const uint8_t *data, size_t dlen);
int tc_cmac_final(uint8_t *tag, TCCmacState_t s);
unsigned int _copy(uint8_t *to, unsigned int to_len,
		const uint8_t *from, unsigned int from_len);
void _set(void *to, uint8_t val, unsigned int len);
uint8_t _double_byte(uint8_t a);
int _compare(const uint8_t *a, const uint8_t *b, size_t size);
const static uint64_t MAX_CALLS = ((uint64_t)1 << 48);
const unsigned char gf_wrap = 0x87;
void gf_double(uint8_t *out, uint8_t *in)
{
	uint8_t *x = in + (((4)*(4)) - 1);
	uint8_t carry = (in[0] >> 7) ? gf_wrap : 0;
	out += (((4)*(4)) - 1);
	for (;;) {
		*out-- = (*x << 1) ^ carry;
		if (x == in) {
			break;
		}
		carry = *x-- >> 7;
	}
}
int tc_cmac_setup(TCCmacState_t s, const uint8_t *key, TCAesKeySched_t sched)
{
	if (s == (TCCmacState_t) 0 ||
			key == (const uint8_t *) 0) {
		return 0;
	}
	_set(s, 0, sizeof(*s));
	s->sched = sched;
	tc_aes128_set_encrypt_key(s->sched, key);
	_set(s->iv, 0, ((4)*(4)));
	tc_aes_encrypt(s->iv, s->iv, s->sched);
	gf_double (s->K1, s->iv);
	gf_double (s->K2, s->K1);
	tc_cmac_init(s);
	return 1;
}
int tc_cmac_erase(TCCmacState_t s)
{
	if (s == (TCCmacState_t) 0) {
		return 0;
	}
	_set(s, 0, sizeof(*s));
	return 1;
}
int tc_cmac_init(TCCmacState_t s)
{
	if (s == (TCCmacState_t) 0) {
		return 0;
	}
	_set(s->iv, 0, ((4)*(4)));
	_set(s->leftover, 0, ((4)*(4)));
	s->leftover_offset = 0;
	s->countdown = MAX_CALLS;
	return 1;
}
int tc_cmac_update(TCCmacState_t s, const uint8_t *data, size_t data_length)
{
	unsigned int i;
	if (s == (TCCmacState_t) 0) {
		return 0;
	}
	if (data_length == 0) {
		return 1;
	}
	if (data == (const uint8_t *) 0) {
		return 0;
	}
	if (s->countdown == 0) {
		return 0;
	}
	s->countdown--;
	if (s->leftover_offset > 0) {
		size_t remaining_space = ((4)*(4)) - s->leftover_offset;
		if (data_length < remaining_space) {
			_copy(&s->leftover[s->leftover_offset], data_length, data, data_length);
			s->leftover_offset += data_length;
			return 1;
		}
		_copy(&s->leftover[s->leftover_offset],
				remaining_space,
				data,
				remaining_space);
		data_length -= remaining_space;
		data += remaining_space;
		s->leftover_offset = 0;
		for (i = 0; i < ((4)*(4)); ++i) {
			s->iv[i] ^= s->leftover[i];
		}
		tc_aes_encrypt(s->iv, s->iv, s->sched);
	}
	while (data_length > ((4)*(4))) {
		for (i = 0; i < ((4)*(4)); ++i) {
			s->iv[i] ^= data[i];
		}
		tc_aes_encrypt(s->iv, s->iv, s->sched);
		data += ((4)*(4));
		data_length -= ((4)*(4));
	}
	if (data_length > 0) {
		_copy(s->leftover, data_length, data, data_length);
		s->leftover_offset = data_length;
	}
	return 1;
}
int tc_cmac_final(uint8_t *tag, TCCmacState_t s)
{
	uint8_t *k;
	unsigned int i;
	if (tag == (uint8_t *) 0 ||
			s == (TCCmacState_t) 0) {
		return 0;
	}
	if (s->leftover_offset == ((4)*(4))) {
		k = (uint8_t *) s->K1;
	} else {
		size_t remaining = ((4)*(4)) - s->leftover_offset;
		_set(&s->leftover[s->leftover_offset], 0, remaining);
		s->leftover[s->leftover_offset] = 0x80;
		k = (uint8_t *) s->K2;
	}
	for (i = 0; i < ((4)*(4)); ++i) {
		s->iv[i] ^= s->leftover[i] ^ k[i];
	}
	tc_aes_encrypt(tag, s->iv, s->sched);
	tc_cmac_erase(s);
	return 1;
}
