typedef unsigned int size_t;
typedef unsigned int wchar_t;
typedef int ptrdiff_t;
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
	extern char **environ;
	void _exit (int __status ) __attribute__ ((__noreturn__));
	int access (const char *__path, int __amode );
	unsigned alarm (unsigned __secs );
	int chdir (const char *__path );
	int chmod (const char *__path, mode_t __mode );
	int chown (const char *__path, uid_t __owner, gid_t __group );
	int chroot (const char *__path );
	int close (int __fildes );
	size_t confstr (int __name, char *__buf, size_t __len);
	int daemon (int nochdir, int noclose);
	int dup (int __fildes );
	int dup2 (int __fildes, int __fildes2 );
	void endusershell (void);
	int execl (const char *__path, const char *, ... );
	int execle (const char *__path, const char *, ... );
	int execlp (const char *__file, const char *, ... );
	int execlpe (const char *__file, const char *, ... );
	int execv (const char *__path, char * const __argv[] );
	int execve (const char *__path, char * const __argv[], char * const __envp[] );
	int execvp (const char *__file, char * const __argv[] );
	int faccessat (int __dirfd, const char *__path, int __mode, int __flags);
	int fchdir (int __fildes);
	int fchmod (int __fildes, mode_t __mode );
	int fchown (int __fildes, uid_t __owner, gid_t __group );
	int fchownat (int __dirfd, const char *__path, uid_t __owner, gid_t __group, int __flags);
	int fexecve (int __fd, char * const __argv[], char * const __envp[] );
	pid_t fork (void );
	long fpathconf (int __fd, int __name );
	int fsync (int __fd);
	int fdatasync (int __fd);
	char * getcwd (char *__buf, size_t __size );
	int getdomainname (char *__name, size_t __len);
	int getentropy (void *, size_t);
	gid_t getegid (void );
	uid_t geteuid (void );
	gid_t getgid (void );
	int getgroups (int __gidsetsize, gid_t __grouplist[] );
	long gethostid (void);
	char * getlogin (void );
	char * getpass (const char *__prompt);
	int getpagesize (void);
	int getpeereid (int, uid_t *, gid_t *);
	pid_t getpgid (pid_t);
	pid_t getpgrp (void );
	pid_t getpid (void );
	pid_t getppid (void );
	pid_t getsid (pid_t);
	uid_t getuid (void );
	char * getusershell (void);
	char * getwd (char *__buf );
	int iruserok (unsigned long raddr, int superuser, const char *ruser, const char *luser);
	int isatty (int __fildes );
	int issetugid (void);
	int lchown (const char *__path, uid_t __owner, gid_t __group );
	int link (const char *__path1, const char *__path2 );
	int linkat (int __dirfd1, const char *__path1, int __dirfd2, const char *__path2, int __flags );
	int nice (int __nice_value );
	off_t lseek (int __fildes, off_t __offset, int __whence );
	int lockf (int __fd, int __cmd, off_t __len);
	long pathconf (const char *__path, int __name );
	int pause (void );
	int pthread_atfork (void (*)(void), void (*)(void), void (*)(void));
	int pipe (int __fildes[2] );
	ssize_t pread (int __fd, void *__buf, size_t __nbytes, off_t __offset);
	ssize_t pwrite (int __fd, const void *__buf, size_t __nbytes, off_t __offset);
	int read (int __fd, void *__buf, size_t __nbyte );
	int rresvport (int *__alport);
	int revoke (char *__path);
	int rmdir (const char *__path );
	int ruserok (const char *rhost, int superuser, const char *ruser, const char *luser);
	void * sbrk (ptrdiff_t __incr);
	int setegid (gid_t __gid );
	int seteuid (uid_t __uid );
	int setgid (gid_t __gid );
	int setgroups (int ngroups, const gid_t *grouplist );
	int sethostname (const char *, size_t);
	int setpgid (pid_t __pid, pid_t __pgid );
	int setpgrp (void );
	int setregid (gid_t __rgid, gid_t __egid);
	int setreuid (uid_t __ruid, uid_t __euid);
	pid_t setsid (void );
	int setuid (uid_t __uid );
	void setusershell (void);
	unsigned sleep (unsigned int __seconds );
	void swab (const void *restrict, void *restrict, ssize_t);
	long sysconf (int __name );
	pid_t tcgetpgrp (int __fildes );
	int tcsetpgrp (int __fildes, pid_t __pgrp_id );
	char * ttyname (int __fildes );
	int ttyname_r (int, char *, size_t);
	int unlink (const char *__path );
	int usleep (useconds_t __useconds);
	int vhangup (void );
	int write (int __fd, const void *__buf, size_t __nbyte );
	extern char *optarg;
	extern int optind, opterr, optopt;
	int getopt(int, char * const [], const char *);
	extern int optreset;
	pid_t vfork (void );
	int ftruncate (int __fd, off_t __length);
	int truncate (const char *, off_t __length);
ssize_t readlink (const char *restrict __path, char *restrict __buf, size_t __buflen)
	;
	int symlink (const char *__name1, const char *__name2);
ssize_t readlinkat (int __dirfd1, const char *restrict __path, char *restrict __buf, size_t __buflen)
	;
	int symlinkat (const char *, int, const char *);
	int unlinkat (int, const char *, int);
	struct flock {
		short l_type;
		short l_whence;
		long l_start;
		long l_len;
		short l_pid;
		short l_xxx;
	};
struct eflock {
	short l_type;
	short l_whence;
	long l_start;
	long l_len;
	short l_pid;
	short l_xxx;
	long l_rpid;
	long l_rsys;
};
struct tm
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};
clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);
char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);
size_t strftime (char *restrict _s, size_t _maxsize, const char *restrict _fmt, const struct tm *restrict _t)
	;
	extern size_t strftime_l (char *restrict _s, size_t _maxsize,
			const char *restrict _fmt,
			const struct tm *restrict _t, locale_t _l);
char *asctime_r (const struct tm *restrict, char *restrict)
	;
	char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *restrict, struct tm *restrict)
	;
struct tm *localtime_r (const time_t *restrict, struct tm *restrict)
	;
	void tzset (void);
	void _tzset_r (struct _reent *);
	typedef struct __tzrule_struct
{
	char ch;
	int m;
	int n;
	int d;
	int s;
	time_t change;
	long offset;
} __tzrule_type;
typedef struct __tzinfo_struct
{
	int __tznorth;
	int __tzyear;
	__tzrule_type __tzrule[2];
} __tzinfo_type;
__tzinfo_type *__gettzinfo (void);
extern long _timezone;
extern int _daylight;
extern char *_tzname[2];
struct stat
{
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	off_t st_size;
	time_t st_atime;
	long st_spare1;
	time_t st_mtime;
	long st_spare2;
	time_t st_ctime;
	long st_spare3;
	blksize_t st_blksize;
	blkcnt_t st_blocks;
	long st_spare4[2];
};
int chmod ( const char *__path, mode_t __mode );
int fchmod (int __fd, mode_t __mode);
int fstat ( int __fd, struct stat *__sbuf );
int mkdir ( const char *_path, mode_t __mode );
int mkfifo ( const char *__path, mode_t __mode );
int stat ( const char *restrict __path, struct stat *restrict __sbuf );
mode_t umask ( mode_t __mask );
int fchmodat (int, const char *, mode_t, int);
int fstatat (int, const char *restrict , struct stat *restrict, int);
int mkdirat (int, const char *, mode_t);
int mkfifoat (int, const char *, mode_t);
int mknodat (int, const char *, mode_t, dev_t);
int utimensat (int, const char *, const struct timespec *, int);
int futimens (int, const struct timespec *);
extern int open (const char *, int, ...);
extern int openat (int, const char *, int, ...);
extern int creat (const char *, mode_t);
extern int fcntl (int, int, ...);
extern int flock (int, int);
struct pollfd {
	int fd;
	short events;
	short revents;
};
typedef void (*FUNCPTR)(void);
struct cli_command {
	const char *name;
	const char *help;
	void (*function)(char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv);
};
struct cli_st {
	int initialized;
	int echo_disabled;
	const struct cli_command *commands[64];
	unsigned int num_commands;
	unsigned int bp;
	char inbuf[256];
	char outbuf[2048];
	int his_idx;
	int his_cur;
	char history[5][256];
};
int aos_cli_register_command(const struct cli_command *command);
int aos_cli_unregister_command(const struct cli_command *command);
int aos_cli_register_commands(const struct cli_command *commands, int num_commands);
int aos_cli_unregister_commands(const struct cli_command *commands, int num_commands);
int aos_cli_printf(const char *buff, ...);
int aos_cli_init(void);
int aos_cli_stop(void);
const char *aos_cli_get_tag(void);
enum {
	CLOUD_CONNECTED,
	CLOUD_DISCONNECTED,
	GET_DEVICE_STATUS,
	SET_DEVICE_STATUS,
	GET_DEVICE_RAWDATA,
	SET_DEVICE_RAWDATA,
	UPGRADE_DEVICE,
	CANCEL_UPGRADE_DEVICE,
	GET_SUB_DEVICE_STATUS,
	SET_SUB_DEVICE_STATUS,
	MAX_EVENT_TYPE,
};
typedef void (*aos_cloud_cb_t)(int event, const char *json_buffer);
int aos_cloud_register_callback(int cb_type, aos_cloud_cb_t cb);
int aos_cloud_report(const char *method,
		const char *json_buffer,
		void (*done_cb)(void *),
		void *arg);
void aos_cloud_trigger(int cb_type, const char *json_buffer);
void aos_cloud_register_backend(int (*report)(const char *method, const char *json_buffer));
typedef struct {
	void *hdl;
} aos_hdl_t;
typedef aos_hdl_t aos_task_t;
typedef aos_hdl_t aos_mutex_t;
typedef aos_hdl_t aos_sem_t;
typedef aos_hdl_t aos_queue_t;
typedef aos_hdl_t aos_timer_t;
typedef aos_hdl_t aos_work_t;
typedef aos_hdl_t aos_event_t;
typedef struct {
	void *hdl;
	void *stk;
} aos_workqueue_t;
typedef unsigned int aos_task_key_t;
void aos_reboot(void);
int aos_get_hz(void);
const char *aos_version_get(void);
int aos_task_new(const char *name, void (*fn)(void *), void *arg, int stack_size);
int aos_task_new_ext(aos_task_t *task, const char *name, void (*fn)(void *), void *arg,
		int stack_size, int prio);
void aos_task_exit(int code);
const char *aos_task_name(void);
int aos_task_key_create(aos_task_key_t *key);
void aos_task_key_delete(aos_task_key_t key);
int aos_task_setspecific(aos_task_key_t key, void *vp);
void *aos_task_getspecific(aos_task_key_t key);
int aos_mutex_new(aos_mutex_t *mutex);
void aos_mutex_free(aos_mutex_t *mutex);
int aos_mutex_lock(aos_mutex_t *mutex, unsigned int timeout);
int aos_mutex_unlock(aos_mutex_t *mutex);
int aos_mutex_is_valid(aos_mutex_t *mutex);
int aos_sem_new(aos_sem_t *sem, int count);
void aos_sem_free(aos_sem_t *sem);
int aos_sem_wait(aos_sem_t *sem, unsigned int timeout);
void aos_sem_signal(aos_sem_t *sem);
int aos_sem_is_valid(aos_sem_t *sem);
void aos_sem_signal_all(aos_sem_t *sem);
int aos_event_new(aos_event_t *event, unsigned int flags);
void aos_event_free(aos_event_t *event);
int aos_event_get(aos_event_t *event, unsigned int flags, unsigned char opt,
		unsigned int *actl_flags, unsigned int timeout);
int aos_event_set(aos_event_t *event, unsigned int flags, unsigned char opt);
int aos_queue_new(aos_queue_t *queue, void *buf, unsigned int size, int max_msg);
void aos_queue_free(aos_queue_t *queue);
int aos_queue_send(aos_queue_t *queue, void *msg, unsigned int size);
int aos_queue_recv(aos_queue_t *queue, unsigned int ms, void *msg, unsigned int *size);
int aos_queue_is_valid(aos_queue_t *queue);
void *aos_queue_buf_ptr(aos_queue_t *queue);
int aos_timer_new(aos_timer_t *timer, void (*fn)(void *, void *),
		void *arg, int ms, int repeat);
int aos_timer_new_ext(aos_timer_t *timer, void (*fn)(void *, void *),
		void *arg, int ms, int repeat, unsigned char auto_run);
void aos_timer_free(aos_timer_t *timer);
int aos_timer_start(aos_timer_t *timer);
int aos_timer_stop(aos_timer_t *timer);
int aos_timer_change(aos_timer_t *timer, int ms);
int aos_workqueue_create(aos_workqueue_t *workqueue, int pri, int stack_size);
int aos_work_init(aos_work_t *work, void (*fn)(void *), void *arg, int dly);
void aos_work_destroy(aos_work_t *work);
int aos_work_run(aos_workqueue_t *workqueue, aos_work_t *work);
int aos_work_sched(aos_work_t *work);
int aos_work_cancel(aos_work_t *work);
void *aos_realloc(void *mem, unsigned int size);
void *aos_malloc(unsigned int size);
void *aos_zalloc(unsigned int size);
void aos_alloc_trace(void *addr, size_t allocator);
void aos_free(void *mem);
long long aos_now(void);
long long aos_now_ms(void);
void aos_msleep(int ms);
void aos_init(void);
void aos_start(void);
int aos_kv_set(const char *key, const void *value, int len, int sync);
int aos_kv_get(const char *key, void *buffer, int *buffer_len);
int aos_kv_del(const char *key);
typedef struct dlist_s {
	struct dlist_s *prev;
	struct dlist_s *next;
} dlist_t;
static inline void __dlist_add(dlist_t *node, dlist_t *prev, dlist_t *next)
{
	node->next = next;
	node->prev = prev;
	prev->next = node;
	next->prev = node;
}
static inline void dlist_add(dlist_t *node, dlist_t *queue)
{
	__dlist_add(node, queue, queue->next);
}
static inline void dlist_add_tail(dlist_t *node, dlist_t *queue)
{
	__dlist_add(node, queue->prev, queue);
}
static inline void dlist_del(dlist_t *node)
{
	dlist_t *prev = node->prev;
	dlist_t *next = node->next;
	prev->next = next;
	next->prev = prev;
}
static inline void dlist_init(dlist_t *node)
{
	node->next = node->prev = node;
}
static inline void INIT_AOS_DLIST_HEAD(dlist_t *list)
{
	list->next = list;
	list->prev = list;
}
static inline int dlist_empty(const dlist_t *head)
{
	return head->next == head;
}
static inline int dlist_entry_number(dlist_t *queue)
{
	int num;
	dlist_t *cur = queue;
	for (num=0;cur->next != queue;cur=cur->next, num++)
		;
	return num;
}
typedef struct slist_s {
	struct slist_s *next;
} slist_t;
static inline void slist_add(slist_t *node, slist_t *head)
{
	node->next = head->next;
	head->next = node;
}
static inline void slist_add_tail(slist_t *node, slist_t *head)
{
	while (head->next) {
		head = head->next;
	}
	slist_add(node, head);
}
static inline void slist_del(slist_t *node, slist_t *head)
{
	while (head->next) {
		if (head->next == node) {
			head->next = node->next;
			break;
		}
		head = head->next;
	}
}
static inline int slist_empty(const slist_t *head)
{
	return !head->next;
}
static inline void slist_init(slist_t *head)
{
	head->next = 0;
}
static inline int slist_entry_number(slist_t *queue)
{
	int num;
	slist_t *cur = queue;
	for (num=0;cur->next;cur=cur->next, num++)
		;
	return num;
}
extern unsigned int aos_log_level;
static inline unsigned int aos_log_get_level(void)
{
	return aos_log_level;
}
enum log_level_bit {
	AOS_LL_V_NONE_BIT = -1,
	AOS_LL_V_FATAL_BIT,
	AOS_LL_V_ERROR_BIT,
	AOS_LL_V_WARN_BIT,
	AOS_LL_V_INFO_BIT,
	AOS_LL_V_DEBUG_BIT,
	AOS_LL_V_MAX_BIT
};
extern int csp_printf(const char *fmt, ...);
int csp_printf(const char *fmt, ...);
typedef enum {
	AOS_LL_NONE,
	AOS_LL_FATAL,
	AOS_LL_ERROR,
	AOS_LL_WARN,
	AOS_LL_INFO,
	AOS_LL_DEBUG,
} aos_log_level_t;
extern unsigned int aos_log_level;
static inline int aos_get_log_level(void)
{
	return aos_log_level;
}
void aos_set_log_level(aos_log_level_t log_level);
typedef struct {
	int d_ino;
	uint8_t d_type;
	char d_name[];
} aos_dirent_t;
typedef struct {
	int dd_vfs_fd;
	int dd_rsv;
} aos_dir_t;
int aos_open(const char *path, int flags);
int aos_close(int fd);
ssize_t aos_read(int fd, void *buf, size_t nbytes);
ssize_t aos_write(int fd, const void *buf, size_t nbytes);
int aos_ioctl(int fd, int cmd, unsigned long arg);
int aos_poll(struct pollfd *fds, int nfds, int timeout);
int aos_fcntl(int fd, int cmd, int val);
off_t aos_lseek(int fd, off_t offset, int whence);
int aos_sync(int fd);
int aos_stat(const char *path, struct stat *st);
int aos_unlink(const char *path);
int aos_rename(const char *oldpath, const char *newpath);
aos_dir_t *aos_opendir(const char *path);
int aos_closedir(aos_dir_t *dir);
aos_dirent_t *aos_readdir(aos_dir_t *dir);
int aos_mkdir(const char *path);
const char *aos_get_product_model(void);
const char *aos_get_os_version(void);
const char *aos_get_kernel_version(void);
const char *aos_get_app_version(void);
const char *aos_get_device_name(void);
void dump_sys_info(void);
typedef struct {
	uint32_t time;
	uint16_t type;
	uint16_t code;
	unsigned long value;
	unsigned long extra;
} input_event_t;
typedef void (*aos_event_cb)(input_event_t *event, void *private_data);
typedef void (*aos_call_t)(void *arg);
typedef void (*aos_poll_call_t)(int fd, void *arg);
int aos_register_event_filter(uint16_t type, aos_event_cb cb, void *priv);
int aos_unregister_event_filter(uint16_t type, aos_event_cb cb, void *priv);
int aos_post_event(uint16_t type, uint16_t code, unsigned long value);
int aos_poll_read_fd(int fd, aos_poll_call_t action, void *param);
void aos_cancel_poll_read_fd(int fd, aos_poll_call_t action, void *param);
int aos_post_delayed_action(int ms, aos_call_t action, void *arg);
void aos_cancel_delayed_action(int ms, aos_call_t action, void *arg);
int aos_schedule_call(aos_call_t action, void *arg);
typedef void *aos_loop_t;
aos_loop_t aos_loop_init(void);
aos_loop_t aos_current_loop(void);
void aos_loop_run(void);
void aos_loop_exit(void);
void aos_loop_destroy(void);
int aos_loop_schedule_call(aos_loop_t *loop, aos_call_t action, void *arg);
void *aos_loop_schedule_work(int ms, aos_call_t action, void *arg1,
		aos_call_t fini_cb, void *arg2);
void aos_cancel_work(void *work, aos_call_t action, void *arg1);
extern int *__errno(void);
typedef struct {
	int argc;
	char **argv;
	_Bool 
		cli_enable;
} kinit_t;
extern int aos_kernel_init(kinit_t *kinit);
enum {
	VFS_TYPE_NOT_INIT,
	VFS_TYPE_CHAR_DEV,
	VFS_TYPE_BLOCK_DEV,
	VFS_TYPE_FS_DEV
};
typedef const struct file_ops file_ops_t;
typedef const struct fs_ops fs_ops_t;
union inode_ops_t {
	const file_ops_t *i_ops;
	const fs_ops_t *i_fops;
};
typedef struct {
	union inode_ops_t ops;
	void *i_arg;
	char *i_name;
	int i_flags;
	uint8_t type;
	uint8_t refs;
	aos_mutex_t mutex;
} inode_t;
typedef struct {
	inode_t *node;
	void *f_arg;
	size_t offset;
} file_t;
struct pollfd;
typedef void (*poll_notify_t)(struct pollfd *fd, void *arg);
struct file_ops {
	int (*open) (inode_t *node, file_t *fp);
	int (*close) (file_t *fp);
	ssize_t (*read) (file_t *fp, void *buf, size_t nbytes);
	ssize_t (*write) (file_t *fp, const void *buf, size_t nbytes);
	int (*ioctl) (file_t *fp, int cmd, unsigned long arg);
	int (*poll) (file_t *fp, 
			_Bool 
			flag, poll_notify_t notify, struct pollfd *fd, void *arg);
};
struct fs_ops {
	int (*open) (file_t *fp, const char *path, int flags);
	int (*close) (file_t *fp);
	ssize_t (*read) (file_t *fp, char *buf, size_t len);
	ssize_t (*write) (file_t *fp, const char *buf, size_t len);
	off_t (*lseek) (file_t *fp, off_t off, int whence);
	int (*sync) (file_t *fp);
	int (*stat) (file_t *fp, const char *path, struct stat *st);
	int (*unlink) (file_t *fp, const char *path);
	int (*rename) (file_t *fp, const char *oldpath, const char *newpath);
	aos_dir_t *(*opendir) (file_t *fp, const char *path);
	aos_dirent_t *(*readdir) (file_t *fp, aos_dir_t *dir);
	int (*closedir) (file_t *fp, aos_dir_t *dir);
	int (*mkdir) (file_t *fp, const char *path);
	int (*ioctl) (file_t *fp, int cmd, unsigned long arg);
};
int inode_init(void);
int inode_alloc(void);
int inode_del(inode_t *node);
inode_t *inode_open(const char *path);
int inode_ptr_get(int fd, inode_t **node);
int inode_avail_count(void);
void inode_ref(inode_t *);
void inode_unref(inode_t *);
int inode_busy(inode_t *);
int inode_reserve(const char *path, inode_t **inode);
int inode_release(const char *path);
int aos_register_driver(const char *path, file_ops_t *fops, void *arg);
int aos_unregister_driver(const char *path);
int aos_register_fs(const char *path, fs_ops_t *fops, void *arg);
int aos_unregister_fs(const char *path);
static int inited;
typedef struct {
	aos_mutex_t mutex;
	poll_notify_t poll_cb;
	struct pollfd *fd;
	void *poll_data;
	int counter;
	dlist_t bufs;
	int cache_count;
	dlist_t buf_cache;
} event_dev_t;
typedef struct {
	dlist_t node;
	size_t len;
	char buf[];
} dev_event_t;
static int event_open(inode_t *node, file_t *file)
{
	event_dev_t *pdev = (event_dev_t *)aos_malloc(sizeof * pdev);
	memset(pdev,0,sizeof (*pdev));
	aos_mutex_new(&pdev->mutex);
	dlist_init(&pdev->bufs);
	dlist_init(&pdev->buf_cache);
	file->f_arg = pdev;
	return 0;
}
static int event_close(file_t *file)
{
	event_dev_t *pdev = file->f_arg;
	aos_mutex_free(&pdev->mutex);
	while (!dlist_empty(&pdev->bufs)) {
		dlist_t *n = pdev->bufs.next;
		dlist_del(n);
		aos_free(n);
	}
	while (!dlist_empty(&pdev->buf_cache)) {
		dlist_t *n = pdev->buf_cache.next;
		dlist_del(n);
		aos_free(n);
	}
	aos_free(pdev);
	return 0;
}
static ssize_t _event_write(file_t *f, const void *buf, size_t len, 
		_Bool 
		urgent)
{
	event_dev_t *pdev = f->f_arg;
	aos_mutex_lock(&pdev->mutex, 0xffffffffu);
	ssize_t ret = len;
	dev_event_t *evt;
	evt = (dev_event_t *)pdev->buf_cache.next;
	if (pdev->cache_count > 0 && evt->len == len) {
		dlist_del(&evt->node);
		pdev->cache_count --;
	} else {
		evt = (dev_event_t *)aos_malloc(sizeof(*evt) + len);
	}
	if (evt == 
			((void *)0)
	   ) {
		ret = -1;
		goto out;
	}
	pdev->counter ++;
	evt->len = len;
	memcpy(evt->buf, buf, len);
	if (urgent) {
		dlist_add(&evt->node, &pdev->bufs);
	} else {
		dlist_add_tail(&evt->node, &pdev->bufs);
	}
	if (pdev->poll_cb != 
			((void *)0)
	   ) {
		pdev->fd->revents |= 0x1;
		pdev->poll_cb(pdev->fd, pdev->poll_data);
	}
out:
	aos_mutex_unlock(&pdev->mutex);
	return ret;
}
static ssize_t event_write(file_t *f, const void *buf, size_t len)
{
	return _event_write(f, buf, len, 
			0
			);
}
static int event_ioctl(file_t *f, int cmd, unsigned long arg)
{
	int len = ((cmd) >> 4);
	void *buf = (void *)arg;
	cmd = ((cmd) & 0xf);
	switch (cmd) {
		case 0x1:
			return _event_write(f, buf, len, 
					0
					);
		case 0x2:
			return _event_write(f, buf, len, 
					1
					);
	}
	return -1;
}
static ssize_t event_read(file_t *f, void *buf, size_t len)
{
	event_dev_t *pdev = f->f_arg;
	int cnt = pdev->counter;
	if (!cnt) {
		return 0;
	}
	aos_mutex_lock(&pdev->mutex, 0xffffffffu);
	dev_event_t *evt = (dev_event_t *)pdev->bufs.next;
	dlist_del(&evt->node);
	cnt = (len > evt->len) ? evt->len : len;
	memcpy(buf, evt->buf, cnt);
	if (pdev->cache_count < 4) {
		dlist_add(&evt->node, &pdev->buf_cache);
		pdev->cache_count ++;
	} else {
		aos_free(evt);
	}
	pdev->counter --;
	aos_mutex_unlock(&pdev->mutex);
	return cnt;
}
static int event_poll(file_t *f, 
		_Bool 
		setup, poll_notify_t notify,
		struct pollfd *fd, void *opa)
{
	event_dev_t *pdev = f->f_arg;
	aos_mutex_lock(&pdev->mutex, 0xffffffffu);
	if (!setup) {
		pdev->poll_cb = 
			((void *)0)
			;
		pdev->poll_data = 
			((void *)0)
			;
		goto out;
	}
	pdev->poll_cb = notify;
	pdev->fd = fd;
	pdev->poll_data = opa;
	if (pdev->counter) {
		pdev->fd->revents |= 0x1;
		(*notify)(fd, opa);
	}
out:
	aos_mutex_unlock(&pdev->mutex);
	return 0;
}
static file_ops_t event_fops = {
	.open = event_open,
	.read = event_read,
	.write = event_write,
	.close = event_close,
	.poll = event_poll,
	.ioctl = event_ioctl,
};
int vfs_device_init(void)
{
	int ret;
	if (inited == 1) {
		return 0u;
	}
	ret = aos_register_driver("/dev/event", &event_fops, 
			((void *)0)
			);
	if (ret != 0u) {
		return ret;
	}
	inited = 1;
	return 0u;
}
