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
	struct __locale_t;
	typedef struct __locale_t *locale_t;
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
extern const struct file_ops pwm_ops;
int vfs_pwm_open(inode_t *inode, file_t *fp);
int vfs_pwm_close(file_t *fp);
int vfs_pwm_ioctl(file_t *fp, int cmd, unsigned long arg);
typedef struct {
	uint32_t sampling_cycle;
} adc_config_t;
typedef struct {
	uint8_t port;
	adc_config_t config;
	void *priv;
} adc_dev_t;
int32_t hal_adc_init(adc_dev_t *adc);
int32_t hal_adc_value_get(adc_dev_t *adc, void *output, uint32_t timeout);
int32_t hal_adc_finalize(adc_dev_t *adc);
typedef enum {
	HAL_PARTITION_ERROR = -1,
	HAL_PARTITION_BOOTLOADER,
	HAL_PARTITION_APPLICATION,
	HAL_PARTITION_ATE,
	HAL_PARTITION_OTA_TEMP,
	HAL_PARTITION_RF_FIRMWARE,
	HAL_PARTITION_PARAMETER_1,
	HAL_PARTITION_PARAMETER_2,
	HAL_PARTITION_PARAMETER_3,
	HAL_PARTITION_PARAMETER_4,
	HAL_PARTITION_BT_FIRMWARE,
	HAL_PARTITION_SPIFFS,
	HAL_PARTITION_CUSTOM_1,
	HAL_PARTITION_CUSTOM_2,
	HAL_PARTITION_MAX,
	HAL_PARTITION_NONE,
} hal_partition_t;
typedef enum {
	HAL_FLASH_EMBEDDED,
	HAL_FLASH_SPI,
	HAL_FLASH_QSPI,
	HAL_FLASH_MAX,
	HAL_FLASH_NONE,
} hal_flash_t;
typedef struct {
	hal_flash_t partition_owner;
	const char *partition_description;
	uint32_t partition_start_addr;
	uint32_t partition_length;
	uint32_t partition_options;
} hal_logic_partition_t;
hal_logic_partition_t *hal_flash_get_info(hal_partition_t in_partition);
int32_t hal_flash_erase(hal_partition_t in_partition, uint32_t off_set, uint32_t size);
int32_t hal_flash_write(hal_partition_t in_partition, uint32_t *off_set,
		const void *in_buf, uint32_t in_buf_len);
int32_t hal_flash_erase_write(hal_partition_t in_partition, uint32_t *off_set,
		const void *in_buf, uint32_t in_buf_len);
int32_t hal_flash_read(hal_partition_t in_partition, uint32_t *off_set,
		void *out_buf, uint32_t in_buf_len);
int32_t hal_flash_enable_secure(hal_partition_t partition, uint32_t off_set, uint32_t size);
int32_t hal_flash_dis_secure(hal_partition_t partition, uint32_t off_set, uint32_t size);
typedef enum {
	ANALOG_MODE,
	IRQ_MODE,
	INPUT_PULL_UP,
	INPUT_PULL_DOWN,
	INPUT_HIGH_IMPEDANCE,
	OUTPUT_PUSH_PULL,
	OUTPUT_OPEN_DRAIN_NO_PULL,
	OUTPUT_OPEN_DRAIN_PULL_UP,
} gpio_config_t;
typedef struct {
	uint8_t port;
	gpio_config_t config;
	void *priv;
} gpio_dev_t;
typedef enum {
	IRQ_TRIGGER_RISING_EDGE = 0x1,
	IRQ_TRIGGER_FALLING_EDGE = 0x2,
	IRQ_TRIGGER_BOTH_EDGES = IRQ_TRIGGER_RISING_EDGE | IRQ_TRIGGER_FALLING_EDGE,
} gpio_irq_trigger_t;
typedef void (*gpio_irq_handler_t)(void *arg);
int32_t hal_gpio_init(gpio_dev_t *gpio);
int32_t hal_gpio_output_high(gpio_dev_t *gpio);
int32_t hal_gpio_output_low(gpio_dev_t *gpio);
int32_t hal_gpio_output_toggle(gpio_dev_t *gpio);
int32_t hal_gpio_input_get(gpio_dev_t *gpio, uint32_t *value);
int32_t hal_gpio_enable_irq(gpio_dev_t *gpio, gpio_irq_trigger_t trigger,
		gpio_irq_handler_t handler, void *arg);
int32_t hal_gpio_disable_irq(gpio_dev_t *gpio);
int32_t hal_gpio_clear_irq(gpio_dev_t *gpio);
int32_t hal_gpio_finalize(gpio_dev_t *gpio);
typedef struct {
	uint32_t address_width;
	uint32_t freq;
	uint8_t mode;
	uint16_t dev_addr;
} i2c_config_t;
typedef struct {
	uint8_t port;
	i2c_config_t config;
	void *priv;
} i2c_dev_t;
int32_t hal_i2c_init(i2c_dev_t *i2c);
int32_t hal_i2c_master_send(i2c_dev_t *i2c, uint16_t dev_addr, const uint8_t *data,
		uint16_t size, uint32_t timeout);
int32_t hal_i2c_master_recv(i2c_dev_t *i2c, uint16_t dev_addr, uint8_t *data,
		uint16_t size, uint32_t timeout);
int32_t hal_i2c_slave_send(i2c_dev_t *i2c, const uint8_t *data, uint16_t size, uint32_t timeout);
int32_t hal_i2c_slave_recv(i2c_dev_t *i2c, uint8_t *data, uint16_t size, uint32_t timeout);
int32_t hal_i2c_mem_write(i2c_dev_t *i2c, uint16_t dev_addr, uint16_t mem_addr,
		uint16_t mem_addr_size, const uint8_t *data, uint16_t size,
		uint32_t timeout);
int32_t hal_i2c_mem_read(i2c_dev_t *i2c, uint16_t dev_addr, uint16_t mem_addr,
		uint16_t mem_addr_size, uint8_t *data, uint16_t size,
		uint32_t timeout);
int32_t hal_i2c_finalize(i2c_dev_t *i2c);
typedef struct {
	uint32_t page_size;
	uint32_t spare_area_size;
	uint32_t block_size;
	uint32_t zone_size;
	uint32_t zone_number;
} nand_config_t;
typedef struct {
	uint16_t page;
	uint16_t block;
	uint16_t zone;
} nand_addr_t;
typedef struct {
	uint32_t base_addr;
	nand_config_t config;
	void *priv;
} nand_dev_t;
int32_t hal_nand_init(nand_dev_t *nand);
int32_t hal_nand_finalize(nand_dev_t *nand);
int32_t hal_nand_read_page(nand_dev_t *nand, nand_addr_t *addr, uint8_t *data, uint32_t page_count);
int32_t hal_nand_write_page(nand_dev_t *nand, nand_addr_t *addr, uint8_t *data, uint32_t page_count);
int32_t hal_nand_read_spare(nand_dev_t *nand, nand_addr_t *addr, uint8_t *data, uint32_t data_len);
int32_t hal_nand_write_spare(nand_dev_t *nand, nand_addr_t *addr, uint8_t *data, uint32_t data_len);
int32_t hal_nand_erase_block(nand_dev_t *nand, nand_addr_t *addr);
typedef struct {
	uint32_t block_size;
	uint32_t chip_size;
} nor_config_t;
typedef struct {
	uint32_t base_addr;
	nor_config_t config;
	void *priv;
} nor_dev_t;
int32_t hal_nor_init(nor_dev_t *nor);
int32_t hal_nor_finalize(nor_dev_t *nor);
int32_t hal_nor_read(nor_dev_t *nor, uint32_t *addr, uint8_t *data, uint32_t len);
int32_t hal_nor_write(nor_dev_t *nor, uint32_t *addr, uint8_t *data, uint32_t len);
int32_t hal_nor_erase_block(nor_dev_t *nor, uint32_t *addr, uint32_t block_count);
int32_t hal_nor_erase_chip(nor_dev_t *nor, uint32_t *addr);
typedef struct {
	float duty_cycle;
	uint32_t freq;
} pwm_config_t;
typedef struct {
	uint8_t port;
	pwm_config_t config;
	void *priv;
} pwm_dev_t;
int32_t hal_pwm_init(pwm_dev_t *pwm);
int32_t hal_pwm_start(pwm_dev_t *pwm);
int32_t hal_pwm_stop(pwm_dev_t *pwm);
int32_t hal_pwm_finalize(pwm_dev_t *pwm);
typedef struct {
	uint32_t freq;
} qspi_config_t;
typedef struct {
	uint8_t port;
	qspi_config_t config;
	void *priv;
} qspi_dev_t;
typedef struct {
	uint32_t instruction;
	uint32_t address;
	uint32_t size;
} qspi_cmd_t;
int32_t hal_qspi_init(qspi_dev_t *qspi);
int32_t hal_qspi_send(qspi_dev_t *qspi, const uint8_t *data, uint32_t timeout);
int32_t hal_qspi_recv(qspi_dev_t *qspi, uint8_t *data, uint32_t timeout);
int32_t hal_qspi_command(qspi_dev_t *qspi, qspi_cmd_t *cmd, uint32_t timeout);
int32_t hal_qspi_auto_polling(qspi_dev_t *qspi, uint32_t cmd, uint32_t timeout);
int32_t hal_qspi_finalize(qspi_dev_t *qspi);
typedef struct {
	uint8_t port;
	void *priv;
} random_dev_t;
int32_t hal_random_num_read(random_dev_t random, void *buf, int32_t bytes);
typedef struct {
	uint8_t format;
} rtc_config_t;
typedef struct {
	uint8_t port;
	rtc_config_t config;
	void *priv;
} rtc_dev_t;
typedef struct {
	uint8_t sec;
	uint8_t min;
	uint8_t hr;
	uint8_t weekday;
	uint8_t date;
	uint8_t month;
	uint8_t year;
} rtc_time_t;
int32_t hal_rtc_init(rtc_dev_t *rtc);
int32_t hal_rtc_get_time(rtc_dev_t *rtc, rtc_time_t *time);
int32_t hal_rtc_set_time(rtc_dev_t *rtc, const rtc_time_t *time);
int32_t hal_rtc_finalize(rtc_dev_t *rtc);
typedef enum {
	SD_STAT_RESET,
	SD_STAT_READY,
	SD_STAT_TIMEOUT,
	SD_STAT_BUSY,
	SD_STAT_PROGRAMMING,
	SD_STAT_RECEIVING,
	SD_STAT_TRANSFER,
	SD_STAT_ERR
} hal_sd_stat;
typedef struct {
	uint32_t blk_nums;
	uint32_t blk_size;
} hal_sd_info_t;
typedef struct {
	uint32_t bus_wide;
	uint32_t freq;
} sd_config_t;
typedef struct {
	uint8_t port;
	sd_config_t config;
	void *priv;
} sd_dev_t;
int32_t hal_sd_init(sd_dev_t *sd);
int32_t hal_sd_blks_read(sd_dev_t *sd, uint8_t *data, uint32_t blk_addr,
		uint32_t blks, uint32_t timeout);
int32_t hal_sd_blks_write(sd_dev_t *sd, uint8_t *data, uint32_t blk_addr,
		uint32_t blks, uint32_t timeout);
int32_t hal_sd_erase(sd_dev_t *sd, uint32_t blk_start_addr, uint32_t blk_end_addr);
int32_t hal_sd_stat_get(sd_dev_t *sd, hal_sd_stat *stat);
int32_t hal_sd_info_get(sd_dev_t *sd, hal_sd_info_t *info);
int32_t hal_sd_finalize(sd_dev_t *sd);
typedef struct {
	uint32_t mode;
	uint32_t freq;
} spi_config_t;
typedef struct {
	uint8_t port;
	spi_config_t config;
	void *priv;
} spi_dev_t;
int32_t hal_spi_init(spi_dev_t *spi);
int32_t hal_spi_send(spi_dev_t *spi, const uint8_t *data, uint16_t size, uint32_t timeout);
int32_t hal_spi_recv(spi_dev_t *spi, uint8_t *data, uint16_t size, uint32_t timeout);
int32_t hal_spi_send_recv(spi_dev_t *spi, uint8_t *tx_data, uint8_t *rx_data,
		uint16_t size, uint32_t timeout);
int32_t hal_spi_finalize(spi_dev_t *spi);
typedef void (*hal_timer_cb_t)(void *arg);
typedef struct {
	uint32_t period;
	uint8_t reload_mode;
	hal_timer_cb_t cb;
	void *arg;
} timer_config_t;
typedef struct {
	int8_t port;
	timer_config_t config;
	void *priv;
} timer_dev_t;
int32_t hal_timer_init(timer_dev_t *tim);
int32_t hal_timer_start(timer_dev_t *tim);
void hal_timer_stop(timer_dev_t *tim);
int32_t hal_timer_finalize(timer_dev_t *tim);
typedef enum {
	DATA_WIDTH_5BIT,
	DATA_WIDTH_6BIT,
	DATA_WIDTH_7BIT,
	DATA_WIDTH_8BIT,
	DATA_WIDTH_9BIT
} hal_uart_data_width_t;
typedef enum {
	STOP_BITS_1,
	STOP_BITS_2
} hal_uart_stop_bits_t;
typedef enum {
	FLOW_CONTROL_DISABLED,
	FLOW_CONTROL_CTS,
	FLOW_CONTROL_RTS,
	FLOW_CONTROL_CTS_RTS
} hal_uart_flow_control_t;
typedef enum {
	NO_PARITY,
	ODD_PARITY,
	EVEN_PARITY
} hal_uart_parity_t;
typedef enum {
	MODE_TX,
	MODE_RX,
	MODE_TX_RX
} hal_uart_mode_t;
typedef struct {
	uint32_t baud_rate;
	hal_uart_data_width_t data_width;
	hal_uart_parity_t parity;
	hal_uart_stop_bits_t stop_bits;
	hal_uart_flow_control_t flow_control;
	hal_uart_mode_t mode;
} uart_config_t;
typedef struct {
	uint8_t port;
	uart_config_t config;
	void *priv;
} uart_dev_t;
int32_t hal_uart_init(uart_dev_t *uart);
int32_t hal_uart_send(uart_dev_t *uart, const void *data, uint32_t size, uint32_t timeout);
int32_t hal_uart_recv(uart_dev_t *uart, void *data, uint32_t expect_size, uint32_t timeout);
int32_t hal_uart_recv_II(uart_dev_t *uart, void *data, uint32_t expect_size,
		uint32_t *recv_size, uint32_t timeout);
int32_t hal_uart_finalize(uart_dev_t *uart);
typedef struct {
	uint32_t timeout;
} wdg_config_t;
typedef struct {
	uint8_t port;
	wdg_config_t config;
	void *priv;
} wdg_dev_t;
int32_t hal_wdg_init(wdg_dev_t *wdg);
void hal_wdg_reload(wdg_dev_t *wdg);
int32_t hal_wdg_finalize(wdg_dev_t *wdg);
typedef void (*hal_interpt_t)(int32_t vec, void *para);
typedef struct {
	hal_interpt_t fun;
	void *para;
} hal_interpt_desc_t;
int32_t hal_interpt_init(void);
int32_t hal_interpt_mask(int32_t vec);
int32_t hal_interpt_umask(int32_t vec);
int32_t hal_interpt_install(int32_t vec, hal_interpt_t handler,
		void *para, char *name);
typedef struct {
	uint8_t port;
	void *priv;
} dac_dev_t;
int32_t hal_dac_init(dac_dev_t *dac);
int32_t hal_dac_start(dac_dev_t *dac, uint32_t channel);
int32_t hal_dac_stop(dac_dev_t *dac, uint32_t channel);
int32_t hal_dac_set_value(dac_dev_t *dac, uint32_t channel, uint32_t data);
int32_t hal_dac_get_value(dac_dev_t *dac, uint32_t channel);
int32_t hal_dac_finalize(dac_dev_t *dac);
const struct file_ops pwm_ops =
{
	.open = vfs_pwm_open,
	.close = vfs_pwm_close,
	.ioctl = vfs_pwm_ioctl
};
int vfs_pwm_open(inode_t *inode, file_t *fp)
{
	int ret = -1;
	pwm_dev_t *pwm_dev = 
		((void *)0)
		;
	if ((fp != 
				((void *)0)
	    ) && (fp->node != 
		    ((void *)0)
		 )) {
		if (fp->node->refs == 1) {
			pwm_dev = (pwm_dev_t *)(fp->node->i_arg);
			ret = hal_pwm_init(pwm_dev);
		} else {
			ret = 0u;
		}
	} else {
		ret = -22;
	}
	return ret;
}
int vfs_pwm_close(file_t *fp)
{
	int ret = -1;
	pwm_dev_t *pwm_dev = 
		((void *)0)
		;
	if ((fp != 
				((void *)0)
	    ) && (fp->node != 
		    ((void *)0)
		 )) {
		if (fp->node->refs == 1) {
			pwm_dev = (pwm_dev_t *)(fp->node->i_arg);
			ret = aos_mutex_lock(&fp->node->mutex, 0xffffffffu);
			if (ret == 0) {
				ret = hal_pwm_finalize(pwm_dev);
			}
			aos_mutex_unlock(&fp->node->mutex);
		} else {
			ret = 0u;
		}
	} else {
		ret = -22;
	}
	return ret;
}
int vfs_pwm_ioctl(file_t *fp, int cmd, unsigned long arg)
{
	int ret = -1;
	pwm_dev_t *pwm_dev = 
		((void *)0)
		;
	if ((fp == 
				((void *)0)
	    ) || (fp->node == 
		    ((void *)0)
		 )) {
		return -22;
	}
	pwm_dev = (pwm_dev_t *)(fp->node->i_arg);
	ret = aos_mutex_lock(&fp->node->mutex, 0xffffffffu);
	if (ret != 0) {
		return ret;
	}
	switch(cmd) {
		case 1:
			ret = hal_pwm_start(pwm_dev);
			break;
		case 2:
			ret = hal_pwm_stop(pwm_dev);
			break;
		default:
			ret = -22;
			break;
	}
	aos_mutex_unlock(&fp->node->mutex);
	return ret;
}
