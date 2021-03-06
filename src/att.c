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
extern int *__errno(void);
static inline void sys_put_be16(u16_t val, u8_t dst[2])
{
	dst[0] = val >> 8;
	dst[1] = val;
}
static inline void sys_put_be32(u32_t val, u8_t dst[4])
{
	sys_put_be16(val >> 16, dst);
	sys_put_be16(val, &dst[2]);
}
static inline void sys_put_le16(u16_t val, u8_t dst[2])
{
	dst[0] = val;
	dst[1] = val >> 8;
}
static inline void sys_put_le32(u32_t val, u8_t dst[4])
{
	sys_put_le16(val, dst);
	sys_put_le16(val >> 16, &dst[2]);
}
static inline void sys_put_le64(u64_t val, u8_t dst[8])
{
	sys_put_le32(val, dst);
	sys_put_le32(val >> 32, &dst[4]);
}
static inline u16_t sys_get_be16(const u8_t src[2])
{
	return ((u16_t)src[0] << 8) | src[1];
}
static inline u32_t sys_get_be32(const u8_t src[4])
{
	return ((u32_t)sys_get_be16(&src[0]) << 16) | sys_get_be16(&src[2]);
}
static inline u16_t sys_get_le16(const u8_t src[2])
{
	return ((u16_t)src[1] << 8) | src[0];
}
static inline u32_t sys_get_le32(const u8_t src[4])
{
	return ((u32_t)sys_get_le16(&src[2]) << 16) | sys_get_le16(&src[0]);
}
static inline u64_t sys_get_le64(const u8_t src[8])
{
	return ((u64_t)sys_get_le32(&src[4]) << 32) | sys_get_le32(&src[0]);
}
static inline void sys_memcpy_swap(void *dst, const void *src, size_t length)
{
	do { } while ((0))
		;
	src += length - 1;
	for (; length > 0; length--) {
		*((u8_t *)dst++) = *((u8_t *)src--);
	}
}
static inline void sys_mem_swap(void *buf, size_t length)
{
	size_t i;
	for (i = 0; i < (length/2); i++) {
		u8_t tmp = ((u8_t *)buf)[i];
		((u8_t *)buf)[i] = ((u8_t *)buf)[length - 1 - i];
		((u8_t *)buf)[length - 1 - i] = tmp;
	}
}
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
enum {
	BT_UUID_TYPE_16,
	BT_UUID_TYPE_32,
	BT_UUID_TYPE_128,
};
struct bt_uuid {
	u8_t type;
};
struct bt_uuid_16 {
	struct bt_uuid uuid;
	u16_t val;
};
struct bt_uuid_32 {
	struct bt_uuid uuid;
	u32_t val;
};
struct bt_uuid_128 {
	struct bt_uuid uuid;
	u8_t val[16];
};
int bt_uuid_cmp(const struct bt_uuid *u1, const struct bt_uuid *u2);
static inline void bt_uuid_to_str(const struct bt_uuid *uuid, char *str,
		size_t len)
{
	if (len > 0) {
		str[0] = '\0';
	}
}
static inline const char *bt_uuid_str(const struct bt_uuid *uuid)
{
	return "";
}
struct bt_conn;
struct bt_le_conn_param {
	u16_t interval_min;
	u16_t interval_max;
	u16_t latency;
	u16_t timeout;
};
struct bt_conn *bt_conn_ref(struct bt_conn *conn);
void bt_conn_unref(struct bt_conn *conn);
struct bt_conn *bt_conn_lookup_addr_le(const bt_addr_le_t *peer);
const bt_addr_le_t *bt_conn_get_dst(const struct bt_conn *conn);
enum {
	BT_CONN_TYPE_LE,
	BT_CONN_TYPE_BR,
	BT_CONN_TYPE_SCO,
};
struct bt_conn_le_info {
	const bt_addr_le_t *src;
	const bt_addr_le_t *dst;
	u16_t interval;
	u16_t latency;
	u16_t timeout;
};
struct bt_conn_br_info {
	const bt_addr_t *dst;
};
enum {
	BT_CONN_ROLE_MASTER,
	BT_CONN_ROLE_SLAVE,
};
struct bt_conn_info {
	u8_t type;
	u8_t role;
	union {
		struct bt_conn_le_info le;
		struct bt_conn_br_info br;
	};
};
int bt_conn_get_info(const struct bt_conn *conn, struct bt_conn_info *info);
int bt_conn_le_param_update(struct bt_conn *conn,
		const struct bt_le_conn_param *param);
int bt_conn_disconnect(struct bt_conn *conn, u8_t reason);
struct bt_conn *bt_conn_create_le(const bt_addr_le_t *peer,
		const struct bt_le_conn_param *param);
int bt_le_set_auto_conn(bt_addr_le_t *addr,
		const struct bt_le_conn_param *param);
struct bt_conn *bt_conn_create_slave_le(const bt_addr_le_t *peer,
		const struct bt_le_adv_param *param);
	typedef enum 
__attribute__((__packed__)) 
{
	BT_SECURITY_NONE,
		BT_SECURITY_LOW,
		BT_SECURITY_MEDIUM,
		BT_SECURITY_HIGH,
		BT_SECURITY_FIPS,
} bt_security_t;
int bt_conn_security(struct bt_conn *conn, bt_security_t sec);
u8_t bt_conn_enc_key_size(struct bt_conn *conn);
struct bt_conn_cb {
	void (*connected)(struct bt_conn *conn, u8_t err);
	void (*disconnected)(struct bt_conn *conn, u8_t reason);
	_Bool 
		(*le_param_req)(struct bt_conn *conn,
				struct bt_le_conn_param *param);
	void (*le_param_updated)(struct bt_conn *conn, u16_t interval,
			u16_t latency, u16_t timeout);
	void (*identity_resolved)(struct bt_conn *conn,
			const bt_addr_le_t *rpa,
			const bt_addr_le_t *identity);
	void (*security_changed)(struct bt_conn *conn, bt_security_t level);
	struct bt_conn_cb *_next;
};
void bt_conn_cb_register(struct bt_conn_cb *cb);
struct bt_conn_auth_cb {
	void (*passkey_display)(struct bt_conn *conn, unsigned int passkey);
	void (*passkey_entry)(struct bt_conn *conn);
	void (*passkey_confirm)(struct bt_conn *conn, unsigned int passkey);
	void (*cancel)(struct bt_conn *conn);
	void (*pairing_confirm)(struct bt_conn *conn);
};
int bt_conn_auth_cb_register(const struct bt_conn_auth_cb *cb);
int bt_conn_auth_passkey_entry(struct bt_conn *conn, unsigned int passkey);
int bt_conn_auth_cancel(struct bt_conn *conn);
int bt_conn_auth_passkey_confirm(struct bt_conn *conn);
int bt_conn_auth_pairing_confirm(struct bt_conn *conn);
int bt_conn_auth_pincode_entry(struct bt_conn *conn, const char *pin);
struct bt_br_conn_param {
	_Bool 
		allow_role_switch;
};
struct bt_conn *bt_conn_create_br(const bt_addr_t *peer,
		const struct bt_br_conn_param *param);
struct bt_conn *bt_conn_create_sco(const bt_addr_t *peer);
typedef void (*bt_att_func_t)(struct bt_conn *conn, u8_t err,
		const void *pdu, u16_t length,
		void *user_data);
typedef void (*bt_att_destroy_t)(void *user_data);
struct bt_att_req {
	sys_snode_t node;
	bt_att_func_t func;
	bt_att_destroy_t destroy;
	struct net_buf_simple_state state;
	struct net_buf *buf;
	_Bool 
		retrying;
};
enum {
	BT_GATT_PERM_NONE = 0,
	BT_GATT_PERM_READ = (1UL << (0)),
	BT_GATT_PERM_WRITE = (1UL << (1)),
	BT_GATT_PERM_READ_ENCRYPT = (1UL << (2)),
	BT_GATT_PERM_WRITE_ENCRYPT = (1UL << (3)),
	BT_GATT_PERM_READ_AUTHEN = (1UL << (4)),
	BT_GATT_PERM_WRITE_AUTHEN = (1UL << (5)),
	BT_GATT_PERM_PREPARE_WRITE = (1UL << (6)),
};
enum {
	BT_GATT_WRITE_FLAG_PREPARE = (1UL << (0)),
};
struct bt_gatt_attr {
	const struct bt_uuid *uuid;
	ssize_t (*read)(struct bt_conn *conn,
			const struct bt_gatt_attr *attr,
			void *buf, u16_t len,
			u16_t offset);
	ssize_t (*write)(struct bt_conn *conn,
			const struct bt_gatt_attr *attr,
			const void *buf, u16_t len,
			u16_t offset, u8_t flags);
	void *user_data;
	u16_t handle;
	u8_t perm;
};
struct bt_gatt_service {
	struct bt_gatt_attr *attrs;
	u16_t attr_count;
	sys_snode_t node;
};
struct bt_gatt_service_val {
	const struct bt_uuid *uuid;
	u16_t end_handle;
};
struct bt_gatt_include {
	const struct bt_uuid *uuid;
	u16_t start_handle;
	u16_t end_handle;
};
struct bt_gatt_chrc {
	const struct bt_uuid *uuid;
	u8_t properties;
};
struct bt_gatt_cep {
	u16_t properties;
};
struct bt_gatt_ccc {
	u16_t flags;
};
struct bt_gatt_cpf {
	u8_t format;
	s8_t exponent;
	u16_t unit;
	u8_t name_space;
	u16_t description;
} 
__attribute__((__packed__))
	;
	int bt_gatt_service_register(struct bt_gatt_service *svc);
	int bt_gatt_service_unregister(struct bt_gatt_service *svc);
	enum {
		BT_GATT_ITER_STOP = 0,
		BT_GATT_ITER_CONTINUE,
	};
typedef u8_t (*bt_gatt_attr_func_t)(const struct bt_gatt_attr *attr,
		void *user_data);
void bt_gatt_foreach_attr(u16_t start_handle, u16_t end_handle,
		bt_gatt_attr_func_t func, void *user_data);
struct bt_gatt_attr *bt_gatt_attr_next(const struct bt_gatt_attr *attr);
ssize_t bt_gatt_attr_read(struct bt_conn *conn, const struct bt_gatt_attr *attr,
		void *buf, u16_t buf_len, u16_t offset,
		const void *value, u16_t value_len);
ssize_t bt_gatt_attr_read_service(struct bt_conn *conn,
		const struct bt_gatt_attr *attr,
		void *buf, u16_t len, u16_t offset);
ssize_t bt_gatt_attr_read_included(struct bt_conn *conn,
		const struct bt_gatt_attr *attr,
		void *buf, u16_t len, u16_t offset);
ssize_t bt_gatt_attr_read_chrc(struct bt_conn *conn,
		const struct bt_gatt_attr *attr, void *buf,
		u16_t len, u16_t offset);
struct bt_gatt_ccc_cfg {
	u8_t valid;
	bt_addr_le_t peer;
	u16_t value;
	u8_t data[4] 
		__attribute__((__aligned__(
						4
					  )))
		;
};
struct _bt_gatt_ccc {
	struct bt_gatt_ccc_cfg *cfg;
	size_t cfg_len;
	u16_t value;
	void (*cfg_changed)(const struct bt_gatt_attr *attr,
			u16_t value);
};
ssize_t bt_gatt_attr_read_ccc(struct bt_conn *conn,
		const struct bt_gatt_attr *attr, void *buf,
		u16_t len, u16_t offset);
ssize_t bt_gatt_attr_write_ccc(struct bt_conn *conn,
		const struct bt_gatt_attr *attr, const void *buf,
		u16_t len, u16_t offset, u8_t flags);
ssize_t bt_gatt_attr_read_cep(struct bt_conn *conn,
		const struct bt_gatt_attr *attr, void *buf,
		u16_t len, u16_t offset);
ssize_t bt_gatt_attr_read_cud(struct bt_conn *conn,
		const struct bt_gatt_attr *attr, void *buf,
		u16_t len, u16_t offset);
ssize_t bt_gatt_attr_read_cpf(struct bt_conn *conn,
		const struct bt_gatt_attr *attr, void *buf,
		u16_t len, u16_t offset);
int bt_gatt_notify(struct bt_conn *conn, const struct bt_gatt_attr *attr,
		const void *data, u16_t len);
typedef void (*bt_gatt_indicate_func_t)(struct bt_conn *conn,
		const struct bt_gatt_attr *attr,
		u8_t err);
struct bt_gatt_indicate_params {
	struct bt_att_req _req;
	const struct bt_gatt_attr *attr;
	bt_gatt_indicate_func_t func;
	const void *data;
	u16_t len;
};
int bt_gatt_indicate(struct bt_conn *conn,
		struct bt_gatt_indicate_params *params);
u16_t bt_gatt_get_mtu(struct bt_conn *conn);
struct bt_gatt_exchange_params {
	struct bt_att_req _req;
	void (*func)(struct bt_conn *conn, u8_t err,
			struct bt_gatt_exchange_params *params);
};
int bt_gatt_exchange_mtu(struct bt_conn *conn,
		struct bt_gatt_exchange_params *params);
struct bt_gatt_discover_params;
typedef u8_t (*bt_gatt_discover_func_t)(struct bt_conn *conn,
		const struct bt_gatt_attr *attr,
		struct bt_gatt_discover_params *params);
enum {
	BT_GATT_DISCOVER_PRIMARY,
	BT_GATT_DISCOVER_SECONDARY,
	BT_GATT_DISCOVER_INCLUDE,
	BT_GATT_DISCOVER_CHARACTERISTIC,
	BT_GATT_DISCOVER_DESCRIPTOR,
};
struct bt_gatt_discover_params {
	struct bt_att_req _req;
	struct bt_uuid *uuid;
	bt_gatt_discover_func_t func;
	union {
		struct {
			u16_t attr_handle;
			u16_t start_handle;
			u16_t end_handle;
		} _included;
		u16_t start_handle;
	};
	u16_t end_handle;
	u8_t type;
};
int bt_gatt_discover(struct bt_conn *conn,
		struct bt_gatt_discover_params *params);
struct bt_gatt_read_params;
typedef u8_t (*bt_gatt_read_func_t)(struct bt_conn *conn, u8_t err,
		struct bt_gatt_read_params *params,
		const void *data, u16_t length);
struct bt_gatt_read_params {
	struct bt_att_req _req;
	bt_gatt_read_func_t func;
	size_t handle_count;
	union {
		struct __single {
			u16_t handle;
			u16_t offset;
		} single;
		u16_t *handles;
	};
};
int bt_gatt_read(struct bt_conn *conn, struct bt_gatt_read_params *params);
struct bt_gatt_write_params;
typedef void (*bt_gatt_write_func_t)(struct bt_conn *conn, u8_t err,
		struct bt_gatt_write_params *params);
struct bt_gatt_write_params {
	struct bt_att_req _req;
	bt_gatt_write_func_t func;
	u16_t handle;
	u16_t offset;
	const void *data;
	u16_t length;
};
int bt_gatt_write(struct bt_conn *conn, struct bt_gatt_write_params *params);
int bt_gatt_write_without_response(struct bt_conn *conn, u16_t handle,
		const void *data, u16_t length,
		_Bool 
		sign);
struct bt_gatt_subscribe_params;
typedef u8_t (*bt_gatt_notify_func_t)(struct bt_conn *conn,
		struct bt_gatt_subscribe_params *params,
		const void *data, u16_t length);
enum {
	BT_GATT_SUBSCRIBE_FLAG_VOLATILE = (1UL << (0)),
};
struct bt_gatt_subscribe_params {
	struct bt_att_req _req;
	bt_addr_le_t _peer;
	bt_gatt_notify_func_t notify;
	u16_t value_handle;
	u16_t ccc_handle;
	u16_t value;
	u8_t flags;
	sys_snode_t node;
};
int bt_gatt_subscribe(struct bt_conn *conn,
		struct bt_gatt_subscribe_params *params);
int bt_gatt_unsubscribe(struct bt_conn *conn,
		struct bt_gatt_subscribe_params *params);
void bt_gatt_cancel(struct bt_conn *conn, void *params);
enum bt_buf_type {
	BT_BUF_CMD,
	BT_BUF_EVT,
	BT_BUF_ACL_OUT,
	BT_BUF_ACL_IN,
};
struct net_buf *bt_buf_get_rx(enum bt_buf_type type, s32_t timeout);
struct net_buf *bt_buf_get_cmd_complete(s32_t timeout);
static inline void bt_buf_set_type(struct net_buf *buf, enum bt_buf_type type)
{
	*(u8_t *)net_buf_user_data(buf) = type;
}
static inline enum bt_buf_type bt_buf_get_type(struct net_buf *buf)
{
	return *(u8_t *)net_buf_user_data(buf);
}
static inline 
	_Bool 
bt_hci_evt_is_prio(u8_t evt)
{
	switch (evt) {
		case 0x0e:
		case 0x0f:
		case 0x13:
			return 
				1
				;
		default:
			return 
				0
				;
	}
}
int bt_recv(struct net_buf *buf);
int bt_recv_prio(struct net_buf *buf);
enum bt_hci_driver_bus {
	BT_HCI_DRIVER_BUS_VIRTUAL = 0,
	BT_HCI_DRIVER_BUS_USB = 1,
	BT_HCI_DRIVER_BUS_PCCARD = 2,
	BT_HCI_DRIVER_BUS_UART = 3,
	BT_HCI_DRIVER_BUS_RS232 = 4,
	BT_HCI_DRIVER_BUS_PCI = 5,
	BT_HCI_DRIVER_BUS_SDIO = 6,
	BT_HCI_DRIVER_BUS_SPI = 7,
	BT_HCI_DRIVER_BUS_I2C = 8,
};
struct bt_hci_driver {
	const char *name;
	enum bt_hci_driver_bus bus;
	int (*open)(void);
	int (*send)(struct net_buf *buf);
};
int bt_hci_driver_register(const struct bt_hci_driver *drv);
const char *bt_hex(const void *buf, size_t len);
const char *bt_addr_str(const bt_addr_t *addr);
const char *bt_addr_le_str(const bt_addr_le_t *addr);
enum {
	BT_EVENT_CMD_TX,
	BT_EVENT_CONN_TX_NOTIFY,
	BT_EVENT_CONN_TX_QUEUE,
};
enum {
	BT_DEV_ENABLE,
	BT_DEV_READY,
	BT_DEV_ID_STATIC_RANDOM,
	BT_DEV_HAS_PUB_KEY,
	BT_DEV_PUB_KEY_BUSY,
	BT_DEV_ADVERTISING,
	BT_DEV_KEEP_ADVERTISING,
	BT_DEV_SCANNING,
	BT_DEV_EXPLICIT_SCAN,
	BT_DEV_ACTIVE_SCAN,
	BT_DEV_SCAN_FILTER_DUP,
	BT_DEV_RPA_VALID,
	BT_DEV_ID_PENDING,
	BT_DEV_NUM_FLAGS,
};
struct bt_dev_le {
	u8_t features[8];
	u64_t states;
	u16_t mtu;
	struct k_sem pkts;
	u8_t rl_size;
	u8_t rl_entries;
};
struct bt_dev {
	bt_addr_le_t id_addr;
	bt_addr_le_t random_addr;
	u8_t hci_version;
	u8_t lmp_version;
	u16_t hci_revision;
	u16_t lmp_subversion;
	u16_t manufacturer;
	u8_t features[1][8];
	u8_t supported_commands[64];
	struct k_work init;
	atomic_t flags[1 + ((BT_DEV_NUM_FLAGS) - 1) / (sizeof(atomic_val_t) * 8)];
	struct bt_dev_le le;
	struct k_sem ncmd_sem;
	struct net_buf *sent_cmd;
	struct k_fifo rx_queue;
	struct k_fifo rx_prio_queue;
	struct k_fifo cmd_tx_queue;
	const struct bt_hci_driver *drv;
};
extern struct bt_dev bt_dev;
extern const struct bt_storage *bt_storage;
extern const struct bt_conn_auth_cb *bt_auth;
_Bool 
bt_le_conn_params_valid(const struct bt_le_conn_param *param);
struct net_buf *bt_hci_cmd_create(u16_t opcode, u8_t param_len);
int bt_hci_cmd_send(u16_t opcode, struct net_buf *buf);
int bt_hci_cmd_send_sync(u16_t opcode, struct net_buf *buf,
		struct net_buf **rsp);
int bt_le_scan_update(
		_Bool 
		fast_scan);
_Bool 
bt_addr_le_is_bonded(const bt_addr_le_t *addr);
int bt_send(struct net_buf *buf);
u16_t bt_hci_get_cmd_opcode(struct net_buf *buf);
struct bt_keys;
int bt_id_add(struct bt_keys *keys);
int bt_id_del(struct bt_keys *keys);
	typedef enum 
__attribute__((__packed__)) 
{
	BT_CONN_DISCONNECTED,
		BT_CONN_CONNECT_SCAN,
		BT_CONN_CONNECT,
		BT_CONN_CONNECTED,
		BT_CONN_DISCONNECT,
} bt_conn_state_t;
enum {
	BT_CONN_AUTO_CONNECT,
	BT_CONN_BR_LEGACY_SECURE,
	BT_CONN_USER,
	BT_CONN_BR_PAIRING,
	BT_CONN_BR_NOBOND,
	BT_CONN_BR_PAIRING_INITIATOR,
	BT_CONN_CLEANUP,
	BT_CONN_AUTO_PHY_UPDATE,
	BT_CONN_AUTO_DATA_LEN,
	BT_CONN_NUM_FLAGS,
};
struct bt_conn_le {
	bt_addr_le_t dst;
	bt_addr_le_t init_addr;
	bt_addr_le_t resp_addr;
	u16_t interval;
	u16_t interval_min;
	u16_t interval_max;
	u16_t latency;
	u16_t timeout;
	u8_t features[8];
	struct bt_keys *keys;
	struct k_delayed_work update_work;
};
typedef void (*bt_conn_tx_cb_t)(struct bt_conn *conn);
struct bt_conn_tx {
	sys_snode_t node;
	bt_conn_tx_cb_t cb;
};
struct bt_conn {
	u16_t handle;
	u8_t type;
	u8_t role;
	atomic_t flags[1 + ((BT_CONN_NUM_FLAGS) - 1) / (sizeof(atomic_val_t) * 8)];
	bt_security_t sec_level;
	bt_security_t required_sec_level;
	u8_t encrypt;
	u8_t err;
	bt_conn_state_t state;
	u16_t rx_len;
	struct net_buf *rx;
	sys_slist_t tx_pending;
	struct k_fifo tx_notify;
	struct k_fifo tx_queue;
	sys_slist_t channels;
	atomic_t ref;
	union {
		struct bt_conn_le le;
	};
};
void bt_conn_recv(struct bt_conn *conn, struct net_buf *buf, u8_t flags);
int bt_conn_send_cb(struct bt_conn *conn, struct net_buf *buf,
		bt_conn_tx_cb_t cb);
static inline int bt_conn_send(struct bt_conn *conn, struct net_buf *buf)
{
	return bt_conn_send_cb(conn, buf, 
			((void *)0)
			);
}
struct bt_conn *bt_conn_add_le(const bt_addr_le_t *peer);
struct bt_conn *bt_conn_add_br(const bt_addr_t *peer);
struct bt_conn *bt_conn_add_sco(const bt_addr_t *peer, int link_type);
void bt_sco_cleanup(struct bt_conn *sco_conn);
struct bt_conn *bt_conn_lookup_addr_sco(const bt_addr_t *peer);
struct bt_conn *bt_conn_lookup_addr_br(const bt_addr_t *peer);
void bt_conn_pin_code_req(struct bt_conn *conn);
u8_t bt_conn_get_io_capa(void);
u8_t bt_conn_ssp_get_auth(const struct bt_conn *conn);
void bt_conn_ssp_auth(struct bt_conn *conn, u32_t passkey);
void bt_conn_disconnect_all(void);
struct bt_conn *bt_conn_lookup_handle(u16_t handle);
int bt_conn_addr_le_cmp(const struct bt_conn *conn, const bt_addr_le_t *peer);
u8_t bt_conn_get_id(struct bt_conn *conn);
struct bt_conn *bt_conn_lookup_id(u8_t id);
struct bt_conn *bt_conn_lookup_state_le(const bt_addr_le_t *peer,
		const bt_conn_state_t state);
void bt_conn_set_state(struct bt_conn *conn, bt_conn_state_t state);
int bt_conn_le_conn_update(struct bt_conn *conn,
		const struct bt_le_conn_param *param);
void notify_le_param_updated(struct bt_conn *conn);
_Bool 
le_param_req(struct bt_conn *conn, struct bt_le_conn_param *param);
int bt_conn_le_start_encryption(struct bt_conn *conn, u64_t rand,
		u16_t ediv, const u8_t *ltk, size_t len);
void bt_conn_identity_resolved(struct bt_conn *conn);
void bt_conn_security_changed(struct bt_conn *conn);
struct net_buf *bt_conn_create_pdu(struct net_buf_pool *pool, size_t reserve);
int bt_conn_init(void);
struct k_sem *bt_conn_get_pkts(struct bt_conn *conn);
int bt_conn_prepare_events(struct k_poll_event events[]);
void bt_conn_process_tx(struct bt_conn *conn);
void bt_conn_notify_tx(struct bt_conn *conn);
struct bt_l2cap_chan;
typedef void (*bt_l2cap_chan_destroy_t)(struct bt_l2cap_chan *chan);
typedef enum bt_l2cap_chan_state {
	BT_L2CAP_DISCONNECTED,
	BT_L2CAP_CONNECT,
	BT_L2CAP_CONFIG,
	BT_L2CAP_CONNECTED,
	BT_L2CAP_DISCONNECT,
} 
__attribute__((__packed__)) 
	bt_l2cap_chan_state_t;
	struct bt_l2cap_chan {
		struct bt_conn *conn;
		struct bt_l2cap_chan_ops *ops;
		sys_snode_t node;
		bt_l2cap_chan_destroy_t destroy;
		struct k_delayed_work rtx_work;
	};
struct bt_l2cap_le_endpoint {
	u16_t cid;
	u16_t mtu;
	u16_t mps;
	u16_t init_credits;
	struct k_sem credits;
};
struct bt_l2cap_le_chan {
	struct bt_l2cap_chan chan;
	struct bt_l2cap_le_endpoint rx;
	struct bt_l2cap_le_endpoint tx;
	struct k_fifo tx_queue;
	struct net_buf *tx_buf;
	struct net_buf *_sdu;
	u16_t _sdu_len;
};
struct bt_l2cap_br_endpoint {
	u16_t cid;
	u16_t mtu;
};
struct bt_l2cap_br_chan {
	struct bt_l2cap_chan chan;
	struct bt_l2cap_br_endpoint rx;
	struct bt_l2cap_br_endpoint tx;
	atomic_t flags[1];
};
struct bt_l2cap_chan_ops {
	void (*connected)(struct bt_l2cap_chan *chan);
	void (*disconnected)(struct bt_l2cap_chan *chan);
	void (*encrypt_change)(struct bt_l2cap_chan *chan, u8_t hci_status);
	struct net_buf *(*alloc_buf)(struct bt_l2cap_chan *chan);
	void (*recv)(struct bt_l2cap_chan *chan, struct net_buf *buf);
};
struct bt_l2cap_server {
	u16_t psm;
	bt_security_t sec_level;
	int (*accept)(struct bt_conn *conn, struct bt_l2cap_chan **chan);
	sys_snode_t node;
};
int bt_l2cap_server_register(struct bt_l2cap_server *server);
int bt_l2cap_br_server_register(struct bt_l2cap_server *server);
int bt_l2cap_chan_connect(struct bt_conn *conn, struct bt_l2cap_chan *chan,
		u16_t psm);
int bt_l2cap_chan_disconnect(struct bt_l2cap_chan *chan);
int bt_l2cap_chan_send(struct bt_l2cap_chan *chan, struct net_buf *buf);
enum l2cap_conn_list_action {
	BT_L2CAP_CHAN_LOOKUP,
	BT_L2CAP_CHAN_DETACH,
};
struct bt_l2cap_hdr {
	u16_t len;
	u16_t cid;
} 
__attribute__((__packed__))
	;
	struct bt_l2cap_sig_hdr {
		u8_t code;
		u8_t ident;
		u16_t len;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_cmd_reject {
		u16_t reason;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_cmd_reject_cid_data {
		u16_t scid;
		u16_t dcid;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conn_req {
		u16_t psm;
		u16_t scid;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conn_rsp {
		u16_t dcid;
		u16_t scid;
		u16_t result;
		u16_t status;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conf_req {
		u16_t dcid;
		u16_t flags;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conf_rsp {
		u16_t scid;
		u16_t flags;
		u16_t result;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conf_opt {
		u8_t type;
		u8_t len;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_disconn_req {
		u16_t dcid;
		u16_t scid;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_disconn_rsp {
		u16_t dcid;
		u16_t scid;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_info_req {
		u16_t type;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_info_rsp {
		u16_t type;
		u16_t result;
		u8_t data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conn_param_req {
		u16_t min_interval;
		u16_t max_interval;
		u16_t latency;
		u16_t timeout;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_conn_param_rsp {
		u16_t result;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_le_conn_req {
		u16_t psm;
		u16_t scid;
		u16_t mtu;
		u16_t mps;
		u16_t credits;
	} 
__attribute__((__packed__))
	;
	struct bt_l2cap_le_conn_rsp {
		u16_t dcid;
		u16_t mtu;
		u16_t mps;
		u16_t credits;
		u16_t result;
	};
struct bt_l2cap_le_credits {
	u16_t cid;
	u16_t credits;
} 
__attribute__((__packed__))
	;
	struct bt_l2cap_fixed_chan {
		u16_t cid;
		int (*accept)(struct bt_conn *conn, struct bt_l2cap_chan **chan);
		sys_snode_t node;
	};
void bt_l2cap_le_fixed_chan_register(struct bt_l2cap_fixed_chan *chan);
void bt_l2cap_connected(struct bt_conn *conn);
void bt_l2cap_disconnected(struct bt_conn *conn);
void bt_l2cap_chan_add(struct bt_conn *conn, struct bt_l2cap_chan *chan,
		bt_l2cap_chan_destroy_t destroy);
void bt_l2cap_chan_remove(struct bt_conn *conn, struct bt_l2cap_chan *chan);
void bt_l2cap_chan_del(struct bt_l2cap_chan *chan);
const char *bt_l2cap_chan_state_str(bt_l2cap_chan_state_t state);
void bt_l2cap_chan_set_state(struct bt_l2cap_chan *chan,
		bt_l2cap_chan_state_t state);
void bt_l2cap_encrypt_change(struct bt_conn *conn, u8_t hci_status);
struct net_buf *bt_l2cap_create_pdu(struct net_buf_pool *pool, size_t reserve);
struct net_buf *bt_l2cap_create_rsp(struct net_buf *buf, size_t reserve);
void bt_l2cap_send_cb(struct bt_conn *conn, u16_t cid, struct net_buf *buf,
		bt_conn_tx_cb_t cb);
static inline void bt_l2cap_send(struct bt_conn *conn, u16_t cid,
		struct net_buf *buf)
{
	bt_l2cap_send_cb(conn, cid, buf, 
			((void *)0)
			);
}
void bt_l2cap_recv(struct bt_conn *conn, struct net_buf *buf);
int bt_l2cap_update_conn_param(struct bt_conn *conn,
		const struct bt_le_conn_param *param);
void bt_l2cap_init(void);
struct bt_l2cap_chan *bt_l2cap_le_lookup_tx_cid(struct bt_conn *conn,
		u16_t cid);
struct bt_l2cap_chan *bt_l2cap_le_lookup_rx_cid(struct bt_conn *conn,
		u16_t cid);
void bt_l2cap_br_init(void);
void bt_l2cap_br_fixed_chan_register(struct bt_l2cap_fixed_chan *chan);
void bt_l2cap_br_connected(struct bt_conn *conn);
struct bt_l2cap_chan *bt_l2cap_br_lookup_rx_cid(struct bt_conn *conn,
		u16_t cid);
int bt_l2cap_br_chan_disconnect(struct bt_l2cap_chan *chan);
int bt_l2cap_br_chan_connect(struct bt_conn *conn, struct bt_l2cap_chan *chan,
		u16_t psm);
int bt_l2cap_br_chan_send(struct bt_l2cap_chan *chan, struct net_buf *buf);
void l2cap_br_encrypt_change(struct bt_conn *conn, u8_t hci_status);
void bt_l2cap_br_recv(struct bt_conn *conn, struct net_buf *buf);
struct bt_smp_hdr {
	u8_t code;
} 
__attribute__((__packed__))
	;
	struct bt_smp_pairing {
		u8_t io_capability;
		u8_t oob_flag;
		u8_t auth_req;
		u8_t max_key_size;
		u8_t init_key_dist;
		u8_t resp_key_dist;
	} 
__attribute__((__packed__))
	;
	struct bt_smp_pairing_confirm {
		u8_t val[16];
	} 
__attribute__((__packed__))
	;
	struct bt_smp_pairing_random {
		u8_t val[16];
	} 
__attribute__((__packed__))
	;
	struct bt_smp_pairing_fail {
		u8_t reason;
	} 
__attribute__((__packed__))
	;
	struct bt_smp_encrypt_info {
		u8_t ltk[16];
	} 
__attribute__((__packed__))
	;
	struct bt_smp_master_ident {
		u16_t ediv;
		u64_t rand;
	} 
__attribute__((__packed__))
	;
	struct bt_smp_ident_info {
		u8_t irk[16];
	} 
__attribute__((__packed__))
	;
	struct bt_smp_ident_addr_info {
		bt_addr_le_t addr;
	} 
__attribute__((__packed__))
	;
	struct bt_smp_signing_info {
		u8_t csrk[16];
	} 
__attribute__((__packed__))
	;
	struct bt_smp_security_request {
		u8_t auth_req;
	} 
__attribute__((__packed__))
	;
	struct bt_smp_public_key {
		u8_t x[32];
		u8_t y[32];
	} 
__attribute__((__packed__))
	;
	struct bt_smp_dhkey_check {
		u8_t e[16];
	} 
__attribute__((__packed__))
	;
	int bt_smp_send_pairing_req(struct bt_conn *conn);
	int bt_smp_send_security_req(struct bt_conn *conn);
	void bt_smp_update_keys(struct bt_conn *conn);
	_Bool 
	bt_smp_get_tk(struct bt_conn *conn, u8_t *tk);
	int bt_smp_br_send_pairing_req(struct bt_conn *conn);
	int bt_smp_init(void);
	int bt_smp_auth_passkey_entry(struct bt_conn *conn, unsigned int passkey);
	int bt_smp_auth_passkey_confirm(struct bt_conn *conn);
	int bt_smp_auth_pairing_confirm(struct bt_conn *conn);
	int bt_smp_auth_cancel(struct bt_conn *conn);
	int bt_smp_sign_verify(struct bt_conn *conn, struct net_buf *buf);
	int bt_smp_sign(struct bt_conn *conn, struct net_buf *buf);
	struct bt_att_hdr {
		u8_t code;
	} 
__attribute__((__packed__))
	;
	struct bt_att_error_rsp {
		u8_t request;
		u16_t handle;
		u8_t error;
	} 
__attribute__((__packed__))
	;
	struct bt_att_exchange_mtu_req {
		u16_t mtu;
	} 
__attribute__((__packed__))
	;
	struct bt_att_exchange_mtu_rsp {
		u16_t mtu;
	} 
__attribute__((__packed__))
	;
	struct bt_att_find_info_req {
		u16_t start_handle;
		u16_t end_handle;
	} 
__attribute__((__packed__))
	;
	struct bt_att_info_16 {
		u16_t handle;
		u16_t uuid;
	} 
__attribute__((__packed__))
	;
	struct bt_att_info_128 {
		u16_t handle;
		u8_t uuid[16];
	} 
__attribute__((__packed__))
	;
	struct bt_att_find_info_rsp {
		u8_t format;
		u8_t info[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_find_type_req {
		u16_t start_handle;
		u16_t end_handle;
		u16_t type;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_handle_group {
		u16_t start_handle;
		u16_t end_handle;
	} 
__attribute__((__packed__))
	;
	struct bt_att_find_type_rsp {
		struct bt_att_handle_group list[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_type_req {
		u16_t start_handle;
		u16_t end_handle;
		u8_t uuid[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_data {
		u16_t handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_type_rsp {
		u8_t len;
		struct bt_att_data data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_req {
		u16_t handle;
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_rsp {
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_blob_req {
		u16_t handle;
		u16_t offset;
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_blob_rsp {
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_mult_req {
		u16_t handles[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_mult_rsp {
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_group_req {
		u16_t start_handle;
		u16_t end_handle;
		u8_t uuid[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_group_data {
		u16_t start_handle;
		u16_t end_handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_read_group_rsp {
		u8_t len;
		struct bt_att_group_data data[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_write_req {
		u16_t handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_prepare_write_req {
		u16_t handle;
		u16_t offset;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_prepare_write_rsp {
		u16_t handle;
		u16_t offset;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_exec_write_req {
		u8_t flags;
	} 
__attribute__((__packed__))
	;
	struct bt_att_notify {
		u16_t handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_indicate {
		u16_t handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_signature {
		u8_t value[12];
	} 
__attribute__((__packed__))
	;
	struct bt_att_write_cmd {
		u16_t handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	struct bt_att_signed_write_cmd {
		u16_t handle;
		u8_t value[0];
	} 
__attribute__((__packed__))
	;
	void bt_att_init(void);
	u16_t bt_att_get_mtu(struct bt_conn *conn);
	struct net_buf *bt_att_create_pdu(struct bt_conn *conn, u8_t op,
			size_t len);
int bt_att_send(struct bt_conn *conn, struct net_buf *buf);
int bt_att_req_send(struct bt_conn *conn, struct bt_att_req *req);
void bt_att_req_cancel(struct bt_conn *conn, struct bt_att_req *req);
void bt_gatt_init(void);
void bt_gatt_connected(struct bt_conn *conn);
void bt_gatt_disconnected(struct bt_conn *conn);
static inline void bt_gatt_notification(struct bt_conn *conn, u16_t handle,
		const void *data, u16_t length)
{
}
	typedef enum 
__attribute__((__packed__)) 
{
	ATT_COMMAND,
		ATT_REQUEST,
		ATT_RESPONSE,
		ATT_NOTIFICATION,
		ATT_CONFIRMATION,
		ATT_INDICATION,
		ATT_UNKNOWN,
} att_type_t;
static att_type_t att_op_get_type(u8_t op);
enum {
	ATT_PENDING_RSP,
	ATT_PENDING_CFM,
	ATT_DISCONNECTED,
	ATT_NUM_FLAGS,
};
struct bt_att {
	struct bt_l2cap_le_chan chan;
	atomic_t flags[1 + ((ATT_NUM_FLAGS) - 1) / (sizeof(atomic_val_t) * 8)];
	struct bt_att_req *req;
	sys_slist_t reqs;
	struct k_delayed_work timeout_work;
	struct k_sem tx_sem;
};
static struct bt_att bt_req_pool[1];
static void att_req_destroy(struct bt_att_req *req)
{
	;
	if (req->buf) {
		net_buf_unref(req->buf);
	}
	if (req->destroy) {
		req->destroy(req);
	}
	memset(req, 0, sizeof(*req));
}
static struct bt_att *att_get(struct bt_conn *conn)
{
	struct bt_l2cap_chan *chan;
	chan = bt_l2cap_le_lookup_tx_cid(conn, 0x0004);
	do { } while ((0));
	return ((struct bt_att *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					chan
					)
				));
}
static void att_cfm_sent(struct bt_conn *conn)
{
	struct bt_att *att = att_get(conn);
	;
	k_sem_give(&att->tx_sem);
}
static void att_rsp_sent(struct bt_conn *conn)
{
	struct bt_att *att = att_get(conn);
	;
	k_sem_give(&att->tx_sem);
}
static void att_req_sent(struct bt_conn *conn)
{
	struct bt_att *att = att_get(conn);
	;
	k_sem_give(&att->tx_sem);
	if (att->req) {
		k_delayed_work_submit(&att->timeout_work, ((30) * 1000));
	}
}
static void att_pdu_sent(struct bt_conn *conn)
{
	struct bt_att *att = att_get(conn);
	;
	k_sem_give(&att->tx_sem);
}
static bt_conn_tx_cb_t att_cb(struct net_buf *buf)
{
	switch (att_op_get_type(buf->data[0])) {
		case ATT_RESPONSE:
			return att_rsp_sent;
		case ATT_CONFIRMATION:
			return att_cfm_sent;
		case ATT_REQUEST:
		case ATT_INDICATION:
			return att_req_sent;
		default:
			return att_pdu_sent;
	}
}
static void send_err_rsp(struct bt_conn *conn, u8_t req, u16_t handle,
		u8_t err)
{
	struct bt_att_error_rsp *rsp;
	struct net_buf *buf;
	if (!req) {
		return;
	}
	buf = bt_att_create_pdu(conn, 0x01, sizeof(*rsp));
	if (!buf) {
		return;
	}
	rsp = net_buf_simple_add(&(buf)->b, sizeof(*rsp));
	rsp->request = req;
	rsp->handle = (handle);
	rsp->error = err;
	bt_l2cap_send_cb(conn, 0x0004, buf, att_rsp_sent);
}
static u8_t att_mtu_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct bt_att_exchange_mtu_req *req;
	struct bt_att_exchange_mtu_rsp *rsp;
	struct net_buf *pdu;
	u16_t mtu_client, mtu_server;
	req = (void *)buf->data;
	mtu_client = (req->mtu);
	;
	if (mtu_client < 23) {
		return 0x04;
	}
	pdu = bt_att_create_pdu(conn, 0x03, sizeof(*rsp));
	if (!pdu) {
		return 0x0e;
	}
	mtu_server = 65;
	;
	rsp = net_buf_simple_add(&(pdu)->b, sizeof(*rsp));
	rsp->mtu = (mtu_server);
	bt_l2cap_send_cb(conn, 0x0004, pdu, att_rsp_sent);
	att->chan.rx.mtu = (((mtu_client) < (mtu_server)) ? (mtu_client) : (mtu_server));
	att->chan.tx.mtu = att->chan.rx.mtu;
	;
	return 0;
}
static inline 
	_Bool 
att_is_connected(struct bt_att *att)
{
	return (att->chan.chan.conn->state != BT_CONN_CONNECTED ||
			!atomic_test_bit(att->flags, ATT_DISCONNECTED));
}
static int att_send_req(struct bt_att *att, struct bt_att_req *req)
{
	;
	att->req = req;
	k_sem_take(&att->tx_sem, -1);
	if (!att_is_connected(att)) {
		;
		k_sem_give(&att->tx_sem);
		return -57;
	}
	net_buf_simple_save(&req->buf->b, &req->state);
	bt_l2cap_send_cb(att->chan.chan.conn, 0x0004,
			net_buf_ref(req->buf), att_cb(req->buf));
	return 0;
}
static void att_process(struct bt_att *att)
{
	sys_snode_t *node;
	;
	node = sys_slist_get(&att->reqs);
	if (!node) {
		return;
	}
	att_send_req(att, ((struct bt_att_req *)(((char *)(node)) - 
					__builtin_offsetof (
						struct bt_att_req
						, 
						node
						)
					)));
}
static u8_t att_handle_rsp(struct bt_att *att, void *pdu, u16_t len, u8_t err)
{
	bt_att_func_t func;
	;
	k_delayed_work_cancel(&att->timeout_work);
	if (!att->req) {
		;
		goto process;
	}
	if (att->req->buf) {
		net_buf_unref(att->req->buf);
		att->req->buf = 
			((void *)0)
			;
	}
	func = att->req->func;
	att->req->func = 
		((void *)0)
		;
	func(att->chan.chan.conn, err, pdu, len, att->req);
	if (!att->req->func) {
		att_req_destroy(att->req);
	}
	att->req = 
		((void *)0)
		;
process:
	att_process(att);
	return 0;
}
static u8_t att_mtu_rsp(struct bt_att *att, struct net_buf *buf)
{
	struct bt_att_exchange_mtu_rsp *rsp;
	u16_t mtu;
	if (!att) {
		return 0;
	}
	rsp = (void *)buf->data;
	mtu = (rsp->mtu);
	;
	if (mtu < 23) {
		return att_handle_rsp(att, 
				((void *)0)
				, 0, 0x04);
	}
	att->chan.rx.mtu = (((mtu) < (65)) ? (mtu) : (65));
	att->chan.tx.mtu = att->chan.rx.mtu;
	;
	return att_handle_rsp(att, rsp, buf->len, 0);
}
static 
	_Bool 
range_is_valid(u16_t start, u16_t end, u16_t *err)
{
	if (!start || !end) {
		if (err) {
			*err = 0;
		}
		return 
			0
			;
	}
	if (start > end) {
		if (err) {
			*err = start;
		}
		return 
			0
			;
	}
	return 
		1
		;
}
struct find_info_data {
	struct bt_att *att;
	struct net_buf *buf;
	struct bt_att_find_info_rsp *rsp;
	union {
		struct bt_att_info_16 *info16;
		struct bt_att_info_128 *info128;
	};
};
static u8_t find_info_cb(const struct bt_gatt_attr *attr, void *user_data)
{
	struct find_info_data *data = user_data;
	struct bt_att *att = data->att;
	;
	if (!data->rsp) {
		data->rsp = net_buf_simple_add(&(data->buf)->b, sizeof(*data->rsp));
		data->rsp->format = (attr->uuid->type == BT_UUID_TYPE_16) ?
			0x01 : 0x02;
	}
	switch (data->rsp->format) {
		case 0x01:
			if (attr->uuid->type != BT_UUID_TYPE_16) {
				return BT_GATT_ITER_STOP;
			}
			data->info16 = net_buf_simple_add(&(data->buf)->b, sizeof(*data->info16));
			data->info16->handle = (attr->handle);
			data->info16->uuid = (((struct bt_uuid_16 *)(((char *)(attr->uuid)) - 
							__builtin_offsetof (
								struct bt_uuid_16
								, 
								uuid
								)
							))->val);
			if (att->chan.tx.mtu - data->buf->len >
					sizeof(*data->info16)) {
				return BT_GATT_ITER_CONTINUE;
			}
			break;
		case 0x02:
			if (attr->uuid->type != BT_UUID_TYPE_128) {
				return BT_GATT_ITER_STOP;
			}
			data->info128 = net_buf_simple_add(&(data->buf)->b, sizeof(*data->info128));
			data->info128->handle = (attr->handle);
			memcpy(data->info128->uuid, ((struct bt_uuid_128 *)(((char *)(attr->uuid)) - 
							__builtin_offsetof (
								struct bt_uuid_128
								, 
								uuid
								)
							))->val,
					sizeof(data->info128->uuid));
			if (att->chan.tx.mtu - data->buf->len >
					sizeof(*data->info128)) {
				return BT_GATT_ITER_CONTINUE;
			}
	}
	return BT_GATT_ITER_STOP;
}
static u8_t att_find_info_rsp(struct bt_att *att, u16_t start_handle,
		u16_t end_handle)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct find_info_data data;
	memset(&data, 0, sizeof(data));
	data.buf = bt_att_create_pdu(conn, 0x05, 0);
	if (!data.buf) {
		return 0x0e;
	}
	data.att = att;
	bt_gatt_foreach_attr(start_handle, end_handle, find_info_cb, &data);
	if (!data.rsp) {
		net_buf_unref(data.buf);
		send_err_rsp(conn, 0x04, start_handle,
				0x0a);
		return 0;
	}
	bt_l2cap_send_cb(conn, 0x0004, data.buf, att_rsp_sent);
	return 0;
}
static u8_t att_find_info_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct bt_att_find_info_req *req;
	u16_t start_handle, end_handle, err_handle;
	req = (void *)buf->data;
	start_handle = (req->start_handle);
	end_handle = (req->end_handle);
	;
	if (!range_is_valid(start_handle, end_handle, &err_handle)) {
		send_err_rsp(conn, 0x04, err_handle,
				0x01);
		return 0;
	}
	return att_find_info_rsp(att, start_handle, end_handle);
}
struct find_type_data {
	struct bt_att *att;
	struct net_buf *buf;
	struct bt_att_handle_group *group;
	const void *value;
	u8_t value_len;
	u8_t err;
};
static u8_t find_type_cb(const struct bt_gatt_attr *attr, void *user_data)
{
	struct find_type_data *data = user_data;
	struct bt_att *att = data->att;
	struct bt_conn *conn = att->chan.chan.conn;
	int read;
	u8_t uuid[16];
	if (!bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) (&(struct bt_uuid_16) { .uuid.type = BT_UUID_TYPE_16, .val = (0x2801), })))) {
		data->group = 
			((void *)0)
			;
		return BT_GATT_ITER_CONTINUE;
	}
	if (bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) (&(struct bt_uuid_16) { .uuid.type = BT_UUID_TYPE_16, .val = (0x2800), })))) {
		if (data->group && attr->handle > data->group->end_handle) {
			data->group->end_handle = (attr->handle);
		}
		return BT_GATT_ITER_CONTINUE;
	}
	;
	if (att->chan.tx.mtu - data->buf->len < sizeof(*data->group)) {
		return BT_GATT_ITER_STOP;
	}
	read = attr->read(conn, attr, uuid, sizeof(uuid), 0);
	if (read < 0) {
		data->group = 
			((void *)0)
			;
		return BT_GATT_ITER_CONTINUE;
	}
	if (read != data->value_len || memcmp(data->value, uuid, read)) {
		data->group = 
			((void *)0)
			;
		return BT_GATT_ITER_CONTINUE;
	}
	data->err = 0x00;
	data->group = net_buf_simple_add(&(data->buf)->b, sizeof(*data->group));
	data->group->start_handle = (attr->handle);
	data->group->end_handle = (attr->handle);
	return BT_GATT_ITER_CONTINUE;
}
static u8_t att_find_type_rsp(struct bt_att *att, u16_t start_handle,
		u16_t end_handle, const void *value,
		u8_t value_len)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct find_type_data data;
	memset(&data, 0, sizeof(data));
	data.buf = bt_att_create_pdu(conn, 0x07, 0);
	if (!data.buf) {
		return 0x0e;
	}
	data.att = att;
	data.group = 
		((void *)0)
		;
	data.value = value;
	data.value_len = value_len;
	data.err = 0x0a;
	bt_gatt_foreach_attr(start_handle, end_handle, find_type_cb, &data);
	if (data.err) {
		net_buf_unref(data.buf);
		send_err_rsp(conn, 0x06, start_handle,
				data.err);
		return 0;
	}
	bt_l2cap_send_cb(conn, 0x0004, data.buf, att_rsp_sent);
	return 0;
}
static u8_t att_find_type_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct bt_att_find_type_req *req;
	u16_t start_handle, end_handle, err_handle, type;
	u8_t *value;
	req = (void *)buf->data;
	start_handle = (req->start_handle);
	end_handle = (req->end_handle);
	type = (req->type);
	value = net_buf_simple_pull(&(buf)->b, sizeof(*req));
	;
	if (!range_is_valid(start_handle, end_handle, &err_handle)) {
		send_err_rsp(conn, 0x06, err_handle,
				0x01);
		return 0;
	}
	if (type != 0x2800) {
		send_err_rsp(conn, 0x06, start_handle,
				0x0a);
		return 0;
	}
	return att_find_type_rsp(att, start_handle, end_handle, value,
			buf->len);
}
static 
	_Bool 
uuid_create(struct bt_uuid *uuid, struct net_buf *buf)
{
	switch (buf->len) {
		case 2:
			uuid->type = BT_UUID_TYPE_16;
			((struct bt_uuid_16 *)(((char *)(uuid)) - 
				__builtin_offsetof (
					struct bt_uuid_16
					, 
					uuid
					)
				))->val = net_buf_simple_pull_le16(&(buf)->b);
			return 
				1
				;
		case 16:
			uuid->type = BT_UUID_TYPE_128;
			memcpy(((struct bt_uuid_128 *)(((char *)(uuid)) - 
							__builtin_offsetof (
								struct bt_uuid_128
								, 
								uuid
								)
						      ))->val, buf->data, buf->len);
			return 
				1
				;
	}
	return 
		0
		;
}
static u8_t check_perm(struct bt_conn *conn, const struct bt_gatt_attr *attr,
		u8_t mask)
{
	if ((mask & BT_GATT_PERM_READ) &&
			(!(attr->perm & (BT_GATT_PERM_READ | BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_READ_AUTHEN)) || !attr->read)) {
		return 0x02;
	}
	if ((mask & BT_GATT_PERM_WRITE) &&
			(!(attr->perm & (BT_GATT_PERM_WRITE | BT_GATT_PERM_WRITE_ENCRYPT | BT_GATT_PERM_WRITE_AUTHEN)) || !attr->write)) {
		return 0x03;
	}
	mask &= attr->perm;
	if (mask & (BT_GATT_PERM_READ_AUTHEN | BT_GATT_PERM_WRITE_AUTHEN)) {
		if (conn->sec_level < BT_SECURITY_HIGH) {
			return 0x05;
		}
	}
	if ((mask & (BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT))) {
		if (!conn->encrypt) {
			return 0x0f;
		}
	}
	return 0;
}
static u8_t err_to_att(int err)
{
	;
	if (err < 0 && err >= -0xff) {
		return -err;
	}
	return 0x0e;
}
struct read_type_data {
	struct bt_att *att;
	struct bt_uuid *uuid;
	struct net_buf *buf;
	struct bt_att_read_type_rsp *rsp;
	struct bt_att_data *item;
	u8_t err;
};
static u8_t read_type_cb(const struct bt_gatt_attr *attr, void *user_data)
{
	struct read_type_data *data = user_data;
	struct bt_att *att = data->att;
	struct bt_conn *conn = att->chan.chan.conn;
	int read;
	if (bt_uuid_cmp(attr->uuid, data->uuid)) {
		return BT_GATT_ITER_CONTINUE;
	}
	;
	data->err = check_perm(conn, attr, (BT_GATT_PERM_READ | BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_READ_AUTHEN));
	if (data->err) {
		if (data->rsp->len) {
			data->err = 0x00;
		}
		return BT_GATT_ITER_STOP;
	}
	data->err = 0x00;
	data->item = net_buf_simple_add(&(data->buf)->b, sizeof(*data->item));
	data->item->handle = (attr->handle);
	read = attr->read(conn, attr, data->buf->data + data->buf->len,
			att->chan.tx.mtu - data->buf->len, 0);
	if (read < 0) {
		data->err = err_to_att(read);
		return BT_GATT_ITER_STOP;
	}
	if (!data->rsp->len) {
		data->rsp->len = read + sizeof(*data->item);
	} else if (data->rsp->len != read + sizeof(*data->item)) {
		data->buf->len -= sizeof(*data->item);
		return BT_GATT_ITER_STOP;
	}
	net_buf_simple_add(&(data->buf)->b, read);
	return att->chan.tx.mtu - data->buf->len > data->rsp->len ?
		BT_GATT_ITER_CONTINUE : BT_GATT_ITER_STOP;
}
static u8_t att_read_type_rsp(struct bt_att *att, struct bt_uuid *uuid,
		u16_t start_handle, u16_t end_handle)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct read_type_data data;
	memset(&data, 0, sizeof(data));
	data.buf = bt_att_create_pdu(conn, 0x09,
			sizeof(*data.rsp));
	if (!data.buf) {
		return 0x0e;
	}
	data.att = att;
	data.uuid = uuid;
	data.rsp = net_buf_simple_add(&(data.buf)->b, sizeof(*data.rsp));
	data.rsp->len = 0;
	data.err = 0x0a;
	bt_gatt_foreach_attr(start_handle, end_handle, read_type_cb, &data);
	if (data.err) {
		net_buf_unref(data.buf);
		send_err_rsp(conn, 0x08, start_handle,
				data.err);
		return 0;
	}
	bt_l2cap_send_cb(conn, 0x0004, data.buf, att_rsp_sent);
	return 0;
}
static u8_t att_read_type_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct bt_att_read_type_req *req;
	u16_t start_handle, end_handle, err_handle;
	union {
		struct bt_uuid uuid;
		struct bt_uuid_16 u16;
		struct bt_uuid_128 u128;
	} u;
	if (buf->len != sizeof(*req) + 2 && buf->len != sizeof(*req) + 16) {
		return 0x04;
	}
	req = (void *)buf->data;
	start_handle = (req->start_handle);
	end_handle = (req->end_handle);
	net_buf_simple_pull(&(buf)->b, sizeof(*req));
	if (!uuid_create(&u.uuid, buf)) {
		return 0x0e;
	}
	;
	if (!range_is_valid(start_handle, end_handle, &err_handle)) {
		send_err_rsp(conn, 0x08, err_handle,
				0x01);
		return 0;
	}
	return att_read_type_rsp(att, &u.uuid, start_handle, end_handle);
}
struct read_data {
	struct bt_att *att;
	u16_t offset;
	struct net_buf *buf;
	struct bt_att_read_rsp *rsp;
	u8_t err;
};
static u8_t read_cb(const struct bt_gatt_attr *attr, void *user_data)
{
	struct read_data *data = user_data;
	struct bt_att *att = data->att;
	struct bt_conn *conn = att->chan.chan.conn;
	int read;
	;
	data->rsp = net_buf_simple_add(&(data->buf)->b, sizeof(*data->rsp));
	data->err = 0x00;
	data->err = check_perm(conn, attr, (BT_GATT_PERM_READ | BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_READ_AUTHEN));
	if (data->err) {
		return BT_GATT_ITER_STOP;
	}
	read = attr->read(conn, attr, data->buf->data + data->buf->len,
			att->chan.tx.mtu - data->buf->len, data->offset);
	if (read < 0) {
		data->err = err_to_att(read);
		return BT_GATT_ITER_STOP;
	}
	net_buf_simple_add(&(data->buf)->b, read);
	return BT_GATT_ITER_CONTINUE;
}
static u8_t att_read_rsp(struct bt_att *att, u8_t op, u8_t rsp, u16_t handle,
		u16_t offset)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct read_data data;
	if (!handle) {
		return 0x01;
	}
	memset(&data, 0, sizeof(data));
	data.buf = bt_att_create_pdu(conn, rsp, 0);
	if (!data.buf) {
		return 0x0e;
	}
	data.att = att;
	data.offset = offset;
	data.err = 0x01;
	bt_gatt_foreach_attr(handle, handle, read_cb, &data);
	if (data.err) {
		net_buf_unref(data.buf);
		send_err_rsp(conn, op, handle, data.err);
		return 0;
	}
	bt_l2cap_send_cb(conn, 0x0004, data.buf, att_rsp_sent);
	return 0;
}
static u8_t att_read_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_att_read_req *req;
	u16_t handle;
	req = (void *)buf->data;
	handle = (req->handle);
	;
	return att_read_rsp(att, 0x0a, 0x0b,
			handle, 0);
}
static u8_t att_read_blob_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_att_read_blob_req *req;
	u16_t handle, offset;
	req = (void *)buf->data;
	handle = (req->handle);
	offset = (req->offset);
	;
	return att_read_rsp(att, 0x0c,
			0x0d, handle, offset);
}
static u8_t att_read_mult_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct read_data data;
	u16_t handle;
	memset(&data, 0, sizeof(data));
	data.buf = bt_att_create_pdu(conn, 0x0f, 0);
	if (!data.buf) {
		return 0x0e;
	}
	data.att = att;
	while (buf->len >= sizeof(u16_t)) {
		handle = net_buf_simple_pull_le16(&(buf)->b);
		;
		data.err = 0x01;
		bt_gatt_foreach_attr(handle, handle, read_cb, &data);
		if (data.err) {
			net_buf_unref(data.buf);
			send_err_rsp(conn, 0x0e, handle,
					data.err);
			return 0;
		}
	}
	bt_l2cap_send_cb(conn, 0x0004, data.buf, att_rsp_sent);
	return 0;
}
struct read_group_data {
	struct bt_att *att;
	struct bt_uuid *uuid;
	struct net_buf *buf;
	struct bt_att_read_group_rsp *rsp;
	struct bt_att_group_data *group;
};
static u8_t read_group_cb(const struct bt_gatt_attr *attr, void *user_data)
{
	struct read_group_data *data = user_data;
	struct bt_att *att = data->att;
	struct bt_conn *conn = att->chan.chan.conn;
	int read;
	if (bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) (&(struct bt_uuid_16) { .uuid.type = BT_UUID_TYPE_16, .val = (0x2800), }))) &&
			bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) (&(struct bt_uuid_16) { .uuid.type = BT_UUID_TYPE_16, .val = (0x2801), })))) {
		if (data->group && attr->handle > data->group->end_handle) {
			data->group->end_handle = (attr->handle);
		}
		return BT_GATT_ITER_CONTINUE;
	}
	if (bt_uuid_cmp(attr->uuid, data->uuid)) {
		data->group = 
			((void *)0)
			;
		return BT_GATT_ITER_CONTINUE;
	}
	;
	if (data->rsp->len &&
			att->chan.tx.mtu - data->buf->len < data->rsp->len) {
		return BT_GATT_ITER_STOP;
	}
	data->group = net_buf_simple_add(&(data->buf)->b, sizeof(*data->group));
	data->group->start_handle = (attr->handle);
	data->group->end_handle = (attr->handle);
	read = attr->read(conn, attr, data->buf->data + data->buf->len,
			att->chan.tx.mtu - data->buf->len, 0);
	if (read < 0) {
		return BT_GATT_ITER_STOP;
	}
	if (!data->rsp->len) {
		data->rsp->len = read + sizeof(*data->group);
	} else if (data->rsp->len != read + sizeof(*data->group)) {
		data->buf->len -= sizeof(*data->group);
		return 
			0
			;
	}
	net_buf_simple_add(&(data->buf)->b, read);
	return BT_GATT_ITER_CONTINUE;
}
static u8_t att_read_group_rsp(struct bt_att *att, struct bt_uuid *uuid,
		u16_t start_handle, u16_t end_handle)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct read_group_data data;
	memset(&data, 0, sizeof(data));
	data.buf = bt_att_create_pdu(conn, 0x11,
			sizeof(*data.rsp));
	if (!data.buf) {
		return 0x0e;
	}
	data.att = att;
	data.uuid = uuid;
	data.rsp = net_buf_simple_add(&(data.buf)->b, sizeof(*data.rsp));
	data.rsp->len = 0;
	data.group = 
		((void *)0)
		;
	bt_gatt_foreach_attr(start_handle, end_handle, read_group_cb, &data);
	if (!data.rsp->len) {
		net_buf_unref(data.buf);
		send_err_rsp(conn, 0x10, start_handle,
				0x0a);
		return 0;
	}
	bt_l2cap_send_cb(conn, 0x0004, data.buf, att_rsp_sent);
	return 0;
}
static u8_t att_read_group_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct bt_att_read_group_req *req;
	u16_t start_handle, end_handle, err_handle;
	union {
		struct bt_uuid uuid;
		struct bt_uuid_16 u16;
		struct bt_uuid_128 u128;
	} u;
	if (buf->len != sizeof(*req) + 2 && buf->len != sizeof(*req) + 16) {
		return 0x04;
	}
	req = (void *)buf->data;
	start_handle = (req->start_handle);
	end_handle = (req->end_handle);
	net_buf_simple_pull(&(buf)->b, sizeof(*req));
	if (!uuid_create(&u.uuid, buf)) {
		return 0x0e;
	}
	;
	if (!range_is_valid(start_handle, end_handle, &err_handle)) {
		send_err_rsp(conn, 0x10, err_handle,
				0x01);
		return 0;
	}
	if (bt_uuid_cmp(&u.uuid, ((struct bt_uuid *) (&(struct bt_uuid_16) { .uuid.type = BT_UUID_TYPE_16, .val = (0x2800), }))) &&
			bt_uuid_cmp(&u.uuid, ((struct bt_uuid *) (&(struct bt_uuid_16) { .uuid.type = BT_UUID_TYPE_16, .val = (0x2801), })))) {
		send_err_rsp(conn, 0x10, start_handle,
				0x10);
		return 0;
	}
	return att_read_group_rsp(att, &u.uuid, start_handle, end_handle);
}
struct write_data {
	struct bt_conn *conn;
	struct net_buf *buf;
	u8_t op;
	const void *value;
	u8_t len;
	u16_t offset;
	u8_t err;
};
static u8_t write_cb(const struct bt_gatt_attr *attr, void *user_data)
{
	struct write_data *data = user_data;
	int write;
	;
	data->err = check_perm(data->conn, attr, (BT_GATT_PERM_WRITE | BT_GATT_PERM_WRITE_ENCRYPT | BT_GATT_PERM_WRITE_AUTHEN));
	if (data->err) {
		return BT_GATT_ITER_STOP;
	}
	write = attr->write(data->conn, attr, data->value, data->len,
			data->offset, 0);
	if (write < 0 || write != data->len) {
		data->err = err_to_att(write);
		return BT_GATT_ITER_STOP;
	}
	data->err = 0;
	return BT_GATT_ITER_CONTINUE;
}
static u8_t att_write_rsp(struct bt_conn *conn, u8_t op, u8_t rsp,
		u16_t handle, u16_t offset, const void *value,
		u8_t len)
{
	struct write_data data;
	if (!handle) {
		return 0x01;
	}
	memset(&data, 0, sizeof(data));
	if (rsp) {
		data.buf = bt_att_create_pdu(conn, rsp, 0);
		if (!data.buf) {
			return 0x0e;
		}
	}
	data.conn = conn;
	data.op = op;
	data.offset = offset;
	data.value = value;
	data.len = len;
	data.err = 0x01;
	bt_gatt_foreach_attr(handle, handle, write_cb, &data);
	if (data.err) {
		if (rsp) {
			net_buf_unref(data.buf);
			send_err_rsp(conn, op, handle, data.err);
		}
		return op == 0x18 ? data.err : 0;
	}
	if (data.buf) {
		bt_l2cap_send_cb(conn, 0x0004, data.buf,
				att_rsp_sent);
	}
	return 0;
}
static u8_t att_write_req(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	u16_t handle;
	handle = net_buf_simple_pull_le16(&(buf)->b);
	;
	return att_write_rsp(conn, 0x12, 0x13,
			handle, 0, buf->data, buf->len);
}
static u8_t att_prepare_write_req(struct bt_att *att, struct net_buf *buf)
{
	return 0x06;
}
static u8_t att_exec_write_req(struct bt_att *att, struct net_buf *buf)
{
	return 0x06;
}
static u8_t att_write_cmd(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	u16_t handle;
	handle = net_buf_simple_pull_le16(&(buf)->b);
	;
	return att_write_rsp(conn, 0, 0, handle, 0, buf->data, buf->len);
}
static u8_t att_signed_write_cmd(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	struct bt_att_signed_write_cmd *req;
	u16_t handle;
	int err;
	req = (void *)buf->data;
	handle = (req->handle);
	;
	net_buf_simple_push(&(buf)->b, sizeof(struct bt_att_hdr));
	err = bt_smp_sign_verify(conn, buf);
	if (err) {
		;
		return 0;
	}
	net_buf_simple_pull(&(buf)->b, sizeof(struct bt_att_hdr));
	net_buf_simple_pull(&(buf)->b, sizeof(*req));
	return att_write_rsp(conn, 0, 0, handle, 0, buf->data,
			buf->len - sizeof(struct bt_att_signature));
}
static int att_change_security(struct bt_conn *conn, u8_t err)
{
	bt_security_t sec;
	switch (err) {
		case 0x0f:
			if (conn->sec_level >= BT_SECURITY_MEDIUM)
				return -69;
			sec = BT_SECURITY_MEDIUM;
			break;
		case 0x05:
			if (conn->sec_level < BT_SECURITY_MEDIUM) {
				sec = BT_SECURITY_MEDIUM;
			} else if (conn->sec_level < BT_SECURITY_HIGH) {
				sec = BT_SECURITY_HIGH;
			} else if (conn->sec_level < BT_SECURITY_FIPS) {
				sec = BT_SECURITY_FIPS;
			} else {
				return -69;
			}
			break;
		default:
			return -22;
	}
	return bt_conn_security(conn, sec);
}
static u8_t att_error_rsp(struct bt_att *att, struct net_buf *buf)
{
	struct bt_att_error_rsp *rsp;
	u8_t err;
	rsp = (void *)buf->data;
	;
	if (!att->req) {
		err = 0x0e;
		goto done;
	}
	if (att->req->buf) {
		net_buf_simple_restore(&att->req->buf->b, &att->req->state);
	}
	err = rsp->error;
	if (att->req->retrying) {
		goto done;
	}
	if (!att_change_security(att->chan.chan.conn, err)) {
		att->req->retrying = 
			1
			;
		return 0;
	}
done:
	return att_handle_rsp(att, 
			((void *)0)
			, 0, err);
}
static u8_t att_handle_find_info_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_find_type_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_read_type_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_read_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_read_blob_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_read_mult_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_write_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_prepare_write_rsp(struct bt_att *att,
		struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_handle_exec_write_rsp(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static u8_t att_notify(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	u16_t handle;
	handle = net_buf_simple_pull_le16(&(buf)->b);
	;
	bt_gatt_notification(conn, handle, buf->data, buf->len);
	return 0;
}
static u8_t att_indicate(struct bt_att *att, struct net_buf *buf)
{
	struct bt_conn *conn = att->chan.chan.conn;
	u16_t handle;
	handle = net_buf_simple_pull_le16(&(buf)->b);
	;
	bt_gatt_notification(conn, handle, buf->data, buf->len);
	buf = bt_att_create_pdu(conn, 0x1e, 0);
	if (!buf) {
		return 0;
	}
	bt_l2cap_send_cb(conn, 0x0004, buf, att_cfm_sent);
	return 0;
}
static u8_t att_confirm(struct bt_att *att, struct net_buf *buf)
{
	;
	return att_handle_rsp(att, buf->data, buf->len, 0);
}
static const struct att_handler {
	u8_t op;
	u8_t expect_len;
	att_type_t type;
	u8_t (*func)(struct bt_att *att, struct net_buf *buf);
} handlers[] = {
	{ 0x01,
		sizeof(struct bt_att_error_rsp),
		ATT_RESPONSE,
		att_error_rsp },
	{ 0x02,
		sizeof(struct bt_att_exchange_mtu_req),
		ATT_REQUEST,
		att_mtu_req },
	{ 0x03,
		sizeof(struct bt_att_exchange_mtu_rsp),
		ATT_RESPONSE,
		att_mtu_rsp },
	{ 0x04,
		sizeof(struct bt_att_find_info_req),
		ATT_REQUEST,
		att_find_info_req },
	{ 0x05,
		sizeof(struct bt_att_find_info_rsp),
		ATT_RESPONSE,
		att_handle_find_info_rsp },
	{ 0x06,
		sizeof(struct bt_att_find_type_req),
		ATT_REQUEST,
		att_find_type_req },
	{ 0x07,
		sizeof(struct bt_att_find_type_rsp),
		ATT_RESPONSE,
		att_handle_find_type_rsp },
	{ 0x08,
		sizeof(struct bt_att_read_type_req),
		ATT_REQUEST,
		att_read_type_req },
	{ 0x09,
		sizeof(struct bt_att_read_type_rsp),
		ATT_RESPONSE,
		att_handle_read_type_rsp },
	{ 0x0a,
		sizeof(struct bt_att_read_req),
		ATT_REQUEST,
		att_read_req },
	{ 0x0b,
		sizeof(struct bt_att_read_rsp),
		ATT_RESPONSE,
		att_handle_read_rsp },
	{ 0x0c,
		sizeof(struct bt_att_read_blob_req),
		ATT_REQUEST,
		att_read_blob_req },
	{ 0x0d,
		sizeof(struct bt_att_read_blob_rsp),
		ATT_RESPONSE,
		att_handle_read_blob_rsp },
	{ 0x0e,
		0x04,
		ATT_REQUEST,
		att_read_mult_req },
	{ 0x0f,
		sizeof(struct bt_att_read_mult_rsp),
		ATT_RESPONSE,
		att_handle_read_mult_rsp },
	{ 0x10,
		sizeof(struct bt_att_read_group_req),
		ATT_REQUEST,
		att_read_group_req },
	{ 0x12,
		sizeof(struct bt_att_write_req),
		ATT_REQUEST,
		att_write_req },
	{ 0x13,
		0,
		ATT_RESPONSE,
		att_handle_write_rsp },
	{ 0x16,
		sizeof(struct bt_att_prepare_write_req),
		ATT_REQUEST,
		att_prepare_write_req },
	{ 0x17,
		sizeof(struct bt_att_prepare_write_rsp),
		ATT_RESPONSE,
		att_handle_prepare_write_rsp },
	{ 0x18,
		sizeof(struct bt_att_exec_write_req),
		ATT_REQUEST,
		att_exec_write_req },
	{ 0x19,
		0,
		ATT_RESPONSE,
		att_handle_exec_write_rsp },
	{ 0x1b,
		sizeof(struct bt_att_notify),
		ATT_NOTIFICATION,
		att_notify },
	{ 0x1d,
		sizeof(struct bt_att_indicate),
		ATT_INDICATION,
		att_indicate },
	{ 0x1e,
		0,
		ATT_CONFIRMATION,
		att_confirm },
	{ 0x52,
		sizeof(struct bt_att_write_cmd),
		ATT_COMMAND,
		att_write_cmd },
	{ 0xd2,
		(sizeof(struct bt_att_write_cmd) +
		 sizeof(struct bt_att_signature)),
		ATT_COMMAND,
		att_signed_write_cmd },
};
static att_type_t att_op_get_type(u8_t op)
{
	int i;
	for (i = 0; i < ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(handlers), __typeof__(&(handlers)[0])))]) - 1) + (sizeof(handlers) / sizeof((handlers)[0])))); i++) {
		if (op == handlers[i].op) {
			return handlers[i].type;
		}
	}
	if (op & 0x40) {
		return ATT_COMMAND;
	}
	return ATT_UNKNOWN;
}
static void bt_att_recv(struct bt_l2cap_chan *chan, struct net_buf *buf)
{
	struct bt_att *att = ((struct bt_att *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					chan.chan
					)
				));
	struct bt_att_hdr *hdr = (void *)buf->data;
	const struct att_handler *handler;
	u8_t err;
	size_t i;
	if (buf->len < sizeof(*hdr)) {
		;
		return;
	}
	;
	net_buf_simple_pull(&(buf)->b, sizeof(*hdr));
	for (i = 0, handler = 
			((void *)0)
			; i < ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(handlers), __typeof__(&(handlers)[0])))]) - 1) + (sizeof(handlers) / sizeof((handlers)[0])))); i++) {
		if (hdr->code == handlers[i].op) {
			handler = &handlers[i];
			break;
		}
	}
	if (!handler) {
		;
		if (att_op_get_type(hdr->code) != ATT_COMMAND) {
			send_err_rsp(chan->conn, hdr->code, 0,
					0x06);
		}
		return;
	}
	if (0) {
		if (handler->type == ATT_REQUEST &&
				atomic_test_and_set_bit(att->flags, ATT_PENDING_RSP)) {
			;
			return;
		} else if (handler->type == ATT_INDICATION &&
				atomic_test_and_set_bit(att->flags,
					ATT_PENDING_CFM)) {
			;
			return;
		}
	}
	if (buf->len < handler->expect_len) {
		;
		err = 0x04;
	} else {
		err = handler->func(att, buf);
	}
	if (handler->type == ATT_REQUEST && err) {
		;
		send_err_rsp(chan->conn, hdr->code, 0, err);
	}
}
static struct bt_att *att_chan_get(struct bt_conn *conn)
{
	struct bt_l2cap_chan *chan;
	struct bt_att *att;
	if (conn->state != BT_CONN_CONNECTED) {
		;
		return 
			((void *)0)
			;
	}
	chan = bt_l2cap_le_lookup_rx_cid(conn, 0x0004);
	if (!chan) {
		;
		return 
			((void *)0)
			;
	}
	att = ((struct bt_att *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					chan.chan
					)
				));
	if (atomic_test_bit(att->flags, ATT_DISCONNECTED)) {
		;
		return 
			((void *)0)
			;
	}
	return att;
}
struct net_buf *bt_att_create_pdu(struct bt_conn *conn, u8_t op, size_t len)
{
	struct bt_att_hdr *hdr;
	struct net_buf *buf;
	struct bt_att *att;
	att = att_chan_get(conn);
	if (!att) {
		return 
			((void *)0)
			;
	}
	if (len + sizeof(op) > att->chan.tx.mtu) {
		;
		return 
			((void *)0)
			;
	}
	buf = bt_l2cap_create_pdu(
			((void *)0)
			, 0);
	hdr = net_buf_simple_add(&(buf)->b, sizeof(*hdr));
	hdr->code = op;
	return buf;
}
static void att_reset(struct bt_att *att)
{
	struct bt_att_req *req, *tmp;
	int i;
	atomic_set_bit(att->flags, ATT_DISCONNECTED);
	for (i = 0; i < 1; i++) {
		k_sem_give(&att->tx_sem);
	}
	for (req = ((sys_slist_peek_head(&att->reqs)) ? ((__typeof__(*(req)) *)(((char *)((sys_slist_peek_head(&att->reqs)))) - 
						__builtin_offsetof (
							__typeof__(*(req))
							, 
							node
							)
						)) : 
				((void *)0)
		   ), tmp = ((req) ? ((sys_slist_peek_next(&((req)->node))) ? ((__typeof__(*(req)) *)(((char *)((sys_slist_peek_next(&((req)->node))))) - 
						   __builtin_offsetof (
							   __typeof__(*(req))
							   , 
							   node
							   )
						   )) : 
				   ((void *)0)
				   ) : 
			   ((void *)0)
			   ); req; req = tmp, tmp = ((req) ? ((sys_slist_peek_next(&((req)->node))) ? ((__typeof__(*(req)) *)(((char *)((sys_slist_peek_next(&((req)->node))))) - 
							   __builtin_offsetof (
								   __typeof__(*(req))
								   , 
								   node
								   )
							   )) : 
					   ((void *)0)
					   ) : 
				   ((void *)0)
				   )) {
					   if (req->func) {
						   req->func(
								   ((void *)0)
								   , 0x0e, 
								   ((void *)0)
								   , 0, req);
					   }
					   att_req_destroy(req);
				   }
	sys_slist_init(&att->reqs);
	if (!att->req) {
		return;
	}
	att_handle_rsp(att, 
			((void *)0)
			, 0, 0x0e);
}
static void att_timeout(struct k_work *work)
{
	struct bt_att *att = ((struct bt_att *)(((char *)(work)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					timeout_work
					)
				));
	struct bt_l2cap_le_chan *ch = &att->chan;
	;
	att_reset(att);
	bt_gatt_disconnected(ch->chan.conn);
	ch->chan.conn = 
		((void *)0)
		;
}
static void bt_att_connected(struct bt_l2cap_chan *chan)
{
	struct bt_att *att = ((struct bt_att *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					chan.chan
					)
				));
	struct bt_l2cap_le_chan *ch = ((struct bt_l2cap_le_chan *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_l2cap_le_chan
					, 
					chan
					)
				));
	;
	ch->tx.mtu = 23;
	ch->rx.mtu = 23;
	k_delayed_work_init(&att->timeout_work, att_timeout);
	sys_slist_init(&att->reqs);
	bt_gatt_connected(ch->chan.conn);
}
static void bt_att_disconnected(struct bt_l2cap_chan *chan)
{
	struct bt_att *att = ((struct bt_att *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					chan.chan
					)
				));
	struct bt_l2cap_le_chan *ch = ((struct bt_l2cap_le_chan *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_l2cap_le_chan
					, 
					chan
					)
				));
	;
	att_reset(att);
	bt_gatt_disconnected(ch->chan.conn);
	memset(att, 0, sizeof(*att));
}
static void bt_att_encrypt_change(struct bt_l2cap_chan *chan,
		u8_t hci_status)
{
	struct bt_att *att = ((struct bt_att *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_att
					, 
					chan.chan
					)
				));
	struct bt_l2cap_le_chan *ch = ((struct bt_l2cap_le_chan *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_l2cap_le_chan
					, 
					chan
					)
				));
	struct bt_conn *conn = ch->chan.conn;
	;
	if (hci_status) {
		att_handle_rsp(att, 
				((void *)0)
				, 0, 0x05);
		return;
	}
	if (conn->sec_level == BT_SECURITY_LOW) {
		return;
	}
	if (!att->req || !att->req->retrying) {
		return;
	}
	k_sem_take(&att->tx_sem, -1);
	if (!att_is_connected(att)) {
		;
		k_sem_give(&att->tx_sem);
		return;
	}
	;
	bt_l2cap_send_cb(conn, 0x0004, att->req->buf,
			att_cb(att->req->buf));
	att->req->buf = 
		((void *)0)
		;
}
static int bt_att_accept(struct bt_conn *conn, struct bt_l2cap_chan **chan)
{
	int i;
	static struct bt_l2cap_chan_ops ops = {
		.connected = bt_att_connected,
		.disconnected = bt_att_disconnected,
		.recv = bt_att_recv,
		.encrypt_change = bt_att_encrypt_change,
	};
	;
	for (i = 0; i < ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(bt_req_pool), __typeof__(&(bt_req_pool)[0])))]) - 1) + (sizeof(bt_req_pool) / sizeof((bt_req_pool)[0])))); i++) {
		struct bt_att *att = &bt_req_pool[i];
		if (att->chan.chan.conn) {
			continue;
		}
		att->chan.chan.ops = &ops;
		atomic_set(att->flags, 0);
		k_sem_init(&att->tx_sem, 1,
				1);
		*chan = &att->chan.chan;
		return 0;
	}
	;
	return -12;
}
void bt_att_init(void)
{
	static struct bt_l2cap_fixed_chan chan = {
		.cid = 0x0004,
		.accept = bt_att_accept,
	};
	bt_l2cap_le_fixed_chan_register(&chan);
	bt_gatt_init();
}
u16_t bt_att_get_mtu(struct bt_conn *conn)
{
	struct bt_att *att;
	att = att_chan_get(conn);
	if (!att) {
		return 0;
	}
	return att->chan.tx.mtu;
}
int bt_att_send(struct bt_conn *conn, struct net_buf *buf)
{
	struct bt_att *att;
	struct bt_att_hdr *hdr;
	if (!conn || !buf) {
		return -22;
	}
	att = att_chan_get(conn);
	if (!att) {
		return -57;
	}
	k_sem_take(&att->tx_sem, -1);
	if (!att_is_connected(att)) {
		;
		k_sem_give(&att->tx_sem);
		return -57;
	}
	hdr = (void *)buf->data;
	;
	if (hdr->code == 0xd2) {
		int err;
		err = bt_smp_sign(conn, buf);
		if (err) {
			;
			k_sem_give(&att->tx_sem);
			return err;
		}
	}
	bt_l2cap_send_cb(conn, 0x0004, buf, att_cb(buf));
	return 0;
}
int bt_att_req_send(struct bt_conn *conn, struct bt_att_req *req)
{
	struct bt_att *att;
	;
	if (!conn || !req) {
		return -22;
	}
	att = att_chan_get(conn);
	if (!att) {
		return -57;
	}
	if (att->req) {
		sys_slist_append(&att->reqs, &req->node);
		return 0;
	}
	return att_send_req(att, req);
}
void bt_att_req_cancel(struct bt_conn *conn, struct bt_att_req *req)
{
	struct bt_att *att;
	;
	if (!conn || !req) {
		return;
	}
	att = att_chan_get(conn);
	if (!att) {
		return;
	}
	if (att->req == req) {
		att->req = 
			((void *)0)
			;
	} else {
		sys_slist_find_and_remove(&att->reqs, &req->node);
	}
	att_req_destroy(req);
}
