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
typedef int8_t wordcount_t;
typedef int16_t bitcount_t;
typedef int8_t cmpresult_t;
typedef unsigned int uECC_word_t;
typedef uint64_t uECC_dword_t;
struct uECC_Curve_t;
typedef const struct uECC_Curve_t * uECC_Curve;
struct uECC_Curve_t {
	wordcount_t num_words;
	wordcount_t num_bytes;
	bitcount_t num_n_bits;
	uECC_word_t p[8];
	uECC_word_t n[8];
	uECC_word_t G[8 * 2];
	uECC_word_t b[8];
	void (*double_jacobian)(uECC_word_t * X1, uECC_word_t * Y1, uECC_word_t * Z1,
			uECC_Curve curve);
	void (*x_side)(uECC_word_t *result, const uECC_word_t *x, uECC_Curve curve);
	void (*mmod_fast)(uECC_word_t *result, uECC_word_t *product);
};
void double_jacobian_default(uECC_word_t * X1, uECC_word_t * Y1,
		uECC_word_t * Z1, uECC_Curve curve);
void x_side_default(uECC_word_t *result, const uECC_word_t *x,
		uECC_Curve curve);
void vli_mmod_fast_secp256r1(unsigned int *result, unsigned int *product);
static const struct uECC_Curve_t curve_secp256r1 = {
	8,
	(4*8),
	256, {
		0xFFFFFFFF, 0xFFFFFFFF,
		0xFFFFFFFF, 0x00000000,
		0x00000000, 0x00000000,
		0x00000001, 0xFFFFFFFF
	}, {
		0xFC632551, 0xF3B9CAC2,
		0xA7179E84, 0xBCE6FAAD,
		0xFFFFFFFF, 0xFFFFFFFF,
		0x00000000, 0xFFFFFFFF
	}, {
		0xD898C296, 0xF4A13945,
		0x2DEB33A0, 0x77037D81,
		0x63A440F2, 0xF8BCE6E5,
		0xE12C4247, 0x6B17D1F2,
		0x37BF51F5, 0xCBB64068,
		0x6B315ECE, 0x2BCE3357,
		0x7C0F9E16, 0x8EE7EB4A,
		0xFE1A7F9B, 0x4FE342E2
	}, {
		0x27D2604B, 0x3BCE3C3E,
		0xCC53B0F6, 0x651D06B0,
		0x769886BC, 0xB3EBBD55,
		0xAA3A93E7, 0x5AC635D8
	},
	&double_jacobian_default,
	&x_side_default,
	&vli_mmod_fast_secp256r1
};
uECC_Curve uECC_secp256r1(void);
int uECC_generate_random_int(uECC_word_t *random, const uECC_word_t *top,
		wordcount_t num_words);
typedef int(*uECC_RNG_Function)(uint8_t *dest, unsigned int size);
void uECC_set_rng(uECC_RNG_Function rng_function);
uECC_RNG_Function uECC_get_rng(void);
int uECC_curve_private_key_size(uECC_Curve curve);
int uECC_curve_public_key_size(uECC_Curve curve);
int uECC_compute_public_key(const uint8_t *private_key,
		uint8_t *public_key, uECC_Curve curve);
uECC_word_t EccPoint_compute_public_key(uECC_word_t *result,
		uECC_word_t *private_key, uECC_Curve curve);
uECC_word_t regularize_k(const uECC_word_t * const k, uECC_word_t *k0,
		uECC_word_t *k1, uECC_Curve curve);
void EccPoint_mult(uECC_word_t * result, const uECC_word_t * point,
		const uECC_word_t * scalar, const uECC_word_t * initial_Z,
		bitcount_t num_bits, uECC_Curve curve);
uECC_word_t uECC_vli_isZero(const uECC_word_t *vli, wordcount_t num_words);
uECC_word_t EccPoint_isZero(const uECC_word_t *point, uECC_Curve curve);
cmpresult_t uECC_vli_cmp(const uECC_word_t *left, const uECC_word_t *right,
		wordcount_t num_words);
cmpresult_t uECC_vli_cmp_unsafe(const uECC_word_t *left, const uECC_word_t *right,
		wordcount_t num_words);
void uECC_vli_modSub(uECC_word_t *result, const uECC_word_t *left,
		const uECC_word_t *right, const uECC_word_t *mod,
		wordcount_t num_words);
void XYcZ_add(uECC_word_t * X1, uECC_word_t * Y1, uECC_word_t * X2,
		uECC_word_t * Y2, uECC_Curve curve);
void apply_z(uECC_word_t * X1, uECC_word_t * Y1, const uECC_word_t * const Z,
		uECC_Curve curve);
uECC_word_t uECC_vli_testBit(const uECC_word_t *vli, bitcount_t bit);
void uECC_vli_mmod(uECC_word_t *result, uECC_word_t *product,
		const uECC_word_t *mod, wordcount_t num_words);
void uECC_vli_modMult_fast(uECC_word_t *result, const uECC_word_t *left,
		const uECC_word_t *right, uECC_Curve curve);
uECC_word_t uECC_vli_sub(uECC_word_t *result, const uECC_word_t *left,
		const uECC_word_t *right, wordcount_t num_words);
uECC_word_t uECC_vli_equal(const uECC_word_t *left, const uECC_word_t *right,
		wordcount_t num_words);
void uECC_vli_modMult(uECC_word_t *result, const uECC_word_t *left,
		const uECC_word_t *right, const uECC_word_t *mod,
		wordcount_t num_words);
void uECC_vli_modInv(uECC_word_t *result, const uECC_word_t *input,
		const uECC_word_t *mod, wordcount_t num_words);
void uECC_vli_set(uECC_word_t *dest, const uECC_word_t *src,
		wordcount_t num_words);
void uECC_vli_modAdd(uECC_word_t *result, const uECC_word_t *left,
		const uECC_word_t *right, const uECC_word_t *mod,
		wordcount_t num_words);
bitcount_t uECC_vli_numBits(const uECC_word_t *vli,
		const wordcount_t max_words);
void uECC_vli_clear(uECC_word_t *vli, wordcount_t num_words);
int uECC_valid_point(const uECC_word_t *point, uECC_Curve curve);
int uECC_valid_public_key(const uint8_t *public_key, uECC_Curve curve);
void uECC_vli_nativeToBytes(uint8_t *bytes, int num_bytes,
		const unsigned int *native);
void uECC_vli_bytesToNative(unsigned int *native, const uint8_t *bytes,
		int num_bytes);
int uECC_make_key(uint8_t *p_public_key, uint8_t *p_private_key, uECC_Curve curve);
int uECC_shared_secret(const uint8_t *p_public_key, const uint8_t *p_private_key,
		uint8_t *p_secret, uECC_Curve curve);
typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef unsigned int wchar_t;
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
typedef long __blkcnt_t;
typedef long __blksize_t;
typedef __uint64_t __fsblkcnt_t;
typedef __uint32_t __fsfilcnt_t;
typedef long _off_t;
typedef int __pid_t;
typedef short __dev_t;
typedef unsigned short __uid_t;
typedef unsigned short __gid_t;
typedef __uint32_t __id_t;
typedef unsigned short __ino_t;
typedef __uint32_t __mode_t;
__extension__ typedef long long _off64_t;
typedef _off_t __off_t;
typedef _off64_t __loff_t;
typedef long __key_t;
typedef long _fpos_t;
typedef unsigned int __size_t;
typedef signed int _ssize_t;
typedef _ssize_t __ssize_t;
typedef unsigned int wint_t;
typedef struct
{
	int __count;
	union
	{
		wint_t __wch;
		unsigned char __wchb[4];
	} __value;
} _mbstate_t;
typedef _LOCK_RECURSIVE_T _flock_t;
typedef void *_iconv_t;
typedef unsigned long __clock_t;
typedef long __time_t;
typedef unsigned long __clockid_t;
typedef unsigned long __timer_t;
typedef __uint8_t __sa_family_t;
typedef __uint32_t __socklen_t;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;
typedef char * __va_list;
typedef unsigned long __ULong;
struct _reent;
struct __locale_t;
struct _Bigint
{
	struct _Bigint *_next;
	int _k, _maxwds, _sign, _wds;
	__ULong _x[1];
};
struct __tm
{
	int __tm_sec;
	int __tm_min;
	int __tm_hour;
	int __tm_mday;
	int __tm_mon;
	int __tm_year;
	int __tm_wday;
	int __tm_yday;
	int __tm_isdst;
};
struct _on_exit_args {
	void * _fnargs[32];
	void * _dso_handle[32];
	__ULong _fntypes;
	__ULong _is_cxa;
};
struct _atexit {
	struct _atexit *_next;
	int _ind;
	void (*_fns[32])(void);
	struct _on_exit_args _on_exit_args;
};
struct __sbuf {
	unsigned char *_base;
	int _size;
};
struct __sFILE {
	unsigned char *_p;
	int _r;
	int _w;
	short _flags;
	short _file;
	struct __sbuf _bf;
	int _lbfsize;
	void * _cookie;
	int (* _read) (struct _reent *, void *, char *, int)
		;
	int (* _write) (struct _reent *, void *, const char *, int)
		;
	_fpos_t (* _seek) (struct _reent *, void *, _fpos_t, int);
	int (* _close) (struct _reent *, void *);
	struct __sbuf _ub;
	unsigned char *_up;
	int _ur;
	unsigned char _ubuf[3];
	unsigned char _nbuf[1];
	struct __sbuf _lb;
	int _blksize;
	_off_t _offset;
	struct _reent *_data;
	_flock_t _lock;
	_mbstate_t _mbstate;
	int _flags2;
};
typedef struct __sFILE __FILE;
struct _glue
{
	struct _glue *_next;
	int _niobs;
	__FILE *_iobs;
};
struct _rand48 {
	unsigned short _seed[3];
	unsigned short _mult[3];
	unsigned short _add;
};
struct _reent
{
	int _errno;
	__FILE *_stdin, *_stdout, *_stderr;
	int _inc;
	char _emergency[25];
	int _unspecified_locale_info;
	struct __locale_t *_locale;
	int __sdidinit;
	void (* __cleanup) (struct _reent *);
	struct _Bigint *_result;
	int _result_k;
	struct _Bigint *_p5s;
	struct _Bigint **_freelist;
	int _cvtlen;
	char *_cvtbuf;
	union
	{
		struct
		{
			unsigned int _unused_rand;
			char * _strtok_last;
			char _asctime_buf[26];
			struct __tm _localtime_buf;
			int _gamma_signgam;
			__extension__ unsigned long long _rand_next;
			struct _rand48 _r48;
			_mbstate_t _mblen_state;
			_mbstate_t _mbtowc_state;
			_mbstate_t _wctomb_state;
			char _l64a_buf[8];
			char _signal_buf[24];
			int _getdate_err;
			_mbstate_t _mbrlen_state;
			_mbstate_t _mbrtowc_state;
			_mbstate_t _mbsrtowcs_state;
			_mbstate_t _wcrtomb_state;
			_mbstate_t _wcsrtombs_state;
			int _h_errno;
		} _reent;
		struct
		{
			unsigned char * _nextf[30];
			unsigned int _nmalloc[30];
		} _unused;
	} _new;
	struct _atexit *_atexit;
	struct _atexit _atexit0;
	void (**(_sig_func))(int);
	struct _glue __sglue;
	__FILE __sf[3];
};
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;
void _reclaim_reent (struct _reent *);
struct __locale_t;
typedef struct __locale_t *locale_t;
void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void * restrict, const void * restrict, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *restrict, const char *restrict);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *restrict, const char *restrict);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *restrict, const char *restrict, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);
size_t strxfrm (char *restrict, const char *restrict, size_t);
int strcoll_l (const char *, const char *, locale_t);
char *strerror_l (int, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
void explicit_bzero (void *, size_t);
int timingsafe_bcmp (const void *, const void *, size_t);
int timingsafe_memcmp (const void *, const void *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void * restrict, const void * restrict, int, size_t);
char *rindex (const char *, int);
char *stpcpy (char *restrict, const char *restrict);
char *stpncpy (char *restrict, const char *restrict, size_t);
int strcasecmp (const char *, const char *);
char *strdup (const char *);
char *_strdup_r (struct _reent *, const char *);
char *strndup (const char *, size_t);
char *_strndup_r (struct _reent *, const char *, size_t);
int strerror_r (int, char *, size_t)
	__asm__ ("" "__xpg_strerror_r")
	;
	char * _strerror_r (struct _reent *, int, int, int *);
	size_t strlcat (char *, const char *, size_t);
	size_t strlcpy (char *, const char *, size_t);
	int strncasecmp (const char *, const char *, size_t);
	size_t strnlen (const char *, size_t);
	char *strsep (char **, const char *);
	char *strlwr (char *);
	char *strupr (char *);
	char *strsignal (int __signo);
	static uECC_RNG_Function g_rng_function = 0;
int uECC_make_key_with_d(uint8_t *public_key, uint8_t *private_key,
		unsigned int *d, uECC_Curve curve)
{
	uECC_word_t _private[8];
	uECC_word_t _public[8 * 2];
	memcpy (_private, d, (4*8));
	if (EccPoint_compute_public_key(_public, _private, curve)) {
		uECC_vli_nativeToBytes(private_key,
				((curve->num_n_bits + 7) / 8),
				_private);
		uECC_vli_nativeToBytes(public_key,
				curve->num_bytes,
				_public);
		uECC_vli_nativeToBytes(public_key + curve->num_bytes,
				curve->num_bytes,
				_public + curve->num_words);
		memset(_private, 0, (4*8));
		return 1;
	}
	return 0;
}
int uECC_make_key(uint8_t *public_key, uint8_t *private_key, uECC_Curve curve)
{
	uECC_word_t _random[8 * 2];
	uECC_word_t _private[8];
	uECC_word_t _public[8 * 2];
	uECC_word_t tries;
	for (tries = 0; tries < 64; ++tries) {
		uECC_RNG_Function rng_function = uECC_get_rng();
		if (!rng_function ||
				!rng_function((uint8_t *)_random, 2 * 8*4)) {
			return 0;
		}
		uECC_vli_mmod(_private, _random, curve->n, ((curve->num_n_bits + ((4 * 8) - 1)) / (4 * 8)));
		if (EccPoint_compute_public_key(_public, _private, curve)) {
			uECC_vli_nativeToBytes(private_key,
					((curve->num_n_bits + 7) / 8),
					_private);
			uECC_vli_nativeToBytes(public_key,
					curve->num_bytes,
					_public);
			uECC_vli_nativeToBytes(public_key + curve->num_bytes,
					curve->num_bytes,
					_public + curve->num_words);
			memset(_private, 0, (4*8));
			return 1;
		}
	}
	return 0;
}
int uECC_shared_secret(const uint8_t *public_key, const uint8_t *private_key,
		uint8_t *secret, uECC_Curve curve)
{
	uECC_word_t _public[8 * 2];
	uECC_word_t _private[8];
	uECC_word_t tmp[8];
	uECC_word_t *p2[2] = {_private, tmp};
	uECC_word_t *initial_Z = 0;
	uECC_word_t carry;
	wordcount_t num_words = curve->num_words;
	wordcount_t num_bytes = curve->num_bytes;
	int r;
	uECC_vli_bytesToNative(_private,
			private_key,
			((curve->num_n_bits + 7) / 8));
	uECC_vli_bytesToNative(_public,
			public_key,
			num_bytes);
	uECC_vli_bytesToNative(_public + num_words,
			public_key + num_bytes,
			num_bytes);
	carry = regularize_k(_private, _private, tmp, curve);
	if (g_rng_function) {
		if (!uECC_generate_random_int(p2[carry], curve->p, num_words)) {
			r = 0;
			goto clear_and_out;
		}
		initial_Z = p2[carry];
	}
	EccPoint_mult(_public, _public, p2[!carry], initial_Z, curve->num_n_bits + 1,
			curve);
	uECC_vli_nativeToBytes(secret, num_bytes, _public);
	r = !EccPoint_isZero(_public, curve);
clear_and_out:
	memset(p2, 0, sizeof(p2));
	memset(tmp, 0, sizeof(tmp));
	memset(_private, 0, sizeof(_private));
	return r;
}
