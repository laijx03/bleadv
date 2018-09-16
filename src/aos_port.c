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
typedef signed char s8_t;
typedef signed short s16_t;
typedef signed int s32_t;
typedef signed long long s64_t;
typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef unsigned long long u64_t;
struct _snode {
	struct _snode *next;
};
typedef struct _snode sys_snode_t;
struct _slist {
	sys_snode_t *head;
	sys_snode_t *tail;
};
typedef struct _slist sys_slist_t;
static inline void sys_slist_init(sys_slist_t *list)
{
	list->head = 
		((void *)0)
		;
	list->tail = 
		((void *)0)
		;
}
static inline 
	_Bool 
sys_slist_is_empty(sys_slist_t *list)
{
	return (!list->head);
}
static inline sys_snode_t *sys_slist_peek_head(sys_slist_t *list)
{
	return list->head;
}
static inline sys_snode_t *sys_slist_peek_tail(sys_slist_t *list)
{
	return list->tail;
}
static inline sys_snode_t *sys_slist_peek_next_no_check(sys_snode_t *node)
{
	return node->next;
}
static inline sys_snode_t *sys_slist_peek_next(sys_snode_t *node)
{
	return node ? sys_slist_peek_next_no_check(node) : 
		((void *)0)
		;
}
static inline void sys_slist_prepend(sys_slist_t *list,
		sys_snode_t *node)
{
	node->next = list->head;
	list->head = node;
	if (!list->tail) {
		list->tail = list->head;
	}
}
static inline void sys_slist_append(sys_slist_t *list,
		sys_snode_t *node)
{
	node->next = 
		((void *)0)
		;
	if (!list->tail) {
		list->tail = node;
		list->head = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
}
static inline void sys_slist_append_list(sys_slist_t *list,
		void *head, void *tail)
{
	if (!list->tail) {
		list->head = (sys_snode_t *)head;
		list->tail = (sys_snode_t *)tail;
	} else {
		list->tail->next = (sys_snode_t *)head;
		list->tail = (sys_snode_t *)tail;
	}
}
static inline void sys_slist_merge_slist(sys_slist_t *list,
		sys_slist_t *list_to_append)
{
	sys_slist_append_list(list, list_to_append->head,
			list_to_append->tail);
	sys_slist_init(list_to_append);
}
static inline void sys_slist_insert(sys_slist_t *list,
		sys_snode_t *prev,
		sys_snode_t *node)
{
	if (!prev) {
		sys_slist_prepend(list, node);
	} else if (!prev->next) {
		sys_slist_append(list, node);
	} else {
		node->next = prev->next;
		prev->next = node;
	}
}
static inline sys_snode_t *sys_slist_get_not_empty(sys_slist_t *list)
{
	sys_snode_t *node = list->head;
	list->head = node->next;
	if (list->tail == node) {
		list->tail = list->head;
	}
	return node;
}
static inline sys_snode_t *sys_slist_get(sys_slist_t *list)
{
	return sys_slist_is_empty(list) ? 
		((void *)0) 
		: sys_slist_get_not_empty(list);
}
static inline void sys_slist_remove(sys_slist_t *list,
		sys_snode_t *prev_node,
		sys_snode_t *node)
{
	if (!prev_node) {
		list->head = node->next;
		if (list->tail == node) {
			list->tail = list->head;
		}
	} else {
		prev_node->next = node->next;
		if (list->tail == node) {
			list->tail = prev_node;
		}
	}
	node->next = 
		((void *)0)
		;
}
static inline 
	_Bool 
sys_slist_find_and_remove(sys_slist_t *list,
		sys_snode_t *node)
{
	sys_snode_t *prev = 
		((void *)0)
		;
	sys_snode_t *test;
	for (test = sys_slist_peek_head(list); test; test = sys_slist_peek_next(test)) {
		if (test == node) {
			sys_slist_remove(list, prev, node);
			return 
				1
				;
		}
		prev = test;
	}
	return 
		0
		;
}
struct _dnode {
	union {
		struct _dnode *head;
		struct _dnode *next;
	};
	union {
		struct _dnode *tail;
		struct _dnode *prev;
	};
};
typedef struct _dnode sys_dlist_t;
typedef struct _dnode sys_dnode_t;
static inline void sys_dlist_init(sys_dlist_t *list)
{
	list->head = (sys_dnode_t *)list;
	list->tail = (sys_dnode_t *)list;
}
static inline int sys_dlist_is_head(sys_dlist_t *list, sys_dnode_t *node)
{
	return list->head == node;
}
static inline int sys_dlist_is_tail(sys_dlist_t *list, sys_dnode_t *node)
{
	return list->tail == node;
}
static inline int sys_dlist_is_empty(sys_dlist_t *list)
{
	return list->head == list;
}
static inline int sys_dlist_has_multiple_nodes(sys_dlist_t *list)
{
	return list->head != list->tail;
}
static inline sys_dnode_t *sys_dlist_peek_head(sys_dlist_t *list)
{
	return sys_dlist_is_empty(list) ? 
		((void *)0) 
		: list->head;
}
static inline sys_dnode_t *sys_dlist_peek_head_not_empty(sys_dlist_t *list)
{
	return list->head;
}
static inline sys_dnode_t *sys_dlist_peek_next_no_check(sys_dlist_t *list,
		sys_dnode_t *node)
{
	return (node == list->tail) ? 
		((void *)0) 
		: node->next;
}
static inline sys_dnode_t *sys_dlist_peek_next(sys_dlist_t *list,
		sys_dnode_t *node)
{
	return node ? sys_dlist_peek_next_no_check(list, node) : 
		((void *)0)
		;
}
static inline sys_dnode_t *sys_dlist_peek_tail(sys_dlist_t *list)
{
	return sys_dlist_is_empty(list) ? 
		((void *)0) 
		: list->tail;
}
static inline void sys_dlist_append(sys_dlist_t *list, sys_dnode_t *node)
{
	node->next = list;
	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
}
static inline void sys_dlist_prepend(sys_dlist_t *list, sys_dnode_t *node)
{
	node->next = list->head;
	node->prev = list;
	list->head->prev = node;
	list->head = node;
}
static inline void sys_dlist_insert_after(sys_dlist_t *list,
		sys_dnode_t *insert_point, sys_dnode_t *node)
{
	if (!insert_point) {
		sys_dlist_prepend(list, node);
	} else {
		node->next = insert_point->next;
		node->prev = insert_point;
		insert_point->next->prev = node;
		insert_point->next = node;
	}
}
static inline void sys_dlist_insert_before(sys_dlist_t *list,
		sys_dnode_t *insert_point, sys_dnode_t *node)
{
	if (!insert_point) {
		sys_dlist_append(list, node);
	} else {
		node->prev = insert_point->prev;
		node->next = insert_point;
		insert_point->prev->next = node;
		insert_point->prev = node;
	}
}
static inline void sys_dlist_insert_at(sys_dlist_t *list, sys_dnode_t *node,
		int (*cond)(sys_dnode_t *, void *), void *data)
{
	if (sys_dlist_is_empty(list)) {
		sys_dlist_append(list, node);
	} else {
		sys_dnode_t *pos = sys_dlist_peek_head(list);
		while (pos && !cond(pos, data)) {
			pos = sys_dlist_peek_next(list, pos);
		}
		sys_dlist_insert_before(list, pos, node);
	}
}
static inline void sys_dlist_remove(sys_dnode_t *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}
static inline sys_dnode_t *sys_dlist_get(sys_dlist_t *list)
{
	sys_dnode_t *node;
	if (sys_dlist_is_empty(list)) {
		return 
			((void *)0)
			;
	}
	node = list->head;
	sys_dlist_remove(node);
	return node;
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
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t;
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
void __assert (const char *, int, const char *) __attribute__ ((__noreturn__))
	;
void __assert_func (const char *, int, const char *, const char *) __attribute__ ((__noreturn__))
	;
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
	typedef char name_t;
	typedef uint32_t sem_count_t;
	typedef uint32_t cpu_stack_t;
	typedef uint32_t hr_timer_t;
	typedef uint32_t lr_timer_t;
	typedef uint32_t mutex_nested_t;
	typedef uint8_t suspend_nested_t;
	typedef uint64_t ctx_switch_t;
	typedef uint32_t cpu_cpsr_t;
	typedef aos_queue_t _queue_t;
	typedef aos_sem_t _sem_t;
	typedef aos_task_t _task_t;
	typedef cpu_stack_t _stack_element_t;
	typedef aos_mutex_t _mutex_t;
	enum {
		LOG_LEVEL_NONE = 0,
		LOG_LEVEL_FATAL,
		LOG_LEVEL_ERROR,
		LOG_LEVEL_WARN,
		LOG_LEVEL_INFO,
		LOG_LEVEL_DEBUG,
		LOG_LEVEL_MAX_BIT
	};
typedef sys_dlist_t _wait_q_t;
struct k_queue {
	_queue_t *_queue;
	sys_dlist_t poll_events;
};
extern void k_queue_init(struct k_queue *queue);
extern void k_queue_cancel_wait(struct k_queue *queue);
extern void k_queue_append(struct k_queue *queue, void *data);
extern void k_queue_prepend(struct k_queue *queue, void *data);
extern void k_queue_insert(struct k_queue *queue, void *prev, void *data);
extern void k_queue_append_list(struct k_queue *queue, void *head, void *tail);
extern void *k_queue_get(struct k_queue *queue, s32_t timeout);
extern int k_queue_is_empty(struct k_queue *queue);
struct k_lifo {
	struct k_queue _queue;
};
struct k_fifo {
	struct k_queue _queue;
};
struct k_sem {
	_sem_t sem;
	sys_dlist_t poll_events;
};
int k_sem_init(struct k_sem *sem, unsigned int initial_count, unsigned int limit);
int k_sem_take(struct k_sem *sem, uint32_t timeout);
int k_sem_give(struct k_sem *sem);
int k_sem_delete(struct k_sem *sem);
unsigned int k_sem_count_get(struct k_sem *sem);
struct k_mutex {
	_mutex_t mutex;
	sys_dlist_t poll_events;
};
typedef void (*k_timer_handler_t)(void *timer, void *args);
typedef struct k_timer {
	aos_timer_t timer;
	k_timer_handler_t handler;
	void *args;
	uint32_t timeout;
	uint32_t start_ms;
} k_timer_t;
void k_timer_init(k_timer_t *timer, k_timer_handler_t handle, void *args);
void k_timer_start(k_timer_t *timer, uint32_t timeout);
void k_timer_stop(k_timer_t *timer);
int64_t k_uptime_get();
inline u32_t k_uptime_get_32(void)
{
	return (u32_t)aos_now_ms();
}
struct k_thread {
	_task_t task;
};
typedef _stack_element_t k_thread_stack_t;
inline void k_call_stacks_analyze(void) { }
static inline char *K_THREAD_STACK_BUFFER(k_thread_stack_t *sym)
{
	return (char *)sym;
}
typedef void (*k_thread_entry_t)(void *p1, void *p2, void *p3);
int k_thread_create(struct k_thread *new_thread, k_thread_stack_t *stack,
		size_t stack_size, k_thread_entry_t entry,
		void *p1, void *p2, void *p3,
		int prio, u32_t options, s32_t delay);
int k_yield();
unsigned int irq_lock();
void irq_unlock(unsigned int key);
typedef int atomic_t;
typedef atomic_t atomic_val_t;
extern int atomic_cas(atomic_t *target, atomic_val_t old_value,
		atomic_val_t new_value);
extern atomic_val_t atomic_add(atomic_t *target, atomic_val_t value);
extern atomic_val_t atomic_sub(atomic_t *target, atomic_val_t value);
extern atomic_val_t atomic_inc(atomic_t *target);
extern atomic_val_t atomic_dec(atomic_t *target);
extern atomic_val_t atomic_get(const atomic_t *target);
extern atomic_val_t atomic_set(atomic_t *target, atomic_val_t value);
extern atomic_val_t atomic_clear(atomic_t *target);
extern atomic_val_t atomic_or(atomic_t *target, atomic_val_t value);
extern atomic_val_t atomic_xor(atomic_t *target, atomic_val_t value);
extern atomic_val_t atomic_and(atomic_t *target, atomic_val_t value);
extern atomic_val_t atomic_nand(atomic_t *target, atomic_val_t value);
static inline int atomic_test_bit(const atomic_t *target, int bit)
{
	atomic_val_t val = atomic_get(((target) + ((bit) / (sizeof(atomic_val_t) * 8))));
	return (1 & (val >> (bit & ((sizeof(atomic_val_t) * 8) - 1))));
}
static inline int atomic_test_and_clear_bit(atomic_t *target, int bit)
{
	atomic_val_t mask = (1 << ((bit) & ((sizeof(atomic_val_t) * 8) - 1)));
	atomic_val_t old;
	old = atomic_and(((target) + ((bit) / (sizeof(atomic_val_t) * 8))), ~mask);
	return (old & mask) != 0;
}
static inline int atomic_test_and_set_bit(atomic_t *target, int bit)
{
	atomic_val_t mask = (1 << ((bit) & ((sizeof(atomic_val_t) * 8) - 1)));
	atomic_val_t old;
	old = atomic_or(((target) + ((bit) / (sizeof(atomic_val_t) * 8))), mask);
	return (old & mask) != 0;
}
static inline void atomic_clear_bit(atomic_t *target, int bit)
{
	atomic_val_t mask = (1 << ((bit) & ((sizeof(atomic_val_t) * 8) - 1)));
	atomic_and(((target) + ((bit) / (sizeof(atomic_val_t) * 8))), ~mask);
}
static inline void atomic_set_bit(atomic_t *target, int bit)
{
	atomic_val_t mask = (1 << ((bit) & ((sizeof(atomic_val_t) * 8) - 1)));
	atomic_or(((target) + ((bit) / (sizeof(atomic_val_t) * 8))), mask);
}
struct k_work_q {
	struct k_fifo fifo;
};
int k_work_q_start();
enum {
	K_WORK_STATE_PENDING,
};
struct k_work;
typedef void (*k_work_handler_t)(struct k_work *work);
struct k_work {
	void *_reserved;
	k_work_handler_t handler;
	atomic_t flags[1];
};
int k_work_init(struct k_work *work, k_work_handler_t handler);
void k_work_submit(struct k_work *work);
struct k_delayed_work {
	struct k_work work;
	struct k_work_q *work_q;
	k_timer_t timer;
};
void k_delayed_work_init(struct k_delayed_work *work, k_work_handler_t handler);
int k_delayed_work_submit(struct k_delayed_work *work, uint32_t delay);
int k_delayed_work_cancel(struct k_delayed_work *work);
s32_t k_delayed_work_remaining_get(struct k_delayed_work *work);
enum _poll_types_bits {
	_POLL_TYPE_IGNORE,
	_POLL_TYPE_SIGNAL,
	_POLL_TYPE_SEM_AVAILABLE,
	_POLL_TYPE_DATA_AVAILABLE,
	_POLL_NUM_TYPES
};
enum _poll_states_bits {
	_POLL_STATE_NOT_READY,
	_POLL_STATE_SIGNALED,
	_POLL_STATE_SEM_AVAILABLE,
	_POLL_STATE_DATA_AVAILABLE,
	_POLL_NUM_STATES
};
struct k_poll_event {
	sys_dnode_t _node;
	struct _poller *poller;
	u32_t tag:8;
	u32_t type:_POLL_NUM_TYPES;
	u32_t state:_POLL_NUM_STATES;
	u32_t mode:1;
	u32_t unused:(32 - (0 + 8 + _POLL_NUM_TYPES + _POLL_NUM_STATES + 1 ));
	union {
		void *obj;
		struct k_poll_signal *signal;
		struct k_sem *sem;
		struct k_fifo *fifo;
		struct k_queue *queue;
	};
};
struct k_poll_signal {
	sys_dlist_t poll_events;
	unsigned int signaled;
	int result;
};
extern int k_poll_signal(struct k_poll_signal *signal, int result);
extern int k_poll(struct k_poll_event *events, int num_events, s32_t timeout);
extern void k_poll_event_init(struct k_poll_event *event, u32_t type, int mode, void *obj);
enum k_poll_modes {
	K_POLL_MODE_NOTIFY_ONLY = 0,
	K_POLL_NUM_MODES
};
void k_sleep(s32_t duration);
unsigned int find_msb_set(u32_t op);
unsigned int find_lsb_set(u32_t op);
static inline int is_power_of_two(unsigned int x)
{
	return (x != 0) && !(x & (x - 1));
}
static inline s64_t arithmetic_shift_right(s64_t value, u8_t shift)
{
	s64_t sign_ext;
	if (shift == 0) {
		return value;
	}
	sign_ext = (value >> 63) & 1;
	sign_ext = -sign_ext;
	return (value >> shift) | (sign_ext << (64 - shift));
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
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
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
struct net_buf_simple {
	u8_t *data;
	u16_t len;
	u16_t size;
	u8_t __buf[0] 
		__attribute__((__aligned__(
						sizeof(int)
					  )))
		;
};
static inline void net_buf_simple_init(struct net_buf_simple *buf,
		size_t reserve_head)
{
	buf->data = buf->__buf + reserve_head;
	buf->len = 0;
}
void *net_buf_simple_add(struct net_buf_simple *buf, size_t len);
void *net_buf_simple_add_mem(struct net_buf_simple *buf, const void *mem,
		size_t len);
u8_t *net_buf_simple_add_u8(struct net_buf_simple *buf, u8_t val);
void net_buf_simple_add_le16(struct net_buf_simple *buf, u16_t val);
void net_buf_simple_add_be16(struct net_buf_simple *buf, u16_t val);
void net_buf_simple_add_le32(struct net_buf_simple *buf, u32_t val);
void net_buf_simple_add_be32(struct net_buf_simple *buf, u32_t val);
void *net_buf_simple_push(struct net_buf_simple *buf, size_t len);
void net_buf_simple_push_le16(struct net_buf_simple *buf, u16_t val);
void net_buf_simple_push_be16(struct net_buf_simple *buf, u16_t val);
void net_buf_simple_push_u8(struct net_buf_simple *buf, u8_t val);
void *net_buf_simple_pull(struct net_buf_simple *buf, size_t len);
u8_t net_buf_simple_pull_u8(struct net_buf_simple *buf);
u16_t net_buf_simple_pull_le16(struct net_buf_simple *buf);
u16_t net_buf_simple_pull_be16(struct net_buf_simple *buf);
u32_t net_buf_simple_pull_le32(struct net_buf_simple *buf);
u32_t net_buf_simple_pull_be32(struct net_buf_simple *buf);
static inline u8_t *net_buf_simple_tail(struct net_buf_simple *buf)
{
	return buf->data + buf->len;
}
size_t net_buf_simple_headroom(struct net_buf_simple *buf);
size_t net_buf_simple_tailroom(struct net_buf_simple *buf);
struct net_buf_simple_state {
	u16_t offset;
	u16_t len;
};
static inline void net_buf_simple_save(struct net_buf_simple *buf,
		struct net_buf_simple_state *state)
{
	state->offset = net_buf_simple_headroom(buf);
	state->len = buf->len;
}
static inline void net_buf_simple_restore(struct net_buf_simple *buf,
		struct net_buf_simple_state *state)
{
	buf->data = buf->__buf + state->offset;
	buf->len = state->len;
}
struct net_buf {
	union {
		sys_snode_t node;
		struct net_buf *frags;
	};
	u8_t ref;
	u8_t flags;
	u8_t pool_id;
	union {
		struct {
			u8_t *data;
			u16_t len;
			u16_t size;
		};
		struct net_buf_simple b;
	};
	u8_t __buf[0] 
		__attribute__((__aligned__(
						sizeof(int)
					  )))
		;
};
struct net_buf_pool {
	struct k_lifo free;
	const u16_t buf_count;
	u16_t uninit_count;
	const u16_t buf_size;
	const u16_t user_data_size;
	void (*const destroy)(struct net_buf *buf);
	struct net_buf * const __bufs;
};
struct net_buf_pool *net_buf_pool_get(int id);
int net_buf_id(struct net_buf *buf);
struct net_buf *net_buf_alloc(struct net_buf_pool *pool, s32_t timeout);
struct net_buf *net_buf_get(struct k_fifo *fifo, s32_t timeout);
static inline void net_buf_destroy(struct net_buf *buf)
{
	struct net_buf_pool *pool = net_buf_pool_get(buf->pool_id);
	k_queue_prepend((struct k_queue *) &pool->free, buf);
}
void net_buf_reset(struct net_buf *buf);
void net_buf_reserve(struct net_buf *buf, size_t reserve);
void net_buf_slist_put(sys_slist_t *list, struct net_buf *buf);
struct net_buf *net_buf_slist_get(sys_slist_t *list);
void net_buf_put(struct k_fifo *fifo, struct net_buf *buf);
void net_buf_unref(struct net_buf *buf);
struct net_buf *net_buf_ref(struct net_buf *buf);
struct net_buf *net_buf_clone(struct net_buf *buf, s32_t timeout);
static inline void *net_buf_user_data(struct net_buf *buf)
{
	return (void *)(((unsigned long)((buf->__buf + buf->size)) + ((unsigned long)sizeof(int) - 1)) & ~((unsigned long)sizeof(int) - 1));
}
struct net_buf *net_buf_frag_last(struct net_buf *frags);
void net_buf_frag_insert(struct net_buf *parent, struct net_buf *frag);
struct net_buf *net_buf_frag_add(struct net_buf *head, struct net_buf *frag);
struct net_buf *net_buf_frag_del(struct net_buf *parent, struct net_buf *frag);
static inline size_t net_buf_frags_len(struct net_buf *buf)
{
	size_t bytes = 0;
	while (buf) {
		bytes += buf->len;
		buf = buf->frags;
	}
	return bytes;
}
typedef struct {
	u8_t val[6];
} bt_addr_t;
typedef struct {
	u8_t type;
	bt_addr_t a;
} bt_addr_le_t;
static inline int bt_addr_cmp(const bt_addr_t *a, const bt_addr_t *b)
{
	return memcmp(a, b, sizeof(*a));
}
static inline int bt_addr_le_cmp(const bt_addr_le_t *a, const bt_addr_le_t *b)
{
	return memcmp(a, b, sizeof(*a));
}
static inline void bt_addr_copy(bt_addr_t *dst, const bt_addr_t *src)
{
	memcpy(dst, src, sizeof(*dst));
}
static inline void bt_addr_le_copy(bt_addr_le_t *dst, const bt_addr_le_t *src)
{
	memcpy(dst, src, sizeof(*dst));
}
int bt_addr_le_create_nrpa(bt_addr_le_t *addr);
int bt_addr_le_create_static(bt_addr_le_t *addr);
static inline 
	_Bool 
bt_addr_le_is_rpa(const bt_addr_le_t *addr)
{
	if (addr->type != 0x01) {
		return 
			0
			;
	}
	return (((&addr->a)->val[5] & 0xc0) == 0x40);
}
static inline 
	_Bool 
bt_addr_le_is_identity(const bt_addr_le_t *addr)
{
	if (addr->type == 0x00) {
		return 
			1
			;
	}
	return (((&addr->a)->val[5] & 0xc0) == 0xc0);
}
struct bt_hci_evt_hdr {
	u8_t evt;
	u8_t len;
} 
__attribute__((__packed__))
	;
	struct bt_hci_acl_hdr {
		u16_t handle;
		u16_t len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cmd_hdr {
		u16_t opcode;
		u8_t param_len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_op_inquiry {
		u8_t lap[3];
		u8_t length;
		u8_t num_rsp;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_connect {
		bt_addr_t bdaddr;
		u16_t packet_type;
		u8_t pscan_rep_mode;
		u8_t reserved;
		u16_t clock_offset;
		u8_t allow_role_switch;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_disconnect {
		u16_t handle;
		u8_t reason;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_connect_cancel {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_connect_cancel {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_accept_conn_req {
		bt_addr_t bdaddr;
		u8_t role;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_setup_sync_conn {
		u16_t handle;
		u32_t tx_bandwidth;
		u32_t rx_bandwidth;
		u16_t max_latency;
		u16_t content_format;
		u8_t retrans_effort;
		u16_t pkt_type;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_accept_sync_conn_req {
		bt_addr_t bdaddr;
		u32_t tx_bandwidth;
		u32_t rx_bandwidth;
		u16_t max_latency;
		u16_t content_format;
		u8_t retrans_effort;
		u16_t pkt_type;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_reject_conn_req {
		bt_addr_t bdaddr;
		u8_t reason;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_link_key_reply {
		bt_addr_t bdaddr;
		u8_t link_key[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_link_key_neg_reply {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_pin_code_reply {
		bt_addr_t bdaddr;
		u8_t pin_len;
		u8_t pin_code[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_pin_code_reply {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_pin_code_neg_reply {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_pin_code_neg_reply {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_auth_requested {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_set_conn_encrypt {
		u16_t handle;
		u8_t encrypt;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_remote_name_request {
		bt_addr_t bdaddr;
		u8_t pscan_rep_mode;
		u8_t reserved;
		u16_t clock_offset;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_remote_name_cancel {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_remote_name_cancel {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_remote_features {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_remote_ext_features {
		u16_t handle;
		u8_t page;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_remote_version_info {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_io_capability_reply {
		bt_addr_t bdaddr;
		u8_t capability;
		u8_t oob_data;
		u8_t authentication;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_user_confirm_reply {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_user_confirm_reply {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_user_passkey_reply {
		bt_addr_t bdaddr;
		u32_t passkey;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_user_passkey_neg_reply {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_io_capability_neg_reply {
		bt_addr_t bdaddr;
		u8_t reason;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_set_event_mask {
		u8_t events[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_write_local_name {
		u8_t local_name[248];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_tx_power_level {
		u16_t handle;
		u8_t type;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_tx_power_level {
		u8_t status;
		u16_t handle;
		s8_t tx_power_level;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_set_ctl_to_host_flow {
		u8_t flow_enable;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_host_buffer_size {
		u16_t acl_mtu;
		u8_t sco_mtu;
		u16_t acl_pkts;
		u16_t sco_pkts;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_handle_count {
		u16_t handle;
		u16_t count;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_host_num_completed_packets {
		u8_t num_handles;
		struct bt_hci_handle_count h[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_write_inquiry_mode {
		u8_t mode;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_write_ssp_mode {
		u8_t mode;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_set_event_mask_page_2 {
		u8_t events_page_2[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_write_le_host_supp {
		u8_t le;
		u8_t simul;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_write_sc_host_supp {
		u8_t sc_support;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_auth_payload_timeout {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_auth_payload_timeout {
		u8_t status;
		u16_t handle;
		u16_t auth_payload_timeout;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_write_auth_payload_timeout {
		u16_t handle;
		u16_t auth_payload_timeout;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_write_auth_payload_timeout {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_local_version_info {
		u8_t status;
		u8_t hci_version;
		u16_t hci_revision;
		u8_t lmp_version;
		u16_t manufacturer;
		u16_t lmp_subversion;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_supported_commands {
		u8_t status;
		u8_t commands[64];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_local_ext_features {
		u8_t page;
	};
struct bt_hci_rp_read_local_ext_features {
	u8_t status;
	u8_t page;
	u8_t max_page;
	u8_t ext_features[8];
} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_local_features {
		u8_t status;
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_buffer_size {
		u8_t status;
		u16_t acl_max_len;
		u8_t sco_max_len;
		u16_t acl_max_num;
		u16_t sco_max_num;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_bd_addr {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_rssi {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_rssi {
		u8_t status;
		u16_t handle;
		s8_t rssi;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_read_encryption_key_size {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_read_encryption_key_size {
		u8_t status;
		u16_t handle;
		u8_t key_size;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_event_mask {
		u8_t events[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_buffer_size {
		u8_t status;
		u16_t le_max_len;
		u8_t le_max_num;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_local_features {
		u8_t status;
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_random_address {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_adv_param {
		u16_t min_interval;
		u16_t max_interval;
		u8_t type;
		u8_t own_addr_type;
		bt_addr_le_t direct_addr;
		u8_t channel_map;
		u8_t filter_policy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_chan_tx_power {
		u8_t status;
		s8_t tx_power_level;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_adv_data {
		u8_t len;
		u8_t data[31];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_scan_rsp_data {
		u8_t len;
		u8_t data[31];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_adv_enable {
		u8_t enable;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_scan_param {
		u8_t scan_type;
		u16_t interval;
		u16_t window;
		u8_t addr_type;
		u8_t filter_policy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_scan_enable {
		u8_t enable;
		u8_t filter_dup;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_create_conn {
		u16_t scan_interval;
		u16_t scan_window;
		u8_t filter_policy;
		bt_addr_le_t peer_addr;
		u8_t own_addr_type;
		u16_t conn_interval_min;
		u16_t conn_interval_max;
		u16_t conn_latency;
		u16_t supervision_timeout;
		u16_t min_ce_len;
		u16_t max_ce_len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_wl_size {
		u8_t status;
		u8_t wl_size;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_add_dev_to_wl {
		bt_addr_le_t addr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_rem_dev_from_wl {
		bt_addr_le_t addr;
	} 
__attribute__((__packed__))
	;
	struct hci_cp_le_conn_update {
		u16_t handle;
		u16_t conn_interval_min;
		u16_t conn_interval_max;
		u16_t conn_latency;
		u16_t supervision_timeout;
		u16_t min_ce_len;
		u16_t max_ce_len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_host_chan_classif {
		u8_t ch_map[5];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_read_chan_map {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_chan_map {
		u8_t status;
		u16_t handle;
		u8_t ch_map[5];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_read_remote_features {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_encrypt {
		u8_t key[16];
		u8_t plaintext[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_encrypt {
		u8_t status;
		u8_t enc_data[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_rand {
		u8_t status;
		u8_t rand[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_start_encryption {
		u16_t handle;
		u64_t rand;
		u16_t ediv;
		u8_t ltk[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_ltk_req_reply {
		u16_t handle;
		u8_t ltk[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_ltk_req_reply {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_ltk_req_neg_reply {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_ltk_req_neg_reply {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_supp_states {
		u8_t status;
		u8_t le_states[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_rx_test {
		u8_t rx_ch;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_tx_test {
		u8_t tx_ch;
		u8_t test_data_len;
		u8_t pkt_payload;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_test_end {
		u8_t status;
		u16_t rx_pkt_count;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_conn_param_req_reply {
		u16_t handle;
		u16_t interval_min;
		u16_t interval_max;
		u16_t latency;
		u16_t timeout;
		u16_t min_ce_len;
		u16_t max_ce_len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_conn_param_req_reply {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_conn_param_req_neg_reply {
		u16_t handle;
		u8_t reason;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_conn_param_req_neg_reply {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_data_len {
		u16_t handle;
		u16_t tx_octets;
		u16_t tx_time;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_set_data_len {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_default_data_len {
		u8_t status;
		u16_t max_tx_octets;
		u16_t max_tx_time;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_write_default_data_len {
		u16_t max_tx_octets;
		u16_t max_tx_time;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_generate_dhkey {
		u8_t key[64];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_add_dev_to_rl {
		bt_addr_le_t peer_id_addr;
		u8_t peer_irk[16];
		u8_t local_irk[16];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_rem_dev_from_rl {
		bt_addr_le_t peer_id_addr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_rl_size {
		u8_t status;
		u8_t rl_size;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_read_peer_rpa {
		bt_addr_le_t peer_id_addr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_peer_rpa {
		u8_t status;
		bt_addr_t peer_rpa;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_read_local_rpa {
		bt_addr_le_t peer_id_addr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_local_rpa {
		u8_t status;
		bt_addr_t local_rpa;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_addr_res_enable {
		u8_t enable;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_rpa_timeout {
		u16_t rpa_timeout;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_max_data_len {
		u8_t status;
		u16_t max_tx_octets;
		u16_t max_tx_time;
		u16_t max_rx_octets;
		u16_t max_rx_time;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_read_phy {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_phy {
		u8_t status;
		u16_t handle;
		u8_t tx_phy;
		u8_t rx_phy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_default_phy {
		u8_t all_phys;
		u8_t tx_phys;
		u8_t rx_phys;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_phy {
		u16_t handle;
		u8_t all_phys;
		u8_t tx_phys;
		u8_t rx_phys;
		u16_t phy_opts;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_enh_rx_test {
		u8_t rx_ch;
		u8_t phy;
		u8_t mod_index;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_enh_tx_test {
		u8_t tx_ch;
		u8_t test_data_len;
		u8_t pkt_payload;
		u8_t phy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_adv_set_random_addr {
		u8_t handle;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_ext_adv_param {
		u8_t handle;
		u16_t props;
		u8_t prim_min_interval[3];
		u8_t prim_max_interval[3];
		u8_t prim_channel_map;
		u8_t own_addr_type;
		bt_addr_le_t peer_addr;
		u8_t filter_policy;
		s8_t tx_power;
		u8_t prim_adv_phy;
		u8_t sec_adv_max_skip;
		u8_t sec_adv_phy;
		u8_t sid;
		u8_t scan_req_notify_enable;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_set_ext_adv_param {
		u8_t status;
		s8_t tx_power;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_ext_adv_data {
		u8_t handle;
		u8_t op;
		u8_t frag_pref;
		u8_t len;
		u8_t data[251];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_ext_scan_rsp_data {
		u8_t handle;
		u8_t op;
		u8_t frag_pref;
		u8_t len;
		u8_t data[251];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_ext_adv_set {
		u8_t handle;
		u16_t duration;
		u8_t max_ext_adv_evts;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_ext_adv_enable {
		u8_t enable;
		u8_t set_num;
		struct bt_hci_ext_adv_set s[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_max_adv_data_len {
		u8_t status;
		u16_t max_adv_data_len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_num_adv_sets {
		u8_t status;
		u8_t num_sets;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_remove_adv_set {
		u8_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_per_adv_param {
		u8_t handle;
		u16_t min_interval;
		u16_t max_interval;
		u16_t props;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_per_adv_data {
		u8_t handle;
		u8_t op;
		u8_t len;
		u8_t data[251];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_per_adv_enable {
		u8_t enable;
		u8_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_ext_scan_phy {
		u8_t type;
		u16_t interval;
		u16_t window;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_ext_scan_param {
		u8_t own_addr_type;
		u8_t filter_policy;
		u8_t phys;
		struct bt_hci_ext_scan_phy p[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_ext_scan_enable {
		u8_t enable;
		u8_t filter_dup;
		u16_t duration;
		u16_t period;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_ext_conn_phy {
		u16_t interval;
		u16_t window;
		u16_t conn_interval_min;
		u16_t conn_interval_max;
		u16_t conn_latency;
		u16_t supervision_timeout;
		u16_t min_ce_len;
		u16_t max_ce_len;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_ext_create_conn {
		u8_t filter_policy;
		u8_t own_addr_type;
		bt_addr_le_t peer_addr;
		u8_t phys;
		struct bt_hci_ext_conn_phy p[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_per_adv_create_sync {
		u8_t filter_policy;
		u8_t sid;
		bt_addr_le_t addr;
		u16_t skip;
		u16_t sync_timeout;
		u8_t unused;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_per_adv_terminate_sync {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_add_dev_to_per_adv_list {
		bt_addr_le_t addr;
		u8_t sid;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_rem_dev_from_per_adv_list {
		bt_addr_le_t addr;
		u8_t sid;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_per_adv_list_size {
		u8_t status;
		u8_t list_size;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_tx_power {
		u8_t status;
		s8_t min_tx_power;
		s8_t max_tx_power;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_rp_le_read_rf_path_comp {
		u8_t status;
		s16_t tx_path_comp;
		s16_t rx_path_comp;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_write_rf_path_comp {
		s16_t tx_path_comp;
		s16_t rx_path_comp;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_cp_le_set_privacy_mode {
		bt_addr_le_t id_addr;
		u8_t mode;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_inquiry_complete {
		u8_t status;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_conn_complete {
		u8_t status;
		u16_t handle;
		bt_addr_t bdaddr;
		u8_t link_type;
		u8_t encr_enabled;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_conn_request {
		bt_addr_t bdaddr;
		u8_t dev_class[3];
		u8_t link_type;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_disconn_complete {
		u8_t status;
		u16_t handle;
		u8_t reason;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_auth_complete {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_remote_name_req_complete {
		u8_t status;
		bt_addr_t bdaddr;
		u8_t name[248];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_encrypt_change {
		u8_t status;
		u16_t handle;
		u8_t encrypt;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_remote_features {
		u8_t status;
		u16_t handle;
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_remote_version_info {
		u8_t status;
		u16_t handle;
		u8_t version;
		u16_t manufacturer;
		u16_t subversion;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_cmd_complete {
		u8_t ncmd;
		u16_t opcode;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_cc_status {
		u8_t status;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_cmd_status {
		u8_t status;
		u8_t ncmd;
		u16_t opcode;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_role_change {
		u8_t status;
		bt_addr_t bdaddr;
		u8_t role;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_num_completed_packets {
		u8_t num_handles;
		struct bt_hci_handle_count h[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_pin_code_req {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_link_key_req {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_link_key_notify {
		bt_addr_t bdaddr;
		u8_t link_key[16];
		u8_t key_type;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_data_buf_overflow {
		u8_t link_type;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_inquiry_result_with_rssi {
		bt_addr_t addr;
		u8_t pscan_rep_mode;
		u8_t reserved;
		u8_t cod[3];
		u16_t clock_offset;
		s8_t rssi;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_remote_ext_features {
		u8_t status;
		u16_t handle;
		u8_t page;
		u8_t max_page;
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_sync_conn_complete {
		u8_t status;
		u16_t handle;
		bt_addr_t bdaddr;
		u8_t link_type;
		u8_t tx_interval;
		u8_t retansmission_window;
		u16_t rx_pkt_length;
		u16_t tx_pkt_length;
		u8_t air_mode;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_extended_inquiry_result {
		u8_t num_reports;
		bt_addr_t addr;
		u8_t pscan_rep_mode;
		u8_t reserved;
		u8_t cod[3];
		u16_t clock_offset;
		s8_t rssi;
		u8_t eir[240];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_encrypt_key_refresh_complete {
		u8_t status;
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_io_capa_req {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_io_capa_resp {
		bt_addr_t bdaddr;
		u8_t capability;
		u8_t oob_data;
		u8_t authentication;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_user_confirm_req {
		bt_addr_t bdaddr;
		u32_t passkey;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_user_passkey_req {
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_ssp_complete {
		u8_t status;
		bt_addr_t bdaddr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_user_passkey_notify {
		bt_addr_t bdaddr;
		u32_t passkey;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_meta_event {
		u8_t subevent;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_auth_payload_timeout_exp {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_conn_complete {
		u8_t status;
		u16_t handle;
		u8_t role;
		bt_addr_le_t peer_addr;
		u16_t interval;
		u16_t latency;
		u16_t supv_timeout;
		u8_t clock_accuracy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_advertising_info {
		u8_t evt_type;
		bt_addr_le_t addr;
		u8_t length;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_advertising_report {
		u8_t num_reports;
		struct bt_hci_evt_le_advertising_info adv_info[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_conn_update_complete {
		u8_t status;
		u16_t handle;
		u16_t interval;
		u16_t latency;
		u16_t supv_timeout;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_remote_feat_complete {
		u8_t status;
		u16_t handle;
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_ltk_request {
		u16_t handle;
		u64_t rand;
		u16_t ediv;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_conn_param_req {
		u16_t handle;
		u16_t interval_min;
		u16_t interval_max;
		u16_t latency;
		u16_t timeout;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_data_len_change {
		u16_t handle;
		u16_t max_tx_octets;
		u16_t max_tx_time;
		u16_t max_rx_octets;
		u16_t max_rx_time;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_p256_public_key_complete {
		u8_t status;
		u8_t key[64];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_generate_dhkey_complete {
		u8_t status;
		u8_t dhkey[32];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_enh_conn_complete {
		u8_t status;
		u16_t handle;
		u8_t role;
		bt_addr_le_t peer_addr;
		bt_addr_t local_rpa;
		bt_addr_t peer_rpa;
		u16_t interval;
		u16_t latency;
		u16_t supv_timeout;
		u8_t clock_accuracy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_direct_adv_info {
		u8_t evt_type;
		bt_addr_le_t addr;
		bt_addr_le_t dir_addr;
		s8_t rssi;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_direct_adv_report {
		u8_t num_reports;
		struct bt_hci_evt_le_direct_adv_info direct_adv_info[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_phy_update_complete {
		u8_t status;
		u16_t handle;
		u8_t tx_phy;
		u8_t rx_phy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_ext_advertising_info {
		u8_t evt_type;
		bt_addr_le_t addr;
		u8_t prim_phy;
		u8_t sec_phy;
		u8_t sid;
		s8_t tx_power;
		s8_t rssi;
		u16_t interval;
		bt_addr_le_t direct_addr;
		u8_t length;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_ext_advertising_report {
		u8_t num_reports;
		struct bt_hci_evt_le_ext_advertising_info adv_info[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_per_adv_sync_established {
		u8_t status;
		u16_t handle;
		u8_t sid;
		bt_addr_le_t adv_addr;
		u8_t phy;
		u16_t interval;
		u8_t clock_accuracy;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_per_advertising_report {
		u16_t handle;
		s8_t tx_power;
		s8_t rssi;
		u8_t unused;
		u8_t data_status;
		u8_t length;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_per_adv_sync_lost {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_per_adv_set_terminated {
		u8_t status;
		u8_t adv_handle;
		u16_t conn_handle;
		u8_t num_completed_ext_adv_evts;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_scan_req_received {
		u8_t handle;
		bt_addr_le_t addr;
	} 
__attribute__((__packed__))
	;
	struct bt_hci_evt_le_chan_sel_algo {
		u16_t handle;
		u8_t chan_sel_algo;
	} 
__attribute__((__packed__))
	;
	int bt_rand(void *buf, size_t len);
	int bt_encrypt_le(const u8_t key[16], const u8_t plaintext[16],
			u8_t enc_data[16]);
int bt_encrypt_be(const u8_t key[16], const u8_t plaintext[16],
		u8_t enc_data[16]);
typedef void (*bt_ready_cb_t)(int err);
int bt_enable(bt_ready_cb_t cb);
struct bt_data {
	u8_t type;
	u8_t data_len;
	const u8_t *data;
};
enum {
	BT_LE_ADV_OPT_NONE = 0,
	BT_LE_ADV_OPT_CONNECTABLE = (1UL << (0)),
	BT_LE_ADV_OPT_ONE_TIME = (1UL << (1)),
};
struct bt_le_adv_param {
	u8_t options;
	u16_t interval_min;
	u16_t interval_max;
	const bt_addr_t *own_addr;
};
int bt_le_adv_start(const struct bt_le_adv_param *param,
		const struct bt_data *ad, size_t ad_len,
		const struct bt_data *sd, size_t sd_len);
int bt_le_adv_stop(void);
typedef void bt_le_scan_cb_t(const bt_addr_le_t *addr, s8_t rssi,
		u8_t adv_type, struct net_buf_simple *buf);
struct bt_le_scan_param {
	u8_t type;
	u8_t filter_dup;
	u16_t interval;
	u16_t window;
};
int bt_le_scan_start(const struct bt_le_scan_param *param, bt_le_scan_cb_t cb);
int bt_le_scan_stop(void);
struct bt_le_oob {
	bt_addr_le_t addr;
};
int bt_le_oob_get_local(struct bt_le_oob *oob);
struct bt_br_discovery_result {
	u8_t _priv[4];
	bt_addr_t addr;
	s8_t rssi;
	u8_t cod[3];
	u8_t eir[240];
};
typedef void bt_br_discovery_cb_t(struct bt_br_discovery_result *results,
		size_t count);
struct bt_br_discovery_param {
	u8_t length;
	_Bool 
		limited;
};
int bt_br_discovery_start(const struct bt_br_discovery_param *param,
		struct bt_br_discovery_result *results, size_t count,
		bt_br_discovery_cb_t cb);
int bt_br_discovery_stop(void);
struct bt_br_oob {
	bt_addr_t addr;
};
int bt_br_oob_get_local(struct bt_br_oob *oob);
static inline int bt_addr_to_str(const bt_addr_t *addr, char *str, size_t len)
{
	return snprintf(str, len, "%02X:%02X:%02X:%02X:%02X:%02X",
			addr->val[5], addr->val[4], addr->val[3],
			addr->val[2], addr->val[1], addr->val[0]);
}
static inline int bt_addr_le_to_str(const bt_addr_le_t *addr, char *str,
		size_t len)
{
	char type[10];
	switch (addr->type) {
		case 0x00:
			strcpy(type, "public");
			break;
		case 0x01:
			strcpy(type, "random");
			break;
		case 0x02:
			strcpy(type, "public id");
			break;
		case 0x03:
			strcpy(type, "random id");
			break;
		default:
			snprintf(type, sizeof(type), "0x%02x", addr->type);
			break;
	}
	return snprintf(str, len, "%02X:%02X:%02X:%02X:%02X:%02X (%s)",
			addr->a.val[5], addr->a.val[4], addr->a.val[3],
			addr->a.val[2], addr->a.val[1], addr->a.val[0], type);
}
int bt_br_set_discoverable(
		_Bool 
		enable);
int bt_br_set_connectable(
		_Bool 
		enable);
const char *bt_hex(const void *buf, size_t len);
const char *bt_addr_str(const bt_addr_t *addr);
const char *bt_addr_le_str(const bt_addr_le_t *addr);
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
typedef struct {
	uint8_t *buf;
	uint8_t *end;
	uint8_t *head;
	uint8_t *tail;
	size_t freesize;
	size_t type;
	size_t blk_size;
} k_ringbuf_t;
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
} kobj_list_t;
typedef struct sem_s {
	blk_obj_t blk_obj;
	sem_count_t count;
	sem_count_t peak_count;
	uint8_t mm_alloc_flag;
} ksem_t;
kstat_t krhino_sem_create(ksem_t *sem, const name_t *name, sem_count_t count);
kstat_t krhino_sem_del(ksem_t *sem);
kstat_t krhino_sem_give(ksem_t *sem);
kstat_t krhino_sem_give_all(ksem_t *sem);
kstat_t krhino_sem_take(ksem_t *sem, tick_t ticks);
kstat_t krhino_sem_count_set(ksem_t *sem, sem_count_t count);
kstat_t krhino_sem_count_get(ksem_t *sem, sem_count_t *count);
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
	uint8_t mm_alloc_flag;
} kqueue_t;
kstat_t krhino_queue_create(kqueue_t *queue, const name_t *name, void **start,
		size_t msg_num);
kstat_t krhino_queue_del(kqueue_t *queue);
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
kstat_t krhino_buf_queue_send(kbuf_queue_t *queue, void *msg, size_t size);
kstat_t krhino_buf_queue_recv(kbuf_queue_t *queue, tick_t ticks, void *msg,
		size_t *size);
kstat_t krhino_buf_queue_flush(kbuf_queue_t *queue);
kstat_t krhino_buf_queue_info_get(kbuf_queue_t *queue, kbuf_queue_info_t *info);
void krhino_tick_proc(void);
sys_time_t krhino_sys_time_get(void);
sys_time_t krhino_sys_tick_get(void);
tick_t krhino_ms_to_ticks(sys_time_t ms);
sys_time_t krhino_ticks_to_ms(tick_t ticks);
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
	cpu_stack_t *task_stack_base;
	uint32_t stack_size;
	klist_t task_list;
	struct mutex_s *mutex_list;
	klist_t tick_list;
	tick_t tick_match;
	tick_t tick_remain;
	klist_t *tick_head;
	void *msg;
	task_stat_t task_state;
	blk_state_t blk_state;
	blk_obj_t *blk_obj;
	uint8_t cpu_num;
	uint8_t prio;
	uint8_t b_prio;
	uint8_t mm_alloc_flag;
} ktask_t;
typedef void (*task_entry_t)(void *arg);
kstat_t krhino_task_create(ktask_t *task, const name_t *name, void *arg,
		uint8_t prio, tick_t ticks, cpu_stack_t *stack_buf,
		size_t stack_size, task_entry_t entry, uint8_t autorun);
kstat_t krhino_task_sleep(tick_t dly);
kstat_t krhino_task_yield(void);
ktask_t *krhino_cur_task_get(void);
kstat_t krhino_task_stack_min_free(ktask_t *task, size_t *free);
kstat_t krhino_task_stack_cur_free(ktask_t *task, size_t *free);
kstat_t krhino_task_pri_change(ktask_t *task, uint8_t pri, uint8_t *old_pri);
void krhino_task_deathbed(void);
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
void k_queue_init(struct k_queue *queue)
{
	void *msg_start;
	int size = 20;
	int stat;
	uint8_t blk_size = sizeof(void *) + 1;
	msg_start = (void *)aos_malloc(size * blk_size);
	((
	  msg_start
	 ) ? (void)0 : __assert_func ("kernel/protocols/bluetooth/port/aos_port.c", 44, __func__, 
		 "msg_start"
		 ))
		;
	queue->_queue = (aos_queue_t *)aos_malloc(sizeof(aos_queue_t));
	((
	  queue->_queue
	 ) ? (void)0 : __assert_func ("kernel/protocols/bluetooth/port/aos_port.c", 47, __func__, 
		 "queue->_queue"
		 ))
		;
	stat = aos_queue_new(queue->_queue, msg_start, size * blk_size, blk_size);
	((
	  stat == 0
	 ) ? (void)0 : __assert_func ("kernel/protocols/bluetooth/port/aos_port.c", 50, __func__, 
		 "stat == 0"
		 ))
		;
	sys_dlist_init(&queue->poll_events);
}
void k_queue_cancel_wait(struct k_queue *queue)
{
}
void k_queue_insert(struct k_queue *queue, void *prev, void *data)
{
	int ret;
	ret = aos_queue_send(queue->_queue, &data, sizeof(void *));
	((
	  ret == 0
	 ) ? (void)0 : __assert_func ("kernel/protocols/bluetooth/port/aos_port.c", 64, __func__, 
		 "ret == 0"
		 ))
		;
}
void k_queue_append(struct k_queue *queue, void *data)
{
	k_queue_insert(queue, 
			((void *)0)
			, data);
}
void k_queue_prepend(struct k_queue *queue, void *data)
{
	k_queue_insert(queue, 
			((void *)0)
			, data);
}
void k_queue_append_list(struct k_queue *queue, void *head, void *tail)
{
	struct net_buf *buf_tail = (struct net_buf *)head;
	for (buf_tail = (struct net_buf *)head; buf_tail; buf_tail = buf_tail->frags) {
		k_queue_append(queue, buf_tail);
	}
}
void *k_queue_get(struct k_queue *queue, s32_t timeout)
{
	void *msg = 
		((void *)0)
		;
	unsigned int t = timeout;
	unsigned int len;
	if (timeout == -1) {
		t = 0xffffffffu;
	} else if (timeout == 0) {
		t = 0x0;
	}
	if (0 == (aos_queue_recv(queue->_queue, t, &msg, &len))) {
		return msg;
	} else {
		return 
			((void *)0)
			;
	}
}
int k_queue_is_empty(struct k_queue *queue)
{
	kbuf_queue_t *k_queue = queue->_queue->hdl;
	return k_queue->cur_num ? 0 : 1;
	return 0;
}
int k_sem_init(struct k_sem *sem, unsigned int initial_count, unsigned int limit)
{
	int ret;
	if (
			((void *)0) 
			== sem) {
		;
		return -22;
	}
	ret = aos_sem_new(&sem->sem, initial_count);
	sys_dlist_init(&sem->poll_events);
	return ret;
}
int k_sem_take(struct k_sem *sem, uint32_t timeout)
{
	unsigned int t = timeout;
	if (timeout == -1) {
		t = 0xffffffffu;
	} else if (timeout == 0) {
		t = 0x0;
	}
	return aos_sem_wait(&sem->sem, t);
}
int k_sem_give(struct k_sem *sem)
{
	if (
			((void *)0) 
			== sem) {
		;
		return -22;
	}
	aos_sem_signal(&sem->sem);
	return 0;
}
int k_sem_delete(struct k_sem *sem)
{
	if (
			((void *)0) 
			== sem) {
		;
		return -22;
	}
	aos_sem_free(&sem->sem);
	return 0;
}
unsigned int k_sem_count_get(struct k_sem *sem)
{
	sem_count_t count;
	ksem_t *k_sem = (ksem_t *) & (sem->sem.hdl);
	krhino_sem_count_get(k_sem, &count);
	return (int)count;
	return 0;
}
void k_mutex_init(struct k_mutex *mutex)
{
	if (
			((void *)0) 
			== mutex) {
		;
		return ;
	}
	aos_mutex_new(&mutex->mutex);
	sys_dlist_init(&mutex->poll_events);
	return ;
}
int k_mutex_lock(struct k_mutex *mutex, s32_t timeout)
{
	unsigned int t = timeout;
	if (timeout == -1) {
		t = 0xffffffffu;
	} else if (timeout == 0) {
		t = 0x0;
	}
	return aos_mutex_lock(&mutex->mutex, t);
}
void k_mutex_unlock(struct k_mutex *mutex)
{
	if (
			((void *)0) 
			== mutex) {
		;
		return;
	}
	aos_mutex_unlock(&mutex->mutex);
	return ;
}
int64_t k_uptime_get()
{
	return aos_now_ms();
}
typedef void (*task_entry_t)(void *args);
int k_thread_create(struct k_thread *new_thread, k_thread_stack_t *stack,
		size_t stack_size, k_thread_entry_t entry,
		void *p1, void *p2, void *p3,
		int prio, u32_t options, s32_t delay)
{
	int ret;
	ret = aos_task_new_ext(&(new_thread->task), "ble", (task_entry_t)entry, p1, stack_size, prio);
	if (ret) {
		do { if (aos_log_get_level() & (1 << AOS_LL_V_ERROR_BIT)) { csp_printf("[%06d]<" "E" "> ", (unsigned)aos_now_ms(), "create ble task fail\n"); csp_printf("create ble task fail\n"); csp_printf("\r\n"); } } while (0);
	}
	return ret;
}
int k_yield(void)
{
	return 0;
}
unsigned int irq_lock(void)
{
	size_t cpsr;
	{ cpsr = cpu_intrpt_save(); };
	return cpsr;
}
void irq_unlock(unsigned int key)
{
	size_t cpsr;
	cpsr = key;
	{ cpu_intrpt_restore(cpsr); };
}
void _SysFatalErrorHandler(unsigned int reason,
		const void *pEsf)
{
};
void k_timer_init(k_timer_t *timer, k_timer_handler_t handle, void *args)
{
	int ret;
	;
	;
	timer->handler = handle;
	timer->args = args;
	ret = aos_timer_new_ext(&timer->timer, timer->handler, args, 1000, 0, 0);
	if (ret) {
		;
	}
}
void k_timer_start(k_timer_t *timer, uint32_t timeout)
{
	int ret;
	;
	;
	timer->timeout = timeout;
	timer->start_ms = aos_now_ms();
	ret = aos_timer_stop(&timer->timer);
	if (ret) {
		;
	}
	ret = aos_timer_change(&timer->timer, timeout);
	if (ret) {
		;
	}
	ret = aos_timer_start(&timer->timer);
	if (ret) {
		;
	}
}
void k_timer_stop(k_timer_t *timer)
{
	int ret;
	;
	;
	ret = aos_timer_stop(&timer->timer);
	if (ret) {
		;
	}
}
void k_sleep(s32_t duration)
{
	aos_msleep(duration);
}
unsigned int find_msb_set(u32_t data)
{
	uint32_t count = 0;
	uint32_t mask = 0x80000000;
	if (!data) {
		return 0;
	}
	while ((data & mask) == 0) {
		count += 1u;
		mask = mask >> 1u;
	}
	return (32 - count);
}
unsigned int find_lsb_set(u32_t data)
{
	uint32_t count = 0;
	uint32_t mask = 0x00000001;
	if (!data) {
		return 0;
	}
	while ((data & mask) == 0) {
		count += 1u;
		mask = mask >> 1u;
	}
	return (count);
}
