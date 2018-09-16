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
static inline unsigned int gcc_current_sp(void)
{
	register unsigned sp __asm("sp");
	return sp;
}
typedef uint32_t ret_code_t;
typedef enum {
	Reset_IRQn = -15,
	NonMaskableInt_IRQn = -14,
	HardFault_IRQn = -13,
	MemoryManagement_IRQn = -12,
	BusFault_IRQn = -11,
	UsageFault_IRQn = -10,
	SVCall_IRQn = -5,
	DebugMonitor_IRQn = -4,
	PendSV_IRQn = -2,
	SysTick_IRQn = -1,
	POWER_CLOCK_IRQn = 0,
	RADIO_IRQn = 1,
	UARTE0_UART0_IRQn = 2,
	SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQn= 3,
	SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQn= 4,
	NFCT_IRQn = 5,
	GPIOTE_IRQn = 6,
	SAADC_IRQn = 7,
	TIMER0_IRQn = 8,
	TIMER1_IRQn = 9,
	TIMER2_IRQn = 10,
	RTC0_IRQn = 11,
	TEMP_IRQn = 12,
	RNG_IRQn = 13,
	ECB_IRQn = 14,
	CCM_AAR_IRQn = 15,
	WDT_IRQn = 16,
	RTC1_IRQn = 17,
	QDEC_IRQn = 18,
	COMP_LPCOMP_IRQn = 19,
	SWI0_EGU0_IRQn = 20,
	SWI1_EGU1_IRQn = 21,
	SWI2_EGU2_IRQn = 22,
	SWI3_EGU3_IRQn = 23,
	SWI4_EGU4_IRQn = 24,
	SWI5_EGU5_IRQn = 25,
	TIMER3_IRQn = 26,
	TIMER4_IRQn = 27,
	PWM0_IRQn = 28,
	PDM_IRQn = 29,
	MWU_IRQn = 32,
	PWM1_IRQn = 33,
	PWM2_IRQn = 34,
	SPIM2_SPIS2_SPI2_IRQn = 35,
	RTC2_IRQn = 36,
	I2S_IRQn = 37,
	FPU_IRQn = 38,
	USBD_IRQn = 39,
	UARTE1_IRQn = 40,
	QSPI_IRQn = 41,
	CRYPTOCELL_IRQn = 42,
	PWM3_IRQn = 45,
	SPIM3_IRQn = 47
} IRQn_Type;
__attribute__( ( always_inline ) ) static inline void __enable_irq(void)
{
	__asm volatile ("cpsie i" : : : "memory");
}
__attribute__( ( always_inline ) ) static inline void __disable_irq(void)
{
	__asm volatile ("cpsid i" : : : "memory");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_CONTROL(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, control" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline void __set_CONTROL(uint32_t control)
{
	__asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_IPSR(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, ipsr" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_APSR(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, apsr" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_xPSR(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, xpsr" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_PSP(void)
{
	register uint32_t result;
	__asm volatile ("MRS %0, psp\n" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline void __set_PSP(uint32_t topOfProcStack)
{
	__asm volatile ("MSR psp, %0\n" : : "r" (topOfProcStack) : "sp");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_MSP(void)
{
	register uint32_t result;
	__asm volatile ("MRS %0, msp\n" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline void __set_MSP(uint32_t topOfMainStack)
{
	__asm volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) : "sp");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_PRIMASK(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, primask" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline void __set_PRIMASK(uint32_t priMask)
{
	__asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
__attribute__( ( always_inline ) ) static inline void __enable_fault_irq(void)
{
	__asm volatile ("cpsie f" : : : "memory");
}
__attribute__( ( always_inline ) ) static inline void __disable_fault_irq(void)
{
	__asm volatile ("cpsid f" : : : "memory");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_BASEPRI(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, basepri" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline void __set_BASEPRI(uint32_t value)
{
	__asm volatile ("MSR basepri, %0" : : "r" (value) : "memory");
}
__attribute__( ( always_inline ) ) static inline void __set_BASEPRI_MAX(uint32_t value)
{
	__asm volatile ("MSR basepri_max, %0" : : "r" (value) : "memory");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_FAULTMASK(void)
{
	uint32_t result;
	__asm volatile ("MRS %0, faultmask" : "=r" (result) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline void __set_FAULTMASK(uint32_t faultMask)
{
	__asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
__attribute__( ( always_inline ) ) static inline uint32_t __get_FPSCR(void)
{
	return(0);
}
__attribute__( ( always_inline ) ) static inline void __set_FPSCR(uint32_t fpscr)
{
}
__attribute__((always_inline)) static inline void __NOP(void)
{
	__asm volatile ("nop");
}
__attribute__((always_inline)) static inline void __WFI(void)
{
	__asm volatile ("wfi");
}
__attribute__((always_inline)) static inline void __WFE(void)
{
	__asm volatile ("wfe");
}
__attribute__((always_inline)) static inline void __SEV(void)
{
	__asm volatile ("sev");
}
__attribute__((always_inline)) static inline void __ISB(void)
{
	__asm volatile ("isb 0xF":::"memory");
}
__attribute__((always_inline)) static inline void __DSB(void)
{
	__asm volatile ("dsb 0xF":::"memory");
}
__attribute__((always_inline)) static inline void __DMB(void)
{
	__asm volatile ("dmb 0xF":::"memory");
}
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{
	return __builtin_bswap32(value);
}
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
	uint32_t result;
	__asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
	return(result);
}
__attribute__((always_inline)) static inline int32_t __REVSH(int32_t value)
{
	return (short)__builtin_bswap16(value);
}
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
	return (op1 >> op2) | (op1 << (32U - op2));
}
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
	uint32_t result;
	__asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
	return(result);
}
__attribute__((always_inline)) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
	uint32_t result;
	__asm volatile ("ldrexb %0, %1" : "=r" (result) : "Q" (*addr) );
	return ((uint8_t) result);
}
__attribute__((always_inline)) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
	uint32_t result;
	__asm volatile ("ldrexh %0, %1" : "=r" (result) : "Q" (*addr) );
	return ((uint16_t) result);
}
__attribute__((always_inline)) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
	uint32_t result;
	__asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
	return(result);
}
__attribute__((always_inline)) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
	uint32_t result;
	__asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
	return(result);
}
__attribute__((always_inline)) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
	uint32_t result;
	__asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
	return(result);
}
__attribute__((always_inline)) static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
	uint32_t result;
	__asm volatile ("strex %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
	return(result);
}
__attribute__((always_inline)) static inline void __CLREX(void)
{
	__asm volatile ("clrex" ::: "memory");
}
__attribute__((always_inline)) static inline uint32_t __RRX(uint32_t value)
{
	uint32_t result;
	__asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
	return(result);
}
__attribute__((always_inline)) static inline uint8_t __LDRBT(volatile uint8_t *addr)
{
	uint32_t result;
	__asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*addr) );
	return ((uint8_t) result);
}
__attribute__((always_inline)) static inline uint16_t __LDRHT(volatile uint16_t *addr)
{
	uint32_t result;
	__asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*addr) );
	return ((uint16_t) result);
}
__attribute__((always_inline)) static inline uint32_t __LDRT(volatile uint32_t *addr)
{
	uint32_t result;
	__asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*addr) );
	return(result);
}
__attribute__((always_inline)) static inline void __STRBT(uint8_t value, volatile uint8_t *addr)
{
	__asm volatile ("strbt %1, %0" : "=Q" (*addr) : "r" ((uint32_t)value) );
}
__attribute__((always_inline)) static inline void __STRHT(uint16_t value, volatile uint16_t *addr)
{
	__asm volatile ("strht %1, %0" : "=Q" (*addr) : "r" ((uint32_t)value) );
}
__attribute__((always_inline)) static inline void __STRT(uint32_t value, volatile uint32_t *addr)
{
	__asm volatile ("strt %1, %0" : "=Q" (*addr) : "r" (value) );
}
__attribute__( ( always_inline ) ) static inline uint32_t __SADD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("sadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __QADD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("qadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SHADD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("shadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UADD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UQADD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uqadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UHADD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uhadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SSUB8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("ssub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __QSUB8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("qsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SHSUB8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("shsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __USUB8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("usub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UQSUB8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uqsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UHSUB8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uhsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SADD16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("sadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __QADD16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("qadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SHADD16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("shadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UADD16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UQADD16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uqadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UHADD16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uhadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SSUB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("ssub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __QSUB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("qsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SHSUB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("shsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __USUB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("usub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UQSUB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uqsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UHSUB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uhsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SASX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("sasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __QASX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("qasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SHASX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("shasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UASX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UQASX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uqasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UHASX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uhasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SSAX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("ssax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __QSAX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("qsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SHSAX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("shsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __USAX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("usax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UQSAX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uqsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UHSAX(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uhsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __USAD8(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("usad8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3)
{
	uint32_t result;
	__asm volatile ("usada8 %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UXTB16(uint32_t op1)
{
	uint32_t result;
	__asm volatile ("uxtb16 %0, %1" : "=r" (result) : "r" (op1));
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __UXTAB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("uxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SXTB16(uint32_t op1)
{
	uint32_t result;
	__asm volatile ("sxtb16 %0, %1" : "=r" (result) : "r" (op1));
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SXTAB16(uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("sxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMUAD (uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("smuad %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMUADX (uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("smuadx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMLAD (uint32_t op1, uint32_t op2, uint32_t op3)
{
	uint32_t result;
	__asm volatile ("smlad %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMLADX (uint32_t op1, uint32_t op2, uint32_t op3)
{
	uint32_t result;
	__asm volatile ("smladx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint64_t __SMLALD (uint32_t op1, uint32_t op2, uint64_t acc)
{
	union llreg_u{
		uint32_t w32[2];
		uint64_t w64;
	} llr;
	llr.w64 = acc;
	__asm volatile ("smlald %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );
	return(llr.w64);
}
__attribute__( ( always_inline ) ) static inline uint64_t __SMLALDX (uint32_t op1, uint32_t op2, uint64_t acc)
{
	union llreg_u{
		uint32_t w32[2];
		uint64_t w64;
	} llr;
	llr.w64 = acc;
	__asm volatile ("smlaldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );
	return(llr.w64);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMUSD (uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("smusd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMUSDX (uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("smusdx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMLSD (uint32_t op1, uint32_t op2, uint32_t op3)
{
	uint32_t result;
	__asm volatile ("smlsd %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMLSDX (uint32_t op1, uint32_t op2, uint32_t op3)
{
	uint32_t result;
	__asm volatile ("smlsdx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint64_t __SMLSLD (uint32_t op1, uint32_t op2, uint64_t acc)
{
	union llreg_u{
		uint32_t w32[2];
		uint64_t w64;
	} llr;
	llr.w64 = acc;
	__asm volatile ("smlsld %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );
	return(llr.w64);
}
__attribute__( ( always_inline ) ) static inline uint64_t __SMLSLDX (uint32_t op1, uint32_t op2, uint64_t acc)
{
	union llreg_u{
		uint32_t w32[2];
		uint64_t w64;
	} llr;
	llr.w64 = acc;
	__asm volatile ("smlsldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );
	return(llr.w64);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SEL (uint32_t op1, uint32_t op2)
{
	uint32_t result;
	__asm volatile ("sel %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline int32_t __QADD( int32_t op1, int32_t op2)
{
	int32_t result;
	__asm volatile ("qadd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline int32_t __QSUB( int32_t op1, int32_t op2)
{
	int32_t result;
	__asm volatile ("qsub %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
	return(result);
}
__attribute__( ( always_inline ) ) static inline uint32_t __SMMLA (int32_t op1, int32_t op2, int32_t op3)
{
	int32_t result;
	__asm volatile ("smmla %0, %1, %2, %3" : "=r" (result): "r" (op1), "r" (op2), "r" (op3) );
	return(result);
}
typedef union
{
	struct
	{
		uint32_t _reserved0:16;
		uint32_t GE:4;
		uint32_t _reserved1:7;
		uint32_t Q:1;
		uint32_t V:1;
		uint32_t C:1;
		uint32_t Z:1;
		uint32_t N:1;
	} b;
	uint32_t w;
} APSR_Type;
typedef union
{
	struct
	{
		uint32_t ISR:9;
		uint32_t _reserved0:23;
	} b;
	uint32_t w;
} IPSR_Type;
typedef union
{
	struct
	{
		uint32_t ISR:9;
		uint32_t _reserved0:7;
		uint32_t GE:4;
		uint32_t _reserved1:4;
		uint32_t T:1;
		uint32_t IT:2;
		uint32_t Q:1;
		uint32_t V:1;
		uint32_t C:1;
		uint32_t Z:1;
		uint32_t N:1;
	} b;
	uint32_t w;
} xPSR_Type;
typedef union
{
	struct
	{
		uint32_t nPRIV:1;
		uint32_t SPSEL:1;
		uint32_t FPCA:1;
		uint32_t _reserved0:29;
	} b;
	uint32_t w;
} CONTROL_Type;
typedef struct
{
	volatile uint32_t ISER[8U];
	uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8U];
	uint32_t RSERVED1[24U];
	volatile uint32_t ISPR[8U];
	uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8U];
	uint32_t RESERVED3[24U];
	volatile uint32_t IABR[8U];
	uint32_t RESERVED4[56U];
	volatile uint8_t IP[240U];
	uint32_t RESERVED5[644U];
	volatile uint32_t STIR;
} NVIC_Type;
typedef struct
{
	volatile const uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint8_t SHP[12U];
	volatile uint32_t SHCSR;
	volatile uint32_t CFSR;
	volatile uint32_t HFSR;
	volatile uint32_t DFSR;
	volatile uint32_t MMFAR;
	volatile uint32_t BFAR;
	volatile uint32_t AFSR;
	volatile const uint32_t PFR[2U];
	volatile const uint32_t DFR;
	volatile const uint32_t ADR;
	volatile const uint32_t MMFR[4U];
	volatile const uint32_t ISAR[5U];
	uint32_t RESERVED0[5U];
	volatile uint32_t CPACR;
} SCB_Type;
typedef struct
{
	uint32_t RESERVED0[1U];
	volatile const uint32_t ICTR;
	volatile uint32_t ACTLR;
} SCnSCB_Type;
typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile const uint32_t CALIB;
} SysTick_Type;
typedef struct
{
	volatile union
	{
		volatile uint8_t u8;
		volatile uint16_t u16;
		volatile uint32_t u32;
	} PORT [32U];
	uint32_t RESERVED0[864U];
	volatile uint32_t TER;
	uint32_t RESERVED1[15U];
	volatile uint32_t TPR;
	uint32_t RESERVED2[15U];
	volatile uint32_t TCR;
	uint32_t RESERVED3[29U];
	volatile uint32_t IWR;
	volatile const uint32_t IRR;
	volatile uint32_t IMCR;
	uint32_t RESERVED4[43U];
	volatile uint32_t LAR;
	volatile const uint32_t LSR;
	uint32_t RESERVED5[6U];
	volatile const uint32_t PID4;
	volatile const uint32_t PID5;
	volatile const uint32_t PID6;
	volatile const uint32_t PID7;
	volatile const uint32_t PID0;
	volatile const uint32_t PID1;
	volatile const uint32_t PID2;
	volatile const uint32_t PID3;
	volatile const uint32_t CID0;
	volatile const uint32_t CID1;
	volatile const uint32_t CID2;
	volatile const uint32_t CID3;
} ITM_Type;
typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t CYCCNT;
	volatile uint32_t CPICNT;
	volatile uint32_t EXCCNT;
	volatile uint32_t SLEEPCNT;
	volatile uint32_t LSUCNT;
	volatile uint32_t FOLDCNT;
	volatile const uint32_t PCSR;
	volatile uint32_t COMP0;
	volatile uint32_t MASK0;
	volatile uint32_t FUNCTION0;
	uint32_t RESERVED0[1U];
	volatile uint32_t COMP1;
	volatile uint32_t MASK1;
	volatile uint32_t FUNCTION1;
	uint32_t RESERVED1[1U];
	volatile uint32_t COMP2;
	volatile uint32_t MASK2;
	volatile uint32_t FUNCTION2;
	uint32_t RESERVED2[1U];
	volatile uint32_t COMP3;
	volatile uint32_t MASK3;
	volatile uint32_t FUNCTION3;
} DWT_Type;
typedef struct
{
	volatile uint32_t SSPSR;
	volatile uint32_t CSPSR;
	uint32_t RESERVED0[2U];
	volatile uint32_t ACPR;
	uint32_t RESERVED1[55U];
	volatile uint32_t SPPR;
	uint32_t RESERVED2[131U];
	volatile const uint32_t FFSR;
	volatile uint32_t FFCR;
	volatile const uint32_t FSCR;
	uint32_t RESERVED3[759U];
	volatile const uint32_t TRIGGER;
	volatile const uint32_t FIFO0;
	volatile const uint32_t ITATBCTR2;
	uint32_t RESERVED4[1U];
	volatile const uint32_t ITATBCTR0;
	volatile const uint32_t FIFO1;
	volatile uint32_t ITCTRL;
	uint32_t RESERVED5[39U];
	volatile uint32_t CLAIMSET;
	volatile uint32_t CLAIMCLR;
	uint32_t RESERVED7[8U];
	volatile const uint32_t DEVID;
	volatile const uint32_t DEVTYPE;
} TPI_Type;
typedef struct
{
	volatile const uint32_t TYPE;
	volatile uint32_t CTRL;
	volatile uint32_t RNR;
	volatile uint32_t RBAR;
	volatile uint32_t RASR;
	volatile uint32_t RBAR_A1;
	volatile uint32_t RASR_A1;
	volatile uint32_t RBAR_A2;
	volatile uint32_t RASR_A2;
	volatile uint32_t RBAR_A3;
	volatile uint32_t RASR_A3;
} MPU_Type;
typedef struct
{
	uint32_t RESERVED0[1U];
	volatile uint32_t FPCCR;
	volatile uint32_t FPCAR;
	volatile uint32_t FPDSCR;
	volatile const uint32_t MVFR0;
	volatile const uint32_t MVFR1;
} FPU_Type;
typedef struct
{
	volatile uint32_t DHCSR;
	volatile uint32_t DCRSR;
	volatile uint32_t DCRDR;
	volatile uint32_t DEMCR;
} CoreDebug_Type;
static inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
	uint32_t reg_value;
	uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
	reg_value = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;
	reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));
	reg_value = (reg_value |
			((uint32_t)0x5FAUL << 16U) |
			(PriorityGroupTmp << 8U) );
	((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = reg_value;
}
static inline uint32_t NVIC_GetPriorityGrouping(void)
{
	return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}
static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}
static inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}
static inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
	return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}
static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}
static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}
static inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
	return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}
static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
	if ((int32_t)(IRQn) < 0)
	{
		((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 3)) & (uint32_t)0xFFUL);
	}
	else
	{
		((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)] = (uint8_t)((priority << (8U - 3)) & (uint32_t)0xFFUL);
	}
}
static inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{
	if ((int32_t)(IRQn) < 0)
	{
		return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 3)));
	}
	else
	{
		return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)] >> (8U - 3)));
	}
}
static inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
	uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
	uint32_t PreemptPriorityBits;
	uint32_t SubPriorityBits;
	PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(3)) ? (uint32_t)(3) : (uint32_t)(7UL - PriorityGroupTmp);
	SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(3)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(3));
	return (
			((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
			((SubPriority & (uint32_t)((1UL << (SubPriorityBits )) - 1UL)))
	       );
}
static inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
	uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
	uint32_t PreemptPriorityBits;
	uint32_t SubPriorityBits;
	PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(3)) ? (uint32_t)(3) : (uint32_t)(7UL - PriorityGroupTmp);
	SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(3)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(3));
	*pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
	*pSubPriority = (Priority ) & (uint32_t)((1UL << (SubPriorityBits )) - 1UL);
}
static inline void NVIC_SystemReset(void)
{
	__DSB();
	((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = (uint32_t)((0x5FAUL << 16U) |
	(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
	(1UL << 2U) );
	__DSB();
	for (;;)
	{
		__NOP();
	}
}
static inline uint32_t SysTick_Config(uint32_t ticks)
{
	if ((ticks - 1UL) > (0xFFFFFFUL ))
	{
		return (1UL);
	}
	((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (uint32_t)(ticks - 1UL);
	NVIC_SetPriority (SysTick_IRQn, (1UL << 3) - 1UL);
	((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0UL;
	((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) |
		(1UL << 1U) |
		(1UL );
	return (0UL);
}
extern volatile int32_t ITM_RxBuffer;
static inline uint32_t ITM_SendChar (uint32_t ch)
{
	if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&
			((((ITM_Type *) (0xE0000000UL) )->TER & 1UL ) != 0UL) )
	{
		while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
		{
			__NOP();
		}
		((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
	}
	return (ch);
}
static inline int32_t ITM_ReceiveChar (void)
{
	int32_t ch = -1;
	if (ITM_RxBuffer != 0x5AA55AA5U)
	{
		ch = ITM_RxBuffer;
		ITM_RxBuffer = 0x5AA55AA5U;
	}
	return (ch);
}
static inline int32_t ITM_CheckChar (void)
{
	if (ITM_RxBuffer == 0x5AA55AA5U)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
extern uint32_t SystemCoreClock;
extern void SystemInit (void);
extern void SystemCoreClockUpdate (void);
typedef struct {
	volatile const uint32_t PART;
	volatile const uint32_t VARIANT;
	volatile const uint32_t PACKAGE;
	volatile const uint32_t RAM;
	volatile const uint32_t FLASH;
	volatile uint32_t UNUSED0[3];
} FICR_INFO_Type;
typedef struct {
	volatile const uint32_t A0;
	volatile const uint32_t A1;
	volatile const uint32_t A2;
	volatile const uint32_t A3;
	volatile const uint32_t A4;
	volatile const uint32_t A5;
	volatile const uint32_t B0;
	volatile const uint32_t B1;
	volatile const uint32_t B2;
	volatile const uint32_t B3;
	volatile const uint32_t B4;
	volatile const uint32_t B5;
	volatile const uint32_t T0;
	volatile const uint32_t T1;
	volatile const uint32_t T2;
	volatile const uint32_t T3;
	volatile const uint32_t T4;
} FICR_TEMP_Type;
typedef struct {
	volatile const uint32_t TAGHEADER0;
	volatile const uint32_t TAGHEADER1;
	volatile const uint32_t TAGHEADER2;
	volatile const uint32_t TAGHEADER3;
} FICR_NFC_Type;
typedef struct {
	volatile uint32_t POWER;
	volatile uint32_t POWERSET;
	volatile uint32_t POWERCLR;
	volatile const uint32_t RESERVED0;
} POWER_RAM_Type;
typedef struct {
	volatile uint32_t RTS;
	volatile uint32_t TXD;
	volatile uint32_t CTS;
	volatile uint32_t RXD;
} UARTE_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} UARTE_RXD_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} UARTE_TXD_Type;
typedef struct {
	volatile uint32_t RTS;
	volatile uint32_t TXD;
	volatile uint32_t CTS;
	volatile uint32_t RXD;
} UART_PSEL_Type;
typedef struct {
	volatile uint32_t SCK;
	volatile uint32_t MOSI;
	volatile uint32_t MISO;
	volatile uint32_t CSN;
} SPIM_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
	volatile uint32_t LIST;
} SPIM_RXD_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
	volatile uint32_t LIST;
} SPIM_TXD_Type;
typedef struct {
	volatile uint32_t RXDELAY;
	volatile uint32_t CSNDUR;
} SPIM_IFTIMING_Type;
typedef struct {
	volatile uint32_t SCK;
	volatile uint32_t MISO;
	volatile uint32_t MOSI;
	volatile uint32_t CSN;
} SPIS_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} SPIS_RXD_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} SPIS_TXD_Type;
typedef struct {
	volatile uint32_t SCL;
	volatile uint32_t SDA;
} TWIM_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
	volatile uint32_t LIST;
} TWIM_RXD_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
	volatile uint32_t LIST;
} TWIM_TXD_Type;
typedef struct {
	volatile uint32_t SCL;
	volatile uint32_t SDA;
} TWIS_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} TWIS_RXD_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} TWIS_TXD_Type;
typedef struct {
	volatile uint32_t SCK;
	volatile uint32_t MOSI;
	volatile uint32_t MISO;
} SPI_PSEL_Type;
typedef struct {
	volatile uint32_t SCL;
	volatile uint32_t SDA;
} TWI_PSEL_Type;
typedef struct {
	volatile uint32_t RX;
} NFCT_FRAMESTATUS_Type;
typedef struct {
	volatile uint32_t FRAMECONFIG;
	volatile uint32_t AMOUNT;
} NFCT_TXD_Type;
typedef struct {
	volatile uint32_t FRAMECONFIG;
	volatile const uint32_t AMOUNT;
} NFCT_RXD_Type;
typedef struct {
	volatile uint32_t LIMITH;
	volatile uint32_t LIMITL;
} SAADC_EVENTS_CH_Type;
typedef struct {
	volatile uint32_t PSELP;
	volatile uint32_t PSELN;
	volatile uint32_t CONFIG;
	volatile uint32_t LIMIT;
} SAADC_CH_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} SAADC_RESULT_Type;
typedef struct {
	volatile uint32_t LED;
	volatile uint32_t A;
	volatile uint32_t B;
} QDEC_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t CNT;
	volatile uint32_t REFRESH;
	volatile uint32_t ENDDELAY;
	volatile const uint32_t RESERVED1[4];
} PWM_SEQ_Type;
typedef struct {
	volatile uint32_t OUT[4];
} PWM_PSEL_Type;
typedef struct {
	volatile uint32_t CLK;
	volatile uint32_t DIN;
} PDM_PSEL_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
} PDM_SAMPLE_Type;
typedef struct {
	volatile uint32_t ADDR;
	volatile uint32_t SIZE;
	volatile uint32_t PERM;
	volatile uint32_t UNUSED0;
} ACL_ACL_Type;
typedef struct {
	volatile uint32_t EN;
	volatile uint32_t DIS;
} PPI_TASKS_CHG_Type;
typedef struct {
	volatile uint32_t EEP;
	volatile uint32_t TEP;
} PPI_CH_Type;
typedef struct {
	volatile uint32_t TEP;
} PPI_FORK_Type;
typedef struct {
	volatile uint32_t WA;
	volatile uint32_t RA;
} MWU_EVENTS_REGION_Type;
typedef struct {
	volatile uint32_t WA;
	volatile uint32_t RA;
} MWU_EVENTS_PREGION_Type;
typedef struct {
	volatile uint32_t SUBSTATWA;
	volatile uint32_t SUBSTATRA;
} MWU_PERREGION_Type;
typedef struct {
	volatile uint32_t START;
	volatile uint32_t END;
	volatile const uint32_t RESERVED2[2];
} MWU_REGION_Type;
typedef struct {
	volatile const uint32_t START;
	volatile const uint32_t END;
	volatile uint32_t SUBS;
	volatile const uint32_t RESERVED3;
} MWU_PREGION_Type;
typedef struct {
	volatile uint32_t MODE;
	volatile uint32_t RXEN;
	volatile uint32_t TXEN;
	volatile uint32_t MCKEN;
	volatile uint32_t MCKFREQ;
	volatile uint32_t RATIO;
	volatile uint32_t SWIDTH;
	volatile uint32_t ALIGN;
	volatile uint32_t FORMAT;
	volatile uint32_t CHANNELS;
} I2S_CONFIG_Type;
typedef struct {
	volatile uint32_t PTR;
} I2S_RXD_Type;
typedef struct {
	volatile uint32_t PTR;
} I2S_TXD_Type;
typedef struct {
	volatile uint32_t MAXCNT;
} I2S_RXTXD_Type;
typedef struct {
	volatile uint32_t MCK;
	volatile uint32_t SCK;
	volatile uint32_t LRCK;
	volatile uint32_t SDIN;
	volatile uint32_t SDOUT;
} I2S_PSEL_Type;
typedef struct {
	volatile const uint32_t EPIN[8];
	volatile const uint32_t RESERVED4;
	volatile const uint32_t EPOUT[8];
} USBD_HALTED_Type;
typedef struct {
	volatile uint32_t EPOUT[8];
	volatile const uint32_t ISOOUT;
} USBD_SIZE_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
	volatile const uint32_t RESERVED5[2];
} USBD_EPIN_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} USBD_ISOIN_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
	volatile const uint32_t RESERVED6[2];
} USBD_EPOUT_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t MAXCNT;
	volatile const uint32_t AMOUNT;
} USBD_ISOOUT_Type;
typedef struct {
	volatile uint32_t SRC;
	volatile uint32_t DST;
	volatile uint32_t CNT;
} QSPI_READ_Type;
typedef struct {
	volatile uint32_t DST;
	volatile uint32_t SRC;
	volatile uint32_t CNT;
} QSPI_WRITE_Type;
typedef struct {
	volatile uint32_t PTR;
	volatile uint32_t LEN;
} QSPI_ERASE_Type;
typedef struct {
	volatile uint32_t SCK;
	volatile uint32_t CSN;
	volatile const uint32_t RESERVED7;
	volatile uint32_t IO0;
	volatile uint32_t IO1;
	volatile uint32_t IO2;
	volatile uint32_t IO3;
} QSPI_PSEL_Type;
typedef struct {
	volatile const uint32_t RESERVED0[4];
	volatile const uint32_t CODEPAGESIZE;
	volatile const uint32_t CODESIZE;
	volatile const uint32_t RESERVED1[18];
	volatile const uint32_t DEVICEID[2];
	volatile const uint32_t RESERVED2[6];
	volatile const uint32_t ER[4];
	volatile const uint32_t IR[4];
	volatile const uint32_t DEVICEADDRTYPE;
	volatile const uint32_t DEVICEADDR[2];
	volatile const uint32_t RESERVED3[21];
	FICR_INFO_Type INFO;
	volatile const uint32_t RESERVED4[185];
	FICR_TEMP_Type TEMP;
	volatile const uint32_t RESERVED5[2];
	FICR_NFC_Type NFC;
} NRF_FICR_Type;
typedef struct {
	volatile uint32_t UNUSED0;
	volatile uint32_t UNUSED1;
	volatile uint32_t UNUSED2;
	volatile const uint32_t RESERVED0;
	volatile uint32_t UNUSED3;
	volatile uint32_t NRFFW[15];
	volatile uint32_t NRFHW[12];
	volatile uint32_t CUSTOMER[32];
	volatile const uint32_t RESERVED1[64];
	volatile uint32_t PSELRESET[2];
	volatile uint32_t APPROTECT;
	volatile uint32_t NFCPINS;
	volatile uint32_t DEBUGCTRL;
	volatile const uint32_t RESERVED2[59];
	volatile uint32_t DCDCDRIVE0;
	volatile uint32_t REGOUT0;
} NRF_UICR_Type;
typedef struct {
	volatile const uint32_t RESERVED0[30];
	volatile uint32_t TASKS_CONSTLAT;
	volatile uint32_t TASKS_LOWPWR;
	volatile const uint32_t RESERVED1[34];
	volatile uint32_t EVENTS_POFWARN;
	volatile const uint32_t RESERVED2[2];
	volatile uint32_t EVENTS_SLEEPENTER;
	volatile uint32_t EVENTS_SLEEPEXIT;
	volatile uint32_t EVENTS_USBDETECTED;
	volatile uint32_t EVENTS_USBREMOVED;
	volatile uint32_t EVENTS_USBPWRRDY;
	volatile const uint32_t RESERVED3[119];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED4[61];
	volatile uint32_t RESETREAS;
	volatile const uint32_t RESERVED5[9];
	volatile const uint32_t RAMSTATUS;
	volatile const uint32_t RESERVED6[3];
	volatile const uint32_t USBREGSTATUS;
	volatile const uint32_t RESERVED7[49];
	volatile uint32_t SYSTEMOFF;
	volatile const uint32_t RESERVED8[3];
	volatile uint32_t POFCON;
	volatile const uint32_t RESERVED9[2];
	volatile uint32_t GPREGRET;
	volatile uint32_t GPREGRET2;
	volatile const uint32_t RESERVED10[21];
	volatile uint32_t DCDCEN;
	volatile const uint32_t RESERVED11;
	volatile uint32_t DCDCEN0;
	volatile const uint32_t RESERVED12[47];
	volatile const uint32_t MAINREGSTATUS;
	volatile const uint32_t RESERVED13[175];
	POWER_RAM_Type RAM[9];
} NRF_POWER_Type;
typedef struct {
	volatile uint32_t TASKS_HFCLKSTART;
	volatile uint32_t TASKS_HFCLKSTOP;
	volatile uint32_t TASKS_LFCLKSTART;
	volatile uint32_t TASKS_LFCLKSTOP;
	volatile uint32_t TASKS_CAL;
	volatile uint32_t TASKS_CTSTART;
	volatile uint32_t TASKS_CTSTOP;
	volatile const uint32_t RESERVED0[57];
	volatile uint32_t EVENTS_HFCLKSTARTED;
	volatile uint32_t EVENTS_LFCLKSTARTED;
	volatile const uint32_t RESERVED1;
	volatile uint32_t EVENTS_DONE;
	volatile uint32_t EVENTS_CTTO;
	volatile const uint32_t RESERVED2[5];
	volatile uint32_t EVENTS_CTSTARTED;
	volatile uint32_t EVENTS_CTSTOPPED;
	volatile const uint32_t RESERVED3[117];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED4[63];
	volatile const uint32_t HFCLKRUN;
	volatile const uint32_t HFCLKSTAT;
	volatile const uint32_t RESERVED5;
	volatile const uint32_t LFCLKRUN;
	volatile const uint32_t LFCLKSTAT;
	volatile const uint32_t LFCLKSRCCOPY;
	volatile const uint32_t RESERVED6[62];
	volatile uint32_t LFCLKSRC;
	volatile const uint32_t RESERVED7[3];
	volatile uint32_t HFXODEBOUNCE;
	volatile const uint32_t RESERVED8[3];
	volatile uint32_t CTIV;
	volatile const uint32_t RESERVED9[8];
	volatile uint32_t TRACECONFIG;
	volatile const uint32_t RESERVED10[21];
	volatile uint32_t LFRCMODE;
} NRF_CLOCK_Type;
typedef struct {
	volatile uint32_t TASKS_TXEN;
	volatile uint32_t TASKS_RXEN;
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_DISABLE;
	volatile uint32_t TASKS_RSSISTART;
	volatile uint32_t TASKS_RSSISTOP;
	volatile uint32_t TASKS_BCSTART;
	volatile uint32_t TASKS_BCSTOP;
	volatile uint32_t TASKS_EDSTART;
	volatile uint32_t TASKS_EDSTOP;
	volatile uint32_t TASKS_CCASTART;
	volatile uint32_t TASKS_CCASTOP;
	volatile const uint32_t RESERVED0[51];
	volatile uint32_t EVENTS_READY;
	volatile uint32_t EVENTS_ADDRESS;
	volatile uint32_t EVENTS_PAYLOAD;
	volatile uint32_t EVENTS_END;
	volatile uint32_t EVENTS_DISABLED;
	volatile uint32_t EVENTS_DEVMATCH;
	volatile uint32_t EVENTS_DEVMISS;
	volatile uint32_t EVENTS_RSSIEND;
	volatile const uint32_t RESERVED1[2];
	volatile uint32_t EVENTS_BCMATCH;
	volatile const uint32_t RESERVED2;
	volatile uint32_t EVENTS_CRCOK;
	volatile uint32_t EVENTS_CRCERROR;
	volatile uint32_t EVENTS_FRAMESTART;
	volatile uint32_t EVENTS_EDEND;
	volatile uint32_t EVENTS_EDSTOPPED;
	volatile uint32_t EVENTS_CCAIDLE;
	volatile uint32_t EVENTS_CCABUSY;
	volatile uint32_t EVENTS_CCASTOPPED;
	volatile uint32_t EVENTS_RATEBOOST;
	volatile uint32_t EVENTS_TXREADY;
	volatile uint32_t EVENTS_RXREADY;
	volatile uint32_t EVENTS_MHRMATCH;
	volatile const uint32_t RESERVED3[3];
	volatile uint32_t EVENTS_PHYEND;
	volatile const uint32_t RESERVED4[36];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED5[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED6[61];
	volatile const uint32_t CRCSTATUS;
	volatile const uint32_t RESERVED7;
	volatile const uint32_t RXMATCH;
	volatile const uint32_t RXCRC;
	volatile const uint32_t DAI;
	volatile const uint32_t PDUSTAT;
	volatile const uint32_t RESERVED8[59];
	volatile uint32_t PACKETPTR;
	volatile uint32_t FREQUENCY;
	volatile uint32_t TXPOWER;
	volatile uint32_t MODE;
	volatile uint32_t PCNF0;
	volatile uint32_t PCNF1;
	volatile uint32_t BASE0;
	volatile uint32_t BASE1;
	volatile uint32_t PREFIX0;
	volatile uint32_t PREFIX1;
	volatile uint32_t TXADDRESS;
	volatile uint32_t RXADDRESSES;
	volatile uint32_t CRCCNF;
	volatile uint32_t CRCPOLY;
	volatile uint32_t CRCINIT;
	volatile const uint32_t RESERVED9;
	volatile uint32_t TIFS;
	volatile const uint32_t RSSISAMPLE;
	volatile const uint32_t RESERVED10;
	volatile const uint32_t STATE;
	volatile uint32_t DATAWHITEIV;
	volatile const uint32_t RESERVED11[2];
	volatile uint32_t BCC;
	volatile const uint32_t RESERVED12[39];
	volatile uint32_t DAB[8];
	volatile uint32_t DAP[8];
	volatile uint32_t DACNF;
	volatile uint32_t MHRMATCHCONF;
	volatile uint32_t MHRMATCHMAS;
	volatile const uint32_t RESERVED13;
	volatile uint32_t MODECNF0;
	volatile const uint32_t RESERVED14[3];
	volatile uint32_t SFD;
	volatile uint32_t EDCNT;
	volatile uint32_t EDSAMPLE;
	volatile uint32_t CCACTRL;
	volatile const uint32_t RESERVED15[611];
	volatile uint32_t POWER;
} NRF_RADIO_Type;
typedef struct {
	volatile uint32_t TASKS_STARTRX;
	volatile uint32_t TASKS_STOPRX;
	volatile uint32_t TASKS_STARTTX;
	volatile uint32_t TASKS_STOPTX;
	volatile const uint32_t RESERVED0[7];
	volatile uint32_t TASKS_FLUSHRX;
	volatile const uint32_t RESERVED1[52];
	volatile uint32_t EVENTS_CTS;
	volatile uint32_t EVENTS_NCTS;
	volatile uint32_t EVENTS_RXDRDY;
	volatile const uint32_t RESERVED2;
	volatile uint32_t EVENTS_ENDRX;
	volatile const uint32_t RESERVED3[2];
	volatile uint32_t EVENTS_TXDRDY;
	volatile uint32_t EVENTS_ENDTX;
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED4[7];
	volatile uint32_t EVENTS_RXTO;
	volatile const uint32_t RESERVED5;
	volatile uint32_t EVENTS_RXSTARTED;
	volatile uint32_t EVENTS_TXSTARTED;
	volatile const uint32_t RESERVED6;
	volatile uint32_t EVENTS_TXSTOPPED;
	volatile const uint32_t RESERVED7[41];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED8[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED9[93];
	volatile uint32_t ERRORSRC;
	volatile const uint32_t RESERVED10[31];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED11;
	UARTE_PSEL_Type PSEL;
	volatile const uint32_t RESERVED12[3];
	volatile uint32_t BAUDRATE;
	volatile const uint32_t RESERVED13[3];
	UARTE_RXD_Type RXD;
	volatile const uint32_t RESERVED14;
	UARTE_TXD_Type TXD;
	volatile const uint32_t RESERVED15[7];
	volatile uint32_t CONFIG;
} NRF_UARTE_Type;
typedef struct {
	volatile uint32_t TASKS_STARTRX;
	volatile uint32_t TASKS_STOPRX;
	volatile uint32_t TASKS_STARTTX;
	volatile uint32_t TASKS_STOPTX;
	volatile const uint32_t RESERVED0[3];
	volatile uint32_t TASKS_SUSPEND;
	volatile const uint32_t RESERVED1[56];
	volatile uint32_t EVENTS_CTS;
	volatile uint32_t EVENTS_NCTS;
	volatile uint32_t EVENTS_RXDRDY;
	volatile const uint32_t RESERVED2[4];
	volatile uint32_t EVENTS_TXDRDY;
	volatile const uint32_t RESERVED3;
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED4[7];
	volatile uint32_t EVENTS_RXTO;
	volatile const uint32_t RESERVED5[46];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED6[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED7[93];
	volatile uint32_t ERRORSRC;
	volatile const uint32_t RESERVED8[31];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED9;
	UART_PSEL_Type PSEL;
	volatile const uint32_t RXD;
	volatile uint32_t TXD;
	volatile const uint32_t RESERVED10;
	volatile uint32_t BAUDRATE;
	volatile const uint32_t RESERVED11[17];
	volatile uint32_t CONFIG;
} NRF_UART_Type;
typedef struct {
	volatile const uint32_t RESERVED0[4];
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED1;
	volatile uint32_t TASKS_SUSPEND;
	volatile uint32_t TASKS_RESUME;
	volatile const uint32_t RESERVED2[56];
	volatile uint32_t EVENTS_STOPPED;
	volatile const uint32_t RESERVED3[2];
	volatile uint32_t EVENTS_ENDRX;
	volatile const uint32_t RESERVED4;
	volatile uint32_t EVENTS_END;
	volatile const uint32_t RESERVED5;
	volatile uint32_t EVENTS_ENDTX;
	volatile const uint32_t RESERVED6[10];
	volatile uint32_t EVENTS_STARTED;
	volatile const uint32_t RESERVED7[44];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED8[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED9[61];
	volatile uint32_t STALLSTAT;
	volatile const uint32_t RESERVED10[63];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED11;
	SPIM_PSEL_Type PSEL;
	volatile const uint32_t RESERVED12[3];
	volatile uint32_t FREQUENCY;
	volatile const uint32_t RESERVED13[3];
	SPIM_RXD_Type RXD;
	SPIM_TXD_Type TXD;
	volatile uint32_t CONFIG;
	volatile const uint32_t RESERVED14[2];
	SPIM_IFTIMING_Type IFTIMING;
	volatile uint32_t CSNPOL;
	volatile uint32_t PSELDCX;
	volatile uint32_t DCXCNT;
	volatile const uint32_t RESERVED15[19];
	volatile uint32_t ORC;
} NRF_SPIM_Type;
typedef struct {
	volatile const uint32_t RESERVED0[9];
	volatile uint32_t TASKS_ACQUIRE;
	volatile uint32_t TASKS_RELEASE;
	volatile const uint32_t RESERVED1[54];
	volatile uint32_t EVENTS_END;
	volatile const uint32_t RESERVED2[2];
	volatile uint32_t EVENTS_ENDRX;
	volatile const uint32_t RESERVED3[5];
	volatile uint32_t EVENTS_ACQUIRED;
	volatile const uint32_t RESERVED4[53];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED5[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED6[61];
	volatile const uint32_t SEMSTAT;
	volatile const uint32_t RESERVED7[15];
	volatile uint32_t STATUS;
	volatile const uint32_t RESERVED8[47];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED9;
	SPIS_PSEL_Type PSEL;
	volatile const uint32_t RESERVED10[7];
	SPIS_RXD_Type RXD;
	volatile const uint32_t RESERVED11;
	SPIS_TXD_Type TXD;
	volatile const uint32_t RESERVED12;
	volatile uint32_t CONFIG;
	volatile const uint32_t RESERVED13;
	volatile uint32_t DEF;
	volatile const uint32_t RESERVED14[24];
	volatile uint32_t ORC;
} NRF_SPIS_Type;
typedef struct {
	volatile uint32_t TASKS_STARTRX;
	volatile const uint32_t RESERVED0;
	volatile uint32_t TASKS_STARTTX;
	volatile const uint32_t RESERVED1[2];
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED2;
	volatile uint32_t TASKS_SUSPEND;
	volatile uint32_t TASKS_RESUME;
	volatile const uint32_t RESERVED3[56];
	volatile uint32_t EVENTS_STOPPED;
	volatile const uint32_t RESERVED4[7];
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED5[8];
	volatile uint32_t EVENTS_SUSPENDED;
	volatile uint32_t EVENTS_RXSTARTED;
	volatile uint32_t EVENTS_TXSTARTED;
	volatile const uint32_t RESERVED6[2];
	volatile uint32_t EVENTS_LASTRX;
	volatile uint32_t EVENTS_LASTTX;
	volatile const uint32_t RESERVED7[39];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED8[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED9[110];
	volatile uint32_t ERRORSRC;
	volatile const uint32_t RESERVED10[14];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED11;
	TWIM_PSEL_Type PSEL;
	volatile const uint32_t RESERVED12[5];
	volatile uint32_t FREQUENCY;
	volatile const uint32_t RESERVED13[3];
	TWIM_RXD_Type RXD;
	TWIM_TXD_Type TXD;
	volatile const uint32_t RESERVED14[13];
	volatile uint32_t ADDRESS;
} NRF_TWIM_Type;
typedef struct {
	volatile const uint32_t RESERVED0[5];
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED1;
	volatile uint32_t TASKS_SUSPEND;
	volatile uint32_t TASKS_RESUME;
	volatile const uint32_t RESERVED2[3];
	volatile uint32_t TASKS_PREPARERX;
	volatile uint32_t TASKS_PREPARETX;
	volatile const uint32_t RESERVED3[51];
	volatile uint32_t EVENTS_STOPPED;
	volatile const uint32_t RESERVED4[7];
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED5[9];
	volatile uint32_t EVENTS_RXSTARTED;
	volatile uint32_t EVENTS_TXSTARTED;
	volatile const uint32_t RESERVED6[4];
	volatile uint32_t EVENTS_WRITE;
	volatile uint32_t EVENTS_READ;
	volatile const uint32_t RESERVED7[37];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED8[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED9[113];
	volatile uint32_t ERRORSRC;
	volatile const uint32_t MATCH;
	volatile const uint32_t RESERVED10[10];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED11;
	TWIS_PSEL_Type PSEL;
	volatile const uint32_t RESERVED12[9];
	TWIS_RXD_Type RXD;
	volatile const uint32_t RESERVED13;
	TWIS_TXD_Type TXD;
	volatile const uint32_t RESERVED14[14];
	volatile uint32_t ADDRESS[2];
	volatile const uint32_t RESERVED15;
	volatile uint32_t CONFIG;
	volatile const uint32_t RESERVED16[10];
	volatile uint32_t ORC;
} NRF_TWIS_Type;
typedef struct {
	volatile const uint32_t RESERVED0[66];
	volatile uint32_t EVENTS_READY;
	volatile const uint32_t RESERVED1[126];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[125];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED3;
	SPI_PSEL_Type PSEL;
	volatile const uint32_t RESERVED4;
	volatile const uint32_t RXD;
	volatile uint32_t TXD;
	volatile const uint32_t RESERVED5;
	volatile uint32_t FREQUENCY;
	volatile const uint32_t RESERVED6[11];
	volatile uint32_t CONFIG;
} NRF_SPI_Type;
typedef struct {
	volatile uint32_t TASKS_STARTRX;
	volatile const uint32_t RESERVED0;
	volatile uint32_t TASKS_STARTTX;
	volatile const uint32_t RESERVED1[2];
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED2;
	volatile uint32_t TASKS_SUSPEND;
	volatile uint32_t TASKS_RESUME;
	volatile const uint32_t RESERVED3[56];
	volatile uint32_t EVENTS_STOPPED;
	volatile uint32_t EVENTS_RXDREADY;
	volatile const uint32_t RESERVED4[4];
	volatile uint32_t EVENTS_TXDSENT;
	volatile const uint32_t RESERVED5;
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED6[4];
	volatile uint32_t EVENTS_BB;
	volatile const uint32_t RESERVED7[3];
	volatile uint32_t EVENTS_SUSPENDED;
	volatile const uint32_t RESERVED8[45];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED9[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED10[110];
	volatile uint32_t ERRORSRC;
	volatile const uint32_t RESERVED11[14];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED12;
	TWI_PSEL_Type PSEL;
	volatile const uint32_t RESERVED13[2];
	volatile const uint32_t RXD;
	volatile uint32_t TXD;
	volatile const uint32_t RESERVED14;
	volatile uint32_t FREQUENCY;
	volatile const uint32_t RESERVED15[24];
	volatile uint32_t ADDRESS;
} NRF_TWI_Type;
typedef struct {
	volatile uint32_t TASKS_ACTIVATE;
	volatile uint32_t TASKS_DISABLE;
	volatile uint32_t TASKS_SENSE;
	volatile uint32_t TASKS_STARTTX;
	volatile const uint32_t RESERVED0[3];
	volatile uint32_t TASKS_ENABLERXDATA;
	volatile const uint32_t RESERVED1;
	volatile uint32_t TASKS_GOIDLE;
	volatile uint32_t TASKS_GOSLEEP;
	volatile const uint32_t RESERVED2[53];
	volatile uint32_t EVENTS_READY;
	volatile uint32_t EVENTS_FIELDDETECTED;
	volatile uint32_t EVENTS_FIELDLOST;
	volatile uint32_t EVENTS_TXFRAMESTART;
	volatile uint32_t EVENTS_TXFRAMEEND;
	volatile uint32_t EVENTS_RXFRAMESTART;
	volatile uint32_t EVENTS_RXFRAMEEND;
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED3[2];
	volatile uint32_t EVENTS_RXERROR;
	volatile uint32_t EVENTS_ENDRX;
	volatile uint32_t EVENTS_ENDTX;
	volatile const uint32_t RESERVED4;
	volatile uint32_t EVENTS_AUTOCOLRESSTARTED;
	volatile const uint32_t RESERVED5[3];
	volatile uint32_t EVENTS_COLLISION;
	volatile uint32_t EVENTS_SELECTED;
	volatile uint32_t EVENTS_STARTED;
	volatile const uint32_t RESERVED6[43];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED7[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED8[62];
	volatile uint32_t ERRORSTATUS;
	volatile const uint32_t RESERVED9;
	NFCT_FRAMESTATUS_Type FRAMESTATUS;
	volatile const uint32_t NFCTAGSTATE;
	volatile const uint32_t RESERVED10[10];
	volatile const uint32_t FIELDPRESENT;
	volatile const uint32_t RESERVED11[49];
	volatile uint32_t FRAMEDELAYMIN;
	volatile uint32_t FRAMEDELAYMAX;
	volatile uint32_t FRAMEDELAYMODE;
	volatile uint32_t PACKETPTR;
	volatile uint32_t MAXLEN;
	NFCT_TXD_Type TXD;
	NFCT_RXD_Type RXD;
	volatile const uint32_t RESERVED12[26];
	volatile uint32_t NFCID1_LAST;
	volatile uint32_t NFCID1_2ND_LAST;
	volatile uint32_t NFCID1_3RD_LAST;
	volatile uint32_t AUTOCOLRESCONFIG;
	volatile uint32_t SENSRES;
	volatile uint32_t SELRES;
} NRF_NFCT_Type;
typedef struct {
	volatile uint32_t TASKS_OUT[8];
	volatile const uint32_t RESERVED0[4];
	volatile uint32_t TASKS_SET[8];
	volatile const uint32_t RESERVED1[4];
	volatile uint32_t TASKS_CLR[8];
	volatile const uint32_t RESERVED2[32];
	volatile uint32_t EVENTS_IN[8];
	volatile const uint32_t RESERVED3[23];
	volatile uint32_t EVENTS_PORT;
	volatile const uint32_t RESERVED4[97];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED5[129];
	volatile uint32_t CONFIG[8];
} NRF_GPIOTE_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_SAMPLE;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_CALIBRATEOFFSET;
	volatile const uint32_t RESERVED0[60];
	volatile uint32_t EVENTS_STARTED;
	volatile uint32_t EVENTS_END;
	volatile uint32_t EVENTS_DONE;
	volatile uint32_t EVENTS_RESULTDONE;
	volatile uint32_t EVENTS_CALIBRATEDONE;
	volatile uint32_t EVENTS_STOPPED;
	SAADC_EVENTS_CH_Type EVENTS_CH[8];
	volatile const uint32_t RESERVED1[106];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[61];
	volatile const uint32_t STATUS;
	volatile const uint32_t RESERVED3[63];
	volatile uint32_t ENABLE;
	volatile const uint32_t RESERVED4[3];
	SAADC_CH_Type CH[8];
	volatile const uint32_t RESERVED5[24];
	volatile uint32_t RESOLUTION;
	volatile uint32_t OVERSAMPLE;
	volatile uint32_t SAMPLERATE;
	volatile const uint32_t RESERVED6[12];
	SAADC_RESULT_Type RESULT;
} NRF_SAADC_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_COUNT;
	volatile uint32_t TASKS_CLEAR;
	volatile uint32_t TASKS_SHUTDOWN;
	volatile const uint32_t RESERVED0[11];
	volatile uint32_t TASKS_CAPTURE[6];
	volatile const uint32_t RESERVED1[58];
	volatile uint32_t EVENTS_COMPARE[6];
	volatile const uint32_t RESERVED2[42];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED3[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED4[126];
	volatile uint32_t MODE;
	volatile uint32_t BITMODE;
	volatile const uint32_t RESERVED5;
	volatile uint32_t PRESCALER;
	volatile const uint32_t RESERVED6[11];
	volatile uint32_t CC[6];
} NRF_TIMER_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_CLEAR;
	volatile uint32_t TASKS_TRIGOVRFLW;
	volatile const uint32_t RESERVED0[60];
	volatile uint32_t EVENTS_TICK;
	volatile uint32_t EVENTS_OVRFLW;
	volatile const uint32_t RESERVED1[14];
	volatile uint32_t EVENTS_COMPARE[4];
	volatile const uint32_t RESERVED2[109];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[13];
	volatile uint32_t EVTEN;
	volatile uint32_t EVTENSET;
	volatile uint32_t EVTENCLR;
	volatile const uint32_t RESERVED4[110];
	volatile const uint32_t COUNTER;
	volatile uint32_t PRESCALER;
	volatile const uint32_t RESERVED5[13];
	volatile uint32_t CC[4];
} NRF_RTC_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED0[62];
	volatile uint32_t EVENTS_DATARDY;
	volatile const uint32_t RESERVED1[128];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[127];
	volatile const int32_t TEMP;
	volatile const uint32_t RESERVED3[5];
	volatile uint32_t A0;
	volatile uint32_t A1;
	volatile uint32_t A2;
	volatile uint32_t A3;
	volatile uint32_t A4;
	volatile uint32_t A5;
	volatile const uint32_t RESERVED4[2];
	volatile uint32_t B0;
	volatile uint32_t B1;
	volatile uint32_t B2;
	volatile uint32_t B3;
	volatile uint32_t B4;
	volatile uint32_t B5;
	volatile const uint32_t RESERVED5[2];
	volatile uint32_t T0;
	volatile uint32_t T1;
	volatile uint32_t T2;
	volatile uint32_t T3;
	volatile uint32_t T4;
} NRF_TEMP_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED0[62];
	volatile uint32_t EVENTS_VALRDY;
	volatile const uint32_t RESERVED1[63];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED2[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[126];
	volatile uint32_t CONFIG;
	volatile const uint32_t VALUE;
} NRF_RNG_Type;
typedef struct {
	volatile uint32_t TASKS_STARTECB;
	volatile uint32_t TASKS_STOPECB;
	volatile const uint32_t RESERVED0[62];
	volatile uint32_t EVENTS_ENDECB;
	volatile uint32_t EVENTS_ERRORECB;
	volatile const uint32_t RESERVED1[127];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[126];
	volatile uint32_t ECBDATAPTR;
} NRF_ECB_Type;
typedef struct {
	volatile uint32_t TASKS_KSGEN;
	volatile uint32_t TASKS_CRYPT;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_RATEOVERRIDE;
	volatile const uint32_t RESERVED0[60];
	volatile uint32_t EVENTS_ENDKSGEN;
	volatile uint32_t EVENTS_ENDCRYPT;
	volatile uint32_t EVENTS_ERROR;
	volatile const uint32_t RESERVED1[61];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED2[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[61];
	volatile const uint32_t MICSTATUS;
	volatile const uint32_t RESERVED4[63];
	volatile uint32_t ENABLE;
	volatile uint32_t MODE;
	volatile uint32_t CNFPTR;
	volatile uint32_t INPTR;
	volatile uint32_t OUTPTR;
	volatile uint32_t SCRATCHPTR;
	volatile uint32_t MAXPACKETSIZE;
	volatile uint32_t RATEOVERRIDE;
} NRF_CCM_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile const uint32_t RESERVED0;
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED1[61];
	volatile uint32_t EVENTS_END;
	volatile uint32_t EVENTS_RESOLVED;
	volatile uint32_t EVENTS_NOTRESOLVED;
	volatile const uint32_t RESERVED2[126];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[61];
	volatile const uint32_t STATUS;
	volatile const uint32_t RESERVED4[63];
	volatile uint32_t ENABLE;
	volatile uint32_t NIRK;
	volatile uint32_t IRKPTR;
	volatile const uint32_t RESERVED5;
	volatile uint32_t ADDRPTR;
	volatile uint32_t SCRATCHPTR;
} NRF_AAR_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile const uint32_t RESERVED0[63];
	volatile uint32_t EVENTS_TIMEOUT;
	volatile const uint32_t RESERVED1[128];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[61];
	volatile const uint32_t RUNSTATUS;
	volatile const uint32_t REQSTATUS;
	volatile const uint32_t RESERVED3[63];
	volatile uint32_t CRV;
	volatile uint32_t RREN;
	volatile uint32_t CONFIG;
	volatile const uint32_t RESERVED4[60];
	volatile uint32_t RR[8];
} NRF_WDT_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_READCLRACC;
	volatile uint32_t TASKS_RDCLRACC;
	volatile uint32_t TASKS_RDCLRDBL;
	volatile const uint32_t RESERVED0[59];
	volatile uint32_t EVENTS_SAMPLERDY;
	volatile uint32_t EVENTS_REPORTRDY;
	volatile uint32_t EVENTS_ACCOF;
	volatile uint32_t EVENTS_DBLRDY;
	volatile uint32_t EVENTS_STOPPED;
	volatile const uint32_t RESERVED1[59];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED2[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[125];
	volatile uint32_t ENABLE;
	volatile uint32_t LEDPOL;
	volatile uint32_t SAMPLEPER;
	volatile const int32_t SAMPLE;
	volatile uint32_t REPORTPER;
	volatile const int32_t ACC;
	volatile const int32_t ACCREAD;
	QDEC_PSEL_Type PSEL;
	volatile uint32_t DBFEN;
	volatile const uint32_t RESERVED4[5];
	volatile uint32_t LEDPRE;
	volatile const uint32_t ACCDBL;
	volatile const uint32_t ACCDBLREAD;
} NRF_QDEC_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_SAMPLE;
	volatile const uint32_t RESERVED0[61];
	volatile uint32_t EVENTS_READY;
	volatile uint32_t EVENTS_DOWN;
	volatile uint32_t EVENTS_UP;
	volatile uint32_t EVENTS_CROSS;
	volatile const uint32_t RESERVED1[60];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED2[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[61];
	volatile const uint32_t RESULT;
	volatile const uint32_t RESERVED4[63];
	volatile uint32_t ENABLE;
	volatile uint32_t PSEL;
	volatile uint32_t REFSEL;
	volatile uint32_t EXTREFSEL;
	volatile const uint32_t RESERVED5[8];
	volatile uint32_t TH;
	volatile uint32_t MODE;
	volatile uint32_t HYST;
} NRF_COMP_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_SAMPLE;
	volatile const uint32_t RESERVED0[61];
	volatile uint32_t EVENTS_READY;
	volatile uint32_t EVENTS_DOWN;
	volatile uint32_t EVENTS_UP;
	volatile uint32_t EVENTS_CROSS;
	volatile const uint32_t RESERVED1[60];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED2[64];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[61];
	volatile const uint32_t RESULT;
	volatile const uint32_t RESERVED4[63];
	volatile uint32_t ENABLE;
	volatile uint32_t PSEL;
	volatile uint32_t REFSEL;
	volatile uint32_t EXTREFSEL;
	volatile const uint32_t RESERVED5[4];
	volatile uint32_t ANADETECT;
	volatile const uint32_t RESERVED6[5];
	volatile uint32_t HYST;
} NRF_LPCOMP_Type;
typedef struct {
	volatile const uint32_t UNUSED;
} NRF_SWI_Type;
typedef struct {
	volatile uint32_t TASKS_TRIGGER[16];
	volatile const uint32_t RESERVED0[48];
	volatile uint32_t EVENTS_TRIGGERED[16];
	volatile const uint32_t RESERVED1[112];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
} NRF_EGU_Type;
typedef struct {
	volatile const uint32_t RESERVED0;
	volatile uint32_t TASKS_STOP;
	volatile uint32_t TASKS_SEQSTART[2];
	volatile uint32_t TASKS_NEXTSTEP;
	volatile const uint32_t RESERVED1[60];
	volatile uint32_t EVENTS_STOPPED;
	volatile uint32_t EVENTS_SEQSTARTED[2];
	volatile uint32_t EVENTS_SEQEND[2];
	volatile uint32_t EVENTS_PWMPERIODEND;
	volatile uint32_t EVENTS_LOOPSDONE;
	volatile const uint32_t RESERVED2[56];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED3[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED4[125];
	volatile uint32_t ENABLE;
	volatile uint32_t MODE;
	volatile uint32_t COUNTERTOP;
	volatile uint32_t PRESCALER;
	volatile uint32_t DECODER;
	volatile uint32_t LOOP;
	volatile const uint32_t RESERVED5[2];
	PWM_SEQ_Type SEQ[2];
	PWM_PSEL_Type PSEL;
} NRF_PWM_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED0[62];
	volatile uint32_t EVENTS_STARTED;
	volatile uint32_t EVENTS_STOPPED;
	volatile uint32_t EVENTS_END;
	volatile const uint32_t RESERVED1[125];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[125];
	volatile uint32_t ENABLE;
	volatile uint32_t PDMCLKCTRL;
	volatile uint32_t MODE;
	volatile const uint32_t RESERVED3[3];
	volatile uint32_t GAINL;
	volatile uint32_t GAINR;
	volatile uint32_t RATIO;
	volatile const uint32_t RESERVED4[7];
	PDM_PSEL_Type PSEL;
	volatile const uint32_t RESERVED5[6];
	PDM_SAMPLE_Type SAMPLE;
} NRF_PDM_Type;
typedef struct {
	volatile const uint32_t RESERVED0[256];
	volatile const uint32_t READY;
	volatile const uint32_t RESERVED1;
	volatile const uint32_t READYNEXT;
	volatile const uint32_t RESERVED2[62];
	volatile uint32_t CONFIG;
	union {
		volatile uint32_t ERASEPAGE;
		volatile uint32_t ERASEPCR1;
	};
	volatile uint32_t ERASEALL;
	volatile uint32_t ERASEPCR0;
	volatile uint32_t ERASEUICR;
	volatile const uint32_t RESERVED3[10];
	volatile uint32_t ICACHECNF;
	volatile const uint32_t RESERVED4;
	volatile uint32_t IHIT;
	volatile uint32_t IMISS;
} NRF_NVMC_Type;
typedef struct {
	volatile const uint32_t RESERVED0[512];
	ACL_ACL_Type ACL[8];
} NRF_ACL_Type;
typedef struct {
	PPI_TASKS_CHG_Type TASKS_CHG[6];
	volatile const uint32_t RESERVED0[308];
	volatile uint32_t CHEN;
	volatile uint32_t CHENSET;
	volatile uint32_t CHENCLR;
	volatile const uint32_t RESERVED1;
	PPI_CH_Type CH[20];
	volatile const uint32_t RESERVED2[148];
	volatile uint32_t CHG[6];
	volatile const uint32_t RESERVED3[62];
	PPI_FORK_Type FORK[32];
} NRF_PPI_Type;
typedef struct {
	volatile const uint32_t RESERVED0[64];
	MWU_EVENTS_REGION_Type EVENTS_REGION[4];
	volatile const uint32_t RESERVED1[16];
	MWU_EVENTS_PREGION_Type EVENTS_PREGION[2];
	volatile const uint32_t RESERVED2[100];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[5];
	volatile uint32_t NMIEN;
	volatile uint32_t NMIENSET;
	volatile uint32_t NMIENCLR;
	volatile const uint32_t RESERVED4[53];
	MWU_PERREGION_Type PERREGION[2];
	volatile const uint32_t RESERVED5[64];
	volatile uint32_t REGIONEN;
	volatile uint32_t REGIONENSET;
	volatile uint32_t REGIONENCLR;
	volatile const uint32_t RESERVED6[57];
	MWU_REGION_Type REGION[4];
	volatile const uint32_t RESERVED7[32];
	MWU_PREGION_Type PREGION[2];
} NRF_MWU_Type;
typedef struct {
	volatile uint32_t TASKS_START;
	volatile uint32_t TASKS_STOP;
	volatile const uint32_t RESERVED0[63];
	volatile uint32_t EVENTS_RXPTRUPD;
	volatile uint32_t EVENTS_STOPPED;
	volatile const uint32_t RESERVED1[2];
	volatile uint32_t EVENTS_TXPTRUPD;
	volatile const uint32_t RESERVED2[122];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED3[125];
	volatile uint32_t ENABLE;
	I2S_CONFIG_Type CONFIG;
	volatile const uint32_t RESERVED4[3];
	I2S_RXD_Type RXD;
	volatile const uint32_t RESERVED5;
	I2S_TXD_Type TXD;
	volatile const uint32_t RESERVED6[3];
	I2S_RXTXD_Type RXTXD;
	volatile const uint32_t RESERVED7[3];
	I2S_PSEL_Type PSEL;
} NRF_I2S_Type;
typedef struct {
	volatile const uint32_t UNUSED;
} NRF_FPU_Type;
typedef struct {
	volatile const uint32_t RESERVED0;
	volatile uint32_t TASKS_STARTEPIN[8];
	volatile uint32_t TASKS_STARTISOIN;
	volatile uint32_t TASKS_STARTEPOUT[8];
	volatile uint32_t TASKS_STARTISOOUT;
	volatile uint32_t TASKS_EP0RCVOUT;
	volatile uint32_t TASKS_EP0STATUS;
	volatile uint32_t TASKS_EP0STALL;
	volatile uint32_t TASKS_DPDMDRIVE;
	volatile uint32_t TASKS_DPDMNODRIVE;
	volatile const uint32_t RESERVED1[40];
	volatile uint32_t EVENTS_USBRESET;
	volatile uint32_t EVENTS_STARTED;
	volatile uint32_t EVENTS_ENDEPIN[8];
	volatile uint32_t EVENTS_EP0DATADONE;
	volatile uint32_t EVENTS_ENDISOIN;
	volatile uint32_t EVENTS_ENDEPOUT[8];
	volatile uint32_t EVENTS_ENDISOOUT;
	volatile uint32_t EVENTS_SOF;
	volatile uint32_t EVENTS_USBEVENT;
	volatile uint32_t EVENTS_EP0SETUP;
	volatile uint32_t EVENTS_EPDATA;
	volatile uint32_t EVENTS_ACCESSFAULT;
	volatile const uint32_t RESERVED2[38];
	volatile uint32_t SHORTS;
	volatile const uint32_t RESERVED3[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED4[61];
	volatile uint32_t EVENTCAUSE;
	volatile const uint32_t BUSSTATE;
	volatile const uint32_t RESERVED5[6];
	USBD_HALTED_Type HALTED;
	volatile const uint32_t RESERVED6;
	volatile uint32_t EPSTATUS;
	volatile uint32_t EPDATASTATUS;
	volatile const uint32_t USBADDR;
	volatile const uint32_t RESERVED7[3];
	volatile const uint32_t BMREQUESTTYPE;
	volatile const uint32_t BREQUEST;
	volatile const uint32_t WVALUEL;
	volatile const uint32_t WVALUEH;
	volatile const uint32_t WINDEXL;
	volatile const uint32_t WINDEXH;
	volatile const uint32_t WLENGTHL;
	volatile const uint32_t WLENGTHH;
	USBD_SIZE_Type SIZE;
	volatile const uint32_t RESERVED8[15];
	volatile uint32_t ENABLE;
	volatile uint32_t USBPULLUP;
	volatile uint32_t DPDMVALUE;
	volatile uint32_t DTOGGLE;
	volatile uint32_t EPINEN;
	volatile uint32_t EPOUTEN;
	volatile uint32_t EPSTALL;
	volatile uint32_t ISOSPLIT;
	volatile const uint32_t FRAMECNTR;
	volatile const uint32_t RESERVED9[2];
	volatile uint32_t LOWPOWER;
	volatile uint32_t ISOINCONFIG;
	volatile const uint32_t RESERVED10[51];
	USBD_EPIN_Type EPIN[8];
	USBD_ISOIN_Type ISOIN;
	volatile const uint32_t RESERVED11[21];
	USBD_EPOUT_Type EPOUT[8];
	USBD_ISOOUT_Type ISOOUT;
} NRF_USBD_Type;
typedef struct {
	volatile uint32_t TASKS_ACTIVATE;
	volatile uint32_t TASKS_READSTART;
	volatile uint32_t TASKS_WRITESTART;
	volatile uint32_t TASKS_ERASESTART;
	volatile uint32_t TASKS_DEACTIVATE;
	volatile const uint32_t RESERVED0[59];
	volatile uint32_t EVENTS_READY;
	volatile const uint32_t RESERVED1[127];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile const uint32_t RESERVED2[125];
	volatile uint32_t ENABLE;
	QSPI_READ_Type READ;
	QSPI_WRITE_Type WRITE;
	QSPI_ERASE_Type ERASE;
	QSPI_PSEL_Type PSEL;
	volatile uint32_t XIPOFFSET;
	volatile uint32_t IFCONFIG0;
	volatile const uint32_t RESERVED3[46];
	volatile uint32_t IFCONFIG1;
	volatile const uint32_t STATUS;
	volatile const uint32_t RESERVED4[3];
	volatile uint32_t DPMDUR;
	volatile const uint32_t RESERVED5[3];
	volatile uint32_t ADDRCONF;
	volatile const uint32_t RESERVED6[3];
	volatile uint32_t CINSTRCONF;
	volatile uint32_t CINSTRDAT0;
	volatile uint32_t CINSTRDAT1;
	volatile uint32_t IFTIMING;
} NRF_QSPI_Type;
typedef struct {
	volatile const uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile const uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile const uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_Type;
typedef struct {
	volatile const uint32_t RESERVED0[320];
	volatile uint32_t ENABLE;
} NRF_CRYPTOCELL_Type;
extern uint32_t __StackTop;
extern uint32_t __StackLimit;
enum
{
	UNIT_0_625_MS = 625,
	UNIT_1_25_MS = 1250,
	UNIT_10_MS = 10000
};
typedef uint8_t uint16_le_t[2];
typedef uint8_t uint32_le_t[4];
typedef struct
{
	uint16_t size;
	uint8_t * p_data;
} uint8_array_t;
static inline uint64_t value_rescale(uint32_t value, uint32_t old_unit_reversal, uint16_t new_unit_reversal)
{
	return (uint64_t)((((uint64_t)value * new_unit_reversal) + ((old_unit_reversal) / 2)) / (old_unit_reversal));
}
static inline uint8_t uint16_encode(uint16_t value, uint8_t * p_encoded_data)
{
	p_encoded_data[0] = (uint8_t) ((value & 0x00FF) >> 0);
	p_encoded_data[1] = (uint8_t) ((value & 0xFF00) >> 8);
	return sizeof(uint16_t);
}
static inline uint8_t uint24_encode(uint32_t value, uint8_t * p_encoded_data)
{
	p_encoded_data[0] = (uint8_t) ((value & 0x000000FF) >> 0);
	p_encoded_data[1] = (uint8_t) ((value & 0x0000FF00) >> 8);
	p_encoded_data[2] = (uint8_t) ((value & 0x00FF0000) >> 16);
	return 3;
}
static inline uint8_t uint32_encode(uint32_t value, uint8_t * p_encoded_data)
{
	p_encoded_data[0] = (uint8_t) ((value & 0x000000FF) >> 0);
	p_encoded_data[1] = (uint8_t) ((value & 0x0000FF00) >> 8);
	p_encoded_data[2] = (uint8_t) ((value & 0x00FF0000) >> 16);
	p_encoded_data[3] = (uint8_t) ((value & 0xFF000000) >> 24);
	return sizeof(uint32_t);
}
static inline uint8_t uint48_encode(uint64_t value, uint8_t * p_encoded_data)
{
	p_encoded_data[0] = (uint8_t) ((value & 0x0000000000FF) >> 0);
	p_encoded_data[1] = (uint8_t) ((value & 0x00000000FF00) >> 8);
	p_encoded_data[2] = (uint8_t) ((value & 0x000000FF0000) >> 16);
	p_encoded_data[3] = (uint8_t) ((value & 0x0000FF000000) >> 24);
	p_encoded_data[4] = (uint8_t) ((value & 0x00FF00000000) >> 32);
	p_encoded_data[5] = (uint8_t) ((value & 0xFF0000000000) >> 40);
	return 6;
}
static inline uint16_t uint16_decode(const uint8_t * p_encoded_data)
{
	return ( (((uint16_t)((uint8_t *)p_encoded_data)[0])) |
			(((uint16_t)((uint8_t *)p_encoded_data)[1]) << 8 ));
}
static inline uint16_t uint16_big_decode(const uint8_t * p_encoded_data)
{
	return ( (((uint16_t)((uint8_t *)p_encoded_data)[0]) << 8 ) |
			(((uint16_t)((uint8_t *)p_encoded_data)[1])) );
}
static inline uint32_t uint24_decode(const uint8_t * p_encoded_data)
{
	return ( (((uint32_t)((uint8_t *)p_encoded_data)[0]) << 0) |
			(((uint32_t)((uint8_t *)p_encoded_data)[1]) << 8) |
			(((uint32_t)((uint8_t *)p_encoded_data)[2]) << 16));
}
static inline uint32_t uint32_decode(const uint8_t * p_encoded_data)
{
	return ( (((uint32_t)((uint8_t *)p_encoded_data)[0]) << 0) |
			(((uint32_t)((uint8_t *)p_encoded_data)[1]) << 8) |
			(((uint32_t)((uint8_t *)p_encoded_data)[2]) << 16) |
			(((uint32_t)((uint8_t *)p_encoded_data)[3]) << 24 ));
}
static inline uint32_t uint32_big_decode(const uint8_t * p_encoded_data)
{
	return ( (((uint32_t)((uint8_t *)p_encoded_data)[0]) << 24) |
			(((uint32_t)((uint8_t *)p_encoded_data)[1]) << 16) |
			(((uint32_t)((uint8_t *)p_encoded_data)[2]) << 8) |
			(((uint32_t)((uint8_t *)p_encoded_data)[3]) << 0) );
}
static inline uint8_t uint16_big_encode(uint16_t value, uint8_t * p_encoded_data)
{
	p_encoded_data[0] = (uint8_t) (value >> 8);
	p_encoded_data[1] = (uint8_t) (value & 0xFF);
	return sizeof(uint16_t);
}
static inline uint8_t uint32_big_encode(uint32_t value, uint8_t * p_encoded_data)
{
	*(uint32_t *)p_encoded_data = __REV(value);
	return sizeof(uint32_t);
}
static inline uint64_t uint48_decode(const uint8_t * p_encoded_data)
{
	return ( (((uint64_t)((uint8_t *)p_encoded_data)[0]) << 0) |
			(((uint64_t)((uint8_t *)p_encoded_data)[1]) << 8) |
			(((uint64_t)((uint8_t *)p_encoded_data)[2]) << 16) |
			(((uint64_t)((uint8_t *)p_encoded_data)[3]) << 24) |
			(((uint64_t)((uint8_t *)p_encoded_data)[4]) << 32) |
			(((uint64_t)((uint8_t *)p_encoded_data)[5]) << 40 ));
}
static inline uint8_t battery_level_in_percent(const uint16_t mvolts)
{
	uint8_t battery_level;
	if (mvolts >= 3000)
	{
		battery_level = 100;
	}
	else if (mvolts > 2900)
	{
		battery_level = 100 - ((3000 - mvolts) * 58) / 100;
	}
	else if (mvolts > 2740)
	{
		battery_level = 42 - ((2900 - mvolts) * 24) / 160;
	}
	else if (mvolts > 2440)
	{
		battery_level = 18 - ((2740 - mvolts) * 12) / 300;
	}
	else if (mvolts > 2100)
	{
		battery_level = 6 - ((2440 - mvolts) * 6) / 340;
	}
	else
	{
		battery_level = 0;
	}
	return battery_level;
}
static inline 
	_Bool 
is_word_aligned(void const* p)
{
	return (((uintptr_t)p & 0x03) == 0);
}
static inline 
	_Bool 
is_address_from_stack(void * ptr)
{
	if (((uint32_t)ptr >= (uint32_t)&__StackLimit) &&
			((uint32_t)ptr < (uint32_t)&__StackTop) )
	{
		return 
			1
			;
	}
	else
	{
		return 
			0
			;
	}
}
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t;
typedef unsigned long __sigset_t;
typedef __suseconds_t suseconds_t;
typedef long time_t;
struct timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};
struct timespec {
	time_t tv_sec;
	long tv_nsec;
};
struct itimerspec {
	struct timespec it_interval;
	struct timespec it_value;
};
typedef __sigset_t sigset_t;
typedef unsigned long fd_mask;
typedef struct _types_fd_set {
	fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;
int select (int __n, _types_fd_set *__readfds, _types_fd_set *__writefds, _types_fd_set *__exceptfds, struct timeval *__timeout)
	;
int pselect (int __n, _types_fd_set *__readfds, _types_fd_set *__writefds, _types_fd_set *__exceptfds, const struct timespec *__timeout, const sigset_t *__set)
	;
	typedef __uint32_t in_addr_t;
	typedef __uint16_t in_port_t;
	typedef unsigned char u_char;
	typedef unsigned short u_short;
	typedef unsigned int u_int;
	typedef unsigned long u_long;
	typedef unsigned short ushort;
	typedef unsigned int uint;
	typedef unsigned long ulong;
	typedef __blkcnt_t blkcnt_t;
	typedef __blksize_t blksize_t;
	typedef unsigned long clock_t;
	typedef long daddr_t;
	typedef char * caddr_t;
	typedef __fsblkcnt_t fsblkcnt_t;
	typedef __fsfilcnt_t fsfilcnt_t;
	typedef __id_t id_t;
	typedef __ino_t ino_t;
	typedef __off_t off_t;
	typedef __dev_t dev_t;
	typedef __uid_t uid_t;
	typedef __gid_t gid_t;
	typedef __pid_t pid_t;
	typedef __key_t key_t;
	typedef _ssize_t ssize_t;
	typedef __mode_t mode_t;
	typedef __nlink_t nlink_t;
	typedef __clockid_t clockid_t;
	typedef __timer_t timer_t;
	typedef __useconds_t useconds_t;
	typedef __int64_t sbintime_t;
	typedef __FILE FILE;
	typedef _fpos_t fpos_t;
	char * ctermid (char *);
	FILE * tmpfile (void);
	char * tmpnam (char *);
	char * tempnam (const char *, const char *);
	int fclose (FILE *);
	int fflush (FILE *);
	FILE * freopen (const char *restrict, const char *restrict, FILE *restrict);
	void setbuf (FILE *restrict, char *restrict);
	int setvbuf (FILE *restrict, char *restrict, int, size_t);
int fprintf (FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
int fscanf (FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
	;
int printf (const char *restrict, ...) __attribute__ ((__format__ (__printf__, 1, 2)))
	;
int scanf (const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 1, 2)))
	;
int sscanf (const char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
	;
int vfprintf (FILE *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
int vprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)))
	;
int vsprintf (char *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
	int fgetc (FILE *);
	char * fgets (char *restrict, int, FILE *restrict);
	int fputc (int, FILE *);
	int fputs (const char *restrict, FILE *restrict);
	int getc (FILE *);
	int getchar (void);
	char * gets (char *);
	int putc (int, FILE *);
	int putchar (int);
	int puts (const char *);
	int ungetc (int, FILE *);
	size_t fread (void * restrict, size_t _size, size_t _n, FILE *restrict);
	size_t fwrite (const void * restrict , size_t _size, size_t _n, FILE *);
	int fgetpos (FILE *restrict, fpos_t *restrict);
	int fseek (FILE *, long, int);
	int fsetpos (FILE *, const fpos_t *);
	long ftell ( FILE *);
	void rewind (FILE *);
	void clearerr (FILE *);
	int feof (FILE *);
	int ferror (FILE *);
	void perror (const char *);
	FILE * fopen (const char *restrict _name, const char *restrict _type);
int sprintf (char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
	int remove (const char *);
	int rename (const char *, const char *);
	int fseeko (FILE *, off_t, int);
	off_t ftello ( FILE *);
int snprintf (char *restrict, size_t, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int vsnprintf (char *restrict, size_t, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int vfscanf (FILE *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
	;
int vscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)))
	;
int vsscanf (const char *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
	;
int asiprintf (char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
char * asniprintf (char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
char * asnprintf (char *restrict, size_t *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int diprintf (int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
int fiprintf (FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
int fiscanf (FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
	;
int iprintf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)))
	;
int iscanf (const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)))
	;
int siprintf (char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
int siscanf (const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
	;
int sniprintf (char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int vasiprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
char * vasniprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
char * vasnprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int vdiprintf (int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
int vfiprintf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
int vfiscanf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
	;
int viprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)))
	;
int viscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)))
	;
int vsiprintf (char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
int vsiscanf (const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
	;
int vsniprintf (char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
	FILE * fdopen (int, const char *);
	int fileno (FILE *);
	int pclose (FILE *);
	FILE * popen (const char *, const char *);
	void setbuffer (FILE *, char *, int);
	int setlinebuf (FILE *);
	int getw (FILE *);
	int putw (int, FILE *);
	int getc_unlocked (FILE *);
	int getchar_unlocked (void);
	void flockfile (FILE *);
	int ftrylockfile (FILE *);
	void funlockfile (FILE *);
	int putc_unlocked (int, FILE *);
	int putchar_unlocked (int);
int dprintf (int, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
	FILE * fmemopen (void *restrict, size_t, const char *restrict);
	FILE * open_memstream (char **, size_t *);
int vdprintf (int, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
	int renameat (int, const char *, int, const char *);
int _asiprintf_r (struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
char * _asniprintf_r (struct _reent *, char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
	;
char * _asnprintf_r (struct _reent *, char *restrict, size_t *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
	;
int _asprintf_r (struct _reent *, char **restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int _diprintf_r (struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int _dprintf_r (struct _reent *, int, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
	int _fclose_r (struct _reent *, FILE *);
	int _fcloseall_r (struct _reent *);
	FILE * _fdopen_r (struct _reent *, int, const char *);
	int _fflush_r (struct _reent *, FILE *);
	int _fgetc_r (struct _reent *, FILE *);
	int _fgetc_unlocked_r (struct _reent *, FILE *);
	char * _fgets_r (struct _reent *, char *restrict, int, FILE *restrict);
	char * _fgets_unlocked_r (struct _reent *, char *restrict, int, FILE *restrict);
	int _fgetpos_r (struct _reent *, FILE *, fpos_t *);
	int _fsetpos_r (struct _reent *, FILE *, const fpos_t *);
int _fiprintf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int _fiscanf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
	;
	FILE * _fmemopen_r (struct _reent *, void *restrict, size_t, const char *restrict);
	FILE * _fopen_r (struct _reent *, const char *restrict, const char *restrict);
	FILE * _freopen_r (struct _reent *, const char *restrict, const char *restrict, FILE *restrict);
int _fprintf_r (struct _reent *, FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
	int _fpurge_r (struct _reent *, FILE *);
	int _fputc_r (struct _reent *, int, FILE *);
	int _fputc_unlocked_r (struct _reent *, int, FILE *);
	int _fputs_r (struct _reent *, const char *restrict, FILE *restrict);
	int _fputs_unlocked_r (struct _reent *, const char *restrict, FILE *restrict);
	size_t _fread_r (struct _reent *, void * restrict, size_t _size, size_t _n, FILE *restrict);
	size_t _fread_unlocked_r (struct _reent *, void * restrict, size_t _size, size_t _n, FILE *restrict);
int _fscanf_r (struct _reent *, FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
	;
	int _fseek_r (struct _reent *, FILE *, long, int);
	int _fseeko_r (struct _reent *, FILE *, _off_t, int);
	long _ftell_r (struct _reent *, FILE *);
	_off_t _ftello_r (struct _reent *, FILE *);
	void _rewind_r (struct _reent *, FILE *);
	size_t _fwrite_r (struct _reent *, const void * restrict, size_t _size, size_t _n, FILE *restrict);
	size_t _fwrite_unlocked_r (struct _reent *, const void * restrict, size_t _size, size_t _n, FILE *restrict);
	int _getc_r (struct _reent *, FILE *);
	int _getc_unlocked_r (struct _reent *, FILE *);
	int _getchar_r (struct _reent *);
	int _getchar_unlocked_r (struct _reent *);
	char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
int _iscanf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
	;
	FILE * _open_memstream_r (struct _reent *, char **, size_t *);
	void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
	;
	int _putc_r (struct _reent *, int, FILE *);
	int _putc_unlocked_r (struct _reent *, int, FILE *);
	int _putchar_unlocked_r (struct _reent *, int);
	int _putchar_r (struct _reent *, int);
	int _puts_r (struct _reent *, const char *);
	int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new)
	;
int _scanf_r (struct _reent *, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
	;
int _siprintf_r (struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int _siscanf_r (struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
	;
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
	;
int _snprintf_r (struct _reent *, char *restrict, size_t, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
	;
int _sprintf_r (struct _reent *, char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
	;
int _sscanf_r (struct _reent *, const char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
	;
	char * _tempnam_r (struct _reent *, const char *, const char *);
	FILE * _tmpfile_r (struct _reent *);
	char * _tmpnam_r (struct _reent *, char *);
	int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
char * _vasniprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
	;
char * _vasnprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
	;
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vdiprintf_r (struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vdprintf_r (struct _reent *, int, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
	;
int _vfprintf_r (struct _reent *, FILE *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vfscanf_r (struct _reent *, FILE *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
	;
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
	;
int _vprintf_r (struct _reent *, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
	;
int _vscanf_r (struct _reent *, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
	;
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
	;
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
	;
int _vsnprintf_r (struct _reent *, char *restrict, size_t, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
	;
int _vsprintf_r (struct _reent *, char *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
	;
int _vsscanf_r (struct _reent *, const char *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
	;
	int fpurge (FILE *);
	ssize_t __getdelim (char **, size_t *, int, FILE *);
	ssize_t __getline (char **, size_t *, FILE *);
	void clearerr_unlocked (FILE *);
	int feof_unlocked (FILE *);
	int ferror_unlocked (FILE *);
	int fileno_unlocked (FILE *);
	int fflush_unlocked (FILE *);
	int fgetc_unlocked (FILE *);
	int fputc_unlocked (int, FILE *);
	size_t fread_unlocked (void * restrict, size_t _size, size_t _n, FILE *restrict);
	size_t fwrite_unlocked (const void * restrict , size_t _size, size_t _n, FILE *);
	int __srget_r (struct _reent *, FILE *);
	int __swbuf_r (struct _reent *, int, FILE *);
FILE *funopen (const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie))
	;
FILE *_funopen_r (struct _reent *, const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie))
	;
	static __inline__ int __sputc_r(struct _reent *_ptr, int _c, FILE *_p) {
		if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
			return (*_p->_p++ = _c);
		else
			return (__swbuf_r(_ptr, _c, _p));
	}
void app_error_fault_handler(uint32_t id, uint32_t pc, uint32_t info);
typedef struct
{
	uint16_t line_num;
	uint8_t const * p_file_name;
	uint32_t err_code;
} error_info_t;
typedef struct
{
	uint16_t line_num;
	uint8_t const * p_file_name;
} assert_info_t;
void app_error_handler(uint32_t error_code, uint32_t line_num, const uint8_t * p_file_name);
void app_error_handler_bare(ret_code_t error_code);
void app_error_save_and_stop(uint32_t id, uint32_t pc, uint32_t info);
void assert_nrf_callback(uint16_t line_num, const uint8_t *file_name);
typedef enum
{
	NRF_CLOCK_LFCLK_RC = (0UL),
	NRF_CLOCK_LFCLK_Xtal = (1UL),
	NRF_CLOCK_LFCLK_Synth = (2UL)
} nrf_clock_lfclk_t;
typedef enum
{
	NRF_CLOCK_HFCLK_LOW_ACCURACY = (0UL),
	NRF_CLOCK_HFCLK_HIGH_ACCURACY = (1UL)
} nrf_clock_hfclk_t;
typedef enum
{
	NRF_CLOCK_START_TASK_NOT_TRIGGERED = (0UL),
	NRF_CLOCK_START_TASK_TRIGGERED = (1UL)
} nrf_clock_start_task_status_t;
typedef enum
{
	NRF_CLOCK_INT_HF_STARTED_MASK = (0x1UL << (0UL)),
	NRF_CLOCK_INT_LF_STARTED_MASK = (0x1UL << (1UL)),
	NRF_CLOCK_INT_DONE_MASK = (0x1UL << (3UL)),
	NRF_CLOCK_INT_CTTO_MASK = (0x1UL << (4UL))
} nrf_clock_int_mask_t;
typedef enum
{
	NRF_CLOCK_TASK_HFCLKSTART = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_HFCLKSTART
				)
		,
	NRF_CLOCK_TASK_HFCLKSTOP = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_HFCLKSTOP
				)
		,
	NRF_CLOCK_TASK_LFCLKSTART = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_LFCLKSTART
				)
		,
	NRF_CLOCK_TASK_LFCLKSTOP = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_LFCLKSTOP
				)
		,
	NRF_CLOCK_TASK_CAL = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_CAL
				)
		,
	NRF_CLOCK_TASK_CTSTART = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_CTSTART
				)
		,
	NRF_CLOCK_TASK_CTSTOP = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				TASKS_CTSTOP
				)
} nrf_clock_task_t;
typedef enum
{
	NRF_CLOCK_EVENT_HFCLKSTARTED = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				EVENTS_HFCLKSTARTED
				)
		,
	NRF_CLOCK_EVENT_LFCLKSTARTED = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				EVENTS_LFCLKSTARTED
				)
		,
	NRF_CLOCK_EVENT_DONE = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				EVENTS_DONE
				)
		,
	NRF_CLOCK_EVENT_CTTO = 
		__builtin_offsetof (
				NRF_CLOCK_Type
				, 
				EVENTS_CTTO
				)
} nrf_clock_event_t;
static inline void nrf_clock_int_enable(uint32_t int_mask);
static inline void nrf_clock_int_disable(uint32_t int_mask);
static inline 
_Bool 
nrf_clock_int_enable_check(nrf_clock_int_mask_t int_mask);
static inline uint32_t nrf_clock_task_address_get(nrf_clock_task_t task);
static inline void nrf_clock_task_trigger(nrf_clock_task_t task);
static inline uint32_t nrf_clock_event_address_get(nrf_clock_event_t event);
static inline void nrf_clock_event_clear(nrf_clock_event_t event);
static inline 
_Bool 
nrf_clock_event_check(nrf_clock_event_t event);
static inline void nrf_clock_lf_src_set(nrf_clock_lfclk_t source);
static inline nrf_clock_lfclk_t nrf_clock_lf_src_get(void);
static inline nrf_clock_lfclk_t nrf_clock_lf_actv_src_get(void);
static inline nrf_clock_lfclk_t nrf_clock_lf_srccopy_get(void);
static inline 
_Bool 
nrf_clock_lf_is_running(void);
static inline nrf_clock_start_task_status_t nrf_clock_lf_start_task_status_get(void);
static inline nrf_clock_hfclk_t nrf_clock_hf_src_get(void);
static inline 
_Bool 
nrf_clock_hf_is_running(nrf_clock_hfclk_t clk_src);
static inline nrf_clock_start_task_status_t nrf_clock_hf_start_task_status_get(void);
static inline void nrf_clock_cal_timer_timeout_set(uint32_t interval);
static inline void nrf_clock_int_enable(uint32_t int_mask)
{
	((NRF_CLOCK_Type *) 0x40000000UL)->INTENSET = int_mask;
}
static inline void nrf_clock_int_disable(uint32_t int_mask)
{
	((NRF_CLOCK_Type *) 0x40000000UL)->INTENCLR = int_mask;
}
static inline 
	_Bool 
nrf_clock_int_enable_check(nrf_clock_int_mask_t int_mask)
{
	return (
			_Bool
	       )(((NRF_CLOCK_Type *) 0x40000000UL)->INTENCLR & int_mask);
}
static inline uint32_t nrf_clock_task_address_get(nrf_clock_task_t task)
{
	return ((uint32_t )((NRF_CLOCK_Type *) 0x40000000UL) + task);
}
static inline void nrf_clock_task_trigger(nrf_clock_task_t task)
{
	*((volatile uint32_t *)((uint8_t *)((NRF_CLOCK_Type *) 0x40000000UL) + task)) = (1UL);
}
static inline uint32_t nrf_clock_event_address_get(nrf_clock_event_t event)
{
	return ((uint32_t)((NRF_CLOCK_Type *) 0x40000000UL) + event);
}
static inline void nrf_clock_event_clear(nrf_clock_event_t event)
{
	*((volatile uint32_t *)((uint8_t *)((NRF_CLOCK_Type *) 0x40000000UL) + event)) = (0UL);
	volatile uint32_t dummy = *((volatile uint32_t *)((uint8_t *)((NRF_CLOCK_Type *) 0x40000000UL) + event));
	(void)dummy;
}
static inline 
	_Bool 
nrf_clock_event_check(nrf_clock_event_t event)
{
	return (
			_Bool
	       )*((volatile uint32_t *)((uint8_t *)((NRF_CLOCK_Type *) 0x40000000UL) + event));
}
static inline void nrf_clock_lf_src_set(nrf_clock_lfclk_t source)
{
	((NRF_CLOCK_Type *) 0x40000000UL)->LFCLKSRC =
		(uint32_t)((source << (0UL)) & (0x3UL << (0UL)));
}
static inline nrf_clock_lfclk_t nrf_clock_lf_src_get(void)
{
	return (nrf_clock_lfclk_t)((((NRF_CLOCK_Type *) 0x40000000UL)->LFCLKSRC &
				(0x3UL << (0UL))) >> (0UL));
}
static inline nrf_clock_lfclk_t nrf_clock_lf_actv_src_get(void)
{
	return (nrf_clock_lfclk_t)((((NRF_CLOCK_Type *) 0x40000000UL)->LFCLKSTAT &
				(0x3UL << (0UL))) >> (0UL));
}
static inline nrf_clock_lfclk_t nrf_clock_lf_srccopy_get(void)
{
	return (nrf_clock_lfclk_t)((((NRF_CLOCK_Type *) 0x40000000UL)->LFCLKSRCCOPY &
				(0x3UL << (0UL))) >> (0UL));
}
static inline 
	_Bool 
nrf_clock_lf_is_running(void)
{
	return ((((NRF_CLOCK_Type *) 0x40000000UL)->LFCLKSTAT &
				(0x1UL << (16UL))) >> (16UL));
}
static inline nrf_clock_start_task_status_t nrf_clock_lf_start_task_status_get(void)
{
	return (nrf_clock_start_task_status_t)((((NRF_CLOCK_Type *) 0x40000000UL)->LFCLKRUN &
				(0x1UL << (0UL))) >>
			(0UL));
}
static inline nrf_clock_hfclk_t nrf_clock_hf_src_get(void)
{
	return (nrf_clock_hfclk_t)((((NRF_CLOCK_Type *) 0x40000000UL)->HFCLKSTAT &
				(0x1UL << (0UL))) >> (0UL));
}
static inline 
	_Bool 
nrf_clock_hf_is_running(nrf_clock_hfclk_t clk_src)
{
	return (((NRF_CLOCK_Type *) 0x40000000UL)->HFCLKSTAT & ((0x1UL << (16UL)) | (0x1UL << (0UL)))) ==
		((0x1UL << (16UL)) | (clk_src << (0UL)));
}
static inline nrf_clock_start_task_status_t nrf_clock_hf_start_task_status_get(void)
{
	return (nrf_clock_start_task_status_t)((((NRF_CLOCK_Type *) 0x40000000UL)->HFCLKRUN &
				(0x1UL << (0UL))) >>
			(0UL));
}
static inline void nrf_clock_cal_timer_timeout_set(uint32_t interval)
{
	((NRF_CLOCK_Type *) 0x40000000UL)->CTIV = ((interval << (0UL)) & (0x7FUL << (0UL)));
}
typedef enum
{
	NRF_DRV_STATE_UNINITIALIZED,
	NRF_DRV_STATE_INITIALIZED,
	NRF_DRV_STATE_POWERED_ON
} nrf_drv_state_t;
typedef enum
{
	NRF_DRV_PWR_CTRL_ON,
	NRF_DRV_PWR_CTRL_OFF
} nrf_drv_pwr_ctrl_t;
typedef void (*nrf_drv_irq_handler_t)(void);
void nrf_drv_common_irq_enable(IRQn_Type IRQn, uint8_t priority);
void nrf_drv_common_clock_irq_disable(void);
static inline 
_Bool 
nrf_drv_common_irq_enable_check(IRQn_Type IRQn);
static inline void nrf_drv_common_irq_disable(IRQn_Type IRQn);
static inline uint32_t nrf_drv_bitpos_to_event(uint32_t bit);
static inline uint32_t nrf_drv_event_to_bitpos(uint32_t event);
static inline IRQn_Type nrf_drv_get_IRQn(void const * const pinst);
static inline void nrf_drv_common_power_clock_irq_init(void);
static inline 
_Bool 
nrf_drv_is_in_RAM(void const * const ptr);
static inline 
	_Bool 
nrf_drv_common_irq_enable_check(IRQn_Type IRQn)
{
	return 0 != (((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] &
			(uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL)));
}
static inline void nrf_drv_common_irq_disable(IRQn_Type IRQn)
{
	NVIC_DisableIRQ(IRQn);
}
static inline uint32_t nrf_drv_bitpos_to_event(uint32_t bit)
{
	return 0x100U + bit * sizeof(uint32_t);
}
static inline uint32_t nrf_drv_event_to_bitpos(uint32_t event)
{
	return (event - 0x100U) / sizeof(uint32_t);
}
static inline IRQn_Type nrf_drv_get_IRQn(void const * const pinst)
{
	uint8_t ret = (uint8_t)((uint32_t)pinst>>12U);
	return (IRQn_Type) ret;
}
static inline void nrf_drv_common_power_clock_irq_init(void)
{
	if (!nrf_drv_common_irq_enable_check(POWER_CLOCK_IRQn))
	{
		nrf_drv_common_irq_enable(
				POWER_CLOCK_IRQn,
				7
				);
	}
}
static inline 
	_Bool 
nrf_drv_is_in_RAM(void const * const ptr)
{
	return ((((uintptr_t)ptr) & 0xE0000000u) == 0x20000000u);
}
typedef enum
{
	NRF_DRV_CLOCK_EVT_HFCLK_STARTED,
	NRF_DRV_CLOCK_EVT_LFCLK_STARTED,
	NRF_DRV_CLOCK_EVT_CAL_DONE,
	NRF_DRV_CLOCK_EVT_CAL_ABORTED,
} nrf_drv_clock_evt_type_t;
typedef void (*nrf_drv_clock_event_handler_t)(nrf_drv_clock_evt_type_t event);
typedef struct nrf_drv_clock_handler_item_s nrf_drv_clock_handler_item_t;
struct nrf_drv_clock_handler_item_s
{
	nrf_drv_clock_handler_item_t * p_next;
	nrf_drv_clock_event_handler_t event_handler;
};
_Bool 
nrf_drv_clock_init_check(void);
ret_code_t nrf_drv_clock_init(void);
void nrf_drv_clock_uninit(void);
void nrf_drv_clock_lfclk_request(nrf_drv_clock_handler_item_t * p_handler_item);
void nrf_drv_clock_lfclk_release(void);
_Bool 
nrf_drv_clock_lfclk_is_running(void);
void nrf_drv_clock_hfclk_request(nrf_drv_clock_handler_item_t * p_handler_item);
void nrf_drv_clock_hfclk_release(void);
_Bool 
nrf_drv_clock_hfclk_is_running(void);
ret_code_t nrf_drv_clock_calibration_start(uint8_t delay, nrf_drv_clock_event_handler_t handler);
ret_code_t nrf_drv_clock_calibration_abort(void);
ret_code_t nrf_drv_clock_is_calibrating(
		_Bool 
		* p_is_calibrating);
static inline uint32_t nrf_drv_clock_ppi_task_addr(nrf_clock_task_t task);
static inline uint32_t nrf_drv_clock_ppi_event_addr(nrf_clock_event_t event);
static inline uint32_t nrf_drv_clock_ppi_task_addr(nrf_clock_task_t task)
{
	return nrf_clock_task_address_get(task);
}
static inline uint32_t nrf_drv_clock_ppi_event_addr(nrf_clock_event_t event)
{
	return nrf_clock_event_address_get(event);
}
typedef enum
{
	APP_IRQ_PRIORITY_HIGHEST = 0,
	APP_IRQ_PRIORITY_HIGH = 2,
	APP_IRQ_PRIORITY_MID = 4,
	APP_IRQ_PRIORITY_LOW = 6,
	APP_IRQ_PRIORITY_LOWEST = 7,
	APP_IRQ_PRIORITY_THREAD = 15
} app_irq_priority_t;
typedef enum
{
	APP_LEVEL_UNPRIVILEGED,
	APP_LEVEL_PRIVILEGED
} app_level_t;
void app_util_critical_region_enter (uint8_t *p_nested);
void app_util_critical_region_exit (uint8_t nested);
uint8_t current_int_priority_get(void);
uint8_t privilege_level_get(void);
typedef char name_t;
typedef uint32_t sem_count_t;
typedef uint32_t cpu_stack_t;
typedef uint32_t hr_timer_t;
typedef uint32_t lr_timer_t;
typedef uint32_t mutex_nested_t;
typedef uint8_t suspend_nested_t;
typedef uint64_t ctx_switch_t;
typedef uint32_t cpu_cpsr_t;
typedef enum {
	RHINO_SUCCESS = 0u,
	RHINO_SYS_FATAL_ERR,
	RHINO_SYS_SP_ERR,
	RHINO_RUNNING,
	RHINO_STOPPED,
	RHINO_INV_PARAM,
	RHINO_NULL_PTR,
	RHINO_INV_ALIGN,
	RHINO_KOBJ_TYPE_ERR,
	RHINO_KOBJ_DEL_ERR,
	RHINO_KOBJ_DOCKER_EXIST,
	RHINO_KOBJ_BLK,
	RHINO_KOBJ_SET_FULL,
	RHINO_NOTIFY_FUNC_EXIST,
	RHINO_MM_POOL_SIZE_ERR = 100u,
	RHINO_MM_ALLOC_SIZE_ERR,
	RHINO_MM_FREE_ADDR_ERR,
	RHINO_MM_CORRUPT_ERR,
	RHINO_DYN_MEM_PROC_ERR,
	RHINO_NO_MEM,
	RHINO_RINGBUF_FULL,
	RHINO_RINGBUF_EMPTY,
	RHINO_SCHED_DISABLE = 200u,
	RHINO_SCHED_ALREADY_ENABLED,
	RHINO_SCHED_LOCK_COUNT_OVF,
	RHINO_INV_SCHED_WAY,
	RHINO_TASK_INV_STACK_SIZE = 300u,
	RHINO_TASK_NOT_SUSPENDED,
	RHINO_TASK_DEL_NOT_ALLOWED,
	RHINO_TASK_SUSPEND_NOT_ALLOWED,
	RHINO_SUSPENDED_COUNT_OVF,
	RHINO_BEYOND_MAX_PRI,
	RHINO_PRI_CHG_NOT_ALLOWED,
	RHINO_INV_TASK_STATE,
	RHINO_IDLE_TASK_EXIST,
	RHINO_NO_PEND_WAIT = 400u,
	RHINO_BLK_ABORT,
	RHINO_BLK_TIMEOUT,
	RHINO_BLK_DEL,
	RHINO_BLK_INV_STATE,
	RHINO_BLK_POOL_SIZE_ERR,
	RHINO_TIMER_STATE_INV = 500u,
	RHINO_NO_THIS_EVENT_OPT = 600u,
	RHINO_BUF_QUEUE_INV_SIZE = 700u,
	RHINO_BUF_QUEUE_SIZE_ZERO,
	RHINO_BUF_QUEUE_FULL,
	RHINO_BUF_QUEUE_MSG_SIZE_OVERFLOW,
	RHINO_QUEUE_FULL,
	RHINO_QUEUE_NOT_FULL,
	RHINO_SEM_OVF = 800u,
	RHINO_SEM_TASK_WAITING,
	RHINO_MUTEX_NOT_RELEASED_BY_OWNER = 900u,
	RHINO_MUTEX_OWNER_NESTED,
	RHINO_MUTEX_NESTED_OVF,
	RHINO_NOT_CALLED_BY_INTRPT = 1000u,
	RHINO_TRY_AGAIN,
	RHINO_WORKQUEUE_EXIST = 1100u,
	RHINO_WORKQUEUE_NOT_EXIST,
	RHINO_WORKQUEUE_WORK_EXIST,
	RHINO_WORKQUEUE_BUSY,
	RHINO_WORKQUEUE_WORK_RUNNING,
	RHINO_TASK_STACK_OVF = 1200u,
	RHINO_INTRPT_STACK_OVF
} kstat_t;
typedef void (*krhino_err_proc_t)(kstat_t err);
extern krhino_err_proc_t g_err_proc;
typedef struct {
	cpu_cpsr_t cpsr;
} kspinlock_t;
typedef uint64_t sys_time_t;
typedef int64_t sys_time_i_t;
typedef uint64_t idle_count_t;
typedef uint64_t tick_t;
typedef int64_t tick_i_t;
kstat_t krhino_init(void);
kstat_t krhino_start(void);
kstat_t krhino_intrpt_enter(void);
void krhino_intrpt_exit(void);
void krhino_intrpt_stack_ovf_check(void);
tick_t krhino_next_sleep_ticks_get(void);
size_t krhino_global_space_get(void);
uint32_t krhino_version_get(void);
static inline void krhino_bitmap_set(uint32_t *bitmap, int32_t nr)
{
	bitmap[((nr) >> 5U)] |= (1UL << (32U - 1U - ((nr) & 0X0000001F)));
}
static inline void krhino_bitmap_clear(uint32_t *bitmap, int32_t nr)
{
	bitmap[((nr) >> 5U)] &= ~(1UL << (32U - 1U - ((nr) & 0X0000001F)));
}
static inline uint8_t krhino_clz32(uint32_t x)
{
	uint8_t n = 0;
	if (x == 0) {
		return 32;
	}
	if ((x & 0XFFFF0000) == 0) {
		x <<= 16;
		n += 16;
	}
	if ((x & 0XFF000000) == 0) {
		x <<= 8;
		n += 8;
	}
	if ((x & 0XF0000000) == 0) {
		x <<= 4;
		n += 4;
	}
	if ((x & 0XC0000000) == 0) {
		x <<= 2;
		n += 2;
	}
	if ((x & 0X80000000) == 0) {
		n += 1;
	}
	return n;
}
static inline uint8_t krhino_ctz32(uint32_t x)
{
	uint8_t n = 0;
	if (x == 0) {
		return 32;
	}
	if ((x & 0X0000FFFF) == 0) {
		x >>= 16;
		n += 16;
	}
	if ((x & 0X000000FF) == 0) {
		x >>= 8;
		n += 8;
	}
	if ((x & 0X0000000F) == 0) {
		x >>= 4;
		n += 4;
	}
	if ((x & 0X00000003) == 0) {
		x >>= 2;
		n += 2;
	}
	if ((x & 0X00000001) == 0) {
		n += 1;
	}
	return n;
}
static inline int32_t krhino_find_first_bit(uint32_t *bitmap)
{
	int32_t nr = 0;
	uint32_t tmp = 0;
	while (*bitmap == 0UL) {
		nr += 32U;
		bitmap++;
	}
	tmp = *bitmap;
	if (!(tmp & 0XFFFF0000)) {
		tmp <<= 16;
		nr += 16;
	}
	if (!(tmp & 0XFF000000)) {
		tmp <<= 8;
		nr += 8;
	}
	if (!(tmp & 0XF0000000)) {
		tmp <<= 4;
		nr += 4;
	}
	if (!(tmp & 0XC0000000)) {
		tmp <<= 2;
		nr += 2;
	}
	if (!(tmp & 0X80000000)) {
		nr += 1;
	}
	return nr;
}
typedef struct klist_s {
	struct klist_s *next;
	struct klist_s *prev;
} klist_t;
static inline void klist_init(klist_t *list_head)
{
	list_head->next = list_head;
	list_head->prev = list_head;
}
static inline uint8_t is_klist_empty(klist_t *list)
{
	return (list->next == list);
}
static inline void klist_insert(klist_t *head, klist_t *element)
{
	element->prev = head->prev;
	element->next = head;
	head->prev->next = element;
	head->prev = element;
}
static inline void klist_add(klist_t *head, klist_t *element)
{
	element->prev = head;
	element->next = head->next;
	head->next->prev = element;
	head->next = element;
}
static inline void klist_rm(klist_t *element)
{
	element->prev->next = element->next;
	element->next->prev = element->prev;
}
static inline void klist_rm_init(klist_t *element)
{
	element->prev->next = element->next;
	element->next->prev = element->prev;
	element->next = element->prev = element;
}
typedef enum {
	BLK_POLICY_PRI = 0u,
	BLK_POLICY_FIFO
} blk_policy_t;
typedef enum {
	BLK_FINISH = 0,
	BLK_ABORT,
	BLK_TIMEOUT,
	BLK_DEL,
	BLK_INVALID
} blk_state_t;
typedef enum {
	RHINO_OBJ_TYPE_NONE = 0,
	RHINO_SEM_OBJ_TYPE,
	RHINO_MUTEX_OBJ_TYPE,
	RHINO_QUEUE_OBJ_TYPE,
	RHINO_BUF_QUEUE_OBJ_TYPE,
	RHINO_TIMER_OBJ_TYPE,
	RHINO_EVENT_OBJ_TYPE,
	RHINO_MM_OBJ_TYPE
} kobj_type_t;
typedef struct blk_obj {
	klist_t blk_list;
	const name_t *name;
	blk_policy_t blk_policy;
	kobj_type_t obj_type;
} blk_obj_t;
typedef struct {
	klist_t task_head;
	klist_t mutex_head;
	klist_t mblkpool_head;
	klist_t sem_head;
	klist_t queue_head;
	klist_t event_head;
	klist_t buf_queue_head;
} kobj_list_t;
typedef struct {
	klist_t *cur_list_item[62];
	uint32_t task_bit_map[((62 + 31) / 32)];
	uint8_t highest_pri;
} runqueue_t;
kstat_t krhino_sched_disable(void);
kstat_t krhino_sched_enable(void);
typedef enum {
	K_SEED,
	K_RDY,
	K_PEND,
	K_SUSPENDED,
	K_PEND_SUSPENDED,
	K_SLEEP,
	K_SLEEP_SUSPENDED,
	K_DELETED,
} task_stat_t;
typedef struct {
	void *task_stack;
	const name_t *task_name;
	void *user_info[2];
	cpu_stack_t *task_stack_base;
	uint32_t stack_size;
	klist_t task_list;
	suspend_nested_t suspend_count;
	struct mutex_s *mutex_list;
	klist_t task_stats_item;
	klist_t tick_list;
	tick_t tick_match;
	tick_t tick_remain;
	klist_t *tick_head;
	void *msg;
	size_t bq_msg_size;
	task_stat_t task_state;
	blk_state_t blk_state;
	blk_obj_t *blk_obj;
	struct sem_s *task_sem_obj;
	uint32_t time_slice;
	uint32_t time_total;
	uint32_t pend_flags;
	void *pend_info;
	uint8_t pend_option;
	uint8_t sched_policy;
	uint8_t cpu_num;
	uint8_t prio;
	uint8_t b_prio;
	uint8_t mm_alloc_flag;
} ktask_t;
typedef void (*task_entry_t)(void *arg);
kstat_t krhino_task_create(ktask_t *task, const name_t *name, void *arg,
		uint8_t prio, tick_t ticks, cpu_stack_t *stack_buf,
		size_t stack_size, task_entry_t entry, uint8_t autorun);
kstat_t krhino_task_dyn_create(ktask_t **task, const name_t *name, void *arg,
		uint8_t pri,
		tick_t ticks, size_t stack,
		task_entry_t entry, uint8_t autorun);
kstat_t krhino_task_del(ktask_t *task);
kstat_t krhino_task_dyn_del(ktask_t *task);
kstat_t krhino_task_sleep(tick_t dly);
kstat_t krhino_task_yield(void);
ktask_t *krhino_cur_task_get(void);
kstat_t krhino_task_suspend(ktask_t *task);
kstat_t krhino_task_resume(ktask_t *task);
kstat_t krhino_task_stack_min_free(ktask_t *task, size_t *free);
kstat_t krhino_task_stack_cur_free(ktask_t *task, size_t *free);
kstat_t krhino_task_pri_change(ktask_t *task, uint8_t pri, uint8_t *old_pri);
kstat_t krhino_task_wait_abort(ktask_t *task);
kstat_t krhino_task_time_slice_set(ktask_t *task, size_t slice);
kstat_t krhino_sched_policy_set(ktask_t *task, uint8_t policy);
kstat_t krhino_sched_policy_get(ktask_t *task, uint8_t *policy);
kstat_t krhino_task_info_set(ktask_t *task, size_t idx, void *info);
kstat_t krhino_task_info_get(ktask_t *task, size_t idx, void **info);
void krhino_task_deathbed(void);
typedef struct {
	uint8_t *buf;
	uint8_t *end;
	uint8_t *head;
	uint8_t *tail;
	size_t freesize;
	size_t type;
	size_t blk_size;
} k_ringbuf_t;
typedef struct {
	void **queue_start;
	size_t size;
	size_t cur_num;
	size_t peak_num;
} msg_q_t;
typedef struct {
	msg_q_t msg_q;
	klist_t *pend_entry;
} msg_info_t;
typedef struct queue_s {
	blk_obj_t blk_obj;
	k_ringbuf_t ringbuf;
	msg_q_t msg_q;
	klist_t queue_item;
	uint8_t mm_alloc_flag;
} kqueue_t;
kstat_t krhino_queue_create(kqueue_t *queue, const name_t *name, void **start,
		size_t msg_num);
kstat_t krhino_queue_del(kqueue_t *queue);
kstat_t krhino_queue_dyn_create(kqueue_t **queue, const name_t *name,
		size_t msg_num);
kstat_t krhino_queue_dyn_del(kqueue_t *queue);
kstat_t krhino_queue_back_send(kqueue_t *queue, void *msg);
kstat_t krhino_queue_all_send(kqueue_t *queue, void *msg);
kstat_t krhino_queue_recv(kqueue_t *queue, tick_t ticks, void **msg);
kstat_t krhino_queue_is_full(kqueue_t *queue);
kstat_t krhino_queue_flush(kqueue_t *queue);
kstat_t krhino_queue_info_get(kqueue_t *queue, msg_info_t *info);
typedef struct {
	blk_obj_t blk_obj;
	void *buf;
	k_ringbuf_t ringbuf;
	size_t max_msg_size;
	size_t cur_num;
	size_t peak_num;
	size_t min_free_buf_size;
	klist_t buf_queue_item;
	uint8_t mm_alloc_flag;
} kbuf_queue_t;
typedef struct {
	size_t buf_size;
	size_t max_msg_size;
	size_t cur_num;
	size_t peak_num;
	size_t free_buf_size;
	size_t min_free_buf_size;
} kbuf_queue_info_t;
kstat_t krhino_buf_queue_create(kbuf_queue_t *queue, const name_t *name,
		void *buf,
		size_t size, size_t max_msg);
kstat_t krhino_fix_buf_queue_create(kbuf_queue_t *queue, const name_t *name,
		void *buf, size_t msg_size, size_t msg_num);
kstat_t krhino_buf_queue_del(kbuf_queue_t *queue);
kstat_t krhino_buf_queue_dyn_create(kbuf_queue_t **queue, const name_t *name,
		size_t size, size_t max_msg);
kstat_t krhino_buf_queue_dyn_del(kbuf_queue_t *queue);
kstat_t krhino_buf_queue_send(kbuf_queue_t *queue, void *msg, size_t size);
kstat_t krhino_buf_queue_recv(kbuf_queue_t *queue, tick_t ticks, void *msg,
		size_t *size);
kstat_t krhino_buf_queue_flush(kbuf_queue_t *queue);
kstat_t krhino_buf_queue_info_get(kbuf_queue_t *queue, kbuf_queue_info_t *info);
typedef struct sem_s {
	blk_obj_t blk_obj;
	sem_count_t count;
	sem_count_t peak_count;
	klist_t sem_item;
	uint8_t mm_alloc_flag;
} ksem_t;
kstat_t krhino_sem_create(ksem_t *sem, const name_t *name, sem_count_t count);
kstat_t krhino_sem_del(ksem_t *sem);
kstat_t krhino_sem_dyn_create(ksem_t **sem, const name_t *name,
		sem_count_t count);
kstat_t krhino_sem_dyn_del(ksem_t *sem);
kstat_t krhino_sem_give(ksem_t *sem);
kstat_t krhino_sem_give_all(ksem_t *sem);
kstat_t krhino_sem_take(ksem_t *sem, tick_t ticks);
kstat_t krhino_sem_count_set(ksem_t *sem, sem_count_t count);
kstat_t krhino_sem_count_get(ksem_t *sem, sem_count_t *count);
kstat_t krhino_task_sem_create(ktask_t *task, ksem_t *sem, const name_t *name,
		size_t count);
kstat_t krhino_task_sem_del(ktask_t *task);
kstat_t krhino_task_sem_give(ktask_t *task);
kstat_t krhino_task_sem_take(tick_t ticks);
kstat_t krhino_task_sem_count_set(ktask_t *task, sem_count_t count);
kstat_t krhino_task_sem_count_get(ktask_t *task, sem_count_t *count);
typedef struct mutex_s {
	blk_obj_t blk_obj;
	ktask_t *mutex_task;
	struct mutex_s *mutex_list;
	mutex_nested_t owner_nested;
	klist_t mutex_item;
	uint8_t mm_alloc_flag;
} kmutex_t;
kstat_t krhino_mutex_create(kmutex_t *mutex, const name_t *name);
kstat_t krhino_mutex_del(kmutex_t *mutex);
kstat_t krhino_mutex_dyn_create(kmutex_t **mutex, const name_t *name);
kstat_t krhino_mutex_dyn_del(kmutex_t *mutex);
kstat_t krhino_mutex_lock(kmutex_t *mutex, tick_t ticks);
kstat_t krhino_mutex_unlock(kmutex_t *mutex);
enum {
	TIMER_CMD_CB = 0u,
	TIMER_CMD_START,
	TIMER_CMD_STOP,
	TIMER_CMD_CHG,
	TIMER_ARG_CHG,
	TIMER_ARG_CHG_AUTO,
	TIMER_CMD_DEL,
	TIMER_CMD_DYN_DEL
};
typedef void (*timer_cb_t)(void *timer, void *arg);
typedef struct {
	klist_t timer_list;
	klist_t *to_head;
	const name_t *name;
	timer_cb_t cb;
	void *timer_cb_arg;
	sys_time_t match;
	sys_time_t remain;
	sys_time_t init_count;
	sys_time_t round_ticks;
	void *priv;
	kobj_type_t obj_type;
	uint8_t timer_state;
	uint8_t mm_alloc_flag;
} ktimer_t;
typedef struct {
	ktimer_t *timer;
	uint8_t cb_num;
	sys_time_t first;
	union {
		sys_time_t round;
		void *arg;
	} u;
} k_timer_queue_cb;
typedef enum {
	TIMER_DEACTIVE = 0u,
	TIMER_ACTIVE
} k_timer_state_t;
kstat_t krhino_timer_create(ktimer_t *timer, const name_t *name, timer_cb_t cb,
		sys_time_t first, sys_time_t round, void *arg, uint8_t auto_run);
kstat_t krhino_timer_del(ktimer_t *timer);
kstat_t krhino_timer_dyn_create(ktimer_t **timer, const name_t *name,
		timer_cb_t cb,
		sys_time_t first, sys_time_t round, void *arg, uint8_t auto_run);
kstat_t krhino_timer_dyn_del(ktimer_t *timer);
kstat_t krhino_timer_start(ktimer_t *timer);
kstat_t krhino_timer_stop(ktimer_t *timer);
kstat_t krhino_timer_change(ktimer_t *timer, sys_time_t first, sys_time_t round);
kstat_t krhino_timer_arg_change_auto(ktimer_t *timer, void *arg);
kstat_t krhino_timer_arg_change(ktimer_t *timer, void *arg);
void krhino_tick_proc(void);
sys_time_t krhino_sys_time_get(void);
sys_time_t krhino_sys_tick_get(void);
tick_t krhino_ms_to_ticks(sys_time_t ms);
sys_time_t krhino_ticks_to_ms(tick_t ticks);
typedef struct {
	blk_obj_t blk_obj;
	uint32_t flags;
	klist_t event_item;
	uint8_t mm_alloc_flag;
} kevent_t;
kstat_t krhino_event_create(kevent_t *event, const name_t *name, uint32_t flags);
kstat_t krhino_event_del(kevent_t *event);
kstat_t krhino_event_dyn_create(kevent_t **event, const name_t *name,
		uint32_t flags);
kstat_t krhino_event_dyn_del(kevent_t *event);
kstat_t krhino_event_get(kevent_t *event, uint32_t flags, uint8_t opt,
		uint32_t *actl_flags, tick_t ticks);
kstat_t krhino_event_set(kevent_t *event, uint32_t flags, uint8_t opt);
void kobj_list_init(void);
void krhino_stack_ovf_check(void);
typedef struct {
	const name_t *pool_name;
	void *pool_end;
	void *pool_start;
	size_t blk_size;
	size_t blk_avail;
	size_t blk_whole;
	uint8_t *avail_list;
	kspinlock_t blk_lock;
	klist_t mblkpool_stats_item;
} mblk_pool_t;
kstat_t krhino_mblk_pool_init(mblk_pool_t *pool, const name_t *name,
		void *pool_start,
		size_t blk_size, size_t pool_size);
kstat_t krhino_mblk_alloc(mblk_pool_t *pool, void **blk);
kstat_t krhino_mblk_free(mblk_pool_t *pool, void *blk);
typedef struct {
	uint8_t *start;
	size_t len;
} k_mm_region_t;
typedef struct free_ptr_struct {
	struct k_mm_list_struct *prev;
	struct k_mm_list_struct *next;
} free_ptr_t;
typedef struct k_mm_list_struct {
	struct k_mm_list_struct *prev;
	size_t buf_size;
	union {
		struct free_ptr_struct free_ptr;
		uint8_t buffer[1];
	} mbinfo;
} k_mm_list_t;
typedef struct k_mm_region_info_struct {
	k_mm_list_t *end;
	struct k_mm_region_info_struct *next;
} k_mm_region_info_t;
typedef struct {
	kspinlock_t mm_lock;
	k_mm_region_info_t *regioninfo;
	void *fix_pool;
	size_t used_size;
	size_t maxused_size;
	size_t free_size;
	size_t alloc_times[(19 - 6 + 2)];
	uint32_t free_bitmap;
	k_mm_list_t *freelist[(19 - 6 + 2)];
} k_mm_head;
kstat_t krhino_init_mm_head(k_mm_head **ppmmhead, void *addr, size_t len );
kstat_t krhino_deinit_mm_head(k_mm_head *mmhead);
kstat_t krhino_add_mm_region(k_mm_head *mmhead, void *addr, size_t len);
void *k_mm_alloc(k_mm_head *mmhead, size_t size);
void k_mm_free(k_mm_head *mmhead, void *ptr);
void *k_mm_realloc(k_mm_head *mmhead, void *oldmem, size_t new_size);
void *krhino_mm_alloc(size_t size);
void krhino_mm_free(void *ptr);
void *krhino_mm_realloc(void *oldmem, size_t newsize);
typedef void (*work_handle_t)(void *arg);
typedef struct {
	klist_t work_node;
	work_handle_t handle;
	void *arg;
	tick_t dly;
	ktimer_t *timer;
	void *wq;
	uint8_t work_exit;
} kwork_t;
typedef struct {
	klist_t workqueue_node;
	klist_t work_list;
	kwork_t *work_current;
	const name_t *name;
	ktask_t worker;
	ksem_t sem;
} kworkqueue_t;
kstat_t krhino_workqueue_create(kworkqueue_t *workqueue, const name_t *name,
		uint8_t pri, cpu_stack_t *stack_buf, size_t stack_size);
kstat_t krhino_work_init(kwork_t *work, work_handle_t handle, void *arg,
		tick_t dly);
kstat_t krhino_work_run(kworkqueue_t *workqueue, kwork_t *work);
kstat_t krhino_work_sched(kwork_t *work);
kstat_t krhino_work_cancel(kwork_t *work);
extern kstat_t g_sys_stat;
extern uint8_t g_idle_task_spawned[1];
extern runqueue_t g_ready_queue;
extern uint8_t g_sched_lock[1];
extern uint8_t g_intrpt_nested_level[1];
extern ktask_t *g_preferred_ready_task[1];
extern ktask_t *g_active_task[1];
extern ktask_t g_idle_task[1];
extern idle_count_t g_idle_count[1];
extern cpu_stack_t g_idle_task_stack[1][200];
extern tick_t g_tick_count;
extern klist_t g_tick_head;
extern kobj_list_t g_kobj_list;
extern klist_t g_timer_head;
extern sys_time_t g_timer_count;
extern ktask_t g_timer_task;
extern cpu_stack_t g_timer_task_stack[300];
extern kbuf_queue_t g_timer_queue;
extern k_timer_queue_cb timer_queue_cb[20];
extern ksem_t g_res_sem;
extern klist_t g_res_list;
extern ktask_t g_dyn_task;
extern cpu_stack_t g_dyn_task_stack[256];
extern klist_t g_workqueue_list_head;
extern kmutex_t g_workqueue_mutex;
extern kworkqueue_t g_workqueue_default;
extern cpu_stack_t g_workqueue_stack[768];
extern k_mm_head *g_kmm_head;
typedef struct {
	size_t cnt;
	void *res[4];
	klist_t res_list;
} res_free_t;
ktask_t *preferred_cpu_ready_task_get(runqueue_t *rq, uint8_t cpu_num);
void core_sched(void);
void runqueue_init(runqueue_t *rq);
void ready_list_add(runqueue_t *rq, ktask_t *task);
void ready_list_add_head(runqueue_t *rq, ktask_t *task);
void ready_list_add_tail(runqueue_t *rq, ktask_t *task);
void ready_list_rm(runqueue_t *rq, ktask_t *task);
void ready_list_head_to_tail(runqueue_t *rq, ktask_t *task);
void time_slice_update(void);
void timer_task_sched(void);
void pend_list_reorder(ktask_t *task);
void pend_task_wakeup(ktask_t *task);
void pend_to_blk_obj(blk_obj_t *blk_obj, ktask_t *task, tick_t timeout);
void pend_task_rm(ktask_t *task);
kstat_t pend_state_end_proc(ktask_t *task);
void idle_task(void *p_arg);
void idle_count_set(idle_count_t value);
idle_count_t idle_count_get(void);
void tick_list_init(void);
void tick_task_start(void);
void tick_list_rm(ktask_t *task);
void tick_list_insert(ktask_t *task, tick_t time);
void tick_list_update(tick_i_t ticks);
uint8_t mutex_pri_limit(ktask_t *tcb, uint8_t pri);
void mutex_task_pri_reset(ktask_t *tcb);
uint8_t mutex_pri_look(ktask_t *tcb, kmutex_t *mutex_rel);
kstat_t task_pri_change(ktask_t *task, uint8_t new_pri);
void k_err_proc(kstat_t err);
void ktimer_init(void);
void intrpt_disable_measure_start(void);
void intrpt_disable_measure_stop(void);
void dyn_mem_proc_task_start(void);
void cpu_usage_stats_start(void);
kstat_t ringbuf_init(k_ringbuf_t *p_ringbuf, void *buf, size_t len, size_t type,
		size_t block_size);
kstat_t ringbuf_reset(k_ringbuf_t *p_ringbuf);
kstat_t ringbuf_push(k_ringbuf_t *p_ringbuf, void *data, size_t len);
kstat_t ringbuf_head_push(k_ringbuf_t *p_ringbuf, void *data, size_t len);
kstat_t ringbuf_pop(k_ringbuf_t *p_ringbuf, void *pdata, size_t *plen);
uint8_t ringbuf_is_full(k_ringbuf_t *p_ringbuf);
uint8_t ringbuf_is_empty(k_ringbuf_t *p_ringbuf);
void workqueue_init(void);
void k_mm_init(void);
void soc_err_proc(kstat_t err);
size_t soc_get_cur_sp(void);
size_t cpu_intrpt_save(void);
void cpu_intrpt_restore(size_t cpsr);
void cpu_intrpt_switch(void);
void cpu_task_switch(void);
void cpu_first_task_start(void);
void *cpu_task_stack_init(cpu_stack_t *base, size_t size, void *arg, task_entry_t entry);
static inline uint8_t cpu_cur_get(void)
{
	return 0;
}
typedef struct
{
	uint16_t module_id;
	uint16_t order_idx;
	uint32_t filter;
	uint32_t filter_lvls;
} nrf_log_module_dynamic_data_t;
typedef struct
{
	const char * p_module_name;
	uint8_t info_color_id;
	uint8_t debug_color_id;
	uint8_t compiled_lvl;
} nrf_log_module_const_data_t;
extern nrf_log_module_dynamic_data_t m_nrf_log_clock_logs_data_dynamic;
typedef struct
{
	uint32_t type : 2;
	uint32_t raw : 1;
	uint32_t data : 29;
} nrf_log_generic_header_t;
typedef struct
{
	uint32_t type : 2;
	uint32_t raw : 1;
	uint32_t severity : 3;
	uint32_t nargs : 4;
	uint32_t addr : 22;
} nrf_log_std_header_t;
typedef struct
{
	uint32_t type : 2;
	uint32_t raw : 1;
	uint32_t severity : 3;
	uint32_t offset : 10;
	uint32_t reserved : 6;
	uint32_t len : 10;
} nrf_log_hexdump_header_t;
typedef struct
{
	uint32_t type : 2;
	uint32_t reserved0 : 4;
	uint32_t offset : 10;
	uint32_t reserved1 : 6;
	uint32_t len : 10;
} nrf_log_pushed_header_t;
typedef struct
{
	union {
		nrf_log_generic_header_t generic;
		nrf_log_std_header_t std;
		nrf_log_hexdump_header_t hexdump;
		nrf_log_pushed_header_t pushed;
		uint32_t raw;
	} base;
	uint32_t module_id;
	uint32_t timestamp;
} nrf_log_header_t;
_Static_assert((sizeof(nrf_log_pushed_header_t)/sizeof(uint32_t)) == 1, "unspecified message");
void nrf_log_frontend_std_0(uint32_t severity_mid, char const * const p_str);
void nrf_log_frontend_std_1(uint32_t severity_mid,
		char const * const p_str,
		uint32_t val0);
void nrf_log_frontend_std_2(uint32_t severity_mid,
		char const * const p_str,
		uint32_t val0,
		uint32_t val1);
void nrf_log_frontend_std_3(uint32_t severity_mid,
		char const * const p_str,
		uint32_t val0,
		uint32_t val1,
		uint32_t val2);
void nrf_log_frontend_std_4(uint32_t severity_mid,
		char const * const p_str,
		uint32_t val0,
		uint32_t val1,
		uint32_t val2,
		uint32_t val3);
void nrf_log_frontend_std_5(uint32_t severity_mid,
		char const * const p_str,
		uint32_t val0,
		uint32_t val1,
		uint32_t val2,
		uint32_t val3,
		uint32_t val4);
void nrf_log_frontend_std_6(uint32_t severity_mid,
		char const * const p_str,
		uint32_t val0,
		uint32_t val1,
		uint32_t val2,
		uint32_t val3,
		uint32_t val4,
		uint32_t val5);
void nrf_log_frontend_hexdump(uint32_t severity_mid,
		const void * const p_data,
		uint16_t length);
uint8_t nrf_log_getchar(void);
uint32_t nrf_log_push(char * const p_str);
;
_Static_assert((((7)) < 8), "unspecified message");
typedef enum
{
	CAL_STATE_IDLE,
	CAL_STATE_CT,
	CAL_STATE_HFCLK_REQ,
	CAL_STATE_CAL,
	CAL_STATE_ABORT,
} nrf_drv_clock_cal_state_t;
typedef struct
{
	_Bool 
		module_initialized;
	volatile 
		_Bool 
		hfclk_on;
	volatile 
		_Bool 
		lfclk_on;
	volatile uint32_t hfclk_requests;
	volatile nrf_drv_clock_handler_item_t * p_hf_head;
	volatile uint32_t lfclk_requests;
	volatile nrf_drv_clock_handler_item_t * p_lf_head;
} nrf_drv_clock_cb_t;
static nrf_drv_clock_cb_t m_clock_cb;
static void lfclk_start(void)
{
	nrf_clock_event_clear(NRF_CLOCK_EVENT_LFCLKSTARTED);
	nrf_clock_int_enable(NRF_CLOCK_INT_LF_STARTED_MASK);
	nrf_clock_task_trigger(NRF_CLOCK_TASK_LFCLKSTART);
}
static void lfclk_stop(void)
{
	nrf_clock_task_trigger(NRF_CLOCK_TASK_LFCLKSTOP);
	while (nrf_clock_lf_is_running())
	{}
	m_clock_cb.lfclk_on = 
		0
		;
}
static void hfclk_start(void)
{
	nrf_clock_event_clear(NRF_CLOCK_EVENT_HFCLKSTARTED);
	nrf_clock_int_enable(NRF_CLOCK_INT_HF_STARTED_MASK);
	nrf_clock_task_trigger(NRF_CLOCK_TASK_HFCLKSTART);
}
static void hfclk_stop(void)
{
	nrf_clock_task_trigger(NRF_CLOCK_TASK_HFCLKSTOP);
	while (nrf_clock_hf_is_running(NRF_CLOCK_HFCLK_HIGH_ACCURACY))
	{}
	m_clock_cb.hfclk_on = 
		0
		;
}
	_Bool 
nrf_drv_clock_init_check(void)
{
	return m_clock_cb.module_initialized;
}
ret_code_t nrf_drv_clock_init(void)
{
	ret_code_t err_code = ((0x0) + 0);
	if (m_clock_cb.module_initialized)
	{
		err_code = (((0x0) + 0x0080) + 0x0005);
	}
	else
	{
		m_clock_cb.p_hf_head = 
			((void *)0)
			;
		m_clock_cb.hfclk_requests = 0;
		m_clock_cb.p_lf_head = 
			((void *)0)
			;
		m_clock_cb.lfclk_requests = 0;
		nrf_drv_common_power_clock_irq_init();
		{
			nrf_clock_lf_src_set((nrf_clock_lfclk_t)1);
		}
		m_clock_cb.module_initialized = 
			1
			;
	}
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("Function: %s, error code: %s."); (void)((uint32_t)__func__); (void)((uint32_t)""); } }
	;
	return err_code;
}
void nrf_drv_clock_uninit(void)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)215, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	nrf_drv_common_clock_irq_disable();
	nrf_clock_int_disable(0xFFFFFFFF);
	lfclk_stop();
	hfclk_stop();
	m_clock_cb.module_initialized = 
		0
		;
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("Uninitialized."); } };
}
static void item_enqueue(nrf_drv_clock_handler_item_t ** p_head,
		nrf_drv_clock_handler_item_t * p_item)
{
	nrf_drv_clock_handler_item_t * p_next = *p_head;
	while (p_next)
	{
		if (p_next == p_item)
		{
			return;
		}
		p_next = p_next->p_next;
	}
	p_item->p_next = (*p_head ? *p_head : 
			((void *)0)
			);
	*p_head = p_item;
}
static nrf_drv_clock_handler_item_t * item_dequeue(nrf_drv_clock_handler_item_t ** p_head)
{
	nrf_drv_clock_handler_item_t * p_item = *p_head;
	if (p_item)
	{
		*p_head = p_item->p_next;
	}
	return p_item;
}
void nrf_drv_clock_lfclk_request(nrf_drv_clock_handler_item_t * p_handler_item)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)254, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	if (m_clock_cb.lfclk_on)
	{
		if (p_handler_item)
		{
			p_handler_item->event_handler(NRF_DRV_CLOCK_EVT_LFCLK_STARTED);
		}
		app_util_critical_region_enter(
				((void *)0)
				);
		++(m_clock_cb.lfclk_requests);
		app_util_critical_region_exit(0);
	}
	else
	{
		app_util_critical_region_enter(
				((void *)0)
				);
		if (p_handler_item)
		{
			item_enqueue((nrf_drv_clock_handler_item_t **)&m_clock_cb.p_lf_head,
					p_handler_item);
		}
		if (m_clock_cb.lfclk_requests == 0)
		{
			lfclk_start();
		}
		++(m_clock_cb.lfclk_requests);
		app_util_critical_region_exit(0);
	}
	if (0) { if (m_clock_cb.lfclk_requests > 0) { } else { assert_nrf_callback((uint16_t)282, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
}
void nrf_drv_clock_lfclk_release(void)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)287, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	if (0) { if (m_clock_cb.lfclk_requests > 0) { } else { assert_nrf_callback((uint16_t)288, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	app_util_critical_region_enter(
			((void *)0)
			);
	--(m_clock_cb.lfclk_requests);
	if (m_clock_cb.lfclk_requests == 0)
	{
		lfclk_stop();
	}
	app_util_critical_region_exit(0);
}
	_Bool 
nrf_drv_clock_lfclk_is_running(void)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)301, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	return nrf_clock_lf_is_running();
}
void nrf_drv_clock_hfclk_request(nrf_drv_clock_handler_item_t * p_handler_item)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)315, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	if (m_clock_cb.hfclk_on)
	{
		if (p_handler_item)
		{
			p_handler_item->event_handler(NRF_DRV_CLOCK_EVT_HFCLK_STARTED);
		}
		app_util_critical_region_enter(
				((void *)0)
				);
		++(m_clock_cb.hfclk_requests);
		app_util_critical_region_exit(0);
	}
	else
	{
		app_util_critical_region_enter(
				((void *)0)
				);
		if (p_handler_item)
		{
			item_enqueue((nrf_drv_clock_handler_item_t **)&m_clock_cb.p_hf_head,
					p_handler_item);
		}
		if (m_clock_cb.hfclk_requests == 0)
		{
			hfclk_start();
		}
		++(m_clock_cb.hfclk_requests);
		app_util_critical_region_exit(0);
	}
	if (0) { if (m_clock_cb.hfclk_requests > 0) { } else { assert_nrf_callback((uint16_t)343, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
}
void nrf_drv_clock_hfclk_release(void)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)348, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	if (0) { if (m_clock_cb.hfclk_requests > 0) { } else { assert_nrf_callback((uint16_t)349, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	app_util_critical_region_enter(
			((void *)0)
			);
	--(m_clock_cb.hfclk_requests);
	if (m_clock_cb.hfclk_requests == 0)
	{
		hfclk_stop();
	}
	app_util_critical_region_exit(0);
}
	_Bool 
nrf_drv_clock_hfclk_is_running(void)
{
	if (0) { if (m_clock_cb.module_initialized) { } else { assert_nrf_callback((uint16_t)362, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/clock/nrf_drv_clock.c"); } };
	return nrf_clock_hf_is_running(NRF_CLOCK_HFCLK_HIGH_ACCURACY);
}
ret_code_t nrf_drv_clock_calibration_start(uint8_t interval, nrf_drv_clock_event_handler_t handler)
{
	ret_code_t err_code = ((0x0) + 0);
	err_code = ((0x0) + 15);
	if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("Function: %s, error code: %s."); (void)((uint32_t)__func__); (void)((uint32_t)""); } };
	return err_code;
}
ret_code_t nrf_drv_clock_calibration_abort(void)
{
	ret_code_t err_code = ((0x0) + 0);
	err_code = ((0x0) + 15);
	if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("Function: %s, error code: %s."); (void)((uint32_t)__func__); (void)((uint32_t)""); } };
	return err_code;
}
ret_code_t nrf_drv_clock_is_calibrating(
		_Bool 
		* p_is_calibrating)
{
	ret_code_t err_code = ((0x0) + 0);
	err_code = ((0x0) + 15);
	if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("Function: %s, error code: %s."); (void)((uint32_t)__func__); (void)((uint32_t)""); } };
	return err_code;
}
static inline void clock_clk_started_notify(nrf_drv_clock_evt_type_t evt_type)
{
	nrf_drv_clock_handler_item_t **p_head;
	if (evt_type == NRF_DRV_CLOCK_EVT_HFCLK_STARTED)
	{
		p_head = (nrf_drv_clock_handler_item_t **)&m_clock_cb.p_hf_head;
	}
	else
	{
		p_head = (nrf_drv_clock_handler_item_t **)&m_clock_cb.p_lf_head;
	}
	while (1)
	{
		nrf_drv_clock_handler_item_t * p_item = item_dequeue(p_head);
		if (!p_item)
		{
			break;
		}
		p_item->event_handler(evt_type);
	}
}
void POWER_CLOCK_IRQHandler(void)
{
	krhino_intrpt_enter();
	if (nrf_clock_event_check(NRF_CLOCK_EVENT_HFCLKSTARTED))
	{
		nrf_clock_event_clear(NRF_CLOCK_EVENT_HFCLKSTARTED);
		if (0 && (0 >= 4UL) && (4UL <= 3)) { if (4UL >= 4UL) { (void)(((4UL) | 0 << 16)); (void)("Event: %s."); (void)((uint32_t)""); } };
		nrf_clock_int_disable(NRF_CLOCK_INT_HF_STARTED_MASK);
		m_clock_cb.hfclk_on = 
			1
			;
		clock_clk_started_notify(NRF_DRV_CLOCK_EVT_HFCLK_STARTED);
	}
	if (nrf_clock_event_check(NRF_CLOCK_EVENT_LFCLKSTARTED))
	{
		nrf_clock_event_clear(NRF_CLOCK_EVENT_LFCLKSTARTED);
		if (0 && (0 >= 4UL) && (4UL <= 3)) { if (4UL >= 4UL) { (void)(((4UL) | 0 << 16)); (void)("Event: %s."); (void)((uint32_t)""); } };
		nrf_clock_int_disable(NRF_CLOCK_INT_LF_STARTED_MASK);
		m_clock_cb.lfclk_on = 
			1
			;
		clock_clk_started_notify(NRF_DRV_CLOCK_EVT_LFCLK_STARTED);
	}
	krhino_intrpt_exit();
}
