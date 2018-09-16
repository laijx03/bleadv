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
struct tc_hmac_state_struct {
	struct tc_sha256_state_struct hash_state;
	uint8_t key[2*(64)];
};
typedef struct tc_hmac_state_struct *TCHmacState_t;
int tc_hmac_set_key(TCHmacState_t ctx, const uint8_t *key,
		unsigned int key_size);
int tc_hmac_init(TCHmacState_t ctx);
int tc_hmac_update(TCHmacState_t ctx, const void *data,
		unsigned int data_length);
int tc_hmac_final(uint8_t *tag, unsigned int taglen, TCHmacState_t ctx);
struct tc_hmac_prng_struct {
	struct tc_hmac_state_struct h;
	uint8_t key[(32)];
	uint8_t v[(32)];
	unsigned int countdown;
};
typedef struct tc_hmac_prng_struct *TCHmacPrng_t;
int tc_hmac_prng_init(TCHmacPrng_t prng,
		const uint8_t *personalization,
		unsigned int plen);
int tc_hmac_prng_reseed(TCHmacPrng_t prng, const uint8_t *seed,
		unsigned int seedlen, const uint8_t *additional_input,
		unsigned int additionallen);
int tc_hmac_prng_generate(uint8_t *out, unsigned int outlen, TCHmacPrng_t prng);
unsigned int _copy(uint8_t *to, unsigned int to_len,
		const uint8_t *from, unsigned int from_len);
void _set(void *to, uint8_t val, unsigned int len);
uint8_t _double_byte(uint8_t a);
int _compare(const uint8_t *a, const uint8_t *b, size_t size);
static const unsigned int MIN_SLEN = 32;
	static const unsigned int MAX_SLEN = 
(0xffffffffUL)
	;
	static const unsigned int MAX_PLEN = 
(0xffffffffUL)
	;
	static const unsigned int MAX_ALEN = 
(0xffffffffUL)
	;
	static const unsigned int MAX_GENS = 
(0xffffffffUL)
	;
	static const unsigned int MAX_OUT = (1 << 19);
static void update(TCHmacPrng_t prng, const uint8_t *e, unsigned int len)
{
	const uint8_t separator0 = 0x00;
	const uint8_t separator1 = 0x01;
	(void)tc_hmac_init(&prng->h);
	(void)tc_hmac_update(&prng->h, prng->v, sizeof(prng->v));
	(void)tc_hmac_update(&prng->h, &separator0, sizeof(separator0));
	(void)tc_hmac_update(&prng->h, e, len);
	(void)tc_hmac_final(prng->key, sizeof(prng->key), &prng->h);
	(void)tc_hmac_set_key(&prng->h, prng->key, sizeof(prng->key));
	(void)tc_hmac_init(&prng->h);
	(void)tc_hmac_update(&prng->h, prng->v, sizeof(prng->v));
	(void)tc_hmac_final(prng->v, sizeof(prng->v), &prng->h);
	(void)tc_hmac_init(&prng->h);
	(void)tc_hmac_update(&prng->h, prng->v, sizeof(prng->v));
	(void)tc_hmac_update(&prng->h, &separator1, sizeof(separator1));
	(void)tc_hmac_update(&prng->h, e, len);
	(void)tc_hmac_final(prng->key, sizeof(prng->key), &prng->h);
	(void)tc_hmac_set_key(&prng->h, prng->key, sizeof(prng->key));
	(void)tc_hmac_init(&prng->h);
	(void)tc_hmac_update(&prng->h, prng->v, sizeof(prng->v));
	(void)tc_hmac_final(prng->v, sizeof(prng->v), &prng->h);
}
int tc_hmac_prng_init(TCHmacPrng_t prng,
		const uint8_t *personalization,
		unsigned int plen)
{
	if (prng == (TCHmacPrng_t) 0 ||
			personalization == (uint8_t *) 0) {
		return 0;
	}
	_set(prng->key, 0x00, sizeof(prng->key));
	_set(prng->v, 0x01, sizeof(prng->v));
	tc_hmac_set_key(&prng->h, prng->key, sizeof(prng->key));
	update(prng, personalization, plen);
	prng->countdown = 0;
	return 1;
}
int tc_hmac_prng_reseed(TCHmacPrng_t prng,
		const uint8_t *seed,
		unsigned int seedlen,
		const uint8_t *additional_input,
		unsigned int additionallen)
{
	if (prng == (TCHmacPrng_t) 0 ||
			seed == (const uint8_t *) 0 ||
			seedlen < MIN_SLEN ||
			seedlen > MAX_SLEN) {
		return 0;
	}
	if (additional_input != (const uint8_t *) 0) {
		if (additionallen == 0) {
			return 0;
		} else {
			update(prng, seed, seedlen);
			update(prng, additional_input, additionallen);
		}
	} else {
		update(prng, seed, seedlen);
	}
	prng->countdown = MAX_GENS;
	return 1;
}
int tc_hmac_prng_generate(uint8_t *out, unsigned int outlen, TCHmacPrng_t prng)
{
	unsigned int bufferlen;
	if (out == (uint8_t *) 0 ||
			prng == (TCHmacPrng_t) 0 ||
			outlen == 0 ||
			outlen > MAX_OUT) {
		return 0;
	} else if (prng->countdown == 0) {
		return -1;
	}
	prng->countdown--;
	while (outlen != 0) {
		(void)tc_hmac_init(&prng->h);
		(void)tc_hmac_update(&prng->h, prng->v, sizeof(prng->v));
		(void)tc_hmac_final(prng->v, sizeof(prng->v), &prng->h);
		bufferlen = ((32) > outlen) ?
			outlen : (32);
		(void)_copy(out, bufferlen, prng->v, bufferlen);
		out += bufferlen;
		outlen = (outlen > (32)) ?
			(outlen - (32)) : 0;
	}
	update(prng, prng->v, (32));
	return 1;
}
