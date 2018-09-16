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
typedef enum
{
	NRF_UART_TASK_STARTRX = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				TASKS_STARTRX
				)
		,
	NRF_UART_TASK_STOPRX = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				TASKS_STOPRX
				)
		,
	NRF_UART_TASK_STARTTX = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				TASKS_STARTTX
				)
		,
	NRF_UART_TASK_STOPTX = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				TASKS_STOPTX
				)
		,
	NRF_UART_TASK_SUSPEND = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				TASKS_SUSPEND
				)
		,
} nrf_uart_task_t;
typedef enum
{
	NRF_UART_EVENT_CTS = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				EVENTS_CTS
				)
		,
	NRF_UART_EVENT_NCTS = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				EVENTS_NCTS
				)
		,
	NRF_UART_EVENT_RXDRDY = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				EVENTS_RXDRDY
				)
		,
	NRF_UART_EVENT_TXDRDY = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				EVENTS_TXDRDY
				)
		,
	NRF_UART_EVENT_ERROR = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				EVENTS_ERROR
				)
		,
	NRF_UART_EVENT_RXTO = 
		__builtin_offsetof (
				NRF_UART_Type
				, 
				EVENTS_RXTO
				)
} nrf_uart_event_t;
typedef enum
{
	NRF_UART_INT_MASK_CTS = (0x1UL << (0UL)),
	NRF_UART_INT_MASK_NCTS = (0x1UL << (1UL)),
	NRF_UART_INT_MASK_RXDRDY = (0x1UL << (2UL)),
	NRF_UART_INT_MASK_TXDRDY = (0x1UL << (7UL)),
	NRF_UART_INT_MASK_ERROR = (0x1UL << (9UL)),
	NRF_UART_INT_MASK_RXTO = (0x1UL << (17UL))
} nrf_uart_int_mask_t;
typedef enum
{
	NRF_UART_BAUDRATE_1200 = (0x0004F000UL),
	NRF_UART_BAUDRATE_2400 = (0x0009D000UL),
	NRF_UART_BAUDRATE_4800 = (0x0013B000UL),
	NRF_UART_BAUDRATE_9600 = (0x00275000UL),
	NRF_UART_BAUDRATE_14400 = (0x003AF000UL),
	NRF_UART_BAUDRATE_19200 = (0x004EA000UL),
	NRF_UART_BAUDRATE_28800 = (0x0075C000UL),
	NRF_UART_BAUDRATE_38400 = (0x009D0000UL),
	NRF_UART_BAUDRATE_57600 = (0x00EB0000UL),
	NRF_UART_BAUDRATE_76800 = (0x013A9000UL),
	NRF_UART_BAUDRATE_115200 = (0x01D60000UL),
	NRF_UART_BAUDRATE_230400 = (0x03B00000UL),
	NRF_UART_BAUDRATE_250000 = (0x04000000UL),
	NRF_UART_BAUDRATE_460800 = (0x07400000UL),
	NRF_UART_BAUDRATE_921600 = (0x0F000000UL),
	NRF_UART_BAUDRATE_1000000 = (0x10000000UL),
} nrf_uart_baudrate_t;
typedef enum
{
	NRF_UART_ERROR_OVERRUN_MASK = (0x1UL << (0UL)),
	NRF_UART_ERROR_PARITY_MASK = (0x1UL << (1UL)),
	NRF_UART_ERROR_FRAMING_MASK = (0x1UL << (2UL)),
	NRF_UART_ERROR_BREAK_MASK = (0x1UL << (3UL)),
} nrf_uart_error_mask_t;
typedef enum
{
	NRF_UART_PARITY_EXCLUDED = (0x0UL) << (1UL),
	NRF_UART_PARITY_INCLUDED = (0x7UL) << (1UL),
} nrf_uart_parity_t;
typedef enum
{
	NRF_UART_HWFC_DISABLED = (0UL),
	NRF_UART_HWFC_ENABLED = (1UL),
} nrf_uart_hwfc_t;
static inline void nrf_uart_event_clear(NRF_UART_Type * p_reg, nrf_uart_event_t event);
static inline 
_Bool 
nrf_uart_event_check(NRF_UART_Type * p_reg, nrf_uart_event_t event);
static inline uint32_t nrf_uart_event_address_get(NRF_UART_Type * p_reg,
		nrf_uart_event_t event);
static inline void nrf_uart_int_enable(NRF_UART_Type * p_reg, uint32_t int_mask);
static inline 
_Bool 
nrf_uart_int_enable_check(NRF_UART_Type * p_reg, uint32_t int_mask);
static inline void nrf_uart_int_disable(NRF_UART_Type * p_reg, uint32_t int_mask);
static inline uint32_t nrf_uart_errorsrc_get_and_clear(NRF_UART_Type * p_reg);
static inline void nrf_uart_enable(NRF_UART_Type * p_reg);
static inline void nrf_uart_disable(NRF_UART_Type * p_reg);
static inline void nrf_uart_txrx_pins_set(NRF_UART_Type * p_reg, uint32_t pseltxd, uint32_t pselrxd);
static inline void nrf_uart_txrx_pins_disconnect(NRF_UART_Type * p_reg);
static inline uint32_t nrf_uart_tx_pin_get(NRF_UART_Type * p_reg);
static inline uint32_t nrf_uart_rx_pin_get(NRF_UART_Type * p_reg);
static inline uint32_t nrf_uart_rts_pin_get(NRF_UART_Type * p_reg);
static inline uint32_t nrf_uart_cts_pin_get(NRF_UART_Type * p_reg);
static inline void nrf_uart_hwfc_pins_set(NRF_UART_Type * p_reg,
		uint32_t pselrts,
		uint32_t pselcts);
static inline void nrf_uart_hwfc_pins_disconnect(NRF_UART_Type * p_reg);
static inline uint8_t nrf_uart_rxd_get(NRF_UART_Type * p_reg);
static inline void nrf_uart_txd_set(NRF_UART_Type * p_reg, uint8_t txd);
static inline void nrf_uart_task_trigger(NRF_UART_Type * p_reg, nrf_uart_task_t task);
static inline uint32_t nrf_uart_task_address_get(NRF_UART_Type * p_reg, nrf_uart_task_t task);
static inline void nrf_uart_configure(NRF_UART_Type * p_reg,
		nrf_uart_parity_t parity,
		nrf_uart_hwfc_t hwfc);
static inline void nrf_uart_baudrate_set(NRF_UART_Type * p_reg, nrf_uart_baudrate_t baudrate);
static inline void nrf_uart_event_clear(NRF_UART_Type * p_reg, nrf_uart_event_t event)
{
	*((volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)event)) = 0x0UL;
	volatile uint32_t dummy = *((volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)event));
	(void)dummy;
}
static inline 
	_Bool 
nrf_uart_event_check(NRF_UART_Type * p_reg, nrf_uart_event_t event)
{
	return (
			_Bool
	       )*(volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)event);
}
static inline uint32_t nrf_uart_event_address_get(NRF_UART_Type * p_reg,
		nrf_uart_event_t event)
{
	return (uint32_t)((uint8_t *)p_reg + (uint32_t)event);
}
static inline void nrf_uart_int_enable(NRF_UART_Type * p_reg, uint32_t int_mask)
{
	p_reg->INTENSET = int_mask;
}
static inline 
	_Bool 
nrf_uart_int_enable_check(NRF_UART_Type * p_reg, uint32_t int_mask)
{
	return (
			_Bool
	       )(p_reg->INTENSET & int_mask);
}
static inline void nrf_uart_int_disable(NRF_UART_Type * p_reg, uint32_t int_mask)
{
	p_reg->INTENCLR = int_mask;
}
static inline uint32_t nrf_uart_errorsrc_get_and_clear(NRF_UART_Type * p_reg)
{
	uint32_t errsrc_mask = p_reg->ERRORSRC;
	p_reg->ERRORSRC = errsrc_mask;
	return errsrc_mask;
}
static inline void nrf_uart_enable(NRF_UART_Type * p_reg)
{
	p_reg->ENABLE = (4UL);
}
static inline void nrf_uart_disable(NRF_UART_Type * p_reg)
{
	p_reg->ENABLE = (0UL);
}
static inline void nrf_uart_txrx_pins_set(NRF_UART_Type * p_reg, uint32_t pseltxd, uint32_t pselrxd)
{
	p_reg->PSEL.RXD = pselrxd;
	p_reg->PSEL.TXD = pseltxd;
}
static inline void nrf_uart_txrx_pins_disconnect(NRF_UART_Type * p_reg)
{
	nrf_uart_txrx_pins_set(p_reg, 0xFFFFFFFF, 0xFFFFFFFF);
}
static inline uint32_t nrf_uart_tx_pin_get(NRF_UART_Type * p_reg)
{
	return p_reg->PSEL.TXD;
}
static inline uint32_t nrf_uart_rx_pin_get(NRF_UART_Type * p_reg)
{
	return p_reg->PSEL.RXD;
}
static inline uint32_t nrf_uart_rts_pin_get(NRF_UART_Type * p_reg)
{
	return p_reg->PSEL.RTS;
}
static inline uint32_t nrf_uart_cts_pin_get(NRF_UART_Type * p_reg)
{
	return p_reg->PSEL.CTS;
}
static inline void nrf_uart_hwfc_pins_set(NRF_UART_Type * p_reg, uint32_t pselrts, uint32_t pselcts)
{
	p_reg->PSEL.RTS = pselrts;
	p_reg->PSEL.CTS = pselcts;
}
static inline void nrf_uart_hwfc_pins_disconnect(NRF_UART_Type * p_reg)
{
	nrf_uart_hwfc_pins_set(p_reg, 0xFFFFFFFF, 0xFFFFFFFF);
}
static inline uint8_t nrf_uart_rxd_get(NRF_UART_Type * p_reg)
{
	return p_reg->RXD;
}
static inline void nrf_uart_txd_set(NRF_UART_Type * p_reg, uint8_t txd)
{
	p_reg->TXD = txd;
}
static inline void nrf_uart_task_trigger(NRF_UART_Type * p_reg, nrf_uart_task_t task)
{
	*((volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)task)) = 0x1UL;
}
static inline uint32_t nrf_uart_task_address_get(NRF_UART_Type * p_reg, nrf_uart_task_t task)
{
	return (uint32_t)p_reg + (uint32_t)task;
}
static inline void nrf_uart_configure(NRF_UART_Type * p_reg,
		nrf_uart_parity_t parity,
		nrf_uart_hwfc_t hwfc)
{
	p_reg->CONFIG = (uint32_t)parity | (uint32_t)hwfc;
}
static inline void nrf_uart_baudrate_set(NRF_UART_Type * p_reg, nrf_uart_baudrate_t baudrate)
{
	p_reg->BAUDRATE = baudrate;
}
typedef enum
{
	NRF_UARTE_TASK_STARTRX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				TASKS_STARTRX
				)
		,
	NRF_UARTE_TASK_STOPRX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				TASKS_STOPRX
				)
		,
	NRF_UARTE_TASK_STARTTX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				TASKS_STARTTX
				)
		,
	NRF_UARTE_TASK_STOPTX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				TASKS_STOPTX
				)
		,
	NRF_UARTE_TASK_FLUSHRX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				TASKS_FLUSHRX
				)
} nrf_uarte_task_t;
typedef enum
{
	NRF_UARTE_EVENT_CTS = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_CTS
				)
		,
	NRF_UARTE_EVENT_NCTS = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_NCTS
				)
		,
	NRF_UARTE_EVENT_ENDRX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_ENDRX
				)
		,
	NRF_UARTE_EVENT_ENDTX = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_ENDTX
				)
		,
	NRF_UARTE_EVENT_ERROR = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_ERROR
				)
		,
	NRF_UARTE_EVENT_RXTO = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_RXTO
				)
		,
	NRF_UARTE_EVENT_RXSTARTED = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_RXSTARTED
				)
		,
	NRF_UARTE_EVENT_TXSTARTED = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_TXSTARTED
				)
		,
	NRF_UARTE_EVENT_TXSTOPPED = 
		__builtin_offsetof (
				NRF_UARTE_Type
				, 
				EVENTS_TXSTOPPED
				)
} nrf_uarte_event_t;
typedef enum
{
	NRF_UARTE_SHORT_ENDRX_STARTRX = (0x1UL << (5UL)),
	NRF_UARTE_SHORT_ENDRX_STOPRX = (0x1UL << (6UL)),
} nrf_uarte_short_t;
typedef enum
{
	NRF_UARTE_INT_CTS_MASK = (0x1UL << (0UL)),
	NRF_UARTE_INT_NCTSRX_MASK = (0x1UL << (1UL)),
	NRF_UARTE_INT_ENDRX_MASK = (0x1UL << (4UL)),
	NRF_UARTE_INT_ENDTX_MASK = (0x1UL << (8UL)),
	NRF_UARTE_INT_ERROR_MASK = (0x1UL << (9UL)),
	NRF_UARTE_INT_RXTO_MASK = (0x1UL << (17UL)),
	NRF_UARTE_INT_RXSTARTED_MASK = (0x1UL << (19UL)),
	NRF_UARTE_INT_TXSTARTED_MASK = (0x1UL << (20UL)),
	NRF_UARTE_INT_TXSTOPPED_MASK = (0x1UL << (22UL))
} nrf_uarte_int_mask_t;
typedef enum
{
	NRF_UARTE_BAUDRATE_1200 = (0x0004F000UL),
	NRF_UARTE_BAUDRATE_2400 = (0x0009D000UL),
	NRF_UARTE_BAUDRATE_4800 = (0x0013B000UL),
	NRF_UARTE_BAUDRATE_9600 = (0x00275000UL),
	NRF_UARTE_BAUDRATE_14400 = (0x003AF000UL),
	NRF_UARTE_BAUDRATE_19200 = (0x004EA000UL),
	NRF_UARTE_BAUDRATE_28800 = (0x0075C000UL),
	NRF_UARTE_BAUDRATE_38400 = (0x009D0000UL),
	NRF_UARTE_BAUDRATE_57600 = (0x00EB0000UL),
	NRF_UARTE_BAUDRATE_76800 = (0x013A9000UL),
	NRF_UARTE_BAUDRATE_115200 = (0x01D60000UL),
	NRF_UARTE_BAUDRATE_230400 = (0x03B00000UL),
	NRF_UARTE_BAUDRATE_250000 = (0x04000000UL),
	NRF_UARTE_BAUDRATE_460800 = (0x07400000UL),
	NRF_UARTE_BAUDRATE_921600 = (0x0F000000UL),
	NRF_UARTE_BAUDRATE_1000000 = (0x10000000UL),
} nrf_uarte_baudrate_t;
typedef enum
{
	NRF_UARTE_ERROR_OVERRUN_MASK = (0x1UL << (0UL)),
	NRF_UARTE_ERROR_PARITY_MASK = (0x1UL << (1UL)),
	NRF_UARTE_ERROR_FRAMING_MASK = (0x1UL << (2UL)),
	NRF_UARTE_ERROR_BREAK_MASK = (0x1UL << (3UL)),
} nrf_uarte_error_mask_t;
typedef enum
{
	NRF_UARTE_PARITY_EXCLUDED = (0x0UL) << (1UL),
	NRF_UARTE_PARITY_INCLUDED = (0x7UL) << (1UL),
} nrf_uarte_parity_t;
typedef enum
{
	NRF_UARTE_HWFC_DISABLED = (0UL) << (0UL),
	NRF_UARTE_HWFC_ENABLED = (1UL) << (0UL),
} nrf_uarte_hwfc_t;
static inline void nrf_uarte_event_clear(NRF_UARTE_Type * p_reg, nrf_uarte_event_t event);
static inline 
_Bool 
nrf_uarte_event_check(NRF_UARTE_Type * p_reg, nrf_uarte_event_t event);
static inline uint32_t nrf_uarte_event_address_get(NRF_UARTE_Type * p_reg,
		nrf_uarte_event_t event);
static inline void nrf_uarte_shorts_enable(NRF_UARTE_Type * p_reg, uint32_t shorts_mask);
static inline void nrf_uarte_shorts_disable(NRF_UARTE_Type * p_reg, uint32_t shorts_mask);
static inline void nrf_uarte_int_enable(NRF_UARTE_Type * p_reg, uint32_t int_mask);
static inline 
_Bool 
nrf_uarte_int_enable_check(NRF_UARTE_Type * p_reg, nrf_uarte_int_mask_t int_mask);
static inline void nrf_uarte_int_disable(NRF_UARTE_Type * p_reg, uint32_t int_mask);
static inline uint32_t nrf_uarte_errorsrc_get_and_clear(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_enable(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_disable(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_txrx_pins_set(NRF_UARTE_Type * p_reg, uint32_t pseltxd, uint32_t pselrxd);
static inline void nrf_uarte_txrx_pins_disconnect(NRF_UARTE_Type * p_reg);
static inline uint32_t nrf_uarte_tx_pin_get(NRF_UARTE_Type * p_reg);
static inline uint32_t nrf_uarte_rx_pin_get(NRF_UARTE_Type * p_reg);
static inline uint32_t nrf_uarte_rts_pin_get(NRF_UARTE_Type * p_reg);
static inline uint32_t nrf_uarte_cts_pin_get(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_hwfc_pins_set(NRF_UARTE_Type * p_reg,
		uint32_t pselrts,
		uint32_t pselcts);
static inline void nrf_uarte_hwfc_pins_disconnect(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_task_trigger(NRF_UARTE_Type * p_reg, nrf_uarte_task_t task);
static inline uint32_t nrf_uarte_task_address_get(NRF_UARTE_Type * p_reg, nrf_uarte_task_t task);
static inline void nrf_uarte_configure(NRF_UARTE_Type * p_reg,
		nrf_uarte_parity_t parity,
		nrf_uarte_hwfc_t hwfc);
static inline void nrf_uarte_baudrate_set(NRF_UARTE_Type * p_reg, nrf_uarte_baudrate_t baudrate);
static inline void nrf_uarte_tx_buffer_set(NRF_UARTE_Type * p_reg,
		uint8_t const * p_buffer,
		uint8_t length);
static inline uint32_t nrf_uarte_tx_amount_get(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_rx_buffer_set(NRF_UARTE_Type * p_reg,
		uint8_t * p_buffer,
		uint8_t length);
static inline uint32_t nrf_uarte_rx_amount_get(NRF_UARTE_Type * p_reg);
static inline void nrf_uarte_event_clear(NRF_UARTE_Type * p_reg, nrf_uarte_event_t event)
{
	*((volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)event)) = 0x0UL;
	volatile uint32_t dummy = *((volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)event));
	(void)dummy;
}
static inline 
	_Bool 
nrf_uarte_event_check(NRF_UARTE_Type * p_reg, nrf_uarte_event_t event)
{
	return (
			_Bool
	       )*(volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)event);
}
static inline uint32_t nrf_uarte_event_address_get(NRF_UARTE_Type * p_reg,
		nrf_uarte_event_t event)
{
	return (uint32_t)((uint8_t *)p_reg + (uint32_t)event);
}
static inline void nrf_uarte_shorts_enable(NRF_UARTE_Type * p_reg, uint32_t shorts_mask)
{
	p_reg->SHORTS |= shorts_mask;
}
static inline void nrf_uarte_shorts_disable(NRF_UARTE_Type * p_reg, uint32_t shorts_mask)
{
	p_reg->SHORTS &= ~(shorts_mask);
}
static inline void nrf_uarte_int_enable(NRF_UARTE_Type * p_reg, uint32_t int_mask)
{
	p_reg->INTENSET = int_mask;
}
static inline 
	_Bool 
nrf_uarte_int_enable_check(NRF_UARTE_Type * p_reg, nrf_uarte_int_mask_t int_mask)
{
	return (
			_Bool
	       )(p_reg->INTENSET & int_mask);
}
static inline void nrf_uarte_int_disable(NRF_UARTE_Type * p_reg, uint32_t int_mask)
{
	p_reg->INTENCLR = int_mask;
}
static inline uint32_t nrf_uarte_errorsrc_get_and_clear(NRF_UARTE_Type * p_reg)
{
	uint32_t errsrc_mask = p_reg->ERRORSRC;
	p_reg->ERRORSRC = errsrc_mask;
	return errsrc_mask;
}
static inline void nrf_uarte_enable(NRF_UARTE_Type * p_reg)
{
	p_reg->ENABLE = (8UL);
}
static inline void nrf_uarte_disable(NRF_UARTE_Type * p_reg)
{
	p_reg->ENABLE = (0UL);
}
static inline void nrf_uarte_txrx_pins_set(NRF_UARTE_Type * p_reg, uint32_t pseltxd, uint32_t pselrxd)
{
	p_reg->PSEL.TXD = pseltxd;
	p_reg->PSEL.RXD = pselrxd;
}
static inline void nrf_uarte_txrx_pins_disconnect(NRF_UARTE_Type * p_reg)
{
	nrf_uarte_txrx_pins_set(p_reg, 0xFFFFFFFF, 0xFFFFFFFF);
}
static inline uint32_t nrf_uarte_tx_pin_get(NRF_UARTE_Type * p_reg)
{
	return p_reg->PSEL.TXD;
}
static inline uint32_t nrf_uarte_rx_pin_get(NRF_UARTE_Type * p_reg)
{
	return p_reg->PSEL.RXD;
}
static inline uint32_t nrf_uarte_rts_pin_get(NRF_UARTE_Type * p_reg)
{
	return p_reg->PSEL.RTS;
}
static inline uint32_t nrf_uarte_cts_pin_get(NRF_UARTE_Type * p_reg)
{
	return p_reg->PSEL.CTS;
}
static inline void nrf_uarte_hwfc_pins_set(NRF_UARTE_Type * p_reg, uint32_t pselrts, uint32_t pselcts)
{
	p_reg->PSEL.RTS = pselrts;
	p_reg->PSEL.CTS = pselcts;
}
static inline void nrf_uarte_hwfc_pins_disconnect(NRF_UARTE_Type * p_reg)
{
	nrf_uarte_hwfc_pins_set(p_reg, 0xFFFFFFFF, 0xFFFFFFFF);
}
static inline void nrf_uarte_task_trigger(NRF_UARTE_Type * p_reg, nrf_uarte_task_t task)
{
	*((volatile uint32_t *)((uint8_t *)p_reg + (uint32_t)task)) = 0x1UL;
}
static inline uint32_t nrf_uarte_task_address_get(NRF_UARTE_Type * p_reg, nrf_uarte_task_t task)
{
	return (uint32_t)p_reg + (uint32_t)task;
}
static inline void nrf_uarte_configure(NRF_UARTE_Type * p_reg,
		nrf_uarte_parity_t parity,
		nrf_uarte_hwfc_t hwfc)
{
	p_reg->CONFIG = (uint32_t)parity | (uint32_t)hwfc;
}
static inline void nrf_uarte_baudrate_set(NRF_UARTE_Type * p_reg, nrf_uarte_baudrate_t baudrate)
{
	p_reg->BAUDRATE = baudrate;
}
static inline void nrf_uarte_tx_buffer_set(NRF_UARTE_Type * p_reg,
		uint8_t const * p_buffer,
		uint8_t length)
{
	p_reg->TXD.PTR = (uint32_t)p_buffer;
	p_reg->TXD.MAXCNT = length;
}
static inline uint32_t nrf_uarte_tx_amount_get(NRF_UARTE_Type * p_reg)
{
	return p_reg->TXD.AMOUNT;
}
static inline void nrf_uarte_rx_buffer_set(NRF_UARTE_Type * p_reg,
		uint8_t * p_buffer,
		uint8_t length)
{
	p_reg->RXD.PTR = (uint32_t)p_buffer;
	p_reg->RXD.MAXCNT = length;
}
static inline uint32_t nrf_uarte_rx_amount_get(NRF_UARTE_Type * p_reg)
{
	return p_reg->RXD.AMOUNT;
}
typedef struct
{
	union
	{
		NRF_UARTE_Type * p_uarte;
		NRF_UART_Type * p_uart;
		void * p_reg;
	} reg;
	uint8_t drv_inst_idx;
} nrf_drv_uart_t;
typedef enum
{
	NRF_DRV_UART_EVT_TX_DONE,
	NRF_DRV_UART_EVT_RX_DONE,
	NRF_DRV_UART_EVT_ERROR,
} nrf_drv_uart_evt_type_t;
typedef struct
{
	uint32_t pseltxd;
	uint32_t pselrxd;
	uint32_t pselcts;
	uint32_t pselrts;
	void * p_context;
	nrf_uart_hwfc_t hwfc;
	nrf_uart_parity_t parity;
	nrf_uart_baudrate_t baudrate;
	uint8_t interrupt_priority;
	_Bool 
		use_easy_dma;
} nrf_drv_uart_config_t;
typedef struct
{
	uint8_t * p_data;
	uint8_t bytes;
} nrf_drv_uart_xfer_evt_t;
typedef struct
{
	nrf_drv_uart_xfer_evt_t rxtx;
	uint32_t error_mask;
} nrf_drv_uart_error_evt_t;
typedef struct
{
	nrf_drv_uart_evt_type_t type;
	union
	{
		nrf_drv_uart_xfer_evt_t rxtx;
		nrf_drv_uart_error_evt_t error;
	} data;
} nrf_drv_uart_event_t;
typedef void (*nrf_uart_event_handler_t)(nrf_drv_uart_event_t * p_event, void * p_context);
ret_code_t nrf_drv_uart_init(nrf_drv_uart_t const * p_instance,
		nrf_drv_uart_config_t const * p_config,
		nrf_uart_event_handler_t event_handler);
void nrf_drv_uart_uninit(nrf_drv_uart_t const * p_instance);
static inline uint32_t nrf_drv_uart_task_address_get(nrf_drv_uart_t const * p_instance,
		nrf_uart_task_t task);
static inline uint32_t nrf_drv_uart_event_address_get(nrf_drv_uart_t const * p_instance,
		nrf_uart_event_t event);
ret_code_t nrf_drv_uart_tx(nrf_drv_uart_t const * p_instance,
		uint8_t const * const p_data, uint8_t length);
_Bool 
nrf_drv_uart_tx_in_progress(nrf_drv_uart_t const * p_instance);
void nrf_drv_uart_tx_abort(nrf_drv_uart_t const * p_instance);
ret_code_t nrf_drv_uart_rx(nrf_drv_uart_t const * p_instance,
		uint8_t * p_data, uint8_t length);
_Bool 
nrf_drv_uart_rx_ready(nrf_drv_uart_t const * p_instance);
void nrf_drv_uart_rx_enable(nrf_drv_uart_t const * p_instance);
void nrf_drv_uart_rx_disable(nrf_drv_uart_t const * p_instance);
void nrf_drv_uart_rx_abort(nrf_drv_uart_t const * p_instance);
uint32_t nrf_drv_uart_errorsrc_get(nrf_drv_uart_t const * p_instance);
static inline uint32_t nrf_drv_uart_task_address_get(nrf_drv_uart_t const * p_instance,
		nrf_uart_task_t task)
{
	return nrf_uart_task_address_get(p_instance->reg.p_uart, task);
}
static inline uint32_t nrf_drv_uart_event_address_get(nrf_drv_uart_t const * p_instance,
		nrf_uart_event_t event)
{
	return nrf_uart_event_address_get(p_instance->reg.p_uart, event);
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
typedef struct
{
	int quot;
	int rem;
} div_t;
typedef struct
{
	long quot;
	long rem;
} ldiv_t;
typedef struct
{
	long long int quot;
	long long int rem;
} lldiv_t;
typedef int (*__compar_fn_t) (const void *, const void *);
int __locale_mb_cur_max (void);
void abort (void) __attribute__ ((__noreturn__));
int abs (int);
__uint32_t arc4random (void);
__uint32_t arc4random_uniform (__uint32_t);
void arc4random_buf (void *, size_t);
int atexit (void (*__func)(void));
double atof (const char *__nptr);
float atoff (const char *__nptr);
int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t _compar)
	;
	void * calloc (size_t __nmemb, size_t __size) ;
	div_t div (int __numer, int __denom);
	void exit (int __status) __attribute__ ((__noreturn__));
	void free (void *) ;
	char * getenv (const char *__string);
	char * _getenv_r (struct _reent *, const char *__string);
	char * _findenv (const char *, int *);
	char * _findenv_r (struct _reent *, const char *, int *);
	extern char *suboptarg;
	int getsubopt (char **, char * const *, char **);
	long labs (long);
	ldiv_t ldiv (long __numer, long __denom);
	void * malloc (size_t __size) ;
	int mblen (const char *, size_t);
	int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
	int mbtowc (wchar_t *restrict, const char *restrict, size_t);
	int _mbtowc_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
	int wctomb (char *, wchar_t);
	int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
	size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
	size_t _mbstowcs_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
	size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);
	size_t _wcstombs_r (struct _reent *, char *restrict, const wchar_t *restrict, size_t, _mbstate_t *);
	char * mkdtemp (char *);
	int mkstemp (char *);
	int mkstemps (char *, int);
	char * mktemp (char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));
	char * _mkdtemp_r (struct _reent *, char *);
	int _mkostemp_r (struct _reent *, char *, int);
	int _mkostemps_r (struct _reent *, char *, int, int);
	int _mkstemp_r (struct _reent *, char *);
	int _mkstemps_r (struct _reent *, char *, int);
	char * _mktemp_r (struct _reent *, char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));
	void qsort (void * __base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
	int rand (void);
	void * realloc (void * __r, size_t __size) ;
	void * reallocf (void * __r, size_t __size);
	char * realpath (const char *restrict path, char *restrict resolved_path);
	int rpmatch (const char *response);
	void srand (unsigned __seed);
	double strtod (const char *restrict __n, char **restrict __end_PTR);
	double _strtod_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR);
	float strtof (const char *restrict __n, char **restrict __end_PTR);
	long strtol (const char *restrict __n, char **restrict __end_PTR, int __base);
	long _strtol_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
	unsigned long strtoul (const char *restrict __n, char **restrict __end_PTR, int __base);
	unsigned long _strtoul_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
	int system (const char *__string);
	long a64l (const char *__input);
	char * l64a (long __input);
	char * _l64a_r (struct _reent *,long __input);
	int on_exit (void (*__func)(int, void *),void * __arg);
	void _Exit (int __status) __attribute__ ((__noreturn__));
	int putenv (char *__string);
	int _putenv_r (struct _reent *, char *__string);
	void * _reallocf_r (struct _reent *, void *, size_t);
	int setenv (const char *__string, const char *__value, int __overwrite);
	int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);
	char * __itoa (int, char *, int);
	char * __utoa (unsigned, char *, int);
	char * itoa (int, char *, int);
	char * utoa (unsigned, char *, int);
	int rand_r (unsigned *__seed);
	double drand48 (void);
	double _drand48_r (struct _reent *);
	double erand48 (unsigned short [3]);
	double _erand48_r (struct _reent *, unsigned short [3]);
	long jrand48 (unsigned short [3]);
	long _jrand48_r (struct _reent *, unsigned short [3]);
	void lcong48 (unsigned short [7]);
	void _lcong48_r (struct _reent *, unsigned short [7]);
	long lrand48 (void);
	long _lrand48_r (struct _reent *);
	long mrand48 (void);
	long _mrand48_r (struct _reent *);
	long nrand48 (unsigned short [3]);
	long _nrand48_r (struct _reent *, unsigned short [3]);
	unsigned short *
	seed48 (unsigned short [3]);
	unsigned short *
	_seed48_r (struct _reent *, unsigned short [3]);
	void srand48 (long);
	void _srand48_r (struct _reent *, long);
	char * initstate (unsigned, char *, size_t);
	long random (void);
	char * setstate (char *);
	void srandom (unsigned);
	long long atoll (const char *__nptr);
	long long _atoll_r (struct _reent *, const char *__nptr);
	long long llabs (long long);
	lldiv_t lldiv (long long __numer, long long __denom);
	long long strtoll (const char *restrict __n, char **restrict __end_PTR, int __base);
	long long _strtoll_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);
	unsigned long long strtoull (const char *restrict __n, char **restrict __end_PTR, int __base);
	unsigned long long _strtoull_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);
	void cfree (void *);
	int unsetenv (const char *__string);
	int _unsetenv_r (struct _reent *, const char *__string);
	int __attribute__((__nonnull__(1))) posix_memalign (void **, size_t, size_t);
	char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);
	void * _malloc_r (struct _reent *, size_t) ;
	void * _calloc_r (struct _reent *, size_t, size_t) ;
	void _free_r (struct _reent *, void *) ;
	void * _realloc_r (struct _reent *, void *, size_t) ;
	void _mstats_r (struct _reent *, char *);
	int _system_r (struct _reent *, const char *);
	void __eprintf (const char *, const char *, unsigned int, const char *);
void qsort_r (void * __base, size_t __nmemb, size_t __size, void * __thunk, int (*_compar)(void *, const void *, const void *))
	__asm__ ("" "__bsd_qsort_r");
	extern long double _strtold_r (struct _reent *, const char *restrict, char **restrict);
	extern long double strtold (const char *restrict, char **restrict);
void * aligned_alloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__alloc_align__(1)))
	__attribute__((__alloc_size__(2)));
	int at_quick_exit(void (*)(void));
	_Noreturn void
	quick_exit(int);
	typedef enum
{
	NRF_GPIO_PIN_DIR_INPUT = (0UL),
	NRF_GPIO_PIN_DIR_OUTPUT = (1UL)
} nrf_gpio_pin_dir_t;
typedef enum
{
	NRF_GPIO_PIN_INPUT_CONNECT = (0UL),
	NRF_GPIO_PIN_INPUT_DISCONNECT = (1UL)
} nrf_gpio_pin_input_t;
typedef enum
{
	NRF_GPIO_PIN_NOPULL = (0UL),
	NRF_GPIO_PIN_PULLDOWN = (1UL),
	NRF_GPIO_PIN_PULLUP = (3UL),
} nrf_gpio_pin_pull_t;
typedef enum
{
	NRF_GPIO_PIN_S0S1 = (0UL),
	NRF_GPIO_PIN_H0S1 = (1UL),
	NRF_GPIO_PIN_S0H1 = (2UL),
	NRF_GPIO_PIN_H0H1 = (3UL),
	NRF_GPIO_PIN_D0S1 = (4UL),
	NRF_GPIO_PIN_D0H1 = (5UL),
	NRF_GPIO_PIN_S0D1 = (6UL),
	NRF_GPIO_PIN_H0D1 = (7UL),
} nrf_gpio_pin_drive_t;
typedef enum
{
	NRF_GPIO_PIN_NOSENSE = (0UL),
	NRF_GPIO_PIN_SENSE_LOW = (3UL),
	NRF_GPIO_PIN_SENSE_HIGH = (2UL),
} nrf_gpio_pin_sense_t;
static inline void nrf_gpio_range_cfg_output(uint32_t pin_range_start, uint32_t pin_range_end);
static inline void nrf_gpio_range_cfg_input(uint32_t pin_range_start,
		uint32_t pin_range_end,
		nrf_gpio_pin_pull_t pull_config);
static inline void nrf_gpio_cfg(
		uint32_t pin_number,
		nrf_gpio_pin_dir_t dir,
		nrf_gpio_pin_input_t input,
		nrf_gpio_pin_pull_t pull,
		nrf_gpio_pin_drive_t drive,
		nrf_gpio_pin_sense_t sense);
static inline void nrf_gpio_cfg_output(uint32_t pin_number);
static inline void nrf_gpio_cfg_input(uint32_t pin_number, nrf_gpio_pin_pull_t pull_config);
static inline void nrf_gpio_cfg_default(uint32_t pin_number);
static inline void nrf_gpio_cfg_watcher(uint32_t pin_number);
static inline void nrf_gpio_input_disconnect(uint32_t pin_number);
static inline void nrf_gpio_cfg_sense_input(uint32_t pin_number,
		nrf_gpio_pin_pull_t pull_config,
		nrf_gpio_pin_sense_t sense_config);
static inline void nrf_gpio_cfg_sense_set(uint32_t pin_number, nrf_gpio_pin_sense_t sense_config);
static inline void nrf_gpio_pin_dir_set(uint32_t pin_number, nrf_gpio_pin_dir_t direction);
static inline void nrf_gpio_pin_set(uint32_t pin_number);
static inline void nrf_gpio_pin_clear(uint32_t pin_number);
static inline void nrf_gpio_pin_toggle(uint32_t pin_number);
static inline void nrf_gpio_pin_write(uint32_t pin_number, uint32_t value);
static inline uint32_t nrf_gpio_pin_read(uint32_t pin_number);
static inline uint32_t nrf_gpio_pin_out_read(uint32_t pin_number);
static inline nrf_gpio_pin_sense_t nrf_gpio_pin_sense_get(uint32_t pin_number);
static inline void nrf_gpio_port_dir_output_set(NRF_GPIO_Type * p_reg, uint32_t out_mask);
static inline void nrf_gpio_port_dir_input_set(NRF_GPIO_Type * p_reg, uint32_t in_mask);
static inline void nrf_gpio_port_dir_write(NRF_GPIO_Type * p_reg, uint32_t dir_mask);
static inline uint32_t nrf_gpio_port_dir_read(NRF_GPIO_Type const * p_reg);
static inline uint32_t nrf_gpio_port_in_read(NRF_GPIO_Type const * p_reg);
static inline uint32_t nrf_gpio_port_out_read(NRF_GPIO_Type const * p_reg);
static inline void nrf_gpio_port_out_write(NRF_GPIO_Type * p_reg, uint32_t value);
static inline void nrf_gpio_port_out_set(NRF_GPIO_Type * p_reg, uint32_t set_mask);
static inline void nrf_gpio_port_out_clear(NRF_GPIO_Type * p_reg, uint32_t clr_mask);
static inline void nrf_gpio_ports_read(uint32_t start_port, uint32_t length, uint32_t * p_masks);
static inline void nrf_gpio_latches_read(uint32_t start_port, uint32_t length,
		uint32_t * p_masks);
static inline uint32_t nrf_gpio_pin_latch_get(uint32_t pin_number);
static inline void nrf_gpio_pin_latch_clear(uint32_t pin_number);
static inline NRF_GPIO_Type * nrf_gpio_pin_port_decode(uint32_t * p_pin)
{
	if (0) { if (*p_pin < (32 + 16)) { } else { assert_nrf_callback((uint16_t)464, (uint8_t *)"././platform/mcu/nrf52xxx/Drivers/drivers_nrf/hal/nrf_gpio.h"); } };
	if (*p_pin < 32)
	{
		return ((NRF_GPIO_Type *) 0x50000000UL);
	}
	else
	{
		*p_pin = *p_pin & (32 - 1);
		return ((NRF_GPIO_Type *) 0x50000300UL);
	}
}
static inline void nrf_gpio_range_cfg_output(uint32_t pin_range_start, uint32_t pin_range_end)
{
	for (; pin_range_start <= pin_range_end; pin_range_start++)
	{
		nrf_gpio_cfg_output(pin_range_start);
	}
}
static inline void nrf_gpio_range_cfg_input(uint32_t pin_range_start,
		uint32_t pin_range_end,
		nrf_gpio_pin_pull_t pull_config)
{
	for (; pin_range_start <= pin_range_end; pin_range_start++)
	{
		nrf_gpio_cfg_input(pin_range_start, pull_config);
	}
}
static inline void nrf_gpio_cfg(
		uint32_t pin_number,
		nrf_gpio_pin_dir_t dir,
		nrf_gpio_pin_input_t input,
		nrf_gpio_pin_pull_t pull,
		nrf_gpio_pin_drive_t drive,
		nrf_gpio_pin_sense_t sense)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	reg->PIN_CNF[pin_number] = ((uint32_t)dir << (0UL))
		| ((uint32_t)input << (1UL))
		| ((uint32_t)pull << (2UL))
		| ((uint32_t)drive << (8UL))
		| ((uint32_t)sense << (16UL));
}
static inline void nrf_gpio_cfg_output(uint32_t pin_number)
{
	nrf_gpio_cfg(
			pin_number,
			NRF_GPIO_PIN_DIR_OUTPUT,
			NRF_GPIO_PIN_INPUT_DISCONNECT,
			NRF_GPIO_PIN_NOPULL,
			NRF_GPIO_PIN_S0S1,
			NRF_GPIO_PIN_NOSENSE);
}
static inline void nrf_gpio_cfg_input(uint32_t pin_number, nrf_gpio_pin_pull_t pull_config)
{
	nrf_gpio_cfg(
			pin_number,
			NRF_GPIO_PIN_DIR_INPUT,
			NRF_GPIO_PIN_INPUT_CONNECT,
			pull_config,
			NRF_GPIO_PIN_S0S1,
			NRF_GPIO_PIN_NOSENSE);
}
static inline void nrf_gpio_cfg_default(uint32_t pin_number)
{
	nrf_gpio_cfg(
			pin_number,
			NRF_GPIO_PIN_DIR_INPUT,
			NRF_GPIO_PIN_INPUT_DISCONNECT,
			NRF_GPIO_PIN_NOPULL,
			NRF_GPIO_PIN_S0S1,
			NRF_GPIO_PIN_NOSENSE);
}
static inline void nrf_gpio_cfg_watcher(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	uint32_t cnf = reg->PIN_CNF[pin_number] & ~(0x1UL << (1UL));
	reg->PIN_CNF[pin_number] = cnf | ((0UL) << (1UL));
}
static inline void nrf_gpio_input_disconnect(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	uint32_t cnf = reg->PIN_CNF[pin_number] & ~(0x1UL << (1UL));
	reg->PIN_CNF[pin_number] = cnf | ((1UL) << (1UL));
}
static inline void nrf_gpio_cfg_sense_input(uint32_t pin_number,
		nrf_gpio_pin_pull_t pull_config,
		nrf_gpio_pin_sense_t sense_config)
{
	nrf_gpio_cfg(
			pin_number,
			NRF_GPIO_PIN_DIR_INPUT,
			NRF_GPIO_PIN_INPUT_CONNECT,
			pull_config,
			NRF_GPIO_PIN_S0S1,
			sense_config);
}
static inline void nrf_gpio_cfg_sense_set(uint32_t pin_number, nrf_gpio_pin_sense_t sense_config)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	reg->PIN_CNF[pin_number] &= ~(0x3UL << (16UL));
	reg->PIN_CNF[pin_number] |= (sense_config << (16UL));
}
static inline void nrf_gpio_pin_dir_set(uint32_t pin_number, nrf_gpio_pin_dir_t direction)
{
	if (direction == NRF_GPIO_PIN_DIR_INPUT)
	{
		nrf_gpio_cfg(
				pin_number,
				NRF_GPIO_PIN_DIR_INPUT,
				NRF_GPIO_PIN_INPUT_CONNECT,
				NRF_GPIO_PIN_NOPULL,
				NRF_GPIO_PIN_S0S1,
				NRF_GPIO_PIN_NOSENSE);
	}
	else
	{
		NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
		reg->DIRSET = (1UL << pin_number);
	}
}
static inline void nrf_gpio_pin_set(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	nrf_gpio_port_out_set(reg, 1UL << pin_number);
}
static inline void nrf_gpio_pin_clear(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	nrf_gpio_port_out_clear(reg, 1UL << pin_number);
}
static inline void nrf_gpio_pin_toggle(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	uint32_t pins_state = reg->OUT;
	reg->OUTSET = (~pins_state & (1UL << pin_number));
	reg->OUTCLR = (pins_state & (1UL << pin_number));
}
static inline void nrf_gpio_pin_write(uint32_t pin_number, uint32_t value)
{
	if (value == 0)
	{
		nrf_gpio_pin_clear(pin_number);
	}
	else
	{
		nrf_gpio_pin_set(pin_number);
	}
}
static inline uint32_t nrf_gpio_pin_read(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	return ((nrf_gpio_port_in_read(reg) >> pin_number) & 1UL);
}
static inline uint32_t nrf_gpio_pin_out_read(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	return ((nrf_gpio_port_out_read(reg) >> pin_number) & 1UL);
}
static inline nrf_gpio_pin_sense_t nrf_gpio_pin_sense_get(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	return (nrf_gpio_pin_sense_t)((reg->PIN_CNF[pin_number] &
				(0x3UL << (16UL))) >> (16UL));
}
static inline void nrf_gpio_port_dir_output_set(NRF_GPIO_Type * p_reg, uint32_t out_mask)
{
	p_reg->DIRSET = out_mask;
}
static inline void nrf_gpio_port_dir_input_set(NRF_GPIO_Type * p_reg, uint32_t in_mask)
{
	p_reg->DIRCLR = in_mask;
}
static inline void nrf_gpio_port_dir_write(NRF_GPIO_Type * p_reg, uint32_t value)
{
	p_reg->DIR = value;
}
static inline uint32_t nrf_gpio_port_dir_read(NRF_GPIO_Type const * p_reg)
{
	return p_reg->DIR;
}
static inline uint32_t nrf_gpio_port_in_read(NRF_GPIO_Type const * p_reg)
{
	return p_reg->IN;
}
static inline uint32_t nrf_gpio_port_out_read(NRF_GPIO_Type const * p_reg)
{
	return p_reg->OUT;
}
static inline void nrf_gpio_port_out_write(NRF_GPIO_Type * p_reg, uint32_t value)
{
	p_reg->OUT = value;
}
static inline void nrf_gpio_port_out_set(NRF_GPIO_Type * p_reg, uint32_t set_mask)
{
	p_reg->OUTSET = set_mask;
}
static inline void nrf_gpio_port_out_clear(NRF_GPIO_Type * p_reg, uint32_t clr_mask)
{
	p_reg->OUTCLR = clr_mask;
}
static inline void nrf_gpio_ports_read(uint32_t start_port, uint32_t length, uint32_t * p_masks)
{
	NRF_GPIO_Type * gpio_regs[2] = {((NRF_GPIO_Type *) 0x50000000UL), ((NRF_GPIO_Type *) 0x50000300UL)};
	if (0) { if (start_port + length <= 2) { } else { assert_nrf_callback((uint16_t)744, (uint8_t *)"././platform/mcu/nrf52xxx/Drivers/drivers_nrf/hal/nrf_gpio.h"); } };
	uint32_t i;
	for (i = start_port; i < (start_port + length); i++)
	{
		*p_masks = nrf_gpio_port_in_read(gpio_regs[i]);
		p_masks++;
	}
}
static inline void nrf_gpio_latches_read(uint32_t start_port, uint32_t length, uint32_t * p_masks)
{
	NRF_GPIO_Type * gpio_regs[2] = {((NRF_GPIO_Type *) 0x50000000UL), ((NRF_GPIO_Type *) 0x50000300UL)};
	uint32_t i;
	for (i = start_port; i < (start_port + length); i++)
	{
		*p_masks = gpio_regs[i]->LATCH;
		p_masks++;
	}
}
static inline uint32_t nrf_gpio_pin_latch_get(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	return (reg->LATCH & (1 << pin_number)) ? 1 : 0;
}
static inline void nrf_gpio_pin_latch_clear(uint32_t pin_number)
{
	NRF_GPIO_Type * reg = nrf_gpio_pin_port_decode(&pin_number);
	reg->LATCH = (1 << pin_number);
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
extern nrf_log_module_dynamic_data_t m_nrf_log_uart_logs_data_dynamic;
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
typedef struct
{
	void * p_context;
	nrf_uart_event_handler_t handler;
	uint8_t const * p_tx_buffer;
	uint8_t * p_rx_buffer;
	uint8_t * p_rx_secondary_buffer;
	volatile uint16_t tx_counter;
	uint8_t tx_buffer_length;
	uint8_t rx_buffer_length;
	uint8_t rx_secondary_buffer_length;
	volatile uint8_t rx_counter;
	_Bool 
		rx_enabled;
	nrf_drv_state_t state;
	_Bool 
		use_easy_dma;
} uart_control_block_t;
static uart_control_block_t m_cb[1 + 0];
static inline void apply_config(nrf_drv_uart_t const * p_instance, nrf_drv_uart_config_t const * p_config)
{
	if (p_config->pseltxd != 0xFFFFFFFF)
	{
		nrf_gpio_pin_set(p_config->pseltxd);
		nrf_gpio_cfg_output(p_config->pseltxd);
	}
	if (p_config->pselrxd != 0xFFFFFFFF)
	{
		nrf_gpio_cfg_input(p_config->pselrxd, NRF_GPIO_PIN_NOPULL);
	}
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_baudrate_set(p_instance->reg.p_uarte, (nrf_uarte_baudrate_t)p_config->baudrate); nrf_uarte_configure(p_instance->reg.p_uarte, (nrf_uarte_parity_t)p_config->parity, (nrf_uarte_hwfc_t)p_config->hwfc); nrf_uarte_txrx_pins_set(p_instance->reg.p_uarte, p_config->pseltxd, p_config->pselrxd); if (p_config->hwfc == NRF_UART_HWFC_ENABLED) { if (p_config->pselcts != 0xFFFFFFFF) { nrf_gpio_cfg_input(p_config->pselcts, NRF_GPIO_PIN_NOPULL); } if (p_config->pselrts != 0xFFFFFFFF) { nrf_gpio_pin_set(p_config->pselrts); nrf_gpio_cfg_output(p_config->pselrts); } nrf_uarte_hwfc_pins_set(p_instance->reg.p_uarte, p_config->pselrts, p_config->pselcts); } }
	else { printf("11"); nrf_uart_baudrate_set(p_instance->reg.p_uart, p_config->baudrate); nrf_uart_configure(p_instance->reg.p_uart, p_config->parity, p_config->hwfc); nrf_uart_txrx_pins_set(p_instance->reg.p_uart, p_config->pseltxd, p_config->pselrxd); if (p_config->hwfc == NRF_UART_HWFC_ENABLED) { if (p_config->pselcts != 0xFFFFFFFF) { nrf_gpio_cfg_input(p_config->pselcts, NRF_GPIO_PIN_NOPULL); } if (p_config->pselrts != 0xFFFFFFFF) { nrf_gpio_pin_set(p_config->pselrts); nrf_gpio_cfg_output(p_config->pselrts); } nrf_uart_hwfc_pins_set(p_instance->reg.p_uart, p_config->pselrts, p_config->pselcts); } }
}
static inline void interrupts_enable(const nrf_drv_uart_t * p_instance, uint8_t interrupt_priority)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDRX); nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDTX); nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ERROR); nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_RXTO); nrf_uarte_int_enable(p_instance->reg.p_uarte, NRF_UARTE_INT_ENDRX_MASK | NRF_UARTE_INT_ENDTX_MASK | NRF_UARTE_INT_ERROR_MASK | NRF_UARTE_INT_RXTO_MASK); nrf_drv_common_irq_enable(nrf_drv_get_IRQn((void *)p_instance->reg.p_uarte), interrupt_priority); }
	else { nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_TXDRDY); nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_RXTO); nrf_uart_int_enable(p_instance->reg.p_uart, NRF_UART_INT_MASK_TXDRDY | NRF_UART_INT_MASK_RXTO); nrf_drv_common_irq_enable(nrf_drv_get_IRQn((void *)p_instance->reg.p_uart), interrupt_priority); }
}
static inline void interrupts_disable(const nrf_drv_uart_t * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_int_disable(p_instance->reg.p_uarte, NRF_UARTE_INT_ENDRX_MASK | NRF_UARTE_INT_ENDTX_MASK | NRF_UARTE_INT_ERROR_MASK | NRF_UARTE_INT_RXTO_MASK); nrf_drv_common_irq_disable(nrf_drv_get_IRQn((void *)p_instance->reg.p_uarte)); }
	else { nrf_uart_int_disable(p_instance->reg.p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_TXDRDY | NRF_UART_INT_MASK_ERROR | NRF_UART_INT_MASK_RXTO); nrf_drv_common_irq_disable(nrf_drv_get_IRQn((void *)p_instance->reg.p_uart)); }
}
static inline void pins_to_default(const nrf_drv_uart_t * p_instance)
{
	uint32_t txd;
	uint32_t rxd;
	uint32_t rts;
	uint32_t cts;
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { txd = nrf_uarte_tx_pin_get(p_instance->reg.p_uarte); rxd = nrf_uarte_rx_pin_get(p_instance->reg.p_uarte); rts = nrf_uarte_rts_pin_get(p_instance->reg.p_uarte); cts = nrf_uarte_cts_pin_get(p_instance->reg.p_uarte); nrf_uarte_txrx_pins_disconnect(p_instance->reg.p_uarte); nrf_uarte_hwfc_pins_disconnect(p_instance->reg.p_uarte); }
	else { txd = nrf_uart_tx_pin_get(p_instance->reg.p_uart); rxd = nrf_uart_rx_pin_get(p_instance->reg.p_uart); rts = nrf_uart_rts_pin_get(p_instance->reg.p_uart); cts = nrf_uart_cts_pin_get(p_instance->reg.p_uart); nrf_uart_txrx_pins_disconnect(p_instance->reg.p_uart); nrf_uart_hwfc_pins_disconnect(p_instance->reg.p_uart); }
	if (txd != 0xFFFFFFFF)
	{
		nrf_gpio_cfg_default(txd);
	}
	if (rxd != 0xFFFFFFFF)
	{
		nrf_gpio_cfg_default(rxd);
	}
	if (cts != 0xFFFFFFFF)
	{
		nrf_gpio_cfg_default(cts);
	}
	if (rts != 0xFFFFFFFF)
	{
		nrf_gpio_cfg_default(rts);
	}
}
static inline void uart_enable(const nrf_drv_uart_t * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_enable(p_instance->reg.p_uarte); }
	else { nrf_uart_enable(p_instance->reg.p_uart); };
}
static inline void uart_disable(const nrf_drv_uart_t * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_disable(p_instance->reg.p_uarte); }
	else { nrf_uart_disable(p_instance->reg.p_uart); };
}
ret_code_t nrf_drv_uart_init(const nrf_drv_uart_t * p_instance, nrf_drv_uart_config_t const * p_config,
		nrf_uart_event_handler_t event_handler)
{
	if (0) { if (p_config) { } else { assert_nrf_callback((uint16_t)274, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } };
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	ret_code_t err_code = ((0x0) + 0);
	if (p_cb->state != NRF_DRV_STATE_UNINITIALIZED)
	{
		err_code = ((0x0) + 8);
		if (0 && (0 >= 1UL) && (1UL <= 3)) { if (4UL >= 1UL) { (void)(((1UL) | 0 << 16)); (void)("Init failed. id:%d in wrong state"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
		return err_code;
	}
	p_cb->use_easy_dma = p_config->use_easy_dma;
	apply_config(p_instance, p_config);
	p_cb->handler = event_handler;
	p_cb->p_context = p_config->p_context;
	if (p_cb->handler)
	{
		interrupts_enable(p_instance, p_config->interrupt_priority);
	}
	uart_enable(p_instance);
	p_cb->rx_buffer_length = 0;
	p_cb->rx_secondary_buffer_length = 0;
	p_cb->tx_buffer_length = 0;
	p_cb->state = NRF_DRV_STATE_INITIALIZED;
	p_cb->rx_enabled = 
		0
		;
	return err_code;
}
void nrf_drv_uart_uninit(const nrf_drv_uart_t * p_instance)
{
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	uart_disable(p_instance);
	if (p_cb->handler)
	{
		interrupts_disable(p_instance);
	}
	pins_to_default(p_instance);
	p_cb->state = NRF_DRV_STATE_UNINITIALIZED;
	p_cb->handler = 
		((void *)0)
		;
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("Uninit id: %d."); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
}
static inline void tx_byte(NRF_UART_Type * p_uart, uart_control_block_t * p_cb)
{
	nrf_uart_event_clear(p_uart, NRF_UART_EVENT_TXDRDY);
	uint8_t txd = p_cb->p_tx_buffer[p_cb->tx_counter];
	p_cb->tx_counter++;
	nrf_uart_txd_set(p_uart, txd);
}
static inline ret_code_t nrf_drv_uart_tx_for_uart(const nrf_drv_uart_t * p_instance)
{
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	ret_code_t err_code = ((0x0) + 0);
	nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_TXDRDY);
	nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STARTTX);
	tx_byte(p_instance->reg.p_uart, p_cb);
	if (p_cb->handler == 
			((void *)0)
	   )
	{
		while (p_cb->tx_counter < (uint16_t) p_cb->tx_buffer_length)
		{
			while (!nrf_uart_event_check(p_instance->reg.p_uart, NRF_UART_EVENT_TXDRDY) &&
					p_cb->tx_counter != 256)
			{
			}
			if (p_cb->tx_counter != 256)
			{
				tx_byte(p_instance->reg.p_uart, p_cb);
			}
		}
		if (p_cb->tx_counter == 256)
		{
			err_code = ((0x0) + 15);
		}
		else
		{
			while (!nrf_uart_event_check(p_instance->reg.p_uart, NRF_UART_EVENT_TXDRDY))
			{
			}
			nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STOPTX);
		}
		p_cb->tx_buffer_length = 0;
	}
	return err_code;
}
static inline ret_code_t nrf_drv_uart_tx_for_uarte(const nrf_drv_uart_t * p_instance)
{
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	ret_code_t err_code = ((0x0) + 0);
	nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDTX);
	nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_TXSTOPPED);
	nrf_uarte_tx_buffer_set(p_instance->reg.p_uarte, p_cb->p_tx_buffer, p_cb->tx_buffer_length);
	nrf_uarte_task_trigger(p_instance->reg.p_uarte, NRF_UARTE_TASK_STARTTX);
	if (p_cb->handler == 
			((void *)0)
	   )
	{
		_Bool 
			endtx;
		_Bool 
			txstopped;
		do
		{
			endtx = nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDTX);
			txstopped = nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_TXSTOPPED);
		}
		while ((!endtx) && (!txstopped));
		if (txstopped)
		{
			err_code = ((0x0) + 15);
		}
		p_cb->tx_buffer_length = 0;
	}
	return err_code;
}
ret_code_t nrf_drv_uart_tx(const nrf_drv_uart_t * p_instance, uint8_t const * const p_data, uint8_t length)
{
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	if (0) { if (p_cb->state == NRF_DRV_STATE_INITIALIZED) { } else { assert_nrf_callback((uint16_t)410, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } };
	if (0) { if (length>0) { } else { assert_nrf_callback((uint16_t)411, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } };
	if (0) { if (p_data) { } else { assert_nrf_callback((uint16_t)412, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } };
	ret_code_t err_code;
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { if (!nrf_drv_is_in_RAM(p_data)) { err_code = ((0x0) + 16); if (0 && (0 >= 1UL) && (1UL <= 3)) { if (4UL >= 1UL) { (void)(((1UL) | 0 << 16)); (void)("Id:%d, Easy-DMA buffer not in RAM: %08x"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); (void)(p_data); } }; return err_code; } }
	if (nrf_drv_uart_tx_in_progress(p_instance))
	{
		err_code = ((0x0) + 17);
		if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("Id:%d busy"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
		return err_code;
	}
	p_cb->tx_buffer_length = length;
	p_cb->p_tx_buffer = p_data;
	p_cb->tx_counter = 0;
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("TX req id:%d length: %d."); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); (void)(p_cb->tx_buffer_length); } }
	;
	if (0 && (0 >= 4UL) && (4UL <= 3)) { if (4UL >= 4UL) { (void)(((4UL) | 0 << 16)); (void)("Tx data:"); } };
	if (0 && (0 >= 4UL) && (4UL <= 3)) { if (4UL >= 4UL) { (void)(((4UL) | 0 << 16)); (void)(((uint8_t *)p_cb->p_tx_buffer)); (void)(p_cb->tx_buffer_length * sizeof(p_cb->p_tx_buffer[0])); } }
	;
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { return nrf_drv_uart_tx_for_uarte(p_instance); }
	else { return nrf_drv_uart_tx_for_uart(p_instance); }
}
	_Bool 
nrf_drv_uart_tx_in_progress(const nrf_drv_uart_t * p_instance)
{
	return (m_cb[p_instance->drv_inst_idx].tx_buffer_length != 0);
}
static inline void rx_enable(const nrf_drv_uart_t * p_instance)
{
	nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_ERROR);
	nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_RXDRDY);
	nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STARTRX);
}
static inline void rx_byte(NRF_UART_Type * p_uart, uart_control_block_t * p_cb)
{
	if (!p_cb->rx_buffer_length)
	{
		nrf_uart_event_clear(p_uart, NRF_UART_EVENT_RXDRDY);
		(void) nrf_uart_rxd_get(p_uart);
		return;
	}
	nrf_uart_event_clear(p_uart, NRF_UART_EVENT_RXDRDY);
	p_cb->p_rx_buffer[p_cb->rx_counter] = nrf_uart_rxd_get(p_uart);
	p_cb->rx_counter++;
}
static inline ret_code_t nrf_drv_uart_rx_for_uart(const nrf_drv_uart_t * p_instance, uint8_t * p_data, uint8_t length, 
		_Bool 
		second_buffer)
{
	ret_code_t err_code;
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	if ((!p_cb->rx_enabled) && (!second_buffer))
	{
		rx_enable(p_instance);
	}
	if (p_cb->handler == 
			((void *)0)
	   )
	{
		nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_RXTO);
		_Bool 
			rxrdy;
		_Bool 
			rxto;
		_Bool 
			error;
		do
		{
			do
			{
				error = nrf_uart_event_check(p_instance->reg.p_uart, NRF_UART_EVENT_ERROR);
				rxrdy = nrf_uart_event_check(p_instance->reg.p_uart, NRF_UART_EVENT_RXDRDY);
				rxto = nrf_uart_event_check(p_instance->reg.p_uart, NRF_UART_EVENT_RXTO);
			} while ((!rxrdy) && (!rxto) && (!error));
			if (error || rxto)
			{
				break;
			}
			rx_byte(p_instance->reg.p_uart, p_cb);
		} while (p_cb->rx_buffer_length > p_cb->rx_counter);
		p_cb->rx_buffer_length = 0;
		if (error)
		{
			err_code = ((0x0) + 3);
			if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("RX Id: %d, transfer error."); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
			return err_code;
		}
		if (rxto)
		{
			if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("RX Id: %d, aborted."); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
			err_code = ((0x0) + 15);
			return err_code;
		}
		if (p_cb->rx_enabled)
		{
			nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STARTRX);
		}
		else
		{
			nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STOPRX);
		}
	}
	else
	{
		nrf_uart_int_enable(p_instance->reg.p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_ERROR);
	}
	err_code = ((0x0) + 0);
	return err_code;
}
static inline ret_code_t nrf_drv_uart_rx_for_uarte(const nrf_drv_uart_t * p_instance, uint8_t * p_data, uint8_t length, 
		_Bool 
		second_buffer)
{
	ret_code_t err_code = ((0x0) + 0);
	nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDRX);
	nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_RXTO);
	nrf_uarte_rx_buffer_set(p_instance->reg.p_uarte, p_data, length);
	if (!second_buffer)
	{
		nrf_uarte_task_trigger(p_instance->reg.p_uarte, NRF_UARTE_TASK_STARTRX);
	}
	else
	{
		nrf_uarte_shorts_enable(p_instance->reg.p_uarte, NRF_UARTE_SHORT_ENDRX_STARTRX);
	}
	if (m_cb[p_instance->drv_inst_idx].handler == 
			((void *)0)
	   )
	{
		_Bool 
			endrx;
		_Bool 
			rxto;
		_Bool 
			error;
		do {
			endrx = nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDRX);
			rxto = nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_RXTO);
			error = nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ERROR);
		}while ((!endrx) && (!rxto) && (!error));
		m_cb[p_instance->drv_inst_idx].rx_buffer_length = 0;
		if (error)
		{
			err_code = ((0x0) + 3);
		}
		if (rxto)
		{
			err_code = ((0x0) + 15);
		}
	}
	else
	{
		nrf_uarte_int_enable(p_instance->reg.p_uarte, NRF_UARTE_INT_ERROR_MASK | NRF_UARTE_INT_ENDRX_MASK);
	}
	return err_code;
}
ret_code_t nrf_drv_uart_rx(const nrf_drv_uart_t * p_instance, uint8_t * p_data, uint8_t length)
{
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	if (0) { if (m_cb[p_instance->drv_inst_idx].state == NRF_DRV_STATE_INITIALIZED) { } else { assert_nrf_callback((uint16_t)602, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } };
	if (0) { if (length>0) { } else { assert_nrf_callback((uint16_t)603, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } };
	ret_code_t err_code;
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { if (!nrf_drv_is_in_RAM(p_data)) { err_code = ((0x0) + 16); if (0 && (0 >= 1UL) && (1UL <= 3)) { if (4UL >= 1UL) { (void)(((1UL) | 0 << 16)); (void)("Id:%d, Easy-DMA buffer not in RAM: %08x"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); (void)(p_data); } }; return err_code; } }
	_Bool 
		second_buffer = 
		0
		;
	if (p_cb->handler)
	{
		if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_int_disable(p_instance->reg.p_uarte, NRF_UARTE_INT_ERROR_MASK | NRF_UARTE_INT_ENDRX_MASK); }
		else { nrf_uart_int_disable(p_instance->reg.p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_ERROR); }
	}
	if (p_cb->rx_buffer_length != 0)
	{
		if (p_cb->rx_secondary_buffer_length != 0)
		{
			if (p_cb->handler)
			{
				if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_int_enable(p_instance->reg.p_uarte, NRF_UARTE_INT_ERROR_MASK | NRF_UARTE_INT_ENDRX_MASK); }
				else { nrf_uart_int_enable(p_instance->reg.p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_ERROR); }
			}
			err_code = ((0x0) + 17);
			if (0 && (0 >= 2UL) && (2UL <= 3)) { if (4UL >= 2UL) { (void)(((2UL) | 0 << 16)); (void)("RX Id:%d, busy"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
			return err_code;
		}
		second_buffer = 
			1
			;
	}
	if (!second_buffer)
	{
		p_cb->rx_buffer_length = length;
		p_cb->p_rx_buffer = p_data;
		p_cb->rx_counter = 0;
		p_cb->rx_secondary_buffer_length = 0;
	}
	else
	{
		p_cb->p_rx_secondary_buffer = p_data;
		p_cb->rx_secondary_buffer_length = length;
	}
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("RX Id:%d len:%d"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); (void)(length); } };
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { return nrf_drv_uart_rx_for_uarte(p_instance, p_data, length, second_buffer); }
	else { return nrf_drv_uart_rx_for_uart(p_instance, p_data, length, second_buffer); }
}
	_Bool 
nrf_drv_uart_rx_ready(nrf_drv_uart_t const * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { return nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ENDRX); }
	else { return nrf_uart_event_check(p_instance->reg.p_uart, NRF_UART_EVENT_RXDRDY); }
}
void nrf_drv_uart_rx_enable(const nrf_drv_uart_t * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { if (0) { if (
			0
			) { } else { assert_nrf_callback((uint16_t)698, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } }; }
	else { if (!m_cb[p_instance->drv_inst_idx].rx_enabled) { rx_enable(p_instance); m_cb[p_instance->drv_inst_idx].rx_enabled = 
		1
			; } }
}
void nrf_drv_uart_rx_disable(const nrf_drv_uart_t * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { if (0) { if (
			0
			) { } else { assert_nrf_callback((uint16_t)715, (uint8_t *)"platform/mcu/nrf52xxx/Drivers/drivers_nrf/uart/nrf_drv_uart.c"); } }; }
	else { nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STOPRX); m_cb[p_instance->drv_inst_idx].rx_enabled = 
		0
			; }
}
uint32_t nrf_drv_uart_errorsrc_get(const nrf_drv_uart_t * p_instance)
{
	uint32_t errsrc;
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_ERROR); errsrc = nrf_uarte_errorsrc_get_and_clear(p_instance->reg.p_uarte); }
	else { nrf_uart_event_clear(p_instance->reg.p_uart, NRF_UART_EVENT_ERROR); errsrc = nrf_uart_errorsrc_get_and_clear(p_instance->reg.p_uart); }
	return errsrc;
}
static inline void rx_done_event(uart_control_block_t * p_cb, uint8_t bytes, uint8_t * p_data)
{
	nrf_drv_uart_event_t event;
	event.type = NRF_DRV_UART_EVT_RX_DONE;
	event.data.rxtx.bytes = bytes;
	event.data.rxtx.p_data = p_data;
	p_cb->handler(&event, p_cb->p_context);
}
static inline void tx_done_event(uart_control_block_t * p_cb, uint8_t bytes)
{
	nrf_drv_uart_event_t event;
	event.type = NRF_DRV_UART_EVT_TX_DONE;
	event.data.rxtx.bytes = bytes;
	event.data.rxtx.p_data = (uint8_t *)p_cb->p_tx_buffer;
	p_cb->tx_buffer_length = 0;
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("TX done len:%d"); (void)(bytes); } };
	p_cb->handler(&event, p_cb->p_context);
}
void nrf_drv_uart_tx_abort(const nrf_drv_uart_t * p_instance)
{
	uart_control_block_t * p_cb = &m_cb[p_instance->drv_inst_idx];
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_event_clear(p_instance->reg.p_uarte, NRF_UARTE_EVENT_TXSTOPPED); nrf_uarte_task_trigger(p_instance->reg.p_uarte, NRF_UARTE_TASK_STOPTX); if (p_cb->handler == 
			((void *)0)
			) { while (!nrf_uarte_event_check(p_instance->reg.p_uarte, NRF_UARTE_EVENT_TXSTOPPED)); } }
	else { nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STOPTX); if (p_cb->handler) { tx_done_event(p_cb, p_cb->tx_counter); } else { p_cb->tx_counter = 256; } }
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("TX abort Id:%d"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
}
void nrf_drv_uart_rx_abort(const nrf_drv_uart_t * p_instance)
{
	if (m_cb[p_instance->drv_inst_idx].use_easy_dma) { nrf_uarte_task_trigger(p_instance->reg.p_uarte, NRF_UARTE_TASK_STOPRX); }
	else { nrf_uart_int_disable(p_instance->reg.p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_ERROR); nrf_uart_task_trigger(p_instance->reg.p_uart, NRF_UART_TASK_STOPRX); }
	if (0 && (0 >= 3UL) && (3UL <= 3)) { if (4UL >= 3UL) { (void)(((3UL) | 0 << 16)); (void)("RX abort Id:%d"); (void)(nrf_drv_get_IRQn((void *)p_instance->reg.p_reg)); } };
}
static inline void uart_irq_handler(NRF_UART_Type * p_uart, uart_control_block_t * p_cb)
{
	if (nrf_uart_int_enable_check(p_uart, NRF_UART_INT_MASK_ERROR) &&
			nrf_uart_event_check(p_uart, NRF_UART_EVENT_ERROR))
	{
		nrf_drv_uart_event_t event;
		nrf_uart_event_clear(p_uart, NRF_UART_EVENT_ERROR);
		nrf_uart_int_disable(p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_ERROR);
		if (!p_cb->rx_enabled)
		{
			nrf_uart_task_trigger(p_uart, NRF_UART_TASK_STOPRX);
		}
		event.type = NRF_DRV_UART_EVT_ERROR;
		event.data.error.error_mask = nrf_uart_errorsrc_get_and_clear(p_uart);
		event.data.error.rxtx.bytes = p_cb->rx_buffer_length;
		event.data.error.rxtx.p_data = p_cb->p_rx_buffer;
		p_cb->rx_buffer_length = 0;
		p_cb->rx_secondary_buffer_length = 0;
		p_cb->handler(&event,p_cb->p_context);
	}
	else if (nrf_uart_int_enable_check(p_uart, NRF_UART_INT_MASK_RXDRDY) &&
			nrf_uart_event_check(p_uart, NRF_UART_EVENT_RXDRDY))
	{
		rx_byte(p_uart, p_cb);
		if (p_cb->rx_buffer_length == p_cb->rx_counter)
		{
			if (p_cb->rx_secondary_buffer_length)
			{
				uint8_t * p_data = p_cb->p_rx_buffer;
				uint8_t rx_counter = p_cb->rx_counter;
				p_cb->rx_buffer_length = p_cb->rx_secondary_buffer_length;
				p_cb->p_rx_buffer = p_cb->p_rx_secondary_buffer;
				p_cb->rx_secondary_buffer_length = 0;
				p_cb->rx_counter = 0;
				rx_done_event(p_cb, rx_counter, p_data);
			}
			else
			{
				if (!p_cb->rx_enabled)
				{
					nrf_uart_task_trigger(p_uart, NRF_UART_TASK_STOPRX);
				}
				nrf_uart_int_disable(p_uart, NRF_UART_INT_MASK_RXDRDY | NRF_UART_INT_MASK_ERROR);
				p_cb->rx_buffer_length = 0;
				rx_done_event(p_cb, p_cb->rx_counter, p_cb->p_rx_buffer);
			}
		}
	}
	if (nrf_uart_event_check(p_uart, NRF_UART_EVENT_TXDRDY))
	{
		if (p_cb->tx_counter < (uint16_t) p_cb->tx_buffer_length)
		{
			tx_byte(p_uart, p_cb);
		}
		else
		{
			nrf_uart_event_clear(p_uart, NRF_UART_EVENT_TXDRDY);
			if (p_cb->tx_buffer_length)
			{
				tx_done_event(p_cb, p_cb->tx_buffer_length);
			}
		}
	}
	if (nrf_uart_event_check(p_uart, NRF_UART_EVENT_RXTO))
	{
		nrf_uart_event_clear(p_uart, NRF_UART_EVENT_RXTO);
		if (p_cb->rx_enabled)
		{
			nrf_uart_task_trigger(p_uart, NRF_UART_TASK_STARTRX);
		}
		if (p_cb->rx_buffer_length)
		{
			p_cb->rx_buffer_length = 0;
			rx_done_event(p_cb, p_cb->rx_counter, p_cb->p_rx_buffer);
		}
	}
}
static inline void uarte_irq_handler(NRF_UARTE_Type * p_uarte, uart_control_block_t * p_cb)
{
	if (nrf_uarte_event_check(p_uarte, NRF_UARTE_EVENT_ERROR))
	{
		nrf_drv_uart_event_t event;
		nrf_uarte_event_clear(p_uarte, NRF_UARTE_EVENT_ERROR);
		event.type = NRF_DRV_UART_EVT_ERROR;
		event.data.error.error_mask = nrf_uarte_errorsrc_get_and_clear(p_uarte);
		event.data.error.rxtx.bytes = nrf_uarte_rx_amount_get(p_uarte);
		event.data.error.rxtx.p_data = p_cb->p_rx_buffer;
		p_cb->rx_buffer_length = 0;
		p_cb->rx_secondary_buffer_length = 0;
		p_cb->handler(&event, p_cb->p_context);
	}
	else if (nrf_uarte_event_check(p_uarte, NRF_UARTE_EVENT_ENDRX))
	{
		nrf_uarte_event_clear(p_uarte, NRF_UARTE_EVENT_ENDRX);
		uint8_t amount = nrf_uarte_rx_amount_get(p_uarte);
		if (amount == p_cb->rx_buffer_length)
		{
			if (p_cb->rx_secondary_buffer_length)
			{
				uint8_t * p_data = p_cb->p_rx_buffer;
				nrf_uarte_shorts_disable(p_uarte, NRF_UARTE_SHORT_ENDRX_STARTRX);
				p_cb->rx_buffer_length = p_cb->rx_secondary_buffer_length;
				p_cb->p_rx_buffer = p_cb->p_rx_secondary_buffer;
				p_cb->rx_secondary_buffer_length = 0;
				rx_done_event(p_cb, amount, p_data);
			}
			else
			{
				p_cb->rx_buffer_length = 0;
				rx_done_event(p_cb, amount, p_cb->p_rx_buffer);
			}
		}
	}
	if (nrf_uarte_event_check(p_uarte, NRF_UARTE_EVENT_RXTO))
	{
		nrf_uarte_event_clear(p_uarte, NRF_UARTE_EVENT_RXTO);
		if (p_cb->rx_buffer_length)
		{
			p_cb->rx_buffer_length = 0;
			rx_done_event(p_cb, nrf_uarte_rx_amount_get(p_uarte), p_cb->p_rx_buffer);
		}
	}
	if (nrf_uarte_event_check(p_uarte, NRF_UARTE_EVENT_ENDTX))
	{
		nrf_uarte_event_clear(p_uarte, NRF_UARTE_EVENT_ENDTX);
		if (p_cb->tx_buffer_length)
		{
			tx_done_event(p_cb, nrf_uarte_tx_amount_get(p_uarte));
		}
	}
}
void UARTE0_UART0_IRQHandler(void)
{
	krhino_intrpt_enter();
	if (m_cb[0].use_easy_dma) { uarte_irq_handler(((NRF_UARTE_Type *) 0x40002000UL), &m_cb[0]); }
	else { uart_irq_handler(((NRF_UART_Type *) 0x40002000UL), &m_cb[0]); }
	krhino_intrpt_exit();
}
