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
typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef unsigned int wchar_t;
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
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
typedef __builtin_va_list __va_list;
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
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t;
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
	enum digest_type {
		DIGEST_TYPE_MD5,
		DIGEST_TYPE_SHA256,
		DIGEST_TYPE_SHA384,
		DIGEST_TYPE_SHA512,
	};
void *digest_md5_init(void);
int digest_md5_update(void *md5, const void *data, uint32_t length);
int digest_md5_final(void *md5, unsigned char *digest);
int digest_md5(const void *data, uint32_t length, unsigned char *digest);
int digest_md5_file(const char *path, unsigned char *digest);
void *digest_sha256_init(void);
int digest_sha256_update(void *sha256, const void *data, uint32_t length);
int digest_sha256_final(void *sha256, unsigned char *digest);
int digest_sha256(const void *data, uint32_t length, unsigned char *digest);
void *digest_sha384_init(void);
int digest_sha384_update(void *sha384, const void *data, uint32_t length);
int digest_sha384_final(void *sha384, unsigned char *digest);
int digest_sha384(const void *data, uint32_t length, unsigned char *digest);
void *digest_sha512_init(void);
int digest_sha512_update(void *sha512, const void *data, uint32_t length);
int digest_sha512_final(void *sha512, unsigned char *digest);
int digest_sha512(const void *data, uint32_t length, unsigned char *digest);
int digest_hmac(enum digest_type type,
		const unsigned char *msg, uint32_t msg_len,
		const unsigned char *key, uint32_t key_len,
		unsigned char *digest);
typedef struct {
	uint32_t state[4];
	uint32_t count[2];
	uint8_t buffer[64];
} MD5_CTX;
void MD5_Init(MD5_CTX *ctx);
void MD5_Update(MD5_CTX *ctx, const uint8_t *msg, int len);
void MD5_Final(uint8_t *digest, MD5_CTX *ctx);
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
	extern uint32_t os_be32toh(uint32_t data);
	extern uint32_t os_htobe32(uint32_t data);
	extern uint64_t os_be64toh(uint64_t data);
	extern uint64_t os_htobe64(uint64_t data);
	typedef uint8_t sha2_byte;
	typedef uint32_t sha2_word32;
	typedef uint64_t sha2_word64;
	typedef struct _SHA256_CTX {
		uint32_t state[8];
		uint64_t bitcount;
		uint8_t buffer[64];
	} SHA256_CTX;
typedef struct _SHA512_CTX {
	uint64_t state[8];
	uint64_t bitcount[2];
	uint8_t buffer[128];
} SHA512_CTX;
typedef SHA512_CTX SHA384_CTX;
static void SHA256_Init(SHA256_CTX *);
static void SHA256_Update(SHA256_CTX *, const uint8_t *, uint32_t);
static void SHA256_Final(uint8_t[32], SHA256_CTX *);
static void SHA384_Init(SHA384_CTX *);
static void SHA384_Update(SHA384_CTX *, const uint8_t *, uint32_t);
static void SHA384_Final(uint8_t[48], SHA384_CTX *);
static void SHA512_Init(SHA512_CTX *);
static void SHA512_Update(SHA512_CTX *, const uint8_t *, uint32_t);
static void SHA512_Final(uint8_t[64], SHA512_CTX *);
static void SHA512_Last(SHA512_CTX *);
static void SHA256_Transform(SHA256_CTX *, const sha2_word32 *);
static void SHA512_Transform(SHA512_CTX *, const sha2_word64 *);
static const sha2_word32 K256[64] = {
	0x428a2f98UL, 0x71374491UL, 0xb5c0fbcfUL, 0xe9b5dba5UL,
	0x3956c25bUL, 0x59f111f1UL, 0x923f82a4UL, 0xab1c5ed5UL,
	0xd807aa98UL, 0x12835b01UL, 0x243185beUL, 0x550c7dc3UL,
	0x72be5d74UL, 0x80deb1feUL, 0x9bdc06a7UL, 0xc19bf174UL,
	0xe49b69c1UL, 0xefbe4786UL, 0x0fc19dc6UL, 0x240ca1ccUL,
	0x2de92c6fUL, 0x4a7484aaUL, 0x5cb0a9dcUL, 0x76f988daUL,
	0x983e5152UL, 0xa831c66dUL, 0xb00327c8UL, 0xbf597fc7UL,
	0xc6e00bf3UL, 0xd5a79147UL, 0x06ca6351UL, 0x14292967UL,
	0x27b70a85UL, 0x2e1b2138UL, 0x4d2c6dfcUL, 0x53380d13UL,
	0x650a7354UL, 0x766a0abbUL, 0x81c2c92eUL, 0x92722c85UL,
	0xa2bfe8a1UL, 0xa81a664bUL, 0xc24b8b70UL, 0xc76c51a3UL,
	0xd192e819UL, 0xd6990624UL, 0xf40e3585UL, 0x106aa070UL,
	0x19a4c116UL, 0x1e376c08UL, 0x2748774cUL, 0x34b0bcb5UL,
	0x391c0cb3UL, 0x4ed8aa4aUL, 0x5b9cca4fUL, 0x682e6ff3UL,
	0x748f82eeUL, 0x78a5636fUL, 0x84c87814UL, 0x8cc70208UL,
	0x90befffaUL, 0xa4506cebUL, 0xbef9a3f7UL, 0xc67178f2UL
};
static const sha2_word32 sha256_initial_hash_value[8] = {
	0x6a09e667UL,
	0xbb67ae85UL,
	0x3c6ef372UL,
	0xa54ff53aUL,
	0x510e527fUL,
	0x9b05688cUL,
	0x1f83d9abUL,
	0x5be0cd19UL
};
static const sha2_word64 K512[80] = {
	0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
	0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
	0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
	0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
	0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
	0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
	0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
	0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
	0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
	0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
	0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
	0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
	0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
	0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
	0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
	0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
	0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
	0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
	0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
	0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
	0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
	0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
	0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
	0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
	0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
	0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
	0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
	0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
	0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
	0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
	0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
	0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
	0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
	0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
	0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
	0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
	0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
	0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
	0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
	0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};
static const sha2_word64 sha384_initial_hash_value[8] = {
	0xcbbb9d5dc1059ed8ULL,
	0x629a292a367cd507ULL,
	0x9159015a3070dd17ULL,
	0x152fecd8f70e5939ULL,
	0x67332667ffc00b31ULL,
	0x8eb44a8768581511ULL,
	0xdb0c2e0d64f98fa7ULL,
	0x47b5481dbefa4fa4ULL
};
static const sha2_word64 sha512_initial_hash_value[8] = {
	0x6a09e667f3bcc908ULL,
	0xbb67ae8584caa73bULL,
	0x3c6ef372fe94f82bULL,
	0xa54ff53a5f1d36f1ULL,
	0x510e527fade682d1ULL,
	0x9b05688c2b3e6c1fULL,
	0x1f83d9abfb41bd6bULL,
	0x5be0cd19137e2179ULL
};
static inline int os_is_big_endian(void)
{
	uint32_t data = 0xFF000000;
	if (0xFF == *(uint8_t *) & data) {
		return 1;
	}
	return 0;
}
static inline uint32_t reverse_32bit(uint32_t data)
{
	data = (data >> 16) | (data << 16);
	return ((data & 0xff00ff00UL) >> 8) | ((data & 0x00ff00ffUL) << 8);
}
uint32_t os_htole32(uint32_t data)
{
	if (os_is_big_endian()) {
		return reverse_32bit(data);
	}
	return data;
}
static inline uint64_t reverse_64bit(uint64_t data)
{
	data = (data >> 32) | (data << 32);
	data = ((data & 0xff00ff00ff00ff00ULL) >> 8) | ((data & 0x00ff00ff00ff00ffULL)
			<< 8);
	return ((data & 0xffff0000ffff0000ULL) >> 16) | ((data & 0x0000ffff0000ffffULL)
			<< 16);
}
uint32_t os_be32toh(uint32_t data)
{
	return os_htobe32(data);
}
uint32_t os_htobe32(uint32_t data)
{
	if (os_is_big_endian()) {
		return data;
	}
	return reverse_32bit(data);
}
uint64_t os_htobe64(uint64_t data)
{
	if (os_is_big_endian()) {
		return data;
	}
	return reverse_64bit(data);
}
uint64_t os_be64toh(uint64_t data)
{
	return os_htobe64(data);
}
static void SHA256_Init(SHA256_CTX *context)
{
	if (context == (SHA256_CTX *) 0) {
		return;
	}
	memcpy((context->state), (sha256_initial_hash_value), (32));
	memset((context->buffer), 0, (64));
	context->bitcount = 0;
}
static void SHA256_Transform(SHA256_CTX *context, const sha2_word32 *data)
{
	sha2_word32 a, b, c, d, e, f, g, h, s0, s1;
	sha2_word32 T1, T2, *W256;
	int j;
	W256 = (sha2_word32 *) context->buffer;
	a = context->state[0];
	b = context->state[1];
	c = context->state[2];
	d = context->state[3];
	e = context->state[4];
	f = context->state[5];
	g = context->state[6];
	h = context->state[7];
	j = 0;
	do {
		W256[j] = os_htobe32(*data++);
		T1 = h + (((((e)) >> (6)) | (((e)) << (32 - (6)))) ^ ((((e)) >> (11)) | (((e)) << (32 - (11)))) ^ ((((e)) >> (25)) | (((e)) << (32 - (25))))) + (((e) & (f)) ^ ((~(e)) & (g))) + K256[j] + W256[j];
		T2 = (((((a)) >> (2)) | (((a)) << (32 - (2)))) ^ ((((a)) >> (13)) | (((a)) << (32 - (13)))) ^ ((((a)) >> (22)) | (((a)) << (32 - (22))))) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
		j++;
	} while (j < 16);
	do {
		s0 = W256[(j + 1) & 0x0f];
		s0 = (((((s0)) >> (7)) | (((s0)) << (32 - (7)))) ^ ((((s0)) >> (18)) | (((s0)) << (32 - (18)))) ^ (((s0)) >> (3)));
		s1 = W256[(j + 14) & 0x0f];
		s1 = (((((s1)) >> (17)) | (((s1)) << (32 - (17)))) ^ ((((s1)) >> (19)) | (((s1)) << (32 - (19)))) ^ (((s1)) >> (10)));
		T1 = h + (((((e)) >> (6)) | (((e)) << (32 - (6)))) ^ ((((e)) >> (11)) | (((e)) << (32 - (11)))) ^ ((((e)) >> (25)) | (((e)) << (32 - (25))))) + (((e) & (f)) ^ ((~(e)) & (g)))
			+ K256[j] + (W256[j & 0x0f] += s1 + W256[(j + 9) & 0x0f] + s0);
		T2 = (((((a)) >> (2)) | (((a)) << (32 - (2)))) ^ ((((a)) >> (13)) | (((a)) << (32 - (13)))) ^ ((((a)) >> (22)) | (((a)) << (32 - (22))))) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
		j++;
	} while (j < 64);
	context->state[0] += a;
	context->state[1] += b;
	context->state[2] += c;
	context->state[3] += d;
	context->state[4] += e;
	context->state[5] += f;
	context->state[6] += g;
	context->state[7] += h;
	a = b = c = d = e = f = g = h = T1 = T2 = 0;
}
static void SHA256_Update(SHA256_CTX *context, const sha2_byte *data,
		uint32_t len)
{
	unsigned int os_freespace, usedspace;
	if (len == 0) {
		return;
	}
	if (context == 
			((void *)0) 
			|| data == 
			((void *)0)
	   ) {
		return;
	}
	usedspace = (context->bitcount >> 3) % 64;
	if (usedspace > 0) {
		os_freespace = 64 - usedspace;
		if (len >= os_freespace) {
			memcpy((&context->buffer[usedspace]), (data), (os_freespace));
			context->bitcount += os_freespace << 3;
			len -= os_freespace;
			data += os_freespace;
			SHA256_Transform(context, (sha2_word32 *) context->buffer);
		} else {
			memcpy((&context->buffer[usedspace]), (data), (len));
			context->bitcount += len << 3;
			usedspace = os_freespace = 0;
			return;
		}
	}
	while (len >= 64) {
		SHA256_Transform(context, (sha2_word32 *) data);
		context->bitcount += 64 << 3;
		len -= 64;
		data += 64;
	}
	if (len > 0) {
		memcpy((context->buffer), (data), (len));
		context->bitcount += len << 3;
	}
	usedspace = os_freespace = 0;
}
static void SHA256_Final(sha2_byte digest[], SHA256_CTX *context)
{
	sha2_word32 *d = (sha2_word32 *) digest;
	unsigned int usedspace;
	if (context == 
			((void *)0)
	   ) {
		return;
	}
	if (digest != (sha2_byte *) 0) {
		usedspace = (context->bitcount >> 3) % 64;
		context->bitcount = os_htobe64(context->bitcount);
		if (usedspace > 0) {
			context->buffer[usedspace++] = 0x80;
			if (usedspace <= (64 - 8)) {
				memset((&context->buffer[usedspace]), 0, ((64 - 8) - usedspace))
					;
			} else {
				if (usedspace < 64) {
					memset((&context->buffer[usedspace]), 0, (64 - usedspace));
				}
				SHA256_Transform(context, (sha2_word32 *) context->buffer);
				memset((context->buffer), 0, ((64 - 8)));
			}
		} else {
			memset((context->buffer), 0, ((64 - 8)));
			*context->buffer = 0x80;
		}
		*(sha2_word64 *) & context->buffer[(64 - 8)] =
			context->bitcount;
		SHA256_Transform(context, (sha2_word32 *) context->buffer);
		{
			int j;
			for (j = 0; j < 8; j++) {
				context->state[j] = os_be32toh(context->state[j]);
				*d++ = context->state[j];
			}
		}
	}
	memset((context), 0, (sizeof(*context)));
	usedspace = 0;
}
static void SHA512_Init(SHA512_CTX *context)
{
	if (context == (SHA512_CTX *) 0) {
		return;
	}
	memcpy((context->state), (sha512_initial_hash_value), (64));
	memset((context->buffer), 0, (128));
	context->bitcount[0] = context->bitcount[1] = 0;
}
static void SHA512_Transform(SHA512_CTX *context, const sha2_word64 *data)
{
	sha2_word64 a, b, c, d, e, f, g, h, s0, s1;
	sha2_word64 T1, T2, *W512 = (sha2_word64 *) context->buffer;
	int j;
	a = context->state[0];
	b = context->state[1];
	c = context->state[2];
	d = context->state[3];
	e = context->state[4];
	f = context->state[5];
	g = context->state[6];
	h = context->state[7];
	j = 0;
	do {
		W512[j] = os_be64toh(*data++);
		T1 = h + (((((e)) >> (14)) | (((e)) << (64 - (14)))) ^ ((((e)) >> (18)) | (((e)) << (64 - (18)))) ^ ((((e)) >> (41)) | (((e)) << (64 - (41))))) + (((e) & (f)) ^ ((~(e)) & (g))) + K512[j] + W512[j];
		T2 = (((((a)) >> (28)) | (((a)) << (64 - (28)))) ^ ((((a)) >> (34)) | (((a)) << (64 - (34)))) ^ ((((a)) >> (39)) | (((a)) << (64 - (39))))) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
		j++;
	} while (j < 16);
	do {
		s0 = W512[(j + 1) & 0x0f];
		s0 = (((((s0)) >> (1)) | (((s0)) << (64 - (1)))) ^ ((((s0)) >> (8)) | (((s0)) << (64 - (8)))) ^ (((s0)) >> (7)));
		s1 = W512[(j + 14) & 0x0f];
		s1 = (((((s1)) >> (19)) | (((s1)) << (64 - (19)))) ^ ((((s1)) >> (61)) | (((s1)) << (64 - (61)))) ^ (((s1)) >> (6)));
		T1 = h + (((((e)) >> (14)) | (((e)) << (64 - (14)))) ^ ((((e)) >> (18)) | (((e)) << (64 - (18)))) ^ ((((e)) >> (41)) | (((e)) << (64 - (41))))) + (((e) & (f)) ^ ((~(e)) & (g)))
			+ K512[j] + (W512[j & 0x0f] += s1 + W512[(j + 9) & 0x0f] + s0);
		T2 = (((((a)) >> (28)) | (((a)) << (64 - (28)))) ^ ((((a)) >> (34)) | (((a)) << (64 - (34)))) ^ ((((a)) >> (39)) | (((a)) << (64 - (39))))) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
		j++;
	} while (j < 80);
	context->state[0] += a;
	context->state[1] += b;
	context->state[2] += c;
	context->state[3] += d;
	context->state[4] += e;
	context->state[5] += f;
	context->state[6] += g;
	context->state[7] += h;
	a = b = c = d = e = f = g = h = T1 = T2 = 0;
}
static void SHA512_Update(SHA512_CTX *context, const sha2_byte *data,
		uint32_t len)
{
	unsigned int os_freespace, usedspace;
	if (len == 0) {
		return;
	}
	if (context == 
			((void *)0) 
			|| data == 
			((void *)0)
	   ) {
		return;
	}
	usedspace = (context->bitcount[0] >> 3) % 128;
	if (usedspace > 0) {
		os_freespace = 128 - usedspace;
		if (len >= os_freespace) {
			memcpy((&context->buffer[usedspace]), (data), (os_freespace));
			{ (context->bitcount)[0] += (sha2_word64)(os_freespace << 3); if ((context->bitcount)[0] < (os_freespace << 3)) { (context->bitcount)[1]++; } };
			len -= os_freespace;
			data += os_freespace;
			SHA512_Transform(context, (sha2_word64 *) context->buffer);
		} else {
			memcpy((&context->buffer[usedspace]), (data), (len));
			{ (context->bitcount)[0] += (sha2_word64)(len << 3); if ((context->bitcount)[0] < (len << 3)) { (context->bitcount)[1]++; } };
			usedspace = os_freespace = 0;
			return;
		}
	}
	while (len >= 128) {
		SHA512_Transform(context, (sha2_word64 *) data);
		{ (context->bitcount)[0] += (sha2_word64)(128 << 3); if ((context->bitcount)[0] < (128 << 3)) { (context->bitcount)[1]++; } };
		len -= 128;
		data += 128;
	}
	if (len > 0) {
		memcpy((context->buffer), (data), (len));
		{ (context->bitcount)[0] += (sha2_word64)(len << 3); if ((context->bitcount)[0] < (len << 3)) { (context->bitcount)[1]++; } };
	}
	usedspace = os_freespace = 0;
}
static void SHA512_Last(SHA512_CTX *context)
{
	unsigned int usedspace;
	usedspace = (context->bitcount[0] >> 3) % 128;
	context->bitcount[0] = os_htobe64(context->bitcount[0]);
	context->bitcount[1] = os_htobe64(context->bitcount[1]);
	if (usedspace > 0) {
		context->buffer[usedspace++] = 0x80;
		if (usedspace <= (128 - 16)) {
			memset((&context->buffer[usedspace]), 0, ((128 - 16) - usedspace))
				;
		} else {
			if (usedspace < 128) {
				memset((&context->buffer[usedspace]), 0, (128 - usedspace));
			}
			SHA512_Transform(context, (sha2_word64 *) context->buffer);
			memset((context->buffer), 0, (128 - 2));
		}
	} else {
		memset((context->buffer), 0, ((128 - 16)));
		*context->buffer = 0x80;
	}
	*(sha2_word64 *) & context->buffer[(128 - 16)] =
		context->bitcount[1];
	*(sha2_word64 *) & context->buffer[(128 - 16) + 8] =
		context->bitcount[0];
	SHA512_Transform(context, (sha2_word64 *) context->buffer);
}
static void SHA512_Final(sha2_byte digest[], SHA512_CTX *context)
{
	sha2_word64 *d = (sha2_word64 *) digest;
	if (context == 
			((void *)0)
	   ) {
		return;
	}
	if (digest != (sha2_byte *) 0) {
		SHA512_Last(context);
		{
			int j;
			for (j = 0; j < 8; j++) {
				context->state[j] = os_be64toh(context->state[j]);
				*d++ = context->state[j];
			}
		}
	}
	memset((context), 0, (sizeof(*context)));
}
static void SHA384_Init(SHA384_CTX *context)
{
	if (context == (SHA384_CTX *) 0) {
		return;
	}
	memcpy((context->state), (sha384_initial_hash_value), (64));
	memset((context->buffer), 0, (128));
	context->bitcount[0] = context->bitcount[1] = 0;
}
static void SHA384_Update(SHA384_CTX *context, const sha2_byte *data,
		uint32_t len)
{
	SHA512_Update((SHA512_CTX *) context, data, len);
}
static void SHA384_Final(sha2_byte digest[], SHA384_CTX *context)
{
	sha2_word64 *d = (sha2_word64 *) digest;
	if (context == 
			((void *)0)
	   ) {
		return;
	}
	if (digest != (sha2_byte *) 0) {
		SHA512_Last((SHA512_CTX *) context);
		{
			int j;
			for (j = 0; j < 6; j++) {
				context->state[j] = os_be64toh(context->state[j]);
				*d++ = context->state[j];
			}
		}
	}
	memset((context), 0, (sizeof(context)));
}
static int digest_hmac_md5(const unsigned char *msg, uint32_t msg_len,
		const unsigned char *key, uint32_t key_len, unsigned char *digest)
{
	void *context;
	unsigned char k_ipad[65];
	unsigned char k_opad[65];
	unsigned char tk[16];
	int i;
	if (key_len > 64) {
		void *ctx;
		ctx = digest_md5_init();
		digest_md5_update(ctx, (uint8_t *) key, key_len);
		digest_md5_final(ctx, (uint8_t *) tk);
		key = tk;
		key_len = 16;
	}
	memset(k_ipad, 0, sizeof(k_ipad));
	memset(k_opad, 0, sizeof(k_opad));
	memcpy(k_ipad, key, key_len);
	memcpy(k_opad, key, key_len);
	for (i = 0; i < 64; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}
	context = digest_md5_init();
	digest_md5_update(context, k_ipad, 64);
	digest_md5_update(context, (uint8_t *) msg, msg_len);
	digest_md5_final(context, (uint8_t *) digest);
	context = digest_md5_init();
	digest_md5_update(context, k_opad, 64);
	digest_md5_update(context, (uint8_t *) digest, 16);
	digest_md5_final(context, (uint8_t *) digest);
	return 0;
}
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
void *digest_md5_init(void)
{
	MD5_CTX *ctx = (MD5_CTX *) aos_malloc(sizeof(MD5_CTX));
	if (
			((void *)0) 
			== ctx) {
		return 
			((void *)0)
			;
	}
	MD5_Init(ctx);
	return ctx;
}
int digest_md5_update(void *md5, const void *data, uint32_t length)
{
	MD5_Update(md5, data, length);
	return 0;
}
int digest_md5_final(void *md5, unsigned char *digest)
{
	MD5_Final(digest, md5);
	aos_free(md5);
	return 0;
}
int digest_md5(const void *data, uint32_t length, unsigned char *digest)
{
	MD5_CTX *ctx = (MD5_CTX *) aos_malloc(sizeof(MD5_CTX));
	if (
			((void *)0) 
			== ctx) {
		return -1;
	}
	MD5_Init(ctx);
	MD5_Update(ctx, data, length);
	MD5_Final(digest, ctx);
	aos_free(ctx);
	return 0;
}
int digest_md5_file(const char *path, unsigned char *md5)
{
	int bytes;
	unsigned char data[512];
	unsigned char digest[16];
	int i, fd;
	fd = aos_open(path, 
			0
		     );
	if (fd < 0) {
		return -1;
	}
	MD5_CTX *ctx = (MD5_CTX *) aos_malloc(sizeof(MD5_CTX));
	if (
			((void *)0) 
			== ctx) {
		aos_close(fd);
		return -1;
	}
	MD5_Init(ctx);
	do {
		bytes = aos_read(fd, data, sizeof(data));
		if (bytes > 0) {
			MD5_Update(ctx, data, bytes);
		}
	} while (bytes == sizeof(data));
	MD5_Final(digest, ctx);
	for (i = 0; i < 16; i++) {
		sprintf((char *)&md5[i * 2], "%02x", digest[i]);
	}
	aos_close(fd);
	aos_free(ctx);
	return 0;
}
void *digest_sha256_init(void)
{
	SHA256_CTX *ctx = (SHA256_CTX *) aos_malloc(sizeof(SHA256_CTX));
	if (
			((void *)0) 
			== ctx) {
		return 
			((void *)0)
			;
	}
	SHA256_Init(ctx);
	return ctx;
}
int digest_sha256_update(void *sha256, const void *data, uint32_t length)
{
	SHA256_Update(sha256, data, length);
	return 0;
}
int digest_sha256_final(void *sha256, unsigned char *digest)
{
	SHA256_Final(digest, sha256);
	aos_free(sha256);
	return 0;
}
int digest_sha256(const void *data, uint32_t length, unsigned char *digest)
{
	SHA256_CTX *ctx = (SHA256_CTX *) aos_malloc(sizeof(SHA256_CTX));
	if (
			((void *)0) 
			== ctx) {
		return -1;
	}
	memset(ctx, 0, sizeof(SHA256_CTX));
	SHA256_Init(ctx);
	SHA256_Update(ctx, data, length);
	SHA256_Final(digest, ctx);
	aos_free(ctx);
	return 0;
}
void *digest_sha384_init(void)
{
	SHA384_CTX *ctx = (SHA384_CTX *) aos_malloc(sizeof(SHA384_CTX));
	if (
			((void *)0) 
			== ctx) {
		return 
			((void *)0)
			;
	}
	SHA384_Init(ctx);
	return ctx;
}
int digest_sha384_update(void *sha384, const void *data, uint32_t length)
{
	SHA384_Update(sha384, data, length);
	return 0;
}
int digest_sha384_final(void *sha384, unsigned char *digest)
{
	SHA384_Final(digest, sha384);
	aos_free(sha384);
	return 0;
}
int digest_sha384(const void *data, uint32_t length, unsigned char *digest)
{
	SHA384_CTX *ctx = (SHA384_CTX *) aos_malloc(sizeof(SHA384_CTX));
	if (
			((void *)0) 
			== ctx) {
		return -1;
	}
	SHA384_Init(ctx);
	SHA384_Update(ctx, data, length);
	SHA384_Final(digest, ctx);
	aos_free(ctx);
	return 0;
}
void *digest_sha512_init(void)
{
	SHA512_CTX *ctx = (SHA512_CTX *) aos_malloc(sizeof(SHA512_CTX));
	if (
			((void *)0) 
			== ctx) {
		return 
			((void *)0)
			;
	}
	SHA512_Init(ctx);
	return ctx;
}
int digest_sha512_update(void *sha512, const void *data, uint32_t length)
{
	SHA512_Update(sha512, data, length);
	return 0;
}
int digest_sha512_final(void *sha512, unsigned char *digest)
{
	SHA512_Final(digest, sha512);
	aos_free(sha512);
	return 0;
}
int digest_sha512(const void *data, uint32_t length, unsigned char *digest)
{
	SHA512_CTX *ctx = (SHA512_CTX *) aos_malloc(sizeof(SHA512_CTX));
	if (
			((void *)0) 
			== ctx) {
		return -1;
	}
	SHA512_Init(ctx);
	SHA512_Update(ctx, data, length);
	SHA512_Final(digest, ctx);
	aos_free(ctx);
	return 0;
}
int digest_hmac(enum digest_type type, const unsigned char *data,
		uint32_t data_len, const unsigned char *key, uint32_t key_len,
		unsigned char *digest)
{
	switch (type) {
		case DIGEST_TYPE_MD5:
			return digest_hmac_md5(data, data_len, key, key_len, digest);
		case DIGEST_TYPE_SHA256:
			break;
		case DIGEST_TYPE_SHA384:
			break;
		case DIGEST_TYPE_SHA512:
			break;
		default:
			break;
	}
	return -1;
}
