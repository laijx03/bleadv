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
unsigned int _copy(uint8_t *to, unsigned int to_len,
		const uint8_t *from, unsigned int from_len);
void _set(void *to, uint8_t val, unsigned int len);
uint8_t _double_byte(uint8_t a);
int _compare(const uint8_t *a, const uint8_t *b, size_t size);
static void rekey(uint8_t *key, const uint8_t *new_key, unsigned int key_size)
{
	const uint8_t inner_pad = (uint8_t) 0x36;
	const uint8_t outer_pad = (uint8_t) 0x5c;
	unsigned int i;
	for (i = 0; i < key_size; ++i) {
		key[i] = inner_pad ^ new_key[i];
		key[i + (64)] = outer_pad ^ new_key[i];
	}
	for (; i < (64); ++i) {
		key[i] = inner_pad; key[i + (64)] = outer_pad;
	}
}
int tc_hmac_set_key(TCHmacState_t ctx, const uint8_t *key,
		unsigned int key_size)
{
	if (ctx == (TCHmacState_t) 0 ||
			key == (const uint8_t *) 0 ||
			key_size == 0) {
		return 0;
	}
	const uint8_t dummy_key[key_size];
	struct tc_hmac_state_struct dummy_state;
	if (key_size <= (64)) {
		(void)tc_sha256_init(&dummy_state.hash_state);
		(void)tc_sha256_update(&dummy_state.hash_state,
				dummy_key,
				key_size);
		(void)tc_sha256_final(&dummy_state.key[(32)],
				&dummy_state.hash_state);
		rekey(ctx->key, key, key_size);
	} else {
		(void)tc_sha256_init(&ctx->hash_state);
		(void)tc_sha256_update(&ctx->hash_state, key, key_size);
		(void)tc_sha256_final(&ctx->key[(32)],
				&ctx->hash_state);
		rekey(ctx->key,
				&ctx->key[(32)],
				(32));
	}
	return 1;
}
int tc_hmac_init(TCHmacState_t ctx)
{
	if (ctx == (TCHmacState_t) 0) {
		return 0;
	}
	(void) tc_sha256_init(&ctx->hash_state);
	(void) tc_sha256_update(&ctx->hash_state, ctx->key, (64));
	return 1;
}
int tc_hmac_update(TCHmacState_t ctx,
		const void *data,
		unsigned int data_length)
{
	if (ctx == (TCHmacState_t) 0) {
		return 0;
	}
	(void)tc_sha256_update(&ctx->hash_state, data, data_length);
	return 1;
}
int tc_hmac_final(uint8_t *tag, unsigned int taglen, TCHmacState_t ctx)
{
	if (tag == (uint8_t *) 0 ||
			taglen != (32) ||
			ctx == (TCHmacState_t) 0) {
		return 0;
	}
	(void) tc_sha256_final(tag, &ctx->hash_state);
	(void)tc_sha256_init(&ctx->hash_state);
	(void)tc_sha256_update(&ctx->hash_state,
			&ctx->key[(64)],
			(64));
	(void)tc_sha256_update(&ctx->hash_state, tag, (32));
	(void)tc_sha256_final(tag, &ctx->hash_state);
	_set(ctx, 0, sizeof(*ctx));
	return 1;
}
