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
static inline size_t stack_unused_space_get(const char *stack, size_t size)
{
	return 0;
}
static inline void stack_analyze(const char *name, const char *stack,
		unsigned int size)
{
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
typedef struct tc_aes_key_sched_struct {
	unsigned int words[(4)*((10)+1)];
} *TCAesKeySched_t;
int tc_aes128_set_encrypt_key(TCAesKeySched_t s, const uint8_t *k);
int tc_aes_encrypt(uint8_t *out, const uint8_t *in,
		const TCAesKeySched_t s);
int tc_aes128_set_decrypt_key(TCAesKeySched_t s, const uint8_t *k);
int tc_aes_decrypt(uint8_t *out, const uint8_t *in,
		const TCAesKeySched_t s);
unsigned int _copy(uint8_t *to, unsigned int to_len,
		const uint8_t *from, unsigned int from_len);
void _set(void *to, uint8_t val, unsigned int len);
uint8_t _double_byte(uint8_t a);
int _compare(const uint8_t *a, const uint8_t *b, size_t size);
typedef struct tc_cmac_struct {
	uint8_t iv[((4)*(4))];
	uint8_t K1[((4)*(4))];
	uint8_t K2[((4)*(4))];
	uint8_t leftover[((4)*(4))];
	unsigned int keyid;
	unsigned int leftover_offset;
	TCAesKeySched_t sched;
	uint64_t countdown;
} *TCCmacState_t;
int tc_cmac_setup(TCCmacState_t s, const uint8_t *key,
		TCAesKeySched_t sched);
int tc_cmac_erase(TCCmacState_t s);
int tc_cmac_init(TCCmacState_t s);
int tc_cmac_update(TCCmacState_t s, const uint8_t *data, size_t dlen);
int tc_cmac_final(uint8_t *tag, TCCmacState_t s);
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
struct bt_pub_key_cb {
	void (*func)(const u8_t key[64]);
	struct bt_pub_key_cb *_next;
};
int bt_pub_key_gen(struct bt_pub_key_cb *cb);
const u8_t *bt_pub_key_get(void);
typedef void (*bt_dh_key_cb_t)(const u8_t key[32]);
int bt_dh_key_gen(const u8_t remote_pk[64], bt_dh_key_cb_t cb);
enum {
	BT_KEYS_SLAVE_LTK = (1UL << (0)),
	BT_KEYS_IRK = (1UL << (1)),
	BT_KEYS_LTK = (1UL << (2)),
	BT_KEYS_LOCAL_CSRK = (1UL << (3)),
	BT_KEYS_REMOTE_CSRK = (1UL << (4)),
	BT_KEYS_LTK_P256 = (1UL << (5)),
	BT_KEYS_ALL = (BT_KEYS_SLAVE_LTK | BT_KEYS_IRK |
			BT_KEYS_LTK | BT_KEYS_LOCAL_CSRK |
			BT_KEYS_REMOTE_CSRK | BT_KEYS_LTK_P256),
};
enum {
	BT_KEYS_AUTHENTICATED,
	BT_KEYS_DEBUG,
	BT_KEYS_ID_PENDING_ADD,
	BT_KEYS_ID_PENDING_DEL,
	BT_KEYS_NUM_FLAGS,
};
struct bt_ltk {
	u64_t rand;
	u16_t ediv;
	u8_t val[16];
};
struct bt_irk {
	u8_t val[16];
	bt_addr_t rpa;
};
struct bt_csrk {
	u8_t val[16];
	u32_t cnt;
};
struct bt_keys {
	bt_addr_le_t addr;
	u8_t enc_size;
	atomic_t flags[1 + ((BT_KEYS_NUM_FLAGS) - 1) / (sizeof(atomic_val_t) * 8)];
	u16_t keys;
	struct bt_ltk ltk;
	struct bt_irk irk;
	struct bt_ltk slave_ltk;
};
void bt_keys_foreach(int type, void (*func)(struct bt_keys *keys));
struct bt_keys *bt_keys_get_addr(const bt_addr_le_t *addr);
struct bt_keys *bt_keys_get_type(int type, const bt_addr_le_t *addr);
struct bt_keys *bt_keys_find(int type, const bt_addr_le_t *addr);
struct bt_keys *bt_keys_find_irk(const bt_addr_le_t *addr);
struct bt_keys *bt_keys_find_addr(const bt_addr_le_t *addr);
void bt_keys_add_type(struct bt_keys *keys, int type);
void bt_keys_clear(struct bt_keys *keys);
void bt_keys_clear_all(void);
enum {
	BT_LINK_KEY_AUTHENTICATED,
	BT_LINK_KEY_DEBUG,
	BT_LINK_KEY_SC,
	BT_LINK_KEY_NUM_FLAGS,
};
struct bt_keys_link_key {
	bt_addr_t addr;
	atomic_t flags[1 + ((BT_LINK_KEY_NUM_FLAGS) - 1) / (sizeof(atomic_val_t) * 8)];
	u8_t val[16];
};
struct bt_keys_link_key *bt_keys_get_link_key(const bt_addr_t *addr);
struct bt_keys_link_key *bt_keys_find_link_key(const bt_addr_t *addr);
void bt_keys_link_key_clear(struct bt_keys_link_key *link_key);
void bt_keys_link_key_clear_addr(const bt_addr_t *addr);
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
	enum pairing_method {
		JUST_WORKS,
		PASSKEY_INPUT,
		PASSKEY_DISPLAY,
		PASSKEY_CONFIRM,
		PASSKEY_ROLE,
	};
enum {
	SMP_FLAG_CFM_DELAYED,
	SMP_FLAG_ENC_PENDING,
	SMP_FLAG_KEYS_DISTR,
	SMP_FLAG_PAIRING,
	SMP_FLAG_TIMEOUT,
	SMP_FLAG_SC,
	SMP_FLAG_PKEY_SEND,
	SMP_FLAG_DHKEY_PENDING,
	SMP_FLAG_DHKEY_SEND,
	SMP_FLAG_USER,
	SMP_FLAG_BOND,
	SMP_FLAG_SC_DEBUG_KEY,
	SMP_FLAG_SEC_REQ,
	SMP_FLAG_DHCHECK_WAIT,
	SMP_FLAG_DERIVE_LK,
	SMP_FLAG_BR_CONNECTED,
	SMP_FLAG_BR_PAIR,
	SMP_FLAG_CT2,
	SMP_NUM_FLAGS,
};
struct bt_smp {
	struct bt_l2cap_le_chan chan;
	atomic_t allowed_cmds;
	atomic_t flags[1 + ((SMP_NUM_FLAGS) - 1) / (sizeof(atomic_val_t) * 8)];
	u8_t method;
	u8_t preq[7];
	u8_t prsp[7];
	u8_t pcnf[16];
	u8_t prnd[16];
	u8_t rrnd[16];
	u8_t tk[16];
	u8_t pkey[64];
	u8_t dhkey[32];
	u8_t e[16];
	u8_t mackey[16];
	u32_t passkey;
	u8_t passkey_round;
	u8_t local_dist;
	u8_t remote_dist;
	struct k_delayed_work work;
};
static const u8_t gen_method_legacy[5 ][5 ] = {
	{ JUST_WORKS, JUST_WORKS, PASSKEY_INPUT, JUST_WORKS, PASSKEY_INPUT },
	{ JUST_WORKS, JUST_WORKS, PASSKEY_INPUT, JUST_WORKS, PASSKEY_INPUT },
	{
		PASSKEY_DISPLAY, PASSKEY_DISPLAY, PASSKEY_INPUT, JUST_WORKS,
		PASSKEY_DISPLAY
	},
	{ JUST_WORKS, JUST_WORKS, JUST_WORKS, JUST_WORKS, JUST_WORKS },
	{
		PASSKEY_DISPLAY, PASSKEY_DISPLAY, PASSKEY_INPUT, JUST_WORKS,
		PASSKEY_ROLE
	},
};
static const u8_t gen_method_sc[5 ][5 ] = {
	{ JUST_WORKS, JUST_WORKS, PASSKEY_INPUT, JUST_WORKS, PASSKEY_INPUT },
	{
		JUST_WORKS, PASSKEY_CONFIRM, PASSKEY_INPUT, JUST_WORKS,
		PASSKEY_CONFIRM
	},
	{
		PASSKEY_DISPLAY, PASSKEY_DISPLAY, PASSKEY_INPUT, JUST_WORKS,
		PASSKEY_DISPLAY
	},
	{ JUST_WORKS, JUST_WORKS, JUST_WORKS, JUST_WORKS, JUST_WORKS },
	{
		PASSKEY_DISPLAY, PASSKEY_CONFIRM, PASSKEY_INPUT, JUST_WORKS,
		PASSKEY_CONFIRM
	},
};
static const u8_t sc_debug_public_key[64] = {
	0xe6, 0x9d, 0x35, 0x0e, 0x48, 0x01, 0x03, 0xcc, 0xdb, 0xfd, 0xf4, 0xac,
	0x11, 0x91, 0xf4, 0xef, 0xb9, 0xa5, 0xf9, 0xe9, 0xa7, 0x83, 0x2c, 0x5e,
	0x2c, 0xbe, 0x97, 0xf2, 0xd2, 0x03, 0xb0, 0x20, 0x8b, 0xd2, 0x89, 0x15,
	0xd0, 0x8e, 0x1c, 0x74, 0x24, 0x30, 0xed, 0x8f, 0xc2, 0x45, 0x63, 0x76,
	0x5c, 0x15, 0x52, 0x5a, 0xbf, 0x9a, 0x32, 0x63, 0x6d, 0xeb, 0x2a, 0x65,
	0x49, 0x9c, 0x80, 0xdc
};
static struct bt_smp bt_smp_pool[1];
static 
_Bool 
sc_supported;
static 
_Bool 
sc_local_pkey_valid;
static u8_t sc_public_key[64];
static u8_t get_io_capa(void)
{
	if (!bt_auth) {
		return 0x03;
	}
	if (bt_auth->passkey_display && bt_auth->passkey_entry &&
			(bt_auth->passkey_confirm || !sc_supported)) {
		return 0x04;
	}
	if (sc_supported && bt_auth->passkey_display &&
			bt_auth->passkey_confirm) {
		return 0x01;
	}
	if (bt_auth->passkey_entry) {
		return 0x02;
	}
	if (bt_auth->passkey_display) {
		return 0x00;
	}
	return 0x03;
}
static u8_t get_pair_method(struct bt_smp *smp, u8_t remote_io)
{
	struct bt_smp_pairing *req, *rsp;
	if (remote_io > 0x04) {
		return JUST_WORKS;
	}
	req = (struct bt_smp_pairing *)&smp->preq[1];
	rsp = (struct bt_smp_pairing *)&smp->prsp[1];
	if (!((req->auth_req | rsp->auth_req) & 0x04)) {
		return JUST_WORKS;
	}
	return gen_method_sc[remote_io][get_io_capa()];
}
static struct net_buf *smp_create_pdu(struct bt_conn *conn, u8_t op,
		size_t len)
{
	struct bt_smp_hdr *hdr;
	struct net_buf *buf;
	buf = bt_l2cap_create_pdu(
			((void *)0)
			, 0);
	hdr = net_buf_simple_add(&(buf)->b, sizeof(*hdr));
	hdr->code = op;
	return buf;
}
static int bt_smp_aes_cmac(const u8_t *key, const u8_t *in, size_t len,
		u8_t *out)
{
	struct tc_aes_key_sched_struct sched;
	struct tc_cmac_struct state;
	if (tc_cmac_setup(&state, key, &sched) == 0) {
		return -5;
	}
	if (tc_cmac_update(&state, in, len) == 0) {
		return -5;
	}
	if (tc_cmac_final(out, &state) == 0) {
		return -5;
	}
	return 0;
}
static int smp_f4(const u8_t *u, const u8_t *v, const u8_t *x,
		u8_t z, u8_t res[16])
{
	u8_t xs[16];
	u8_t m[65];
	int err;
	;
	;
	;
	sys_memcpy_swap(m, u, 32);
	sys_memcpy_swap(m + 32, v, 32);
	m[64] = z;
	sys_memcpy_swap(xs, x, 16);
	err = bt_smp_aes_cmac(xs, m, sizeof(m), res);
	if (err) {
		return err;
	}
	sys_mem_swap(res, 16);
	;
	return err;
}
static int smp_f5(const u8_t *w, const u8_t *n1, const u8_t *n2,
		const bt_addr_le_t *a1, const bt_addr_le_t *a2, u8_t *mackey,
		u8_t *ltk)
{
	static const u8_t salt[16] = { 0x6c, 0x88, 0x83, 0x91, 0xaa, 0xf5,
		0xa5, 0x38, 0x60, 0x37, 0x0b, 0xdb,
		0x5a, 0x60, 0x83, 0xbe
	};
	u8_t m[53] = { 0x00,
		0x62, 0x74, 0x6c, 0x65,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x00
	};
	u8_t t[16], ws[32];
	int err;
	;
	;
	sys_memcpy_swap(ws, w, 32);
	err = bt_smp_aes_cmac(salt, ws, 32, t);
	if (err) {
		return err;
	}
	;
	sys_memcpy_swap(m + 5, n1, 16);
	sys_memcpy_swap(m + 21, n2, 16);
	m[37] = a1->type;
	sys_memcpy_swap(m + 38, a1->a.val, 6);
	m[44] = a2->type;
	sys_memcpy_swap(m + 45, a2->a.val, 6);
	err = bt_smp_aes_cmac(t, m, sizeof(m), mackey);
	if (err) {
		return err;
	}
	;
	sys_mem_swap(mackey, 16);
	m[0] = 0x01;
	err = bt_smp_aes_cmac(t, m, sizeof(m), ltk);
	if (err) {
		return err;
	}
	;
	sys_mem_swap(ltk, 16);
	return 0;
}
static int smp_f6(const u8_t *w, const u8_t *n1, const u8_t *n2,
		const u8_t *r, const u8_t *iocap, const bt_addr_le_t *a1,
		const bt_addr_le_t *a2, u8_t *check)
{
	u8_t ws[16];
	u8_t m[65];
	int err;
	;
	;
	;
	;
	sys_memcpy_swap(m, n1, 16);
	sys_memcpy_swap(m + 16, n2, 16);
	sys_memcpy_swap(m + 32, r, 16);
	sys_memcpy_swap(m + 48, iocap, 3);
	m[51] = a1->type;
	memcpy(m + 52, a1->a.val, 6);
	sys_memcpy_swap(m + 52, a1->a.val, 6);
	m[58] = a2->type;
	memcpy(m + 59, a2->a.val, 6);
	sys_memcpy_swap(m + 59, a2->a.val, 6);
	sys_memcpy_swap(ws, w, 16);
	err = bt_smp_aes_cmac(ws, m, sizeof(m), check);
	if (err) {
		return err;
	}
	;
	sys_mem_swap(check, 16);
	return 0;
}
static int smp_g2(const u8_t u[32], const u8_t v[32],
		const u8_t x[16], const u8_t y[16], u32_t *passkey)
{
	u8_t m[80], xs[16];
	int err;
	;
	;
	;
	sys_memcpy_swap(m, u, 32);
	sys_memcpy_swap(m + 32, v, 32);
	sys_memcpy_swap(m + 64, y, 16);
	sys_memcpy_swap(xs, x, 16);
	err = bt_smp_aes_cmac(xs, m, sizeof(m), xs);
	if (err) {
		return err;
	}
	;
	memcpy(passkey, xs + 12, 4);
	*passkey = ((u32_t) ((((*passkey) >> 24) & 0xff) | (((*passkey) >> 8) & 0xff00) | (((*passkey) & 0xff00) << 8) | (((*passkey) & 0xff) << 24))) % 1000000;
	;
	return 0;
}
static u8_t get_encryption_key_size(struct bt_smp *smp)
{
	struct bt_smp_pairing *req, *rsp;
	req = (struct bt_smp_pairing *)&smp->preq[1];
	rsp = (struct bt_smp_pairing *)&smp->prsp[1];
	return (((req->max_key_size) < (rsp->max_key_size)) ? (req->max_key_size) : (rsp->max_key_size));
}
static void smp_pairing_complete(struct bt_smp *smp, u8_t status);
static void smp_check_complete(struct bt_conn *conn, u8_t dist_complete)
{
	struct bt_l2cap_chan *chan;
	if (conn->type == BT_CONN_TYPE_LE) {
		struct bt_smp *smp;
		chan = bt_l2cap_le_lookup_tx_cid(conn, 0x0006);
		do { } while ((0));
		smp = ((struct bt_smp *)(((char *)(chan)) - 
					__builtin_offsetof (
						struct bt_smp
						, 
						chan
						)
					));
		smp->local_dist &= ~dist_complete;
		if (!smp->local_dist && !smp->remote_dist) {
			smp_pairing_complete(smp, 0);
		}
		return;
	}
}
static void smp_reset(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	k_delayed_work_cancel(&smp->work);
	smp->method = JUST_WORKS;
	atomic_set(&smp->allowed_cmds, 0);
	atomic_set(smp->flags, 0);
	if (conn->required_sec_level != conn->sec_level) {
		conn->required_sec_level = conn->sec_level;
	}
	if (0 &&
			conn->role == 0x00) {
		atomic_set_bit(&smp->allowed_cmds, 0x0b);
		return;
	}
	if (1) {
		atomic_set_bit(&smp->allowed_cmds, 0x01);
	}
}
static void smp_pairing_complete(struct bt_smp *smp, u8_t status)
{
	;
	smp_reset(smp);
}
static void smp_timeout(struct k_work *work)
{
	struct bt_smp *smp = ((struct bt_smp *)(((char *)(work)) - 
				__builtin_offsetof (
					struct bt_smp
					, 
					work
					)
				));
	;
	if (atomic_test_bit(smp->flags, SMP_FLAG_KEYS_DISTR) &&
			smp->chan.chan.conn->le.keys) {
		bt_keys_clear(smp->chan.chan.conn->le.keys);
	}
	smp_pairing_complete(smp, 0x08);
	atomic_set_bit(smp->flags, SMP_FLAG_TIMEOUT);
}
static void smp_send(struct bt_smp *smp, struct net_buf *buf,
		bt_conn_tx_cb_t cb)
{
	bt_l2cap_send_cb(smp->chan.chan.conn, 0x0006, buf, cb);
	k_delayed_work_submit(&smp->work, ((30) * 1000));
}
static int smp_error(struct bt_smp *smp, u8_t reason)
{
	struct bt_smp_pairing_fail *rsp;
	struct net_buf *buf;
	smp_pairing_complete(smp, reason);
	buf = smp_create_pdu(smp->chan.chan.conn, 0x05,
			sizeof(*rsp));
	if (!buf) {
		return -55;
	}
	rsp = net_buf_simple_add(&(buf)->b, sizeof(*rsp));
	rsp->reason = reason;
	bt_l2cap_send(smp->chan.chan.conn, 0x0006, buf);
	return 0;
}
static u8_t smp_send_pairing_random(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_pairing_random *req;
	struct net_buf *rsp_buf;
	rsp_buf = smp_create_pdu(conn, 0x04, sizeof(*req));
	if (!rsp_buf) {
		return 0x08;
	}
	req = net_buf_simple_add(&(rsp_buf)->b, sizeof(*req));
	memcpy(req->val, smp->prnd, sizeof(req->val));
	smp_send(smp, rsp_buf, 
			((void *)0)
		);
	return 0;
}
static void xor_128(const u8_t p[16], const u8_t q[16], u8_t r[16])
{
	size_t len = 16;
	while (len--) {
		*r++ = *p++ ^ *q++;
	}
}
static int smp_c1(const u8_t k[16], const u8_t r[16],
		const u8_t preq[7], const u8_t pres[7],
		const bt_addr_le_t *ia, const bt_addr_le_t *ra,
		u8_t enc_data[16])
{
	u8_t p1[16], p2[16];
	int err;
	;
	;
	;
	p1[0] = ia->type;
	p1[1] = ra->type;
	memcpy(p1 + 2, preq, 7);
	memcpy(p1 + 9, pres, 7);
	;
	xor_128(r, p1, enc_data);
	err = bt_encrypt_le(k, enc_data, enc_data);
	if (err) {
		return err;
	}
	memcpy(p2, ra->a.val, 6);
	memcpy(p2 + 6, ia->a.val, 6);
	memset(p2 + 12, 0, 4);
	;
	xor_128(enc_data, p2, enc_data);
	return bt_encrypt_le(k, enc_data, enc_data);
}
static u8_t smp_send_pairing_confirm(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_pairing_confirm *req;
	struct net_buf *buf;
	u8_t r;
	switch (smp->method) {
		case PASSKEY_CONFIRM:
		case JUST_WORKS:
			r = 0;
			break;
		case PASSKEY_DISPLAY:
		case PASSKEY_INPUT:
			r = (smp->passkey >> smp->passkey_round) & 0x01;
			r |= 0x80;
			break;
		default:
			return 0x08;
	}
	buf = smp_create_pdu(conn, 0x03, sizeof(*req));
	if (!buf) {
		return 0x08;
	}
	req = net_buf_simple_add(&(buf)->b, sizeof(*req));
	if (smp_f4(sc_public_key, smp->pkey, smp->prnd, r, req->val)) {
		net_buf_unref(buf);
		return 0x08;
	}
	smp_send(smp, buf, 
			((void *)0)
		);
	atomic_clear_bit(smp->flags, SMP_FLAG_CFM_DELAYED);
	return 0;
}
static void ident_sent(struct bt_conn *conn)
{
	smp_check_complete(conn, 0x01);
}
static void legacy_distribute_keys(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_keys *keys = conn->le.keys;
	if (smp->local_dist & 0x01) {
		struct bt_smp_encrypt_info *info;
		struct bt_smp_master_ident *ident;
		struct net_buf *buf;
		u8_t key[16];
		u64_t rand;
		u16_t ediv;
		bt_rand(key, sizeof(key));
		bt_rand(&rand, sizeof(rand));
		bt_rand(&ediv, sizeof(ediv));
		buf = smp_create_pdu(conn, 0x06,
				sizeof(*info));
		if (!buf) {
			;
			return;
		}
		info = net_buf_simple_add(&(buf)->b, sizeof(*info));
		memcpy(info->ltk, key, keys->enc_size);
		if (keys->enc_size < sizeof(info->ltk)) {
			memset(info->ltk + keys->enc_size, 0,
					sizeof(info->ltk) - keys->enc_size);
		}
		smp_send(smp, buf, 
				((void *)0)
			);
		buf = smp_create_pdu(conn, 0x07,
				sizeof(*ident));
		if (!buf) {
			;
			return;
		}
		ident = net_buf_simple_add(&(buf)->b, sizeof(*ident));
		ident->rand = rand;
		ident->ediv = ediv;
		smp_send(smp, buf, ident_sent);
		if (atomic_test_bit(smp->flags, SMP_FLAG_BOND)) {
			bt_keys_add_type(keys, BT_KEYS_SLAVE_LTK);
			memcpy(keys->slave_ltk.val, key,
					sizeof(keys->slave_ltk.val));
			keys->slave_ltk.rand = rand;
			keys->slave_ltk.ediv = ediv;
		}
	}
}
static void bt_smp_distribute_keys(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_keys *keys = conn->le.keys;
	if (!keys) {
		;
		return;
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		legacy_distribute_keys(smp);
	}
}
static u8_t send_pairing_rsp(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_pairing *rsp;
	struct net_buf *rsp_buf;
	rsp_buf = smp_create_pdu(conn, 0x02, sizeof(*rsp));
	if (!rsp_buf) {
		return 0x08;
	}
	rsp = net_buf_simple_add(&(rsp_buf)->b, sizeof(*rsp));
	memcpy(rsp, smp->prsp + 1, sizeof(*rsp));
	smp_send(smp, rsp_buf, 
			((void *)0)
		);
	return 0;
}
static int smp_s1(const u8_t k[16], const u8_t r1[16],
		const u8_t r2[16], u8_t out[16])
{
	memcpy(out, r2, 8);
	memcpy(out + 8, r1, 8);
	return bt_encrypt_le(k, out, out);
}
static u8_t legacy_get_pair_method(struct bt_smp *smp, u8_t remote_io)
{
	struct bt_smp_pairing *req, *rsp;
	u8_t method;
	if (remote_io > 0x04) {
		return JUST_WORKS;
	}
	req = (struct bt_smp_pairing *)&smp->preq[1];
	rsp = (struct bt_smp_pairing *)&smp->prsp[1];
	if (!((req->auth_req | rsp->auth_req) & 0x04)) {
		return JUST_WORKS;
	}
	method = gen_method_legacy[remote_io][get_io_capa()];
	if (method == PASSKEY_ROLE) {
		if (smp->chan.chan.conn->role == 0x00) {
			method = PASSKEY_DISPLAY;
		} else {
			method = PASSKEY_INPUT;
		}
	}
	return method;
}
static u8_t legacy_request_tk(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_keys *keys;
	u32_t passkey;
	keys = bt_keys_find_addr(&conn->le.dst);
	if (keys && atomic_test_bit(keys->flags, BT_KEYS_AUTHENTICATED) &&
			smp->method == JUST_WORKS) {
		;
		return 0x08;
	}
	switch (smp->method) {
		case PASSKEY_DISPLAY:
			if (bt_rand(&passkey, sizeof(passkey))) {
				return 0x08;
			}
			passkey %= 1000000;
			bt_auth->passkey_display(conn, passkey);
			passkey = (passkey);
			memcpy(smp->tk, &passkey, sizeof(passkey));
			break;
		case PASSKEY_INPUT:
			atomic_set_bit(smp->flags, SMP_FLAG_USER);
			bt_auth->passkey_entry(conn);
			break;
		case JUST_WORKS:
			break;
		default:
			;
			return 0x08;
	}
	return 0;
}
static u8_t legacy_send_pairing_confirm(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_pairing_confirm *req;
	struct net_buf *buf;
	buf = smp_create_pdu(conn, 0x03, sizeof(*req));
	if (!buf) {
		return 0x08;
	}
	req = net_buf_simple_add(&(buf)->b, sizeof(*req));
	if (smp_c1(smp->tk, smp->prnd, smp->preq, smp->prsp,
				&conn->le.init_addr, &conn->le.resp_addr, req->val)) {
		net_buf_unref(buf);
		return 0x08;
	}
	smp_send(smp, buf, 
			((void *)0)
		);
	atomic_clear_bit(smp->flags, SMP_FLAG_CFM_DELAYED);
	return 0;
}
static u8_t legacy_pairing_req(struct bt_smp *smp, u8_t remote_io)
{
	u8_t ret;
	;
	smp->method = legacy_get_pair_method(smp, remote_io);
	if (smp->method == JUST_WORKS &&
			!atomic_test_bit(smp->flags, SMP_FLAG_SEC_REQ) &&
			bt_auth && bt_auth->pairing_confirm) {
		atomic_set_bit(smp->flags, SMP_FLAG_USER);
		bt_auth->pairing_confirm(smp->chan.chan.conn);
		return 0;
	}
	ret = send_pairing_rsp(smp);
	if (ret) {
		return ret;
	}
	atomic_set_bit(&smp->allowed_cmds, 0x03);
	return legacy_request_tk(smp);
}
static u8_t legacy_pairing_random(struct bt_smp *smp)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	u8_t tmp[16];
	int err;
	;
	err = smp_c1(smp->tk, smp->rrnd, smp->preq, smp->prsp,
			&conn->le.init_addr, &conn->le.resp_addr, tmp);
	if (err) {
		return 0x08;
	}
	;
	if (memcmp(smp->pcnf, tmp, sizeof(smp->pcnf))) {
		return 0x04;
	}
	if (0 &&
			conn->role == 0x00) {
		err = smp_s1(smp->tk, smp->rrnd, smp->prnd, tmp);
		if (err) {
			return 0x08;
		}
		if (bt_conn_le_start_encryption(conn, 0, 0, tmp,
					get_encryption_key_size(smp))) {
			;
			return 0x08;
		}
		atomic_set_bit(smp->flags, SMP_FLAG_ENC_PENDING);
		return 0;
	}
	if (1) {
		err = smp_s1(smp->tk, smp->prnd, smp->rrnd, tmp);
		if (err) {
			return 0x08;
		}
		memcpy(smp->tk, tmp, sizeof(smp->tk));
		;
		atomic_set_bit(smp->flags, SMP_FLAG_ENC_PENDING);
		smp_send_pairing_random(smp);
	}
	return 0;
}
static u8_t legacy_pairing_confirm(struct bt_smp *smp)
{
	;
	if (0 &&
			smp->chan.chan.conn->role == 0x00) {
		atomic_set_bit(&smp->allowed_cmds, 0x03);
		return legacy_send_pairing_confirm(smp);
	}
	if (1) {
		if (!atomic_test_bit(smp->flags, SMP_FLAG_USER)) {
			atomic_set_bit(&smp->allowed_cmds,
					0x04);
			return legacy_send_pairing_confirm(smp);
		}
		atomic_set_bit(smp->flags, SMP_FLAG_CFM_DELAYED);
	}
	return 0;
}
static void legacy_passkey_entry(struct bt_smp *smp, unsigned int passkey)
{
	passkey = (passkey);
	memcpy(smp->tk, &passkey, sizeof(passkey));
	if (!atomic_test_and_clear_bit(smp->flags, SMP_FLAG_CFM_DELAYED)) {
		return;
	}
	if (legacy_pairing_confirm(smp)) {
		smp_error(smp, 0x01);
		return;
	}
	if (0 &&
			smp->chan.chan.conn->role == 0x00) {
		atomic_set_bit(&smp->allowed_cmds, 0x03);
		return;
	}
	if (1) {
		atomic_set_bit(&smp->allowed_cmds, 0x04);
	}
}
static u8_t smp_encrypt_info(struct bt_smp *smp, struct net_buf *buf)
{
	;
	if (atomic_test_bit(smp->flags, SMP_FLAG_BOND)) {
		struct bt_smp_encrypt_info *req = (void *)buf->data;
		struct bt_conn *conn = smp->chan.chan.conn;
		struct bt_keys *keys;
		keys = bt_keys_get_type(BT_KEYS_LTK, &conn->le.dst);
		if (!keys) {
			;
			return 0x08;
		}
		memcpy(keys->ltk.val, req->ltk, 16);
	}
	atomic_set_bit(&smp->allowed_cmds, 0x07);
	return 0;
}
static u8_t smp_master_ident(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	;
	if (atomic_test_bit(smp->flags, SMP_FLAG_BOND)) {
		struct bt_smp_master_ident *req = (void *)buf->data;
		struct bt_keys *keys;
		keys = bt_keys_get_type(BT_KEYS_LTK, &conn->le.dst);
		if (!keys) {
			;
			return 0x08;
		}
		keys->ltk.ediv = req->ediv;
		keys->ltk.rand = req->rand;
		smp->remote_dist &= ~0x01;
	}
	if (smp->remote_dist & 0x02) {
		atomic_set_bit(&smp->allowed_cmds, 0x08);
	} else if (smp->remote_dist & 0x04) {
		atomic_set_bit(&smp->allowed_cmds, 0x0a);
	}
	if (0 &&
			conn->role == 0x00 && !smp->remote_dist) {
		bt_smp_distribute_keys(smp);
	}
	if (!smp->local_dist && !smp->remote_dist) {
		smp_pairing_complete(smp, 0);
	}
	return 0;
}
static int smp_init(struct bt_smp *smp)
{
	memset((u8_t *)smp + sizeof(smp->chan), 0,
			sizeof(*smp) - (sizeof(smp->chan) + sizeof(smp->work)));
	if (bt_rand(smp->prnd, 16)) {
		return 0x08;
	}
	;
	atomic_set_bit(&smp->allowed_cmds, 0x05);
	return 0;
}
static u8_t get_auth(u8_t auth)
{
	if (sc_supported) {
		auth &= 0x0f;
	} else {
		auth &= 0x07;
	}
	if (get_io_capa() == 0x03) {
		auth &= ~(0x04);
	} else {
		auth |= 0x04;
	}
	return auth;
}
static 
	_Bool 
sec_level_reachable(struct bt_conn *conn)
{
	switch (conn->required_sec_level) {
		case BT_SECURITY_LOW:
		case BT_SECURITY_MEDIUM:
			return 
				1
				;
		case BT_SECURITY_HIGH:
			return get_io_capa() != 0x03;
		case BT_SECURITY_FIPS:
			return get_io_capa() != 0x03 &&
				sc_supported;
		default:
			return 
				0
				;
	}
}
static struct bt_smp *smp_chan_get(struct bt_conn *conn)
{
	struct bt_l2cap_chan *chan;
	chan = bt_l2cap_le_lookup_rx_cid(conn, 0x0006);
	if (!chan) {
		;
		return 
			((void *)0)
			;
	}
	return ((struct bt_smp *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_smp
					, 
					chan
					)
				));
}
int bt_smp_send_security_req(struct bt_conn *conn)
{
	struct bt_smp *smp;
	struct bt_smp_security_request *req;
	struct net_buf *req_buf;
	;
	smp = smp_chan_get(conn);
	if (!smp) {
		return -57;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_TIMEOUT)) {
		return -5;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_PAIRING)) {
		return -16;
	}
	if (!sec_level_reachable(conn)) {
		return -22;
	}
	req_buf = smp_create_pdu(conn, 0x0b,
			sizeof(*req));
	if (!req_buf) {
		return -55;
	}
	req = net_buf_simple_add(&(req_buf)->b, sizeof(*req));
	req->auth_req = get_auth((0x01 | 0x08));
	bt_l2cap_send(conn, 0x0006, req_buf);
	atomic_set_bit(&smp->allowed_cmds, 0x05);
	return 0;
}
static u8_t smp_pairing_req(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_smp_pairing *req = (void *)buf->data;
	struct bt_smp_pairing *rsp;
	int ret;
	;
	if ((req->max_key_size > 16) ||
			(req->max_key_size < 7)) {
		return 0x06;
	}
	ret = smp_init(smp);
	if (ret) {
		return ret;
	}
	smp->preq[0] = 0x01;
	memcpy(smp->preq + 1, req, sizeof(*req));
	smp->prsp[0] = 0x02;
	rsp = (struct bt_smp_pairing *)&smp->prsp[1];
	rsp->auth_req = get_auth(req->auth_req);
	rsp->io_capability = get_io_capa();
	rsp->oob_flag = 0x00;
	rsp->max_key_size = 16;
	rsp->init_key_dist = (req->init_key_dist & (0x01 | 0x02 | 0 | 0));
	rsp->resp_key_dist = (req->resp_key_dist & (0x01 | 0 | 0 | 0));
	if ((rsp->auth_req & 0x08) &&
			(req->auth_req & 0x08)) {
		atomic_set_bit(smp->flags, SMP_FLAG_SC);
		rsp->init_key_dist &= ((0x01 | 0x02 | 0 | 0) & ~(0x01));
		rsp->resp_key_dist &= ((0x01 | 0 | 0 | 0) & ~(0x01));
	}
	if ((rsp->auth_req & 0x20) &&
			(req->auth_req & 0x20)) {
		atomic_set_bit(smp->flags, SMP_FLAG_CT2);
	}
	smp->local_dist = rsp->resp_key_dist;
	smp->remote_dist = rsp->init_key_dist;
	if ((rsp->auth_req & 0x01) &&
			(req->auth_req & 0x01)) {
		atomic_set_bit(smp->flags, SMP_FLAG_BOND);
	}
	atomic_set_bit(smp->flags, SMP_FLAG_PAIRING);
	if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		return legacy_pairing_req(smp, req->io_capability);
	}
	smp->method = get_pair_method(smp, req->io_capability);
	if (0 &&
			smp->method == JUST_WORKS) {
		return 0x03;
	}
	if (smp->method == JUST_WORKS) {
		if (0) {
			return 0x03;
		}
		if (!atomic_test_bit(smp->flags, SMP_FLAG_SEC_REQ) &&
				bt_auth && bt_auth->pairing_confirm) {
			atomic_set_bit(smp->flags, SMP_FLAG_USER);
			bt_auth->pairing_confirm(smp->chan.chan.conn);
			return 0;
		}
	}
	atomic_set_bit(&smp->allowed_cmds, 0x0c);
	return send_pairing_rsp(smp);
}
static u8_t sc_send_public_key(struct bt_smp *smp)
{
	struct bt_smp_public_key *req;
	struct net_buf *req_buf;
	req_buf = smp_create_pdu(smp->chan.chan.conn, 0x0c,
			sizeof(*req));
	if (!req_buf) {
		return 0x08;
	}
	req = net_buf_simple_add(&(req_buf)->b, sizeof(*req));
	memcpy(req->x, sc_public_key, sizeof(req->x));
	memcpy(req->y, &sc_public_key[32], sizeof(req->y));
	smp_send(smp, req_buf, 
			((void *)0)
		);
	if (0) {
		atomic_set_bit(smp->flags, SMP_FLAG_SC_DEBUG_KEY);
	}
	return 0;
}
static u8_t smp_pairing_rsp(struct bt_smp *smp, struct net_buf *buf)
{
	return 0x07;
}
static u8_t smp_pairing_confirm(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_smp_pairing_confirm *req = (void *)buf->data;
	;
	memcpy(smp->pcnf, req->val, sizeof(smp->pcnf));
	if (0 &&
			smp->chan.chan.conn->role == 0x00) {
		atomic_set_bit(&smp->allowed_cmds, 0x04);
		return smp_send_pairing_random(smp);
	}
	if (!1) {
		return 0;
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		return legacy_pairing_confirm(smp);
	}
	switch (smp->method) {
		case PASSKEY_DISPLAY:
			atomic_set_bit(&smp->allowed_cmds, 0x04);
			return smp_send_pairing_confirm(smp);
		case PASSKEY_INPUT:
			if (atomic_test_bit(smp->flags, SMP_FLAG_USER)) {
				atomic_set_bit(smp->flags, SMP_FLAG_CFM_DELAYED);
				return 0;
			}
			atomic_set_bit(&smp->allowed_cmds, 0x04);
			return smp_send_pairing_confirm(smp);
		case JUST_WORKS:
		case PASSKEY_CONFIRM:
		default:
			return 0x08;
	}
}
static u8_t sc_smp_send_dhkey_check(struct bt_smp *smp, const u8_t *e)
{
	struct bt_smp_dhkey_check *req;
	struct net_buf *buf;
	;
	buf = smp_create_pdu(smp->chan.chan.conn, 0x0d,
			sizeof(*req));
	if (!buf) {
		return 0x08;
	}
	req = net_buf_simple_add(&(buf)->b, sizeof(*req));
	memcpy(req->e, e, sizeof(req->e));
	smp_send(smp, buf, 
			((void *)0)
		);
	return 0;
}
static u8_t compute_and_check_and_send_slave_dhcheck(struct bt_smp *smp)
{
	u8_t re[16], e[16], r[16];
	memset(r, 0, sizeof(r));
	switch (smp->method) {
		case JUST_WORKS:
		case PASSKEY_CONFIRM:
			break;
		case PASSKEY_DISPLAY:
		case PASSKEY_INPUT:
			memcpy(r, &smp->passkey, sizeof(smp->passkey));
			break;
		default:
			return 0x08;
	}
	if (smp_f5(smp->dhkey, smp->rrnd, smp->prnd,
				&smp->chan.chan.conn->le.init_addr,
				&smp->chan.chan.conn->le.resp_addr, smp->mackey,
				smp->tk)) {
		return 0x08;
	}
	if (smp_f6(smp->mackey, smp->prnd, smp->rrnd, r, &smp->prsp[1],
				&smp->chan.chan.conn->le.resp_addr,
				&smp->chan.chan.conn->le.init_addr, e)) {
		return 0x08;
	}
	if (smp_f6(smp->mackey, smp->rrnd, smp->prnd, r, &smp->preq[1],
				&smp->chan.chan.conn->le.init_addr,
				&smp->chan.chan.conn->le.resp_addr, re)) {
		return 0x08;
	}
	if (memcmp(smp->e, re, 16)) {
		return 0x0b;
	}
	sc_smp_send_dhkey_check(smp, e);
	atomic_set_bit(smp->flags, SMP_FLAG_ENC_PENDING);
	return 0;
}
static void bt_smp_dhkey_ready(const u8_t *dhkey)
{
	struct bt_smp *smp = 
		((void *)0)
		;
	int i;
	;
	for (i = 0; i < ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(bt_smp_pool), __typeof__(&(bt_smp_pool)[0])))]) - 1) + (sizeof(bt_smp_pool) / sizeof((bt_smp_pool)[0])))); i++) {
		if (atomic_test_and_clear_bit(bt_smp_pool[i].flags,
					SMP_FLAG_DHKEY_PENDING)) {
			smp = &bt_smp_pool[i];
			break;
		}
	}
	if (!smp) {
		return;
	}
	if (!dhkey) {
		smp_error(smp, 0x0b);
		return;
	}
	memcpy(smp->dhkey, dhkey, 32);
	if (atomic_test_bit(smp->flags, SMP_FLAG_USER)) {
		atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_SEND);
		return;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_DHCHECK_WAIT)) {
		atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_SEND);
		return;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_DHKEY_SEND)) {
		u8_t err;
		err = compute_and_check_and_send_slave_dhcheck(smp);
		if (err) {
			smp_error(smp, err);
		}
	}
}
static u8_t sc_smp_check_confirm(struct bt_smp *smp)
{
	u8_t cfm[16];
	u8_t r;
	switch (smp->method) {
		case PASSKEY_CONFIRM:
		case JUST_WORKS:
			r = 0;
			break;
		case PASSKEY_DISPLAY:
		case PASSKEY_INPUT:
			r = (smp->passkey >> smp->passkey_round) & 0x01;
			r |= 0x80;
			break;
		default:
			return 0x08;
	}
	if (smp_f4(smp->pkey, sc_public_key, smp->rrnd, r, cfm)) {
		return 0x08;
	}
	;
	if (memcmp(smp->pcnf, cfm, 16)) {
		return 0x04;
	}
	return 0;
}
static u8_t smp_pairing_random(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_smp_pairing_random *req = (void *)buf->data;
	u32_t passkey;
	u8_t err;
	;
	memcpy(smp->rrnd, req->val, sizeof(smp->rrnd));
	if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		return legacy_pairing_random(smp);
	}
	switch (smp->method) {
		case PASSKEY_CONFIRM:
			if (smp_g2(smp->pkey, sc_public_key, smp->rrnd, smp->prnd,
						&passkey)) {
				return 0x08;
			}
			atomic_set_bit(smp->flags, SMP_FLAG_USER);
			bt_auth->passkey_confirm(smp->chan.chan.conn, passkey);
			break;
		case JUST_WORKS:
			break;
		case PASSKEY_DISPLAY:
		case PASSKEY_INPUT:
			err = sc_smp_check_confirm(smp);
			if (err) {
				return err;
			}
			atomic_set_bit(&smp->allowed_cmds,
					0x03);
			smp_send_pairing_random(smp);
			smp->passkey_round++;
			if (smp->passkey_round == 20) {
				atomic_set_bit(&smp->allowed_cmds, 0x0d);
				atomic_set_bit(smp->flags, SMP_FLAG_DHCHECK_WAIT);
				return 0;
			}
			if (bt_rand(smp->prnd, 16)) {
				return 0x08;
			}
			return 0;
		default:
			return 0x08;
	}
	atomic_set_bit(&smp->allowed_cmds, 0x0d);
	atomic_set_bit(smp->flags, SMP_FLAG_DHCHECK_WAIT);
	smp_send_pairing_random(smp);
	return 0;
}
static u8_t smp_pairing_failed(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_pairing_fail *req = (void *)buf->data;
	;
	(void)(req);
	switch (smp->method) {
		case PASSKEY_INPUT:
		case PASSKEY_DISPLAY:
		case PASSKEY_CONFIRM:
			bt_auth->cancel(conn);
			break;
		default:
			break;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_KEYS_DISTR) &&
			smp->chan.chan.conn->le.keys) {
		bt_keys_clear(smp->chan.chan.conn->le.keys);
	}
	smp_pairing_complete(smp, req->reason);
	return 0;
}
static u8_t smp_ident_info(struct bt_smp *smp, struct net_buf *buf)
{
	;
	if (atomic_test_bit(smp->flags, SMP_FLAG_BOND)) {
		struct bt_smp_ident_info *req = (void *)buf->data;
		struct bt_conn *conn = smp->chan.chan.conn;
		struct bt_keys *keys;
		keys = bt_keys_get_type(BT_KEYS_IRK, &conn->le.dst);
		if (!keys) {
			;
			return 0x08;
		}
		memcpy(keys->irk.val, req->irk, 16);
	}
	atomic_set_bit(&smp->allowed_cmds, 0x09);
	return 0;
}
static u8_t smp_ident_addr_info(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_ident_addr_info *req = (void *)buf->data;
	;
	if (!bt_addr_le_is_identity(&req->addr)) {
		;
		return 0x0a;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_BOND)) {
		const bt_addr_le_t *dst;
		struct bt_keys *keys;
		keys = bt_keys_get_type(BT_KEYS_IRK, &conn->le.dst);
		if (!keys) {
			;
			return 0x08;
		}
		if (conn->role == 0x00) {
			dst = &conn->le.resp_addr;
		} else {
			dst = &conn->le.init_addr;
		}
		if (bt_addr_le_is_rpa(dst)) {
			bt_addr_copy(&keys->irk.rpa, &dst->a);
			if (!bt_addr_le_is_identity(&conn->le.dst)) {
				bt_addr_le_copy(&keys->addr, &req->addr);
				bt_addr_le_copy(&conn->le.dst, &req->addr);
				bt_conn_identity_resolved(conn);
			}
		}
		bt_id_add(keys);
	}
	smp->remote_dist &= ~0x02;
	if (smp->remote_dist & 0x04) {
		atomic_set_bit(&smp->allowed_cmds, 0x0a);
	}
	if (0 &&
			conn->role == 0x00 && !smp->remote_dist) {
		bt_smp_distribute_keys(smp);
	}
	if (!smp->local_dist && !smp->remote_dist) {
		smp_pairing_complete(smp, 0);
	}
	return 0;
}
static u8_t smp_signing_info(struct bt_smp *smp, struct net_buf *buf)
{
	return 0x07;
}
static u8_t smp_security_request(struct bt_smp *smp, struct net_buf *buf)
{
	return 0x07;
}
static u8_t generate_dhkey(struct bt_smp *smp)
{
	if (bt_dh_key_gen(smp->pkey, bt_smp_dhkey_ready)) {
		return 0x08;
	}
	atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_PENDING);
	return 0;
}
static u8_t display_passkey(struct bt_smp *smp)
{
	if (bt_rand(&smp->passkey, sizeof(smp->passkey))) {
		return 0x08;
	}
	smp->passkey %= 1000000;
	smp->passkey_round = 0;
	bt_auth->passkey_display(smp->chan.chan.conn, smp->passkey);
	smp->passkey = (smp->passkey);
	return 0;
}
static u8_t smp_public_key_slave(struct bt_smp *smp)
{
	u8_t err;
	err = sc_send_public_key(smp);
	if (err) {
		return err;
	}
	switch (smp->method) {
		case PASSKEY_CONFIRM:
		case JUST_WORKS:
			atomic_set_bit(&smp->allowed_cmds, 0x04);
			err = smp_send_pairing_confirm(smp);
			if (err) {
				return err;
			}
			break;
		case PASSKEY_DISPLAY:
			err = display_passkey(smp);
			if (err) {
				return err;
			}
			atomic_set_bit(&smp->allowed_cmds, 0x03);
			break;
		case PASSKEY_INPUT:
			atomic_set_bit(&smp->allowed_cmds, 0x03);
			atomic_set_bit(smp->flags, SMP_FLAG_USER);
			bt_auth->passkey_entry(smp->chan.chan.conn);
			break;
		default:
			return 0x08;
	}
	return generate_dhkey(smp);
}
static u8_t smp_public_key(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_smp_public_key *req = (void *)buf->data;
	u8_t err;
	;
	memcpy(smp->pkey, req->x, 32);
	memcpy(&smp->pkey[32], req->y, 32);
	if (memcmp(smp->pkey, sc_debug_public_key, 64) == 0) {
		;
		atomic_set_bit(smp->flags, SMP_FLAG_SC_DEBUG_KEY);
	}
	if (0 &&
			smp->chan.chan.conn->role == 0x00) {
		switch (smp->method) {
			case PASSKEY_CONFIRM:
			case JUST_WORKS:
				atomic_set_bit(&smp->allowed_cmds,
						0x03);
				break;
			case PASSKEY_DISPLAY:
				err = display_passkey(smp);
				if (err) {
					return err;
				}
				atomic_set_bit(&smp->allowed_cmds,
						0x03);
				err = smp_send_pairing_confirm(smp);
				if (err) {
					return err;
				}
				break;
			case PASSKEY_INPUT:
				atomic_set_bit(smp->flags, SMP_FLAG_USER);
				bt_auth->passkey_entry(smp->chan.chan.conn);
				break;
			default:
				return 0x08;
		}
		return generate_dhkey(smp);
	}
	if (!sc_local_pkey_valid) {
		atomic_set_bit(smp->flags, SMP_FLAG_PKEY_SEND);
		return 0;
	}
	err = smp_public_key_slave(smp);
	if (err) {
		return err;
	}
	return 0;
}
static u8_t smp_dhkey_check(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_smp_dhkey_check *req = (void *)buf->data;
	;
	if (0 &&
			smp->chan.chan.conn->role == 0x00) {
		u8_t e[16], r[16], enc_size;
		memset(r, 0, sizeof(r));
		switch (smp->method) {
			case JUST_WORKS:
			case PASSKEY_CONFIRM:
				break;
			case PASSKEY_DISPLAY:
			case PASSKEY_INPUT:
				memcpy(r, &smp->passkey, sizeof(smp->passkey));
				break;
			default:
				return 0x08;
		}
		if (smp_f6(smp->mackey, smp->rrnd, smp->prnd, r, &smp->prsp[1],
					&smp->chan.chan.conn->le.resp_addr,
					&smp->chan.chan.conn->le.init_addr, e)) {
			return 0x08;
		}
		if (memcmp(e, req->e, 16)) {
			return 0x0b;
		}
		enc_size = get_encryption_key_size(smp);
		if (bt_conn_le_start_encryption(smp->chan.chan.conn, 0, 0,
					smp->tk, enc_size) < 0) {
			return 0x08;
		}
		atomic_set_bit(smp->flags, SMP_FLAG_ENC_PENDING);
		return 0;
	}
	if (smp->chan.chan.conn->role == 0x01) {
		atomic_clear_bit(smp->flags, SMP_FLAG_DHCHECK_WAIT);
		memcpy(smp->e, req->e, sizeof(smp->e));
		if (atomic_test_bit(smp->flags, SMP_FLAG_DHKEY_PENDING)) {
			atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_SEND);
			return 0;
		}
		if (atomic_test_bit(smp->flags, SMP_FLAG_USER)) {
			atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_SEND);
			return 0;
		}
		return compute_and_check_and_send_slave_dhcheck(smp);
	}
	return 0;
}
static const struct {
	u8_t (*func)(struct bt_smp *smp, struct net_buf *buf);
	u8_t expect_len;
} handlers[] = {
	{ },
	{ smp_pairing_req, sizeof(struct bt_smp_pairing) },
	{ smp_pairing_rsp, sizeof(struct bt_smp_pairing) },
	{ smp_pairing_confirm, sizeof(struct bt_smp_pairing_confirm) },
	{ smp_pairing_random, sizeof(struct bt_smp_pairing_random) },
	{ smp_pairing_failed, sizeof(struct bt_smp_pairing_fail) },
	{ smp_encrypt_info, sizeof(struct bt_smp_encrypt_info) },
	{ smp_master_ident, sizeof(struct bt_smp_master_ident) },
	{ smp_ident_info, sizeof(struct bt_smp_ident_info) },
	{ smp_ident_addr_info, sizeof(struct bt_smp_ident_addr_info) },
	{ smp_signing_info, sizeof(struct bt_smp_signing_info) },
	{ smp_security_request, sizeof(struct bt_smp_security_request) },
	{ smp_public_key, sizeof(struct bt_smp_public_key) },
	{ smp_dhkey_check, sizeof(struct bt_smp_dhkey_check) },
};
static void bt_smp_recv(struct bt_l2cap_chan *chan, struct net_buf *buf)
{
	struct bt_smp *smp = ((struct bt_smp *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_smp
					, 
					chan
					)
				));
	struct bt_smp_hdr *hdr = (void *)buf->data;
	u8_t err;
	if (buf->len < sizeof(*hdr)) {
		;
		return;
	}
	;
	net_buf_simple_pull(&(buf)->b, sizeof(*hdr));
	if (atomic_test_bit(smp->flags, SMP_FLAG_TIMEOUT)) {
		;
		return;
	}
	if (hdr->code >= ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(handlers), __typeof__(&(handlers)[0])))]) - 1) + (sizeof(handlers) / sizeof((handlers)[0])))) || !handlers[hdr->code].func) {
		;
		smp_error(smp, 0x07);
		return;
	}
	if (((((smp->allowed_cmds) < 0x0F)? 1:0)) &&
			(!atomic_test_and_clear_bit(&smp->allowed_cmds, hdr->code))) {
		;
		if (hdr->code != 0x05) {
			smp_error(smp, 0x08);
		}
		return;
	}
	if (buf->len != handlers[hdr->code].expect_len) {
		;
		smp_error(smp, 0x0a);
		return;
	}
	err = handlers[hdr->code].func(smp, buf);
	if (err) {
		smp_error(smp, err);
	}
}
static void bt_smp_pkey_ready(const u8_t *pkey)
{
	int i;
	;
	if (!pkey) {
		;
		sc_local_pkey_valid = 
			0
			;
		return;
	}
	memcpy(sc_public_key, pkey, 64);
	sc_local_pkey_valid = 
		1
		;
	for (i = 0; i < ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(bt_smp_pool), __typeof__(&(bt_smp_pool)[0])))]) - 1) + (sizeof(bt_smp_pool) / sizeof((bt_smp_pool)[0])))); i++) {
		struct bt_smp *smp = &bt_smp_pool[i];
		u8_t err;
		if (!atomic_test_bit(smp->flags, SMP_FLAG_PKEY_SEND)) {
			continue;
		}
		if (0 &&
				smp->chan.chan.conn->role == 0x00) {
			err = sc_send_public_key(smp);
			if (err) {
				smp_error(smp, err);
			}
			atomic_set_bit(&smp->allowed_cmds,
					0x0c);
			continue;
		}
		err = smp_public_key_slave(smp);
		if (err) {
			smp_error(smp, err);
		}
	}
}
static void bt_smp_connected(struct bt_l2cap_chan *chan)
{
	struct bt_smp *smp = ((struct bt_smp *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_smp
					, 
					chan
					)
				));
	;
	k_delayed_work_init(&smp->work, smp_timeout);
	smp_reset(smp);
}
static void bt_smp_disconnected(struct bt_l2cap_chan *chan)
{
	struct bt_smp *smp = ((struct bt_smp *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_smp
					, 
					chan
					)
				));
	struct bt_keys *keys = chan->conn->le.keys;
	;
	k_delayed_work_cancel(&smp->work);
	if (keys) {
		if (!keys->keys ||
				atomic_test_bit(keys->flags, BT_KEYS_DEBUG)) {
			bt_keys_clear(keys);
		}
	}
	memset(smp, 0, sizeof(*smp));
}
static void bt_smp_encrypt_change(struct bt_l2cap_chan *chan,
		u8_t hci_status)
{
	struct bt_smp *smp = ((struct bt_smp *)(((char *)(chan)) - 
				__builtin_offsetof (
					struct bt_smp
					, 
					chan
					)
				));
	struct bt_conn *conn = chan->conn;
	;
	if (hci_status) {
		return;
	}
	if (!smp || !conn->encrypt) {
		return;
	}
	if (!atomic_test_and_clear_bit(smp->flags, SMP_FLAG_ENC_PENDING)) {
		return;
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_PAIRING)) {
		atomic_set_bit(&smp->allowed_cmds, 0x0b);
		return;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		if ((smp->local_dist & 0x08) &&
				(smp->remote_dist & 0x08)) {
			atomic_set_bit(smp->flags, SMP_FLAG_DERIVE_LK);
		}
		smp->local_dist &= ~0x08;
		smp->remote_dist &= ~0x08;
	}
	if (smp->remote_dist & 0x01) {
		atomic_set_bit(&smp->allowed_cmds, 0x06);
	} else if (smp->remote_dist & 0x02) {
		atomic_set_bit(&smp->allowed_cmds, 0x08);
	} else if (smp->remote_dist & 0x04) {
		atomic_set_bit(&smp->allowed_cmds, 0x0a);
	}
	atomic_set_bit(smp->flags, SMP_FLAG_KEYS_DISTR);
	if (0 &&
			conn->role == 0x00 && smp->remote_dist) {
		return;
	}
	bt_smp_distribute_keys(smp);
	if (!smp->local_dist && !smp->remote_dist) {
		smp_pairing_complete(smp, 0);
	}
}
int bt_smp_sign_verify(struct bt_conn *conn, struct net_buf *buf)
{
	return -35;
}
int bt_smp_sign(struct bt_conn *conn, struct net_buf *buf)
{
	return -35;
}
static inline int smp_self_test(void)
{
	return 0;
}
int bt_smp_auth_passkey_entry(struct bt_conn *conn, unsigned int passkey)
{
	struct bt_smp *smp;
	smp = smp_chan_get(conn);
	if (!smp) {
		return -22;
	}
	if (!atomic_test_and_clear_bit(smp->flags, SMP_FLAG_USER)) {
		return -22;
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		legacy_passkey_entry(smp, passkey);
		return 0;
	}
	smp->passkey = (passkey);
	if (0 &&
			smp->chan.chan.conn->role == 0x00) {
		if (smp_send_pairing_confirm(smp)) {
			smp_error(smp, 0x01);
			return 0;
		}
		atomic_set_bit(&smp->allowed_cmds, 0x03);
		return 0;
	}
	if (1 &&
			atomic_test_bit(smp->flags, SMP_FLAG_CFM_DELAYED)) {
		if (smp_send_pairing_confirm(smp)) {
			smp_error(smp, 0x01);
			return 0;
		}
		atomic_set_bit(&smp->allowed_cmds, 0x04);
	}
	return 0;
}
int bt_smp_auth_passkey_confirm(struct bt_conn *conn)
{
	struct bt_smp *smp;
	smp = smp_chan_get(conn);
	if (!smp) {
		return -22;
	}
	if (!atomic_test_and_clear_bit(smp->flags, SMP_FLAG_USER)) {
		return -22;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_DHKEY_PENDING)) {
		atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_SEND);
		return 0;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_DHCHECK_WAIT)) {
		atomic_set_bit(smp->flags, SMP_FLAG_DHKEY_SEND);
		return 0;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_DHKEY_SEND)) {
		u8_t err;
		err = compute_and_check_and_send_slave_dhcheck(smp);
		if (err) {
			smp_error(smp, err);
		}
	}
	return 0;
}
int bt_smp_auth_cancel(struct bt_conn *conn)
{
	struct bt_smp *smp;
	smp = smp_chan_get(conn);
	if (!smp) {
		return -22;
	}
	if (!atomic_test_and_clear_bit(smp->flags, SMP_FLAG_USER)) {
		return -22;
	}
	switch (smp->method) {
		case PASSKEY_INPUT:
		case PASSKEY_DISPLAY:
			return smp_error(smp, 0x01);
		case PASSKEY_CONFIRM:
			return smp_error(smp, 0x04);
		case JUST_WORKS:
			return smp_error(smp, 0x08);
		default:
			return 0;
	}
}
int bt_smp_auth_pairing_confirm(struct bt_conn *conn)
{
	struct bt_smp *smp;
	smp = smp_chan_get(conn);
	if (!smp) {
		return -22;
	}
	if (!atomic_test_and_clear_bit(smp->flags, SMP_FLAG_USER)) {
		return -22;
	}
	if (0 &&
			conn->role == BT_CONN_ROLE_MASTER) {
		if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
			atomic_set_bit(&smp->allowed_cmds,
					0x03);
			return legacy_send_pairing_confirm(smp);
		}
		if (!sc_local_pkey_valid) {
			atomic_set_bit(smp->flags, SMP_FLAG_PKEY_SEND);
			return 0;
		}
		atomic_set_bit(&smp->allowed_cmds, 0x0c);
		return sc_send_public_key(smp);
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_SC)) {
		atomic_set_bit(&smp->allowed_cmds,
				0x03);
		return send_pairing_rsp(smp);
	}
	atomic_set_bit(&smp->allowed_cmds, 0x0c);
	if (send_pairing_rsp(smp)) {
		return -5;
	}
	return 0;
}
void bt_smp_update_keys(struct bt_conn *conn)
{
	struct bt_smp *smp;
	smp = smp_chan_get(conn);
	if (!smp) {
		return;
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_PAIRING)) {
		return;
	}
	if (conn->le.keys) {
		bt_keys_clear(conn->le.keys);
	}
	conn->le.keys = bt_keys_get_addr(&conn->le.dst);
	if (!conn->le.keys) {
		;
		return;
	}
	if (atomic_test_bit(smp->flags, SMP_FLAG_SC_DEBUG_KEY)) {
		atomic_set_bit(conn->le.keys->flags, BT_KEYS_DEBUG);
	}
	switch (smp->method) {
		case PASSKEY_DISPLAY:
		case PASSKEY_INPUT:
		case PASSKEY_CONFIRM:
			atomic_set_bit(conn->le.keys->flags, BT_KEYS_AUTHENTICATED);
			break;
		case JUST_WORKS:
		default:
			atomic_clear_bit(conn->le.keys->flags, BT_KEYS_AUTHENTICATED);
			break;
	}
	conn->le.keys->enc_size = get_encryption_key_size(smp);
	if (atomic_test_bit(smp->flags, SMP_FLAG_SC) &&
			atomic_test_bit(smp->flags, SMP_FLAG_BOND)) {
		bt_keys_add_type(conn->le.keys, BT_KEYS_LTK_P256);
		memcpy(conn->le.keys->ltk.val, smp->tk,
				sizeof(conn->le.keys->ltk.val));
		conn->le.keys->ltk.rand = 0;
		conn->le.keys->ltk.ediv = 0;
	}
}
	_Bool 
bt_smp_get_tk(struct bt_conn *conn, u8_t *tk)
{
	struct bt_smp *smp;
	u8_t enc_size;
	smp = smp_chan_get(conn);
	if (!smp) {
		return 
			0
			;
	}
	if (!atomic_test_bit(smp->flags, SMP_FLAG_PAIRING)) {
		return 
			0
			;
	}
	enc_size = get_encryption_key_size(smp);
	memcpy(tk, smp->tk, enc_size);
	if (enc_size < sizeof(smp->tk)) {
		memset(tk + enc_size, 0, sizeof(smp->tk) - enc_size);
	}
	return 
		1
		;
}
static int bt_smp_accept(struct bt_conn *conn, struct bt_l2cap_chan **chan)
{
	int i;
	static struct bt_l2cap_chan_ops ops = {
		.connected = bt_smp_connected,
		.disconnected = bt_smp_disconnected,
		.encrypt_change = bt_smp_encrypt_change,
		.recv = bt_smp_recv,
	};
	;
	for (i = 0; i < ((unsigned long) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(bt_smp_pool), __typeof__(&(bt_smp_pool)[0])))]) - 1) + (sizeof(bt_smp_pool) / sizeof((bt_smp_pool)[0])))); i++) {
		struct bt_smp *smp = &bt_smp_pool[i];
		if (smp->chan.chan.conn) {
			continue;
		}
		smp->chan.chan.ops = &ops;
		*chan = &smp->chan.chan;
		return 0;
	}
	;
	return -12;
}
static 
	_Bool 
le_sc_supported(void)
{
	return (bt_dev.supported_commands[34] & 0x02) &&
		(bt_dev.supported_commands[34] & 0x04);
}
int bt_smp_init(void)
{
	static struct bt_l2cap_fixed_chan chan = {
		.cid = 0x0006,
		.accept = bt_smp_accept,
	};
	static struct bt_pub_key_cb pub_key_cb = {
		.func = bt_smp_pkey_ready,
	};
	sc_supported = le_sc_supported();
	if (0 && !sc_supported) {
		;
		return -2;
	}
	bt_l2cap_le_fixed_chan_register(&chan);
	;
	bt_pub_key_gen(&pub_key_cb);
	return smp_self_test();
}
