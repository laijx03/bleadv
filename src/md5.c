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
	typedef struct {
		uint32_t state[4];
		uint32_t count[2];
		uint8_t buffer[64];
	} MD5_CTX;
void MD5_Init(MD5_CTX *ctx);
void MD5_Update(MD5_CTX *ctx, const uint8_t *msg, int len);
void MD5_Final(uint8_t *digest, MD5_CTX *ctx);
static void MD5Transform(uint32_t state[4], const uint8_t block[64]);
static void Encode(uint8_t *output, uint32_t *input, uint32_t len);
static void Decode(uint32_t *output, const uint8_t *input, uint32_t len);
static const uint8_t PADDING[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
void MD5_Init(MD5_CTX *ctx)
{
	ctx->count[0] = ctx->count[1] = 0;
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
}
void MD5_Update(MD5_CTX *ctx, const uint8_t *msg,
		int len)
{
	uint32_t x;
	int i, partLen;
	x = (uint32_t) ((ctx->count[0] >> 3) & 0x3F);
	if ((ctx->count[0] += ((uint32_t) len << 3)) < ((uint32_t) len << 3)) {
		ctx->count[1]++;
	}
	ctx->count[1] += ((uint32_t) len >> 29);
	partLen = 64 - x;
	if (len >= partLen) {
		memcpy(&ctx->buffer[x], msg, partLen);
		MD5Transform(ctx->state, ctx->buffer);
		for (i = partLen; i + 63 < len; i += 64) {
			MD5Transform(ctx->state, &msg[i]);
		}
		x = 0;
	} else {
		i = 0;
	}
	memcpy(&ctx->buffer[x], &msg[i], len - i);
}
void MD5_Final(uint8_t *digest, MD5_CTX *ctx)
{
	uint8_t bits[8];
	uint32_t x, padLen;
	Encode(bits, ctx->count, 8);
	x = (uint32_t) ((ctx->count[0] >> 3) & 0x3f);
	padLen = (x < 56) ? (56 - x) : (120 - x);
	MD5_Update(ctx, PADDING, padLen);
	MD5_Update(ctx, bits, 8);
	Encode(digest, ctx->state, 16);
}
static void MD5Transform(uint32_t state[4], const uint8_t block[64])
{
	uint32_t a = state[0], b = state[1], c = state[2], d = state[3], x[16];
	Decode(x, block, 64);
	{ (a) += ((((b)) & ((c))) | ((~(b)) & ((d)))) + (x[0]) + (uint32_t)(0xd76aa478); (a) = ((((a)) << ((7))) | (((a)) >> (32-((7))))); (a) += (b); };
	{ (d) += ((((a)) & ((b))) | ((~(a)) & ((c)))) + (x[1]) + (uint32_t)(0xe8c7b756); (d) = ((((d)) << ((12))) | (((d)) >> (32-((12))))); (d) += (a); };
	{ (c) += ((((d)) & ((a))) | ((~(d)) & ((b)))) + (x[2]) + (uint32_t)(0x242070db); (c) = ((((c)) << ((17))) | (((c)) >> (32-((17))))); (c) += (d); };
	{ (b) += ((((c)) & ((d))) | ((~(c)) & ((a)))) + (x[3]) + (uint32_t)(0xc1bdceee); (b) = ((((b)) << ((22))) | (((b)) >> (32-((22))))); (b) += (c); };
	{ (a) += ((((b)) & ((c))) | ((~(b)) & ((d)))) + (x[4]) + (uint32_t)(0xf57c0faf); (a) = ((((a)) << ((7))) | (((a)) >> (32-((7))))); (a) += (b); };
	{ (d) += ((((a)) & ((b))) | ((~(a)) & ((c)))) + (x[5]) + (uint32_t)(0x4787c62a); (d) = ((((d)) << ((12))) | (((d)) >> (32-((12))))); (d) += (a); };
	{ (c) += ((((d)) & ((a))) | ((~(d)) & ((b)))) + (x[6]) + (uint32_t)(0xa8304613); (c) = ((((c)) << ((17))) | (((c)) >> (32-((17))))); (c) += (d); };
	{ (b) += ((((c)) & ((d))) | ((~(c)) & ((a)))) + (x[7]) + (uint32_t)(0xfd469501); (b) = ((((b)) << ((22))) | (((b)) >> (32-((22))))); (b) += (c); };
	{ (a) += ((((b)) & ((c))) | ((~(b)) & ((d)))) + (x[8]) + (uint32_t)(0x698098d8); (a) = ((((a)) << ((7))) | (((a)) >> (32-((7))))); (a) += (b); };
	{ (d) += ((((a)) & ((b))) | ((~(a)) & ((c)))) + (x[9]) + (uint32_t)(0x8b44f7af); (d) = ((((d)) << ((12))) | (((d)) >> (32-((12))))); (d) += (a); };
	{ (c) += ((((d)) & ((a))) | ((~(d)) & ((b)))) + (x[10]) + (uint32_t)(0xffff5bb1); (c) = ((((c)) << ((17))) | (((c)) >> (32-((17))))); (c) += (d); };
	{ (b) += ((((c)) & ((d))) | ((~(c)) & ((a)))) + (x[11]) + (uint32_t)(0x895cd7be); (b) = ((((b)) << ((22))) | (((b)) >> (32-((22))))); (b) += (c); };
	{ (a) += ((((b)) & ((c))) | ((~(b)) & ((d)))) + (x[12]) + (uint32_t)(0x6b901122); (a) = ((((a)) << ((7))) | (((a)) >> (32-((7))))); (a) += (b); };
	{ (d) += ((((a)) & ((b))) | ((~(a)) & ((c)))) + (x[13]) + (uint32_t)(0xfd987193); (d) = ((((d)) << ((12))) | (((d)) >> (32-((12))))); (d) += (a); };
	{ (c) += ((((d)) & ((a))) | ((~(d)) & ((b)))) + (x[14]) + (uint32_t)(0xa679438e); (c) = ((((c)) << ((17))) | (((c)) >> (32-((17))))); (c) += (d); };
	{ (b) += ((((c)) & ((d))) | ((~(c)) & ((a)))) + (x[15]) + (uint32_t)(0x49b40821); (b) = ((((b)) << ((22))) | (((b)) >> (32-((22))))); (b) += (c); };
	{ (a) += ((((b)) & ((d))) | (((c)) & (~(d)))) + (x[1]) + (uint32_t)(0xf61e2562); (a) = ((((a)) << ((5))) | (((a)) >> (32-((5))))); (a) += (b); };
	{ (d) += ((((a)) & ((c))) | (((b)) & (~(c)))) + (x[6]) + (uint32_t)(0xc040b340); (d) = ((((d)) << ((9))) | (((d)) >> (32-((9))))); (d) += (a); };
	{ (c) += ((((d)) & ((b))) | (((a)) & (~(b)))) + (x[11]) + (uint32_t)(0x265e5a51); (c) = ((((c)) << ((14))) | (((c)) >> (32-((14))))); (c) += (d); };
	{ (b) += ((((c)) & ((a))) | (((d)) & (~(a)))) + (x[0]) + (uint32_t)(0xe9b6c7aa); (b) = ((((b)) << ((20))) | (((b)) >> (32-((20))))); (b) += (c); };
	{ (a) += ((((b)) & ((d))) | (((c)) & (~(d)))) + (x[5]) + (uint32_t)(0xd62f105d); (a) = ((((a)) << ((5))) | (((a)) >> (32-((5))))); (a) += (b); };
	{ (d) += ((((a)) & ((c))) | (((b)) & (~(c)))) + (x[10]) + (uint32_t)(0x2441453); (d) = ((((d)) << ((9))) | (((d)) >> (32-((9))))); (d) += (a); };
	{ (c) += ((((d)) & ((b))) | (((a)) & (~(b)))) + (x[15]) + (uint32_t)(0xd8a1e681); (c) = ((((c)) << ((14))) | (((c)) >> (32-((14))))); (c) += (d); };
	{ (b) += ((((c)) & ((a))) | (((d)) & (~(a)))) + (x[4]) + (uint32_t)(0xe7d3fbc8); (b) = ((((b)) << ((20))) | (((b)) >> (32-((20))))); (b) += (c); };
	{ (a) += ((((b)) & ((d))) | (((c)) & (~(d)))) + (x[9]) + (uint32_t)(0x21e1cde6); (a) = ((((a)) << ((5))) | (((a)) >> (32-((5))))); (a) += (b); };
	{ (d) += ((((a)) & ((c))) | (((b)) & (~(c)))) + (x[14]) + (uint32_t)(0xc33707d6); (d) = ((((d)) << ((9))) | (((d)) >> (32-((9))))); (d) += (a); };
	{ (c) += ((((d)) & ((b))) | (((a)) & (~(b)))) + (x[3]) + (uint32_t)(0xf4d50d87); (c) = ((((c)) << ((14))) | (((c)) >> (32-((14))))); (c) += (d); };
	{ (b) += ((((c)) & ((a))) | (((d)) & (~(a)))) + (x[8]) + (uint32_t)(0x455a14ed); (b) = ((((b)) << ((20))) | (((b)) >> (32-((20))))); (b) += (c); };
	{ (a) += ((((b)) & ((d))) | (((c)) & (~(d)))) + (x[13]) + (uint32_t)(0xa9e3e905); (a) = ((((a)) << ((5))) | (((a)) >> (32-((5))))); (a) += (b); };
	{ (d) += ((((a)) & ((c))) | (((b)) & (~(c)))) + (x[2]) + (uint32_t)(0xfcefa3f8); (d) = ((((d)) << ((9))) | (((d)) >> (32-((9))))); (d) += (a); };
	{ (c) += ((((d)) & ((b))) | (((a)) & (~(b)))) + (x[7]) + (uint32_t)(0x676f02d9); (c) = ((((c)) << ((14))) | (((c)) >> (32-((14))))); (c) += (d); };
	{ (b) += ((((c)) & ((a))) | (((d)) & (~(a)))) + (x[12]) + (uint32_t)(0x8d2a4c8a); (b) = ((((b)) << ((20))) | (((b)) >> (32-((20))))); (b) += (c); };
	{ (a) += (((b)) ^ ((c)) ^ ((d))) + (x[5]) + (uint32_t)(0xfffa3942); (a) = ((((a)) << ((4))) | (((a)) >> (32-((4))))); (a) += (b); };
	{ (d) += (((a)) ^ ((b)) ^ ((c))) + (x[8]) + (uint32_t)(0x8771f681); (d) = ((((d)) << ((11))) | (((d)) >> (32-((11))))); (d) += (a); };
	{ (c) += (((d)) ^ ((a)) ^ ((b))) + (x[11]) + (uint32_t)(0x6d9d6122); (c) = ((((c)) << ((16))) | (((c)) >> (32-((16))))); (c) += (d); };
	{ (b) += (((c)) ^ ((d)) ^ ((a))) + (x[14]) + (uint32_t)(0xfde5380c); (b) = ((((b)) << ((23))) | (((b)) >> (32-((23))))); (b) += (c); };
	{ (a) += (((b)) ^ ((c)) ^ ((d))) + (x[1]) + (uint32_t)(0xa4beea44); (a) = ((((a)) << ((4))) | (((a)) >> (32-((4))))); (a) += (b); };
	{ (d) += (((a)) ^ ((b)) ^ ((c))) + (x[4]) + (uint32_t)(0x4bdecfa9); (d) = ((((d)) << ((11))) | (((d)) >> (32-((11))))); (d) += (a); };
	{ (c) += (((d)) ^ ((a)) ^ ((b))) + (x[7]) + (uint32_t)(0xf6bb4b60); (c) = ((((c)) << ((16))) | (((c)) >> (32-((16))))); (c) += (d); };
	{ (b) += (((c)) ^ ((d)) ^ ((a))) + (x[10]) + (uint32_t)(0xbebfbc70); (b) = ((((b)) << ((23))) | (((b)) >> (32-((23))))); (b) += (c); };
	{ (a) += (((b)) ^ ((c)) ^ ((d))) + (x[13]) + (uint32_t)(0x289b7ec6); (a) = ((((a)) << ((4))) | (((a)) >> (32-((4))))); (a) += (b); };
	{ (d) += (((a)) ^ ((b)) ^ ((c))) + (x[0]) + (uint32_t)(0xeaa127fa); (d) = ((((d)) << ((11))) | (((d)) >> (32-((11))))); (d) += (a); };
	{ (c) += (((d)) ^ ((a)) ^ ((b))) + (x[3]) + (uint32_t)(0xd4ef3085); (c) = ((((c)) << ((16))) | (((c)) >> (32-((16))))); (c) += (d); };
	{ (b) += (((c)) ^ ((d)) ^ ((a))) + (x[6]) + (uint32_t)(0x4881d05); (b) = ((((b)) << ((23))) | (((b)) >> (32-((23))))); (b) += (c); };
	{ (a) += (((b)) ^ ((c)) ^ ((d))) + (x[9]) + (uint32_t)(0xd9d4d039); (a) = ((((a)) << ((4))) | (((a)) >> (32-((4))))); (a) += (b); };
	{ (d) += (((a)) ^ ((b)) ^ ((c))) + (x[12]) + (uint32_t)(0xe6db99e5); (d) = ((((d)) << ((11))) | (((d)) >> (32-((11))))); (d) += (a); };
	{ (c) += (((d)) ^ ((a)) ^ ((b))) + (x[15]) + (uint32_t)(0x1fa27cf8); (c) = ((((c)) << ((16))) | (((c)) >> (32-((16))))); (c) += (d); };
	{ (b) += (((c)) ^ ((d)) ^ ((a))) + (x[2]) + (uint32_t)(0xc4ac5665); (b) = ((((b)) << ((23))) | (((b)) >> (32-((23))))); (b) += (c); };
	{ (a) += (((c)) ^ (((b)) | (~(d)))) + (x[0]) + (uint32_t)(0xf4292244); (a) = ((((a)) << ((6))) | (((a)) >> (32-((6))))); (a) += (b); };
	{ (d) += (((b)) ^ (((a)) | (~(c)))) + (x[7]) + (uint32_t)(0x432aff97); (d) = ((((d)) << ((10))) | (((d)) >> (32-((10))))); (d) += (a); };
	{ (c) += (((a)) ^ (((d)) | (~(b)))) + (x[14]) + (uint32_t)(0xab9423a7); (c) = ((((c)) << ((15))) | (((c)) >> (32-((15))))); (c) += (d); };
	{ (b) += (((d)) ^ (((c)) | (~(a)))) + (x[5]) + (uint32_t)(0xfc93a039); (b) = ((((b)) << ((21))) | (((b)) >> (32-((21))))); (b) += (c); };
	{ (a) += (((c)) ^ (((b)) | (~(d)))) + (x[12]) + (uint32_t)(0x655b59c3); (a) = ((((a)) << ((6))) | (((a)) >> (32-((6))))); (a) += (b); };
	{ (d) += (((b)) ^ (((a)) | (~(c)))) + (x[3]) + (uint32_t)(0x8f0ccc92); (d) = ((((d)) << ((10))) | (((d)) >> (32-((10))))); (d) += (a); };
	{ (c) += (((a)) ^ (((d)) | (~(b)))) + (x[10]) + (uint32_t)(0xffeff47d); (c) = ((((c)) << ((15))) | (((c)) >> (32-((15))))); (c) += (d); };
	{ (b) += (((d)) ^ (((c)) | (~(a)))) + (x[1]) + (uint32_t)(0x85845dd1); (b) = ((((b)) << ((21))) | (((b)) >> (32-((21))))); (b) += (c); };
	{ (a) += (((c)) ^ (((b)) | (~(d)))) + (x[8]) + (uint32_t)(0x6fa87e4f); (a) = ((((a)) << ((6))) | (((a)) >> (32-((6))))); (a) += (b); };
	{ (d) += (((b)) ^ (((a)) | (~(c)))) + (x[15]) + (uint32_t)(0xfe2ce6e0); (d) = ((((d)) << ((10))) | (((d)) >> (32-((10))))); (d) += (a); };
	{ (c) += (((a)) ^ (((d)) | (~(b)))) + (x[6]) + (uint32_t)(0xa3014314); (c) = ((((c)) << ((15))) | (((c)) >> (32-((15))))); (c) += (d); };
	{ (b) += (((d)) ^ (((c)) | (~(a)))) + (x[13]) + (uint32_t)(0x4e0811a1); (b) = ((((b)) << ((21))) | (((b)) >> (32-((21))))); (b) += (c); };
	{ (a) += (((c)) ^ (((b)) | (~(d)))) + (x[4]) + (uint32_t)(0xf7537e82); (a) = ((((a)) << ((6))) | (((a)) >> (32-((6))))); (a) += (b); };
	{ (d) += (((b)) ^ (((a)) | (~(c)))) + (x[11]) + (uint32_t)(0xbd3af235); (d) = ((((d)) << ((10))) | (((d)) >> (32-((10))))); (d) += (a); };
	{ (c) += (((a)) ^ (((d)) | (~(b)))) + (x[2]) + (uint32_t)(0x2ad7d2bb); (c) = ((((c)) << ((15))) | (((c)) >> (32-((15))))); (c) += (d); };
	{ (b) += (((d)) ^ (((c)) | (~(a)))) + (x[9]) + (uint32_t)(0xeb86d391); (b) = ((((b)) << ((21))) | (((b)) >> (32-((21))))); (b) += (c); };
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
}
static void Encode(uint8_t *output, uint32_t *input, uint32_t len)
{
	uint32_t i, j;
	for (i = 0, j = 0; j < len; i++, j += 4) {
		output[j] = (uint8_t) (input[i] & 0xff);
		output[j + 1] = (uint8_t) ((input[i] >> 8) & 0xff);
		output[j + 2] = (uint8_t) ((input[i] >> 16) & 0xff);
		output[j + 3] = (uint8_t) ((input[i] >> 24) & 0xff);
	}
}
static void Decode(uint32_t *output, const uint8_t *input, uint32_t len)
{
	uint32_t i, j;
	for (i = 0, j = 0; j < len; i++, j += 4) {
		output[i] = ((uint32_t) input[j]) | (((uint32_t) input[j + 1]) << 8) | (((
						uint32_t) input[j + 2]) << 16) | (((uint32_t) input[j + 3]) << 24);
	}
}
