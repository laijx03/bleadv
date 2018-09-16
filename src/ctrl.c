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
typedef signed char s8_t;
typedef signed short s16_t;
typedef signed int s32_t;
typedef signed long long s64_t;
typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef unsigned long long u64_t;
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
	int ll_init(struct k_sem *sem_rx);
	void ll_reset(void);
	void ll_radio_state_abort(void);
	u32_t ll_radio_state_is_idle(void);
	u8_t *ll_addr_get(u8_t addr_type, u8_t *p_bdaddr);
	void ll_addr_set(u8_t addr_type, u8_t const *const p_bdaddr);
	u32_t ll_adv_params_set(u16_t interval, u8_t adv_type,
			u8_t own_addr_type, u8_t direct_addr_type,
			u8_t const *const direct_addr, u8_t chan_map,
			u8_t filter_policy);
void ll_adv_data_set(u8_t len, u8_t const *const p_data);
void ll_scan_data_set(u8_t len, u8_t const *const p_data);
u32_t ll_adv_enable(u8_t enable);
u32_t ll_scan_params_set(u8_t type, u16_t interval, u16_t window,
		u8_t own_addr_type, u8_t filter_policy);
u32_t ll_scan_enable(u8_t enable);
u32_t ll_wl_size_get(void);
u32_t ll_wl_clear(void);
u32_t ll_wl_add(bt_addr_le_t *addr);
u32_t ll_wl_remove(bt_addr_le_t *addr);
void ll_rl_id_addr_get(u8_t rl_idx, u8_t *id_addr_type, u8_t *id_addr);
u32_t ll_rl_size_get(void);
u32_t ll_rl_clear(void);
u32_t ll_rl_add(bt_addr_le_t *id_addr, const u8_t pirk[16],
		const u8_t lirk[16]);
u32_t ll_rl_remove(bt_addr_le_t *id_addr);
void ll_rl_crpa_set(u8_t id_addr_type, u8_t *id_addr, u8_t rl_idx, u8_t *crpa);
u32_t ll_rl_crpa_get(bt_addr_le_t *id_addr, bt_addr_t *crpa);
u32_t ll_rl_lrpa_get(bt_addr_le_t *id_addr, bt_addr_t *lrpa);
u32_t ll_rl_enable(u8_t enable);
void ll_rl_timeout_set(u16_t timeout);
u32_t ll_priv_mode_set(bt_addr_le_t *id_addr, u8_t mode);
u32_t ll_create_connection(u16_t scan_interval, u16_t scan_window,
		u8_t filter_policy, u8_t peer_addr_type,
		u8_t *p_peer_addr, u8_t own_addr_type,
		u16_t interval, u16_t latency,
		u16_t timeout);
u32_t ll_connect_disable(void);
u32_t ll_conn_update(u16_t handle, u8_t cmd, u8_t status,
		u16_t interval, u16_t latency,
		u16_t timeout);
u32_t ll_chm_update(u8_t *chm);
u32_t ll_chm_get(u16_t handle, u8_t *chm);
u32_t ll_enc_req_send(u16_t handle, u8_t *rand, u8_t *ediv,
		u8_t *ltk);
u32_t ll_start_enc_req_send(u16_t handle, u8_t err_code,
		u8_t const *const ltk);
u32_t ll_feature_req_send(u16_t handle);
u32_t ll_version_ind_send(u16_t handle);
u32_t ll_terminate_ind_send(u16_t handle, u8_t reason);
void ll_timeslice_ticker_id_get(u8_t * const instance_index, u8_t * const user_id);
u32_t ll_rssi_get(u16_t handle, u8_t *rssi);
u32_t ll_tx_power_level_get(u16_t handle, u8_t type, s8_t *tx_power_level);
void ll_tx_power_get(s8_t *min, s8_t *max);
u32_t ll_phy_get(u16_t handle, u8_t *tx, u8_t *rx);
u32_t ll_phy_default_set(u8_t tx, u8_t rx);
u32_t ll_phy_req_send(u16_t handle, u8_t tx, u8_t flags, u8_t rx);
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
static inline unsigned int gcc_current_sp(void)
{
	register unsigned sp __asm("sp");
	return sp;
}
static inline void cpu_sleep(void)
{
	__WFE();
	__SEV();
	__WFE();
}
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
void rand_init(u8_t *context, u8_t context_len, u8_t threshold);
void rand_isr_init(u8_t *context, u8_t context_len, u8_t threshold);
size_t rand_get(size_t octets, u8_t *rand);
size_t rand_isr_get(size_t octets, u8_t *rand);
void isr_rand(void *param);
typedef void (*ecb_fp) (u32_t status, u8_t *cipher_be, void *context);
struct ecb {
	u8_t in_key_be[16];
	u8_t in_clear_text_be[16];
	u8_t out_cipher_text_be[16];
	u8_t *in_key_le;
	u8_t *in_clear_text_le;
	ecb_fp fp_ecb;
	void *context;
};
void ecb_encrypt_be(u8_t const *const key_be, u8_t const *const clear_text_be,
		u8_t * const cipher_text_be);
void ecb_encrypt(u8_t const *const key_le, u8_t const *const clear_text_le,
		u8_t * const cipher_text_le, u8_t * const cipher_text_be);
u32_t ecb_encrypt_nonblocking(struct ecb *ecb);
void isr_ecb(void *param);
u32_t ecb_ut(void);
struct ccm {
	u8_t key[16];
	u64_t counter;
	u8_t direction:1;
	u8_t resv1:7;
	u8_t iv[8];
} 
__attribute__((__packed__))
	;
	typedef void (*radio_isr_fp) (void);
	void isr_radio(void);
	void radio_isr_set(radio_isr_fp fp_radio_isr);
	void radio_setup(void);
	void radio_reset(void);
	void radio_phy_set(u8_t phy, u8_t flags);
	void radio_tx_power_set(u32_t power);
	void radio_freq_chan_set(u32_t chan);
	void radio_whiten_iv_set(u32_t iv);
	void radio_aa_set(u8_t *aa);
	void radio_pkt_configure(u8_t bits_len, u8_t max_len, u8_t flags);
	void radio_pkt_rx_set(void *rx_packet);
	void radio_pkt_tx_set(void *tx_packet);
	u32_t radio_tx_ready_delay_get(u8_t phy, u8_t flags);
	u32_t radio_tx_chain_delay_get(u8_t phy, u8_t flags);
	u32_t radio_rx_ready_delay_get(u8_t phy);
	u32_t radio_rx_chain_delay_get(u8_t phy, u8_t flags);
	void radio_rx_enable(void);
	void radio_tx_enable(void);
	void radio_disable(void);
	void radio_status_reset(void);
	u32_t radio_is_ready(void);
	u32_t radio_is_done(void);
	u32_t radio_has_disabled(void);
	u32_t radio_is_idle(void);
	void radio_crc_configure(u32_t polynomial, u32_t iv);
	u32_t radio_crc_is_valid(void);
	void *radio_pkt_empty_get(void);
	void *radio_pkt_scratch_get(void);
	void radio_switch_complete_and_rx(u8_t phy_rx);
	void radio_switch_complete_and_tx(u8_t phy_rx, u8_t flags_rx, u8_t phy_tx,
			u8_t flags_tx);
void radio_switch_complete_and_disable(void);
void radio_rssi_measure(void);
u32_t radio_rssi_get(void);
void radio_rssi_status_reset(void);
u32_t radio_rssi_is_ready(void);
void radio_filter_configure(u8_t bitmask_enable, u8_t bitmask_addr_type,
		u8_t *bdaddr);
void radio_filter_disable(void);
void radio_filter_status_reset(void);
u32_t radio_filter_has_match(void);
u32_t radio_filter_match_get(void);
void radio_bc_configure(u32_t n);
void radio_bc_status_reset(void);
u32_t radio_bc_has_match(void);
void radio_tmr_status_reset(void);
void radio_tmr_tifs_set(u32_t tifs);
u32_t radio_tmr_start(u8_t trx, u32_t ticks_start, u32_t remainder);
void radio_tmr_start_us(u8_t trx, u32_t us);
u32_t radio_tmr_start_now(u8_t trx);
void radio_tmr_stop(void);
void radio_tmr_hcto_configure(u32_t hcto);
void radio_tmr_aa_capture(void);
u32_t radio_tmr_aa_get(void);
void radio_tmr_aa_save(u32_t aa);
u32_t radio_tmr_aa_restore(void);
u32_t radio_tmr_ready_get(void);
void radio_tmr_end_capture(void);
u32_t radio_tmr_end_get(void);
void radio_tmr_sample(void);
u32_t radio_tmr_sample_get(void);
void radio_gpio_pa_setup(void);
void radio_gpio_lna_setup(void);
void radio_gpio_lna_on(void);
void radio_gpio_lna_off(void);
void radio_gpio_pa_lna_enable(u32_t trx_us);
void radio_gpio_pa_lna_disable(void);
void *radio_ccm_rx_pkt_set(struct ccm *ccm, u8_t phy, void *pkt);
void *radio_ccm_tx_pkt_set(struct ccm *ccm, void *pkt);
u32_t radio_ccm_is_done(void);
u32_t radio_ccm_mic_is_valid(void);
void radio_ar_configure(u32_t nirk, void *irk);
u32_t radio_ar_match_get(void);
void radio_ar_status_reset(void);
u32_t radio_ar_has_match(void);
u8_t util_ones_count_get(u8_t *octets, u8_t octets_len);
void mem_init(void *mem_pool, u16_t mem_size, u16_t mem_count, void **mem_head);
void *mem_acquire(void **mem_head);
void mem_release(void *mem, void **mem_head);
u16_t mem_free_count_get(void *mem_head);
void *mem_get(void *mem_pool, u16_t mem_size, u16_t index);
u16_t mem_index_get(void *mem, void *mem_pool, u16_t mem_size);
void mem_rcopy(u8_t *dst, u8_t const *src, u16_t len);
u8_t mem_nz(u8_t *src, u16_t len);
u32_t mem_ut(void);
struct _memq_link {
	struct _memq_link *next;
	void *mem;
};
typedef struct _memq_link memq_link_t;
memq_link_t *memq_init(memq_link_t *link, memq_link_t **head,
		memq_link_t **tail);
memq_link_t *memq_enqueue(memq_link_t *link, void *mem, memq_link_t **tail);
memq_link_t *memq_peek(memq_link_t *head, memq_link_t *tail, void **mem);
memq_link_t *memq_dequeue(memq_link_t *tail, memq_link_t **head, void **mem);
struct mayfly {
	u8_t volatile _req;
	u8_t _ack;
	memq_link_t *_link;
	void *param;
	void (*fp)(void *);
};
void mayfly_init(void);
void mayfly_enable(u8_t caller_id, u8_t callee_id, u8_t enable);
u32_t mayfly_enqueue(u8_t caller_id, u8_t callee_id, u8_t chain,
		struct mayfly *m);
void mayfly_run(u8_t callee_id);
extern void mayfly_enable_cb(u8_t caller_id, u8_t callee_id, u8_t enable);
extern u32_t mayfly_is_enabled(u8_t caller_id, u8_t callee_id);
extern u32_t mayfly_prio_is_equal(u8_t caller_id, u8_t callee_id);
extern void mayfly_pend(u8_t caller_id, u8_t callee_id);
typedef void (*ticker_timeout_func) (u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context);
typedef void (*ticker_op_func) (u32_t status, void *op_context);
u32_t ticker_init(u8_t instance_index, u8_t count_node, void *node,
		u8_t count_user, void *user, u8_t count_op, void *user_op);
_Bool 
ticker_is_initialized(u8_t instance_index);
void ticker_trigger(u8_t instance_index);
u32_t ticker_start(u8_t instance_index, u8_t user_id, u8_t ticker_id,
		u32_t ticks_anchor, u32_t ticks_first, u32_t ticks_periodic,
		u32_t remainder_periodic, u16_t lazy, u16_t ticks_slot,
		ticker_timeout_func ticker_timeout_func, void *context,
		ticker_op_func fp_op_func, void *op_context);
u32_t ticker_update(u8_t instance_index, u8_t user_id, u8_t ticker_id,
		u16_t ticks_drift_plus, u16_t ticks_drift_minus,
		u16_t ticks_slot_plus, u16_t ticks_slot_minus, u16_t lazy,
		u8_t force, ticker_op_func fp_op_func, void *op_context);
u32_t ticker_stop(u8_t instance_index, u8_t user_id, u8_t ticker_id,
		ticker_op_func fp_op_func, void *op_context);
u32_t ticker_next_slot_get(u8_t instance_index, u8_t user_id,
		u8_t *ticker_id_head, u32_t *ticks_current,
		u32_t *ticks_to_expire,
		ticker_op_func fp_op_func, void *op_context);
u32_t ticker_job_idle_get(u8_t instance_index, u8_t user_id,
		ticker_op_func fp_op_func, void *op_context);
void ticker_job_sched(u8_t instance_index, u8_t user_id);
u32_t ticker_ticks_now_get(void);
u32_t ticker_ticks_diff_get(u32_t ticks_now, u32_t ticks_old);
struct pdu_adv_payload_adv_ind {
	u8_t addr[6];
	u8_t data[31];
} 
__attribute__((__packed__))
	;
	struct pdu_adv_payload_direct_ind {
		u8_t adv_addr[6];
		u8_t tgt_addr[6];
	} 
__attribute__((__packed__))
	;
	struct pdu_adv_payload_scan_rsp {
		u8_t addr[6];
		u8_t data[31];
	} 
__attribute__((__packed__))
	;
	struct pdu_adv_payload_scan_req {
		u8_t scan_addr[6];
		u8_t adv_addr[6];
	} 
__attribute__((__packed__))
	;
	struct pdu_adv_payload_connect_ind {
		u8_t init_addr[6];
		u8_t adv_addr[6];
		struct {
			u8_t access_addr[4];
			u8_t crc_init[3];
			u8_t win_size;
			u16_t win_offset;
			u16_t interval;
			u16_t latency;
			u16_t timeout;
			u8_t chan_map[5];
			u8_t hop:5;
			u8_t sca:3;
		} 
		__attribute__((__packed__)) 
			lldata;
	} 
__attribute__((__packed__))
	;
	enum pdu_adv_type {
		PDU_ADV_TYPE_ADV_IND = 0x00,
		PDU_ADV_TYPE_DIRECT_IND = 0x01,
		PDU_ADV_TYPE_NONCONN_IND = 0x02,
		PDU_ADV_TYPE_SCAN_REQ = 0x03,
		PDU_ADV_TYPE_AUX_SCAN_REQ = PDU_ADV_TYPE_SCAN_REQ,
		PDU_ADV_TYPE_SCAN_RSP = 0x04,
		PDU_ADV_TYPE_CONNECT_IND = 0x05,
		PDU_ADV_TYPE_AUX_CONNECT_REQ = PDU_ADV_TYPE_CONNECT_IND,
		PDU_ADV_TYPE_SCAN_IND = 0x06,
		PDU_ADV_TYPE_EXT_IND = 0x07,
		PDU_ADV_TYPE_AUX_ADV_IND = PDU_ADV_TYPE_EXT_IND,
		PDU_ADV_TYPE_AUX_SCAN_RSP = PDU_ADV_TYPE_EXT_IND,
		PDU_ADV_TYPE_AUX_SYNC_IND = PDU_ADV_TYPE_EXT_IND,
		PDU_ADV_TYPE_AUX_CHAIN_IND = PDU_ADV_TYPE_EXT_IND,
		PDU_ADV_TYPE_AUX_CONNECT_RSP = 0x08,
	} 
__attribute__((__packed__))
	;
	struct pdu_adv {
		u8_t type:4;
		u8_t rfu:1;
		u8_t chan_sel:1;
		u8_t tx_addr:1;
		u8_t rx_addr:1;
		u8_t len:8;
		union {
			struct pdu_adv_payload_adv_ind adv_ind;
			struct pdu_adv_payload_direct_ind direct_ind;
			struct pdu_adv_payload_scan_req scan_req;
			struct pdu_adv_payload_scan_rsp scan_rsp;
			struct pdu_adv_payload_connect_ind connect_ind;
		} 
		__attribute__((__packed__)) 
			payload;
	} 
__attribute__((__packed__))
	;
	enum pdu_data_llid {
		PDU_DATA_LLID_RESV = 0x00,
		PDU_DATA_LLID_DATA_CONTINUE = 0x01,
		PDU_DATA_LLID_DATA_START = 0x02,
		PDU_DATA_LLID_CTRL = 0x03,
	};
enum pdu_data_llctrl_type {
	PDU_DATA_LLCTRL_TYPE_CONN_UPDATE_IND = 0x00,
	PDU_DATA_LLCTRL_TYPE_CHAN_MAP_IND = 0x01,
	PDU_DATA_LLCTRL_TYPE_TERMINATE_IND = 0x02,
	PDU_DATA_LLCTRL_TYPE_ENC_REQ = 0x03,
	PDU_DATA_LLCTRL_TYPE_ENC_RSP = 0x04,
	PDU_DATA_LLCTRL_TYPE_START_ENC_REQ = 0x05,
	PDU_DATA_LLCTRL_TYPE_START_ENC_RSP = 0x06,
	PDU_DATA_LLCTRL_TYPE_UNKNOWN_RSP = 0x07,
	PDU_DATA_LLCTRL_TYPE_FEATURE_REQ = 0x08,
	PDU_DATA_LLCTRL_TYPE_FEATURE_RSP = 0x09,
	PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_REQ = 0x0A,
	PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_RSP = 0x0B,
	PDU_DATA_LLCTRL_TYPE_VERSION_IND = 0x0C,
	PDU_DATA_LLCTRL_TYPE_REJECT_IND = 0x0D,
	PDU_DATA_LLCTRL_TYPE_SLAVE_FEATURE_REQ = 0x0E,
	PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ = 0x0F,
	PDU_DATA_LLCTRL_TYPE_CONN_PARAM_RSP = 0x10,
	PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND = 0x11,
	PDU_DATA_LLCTRL_TYPE_PING_REQ = 0x12,
	PDU_DATA_LLCTRL_TYPE_PING_RSP = 0x13,
	PDU_DATA_LLCTRL_TYPE_LENGTH_REQ = 0x14,
	PDU_DATA_LLCTRL_TYPE_LENGTH_RSP = 0x15,
	PDU_DATA_LLCTRL_TYPE_PHY_REQ = 0x16,
	PDU_DATA_LLCTRL_TYPE_PHY_RSP = 0x17,
	PDU_DATA_LLCTRL_TYPE_PHY_UPD_IND = 0x18,
	PDU_DATA_LLCTRL_TYPE_MIN_USED_CHAN_IND = 0x19,
};
struct pdu_data_llctrl_conn_update_ind {
	u8_t win_size;
	u16_t win_offset;
	u16_t interval;
	u16_t latency;
	u16_t timeout;
	u16_t instant;
} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_chan_map_ind {
		u8_t chm[5];
		u16_t instant;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_terminate_ind {
		u8_t error_code;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_enc_req {
		u8_t rand[8];
		u8_t ediv[2];
		u8_t skdm[8];
		u8_t ivm[4];
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_enc_rsp {
		u8_t skds[8];
		u8_t ivs[4];
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_unknown_rsp {
		u8_t type;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_feature_req {
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_feature_rsp {
		u8_t features[8];
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_version_ind {
		u8_t version_number;
		u16_t company_id;
		u16_t sub_version_number;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_reject_ind {
		u8_t error_code;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_conn_param_req {
		u16_t interval_min;
		u16_t interval_max;
		u16_t latency;
		u16_t timeout;
		u8_t preferred_periodicity;
		u16_t reference_conn_event_count;
		u16_t offset0;
		u16_t offset1;
		u16_t offset2;
		u16_t offset3;
		u16_t offset4;
		u16_t offset5;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_conn_param_rsp {
		u16_t interval_min;
		u16_t interval_max;
		u16_t latency;
		u16_t timeout;
		u8_t preferred_periodicity;
		u16_t reference_conn_event_count;
		u16_t offset0;
		u16_t offset1;
		u16_t offset2;
		u16_t offset3;
		u16_t offset4;
		u16_t offset5;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_reject_ext_ind {
		u8_t reject_opcode;
		u8_t error_code;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_length_req_rsp {
		u16_t max_rx_octets;
		u16_t max_rx_time;
		u16_t max_tx_octets;
		u16_t max_tx_time;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_phy_req_rsp {
		u8_t tx_phys;
		u8_t rx_phys;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_phy_upd_ind {
		u8_t m_to_s_phy;
		u8_t s_to_m_phy;
		u16_t instant;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl_min_used_chans_ind {
		u8_t phys;
		u8_t min_used_chans;
	} 
__attribute__((__packed__))
	;
	struct pdu_data_llctrl {
		u8_t opcode;
		union {
			struct pdu_data_llctrl_conn_update_ind conn_update_ind;
			struct pdu_data_llctrl_chan_map_ind chan_map_ind;
			struct pdu_data_llctrl_terminate_ind terminate_ind;
			struct pdu_data_llctrl_enc_req enc_req;
			struct pdu_data_llctrl_enc_rsp enc_rsp;
			struct pdu_data_llctrl_unknown_rsp unknown_rsp;
			struct pdu_data_llctrl_feature_req feature_req;
			struct pdu_data_llctrl_feature_rsp feature_rsp;
			struct pdu_data_llctrl_version_ind version_ind;
			struct pdu_data_llctrl_reject_ind reject_ind;
			struct pdu_data_llctrl_feature_req slave_feature_req;
			struct pdu_data_llctrl_conn_param_req conn_param_req;
			struct pdu_data_llctrl_conn_param_rsp conn_param_rsp;
			struct pdu_data_llctrl_reject_ext_ind reject_ext_ind;
			struct pdu_data_llctrl_length_req_rsp length_req;
			struct pdu_data_llctrl_length_req_rsp length_rsp;
			struct pdu_data_llctrl_phy_req_rsp phy_req;
			struct pdu_data_llctrl_phy_req_rsp phy_rsp;
			struct pdu_data_llctrl_phy_upd_ind phy_upd_ind;
			struct pdu_data_llctrl_min_used_chans_ind min_used_chans_ind;
		} 
		__attribute__((__packed__)) 
			ctrldata;
	} 
__attribute__((__packed__))
	;
	struct pdu_data {
		u8_t ll_id:2;
		u8_t nesn:1;
		u8_t sn:1;
		u8_t md:1;
		u8_t rfu:3;
		u8_t len:8;
		u8_t resv:8;
		union {
			u8_t lldata[1];
			struct pdu_data_llctrl llctrl;
		} 
		__attribute__((__packed__)) 
			payload;
	} 
__attribute__((__packed__))
	;
	struct radio_adv_data {
		u8_t data[2][(
				__builtin_offsetof (
					struct pdu_adv
					, 
					payload
					) 
				+ 37)];
		u8_t first;
		u8_t last;
	};
struct radio_pdu_node_tx {
	void *next;
	u8_t pdu_data[1];
};
enum radio_pdu_node_rx_type {
	NODE_RX_TYPE_NONE,
	NODE_RX_TYPE_DC_PDU,
	NODE_RX_TYPE_REPORT,
	NODE_RX_TYPE_CONNECTION,
	NODE_RX_TYPE_TERMINATE,
	NODE_RX_TYPE_CONN_UPDATE,
	NODE_RX_TYPE_ENC_REFRESH,
	NODE_RX_TYPE_CHAN_SEL_ALGO,
	NODE_RX_TYPE_PHY_UPDATE,
};
struct radio_le_conn_cmplt {
	u8_t status;
	u8_t role;
	u8_t peer_addr_type;
	u8_t peer_addr[6];
	u16_t interval;
	u16_t latency;
	u16_t timeout;
	u8_t mca;
} 
__attribute__((__packed__))
	;
	struct radio_le_conn_update_cmplt {
		u8_t status;
		u16_t interval;
		u16_t latency;
		u16_t timeout;
	} 
__attribute__((__packed__))
	;
	struct radio_le_chan_sel_algo {
		u8_t chan_sel_algo;
	} 
__attribute__((__packed__))
	;
	struct radio_le_phy_upd_cmplt {
		u8_t status;
		u8_t tx;
		u8_t rx;
	} 
__attribute__((__packed__))
	;
	struct radio_pdu_node_rx_hdr {
		union {
			sys_snode_t node;
			void *next;
			void *link;
			u8_t packet_release_last;
		} onion;
		enum radio_pdu_node_rx_type type;
		u16_t handle;
	};
struct radio_pdu_node_rx {
	struct radio_pdu_node_rx_hdr hdr;
	u8_t pdu_data[1];
};
u32_t radio_init(void *hf_clock, u8_t sca, u8_t connection_count_max,
		u8_t rx_count_max, u8_t tx_count_max,
		u16_t packet_data_octets_max,
		u16_t packet_tx_data_size, u8_t *mem_radio,
		u16_t mem_size);
struct device *radio_hf_clock_get(void);
void radio_ticks_active_to_start_set(u32_t ticks_active_to_start);
struct radio_adv_data *radio_adv_data_get(void);
struct radio_adv_data *radio_scan_data_get(void);
u32_t radio_adv_enable(u16_t interval, u8_t chan_map, u8_t filter_policy,
		u8_t rl_idx);
u32_t radio_adv_disable(void);
u32_t radio_adv_is_enabled(void);
u32_t radio_adv_filter_pol_get(void);
u32_t radio_scan_enable(u8_t type, u8_t init_addr_type, u8_t *init_addr,
		u16_t interval, u16_t window, u8_t filter_policy,
		u8_t rpa_gen, u8_t rl_idx);
u32_t radio_scan_disable(void);
u32_t radio_scan_is_enabled(void);
u32_t radio_scan_filter_pol_get(void);
u32_t radio_connect_enable(u8_t adv_addr_type, u8_t *adv_addr,
		u16_t interval, u16_t latency,
		u16_t timeout);
u8_t radio_rx_get(struct radio_pdu_node_rx **radio_pdu_node_rx,
		u16_t *handle);
void radio_rx_dequeue(void);
void radio_rx_mem_release(struct radio_pdu_node_rx **radio_pdu_node_rx);
u8_t radio_rx_fc_set(u16_t handle, u8_t fc);
u8_t radio_rx_fc_get(u16_t *handle);
struct radio_pdu_node_tx *radio_tx_mem_acquire(void);
void radio_tx_mem_release(struct radio_pdu_node_tx *pdu_data_node_tx);
u32_t radio_tx_mem_enqueue(u16_t handle,
		struct radio_pdu_node_tx *pdu_data_node_tx);
extern void radio_active_callback(u8_t active);
extern void radio_event_callback(void);
extern void ll_adv_scan_state_cb(u8_t bm);
enum llcp {
	LLCP_NONE,
	LLCP_CONN_UPD,
	LLCP_CHAN_MAP,
	LLCP_ENCRYPTION,
	LLCP_FEATURE_EXCHANGE,
	LLCP_VERSION_EXCHANGE,
	LLCP_CONNECTION_PARAM_REQ,
	LLCP_PHY_UPD,
};
struct shdr {
	u32_t ticks_xtal_to_start;
	u32_t ticks_active_to_start;
	u32_t ticks_preempt_to_start;
	u32_t ticks_slot;
};
struct connection {
	struct shdr hdr;
	u8_t access_addr[4];
	u8_t crc_init[3];
	u8_t data_chan_map[5];
	u8_t chm_update;
	u8_t data_chan_count:6;
	u8_t data_chan_sel:1;
	u8_t role:1;
	union {
		struct {
			u8_t data_chan_hop;
			u8_t data_chan_use;
		};
		u16_t data_chan_id;
	};
	u16_t handle;
	u16_t event_counter;
	u16_t conn_interval;
	u16_t latency;
	u16_t latency_prepare;
	u16_t latency_event;
	u8_t phy_pref_tx:3;
	u8_t phy_tx:3;
	u8_t phy_pref_flags:1;
	u8_t phy_flags:1;
	u8_t phy_tx_time:3;
	u8_t phy_pref_rx:3;
	u8_t phy_rx:3;
	u16_t connect_expire;
	u16_t supervision_reload;
	u16_t supervision_expire;
	u16_t procedure_reload;
	u16_t procedure_expire;
	union {
		struct {
			u8_t reserved:5;
			u8_t fex_valid:1;
		} common;
		struct {
			u8_t terminate_ack:1;
			u8_t rfu:4;
			u8_t fex_valid:1;
		} master;
		struct {
			u8_t latency_enabled:1;
			u8_t latency_cancel:1;
			u8_t sca:3;
			u8_t fex_valid:1;
			u32_t window_widening_periodic_us;
			u32_t window_widening_max_us;
			u32_t window_widening_prepare_us;
			u32_t window_widening_event_us;
			u32_t window_size_prepare_us;
			u32_t window_size_event_us;
			u32_t force;
			u32_t ticks_to_offset;
		} slave;
	};
	u8_t llcp_req;
	u8_t llcp_ack;
	enum llcp llcp_type;
	union {
		struct {
			enum {
				LLCP_CUI_STATE_INPROG,
				LLCP_CUI_STATE_USE,
				LLCP_CUI_STATE_SELECT
			} state:2 
			__attribute__((__packed__))
				;
			u8_t is_internal:1;
			u16_t interval;
			u16_t latency;
			u16_t timeout;
			u16_t instant;
			u32_t win_offset_us;
			u8_t win_size;
			u16_t *pdu_win_offset;
			u32_t ticks_anchor;
		} conn_upd;
		struct {
			u8_t initiate;
			u8_t chm[5];
			u16_t instant;
		} chan_map;
		struct {
			u8_t initiate:1;
			u8_t cmd:1;
			u8_t tx:3;
			u8_t rx:3;
			u16_t instant;
		} phy_upd_ind;
		struct {
			u8_t initiate;
			u8_t error_code;
			u8_t rand[8];
			u8_t ediv[2];
			u8_t ltk[16];
			u8_t skd[16];
		} encryption;
	} llcp;
	u32_t llcp_features;
	struct {
		u8_t tx:1;
		u8_t rx:1;
		u8_t version_number;
		u16_t company_id;
		u16_t sub_version_number;
	} llcp_version;
	struct {
		u8_t req;
		u8_t ack;
		u8_t reason_own;
		u8_t reason_peer;
		struct {
			struct radio_pdu_node_rx_hdr hdr;
			u8_t reason;
		} radio_pdu_node_rx;
	} llcp_terminate;
	struct {
		u8_t req;
		u8_t ack;
		enum {
			LLCP_CPR_STATE_REQ,
			LLCP_CPR_STATE_RSP,
			LLCP_CPR_STATE_APP_REQ,
			LLCP_CPR_STATE_APP_WAIT,
			LLCP_CPR_STATE_RSP_WAIT,
			LLCP_CPR_STATE_UPD
		} state:3 
		__attribute__((__packed__))
			;
		u8_t cmd:1;
		u8_t status;
		u16_t interval;
		u16_t latency;
		u16_t timeout;
		u8_t preferred_periodicity;
		u16_t reference_conn_event_count;
		u16_t offset0;
		u16_t offset1;
		u16_t offset2;
		u16_t offset3;
		u16_t offset4;
		u16_t offset5;
		u16_t *pdu_win_offset0;
		u32_t ticks_ref;
		u32_t ticks_to_offset_next;
	} llcp_conn_param;
	struct {
		u8_t req;
		u8_t ack;
		u8_t state:2;
		u8_t tx:3;
		u8_t rx:3;
		u8_t flags:1;
		u8_t cmd:1;
	} llcp_phy;
	u8_t sn:1;
	u8_t nesn:1;
	u8_t pause_rx:1;
	u8_t pause_tx:1;
	u8_t enc_rx:1;
	u8_t enc_tx:1;
	u8_t refresh:1;
	u8_t empty:1;
	struct ccm ccm_rx;
	struct ccm ccm_tx;
	struct radio_pdu_node_tx *pkt_tx_head;
	struct radio_pdu_node_tx *pkt_tx_ctrl;
	struct radio_pdu_node_tx *pkt_tx_ctrl_last;
	struct radio_pdu_node_tx *pkt_tx_data;
	struct radio_pdu_node_tx *pkt_tx_last;
	u8_t packet_tx_head_len;
	u8_t packet_tx_head_offset;
};
struct pdu_data_q_tx {
	u16_t handle;
	struct radio_pdu_node_tx *node_tx;
};
struct ll_filter {
	u8_t enable_bitmask;
	u8_t addr_type_bitmask;
	u8_t bdaddr[8][6];
};
void ll_filter_reset(
		_Bool 
		init);
void ll_filters_adv_update(u8_t adv_fp);
void ll_filters_scan_update(u8_t scan_fp);
struct ll_filter *ctrl_filter_get(
		_Bool 
		whitelist);
bt_addr_t *ctrl_lrpa_get(u8_t rl_idx);
u8_t *ctrl_irks_get(u8_t *count);
u8_t ctrl_rl_idx(
		_Bool 
		whitelist, u8_t devmatch_id);
u8_t ctrl_rl_irk_idx(u8_t irkmatch_id);
_Bool 
ctrl_irk_whitelisted(u8_t rl_idx);
_Bool 
ctrl_rl_enabled(void);
void ll_rl_rpa_update(
		_Bool 
		timeout);
u8_t ll_rl_find(u8_t id_addr_type, u8_t *id_addr, u8_t *free);
_Bool 
ctrl_rl_addr_allowed(u8_t id_addr_type, u8_t *id_addr, u8_t *rl_idx);
_Bool 
ctrl_rl_addr_resolve(u8_t id_addr_type, u8_t *id_addr, u8_t rl_idx);
_Bool 
ctrl_rl_idx_allowed(u8_t irkmatch_ok, u8_t rl_idx);
void ll_rl_pdu_adv_update(u8_t idx, struct pdu_adv *pdu);
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
int isalnum (int __c);
int isalpha (int __c);
int iscntrl (int __c);
int isdigit (int __c);
int isgraph (int __c);
int islower (int __c);
int isprint (int __c);
int ispunct (int __c);
int isspace (int __c);
int isupper (int __c);
int isxdigit (int __c);
int tolower (int __c);
int toupper (int __c);
int isblank (int __c);
int isascii (int __c);
int toascii (int __c);
extern int isalnum_l (int __c, locale_t __l);
extern int isalpha_l (int __c, locale_t __l);
extern int isblank_l (int __c, locale_t __l);
extern int iscntrl_l (int __c, locale_t __l);
extern int isdigit_l (int __c, locale_t __l);
extern int isgraph_l (int __c, locale_t __l);
extern int islower_l (int __c, locale_t __l);
extern int isprint_l (int __c, locale_t __l);
extern int ispunct_l (int __c, locale_t __l);
extern int isspace_l (int __c, locale_t __l);
extern int isupper_l (int __c, locale_t __l);
extern int isxdigit_l(int __c, locale_t __l);
extern int tolower_l (int __c, locale_t __l);
extern int toupper_l (int __c, locale_t __l);
extern int isascii_l (int __c, locale_t __l);
extern int toascii_l (int __c, locale_t __l);
const char *__locale_ctype_ptr (void);
const char *__locale_ctype_ptr_l (locale_t);
extern const char _ctype_[];
void *memrchr( const void *s, int c, size_t n );
typedef uint8_t mico_bool_t;
typedef uint32_t mico_time_t;
typedef uint32_t mico_utc_time_t;
typedef uint64_t mico_utc_time_ms_t;
typedef int OSStatus;
static inline inline __attribute__((always_inline)) char nibble_to_hexchar( uint8_t nibble )
{
	if (nibble > 9)
	{
		return (char)('A' + (nibble - 10));
	}
	else
	{
		return (char) ('0' + nibble);
	}
}
static inline inline __attribute__((always_inline)) char hexchar_to_nibble( char hexchar, uint8_t* nibble )
{
	if ( ( hexchar >= '0' ) && ( hexchar <= '9' ) )
	{
		*nibble = (uint8_t)( hexchar - '0' );
		return 0;
	}
	else if ( ( hexchar >= 'A' ) && ( hexchar <= 'F' ) )
	{
		*nibble = (uint8_t) ( hexchar - 'A' + 10 );
		return 0;
	}
	else if ( ( hexchar >= 'a' ) && ( hexchar <= 'f' ) )
	{
		*nibble = (uint8_t) ( hexchar - 'a' + 10 );
		return 0;
	}
	return -1;
}
static const int _INIT_LEVEL_PRE_KERNEL_1 = 1;
static const int _INIT_LEVEL_PRE_KERNEL_2 = 1;
static const int _INIT_LEVEL_POST_KERNEL = 1;
static const int _INIT_LEVEL_APPLICATION = 1;
struct device {
	struct device_config *config;
	const void *driver_api;
	void *driver_data;
};
struct device_config {
	char *name;
	int (*init)(struct device *device);
	int (*device_pm_control)(struct device *device, u32_t command,
			void *context);
	const void *config_info;
};
struct device;
void _sys_device_do_config_level(int level);
struct device *device_get_binding(const char *name);
void device_busy_set(struct device *busy_dev);
void device_busy_clear(struct device *busy_dev);
int device_pm_control_nop(struct device *unused_device,
		u32_t unused_ctrl_command, void *unused_context);
static inline int device_set_power_state(struct device *device,
		u32_t device_power_state)
{
	return device->config->device_pm_control(device,
			1, &device_power_state);
}
static inline int device_get_power_state(struct device *device,
		u32_t *device_power_state)
{
	return device->config->device_pm_control(device,
			2, device_power_state);
}
void device_list_get(struct device **device_list, int *device_count);
int device_any_busy_check(void);
int device_busy_check(struct device *chk_dev);
typedef void *clock_control_subsys_t;
typedef int (*clock_control)(struct device *dev, clock_control_subsys_t sys);
typedef int (*clock_control_get)(struct device *dev,
		clock_control_subsys_t sys,
		u32_t *rate);
struct clock_control_driver_api {
	clock_control on;
	clock_control off;
	clock_control_get get_rate;
};
static inline int clock_control_on(struct device *dev,
		clock_control_subsys_t sys)
{
	const struct clock_control_driver_api *api = dev->driver_api;
	return api->on(dev, sys);
}
static inline int clock_control_off(struct device *dev,
		clock_control_subsys_t sys)
{
	const struct clock_control_driver_api *api = dev->driver_api;
	return api->off(dev, sys);
}
static inline int clock_control_get_rate(struct device *dev,
		clock_control_subsys_t sys,
		u32_t *rate)
{
	const struct clock_control_driver_api *api = dev->driver_api;
	do { } while ((0))
		;
	return api->get_rate(dev, sys, rate);
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
const char *bt_hex(const void *buf, size_t len);
const char *bt_addr_str(const bt_addr_t *addr);
const char *bt_addr_le_str(const bt_addr_le_t *addr);
enum role {
	ROLE_NONE,
	ROLE_ADV,
	ROLE_SCAN,
	ROLE_SLAVE,
	ROLE_MASTER,
};
enum state {
	STATE_NONE,
	STATE_RX,
	STATE_TX,
	STATE_CLOSE,
	STATE_STOP,
	STATE_ABORT,
};
struct advertiser {
	struct shdr hdr;
	u8_t is_enabled:1;
	u8_t chan_map_current:3;
	u8_t rfu:4;
	u8_t chan_map:3;
	u8_t filter_policy:2;
	struct radio_adv_data adv_data;
	struct radio_adv_data scan_data;
	struct connection *conn;
};
struct scanner {
	struct shdr hdr;
	u8_t is_enabled:1;
	u8_t state:1;
	u8_t chan:2;
	u8_t rfu:4;
	u8_t type:1;
	u8_t filter_policy:2;
	u8_t adv_addr_type:1;
	u8_t init_addr_type:1;
	u8_t init_addr[6];
	u8_t adv_addr[6];
	u32_t ticks_window;
	u16_t conn_interval;
	u16_t conn_latency;
	u16_t conn_timeout;
	u32_t ticks_conn_slot;
	struct connection *conn;
	u32_t win_offset_us;
};
static struct {
	struct device *hf_clock;
	u32_t ticks_anchor;
	u32_t remainder_anchor;
	u8_t volatile ticker_id_prepare;
	u8_t volatile ticker_id_event;
	u8_t volatile ticker_id_stop;
	enum role volatile role;
	enum state state;
	struct advertiser advertiser;
	struct scanner scanner;
	void *conn_pool;
	void *conn_free;
	u8_t connection_count;
	struct connection *conn_curr;
	u8_t packet_counter;
	u8_t crc_expire;
	u8_t data_chan_map[5];
	u8_t data_chan_count;
	u8_t sca;
	u16_t default_phy_tx;
	u16_t default_phy_rx;
	void *pkt_rx_data_pool;
	void *pkt_rx_data_free;
	u16_t packet_data_octets_max;
	u16_t packet_rx_data_pool_size;
	u16_t packet_rx_data_size;
	u8_t packet_rx_data_count;
	struct radio_pdu_node_rx **packet_rx;
	u8_t packet_rx_count;
	u8_t volatile packet_rx_last;
	u8_t packet_rx_acquire;
	void *link_rx_pool;
	void *link_rx_free;
	memq_link_t *link_rx_head;
	memq_link_t *volatile link_rx_tail;
	u8_t link_rx_data_quota;
	void *pkt_tx_ctrl_pool;
	void *pkt_tx_ctrl_free;
	void *pkt_tx_data_pool;
	void *pkt_tx_data_free;
	u16_t packet_tx_data_size;
	struct pdu_data_q_tx *pkt_tx;
	struct pdu_data_q_tx *pkt_release;
	u8_t packet_tx_count;
	u8_t volatile packet_tx_first;
	u8_t packet_tx_last;
	u8_t packet_release_first;
	u8_t volatile packet_release_last;
	u16_t fc_handle[3];
	u8_t volatile fc_req;
	u8_t fc_ack;
	u8_t fc_ena;
	u32_t ticks_active_to_start;
	struct connection *conn_upd;
} _radio;
static u16_t const gc_lookup_ppm[] = { 500, 250, 150, 100, 75, 50, 30, 20 };
static void common_init(void);
static void ticker_success_assert(u32_t status, void *params);
static void ticker_stop_adv_assert(u32_t status, void *params);
static void ticker_stop_scan_assert(u32_t status, void *params);
static void ticker_update_adv_assert(u32_t status, void *params);
static void ticker_update_slave_assert(u32_t status, void *params);
static void event_inactive(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context);
static void adv_setup(void);
static void event_adv(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context);
static void event_scan(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context);
static void event_slave_prepare(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context);
static void event_slave(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context);
static void event_master_prepare(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context);
static void event_master(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context);
static void rx_packet_set(struct connection *conn,
		struct pdu_data *pdu_data_rx);
static void tx_packet_set(struct connection *conn,
		struct pdu_data *pdu_data_tx);
static void prepare_pdu_data_tx(struct connection *conn,
		struct pdu_data **pdu_data_tx);
static void packet_rx_allocate(u8_t max);
static inline u8_t packet_rx_acquired_count_get(void);
static inline struct radio_pdu_node_rx *packet_rx_reserve_get(u8_t count);
static void packet_rx_enqueue(void);
static void packet_tx_enqueue(u8_t max);
static struct pdu_data *empty_tx_enqueue(struct connection *conn);
static void ctrl_tx_enqueue(struct connection *conn,
		struct radio_pdu_node_tx *node_tx);
static void pdu_node_tx_release(u16_t handle,
		struct radio_pdu_node_tx *node_tx);
static void connection_release(struct connection *conn);
static void terminate_ind_rx_enqueue(struct connection *conn, u8_t reason);
static u32_t conn_update(struct connection *conn, struct pdu_data *pdu_data_rx);
static u32_t chan_map_update(struct connection *conn,
		struct pdu_data *pdu_data_rx);
static inline u32_t phy_upd_ind(struct radio_pdu_node_rx *radio_pdu_node_rx,
		u8_t *rx_enqueue);
static void enc_req_reused_send(struct connection *conn,
		struct radio_pdu_node_tx *node_tx);
static u8_t enc_rsp_send(struct connection *conn);
static u8_t start_enc_rsp_send(struct connection *conn,
		struct pdu_data *pdu_ctrl_tx);
static u8_t pause_enc_rsp_send(struct connection *conn, u8_t req);
static u8_t unknown_rsp_send(struct connection *conn, u8_t type);
static u8_t feature_rsp_send(struct connection *conn,
		struct pdu_data *pdu_data_rx);
static u8_t version_ind_send(struct connection *conn,
		struct pdu_data *pdu_data_rx, u8_t *rx_enqueue);
static u8_t reject_ext_ind_send(struct connection *conn, u8_t reject_opcode,
		u8_t error_code);
static u8_t phy_rsp_send(struct connection *conn, struct pdu_data *pdu_data_rx);
static u32_t role_disable(u8_t ticker_id_primary, u8_t ticker_id_stop);
static void rx_fc_lock(u16_t handle);
u32_t radio_init(void *hf_clock, u8_t sca, u8_t connection_count_max,
		u8_t rx_count_max, u8_t tx_count_max,
		u16_t packet_data_octets_max,
		u16_t packet_tx_data_size, u8_t *mem_radio,
		u16_t mem_size)
{
	u32_t retcode;
	u8_t *mem_radio_end;
	_radio.hf_clock = hf_clock;
	_radio.sca = sca;
	mem_radio_end = mem_radio + mem_size;
	_radio.connection_count = connection_count_max;
	_radio.conn_pool = mem_radio;
	mem_radio += (sizeof(struct connection) * _radio.connection_count);
	rx_count_max += 3;
	tx_count_max += 1;
	_radio.packet_rx_count = (rx_count_max + 1);
	_radio.packet_tx_count = (tx_count_max + 1);
	_radio.link_rx_data_quota = rx_count_max;
	_radio.packet_rx = (void *)mem_radio;
	mem_radio +=
		(sizeof(struct radio_pdu_node_rx *)*_radio.packet_rx_count);
	_radio.pkt_tx = (void *)mem_radio;
	mem_radio += (sizeof(struct pdu_data_q_tx) * _radio.packet_tx_count);
	_radio.pkt_release = (void *)mem_radio;
	mem_radio += (sizeof(struct pdu_data_q_tx) * _radio.packet_tx_count);
	_radio.packet_data_octets_max = packet_data_octets_max;
	if (((
					__builtin_offsetof (
						struct pdu_adv
						, 
						payload
						) 
					+ 37) + 1) <
			(
			 __builtin_offsetof (
				 struct pdu_data
				 , 
				 payload
				 ) 
			 +
			 _radio.packet_data_octets_max)) {
		_radio.packet_rx_data_pool_size =
			((((u32_t)(
				   __builtin_offsetof (
					   struct radio_pdu_node_rx
					   , 
					   pdu_data
					   ) 
				   + 
				   __builtin_offsetof (
					   struct pdu_data
					   , 
					   payload
					   ) 
				   + _radio.packet_data_octets_max)+3) & (~((u32_t)3)))
			 * rx_count_max);
	} else {
		_radio.packet_rx_data_pool_size =
			((((u32_t)(
				   __builtin_offsetof (
					   struct radio_pdu_node_rx
					   , 
					   pdu_data
					   ) 
				   + ((
						   __builtin_offsetof (
							   struct pdu_adv
							   , 
							   payload
							   ) 
						   + 37) + 1))+3) & (~((u32_t)3)))
			 * rx_count_max);
	}
	_radio.packet_rx_data_size = (((u32_t)(
					__builtin_offsetof (
						struct radio_pdu_node_rx
						, 
						pdu_data
						) 
					+ ((
							__builtin_offsetof (
								struct pdu_adv
								, 
								payload
								) 
							+ 37) + 1))+3) & (~((u32_t)3)));
	_radio.packet_rx_data_count = (_radio.packet_rx_data_pool_size /
			_radio.packet_rx_data_size);
	_radio.pkt_rx_data_pool = mem_radio;
	mem_radio += _radio.packet_rx_data_pool_size;
	_radio.link_rx_pool = mem_radio;
	mem_radio += (sizeof(memq_link_t) * (_radio.packet_rx_count +
				_radio.connection_count));
	_radio.pkt_tx_ctrl_pool = mem_radio;
	mem_radio += (((u32_t)(
					__builtin_offsetof (
						struct radio_pdu_node_tx
						, 
						pdu_data
						) 
					+ 
					__builtin_offsetof (
						struct pdu_data
						, 
						payload
						) 
					+ 27)+3) & (~((u32_t)3))) * 2;
	_radio.packet_tx_data_size =
		(((u32_t)(
			  __builtin_offsetof (
				  struct radio_pdu_node_tx
				  , 
				  pdu_data
				  ) 
			  + 
			  __builtin_offsetof (
				  struct pdu_data
				  , 
				  payload
				  ) 
			  + packet_tx_data_size)+3) & (~((u32_t)3)))
		;
	_radio.pkt_tx_data_pool = mem_radio;
	mem_radio += (_radio.packet_tx_data_size * tx_count_max);
	retcode = (mem_radio - mem_radio_end);
	if (retcode) {
		return (retcode + mem_size);
	}
	_radio.fc_ena = 1;
	common_init();
	radio_setup();
	return retcode;
}
struct device *radio_hf_clock_get(void)
{
	return _radio.hf_clock;
}
void ll_reset(void)
{
	u16_t conn_handle;
	role_disable(5, 3);
	role_disable(6, 4);
	for (conn_handle = 0; conn_handle < _radio.connection_count;
			conn_handle++) {
		role_disable(7 + conn_handle,
				((u8_t)((u8_t)0 - 1)));
	}
	_radio.advertiser.is_enabled = 0;
	_radio.advertiser.conn = 
		((void *)0)
		;
	_radio.scanner.is_enabled = 0;
	_radio.scanner.conn = 
		((void *)0)
		;
	_radio.packet_rx_data_size = (((u32_t)(
					__builtin_offsetof (
						struct radio_pdu_node_rx
						, 
						pdu_data
						) 
					+ ((
							__builtin_offsetof (
								struct pdu_adv
								, 
								payload
								) 
							+ 37) + 1))+3) & (~((u32_t)3)));
	_radio.packet_rx_data_count = (_radio.packet_rx_data_pool_size /
			_radio.packet_rx_data_size);
	_radio.packet_rx_last = 0;
	_radio.packet_rx_acquire = 0;
	_radio.link_rx_data_quota = _radio.packet_rx_count - 1;
	_radio.packet_tx_first = 0;
	_radio.packet_tx_last = 0;
	_radio.packet_release_first = 0;
	_radio.packet_release_last = 0;
	_radio.fc_ack = _radio.fc_req;
	ll_filter_reset(
			0
		       );
	common_init();
}
static void common_init(void)
{
	memq_link_t *link;
	if (_radio.connection_count) {
		mem_init(_radio.conn_pool, (((u32_t)(sizeof(struct connection))+3) & (~((u32_t)3))),
				_radio.connection_count,
				&_radio.conn_free);
	} else {
		_radio.conn_free = 
			((void *)0)
			;
	}
	mem_init(_radio.pkt_rx_data_pool,
			_radio.packet_rx_data_size,
			_radio.packet_rx_data_count,
			&_radio.pkt_rx_data_free);
	mem_init(_radio.link_rx_pool, (sizeof(memq_link_t)),
			(_radio.packet_rx_count + _radio.connection_count),
			&_radio.link_rx_free);
	mem_init(_radio.pkt_tx_ctrl_pool, (((u32_t)(
						__builtin_offsetof (
							struct radio_pdu_node_tx
							, 
							pdu_data
							) 
						+ 
						__builtin_offsetof (
							struct pdu_data
							, 
							payload
							) 
						+ 27)+3) & (~((u32_t)3))),
			2, &_radio.pkt_tx_ctrl_free);
	mem_init(_radio.pkt_tx_data_pool, _radio.packet_tx_data_size,
			(_radio.packet_tx_count - 1), &_radio.pkt_tx_data_free);
	link = mem_acquire(&_radio.link_rx_free);
	if (!(link)) { ; ; };
	memq_init(link, &_radio.link_rx_head, (void *)&_radio.link_rx_tail);
	_radio.advertiser.chan_map = 0x07;
	_radio.data_chan_map[0] = 0xFF;
	_radio.data_chan_map[1] = 0xFF;
	_radio.data_chan_map[2] = 0xFF;
	_radio.data_chan_map[3] = 0xFF;
	_radio.data_chan_map[4] = 0x1F;
	_radio.data_chan_count = 37;
	_radio.default_phy_tx = (1UL << (0));
	_radio.default_phy_rx = (1UL << (0));
	packet_rx_allocate(0xFF);
}
static inline u32_t addr_us_get(u8_t phy)
{
	switch (phy) {
		default:
		case (1UL << (0)):
			return 40;
		case (1UL << (1)):
			return 24;
		case (1UL << (2)):
			return 376;
	}
}
static inline u32_t empty_pkt_us_get(u8_t phy)
{
	switch (phy) {
		default:
		case (1UL << (0)):
			return 80;
		case (1UL << (1)):
			return 40;
		case (1UL << (2)):
			return 720;
	}
}
static inline void isr_radio_state_tx(void)
{
	u32_t hcto;
	_radio.state = STATE_RX;
	hcto = radio_tmr_end_get() + 150 + 4 + 1;
	radio_tmr_tifs_set(150);
	switch (_radio.role) {
		case ROLE_ADV:
			radio_switch_complete_and_tx(0, 0, 0, 0);
			radio_pkt_rx_set(radio_pkt_scratch_get());
			if (!(!radio_is_ready())) { ; ; };
			hcto += radio_rx_chain_delay_get(0, 0);
			hcto += addr_us_get(0);
			hcto -= radio_tx_chain_delay_get(0, 0);
			radio_tmr_hcto_configure(hcto);
			radio_tmr_end_capture();
			break;
		case ROLE_SCAN:
			radio_switch_complete_and_tx(0, 0, 0, 0);
			radio_pkt_rx_set(_radio.packet_rx[_radio.packet_rx_last]->
					pdu_data);
			if (!(!radio_is_ready())) { ; ; };
			hcto += radio_rx_chain_delay_get(0, 0);
			hcto += addr_us_get(0);
			hcto -= radio_tx_chain_delay_get(0, 0);
			radio_tmr_hcto_configure(hcto);
			radio_rssi_measure();
			break;
		case ROLE_MASTER:
		case ROLE_SLAVE:
			radio_switch_complete_and_tx(_radio.conn_curr->phy_rx, 0,
					_radio.conn_curr->phy_tx,
					_radio.conn_curr->phy_flags);
			rx_packet_set(_radio.conn_curr, (struct pdu_data *)_radio.
					packet_rx[_radio.packet_rx_last]->pdu_data);
			if (!(!radio_is_ready())) { ; ; };
			hcto += radio_rx_chain_delay_get(_radio.conn_curr->phy_rx, 1);
			hcto += addr_us_get(_radio.conn_curr->phy_rx);
			hcto -= radio_tx_chain_delay_get(_radio.conn_curr->phy_tx,
					_radio.conn_curr->phy_flags);
			radio_tmr_hcto_configure(hcto);
			packet_tx_enqueue(1);
			break;
		case ROLE_NONE:
		default:
			if (!(0)) { ; ; };
			break;
	}
}
static inline 
	_Bool 
isr_adv_sr_adva_check(struct pdu_adv *adv,
		struct pdu_adv *sr)
{
	return (adv->tx_addr == sr->rx_addr) &&
		!memcmp(adv->payload.adv_ind.addr,
				sr->payload.scan_req.adv_addr, 6);
}
static inline 
	_Bool 
isr_adv_sr_check(struct pdu_adv *adv, struct pdu_adv *sr,
		u8_t devmatch_ok, u8_t *rl_idx)
{
	return (((_radio.advertiser.filter_policy & 0x01) == 0) ||
			(devmatch_ok)) &&
		isr_adv_sr_adva_check(adv, sr);
}
static inline 
	_Bool 
isr_adv_ci_tgta_check(struct pdu_adv *adv, struct pdu_adv *ci,
		u8_t rl_idx)
{
	return (adv->rx_addr == ci->tx_addr) &&
		!memcmp(adv->payload.direct_ind.tgt_addr,
				ci->payload.connect_ind.init_addr, 6);
}
static inline 
	_Bool 
isr_adv_ci_adva_check(struct pdu_adv *adv,
		struct pdu_adv *ci)
{
	return (adv->tx_addr == ci->rx_addr) &&
		(((adv->type == PDU_ADV_TYPE_DIRECT_IND) &&
		  !memcmp(adv->payload.direct_ind.adv_addr,
			  ci->payload.connect_ind.adv_addr, 6)) ||
		 (!memcmp(adv->payload.adv_ind.addr,
			  ci->payload.connect_ind.adv_addr, 6)));
}
static inline 
	_Bool 
isr_adv_ci_check(struct pdu_adv *adv, struct pdu_adv *ci,
		u8_t devmatch_ok, u8_t *rl_idx)
{
	if (adv->type == PDU_ADV_TYPE_DIRECT_IND) {
		return (1) &&
			isr_adv_ci_adva_check(adv, ci) &&
			isr_adv_ci_tgta_check(adv, ci, *rl_idx);
	}
	return (((_radio.advertiser.filter_policy & 0x02) == 0) ||
			(devmatch_ok)) &&
		isr_adv_ci_adva_check(adv, ci);
}
static inline u32_t isr_rx_adv(u8_t devmatch_ok, u8_t devmatch_id,
		u8_t irkmatch_ok, u8_t irkmatch_id,
		u8_t rssi_ready)
{
	struct pdu_adv *pdu_adv, *_pdu_adv;
	struct radio_pdu_node_rx *radio_pdu_node_rx;
	u8_t rl_idx = 0xFF;
	pdu_adv = (struct pdu_adv *)radio_pkt_scratch_get();
	_pdu_adv = (struct pdu_adv *)&_radio.advertiser.adv_data.data
		[_radio.advertiser.adv_data.first][0];
	if ((pdu_adv->type == PDU_ADV_TYPE_SCAN_REQ) &&
			(pdu_adv->len == sizeof(struct pdu_adv_payload_scan_req)) &&
			isr_adv_sr_check(_pdu_adv, pdu_adv, devmatch_ok, &rl_idx)) {
		_radio.state = STATE_CLOSE;
		radio_switch_complete_and_disable();
		radio_pkt_tx_set(&_radio.advertiser.scan_data.
				data[_radio.advertiser.scan_data.first][0]);
		if (!(!radio_is_ready())) { ; ; };
		return 0;
	} else if ((pdu_adv->type == PDU_ADV_TYPE_CONNECT_IND) &&
			(pdu_adv->len == sizeof(struct pdu_adv_payload_connect_ind)) &&
			isr_adv_ci_check(_pdu_adv, pdu_adv, devmatch_ok, &rl_idx) &&
			((_radio.fc_ena == 0) || (_radio.fc_req == _radio.fc_ack)) &&
			(_radio.advertiser.conn)) {
		struct radio_le_conn_cmplt *radio_le_conn_cmplt;
		struct pdu_data *pdu_data;
		struct connection *conn;
		u32_t ticks_slot_offset;
		u32_t conn_interval_us;
		u32_t conn_offset_us;
		u32_t rx_ready_delay;
		u32_t ticker_status;
		if (1) {
			radio_pdu_node_rx = packet_rx_reserve_get(4);
		} else {
			radio_pdu_node_rx = packet_rx_reserve_get(3);
		}
		if (radio_pdu_node_rx == 0) {
			return 1;
		}
		_radio.state = STATE_STOP;
		radio_disable();
		conn = _radio.advertiser.conn;
		_radio.advertiser.conn = 
			((void *)0)
			;
		conn->handle = mem_index_get(conn, _radio.conn_pool,
				(((u32_t)(sizeof(struct connection))+3) & (~((u32_t)3))));
		memcpy(&conn->crc_init[0],
				&pdu_adv->payload.connect_ind.lldata.crc_init[0],
				3);
		memcpy(&conn->access_addr[0],
				&pdu_adv->payload.connect_ind.lldata.access_addr[0],
				4);
		memcpy(&conn->data_chan_map[0],
				&pdu_adv->payload.connect_ind.lldata.chan_map[0],
				sizeof(conn->data_chan_map));
		conn->data_chan_count =
			util_ones_count_get(&conn->data_chan_map[0],
					sizeof(conn->data_chan_map));
		conn->data_chan_hop = pdu_adv->payload.connect_ind.lldata.hop;
		conn->conn_interval =
			pdu_adv->payload.connect_ind.lldata.interval;
		conn_interval_us =
			pdu_adv->payload.connect_ind.lldata.interval * 1250;
		conn->latency = pdu_adv->payload.connect_ind.lldata.latency;
		memcpy((void *)&conn->slave.force, &conn->access_addr[0],
				sizeof(conn->slave.force));
		conn->supervision_reload =
			((u16_t)((((pdu_adv->payload.connect_ind.lldata.timeout * 10 * 1000)) + (conn_interval_us) - 1) / (conn_interval_us)))
			;
		conn->procedure_reload = ((u16_t)((((40 * 1000 * 1000)) + (conn_interval_us) - 1) / (conn_interval_us)))
			;
		radio_pdu_node_rx->hdr.handle = conn->handle;
		radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_CONNECTION;
		pdu_data = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
		radio_le_conn_cmplt =
			(struct radio_le_conn_cmplt *)&pdu_data->payload;
		radio_le_conn_cmplt->status = 0x00;
		radio_le_conn_cmplt->role = 0x01;
		if (1) {
			radio_le_conn_cmplt->peer_addr_type = pdu_adv->tx_addr;
			memcpy(&radio_le_conn_cmplt->peer_addr[0],
					&pdu_adv->payload.connect_ind.init_addr[0],
					6);
		}
		radio_le_conn_cmplt->interval =
			pdu_adv->payload.connect_ind.lldata.interval;
		radio_le_conn_cmplt->latency =
			pdu_adv->payload.connect_ind.lldata.latency;
		radio_le_conn_cmplt->timeout =
			pdu_adv->payload.connect_ind.lldata.timeout;
		radio_le_conn_cmplt->mca =
			pdu_adv->payload.connect_ind.lldata.sca;
		rx_fc_lock(conn->handle);
		packet_rx_enqueue();
		if (1) {
			struct radio_le_chan_sel_algo *le_chan_sel_algo;
			radio_pdu_node_rx = packet_rx_reserve_get(3);
			if (!(radio_pdu_node_rx)) { ; ; };
			radio_pdu_node_rx->hdr.handle = conn->handle;
			radio_pdu_node_rx->hdr.type =
				NODE_RX_TYPE_CHAN_SEL_ALGO;
			pdu_data = (struct pdu_data *)
				radio_pdu_node_rx->pdu_data;
			le_chan_sel_algo = (struct radio_le_chan_sel_algo *)
				&pdu_data->payload;
			if (pdu_adv->chan_sel) {
				u16_t aa_ls =
					((u16_t)conn->access_addr[1] << 8) |
					conn->access_addr[0];
				u16_t aa_ms =
					((u16_t)conn->access_addr[3] << 8) |
					conn->access_addr[2];
				conn->data_chan_sel = 1;
				conn->data_chan_id = aa_ms ^ aa_ls;
				le_chan_sel_algo->chan_sel_algo = 0x01;
			} else {
				le_chan_sel_algo->chan_sel_algo = 0x00;
			}
			packet_rx_enqueue();
		}
		conn->slave.sca = pdu_adv->payload.connect_ind.lldata.sca;
		conn->slave.window_widening_periodic_us =
			(((gc_lookup_ppm[_radio.sca] +
			   gc_lookup_ppm[conn->slave.sca]) *
			  conn_interval_us) + (1000000 - 1)) / 1000000;
		conn->slave.window_widening_max_us =
			(conn_interval_us >> 1) - 150;
		conn->slave.window_size_event_us =
			pdu_adv->payload.connect_ind.lldata.win_size * 1250;
		conn->slave.window_size_prepare_us = 0;
		rx_ready_delay = radio_rx_ready_delay_get(0);
		conn->hdr.ticks_slot =
			( ((u32_t)(((u64_t) (300 + rx_ready_delay + 328 + 150 + 328) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
			;
		conn->hdr.ticks_active_to_start = _radio.ticks_active_to_start;
		conn->hdr.ticks_xtal_to_start =
			( ((u32_t)(((u64_t) (1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
		conn->hdr.ticks_preempt_to_start =
			( ((u32_t)(((u64_t) (0) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
		ticks_slot_offset =
			(conn->hdr.ticks_active_to_start <
			 conn->hdr.ticks_xtal_to_start) ?
			conn->hdr.ticks_xtal_to_start :
			conn->hdr.ticks_active_to_start;
		conn_interval_us -=
			conn->slave.window_widening_periodic_us;
		conn_offset_us = radio_tmr_end_get();
		conn_offset_us +=
			((u64_t)pdu_adv->payload.connect_ind.lldata.win_offset +
			 1) * 1250;
		conn_offset_us -= radio_tx_chain_delay_get(0, 0);
		conn_offset_us -= rx_ready_delay;
		conn_offset_us -= 16 << 1;
		conn_offset_us -= 16;
		ticker_status = ticker_stop(0,
				0,
				5,
				ticker_stop_adv_assert,
				(void *)1142);
		ticker_stop_adv_assert(ticker_status, (void *)1143);
		if (_pdu_adv->type == PDU_ADV_TYPE_DIRECT_IND) {
			ticker_stop(0,
					0,
					3, 
					((void *)0)
					, 
					((void *)0)
				   );
		}
		ticker_status = ticker_start(0,
				0,
				7 + conn->handle,
				(_radio.ticks_anchor - ticks_slot_offset),
				( ((u32_t)(((u64_t) (conn_offset_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
				( ((u32_t)(((u64_t) (conn_interval_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
				( ( ((u64_t) (conn_interval_us) * 1000000000UL) - ((u64_t) ( ((u32_t)(((u64_t) (conn_interval_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ) * 30517578125UL) ) / 1000UL ), 0,
				(ticks_slot_offset + conn->hdr.ticks_slot),
				event_slave_prepare, conn, ticker_success_assert,
				(void *)1166);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		return 0;
	}
	return 1;
}
static u32_t isr_rx_scan_report(u8_t rssi_ready, u8_t rl_idx, 
		_Bool 
		dir_report)
{
	struct radio_pdu_node_rx *radio_pdu_node_rx;
	struct pdu_adv *pdu_adv_rx;
	radio_pdu_node_rx = packet_rx_reserve_get(3);
	if (radio_pdu_node_rx == 0) {
		return 1;
	}
	radio_pdu_node_rx->hdr.handle = 0xffff;
	if (0) {
	} else {
		radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_REPORT;
	}
	pdu_adv_rx = (struct pdu_adv *)radio_pdu_node_rx->pdu_data;
	((u8_t *)pdu_adv_rx)[
		__builtin_offsetof (
				struct pdu_adv
				, 
				payload
				) 
			+
			pdu_adv_rx->len] =
			(rssi_ready) ? (radio_rssi_get() & 0x7f) : 0x7f;
	packet_rx_enqueue();
	return 0;
}
static inline 
	_Bool 
isr_rx_scan_check(u8_t irkmatch_ok, u8_t devmatch_ok,
		u8_t rl_idx)
{
	return ((_radio.scanner.filter_policy & 0x01) == 0) ||
		devmatch_ok;
}
static inline 
	_Bool 
isr_scan_rsp_adva_matches(struct pdu_adv *srsp)
{
	struct pdu_adv *sreq = (struct pdu_adv *)radio_pkt_scratch_get();
	return ((sreq->rx_addr == srsp->tx_addr) &&
			(memcmp(&sreq->payload.scan_req.adv_addr[0],
				&srsp->payload.scan_rsp.addr[0], 6) == 0));
}
static inline 
	_Bool 
isr_scan_init_adva_check(struct pdu_adv *pdu,
		u8_t rl_idx)
{
	return ((_radio.scanner.adv_addr_type == pdu->tx_addr) &&
			(memcmp(&_radio.scanner.adv_addr[0],
				&pdu->payload.adv_ind.addr[0], 6) == 0));
}
static inline 
_Bool 
isr_scan_tgta_rpa_check(struct pdu_adv *pdu,
		_Bool 
		*dir_report)
{
	if (((_radio.scanner.filter_policy & 0x02) != 0) &&
			(pdu->rx_addr != 0) &&
			((pdu->payload.direct_ind.tgt_addr[5] & 0xc0) == 0x40)) {
		if (dir_report) {
			*dir_report = 
				1
				;
		}
		return 
			1
			;
	}
	return 
		0
		;
}
static inline 
_Bool 
isr_scan_tgta_check(
		_Bool 
		init, struct pdu_adv *pdu,
		u8_t rl_idx, 
		_Bool 
		*dir_report)
{
	return (((_radio.scanner.init_addr_type == pdu->rx_addr) &&
				(memcmp(&_radio.scanner.init_addr[0],
					&pdu->payload.direct_ind.tgt_addr[0],
					6) == 0))) ||
		isr_scan_tgta_rpa_check(pdu, dir_report);
}
static inline 
	_Bool 
isr_scan_init_check(struct pdu_adv *pdu, u8_t rl_idx)
{
	return ((((_radio.scanner.filter_policy & 0x01) != 0) ||
				isr_scan_init_adva_check(pdu, rl_idx)) &&
			((pdu->type == PDU_ADV_TYPE_ADV_IND) ||
			 ((pdu->type == PDU_ADV_TYPE_DIRECT_IND) &&
			  (
			   isr_scan_tgta_check(
				   1
				   , pdu, rl_idx, 
				   ((void *)0)
				   )))));
}
static inline u32_t isr_rx_scan(u8_t devmatch_ok, u8_t devmatch_id,
		u8_t irkmatch_ok, u8_t irkmatch_id, u8_t rl_idx,
		u8_t rssi_ready)
{
	struct pdu_adv *pdu_adv_rx;
	_Bool 
		dir_report = 
		0
		;
	pdu_adv_rx = (struct pdu_adv *)
		_radio.packet_rx[_radio.packet_rx_last]->pdu_data;
	if ((_radio.scanner.conn) && ((_radio.fc_ena == 0) ||
				(_radio.fc_req == _radio.fc_ack)) &&
			isr_scan_init_check(pdu_adv_rx, rl_idx) &&
			((radio_tmr_end_get() + 502 + (16 << 1)) <
			 (((u32_t)(((u64_t) (_radio.scanner.hdr.ticks_slot) * 30517578125UL) / 1000000000UL)) -
			  300))) {
		struct radio_le_conn_cmplt *radio_le_conn_cmplt;
		struct radio_pdu_node_rx *radio_pdu_node_rx;
		struct pdu_adv *pdu_adv_tx;
		struct pdu_data *pdu_data;
		struct connection *conn;
		u32_t ticks_slot_offset;
		u32_t conn_interval_us;
		u32_t conn_offset_us;
		u32_t ticker_status;
		u32_t conn_space_us;
		if (1) {
			radio_pdu_node_rx = packet_rx_reserve_get(4);
		} else {
			radio_pdu_node_rx = packet_rx_reserve_get(3);
		}
		if (radio_pdu_node_rx == 0) {
			return 1;
		}
		_radio.state = STATE_STOP;
		conn = _radio.scanner.conn;
		_radio.scanner.conn = 
			((void *)0)
			;
		pdu_adv_tx = (struct pdu_adv *)radio_pkt_scratch_get();
		pdu_adv_tx->type = PDU_ADV_TYPE_CONNECT_IND;
		if (1) {
			pdu_adv_tx->chan_sel = 1;
		} else {
			pdu_adv_tx->chan_sel = 0;
		}
		pdu_adv_tx->rx_addr = pdu_adv_rx->tx_addr;
		pdu_adv_tx->len = sizeof(struct pdu_adv_payload_connect_ind);
		if (1) {
			pdu_adv_tx->tx_addr = _radio.scanner.init_addr_type;
			memcpy(&pdu_adv_tx->payload.connect_ind.init_addr[0],
					&_radio.scanner.init_addr[0], 6);
		}
		memcpy(&pdu_adv_tx->payload.connect_ind.adv_addr[0],
				&pdu_adv_rx->payload.adv_ind.addr[0], 6);
		memcpy(&pdu_adv_tx->payload.connect_ind.lldata.
				access_addr[0], &conn->access_addr[0], 4);
		memcpy(&pdu_adv_tx->payload.connect_ind.lldata.crc_init[0],
				&conn->crc_init[0], 3);
		pdu_adv_tx->payload.connect_ind.lldata.win_size = 1;
		conn_interval_us =
			(u32_t)_radio.scanner.conn_interval * 1250;
		conn_offset_us = radio_tmr_end_get() + 502 + 1250;
		if (!_radio.remainder_anchor ||
				(_radio.remainder_anchor & (1UL << (31)))) {
			conn_offset_us -= ((u32_t)(((u64_t) (1) * 30517578125UL) / 1000000000UL));
		}
		if (_radio.scanner.win_offset_us == 0) {
			conn_space_us = conn_offset_us;
			pdu_adv_tx->payload.connect_ind.lldata.win_offset = 0;
		} else {
			conn_space_us = _radio.scanner.win_offset_us;
			while ((conn_space_us & ((u32_t)1 << 31)) ||
					(conn_space_us < conn_offset_us)) {
				conn_space_us += conn_interval_us;
			}
			pdu_adv_tx->payload.connect_ind.lldata.win_offset =
				(conn_space_us - conn_offset_us) / 1250;
			pdu_adv_tx->payload.connect_ind.lldata.win_size++;
		}
		conn_space_us -= radio_tx_ready_delay_get(0, 0);
		conn_space_us -= radio_tx_chain_delay_get(0, 0);
		conn_space_us += ((u32_t)(((u64_t) (1) * 30517578125UL) / 1000000000UL));
		pdu_adv_tx->payload.connect_ind.lldata.interval =
			_radio.scanner.conn_interval;
		pdu_adv_tx->payload.connect_ind.lldata.latency =
			_radio.scanner.conn_latency;
		pdu_adv_tx->payload.connect_ind.lldata.timeout =
			_radio.scanner.conn_timeout;
		memcpy(&pdu_adv_tx->payload.connect_ind.lldata.chan_map[0],
				&conn->data_chan_map[0],
				sizeof(pdu_adv_tx->payload.connect_ind.lldata.chan_map));
		pdu_adv_tx->payload.connect_ind.lldata.hop =
			conn->data_chan_hop;
		pdu_adv_tx->payload.connect_ind.lldata.sca = _radio.sca;
		radio_switch_complete_and_disable();
		radio_pkt_tx_set(pdu_adv_tx);
		if (!(!radio_is_ready())) { ; ; };
		conn->handle = mem_index_get(conn, _radio.conn_pool,
				(((u32_t)(sizeof(struct connection))+3) & (~((u32_t)3))));
		radio_pdu_node_rx->hdr.handle = conn->handle;
		radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_CONNECTION;
		pdu_data = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
		radio_le_conn_cmplt =
			(struct radio_le_conn_cmplt *)&pdu_data->payload;
		radio_le_conn_cmplt->status = 0x00;
		radio_le_conn_cmplt->role = 0x00;
		if (1) {
			radio_le_conn_cmplt->peer_addr_type =
				pdu_adv_tx->rx_addr;
			memcpy(&radio_le_conn_cmplt->peer_addr[0],
					&pdu_adv_tx->payload.connect_ind.adv_addr[0],
					6);
		}
		radio_le_conn_cmplt->interval = _radio.scanner.conn_interval;
		radio_le_conn_cmplt->latency = _radio.scanner. conn_latency;
		radio_le_conn_cmplt->timeout = _radio.scanner.conn_timeout;
		radio_le_conn_cmplt->mca =
			pdu_adv_tx->payload.connect_ind.lldata.sca;
		rx_fc_lock(conn->handle);
		packet_rx_enqueue();
		if (1) {
			struct radio_le_chan_sel_algo *le_chan_sel_algo;
			radio_pdu_node_rx = packet_rx_reserve_get(3);
			if (!(radio_pdu_node_rx)) { ; ; };
			radio_pdu_node_rx->hdr.handle = conn->handle;
			radio_pdu_node_rx->hdr.type =
				NODE_RX_TYPE_CHAN_SEL_ALGO;
			pdu_data = (struct pdu_data *)
				radio_pdu_node_rx->pdu_data;
			le_chan_sel_algo = (struct radio_le_chan_sel_algo *)
				&pdu_data->payload;
			if (pdu_adv_rx->chan_sel) {
				u16_t aa_ls =
					((u16_t)conn->access_addr[1] << 8) |
					conn->access_addr[0];
				u16_t aa_ms =
					((u16_t)conn->access_addr[3] << 8) |
					conn->access_addr[2];
				conn->data_chan_sel = 1;
				conn->data_chan_id = aa_ms ^ aa_ls;
				le_chan_sel_algo->chan_sel_algo = 0x01;
			} else {
				le_chan_sel_algo->chan_sel_algo = 0x00;
			}
			packet_rx_enqueue();
		}
		conn->hdr.ticks_slot = _radio.scanner.ticks_conn_slot;
		conn->hdr.ticks_active_to_start = _radio.ticks_active_to_start;
		conn->hdr.ticks_xtal_to_start =
			( ((u32_t)(((u64_t) (1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
		conn->hdr.ticks_preempt_to_start =
			( ((u32_t)(((u64_t) (0) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
		ticks_slot_offset =
			(conn->hdr. ticks_active_to_start <
			 conn->hdr.ticks_xtal_to_start) ?
			conn->hdr.ticks_xtal_to_start :
			conn->hdr.ticks_active_to_start;
		ticker_status = ticker_stop(0,
				0,
				6,
				ticker_stop_scan_assert,
				(void *)1588);
		ticker_stop_scan_assert(ticker_status, (void *)1589);
		ticker_stop(0,
				0,
				4, 
				((void *)0)
				, 
				((void *)0)
			   );
		ticker_status =
			ticker_start(0,
					0,
					7 +
					conn->handle,
					(_radio.ticks_anchor - ticks_slot_offset),
					( ((u32_t)(((u64_t) (conn_space_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
					( ((u32_t)(((u64_t) (conn_interval_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
					( ( ((u64_t) (conn_interval_us) * 1000000000UL) - ((u64_t) ( ((u32_t)(((u64_t) (conn_interval_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ) * 30517578125UL) ) / 1000UL ),
					0,
					(ticks_slot_offset + conn->hdr.ticks_slot),
					event_master_prepare, conn,
					ticker_success_assert, (void *)1612);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		return 0;
	}
	else if (((pdu_adv_rx->type == PDU_ADV_TYPE_ADV_IND) ||
				(pdu_adv_rx->type == PDU_ADV_TYPE_SCAN_IND)) &&
			(_radio.scanner.type != 0) &&
			(_radio.scanner.conn == 0)) {
		struct pdu_adv *pdu_adv_tx;
		u32_t err;
		err = isr_rx_scan_report(rssi_ready,
				irkmatch_ok ? rl_idx :
				0xFF,
				0
				);
		if (err) {
			return err;
		}
		pdu_adv_tx = (struct pdu_adv *)radio_pkt_scratch_get();
		pdu_adv_tx->type = PDU_ADV_TYPE_SCAN_REQ;
		pdu_adv_tx->rx_addr = pdu_adv_rx->tx_addr;
		pdu_adv_tx->len = sizeof(struct pdu_adv_payload_scan_req);
		if (1) {
			pdu_adv_tx->tx_addr = _radio.scanner.init_addr_type;
			memcpy(&pdu_adv_tx->payload.scan_req.scan_addr[0],
					&_radio.scanner.init_addr[0], 6);
		}
		memcpy(&pdu_adv_tx->payload.scan_req.adv_addr[0],
				&pdu_adv_rx->payload.adv_ind.addr[0], 6);
		_radio.scanner.state = 1;
		_radio.state = STATE_TX;
		radio_tmr_tifs_set(150);
		radio_switch_complete_and_rx(0);
		radio_pkt_tx_set(pdu_adv_tx);
		radio_tmr_end_capture();
		if (!(!radio_is_ready())) { ; ; };
		return 0;
	}
	else if (((pdu_adv_rx->type == PDU_ADV_TYPE_ADV_IND) ||
				((pdu_adv_rx->type == PDU_ADV_TYPE_DIRECT_IND) &&
				 (
				  isr_scan_tgta_check(
					  0
					  , pdu_adv_rx, rl_idx,
					  &dir_report))) ||
				(pdu_adv_rx->type == PDU_ADV_TYPE_NONCONN_IND) ||
				(pdu_adv_rx->type == PDU_ADV_TYPE_SCAN_IND) ||
				((pdu_adv_rx->type == PDU_ADV_TYPE_SCAN_RSP) &&
				 (_radio.scanner.state != 0) &&
				 isr_scan_rsp_adva_matches(pdu_adv_rx))) &&
			(pdu_adv_rx->len != 0) && (!_radio.scanner.conn)) {
		u32_t err;
		err = isr_rx_scan_report(rssi_ready,
				irkmatch_ok ? rl_idx :
				0xFF,
				dir_report);
		if (err) {
			return err;
		}
	}
	else {
		return 1;
	}
	return 1;
}
static inline void isr_rx_conn_phy_tx_time_set(void)
{
	u8_t phy_tx_time[8] = {(1UL << (0)), (1UL << (0)), (1UL << (1)), (1UL << (0)),
		(1UL << (2)), (1UL << (2)), (1UL << (2)), (1UL << (2))};
	struct connection *conn = _radio.conn_curr;
	u8_t phys = conn->llcp_phy.tx | conn->phy_tx;
	conn->phy_tx_time = phy_tx_time[phys];
}
static inline u8_t isr_rx_conn_pkt_ack(struct pdu_data *pdu_data_tx,
		struct radio_pdu_node_tx **node_tx)
{
	u8_t terminate = 0;
	switch (pdu_data_tx->payload.llctrl.opcode) {
		case PDU_DATA_LLCTRL_TYPE_TERMINATE_IND:
			_radio.state = STATE_CLOSE;
			radio_disable();
			if (!(!radio_is_ready())) { ; ; };
			terminate_ind_rx_enqueue(_radio.conn_curr,
					(pdu_data_tx->payload.llctrl.ctrldata.terminate_ind.
					 error_code == 0x13) ? 0x16 :
					pdu_data_tx->payload.llctrl.ctrldata.terminate_ind.
					error_code);
			terminate = 1;
			break;
		case PDU_DATA_LLCTRL_TYPE_ENC_REQ:
			memcpy(&_radio.conn_curr->llcp.encryption.skd[0],
					&pdu_data_tx->payload.llctrl.ctrldata.enc_req.skdm[0],
					8);
			memcpy(&_radio.conn_curr->ccm_rx.iv[0],
					&pdu_data_tx->payload.llctrl.ctrldata.enc_req.ivm[0],
					4);
			_radio.conn_curr->pause_tx = 1;
			_radio.conn_curr->procedure_expire =
				_radio.conn_curr->procedure_reload;
			break;
		case PDU_DATA_LLCTRL_TYPE_ENC_RSP:
			_radio.conn_curr->pause_tx = 1;
			break;
		case PDU_DATA_LLCTRL_TYPE_START_ENC_REQ:
			break;
		case PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_REQ:
			_radio.conn_curr->pause_tx = 1;
			_radio.conn_curr->refresh = 1;
			_radio.conn_curr->procedure_expire =
				_radio.conn_curr->procedure_reload;
			break;
		case PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_RSP:
			if (_radio.role == ROLE_MASTER) {
				enc_req_reused_send(_radio.conn_curr, *node_tx);
				*node_tx = 
					((void *)0)
					;
			} else {
				_radio.conn_curr->pause_tx = 1;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_REJECT_IND:
			_radio.conn_curr->pause_rx = 0;
			_radio.conn_curr->pause_tx = 0;
			_radio.conn_curr->procedure_expire = 0;
			break;
		case PDU_DATA_LLCTRL_TYPE_PHY_REQ:
			_radio.conn_curr->llcp_phy.state = 2;
		case PDU_DATA_LLCTRL_TYPE_PHY_RSP:
			if (_radio.role == ROLE_SLAVE) {
				isr_rx_conn_phy_tx_time_set();
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_PHY_UPD_IND:
			_radio.conn_curr->phy_tx_time =
				_radio.conn_curr->llcp.phy_upd_ind.tx;
			break;
		default:
			break;
	}
	return terminate;
}
	static inline struct radio_pdu_node_tx *
isr_rx_conn_pkt_release(struct radio_pdu_node_tx *node_tx)
{
	struct connection *conn = _radio.conn_curr;
	conn->packet_tx_head_len = 0;
	conn->packet_tx_head_offset = 0;
	if (conn->pkt_tx_head == conn->pkt_tx_ctrl) {
		if (node_tx) {
			conn->pkt_tx_head = conn->pkt_tx_head->next;
			if (conn->pkt_tx_ctrl == conn->pkt_tx_ctrl_last) {
				conn->pkt_tx_ctrl = 
					((void *)0)
					;
				conn->pkt_tx_ctrl_last = 
					((void *)0)
					;
			} else {
				conn->pkt_tx_ctrl = conn->pkt_tx_head;
			}
			mem_release(node_tx, &_radio.pkt_tx_ctrl_free);
		}
	} else {
		if (conn->pkt_tx_head == conn->pkt_tx_data) {
			conn->pkt_tx_data = conn->pkt_tx_data->next;
		}
		conn->pkt_tx_head = conn->pkt_tx_head->next;
		return node_tx;
	}
	return 
		((void *)0)
		;
}
static inline u32_t feat_get(u8_t *features)
{
	u32_t feat;
	feat = ~0x1CF2F | features[0] |
		(features[1] << 8) | (features[2] << 16);
	feat &= 0x1FFFF;
	return feat;
}
	static inline void
isr_rx_conn_pkt_ctrl_rej_conn_upd(struct radio_pdu_node_rx *radio_pdu_node_rx,
		u8_t *rx_enqueue)
{
	struct pdu_data_llctrl_reject_ext_ind *rej_ext_ind;
	struct radio_le_conn_update_cmplt *cp;
	struct pdu_data *pdu_data_rx;
	struct connection *conn;
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	rej_ext_ind = (struct pdu_data_llctrl_reject_ext_ind *)
		&pdu_data_rx->payload.llctrl.ctrldata.reject_ext_ind;
	if (rej_ext_ind->reject_opcode != PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ) {
		return;
	}
	conn = _radio.conn_curr;
	if (!conn->role && (rej_ext_ind->error_code == 0x1a)) {
		if (!(conn->llcp_req == conn->llcp_ack)) { ; ; };
		conn->llcp_conn_param.state = LLCP_CPR_STATE_UPD;
		conn->llcp.conn_upd.win_size = 1;
		conn->llcp.conn_upd.win_offset_us = 0;
		conn->llcp.conn_upd.interval = conn->llcp_conn_param.interval;
		conn->llcp.conn_upd.latency = conn->llcp_conn_param.latency;
		conn->llcp.conn_upd.timeout = conn->llcp_conn_param.timeout;
		conn->llcp.conn_upd.state = LLCP_CUI_STATE_USE;
		conn->llcp.conn_upd.is_internal = !conn->llcp_conn_param.cmd;
		conn->llcp_type = LLCP_CONN_UPD;
		conn->llcp_ack--;
		return;
	}
	else if (rej_ext_ind->error_code != 0x23) {
		if (!(_radio.conn_upd == conn)) { ; ; };
		_radio.conn_upd = 
			((void *)0)
			;
		conn->llcp_conn_param.ack =
			conn->llcp_conn_param.req;
		conn->procedure_expire = 0;
		if (conn->role) {
			conn->slave.ticks_to_offset =
				conn->llcp_conn_param.ticks_to_offset_next;
		}
	}
	if (!conn->llcp_conn_param.cmd) {
		return;
	}
	radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_CONN_UPDATE;
	pdu_data_rx = (void *)radio_pdu_node_rx->pdu_data;
	cp = (void *)&pdu_data_rx->payload;
	cp->status = rej_ext_ind->error_code;
	cp->interval = conn->conn_interval;
	cp->latency = conn->latency;
	cp->timeout = conn->supervision_reload *
		conn->conn_interval * 125 / 1000;
	*rx_enqueue = 1;
}
	static inline void
isr_rx_conn_pkt_ctrl_rej_phy_upd(struct radio_pdu_node_rx *radio_pdu_node_rx,
		u8_t *rx_enqueue)
{
	struct pdu_data_llctrl_reject_ext_ind *rej_ext_ind;
	struct pdu_data *pdu_data_rx;
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	rej_ext_ind = (struct pdu_data_llctrl_reject_ext_ind *)
		&pdu_data_rx->payload.llctrl.ctrldata.reject_ext_ind;
	if (rej_ext_ind->reject_opcode == PDU_DATA_LLCTRL_TYPE_PHY_REQ) {
		struct radio_le_phy_upd_cmplt *p;
		if (rej_ext_ind->error_code != 0x23) {
			_radio.conn_curr->llcp_phy.ack =
				_radio.conn_curr->llcp_phy.req;
			_radio.conn_curr->phy_tx_time =
				_radio.conn_curr->phy_tx;
			_radio.conn_curr->procedure_expire = 0;
		}
		if (!_radio.conn_curr->llcp_phy.cmd) {
			return;
		}
		radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_PHY_UPDATE;
		p = (void *) &pdu_data_rx->payload;
		p->status = rej_ext_ind->error_code;
		p->tx = _radio.conn_curr->phy_tx;
		p->rx = _radio.conn_curr->phy_rx;
		*rx_enqueue = 1;
	}
}
	static inline void
isr_rx_conn_pkt_ctrl_rej(struct radio_pdu_node_rx *radio_pdu_node_rx,
		u8_t *rx_enqueue)
{
	if (0) {
	} else if (_radio.conn_curr->llcp_phy.ack !=
			_radio.conn_curr->llcp_phy.req) {
		isr_rx_conn_pkt_ctrl_rej_phy_upd(radio_pdu_node_rx,
				rx_enqueue);
	} else if (_radio.conn_curr->llcp_conn_param.ack !=
			_radio.conn_curr->llcp_conn_param.req) {
		isr_rx_conn_pkt_ctrl_rej_conn_upd(radio_pdu_node_rx,
				rx_enqueue);
	} else {
		struct pdu_data_llctrl_reject_ext_ind *rej_ext_ind;
		struct pdu_data *pdu_rx;
		pdu_rx = (void *)radio_pdu_node_rx->pdu_data;
		rej_ext_ind = (void *)
			&pdu_rx->payload.llctrl.ctrldata.reject_ext_ind;
		switch (rej_ext_ind->reject_opcode) {
			case PDU_DATA_LLCTRL_TYPE_ENC_REQ:
				_radio.conn_curr->pause_rx = 0;
				_radio.conn_curr->pause_tx = 0;
				_radio.conn_curr->procedure_expire = 0;
				pdu_rx->payload.llctrl.opcode =
					PDU_DATA_LLCTRL_TYPE_REJECT_IND;
				pdu_rx->payload.llctrl.ctrldata.reject_ind.error_code =
					rej_ext_ind->error_code;
				*rx_enqueue = 1;
				break;
			default:
				break;
		}
	}
}
	static inline u8_t
isr_rx_conn_pkt_ctrl(struct radio_pdu_node_rx *radio_pdu_node_rx,
		u8_t *rx_enqueue)
{
	struct pdu_data *pdu_data_rx;
	u8_t nack = 0;
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	if (_radio.conn_curr->role) {
		switch (pdu_data_rx->payload.llctrl.opcode) {
			case PDU_DATA_LLCTRL_TYPE_ENC_RSP:
			case PDU_DATA_LLCTRL_TYPE_START_ENC_REQ:
			case PDU_DATA_LLCTRL_TYPE_SLAVE_FEATURE_REQ:
			case PDU_DATA_LLCTRL_TYPE_CONN_PARAM_RSP:
			case PDU_DATA_LLCTRL_TYPE_PHY_RSP:
			case PDU_DATA_LLCTRL_TYPE_MIN_USED_CHAN_IND:
				nack = unknown_rsp_send(_radio.conn_curr,
						pdu_data_rx->payload.llctrl.opcode);
				return nack;
			default:
				break;
		}
	} else {
		switch (pdu_data_rx->payload.llctrl.opcode) {
			case PDU_DATA_LLCTRL_TYPE_CONN_UPDATE_IND:
			case PDU_DATA_LLCTRL_TYPE_CHAN_MAP_IND:
			case PDU_DATA_LLCTRL_TYPE_ENC_REQ:
			case PDU_DATA_LLCTRL_TYPE_FEATURE_REQ:
			case PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_REQ:
			case PDU_DATA_LLCTRL_TYPE_PHY_UPD_IND:
				nack = unknown_rsp_send(_radio.conn_curr,
						pdu_data_rx->payload.llctrl.opcode);
				return nack;
			default:
				break;
		}
	}
	switch (pdu_data_rx->payload.llctrl.opcode) {
		case PDU_DATA_LLCTRL_TYPE_CONN_UPDATE_IND:
			if (conn_update(_radio.conn_curr, pdu_data_rx) == 0) {
				_radio.conn_curr->procedure_expire = 0;
			} else {
				_radio.conn_curr->llcp_terminate.reason_peer = 0x28;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_CHAN_MAP_IND:
			if (chan_map_update(_radio.conn_curr, pdu_data_rx)) {
				_radio.conn_curr->llcp_terminate.reason_peer = 0x28;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_TERMINATE_IND:
			_radio.conn_curr->llcp_terminate.reason_peer =
				pdu_data_rx->payload.llctrl.ctrldata.terminate_ind.error_code;
			break;
		case PDU_DATA_LLCTRL_TYPE_ENC_REQ:
			memcpy(&_radio.conn_curr->llcp.encryption.skd[0],
					&pdu_data_rx->payload.llctrl.ctrldata.enc_req.skdm[0],
					8);
			memcpy(&_radio.conn_curr->ccm_rx.iv[0],
					&pdu_data_rx->payload.llctrl.ctrldata.enc_req.ivm[0], 4);
			_radio.conn_curr->pause_rx = 1;
			_radio.conn_curr->procedure_expire =
				_radio.conn_curr->procedure_reload;
			*rx_enqueue = 1;
			break;
		case PDU_DATA_LLCTRL_TYPE_ENC_RSP:
			memcpy(&_radio.conn_curr->llcp.encryption.skd[8],
					&pdu_data_rx->payload.llctrl.ctrldata.enc_rsp.skds[0],
					8);
			memcpy(&_radio.conn_curr->ccm_rx.iv[4],
					&pdu_data_rx->payload.llctrl.ctrldata.enc_rsp.ivs[0],
					4);
			_radio.conn_curr->pause_rx = 1;
			break;
		case PDU_DATA_LLCTRL_TYPE_START_ENC_REQ:
			if (!((_radio.conn_curr->llcp_req == _radio.conn_curr->llcp_ack) || (_radio.conn_curr->llcp_type == LLCP_ENCRYPTION))) { ; ; }
			;
			_radio.conn_curr->llcp.encryption.initiate = 0;
			_radio.conn_curr->llcp_type = LLCP_ENCRYPTION;
			_radio.conn_curr->llcp_ack--;
			break;
		case PDU_DATA_LLCTRL_TYPE_START_ENC_RSP:
			if (_radio.role == ROLE_SLAVE) {
				if (!((_radio.conn_curr->llcp_req == _radio.conn_curr->llcp_ack) || (_radio.conn_curr->llcp_type == LLCP_ENCRYPTION))) { ; ; }
				;
				_radio.conn_curr->llcp.encryption.initiate = 0;
				_radio.conn_curr->llcp_type = LLCP_ENCRYPTION;
				_radio.conn_curr->llcp_ack--;
			} else {
				_radio.conn_curr->pause_rx = 0;
				_radio.conn_curr->pause_tx = 0;
			}
			if (_radio.conn_curr->refresh) {
				_radio.conn_curr->refresh = 0;
				radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_ENC_REFRESH;
			}
			*rx_enqueue = 1;
			_radio.conn_curr->procedure_expire = 0;
			break;
		case PDU_DATA_LLCTRL_TYPE_FEATURE_REQ:
		case PDU_DATA_LLCTRL_TYPE_SLAVE_FEATURE_REQ:
			{
				nack = feature_rsp_send(_radio.conn_curr, pdu_data_rx);
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_FEATURE_RSP:
			{
				struct pdu_data_llctrl_feature_rsp *rsp;
				rsp = &pdu_data_rx->payload.llctrl.ctrldata.feature_rsp;
				_radio.conn_curr->llcp_features &= feat_get(&rsp->features[0]);
				_radio.conn_curr->common.fex_valid = 1;
				*rx_enqueue = 1;
				_radio.conn_curr->procedure_expire = 0;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_REQ:
			nack = pause_enc_rsp_send(_radio.conn_curr, 1);
			break;
		case PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_RSP:
			nack = pause_enc_rsp_send(_radio.conn_curr, 0);
			break;
		case PDU_DATA_LLCTRL_TYPE_VERSION_IND:
			nack = version_ind_send(_radio.conn_curr, pdu_data_rx,
					rx_enqueue);
			break;
		case PDU_DATA_LLCTRL_TYPE_REJECT_IND:
			_radio.conn_curr->pause_rx = 0;
			_radio.conn_curr->pause_tx = 0;
			_radio.conn_curr->procedure_expire = 0;
			*rx_enqueue = 1;
			break;
		case PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ:
			if (_radio.conn_upd && (_radio.conn_upd != _radio.conn_curr)) {
				nack = reject_ext_ind_send(_radio.conn_curr,
						PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ,
						0x20);
				break;
			}
			if (!_radio.conn_curr->role) {
				struct connection *conn = _radio.conn_curr;
				if ((conn->llcp_conn_param.req !=
							conn->llcp_conn_param.ack) &&
						((conn->llcp_conn_param.state ==
						  LLCP_CPR_STATE_REQ) ||
						 (conn->llcp_conn_param.state ==
						  LLCP_CPR_STATE_RSP_WAIT) ||
						 (conn->llcp_conn_param.state ==
						  LLCP_CPR_STATE_UPD))) {
					nack = reject_ext_ind_send(_radio.conn_curr,
							PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ,
							0x23);
				} else if (((conn->llcp_req != conn->llcp_ack) &&
							(conn->llcp_type != LLCP_ENCRYPTION)) ||
						(conn->llcp_phy.req != conn->llcp_phy.ack)) {
					nack = reject_ext_ind_send(_radio.conn_curr,
							PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ,
							0x2a);
				} else {
					struct pdu_data_llctrl_conn_param_req *cpr = (void *)
						&pdu_data_rx->payload.llctrl.ctrldata.conn_param_req;
					if ((cpr->interval_min < 6) ||
							(cpr->interval_max > 3200) ||
							(cpr->interval_min > cpr->interval_max) ||
							(cpr->latency > 499) ||
							(cpr->timeout < 10) ||
							(cpr->timeout > 3200) ||
							((cpr->timeout * 4) <=
							 ((cpr->latency + 1) *
							  cpr->interval_max)) ||
							(cpr->preferred_periodicity >
							 cpr->interval_max)) {
						nack = reject_ext_ind_send(conn,
								PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ,
								0x1e);
						break;
					}
					conn->llcp_conn_param.interval = cpr->interval_min;
					conn->llcp_conn_param.latency = cpr->latency;
					conn->llcp_conn_param.timeout = cpr->timeout;
					conn->llcp_conn_param.preferred_periodicity =
						cpr->preferred_periodicity;
					conn->llcp_conn_param.reference_conn_event_count =
						cpr->reference_conn_event_count;
					conn->llcp_conn_param.offset0 = cpr->offset0;
					conn->llcp_conn_param.offset1 = cpr->offset1;
					conn->llcp_conn_param.offset2 = cpr->offset2;
					conn->llcp_conn_param.offset3 = cpr->offset3;
					conn->llcp_conn_param.offset4 = cpr->offset4;
					conn->llcp_conn_param.offset5 = cpr->offset5;
					if ((conn->llcp_conn_param.interval !=
								conn->conn_interval) ||
							(conn->llcp_conn_param.latency !=
							 conn->latency) ||
							(((u16_t)(((conn->llcp_conn_param.timeout * 10000) + (conn->conn_interval * 1250) - 1) / (conn->conn_interval * 1250)))
							 !=
							 conn->supervision_reload)) {
						if (conn->pause_tx) {
							conn->llcp_conn_param.state =
								LLCP_CPR_STATE_APP_REQ;
						} else {
							*rx_enqueue = 1;
							conn->llcp_conn_param.state =
								LLCP_CPR_STATE_APP_WAIT;
						}
					} else {
						conn->llcp_conn_param.status = 0;
						conn->llcp_conn_param.cmd = 0;
						conn->llcp_conn_param.state =
							LLCP_CPR_STATE_RSP;
					}
					conn->llcp_conn_param.ack--;
					if (_radio.conn_upd == 0) {
						_radio.conn_upd = conn;
					}
				}
			} else if ((_radio.conn_curr->llcp_conn_param.req ==
						_radio.conn_curr->llcp_conn_param.ack) ||
					(_radio.conn_curr->llcp_conn_param.state ==
					 LLCP_CPR_STATE_REQ) ||
					(_radio.conn_curr->llcp_conn_param.state ==
					 LLCP_CPR_STATE_RSP_WAIT)) {
				struct connection *conn = _radio.conn_curr;
				struct pdu_data_llctrl_conn_param_req *cpr = (void *)
					&pdu_data_rx->payload.llctrl.ctrldata.conn_param_req;
				if ((cpr->interval_min < 6) ||
						(cpr->interval_max > 3200) ||
						(cpr->interval_min > cpr->interval_max) ||
						(cpr->latency > 499) ||
						(cpr->timeout < 10) || (cpr->timeout > 3200) ||
						((cpr->timeout * 4) <= ((cpr->latency + 1) *
							cpr->interval_max)) ||
						(cpr->preferred_periodicity > cpr->interval_max)) {
					nack = reject_ext_ind_send(conn,
							PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ,
							0x1e);
					break;
				}
				conn->llcp_conn_param.interval = cpr->interval_min;
				conn->llcp_conn_param.latency = cpr->latency;
				conn->llcp_conn_param.timeout = cpr->timeout;
				conn->llcp_conn_param.preferred_periodicity =
					cpr->preferred_periodicity;
				conn->llcp_conn_param.reference_conn_event_count =
					cpr->reference_conn_event_count;
				conn->llcp_conn_param.offset0 = cpr->offset0;
				conn->llcp_conn_param.offset1 = cpr->offset1;
				conn->llcp_conn_param.offset2 = cpr->offset2;
				conn->llcp_conn_param.offset3 = cpr->offset3;
				conn->llcp_conn_param.offset4 = cpr->offset4;
				conn->llcp_conn_param.offset5 = cpr->offset5;
				if ((conn->llcp_conn_param.interval !=
							conn->conn_interval) ||
						(conn->llcp_conn_param.latency != conn->latency) ||
						(((u16_t)(((conn->llcp_conn_param.timeout * 10000) + (conn->conn_interval * 1250) - 1) / (conn->conn_interval * 1250)))
						 !=
						 conn->supervision_reload)) {
					*rx_enqueue = 1;
					conn->llcp_conn_param.state =
						LLCP_CPR_STATE_APP_WAIT;
				} else {
					conn->llcp_conn_param.status = 0;
					conn->llcp_conn_param.cmd = 0;
					conn->llcp_conn_param.state =
						LLCP_CPR_STATE_RSP;
				}
				conn->llcp_conn_param.ack--;
				if (_radio.conn_upd == 0) {
					_radio.conn_upd = conn;
				}
			} else {
				if (!(0)) { ; ; };
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_CONN_PARAM_RSP:
			if (!_radio.conn_curr->role &&
					(_radio.conn_curr->llcp_conn_param.req !=
					 _radio.conn_curr->llcp_conn_param.ack) &&
					(_radio.conn_curr->llcp_conn_param.state ==
					 LLCP_CPR_STATE_RSP_WAIT)) {
				struct connection *conn = _radio.conn_curr;
				struct pdu_data_llctrl_conn_param_req *cpr = (void *)
					&pdu_data_rx->payload.llctrl.ctrldata.conn_param_req;
				if ((cpr->interval_min < 6) ||
						(cpr->interval_max > 3200) ||
						(cpr->interval_min > cpr->interval_max) ||
						(cpr->latency > 499) ||
						(cpr->timeout < 10) || (cpr->timeout > 3200) ||
						((cpr->timeout * 4) <= ((cpr->latency + 1) *
							cpr->interval_max)) ||
						(cpr->preferred_periodicity > cpr->interval_max)) {
					nack = reject_ext_ind_send(conn,
							PDU_DATA_LLCTRL_TYPE_CONN_PARAM_RSP,
							0x1e);
					break;
				}
				_radio.conn_curr->procedure_expire = 0;
				conn->llcp_conn_param.interval = cpr->interval_min;
				conn->llcp_conn_param.latency = cpr->latency;
				conn->llcp_conn_param.timeout = cpr->timeout;
				conn->llcp_conn_param.preferred_periodicity =
					cpr->preferred_periodicity;
				conn->llcp_conn_param.reference_conn_event_count =
					cpr->reference_conn_event_count;
				conn->llcp_conn_param.offset0 = cpr->offset0;
				conn->llcp_conn_param.offset1 = cpr->offset1;
				conn->llcp_conn_param.offset2 = cpr->offset2;
				conn->llcp_conn_param.offset3 = cpr->offset3;
				conn->llcp_conn_param.offset4 = cpr->offset4;
				conn->llcp_conn_param.offset5 = cpr->offset5;
				conn->llcp_conn_param.state = LLCP_CPR_STATE_RSP;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND:
			isr_rx_conn_pkt_ctrl_rej(radio_pdu_node_rx, rx_enqueue);
			break;
		case PDU_DATA_LLCTRL_TYPE_UNKNOWN_RSP:
			if (0) {
			} else if (_radio.conn_curr->llcp_phy.req !=
					_radio.conn_curr->llcp_phy.ack) {
				struct radio_le_phy_upd_cmplt *p;
				_radio.conn_curr->llcp_phy.ack =
					_radio.conn_curr->llcp_phy.req;
				_radio.conn_curr->phy_tx_time =
					_radio.conn_curr->phy_tx;
				if (_radio.conn_curr->llcp_phy.cmd) {
					radio_pdu_node_rx->hdr.type =
						NODE_RX_TYPE_PHY_UPDATE;
					p = (struct radio_le_phy_upd_cmplt *)
						&pdu_data_rx->payload;
					p->status = 0;
					p->tx = _radio.conn_curr->phy_tx;
					p->rx = _radio.conn_curr->phy_rx;
					*rx_enqueue = 1;
				}
			} else {
				struct pdu_data_llctrl *llctrl;
				llctrl = (struct pdu_data_llctrl *)
					&pdu_data_rx->payload.llctrl;
				switch (llctrl->ctrldata.unknown_rsp.type) {
					default:
						*rx_enqueue = 1;
						break;
				}
			}
			_radio.conn_curr->procedure_expire = 0;
			break;
		case PDU_DATA_LLCTRL_TYPE_PHY_REQ:
			if (_radio.role == ROLE_MASTER) {
				if ((_radio.conn_curr->llcp_phy.ack !=
							_radio.conn_curr->llcp_phy.req) &&
						((_radio.conn_curr->llcp_phy.state ==
						  1) ||
						 (_radio.conn_curr->llcp_phy.state ==
						  2) ||
						 (_radio.conn_curr->llcp_phy.state ==
						  3))) {
					nack = reject_ext_ind_send(_radio.conn_curr,
							PDU_DATA_LLCTRL_TYPE_PHY_REQ,
							0x23);
				} else if (((_radio.conn_curr->llcp_req !=
								_radio.conn_curr->llcp_ack) &&
							(_radio.conn_curr->llcp_type !=
							 LLCP_ENCRYPTION)) ||
						(_radio.conn_curr->llcp_conn_param.req !=
						 _radio.conn_curr->llcp_conn_param.ack)) {
					nack = reject_ext_ind_send(_radio.conn_curr,
							PDU_DATA_LLCTRL_TYPE_PHY_REQ,
							0x2a);
				} else {
					struct pdu_data_llctrl *c =
						&pdu_data_rx->payload.llctrl;
					struct pdu_data_llctrl_phy_req_rsp *p =
						&c->ctrldata.phy_req;
					_radio.conn_curr->llcp_phy.state =
						3;
					if (_radio.conn_curr->llcp_phy.ack ==
							_radio.conn_curr->llcp_phy.req) {
						_radio.conn_curr->llcp_phy.ack--;
						_radio.conn_curr->llcp_phy.cmd = 0;
						_radio.conn_curr->llcp_phy.tx =
							_radio.conn_curr->phy_pref_tx;
						_radio.conn_curr->llcp_phy.rx =
							_radio.conn_curr->phy_pref_rx;
					}
					_radio.conn_curr->llcp_phy.tx &= p->rx_phys;
					_radio.conn_curr->llcp_phy.rx &= p->tx_phys;
				}
			} else {
				nack = phy_rsp_send(_radio.conn_curr, pdu_data_rx);
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_PHY_RSP:
			if ((_radio.role == ROLE_MASTER) &&
					(_radio.conn_curr->llcp_phy.ack !=
					 _radio.conn_curr->llcp_phy.req) &&
					(_radio.conn_curr->llcp_phy.state ==
					 2)) {
				struct pdu_data_llctrl_phy_req_rsp *p =
					&pdu_data_rx->payload.llctrl.ctrldata.phy_rsp;
				_radio.conn_curr->llcp_phy.state = 3;
				_radio.conn_curr->llcp_phy.tx &= p->rx_phys;
				_radio.conn_curr->llcp_phy.rx &= p->tx_phys;
				_radio.conn_curr->procedure_expire = 0;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_PHY_UPD_IND:
			if (phy_upd_ind(radio_pdu_node_rx, rx_enqueue)) {
				_radio.conn_curr->llcp_terminate.reason_peer = 0x28;
			}
			break;
		case PDU_DATA_LLCTRL_TYPE_MIN_USED_CHAN_IND:
			if (!_radio.conn_curr->role) {
				struct pdu_data_llctrl_min_used_chans_ind *p =
					&pdu_data_rx->payload.llctrl.ctrldata.min_used_chans_ind;
				struct connection *conn = _radio.conn_curr;
				if (!(p->phys & (conn->phy_tx | conn->phy_rx))) {
					break;
				}
				if (conn->llcp_req != conn->llcp_ack) {
					break;
				}
				memcpy(&conn->llcp.chan_map.chm[0],
						&_radio.data_chan_map[0],
						sizeof(conn->llcp.chan_map.chm));
				conn->llcp.chan_map.initiate = 1;
				conn->llcp_type = LLCP_CHAN_MAP;
				conn->llcp_ack--;
			}
			break;
		default:
			nack = unknown_rsp_send(_radio.conn_curr,
					pdu_data_rx->payload.llctrl.opcode);
			break;
	}
	return nack;
}
static inline 
	_Bool 
isr_rx_conn_enc_unexpected(struct connection *conn,
		struct pdu_data *pdu_data)
{
	u8_t opcode = pdu_data->payload.llctrl.opcode;
	return (pdu_data->ll_id != PDU_DATA_LLID_CTRL) ||
		(!conn->role &&
		 ((!conn->refresh &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_TERMINATE_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_START_ENC_REQ) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_START_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND)) ||
		  (conn->refresh &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_TERMINATE_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_START_ENC_REQ) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_START_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND)))) ||
		(conn->role &&
		 ((!conn->refresh &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_TERMINATE_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_START_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND)) ||
		  (conn->refresh &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_TERMINATE_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_ENC_REQ) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_START_ENC_RSP) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_IND) &&
		   (opcode != PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND))));
}
	static inline u32_t
isr_rx_conn_pkt(struct radio_pdu_node_rx *radio_pdu_node_rx,
		struct radio_pdu_node_tx **tx_release, u8_t *rx_enqueue)
{
	struct pdu_data *pdu_data_rx;
	struct pdu_data *pdu_data_tx;
	u8_t terminate = 0;
	u8_t nack = 0;
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	if (pdu_data_rx->nesn != _radio.conn_curr->sn) {
		_radio.conn_curr->sn++;
		if (_radio.role == ROLE_SLAVE) {
			_radio.conn_curr->slave.latency_enabled = 1;
		}
		if (_radio.conn_curr->empty == 0) {
			struct radio_pdu_node_tx *node_tx;
			u8_t pdu_data_tx_len;
			node_tx = _radio.conn_curr->pkt_tx_head;
			pdu_data_tx = (struct pdu_data *)
				(node_tx->pdu_data +
				 _radio.conn_curr->packet_tx_head_offset);
			pdu_data_tx_len = pdu_data_tx->len;
			if (pdu_data_tx_len != 0) {
				if (_radio.conn_curr->enc_tx) {
					_radio.conn_curr->ccm_tx.counter++;
				}
				if (pdu_data_tx->ll_id == PDU_DATA_LLID_CTRL) {
					terminate =
						isr_rx_conn_pkt_ack(pdu_data_tx,
								&node_tx);
				}
			}
			_radio.conn_curr->packet_tx_head_offset += pdu_data_tx_len;
			if (_radio.conn_curr->packet_tx_head_offset ==
					_radio.conn_curr->packet_tx_head_len) {
				*tx_release = isr_rx_conn_pkt_release(node_tx);
			}
		} else {
			_radio.conn_curr->empty = 0;
		}
	}
	if (terminate) {
		connection_release(_radio.conn_curr);
		_radio.conn_curr = 
			((void *)0)
			;
		return terminate;
	}
	if ((pdu_data_rx->sn == _radio.conn_curr->nesn) &&
			(packet_rx_reserve_get(3) != 0) &&
			((_radio.fc_ena == 0) ||
			 ((_radio.link_rx_head == _radio.link_rx_tail) &&
			  (_radio.fc_req == _radio.fc_ack)) ||
			 ((_radio.link_rx_head != _radio.link_rx_tail) &&
			  (_radio.fc_req != _radio.fc_ack) &&
			  (((_radio.fc_req == 0) &&
			    (_radio.fc_handle[3 - 1] ==
			     _radio.conn_curr->handle)) ||
			   ((_radio.fc_req != 0) &&
			    (_radio.fc_handle[_radio.fc_req - 1] ==
			     _radio.conn_curr->handle)))))) {
		u8_t ccm_rx_increment = 0;
		if (pdu_data_rx->len != 0) {
			if (_radio.conn_curr->enc_rx) {
				u32_t done;
				done = radio_ccm_is_done();
				if (!(done)) { ; ; };
				ccm_rx_increment = 1;
			}
			if ((_radio.conn_curr->enc_rx &&
						!radio_ccm_mic_is_valid()) ||
					(_radio.conn_curr->pause_rx &&
					 isr_rx_conn_enc_unexpected(_radio.conn_curr,
						 pdu_data_rx))) {
				_radio.state = STATE_CLOSE;
				radio_disable();
				if (!(!radio_is_ready())) { ; ; };
				terminate_ind_rx_enqueue(_radio.conn_curr,
						0x3d);
				connection_release(_radio.conn_curr);
				_radio.conn_curr = 
					((void *)0)
					;
				return 1;
			}
			switch (pdu_data_rx->ll_id) {
				case PDU_DATA_LLID_DATA_CONTINUE:
				case PDU_DATA_LLID_DATA_START:
					*rx_enqueue = 1;
					break;
				case PDU_DATA_LLID_CTRL:
					nack = isr_rx_conn_pkt_ctrl(radio_pdu_node_rx,
							rx_enqueue);
					break;
				case PDU_DATA_LLID_RESV:
				default:
					break;
			}
		}
		if (!nack) {
			_radio.conn_curr->nesn++;
			if (ccm_rx_increment) {
				_radio.conn_curr->ccm_rx.counter++;
			}
		}
	}
	return 0;
}
static inline void isr_rx_conn(u8_t crc_ok, u8_t trx_done,
		u8_t rssi_ready)
{
	struct radio_pdu_node_rx *radio_pdu_node_rx;
	struct radio_pdu_node_tx *tx_release = 
		((void *)0)
		;
	u8_t is_empty_pdu_tx_retry;
	struct pdu_data *pdu_data_rx;
	struct pdu_data *pdu_data_tx;
	u8_t rx_enqueue = 0;
	u8_t crc_close = 0;
	_radio.packet_counter++;
	radio_pdu_node_rx = _radio.packet_rx[_radio.packet_rx_last];
	radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_DC_PDU;
	if (crc_ok) {
		u32_t terminate;
		terminate = isr_rx_conn_pkt(radio_pdu_node_rx, &tx_release,
				&rx_enqueue);
		if (terminate) {
			goto isr_rx_conn_exit;
		}
		_radio.crc_expire = 0;
		_radio.conn_curr->supervision_expire = 0;
	} else {
		if (_radio.crc_expire == 0) {
			_radio.crc_expire = 2;
		}
		_radio.crc_expire--;
		crc_close = (_radio.crc_expire == 0);
		if (!_radio.conn_curr->supervision_expire) {
			_radio.conn_curr->supervision_expire =
				_radio.conn_curr->supervision_reload;
		}
	}
	is_empty_pdu_tx_retry = _radio.conn_curr->empty;
	prepare_pdu_data_tx(_radio.conn_curr, &pdu_data_tx);
	if (0) {
		if (_radio.packet_counter == 0) {
			_radio.packet_counter = 0xFF;
		}
		if (!trx_done) {
			if (_radio.packet_counter == 1) {
				_radio.packet_counter = 0xFF;
			}
			if ((_radio.conn_curr->empty) &&
					(pdu_data_tx->md == 0)) {
				_radio.state = STATE_CLOSE;
				radio_disable();
				goto isr_rx_conn_exit;
			}
		}
	}
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	_radio.state = ((_radio.state == STATE_CLOSE) || (crc_close) ||
			((crc_ok) && (pdu_data_rx->md == 0) &&
			 (pdu_data_tx->len == 0)) ||
			_radio.conn_curr->llcp_terminate.reason_peer) ?
		STATE_CLOSE : STATE_TX;
	if (_radio.state == STATE_CLOSE) {
		if (_radio.role == ROLE_MASTER) {
			_radio.conn_curr->empty = is_empty_pdu_tx_retry;
			radio_disable();
			goto isr_rx_conn_exit;
		}
		else {
			radio_switch_complete_and_disable();
		}
	} else {
		radio_tmr_tifs_set(150);
		radio_switch_complete_and_rx(_radio.conn_curr->phy_rx);
		radio_tmr_end_capture();
	}
	pdu_data_tx->sn = _radio.conn_curr->sn;
	pdu_data_tx->nesn = _radio.conn_curr->nesn;
	tx_packet_set(_radio.conn_curr, pdu_data_tx);
	if (!(!radio_is_ready())) { ; ; };
isr_rx_conn_exit:
	if (!radio_tmr_aa_restore()) {
		radio_tmr_aa_save(radio_tmr_aa_get());
	}
	if (!_radio.conn_curr) {
		goto isr_rx_conn_terminate_exit;
	}
	if (tx_release) {
		pdu_node_tx_release(_radio.conn_curr->handle, tx_release);
	}
	if (rx_enqueue) {
		rx_fc_lock(_radio.conn_curr->handle);
		radio_pdu_node_rx->hdr.handle = _radio.conn_curr->handle;
		packet_rx_enqueue();
	}
	(void)(rssi_ready);
isr_rx_conn_terminate_exit:
	return;
}
static inline void isr_radio_state_rx(u8_t trx_done, u8_t crc_ok,
		u8_t devmatch_ok, u8_t devmatch_id,
		u8_t irkmatch_ok, u8_t irkmatch_id,
		u8_t rssi_ready)
{
	u32_t err;
	u8_t rl_idx;
	if (!((trx_done) || ((0) &&
					(_radio.role == ROLE_SLAVE)))) {
		_radio.state = STATE_CLOSE;
		radio_disable();
		return;
	}
	switch (_radio.role) {
		case ROLE_ADV:
			if (crc_ok) {
				err = isr_rx_adv(devmatch_ok, devmatch_id, irkmatch_ok,
						irkmatch_id, rssi_ready);
			} else {
				err = 1;
			}
			if (err) {
				_radio.state = STATE_CLOSE;
				radio_disable();
			}
			break;
		case ROLE_SCAN:
			rl_idx = 0xFF;
			if (crc_ok &&
					isr_rx_scan_check(irkmatch_ok, devmatch_ok, rl_idx)) {
				err = isr_rx_scan(devmatch_ok, devmatch_id, irkmatch_ok,
						irkmatch_id, rl_idx, rssi_ready);
			} else {
				err = 1;
			}
			if (err) {
				_radio.state = STATE_CLOSE;
				radio_disable();
				_radio.scanner.state = 0;
			}
			break;
		case ROLE_SLAVE:
		case ROLE_MASTER:
			isr_rx_conn(crc_ok, trx_done, rssi_ready);
			break;
		case ROLE_NONE:
		default:
			if (!(0)) { ; ; };
			break;
	}
}
static inline u32_t isr_close_adv(void)
{
	u32_t dont_close = 0;
	if ((_radio.state == STATE_CLOSE) &&
			(_radio.advertiser.chan_map_current != 0)) {
		u32_t start_us;
		dont_close = 1;
		adv_setup();
		(void)(start_us);
		radio_tx_enable();
		radio_tmr_end_capture();
	} else {
		struct pdu_adv *pdu_adv;
		radio_filter_disable();
		pdu_adv = (struct pdu_adv *)
			&_radio.advertiser.adv_data.data[_radio.advertiser.adv_data.first][0];
		if ((_radio.state == STATE_CLOSE) &&
				(pdu_adv->type != PDU_ADV_TYPE_DIRECT_IND)) {
			u32_t ticker_status;
			u8_t random_delay;
			rand_isr_get(sizeof(random_delay), &random_delay);
			random_delay %= 10;
			random_delay += 1;
			ticker_status =
				ticker_update(0,
						0,
						5,
						( ((u32_t)(((u64_t) (random_delay * 1000) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
						,
						0, 0, 0, 0, 0,
						ticker_update_adv_assert,
						(void *)3706);
			if (!((ticker_status == 0) || (ticker_status == 2) || (_radio.ticker_id_stop == 5))) { ; ; }
			;
		}
	}
	return dont_close;
}
static inline u32_t isr_close_scan(void)
{
	u32_t dont_close = 0;
	if (_radio.state == STATE_CLOSE) {
		u32_t start_us;
		dont_close = 1;
		radio_tmr_tifs_set(150);
		radio_switch_complete_and_tx(0, 0, 0, 0);
		radio_pkt_rx_set(_radio.packet_rx[_radio.packet_rx_last]->
				pdu_data);
		radio_rssi_measure();
		_radio.state = STATE_RX;
		(void)(start_us);
		radio_rx_enable();
		radio_tmr_end_capture();
	} else {
		radio_filter_disable();
		if (_radio.state == STATE_ABORT) {
			ticker_stop(0,
					0,
					4, 
					((void *)0)
					, 
					((void *)0)
				   );
		}
	}
	return dont_close;
}
static inline void isr_close_conn(void)
{
	u16_t ticks_drift_plus;
	u16_t ticks_drift_minus;
	u16_t latency_event;
	u16_t elapsed_event;
	u8_t reason_peer;
	u16_t lazy;
	u8_t force;
	if (_radio.conn_curr == 0) {
		return;
	}
	reason_peer = _radio.conn_curr->llcp_terminate.reason_peer;
	if (reason_peer && ((_radio.role == ROLE_SLAVE) ||
				_radio.conn_curr->master.terminate_ack)) {
		terminate_ind_rx_enqueue(_radio.conn_curr, reason_peer);
		connection_release(_radio.conn_curr);
		_radio.conn_curr = 
			((void *)0)
			;
		return;
	}
	ticks_drift_plus = 0;
	ticks_drift_minus = 0;
	latency_event = _radio.conn_curr->latency_event;
	elapsed_event = latency_event + 1;
	if (_radio.packet_counter &&
			(!0 || (_radio.packet_counter != 0xFF))) {
		if (_radio.role == ROLE_SLAVE) {
			u32_t start_to_address_expected_us;
			u32_t start_to_address_actual_us;
			u32_t window_widening_event_us;
			u32_t preamble_to_addr_us;
			start_to_address_actual_us = radio_tmr_aa_restore() -
				radio_tmr_ready_get();
			window_widening_event_us =
				_radio.conn_curr->slave.window_widening_event_us;
			preamble_to_addr_us =
				addr_us_get(_radio.conn_curr->phy_rx);
			start_to_address_expected_us = 16 +
				(16 << 1) +
				preamble_to_addr_us +
				window_widening_event_us;
			if (start_to_address_actual_us <=
					start_to_address_expected_us) {
				ticks_drift_plus =
					( ((u32_t)(((u64_t) (window_widening_event_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
				ticks_drift_minus =
					( ((u32_t)(((u64_t) ((u64_t)(start_to_address_expected_us - start_to_address_actual_us)) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
					;
			} else {
				ticks_drift_plus =
					( ((u32_t)(((u64_t) (start_to_address_actual_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
				ticks_drift_minus =
					( ((u32_t)(((u64_t) (16 + (16 << 1) + preamble_to_addr_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
					;
			}
			_radio.conn_curr->slave.window_widening_event_us = 0;
			_radio.conn_curr->slave.window_size_event_us = 0;
			if (_radio.conn_curr->pkt_tx_head) {
				struct pdu_data *pdu_data_tx;
				pdu_data_tx = (struct pdu_data *)
					_radio.conn_curr->pkt_tx_head->pdu_data;
				if (pdu_data_tx->len ||
						_radio.conn_curr->packet_tx_head_offset) {
					_radio.conn_curr->latency_event = 0;
				}
			} else if (_radio.conn_curr->slave.latency_enabled) {
				_radio.conn_curr->latency_event =
					_radio.conn_curr->latency;
			}
		} else if (reason_peer) {
			_radio.conn_curr->master.terminate_ack = 1;
		}
		_radio.conn_curr->connect_expire = 0;
	}
	else if (_radio.conn_curr->connect_expire) {
		if (_radio.conn_curr->connect_expire > elapsed_event) {
			_radio.conn_curr->connect_expire -= elapsed_event;
		} else {
			terminate_ind_rx_enqueue(_radio.conn_curr, 0x3e);
			connection_release(_radio.conn_curr);
			_radio.conn_curr = 
				((void *)0)
				;
			return;
		}
	}
	else {
		if (!_radio.conn_curr->supervision_expire) {
			_radio.conn_curr->supervision_expire =
				_radio.conn_curr->supervision_reload;
		}
	}
	force = 0;
	if (_radio.conn_curr->supervision_expire) {
		if (_radio.conn_curr->supervision_expire > elapsed_event) {
			_radio.conn_curr->supervision_expire -= elapsed_event;
			_radio.conn_curr->latency_event = 0;
			if (_radio.conn_curr->supervision_expire <= 6) {
				force = 1;
			}
			else if (_radio.role == ROLE_SLAVE) {
				if (latency_event != 0) {
					force = 1;
				} else {
					force = _radio.conn_curr->slave.force & 0x01;
					_radio.conn_curr->slave.force >>= 1;
					if (force) {
						_radio.conn_curr->slave.force |=
							((u32_t)1 << 31);
					}
				}
			}
		} else {
			terminate_ind_rx_enqueue(_radio.conn_curr, 0x08);
			connection_release(_radio.conn_curr);
			_radio.conn_curr = 
				((void *)0)
				;
			return;
		}
	}
	if (_radio.conn_curr->procedure_expire != 0) {
		if (_radio.conn_curr->procedure_expire > elapsed_event) {
			_radio.conn_curr->procedure_expire -= elapsed_event;
		} else {
			terminate_ind_rx_enqueue(_radio.conn_curr, 0x22);
			connection_release(_radio.conn_curr);
			_radio.conn_curr = 
				((void *)0)
				;
			return;
		}
	}
	if ((_radio.conn_curr->llcp_ack != _radio.conn_curr->llcp_req) &&
			((_radio.conn_curr->llcp_type == LLCP_CONN_UPD) ||
			 (_radio.conn_curr->llcp_type == LLCP_CHAN_MAP))) {
		_radio.conn_curr->latency_event = 0;
	}
	lazy = 0;
	if ((force) || (latency_event != _radio.conn_curr->latency_event)) {
		lazy = _radio.conn_curr->latency_event + 1;
	}
	if ((ticks_drift_plus != 0) || (ticks_drift_minus != 0) ||
			(lazy != 0) || (force != 0)) {
		u32_t ticker_status;
		u8_t ticker_id = 7 +
			_radio.conn_curr->handle;
		ticker_status =
			ticker_update(0,
					0,
					ticker_id,
					ticks_drift_plus, ticks_drift_minus, 0, 0,
					lazy, force, ticker_update_slave_assert,
					(void *)(u32_t)ticker_id);
		if (!((ticker_status == 0) || (ticker_status == 2) || (_radio.ticker_id_stop == ticker_id))) { ; ; }
		;
	}
}
static inline void isr_radio_state_close(void)
{
	u32_t dont_close = 0;
	switch (_radio.role) {
		case ROLE_ADV:
			dont_close = isr_close_adv();
			break;
		case ROLE_SCAN:
			dont_close = isr_close_scan();
			break;
		case ROLE_SLAVE:
		case ROLE_MASTER:
			isr_close_conn();
			break;
		case ROLE_NONE:
			if (!((_radio.state == STATE_STOP) || (_radio.state == STATE_ABORT))) { ; ; }
			;
			_radio.state = STATE_NONE;
			return;
		default:
			if (!(0)) { ; ; };
			break;
	}
	if (dont_close) {
		return;
	}
	_radio.role = ROLE_NONE;
	_radio.state = STATE_NONE;
	_radio.ticker_id_event = 0;
	radio_tmr_stop();
	event_inactive(0, 0, 0, 
			((void *)0)
		      );
	clock_control_off(_radio.hf_clock, 
			((void *)0)
			);
	mayfly_enable(0, 1, 1);
	;
}
static void isr(void)
{
	u8_t trx_done;
	u8_t crc_ok;
	u8_t devmatch_ok;
	u8_t devmatch_id;
	u8_t irkmatch_ok;
	u8_t irkmatch_id;
	u8_t rssi_ready;
	;
	trx_done = radio_is_done();
	if (trx_done) {
		crc_ok = radio_crc_is_valid();
		devmatch_ok = radio_filter_has_match();
		devmatch_id = radio_filter_match_get();
		irkmatch_ok = radio_ar_has_match();
		irkmatch_id = radio_ar_match_get();
		rssi_ready = radio_rssi_is_ready();
	} else {
		crc_ok = devmatch_ok = irkmatch_ok = rssi_ready = 0;
		devmatch_id = irkmatch_id = 0xFF;
	}
	radio_status_reset();
	radio_tmr_status_reset();
	radio_filter_status_reset();
	radio_ar_status_reset();
	radio_rssi_status_reset();
	switch (_radio.state) {
		case STATE_TX:
			isr_radio_state_tx();
			break;
		case STATE_RX:
			isr_radio_state_rx(trx_done, crc_ok, devmatch_ok, devmatch_id,
					irkmatch_ok, irkmatch_id, rssi_ready);
			break;
		case STATE_ABORT:
		case STATE_STOP:
		case STATE_CLOSE:
			isr_radio_state_close();
			break;
		case STATE_NONE:
			break;
		default:
			if (!(0)) { ; ; };
			break;
	}
	;
}
static void ticker_job_disable(u32_t status, void *op_context)
{
	(void)(status);
	(void)(op_context);
	if (_radio.state != STATE_NONE) {
		mayfly_enable(1,
				1, 0);
	}
}
static void ticker_if_done(u32_t status, void *ops_context)
{
	*((u32_t volatile *)ops_context) = status;
}
static void ticker_success_assert(u32_t status, void *params)
{
	(void)(params);
	if (!(status == 0)) { ; ; };
}
static void ticker_stop_adv_assert(u32_t status, void *params)
{
	(void)(params);
	if (status == 1) {
		if (_radio.ticker_id_stop == 5) {
			_radio.ticker_id_stop = 0;
		} else {
			if (!(0)) { ; ; };
		}
	} else {
		if (!(_radio.ticker_id_prepare != 5)) { ; ; };
	}
}
static void ticker_stop_scan_assert(u32_t status, void *params)
{
	(void)(params);
	if (status == 1) {
		if (_radio.ticker_id_stop == 6) {
			_radio.ticker_id_stop = 0;
		} else {
			if (!(0)) { ; ; };
		}
	} else {
		if (!(_radio.ticker_id_prepare != 6)) { ; ; };
	}
}
static void ticker_update_adv_assert(u32_t status, void *params)
{
	(void)(params);
	if (!((status == 0) || (_radio.ticker_id_stop == 5))) { ; ; }
	;
}
static void ticker_update_slave_assert(u32_t status, void *params)
{
	u8_t ticker_id = (u32_t)params & 0xFF;
	if (!((status == 0) || (_radio.ticker_id_stop == ticker_id))) { ; ; }
	;
}
static void mayfly_radio_active(void *params)
{
	static u8_t s_active;
	if ((u32_t)params) {
		if (s_active++) {
			return;
		}
		;
		radio_active_callback(1);
	} else {
		if (!(s_active)) { ; ; };
		if (--s_active) {
			return;
		}
		;
		radio_active_callback(0);
	}
}
static void event_active(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_radio_active = {0, 0, &s_link, (void *)1,
		mayfly_radio_active};
	u32_t retval;
	(void)(ticks_at_expire);
	(void)(remainder);
	(void)(lazy);
	(void)(context);
	retval = mayfly_enqueue(0,
			0, 0,
			&s_mfy_radio_active);
	if (!(!retval)) { ; ; };
}
static void mayfly_radio_inactive(void *params)
{
	(void)(params);
	mayfly_radio_active(0);
	;
}
static void event_inactive(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_radio_inactive = {0, 0, &s_link, 
		((void *)0)
			,
		mayfly_radio_inactive};
	u32_t retval;
	(void)(ticks_at_expire);
	(void)(remainder);
	(void)(lazy);
	(void)(context);
	retval = mayfly_enqueue(0,
			0, 0,
			&s_mfy_radio_inactive);
	if (!(!retval)) { ; ; };
}
static void mayfly_xtal_start(void *params)
{
	(void)(params);
	clock_control_on(_radio.hf_clock, 
			((void *)0)
			);
}
static void event_xtal(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_xtal_start = {0, 0, &s_link, 
		((void *)0)
			,
		mayfly_xtal_start};
	u32_t retval;
	(void)(ticks_at_expire);
	(void)(remainder);
	(void)(lazy);
	(void)(context);
	retval = mayfly_enqueue(0,
			0, 0,
			&s_mfy_xtal_start);
	if (!(!retval)) { ; ; };
}
static void mayfly_xtal_stop(void *params)
{
	(void)(params);
	clock_control_off(_radio.hf_clock, 
			((void *)0)
			);
	;
}
static void mayfly_radio_stop(void *params)
{
	enum state state = (enum state)((u32_t)params & 0xff);
	u32_t radio_used;
	if (!((state == STATE_STOP) || (state == STATE_ABORT))) { ; ; };
	radio_used = ((_radio.state != STATE_NONE) &&
			(_radio.state != STATE_STOP) &&
			(_radio.state != STATE_ABORT));
	if (radio_used || !radio_is_idle()) {
		if (radio_used) {
			_radio.state = state;
		}
		radio_disable();
	}
}
static void event_stop(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_radio_stop = {0, 0, &s_link, 
		((void *)0)
			,
		mayfly_radio_stop};
	u32_t retval;
	(void)(ticks_at_expire);
	(void)(remainder);
	(void)(lazy);
	s_mfy_radio_stop.param = context;
	retval = mayfly_enqueue(0,
			0, 0,
			&s_mfy_radio_stop);
	if (!(!retval)) { ; ; };
}
static void event_common_prepare(u32_t ticks_at_expire,
		u32_t remainder,
		u32_t *ticks_xtal_to_start,
		u32_t *ticks_active_to_start,
		u32_t ticks_preempt_to_start,
		u8_t ticker_id,
		ticker_timeout_func ticker_timeout_fp,
		void *context)
{
	u32_t ticker_status;
	u32_t _ticks_xtal_to_start = *ticks_xtal_to_start;
	u32_t _ticks_active_to_start = *ticks_active_to_start;
	u32_t ticks_to_start;
	if (_ticks_xtal_to_start & ((u32_t)1 << 31)) {
		_ticks_xtal_to_start =
			(_ticks_active_to_start > ticks_preempt_to_start) ?
			_ticks_active_to_start :
			ticks_preempt_to_start;
	}
	if (_ticks_active_to_start < _ticks_xtal_to_start) {
		u32_t ticks_to_active;
		ticks_to_active = _ticks_xtal_to_start - _ticks_active_to_start;
		ticks_to_start = _ticks_xtal_to_start;
		ticker_status =
			ticker_start(0,
					0,
					1, ticks_at_expire,
					ticks_to_active, 0,
					0, 0,
					0, event_active, 
					((void *)0)
					,
					ticker_success_assert, (void *)5271);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		event_xtal(0, 0, 0, 
				((void *)0)
			  );
	} else if (_ticks_active_to_start > _ticks_xtal_to_start) {
		u32_t ticks_to_xtal;
		ticks_to_xtal = _ticks_active_to_start - _ticks_xtal_to_start;
		ticks_to_start = _ticks_active_to_start;
		event_active(0, 0, 0, 
				((void *)0)
			    );
		ticker_status =
			ticker_start(0,
					0,
					1, ticks_at_expire,
					ticks_to_xtal, 0,
					0, 0,
					0, event_xtal, 
					((void *)0)
					,
					ticker_success_assert, (void *)5292);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	} else {
		ticks_to_start = _ticks_xtal_to_start;
		event_active(0, 0, 0, 
				((void *)0)
			    );
		event_xtal(0, 0, 0, 
				((void *)0)
			  );
	}
	_radio.remainder_anchor = remainder;
	ticker_status =
		ticker_start(0,
				0, 0,
				ticks_at_expire, ticks_to_start,
				0, 0,
				0, 0,
				ticker_timeout_fp, context, ticker_success_assert,
				(void *)5316);
	if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
	;
	event_stop(0, 0, 0, (void *)STATE_ABORT);
	if (_radio.ticks_active_to_start != _ticks_active_to_start) {
		u32_t ticks_to_start_new =
			((_radio.ticks_active_to_start <
			  (*ticks_xtal_to_start & ~(((u32_t)1 << 31)))) ?
			 (*ticks_xtal_to_start & ~(((u32_t)1 << 31))) :
			 _radio.ticks_active_to_start);
		*ticks_active_to_start = _radio.ticks_active_to_start;
		if ((*ticks_xtal_to_start) & ((u32_t)1 << 31)) {
			*ticks_xtal_to_start &= ~(((u32_t)1 << 31));
		}
		ticker_status =
			ticker_update(0,
					0, ticker_id,
					ticks_to_start, ticks_to_start_new,
					ticks_to_start_new, ticks_to_start, 0, 0,
					ticker_success_assert, (void *)5361);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	}
	packet_tx_enqueue(0xFF);
}
static u8_t chan_sel_remap(u8_t *chan_map, u8_t chan_index)
{
	u8_t chan_next;
	u8_t byte_count;
	chan_next = 0;
	byte_count = 5;
	while (byte_count--) {
		u8_t bite;
		u8_t bit_count;
		bite = *chan_map;
		bit_count = 8;
		while (bit_count--) {
			if (bite & 0x01) {
				if (chan_index == 0) {
					break;
				}
				chan_index--;
			}
			chan_next++;
			bite >>= 1;
		}
		if (bit_count < 8) {
			break;
		}
		chan_map++;
	}
	return chan_next;
}
static u8_t chan_sel_1(u8_t *chan_use, u8_t hop, u16_t latency, u8_t *chan_map,
		u8_t chan_count)
{
	u8_t chan_next;
	chan_next = ((*chan_use) + (hop * (1 + latency))) % 37;
	*chan_use = chan_next;
	if ((chan_map[chan_next >> 3] & (1 << (chan_next % 8))) == 0) {
		u8_t chan_index;
		chan_index = chan_next % chan_count;
		chan_next = chan_sel_remap(chan_map, chan_index);
	} else {
	}
	return chan_next;
}
static u8_t chan_rev_8(u8_t i)
{
	u8_t iterate;
	u8_t o;
	o = 0;
	for (iterate = 0; iterate < 8; iterate++) {
		o <<= 1;
		o |= (i & 1);
		i >>= 1;
	}
	return o;
}
static u16_t chan_perm(u16_t i)
{
	return (chan_rev_8((i >> 8) & 0xFF) << 8) | chan_rev_8(i & 0xFF);
}
static u16_t chan_mam(u16_t a, u16_t b)
{
	return ((u32_t)a * 17 + b) & 0xFFFF;
}
static u16_t chan_prn(u16_t counter, u16_t chan_id)
{
	u8_t iterate;
	u16_t prn_e;
	prn_e = counter ^ chan_id;
	for (iterate = 0; iterate < 3; iterate++) {
		prn_e = chan_perm(prn_e);
		prn_e = chan_mam(prn_e, chan_id);
	}
	prn_e ^= chan_id;
	return prn_e;
}
static u8_t chan_sel_2(u16_t counter, u16_t chan_id, u8_t *chan_map,
		u8_t chan_count)
{
	u8_t chan_next;
	u16_t prn_e;
	prn_e = chan_prn(counter, chan_id);
	chan_next = prn_e % 37;
	if ((chan_map[chan_next >> 3] & (1 << (chan_next % 8))) == 0) {
		u8_t chan_index;
		chan_index = ((u32_t)chan_count * prn_e) >> 16;
		chan_next = chan_sel_remap(chan_map, chan_index);
	} else {
	}
	return chan_next;
}
static void chan_set(u32_t chan)
{
	switch (chan) {
		case 37:
			radio_freq_chan_set(2);
			break;
		case 38:
			radio_freq_chan_set(26);
			break;
		case 39:
			radio_freq_chan_set(80);
			break;
		default:
			if (chan < 11) {
				radio_freq_chan_set(4 + (2 * chan));
			} else if (chan < 40) {
				radio_freq_chan_set(28 + (2 * (chan - 11)));
			} else {
				if (!(0)) { ; ; };
			}
			break;
	}
	radio_whiten_iv_set(chan);
}
static u32_t access_addr_get(void)
{
	u8_t consecutive_cnt;
	u8_t consecutive_bit;
	u32_t adv_aa_check;
	u32_t access_addr;
	u8_t transitions;
	u8_t bit_idx;
	u8_t retry;
	u8_t len;
	retry = 3;
again:
	if (!(retry)) { ; ; };
	retry--;
	len = sizeof(u32_t);
	while (len) {
		len = rand_get(len, (u8_t *)&access_addr);
		if (len) {
			cpu_sleep();
		}
	}
	bit_idx = 31;
	transitions = 0;
	consecutive_cnt = 1;
	consecutive_bit = (access_addr >> bit_idx) & 0x01;
	while (bit_idx--) {
		u8_t bit;
		bit = (access_addr >> bit_idx) & 0x01;
		if (bit == consecutive_bit) {
			consecutive_cnt++;
		} else {
			consecutive_cnt = 1;
			consecutive_bit = bit;
			transitions++;
		}
		if ((consecutive_cnt > 6) ||
				((bit_idx < 28) && (transitions < 1)) ||
				((bit_idx < 27) && (transitions < 2))) {
			if (consecutive_bit) {
				consecutive_bit = 0;
				access_addr &= ~(1UL << (bit_idx));
			} else {
				consecutive_bit = 1;
				access_addr |= (1UL << (bit_idx));
			}
			consecutive_cnt = 1;
			transitions++;
		}
		if (transitions > 24) {
			if (consecutive_bit) {
				access_addr &= ~((1UL << (bit_idx + 1)) - 1);
			} else {
				access_addr |= ((1UL << (bit_idx + 1)) - 1);
			}
			break;
		}
	}
	adv_aa_check = access_addr ^ 0x8e89bed6;
	if (util_ones_count_get((u8_t *)&adv_aa_check,
				sizeof(adv_aa_check)) <= 1) {
		goto again;
	}
	if (!((access_addr & 0xFFFF) ^ (access_addr >> 16)) &&
			!((access_addr & 0xFF) ^ (access_addr >> 24))) {
		goto again;
	}
	return access_addr;
}
static void adv_scan_conn_configure(void)
{
	radio_reset();
	radio_tx_power_set(0);
	radio_isr_set(isr);
}
static void adv_scan_configure(u8_t phy, u8_t flags)
{
	u32_t aa = 0x8e89bed6;
	adv_scan_conn_configure();
	radio_phy_set(phy, flags);
	radio_aa_set((u8_t *)&aa);
	radio_pkt_configure(8, 37, (phy << 1));
	radio_crc_configure(((0x5bUL) | ((0x06UL) << 8) | ((0x00UL) << 16)),
			0x555555);
}
void radio_event_adv_prepare(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	(void)(lazy);
	(void)(context);
	;
	if (!(!_radio.ticker_id_prepare)) { ; ; };
	_radio.ticker_id_prepare = 5;
	event_common_prepare(ticks_at_expire, remainder,
			&_radio.advertiser.hdr.ticks_xtal_to_start,
			&_radio.advertiser.hdr.ticks_active_to_start,
			_radio.advertiser.hdr.ticks_preempt_to_start,
			5, event_adv, 
			((void *)0)
			);
	;
}
static void adv_setup(void)
{
	struct pdu_adv *pdu;
	u8_t bitmap;
	u8_t chan;
	u8_t upd = 0;
	if (_radio.advertiser.adv_data.first !=
			_radio.advertiser.adv_data.last) {
		u8_t first;
		first = _radio.advertiser.adv_data.first + 1;
		if (first == 2) {
			first = 0;
		}
		_radio.advertiser.adv_data.first = first;
		upd = 1;
	}
	if (_radio.advertiser.scan_data.first != _radio.
			advertiser.scan_data.last) {
		u8_t first;
		first = _radio.advertiser.scan_data.first + 1;
		if (first == 2) {
			first = 0;
		}
		_radio.advertiser.scan_data.first = first;
		upd = 1;
	}
	pdu = (struct pdu_adv *)
		_radio.advertiser.adv_data.data[
		_radio.advertiser.adv_data.first];
	(void)(upd);
	radio_pkt_tx_set(pdu);
	if ((pdu->type != PDU_ADV_TYPE_NONCONN_IND) &&
			(!0 ||
			 (pdu->type != PDU_ADV_TYPE_EXT_IND))) {
		_radio.state = STATE_TX;
		radio_tmr_tifs_set(150);
		radio_switch_complete_and_rx(0);
	} else {
		_radio.state = STATE_CLOSE;
		radio_switch_complete_and_disable();
	}
	bitmap = _radio.advertiser.chan_map_current;
	chan = 0;
	while ((bitmap & 0x01) == 0) {
		chan++;
		bitmap >>= 1;
	}
	_radio.advertiser.chan_map_current &=
		(_radio.advertiser.chan_map_current - 1);
	chan_set(37 + chan);
}
static void event_adv(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	u32_t remainder_us;
	(void)(remainder);
	(void)(lazy);
	(void)(context);
	;
	if (!(_radio.role == ROLE_NONE)) { ; ; };
	if (!(_radio.ticker_id_prepare == 5)) { ; ; };
	_radio.role = ROLE_ADV;
	_radio.ticker_id_prepare = 0;
	_radio.ticker_id_event = 5;
	_radio.ticks_anchor = ticks_at_expire;
	adv_scan_configure(0, 0);
	_radio.advertiser.chan_map_current = _radio.advertiser.chan_map;
	adv_setup();
	if (_radio.advertiser.filter_policy) {
		struct ll_filter *wl = ctrl_filter_get(
				1
				);
		radio_filter_configure(wl->enable_bitmask,
				wl->addr_type_bitmask,
				(u8_t *)wl->bdaddr);
	}
	remainder_us = radio_tmr_start(1,
			ticks_at_expire +
			( ((u32_t)(((u64_t) (300) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
			_radio.remainder_anchor);
	radio_tmr_end_capture();
	(void)(remainder_us);
	{
		u32_t ticker_status;
		ticker_status =
			ticker_job_idle_get(0,
					0,
					ticker_job_disable, 
					((void *)0)
					);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	}
	;
}
static void mayfly_adv_stop(void *param)
{
	struct radio_le_conn_cmplt *radio_le_conn_cmplt;
	struct radio_pdu_node_rx *radio_pdu_node_rx;
	struct pdu_data *pdu_data_rx;
	radio_pdu_node_rx = packet_rx_reserve_get(1);
	if (!(radio_pdu_node_rx)) { ; ; };
	radio_pdu_node_rx->hdr.handle = 0xffff;
	radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_CONNECTION;
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	radio_le_conn_cmplt =
		(struct radio_le_conn_cmplt *)&pdu_data_rx->payload;
	memset(radio_le_conn_cmplt, 0x00, sizeof(struct radio_le_conn_cmplt));
	radio_le_conn_cmplt->status = 0x3c;
	packet_rx_enqueue();
}
static inline void ticker_stop_adv_stop_active(void)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_radio_inactive = {0, 0, &s_link, 
		((void *)0)
			,
		mayfly_radio_inactive};
	u32_t volatile ret_cb = 2;
	u32_t ret;
	ret = ticker_stop(0,
			1, 0,
			ticker_if_done, (void *)&ret_cb);
	if (ret == 2) {
		mayfly_enable(1,
				1, 1);
		while (ret_cb == 2) {
			ticker_job_sched(0,
					1);
		}
	}
	if (ret_cb == 0) {
		static memq_link_t s_link;
		static struct mayfly s_mfy_xtal_stop = {0, 0, &s_link, 
			((void *)0)
				,
			mayfly_xtal_stop};
		u32_t volatile ret_cb = 2;
		u32_t ret;
		if (!(_radio.ticker_id_prepare)) { ; ; };
		_radio.ticker_id_prepare = 0;
		ret = ticker_stop(0,
				1,
				1,
				ticker_if_done, (void *)&ret_cb);
		if (ret == 2) {
			mayfly_enable(1,
					1, 1);
			while (ret_cb == 2) {
				ticker_job_sched(0,
						1);
			}
		}
		if (ret_cb == 0) {
			if (_radio.advertiser.hdr.ticks_active_to_start >
					(_radio.advertiser.hdr.ticks_xtal_to_start &
					 ~(1UL << (31)))) {
				u32_t retval;
				retval = mayfly_enqueue(
						1,
						0, 0,
						&s_mfy_radio_inactive);
				if (!(!retval)) { ; ; };
			} else {
				u32_t retval;
				retval = mayfly_enqueue(
						1,
						0, 0,
						&s_mfy_xtal_stop);
				if (!(!retval)) { ; ; };
			}
		} else if (ret_cb == 1) {
			u32_t retval;
			retval = mayfly_enqueue(1,
					0, 0,
					&s_mfy_radio_inactive);
			if (!(!retval)) { ; ; };
			retval = mayfly_enqueue(1,
					0, 0,
					&s_mfy_xtal_stop);
			if (!(!retval)) { ; ; };
		} else {
			if (!(0)) { ; ; };
		}
	} else if (ret_cb == 1) {
		if (_radio.role != ROLE_NONE) {
			static memq_link_t s_link;
			static struct mayfly s_mfy_radio_stop = {0, 0, &s_link,
				((void *)0)
					, mayfly_radio_stop};
			u32_t retval;
			s_mfy_radio_stop.param = (void *)STATE_STOP;
			retval = mayfly_enqueue(1,
					0, 0,
					&s_mfy_radio_stop);
			if (!(!retval)) { ; ; };
		}
	} else {
		if (!(0)) { ; ; };
	}
}
static void ticker_stop_adv_stop(u32_t status, void *params)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_adv_stop = {0, 0, &s_link, 
		((void *)0)
			,
		mayfly_adv_stop};
	u32_t retval;
	(void)(params);
	if (status != 0) {
		if (!(_radio.ticker_id_stop == 5)) { ; ; };
		return;
	}
	if ((_radio.ticker_id_prepare == 5) ||
			(_radio.ticker_id_event == 5)) {
		ticker_stop_adv_stop_active();
	}
	retval = mayfly_enqueue(1,
			0, 0,
			&s_mfy_adv_stop);
	if (!(!retval)) { ; ; };
}
void event_adv_stop(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context)
{
	u32_t ticker_status;
	(void)(ticks_at_expire);
	(void)(remainder);
	(void)(lazy);
	(void)(context);
	event_stop(0, 0, 0, (void *)STATE_ABORT);
	ticker_status =
		ticker_stop(0,
				0, 5,
				ticker_stop_adv_stop, (void *)6079);
	if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
	;
}
static void event_scan_prepare(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	(void)(lazy);
	(void)(context);
	;
	if (!(!_radio.ticker_id_prepare)) { ; ; };
	_radio.ticker_id_prepare = 6;
	event_common_prepare(ticks_at_expire, remainder,
			&_radio.scanner.hdr.ticks_xtal_to_start,
			&_radio.scanner.hdr.ticks_active_to_start,
			_radio.scanner.hdr.ticks_preempt_to_start,
			6, event_scan, 
			((void *)0)
			);
	;
}
static void event_scan(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context)
{
	u32_t ticker_status;
	u32_t remainder_us;
	(void)(remainder);
	(void)(lazy);
	(void)(context);
	;
	if (!(_radio.role == ROLE_NONE)) { ; ; };
	if (!(_radio.ticker_id_prepare == 6)) { ; ; };
	_radio.role = ROLE_SCAN;
	_radio.state = STATE_RX;
	_radio.ticker_id_prepare = 0;
	_radio.ticker_id_event = 6;
	_radio.ticks_anchor = ticks_at_expire;
	_radio.scanner.state = 0;
	adv_scan_configure(0, 0);
	chan_set(37 + _radio.scanner.chan++);
	if (_radio.scanner.chan == 3) {
		_radio.scanner.chan = 0;
	}
	radio_tmr_tifs_set(150);
	radio_switch_complete_and_tx(0, 0, 0, 0);
	radio_pkt_rx_set(_radio.packet_rx[_radio.packet_rx_last]->pdu_data);
	radio_rssi_measure();
	if (_radio.scanner.filter_policy) {
		struct ll_filter *wl = ctrl_filter_get(
				1
				);
		radio_filter_configure(wl->enable_bitmask,
				wl->addr_type_bitmask,
				(u8_t *)wl->bdaddr);
	}
	remainder_us = radio_tmr_start(0,
			ticks_at_expire +
			( ((u32_t)(((u64_t) (300) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
			_radio.remainder_anchor);
	radio_tmr_end_capture();
	(void)(remainder_us);
	{
		ticker_status =
			ticker_start(0,
					0,
					4, ticks_at_expire,
					_radio.scanner.ticks_window +
					( ((u32_t)(((u64_t) (300) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
					0, 0,
					0, 0,
					event_stop, (void *)STATE_STOP,
					ticker_success_assert, (void *)6242);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		{
			u32_t ticker_status;
			ticker_status =
				ticker_job_idle_get(0,
						0,
						ticker_job_disable, 
						((void *)0)
						);
			if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
			;
		}
	}
	;
}
static inline void event_conn_upd_init(struct connection *conn,
		u16_t event_counter,
		u32_t ticks_at_expire,
		struct pdu_data *pdu_ctrl_tx,
		struct mayfly *mayfly_sched_offset,
		void (*fp_mayfly_select_or_use)(void *))
{
	conn->llcp.conn_upd.state = LLCP_CUI_STATE_INPROG;
	conn->llcp.conn_upd.instant =
		event_counter + conn->latency + 6;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_conn_update_ind);
	pdu_ctrl_tx->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_CONN_UPDATE_IND;
	pdu_ctrl_tx->payload.llctrl.ctrldata.conn_update_ind.win_size =
		conn->llcp.conn_upd.win_size;
	pdu_ctrl_tx->payload.llctrl.ctrldata.conn_update_ind.
		win_offset = conn->llcp.conn_upd.win_offset_us / 1250;
	pdu_ctrl_tx->payload.llctrl.ctrldata.conn_update_ind.interval =
		conn->llcp.conn_upd.interval;
	pdu_ctrl_tx->payload.llctrl.ctrldata.conn_update_ind.latency =
		conn->llcp.conn_upd.latency;
	pdu_ctrl_tx->payload.llctrl.ctrldata.conn_update_ind.timeout =
		conn->llcp.conn_upd.timeout;
	pdu_ctrl_tx->payload.llctrl.ctrldata.conn_update_ind.instant =
		conn->llcp.conn_upd.instant;
	(void)(ticks_at_expire);
	(void)(mayfly_sched_offset);
	(void)(fp_mayfly_select_or_use);
}
static inline u32_t event_conn_upd_prep(struct connection *conn,
		u16_t event_counter,
		u32_t ticks_at_expire)
{
	struct connection *conn_upd;
	u16_t instant_latency;
	conn_upd = _radio.conn_upd;
	if (!conn_upd) {
		_radio.conn_upd = conn;
	}
	instant_latency = (event_counter - conn->llcp.conn_upd.instant) &
		0xffff;
	if (conn->llcp.conn_upd.state != LLCP_CUI_STATE_INPROG) {
		struct radio_pdu_node_tx *node_tx;
		struct pdu_data *pdu_ctrl_tx;
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (!node_tx) {
			return 1;
		}
		pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
		event_conn_upd_init(conn, event_counter, ticks_at_expire,
				pdu_ctrl_tx, 
				((void *)0)
				, 
				((void *)0)
				);
		ctrl_tx_enqueue(conn, node_tx);
	} else if (instant_latency <= 0x7FFF) {
		struct radio_pdu_node_rx *radio_pdu_node_rx;
		struct pdu_data *pdu_data_rx;
		struct radio_le_conn_update_cmplt *radio_le_conn_update_cmplt;
		u32_t ticker_status;
		u32_t conn_interval_us;
		u32_t periodic_us;
		u32_t ticks_win_offset;
		u32_t ticks_slot_offset;
		u16_t conn_interval_old;
		u16_t conn_interval_new;
		u16_t latency;
		u32_t mayfly_was_enabled;
		conn->llcp_ack = conn->llcp_req;
		if ((conn->llcp_conn_param.req != conn->llcp_conn_param.ack) &&
				(conn->llcp_conn_param.state == LLCP_CPR_STATE_UPD)) {
			conn->llcp_conn_param.ack = conn->llcp_conn_param.req;
			conn->procedure_expire = 0;
		}
		_radio.ticker_id_prepare = 0;
		if (_radio.conn_upd == conn) {
			_radio.conn_upd = 
				((void *)0)
				;
		}
		if ((conn->llcp.conn_upd.interval !=
					conn->conn_interval) ||
				(conn->llcp.conn_upd.latency != conn->latency) ||
				(((u16_t)(((conn->llcp.conn_upd.timeout * 10000) + (conn->conn_interval * 1250) - 1) / (conn->conn_interval * 1250)))
				 !=
				 conn->supervision_reload)) {
			radio_pdu_node_rx = packet_rx_reserve_get(2);
			if (!(radio_pdu_node_rx)) { ; ; };
			radio_pdu_node_rx->hdr.handle = conn->handle;
			radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_CONN_UPDATE;
			pdu_data_rx =
				(struct pdu_data *)radio_pdu_node_rx->pdu_data;
			radio_le_conn_update_cmplt =
				(struct radio_le_conn_update_cmplt *)
				&pdu_data_rx->payload;
			radio_le_conn_update_cmplt->status = 0x00;
			radio_le_conn_update_cmplt->interval =
				conn->llcp.conn_upd.interval;
			radio_le_conn_update_cmplt->latency =
				conn->llcp.conn_upd.latency;
			radio_le_conn_update_cmplt->timeout =
				conn->llcp.conn_upd.timeout;
			packet_rx_enqueue();
		}
		if (conn->hdr.ticks_xtal_to_start & ((u32_t)1 << 31)) {
			u32_t ticks_prepare_to_start =
				(conn->hdr.ticks_active_to_start >
				 conn->hdr.ticks_preempt_to_start) ?
				conn->hdr.ticks_active_to_start :
				conn->hdr.ticks_preempt_to_start;
			conn->hdr.ticks_xtal_to_start &= ~((u32_t)1 << 31);
			ticks_at_expire -= (conn->hdr.ticks_xtal_to_start -
					ticks_prepare_to_start);
		}
		conn_interval_old = instant_latency * conn->conn_interval;
		latency = conn_interval_old /
			conn->llcp.conn_upd.interval;
		conn_interval_new = latency *
			conn->llcp.conn_upd.interval;
		if (conn_interval_new > conn_interval_old) {
			ticks_at_expire +=
				( ((u32_t)(((u64_t) ((conn_interval_new - conn_interval_old) * 1250) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
				;
		} else {
			ticks_at_expire -=
				( ((u32_t)(((u64_t) ((conn_interval_old - conn_interval_new) * 1250) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
				;
		}
		conn->latency_prepare -= (instant_latency - latency);
		ticks_slot_offset =
			(conn->hdr.ticks_active_to_start <
			 conn->hdr.ticks_xtal_to_start) ?
			conn->hdr.ticks_xtal_to_start :
			conn->hdr.ticks_active_to_start;
		conn_interval_us = conn->llcp.conn_upd.interval * 1250;
		periodic_us = conn_interval_us;
		if (conn->role) {
			conn->slave.window_widening_prepare_us -=
				conn->slave.window_widening_periodic_us *
				instant_latency;
			conn->slave.window_widening_periodic_us =
				(((gc_lookup_ppm[_radio.sca] +
				   gc_lookup_ppm[conn->slave.sca]) *
				  conn_interval_us) + (1000000 - 1)) / 1000000;
			conn->slave.window_widening_max_us =
				(conn_interval_us >> 1) - 150;
			conn->slave.window_size_prepare_us =
				conn->llcp.conn_upd.win_size * 1250;
			conn->slave.ticks_to_offset = 0;
			conn->slave.window_widening_prepare_us +=
				conn->slave.window_widening_periodic_us *
				latency;
			if (conn->slave.window_widening_prepare_us >
					conn->slave.window_widening_max_us) {
				conn->slave.window_widening_prepare_us =
					conn->slave.window_widening_max_us;
			}
			ticks_at_expire -=
				( ((u32_t)(((u64_t) (conn->slave.window_widening_periodic_us * latency) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
				;
			ticks_win_offset =
				( ((u32_t)(((u64_t) ((conn->llcp.conn_upd.win_offset_us / 1250) * 1250) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
				;
			periodic_us -=
				conn->slave.window_widening_periodic_us;
		} else {
			ticks_win_offset =
				( ((u32_t)(((u64_t) (conn->llcp.conn_upd.win_offset_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
			ticks_win_offset += 1;
		}
		conn->conn_interval = conn->llcp.conn_upd.interval;
		conn->latency = conn->llcp.conn_upd.latency;
		conn->supervision_reload =
			((u16_t)((((conn->llcp.conn_upd.timeout * 10 * 1000)) + (conn_interval_us) - 1) / (conn_interval_us)))
			;
		conn->procedure_reload =
			((u16_t)((((40 * 1000 * 1000)) + (conn_interval_us) - 1) / (conn_interval_us)));
		if (!conn->llcp.conn_upd.is_internal) {
			conn->supervision_expire = 0;
		}
		mayfly_was_enabled =
			mayfly_is_enabled(0,
					1);
		mayfly_enable(0,
				1, 0);
		ticker_status =
			ticker_stop(0,
					0,
					7 +
					conn->handle, ticker_success_assert,
					(void *)6590);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		ticker_status =
			ticker_start(0,
					0,
					7 +
					conn->handle,
					ticks_at_expire, ticks_win_offset,
					( ((u32_t)(((u64_t) (periodic_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
					( ( ((u64_t) (periodic_us) * 1000000000UL) - ((u64_t) ( ((u32_t)(((u64_t) (periodic_us) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ) * 30517578125UL) ) / 1000UL ),
					0,
					(ticks_slot_offset + conn->hdr.ticks_slot),
					conn->role ?
					event_slave_prepare : event_master_prepare,
					conn, ticker_success_assert,
					(void *)6606);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		if (mayfly_was_enabled) {
			mayfly_enable(0,
					1, 1);
		}
		return 0;
	}
	return 1;
}
static inline void event_ch_map_prep(struct connection *conn,
		u16_t event_counter)
{
	if (conn->llcp.chan_map.initiate) {
		struct radio_pdu_node_tx *node_tx;
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (node_tx) {
			struct pdu_data *pdu_ctrl_tx =
				(struct pdu_data *)node_tx->pdu_data;
			conn->llcp.chan_map.initiate = 0;
			conn->llcp.chan_map.instant =
				event_counter + conn->latency + 6;
			pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_ctrl_tx->len = 
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						)
				+
				sizeof(struct pdu_data_llctrl_chan_map_ind);
			pdu_ctrl_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_CHAN_MAP_IND;
			memcpy(&pdu_ctrl_tx->payload.llctrl.
					ctrldata.chan_map_ind.chm[0],
					&conn->llcp.chan_map.chm[0],
					sizeof(pdu_ctrl_tx->payload.
						llctrl.ctrldata.chan_map_ind.chm));
			pdu_ctrl_tx->payload.llctrl.ctrldata.chan_map_ind.instant =
				conn->llcp.chan_map.instant;
			ctrl_tx_enqueue(conn, node_tx);
		}
	} else if (((event_counter - conn->llcp.chan_map.instant) & 0xFFFF)
			<= 0x7FFF) {
		conn->llcp_ack = conn->llcp_req;
		memcpy(&conn->data_chan_map[0],
				&conn->llcp.chan_map.chm[0],
				sizeof(conn->data_chan_map));
		conn->data_chan_count =
			util_ones_count_get(&conn->data_chan_map[0],
					sizeof(conn->data_chan_map));
		conn->chm_update = 1;
	}
}
static inline void event_enc_reject_prep(struct connection *conn,
		struct pdu_data *pdu)
{
	pdu->ll_id = PDU_DATA_LLID_CTRL;
	if (conn->common.fex_valid &&
			(conn->llcp_features & (1UL << (2)))) {
		struct pdu_data_llctrl_reject_ext_ind *p;
		pdu->payload.llctrl.opcode =
			PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND;
		p = (void *)&pdu->payload.llctrl.ctrldata.reject_ext_ind;
		p->reject_opcode = PDU_DATA_LLCTRL_TYPE_ENC_REQ;
		p->error_code = conn->llcp.encryption.error_code;
		pdu->len = sizeof(struct pdu_data_llctrl_reject_ext_ind);
	} else {
		struct pdu_data_llctrl_reject_ind *p;
		pdu->payload.llctrl.opcode = PDU_DATA_LLCTRL_TYPE_REJECT_IND;
		p = (void *)&pdu->payload.llctrl.ctrldata.reject_ind;
		p->error_code = conn->llcp.encryption.error_code;
		pdu->len = sizeof(struct pdu_data_llctrl_reject_ind);
	}
	pdu->len += 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				)
		;
	conn->llcp.encryption.error_code = 0;
}
static inline void event_enc_prep(struct connection *conn)
{
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	if (conn->llcp.encryption.initiate) {
		return;
	}
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return;
	}
	pdu_ctrl_tx = (void *)node_tx->pdu_data;
	if (!conn->role) {
		ecb_encrypt(&conn->llcp.encryption.ltk[0],
				&conn->llcp.encryption.skd[0],
				((void *)0)
				, &conn->ccm_rx.key[0]);
		memcpy(&conn->ccm_tx.key[0], &conn->ccm_rx.key[0],
				sizeof(conn->ccm_tx.key));
		memcpy(&conn->ccm_tx.iv[0], &conn->ccm_rx.iv[0],
				sizeof(conn->ccm_tx.iv));
		conn->ccm_rx.counter = 0;
		conn->ccm_tx.counter = 0;
		conn->ccm_rx.direction = 0;
		conn->ccm_tx.direction = 1;
		conn->enc_rx = 1;
		start_enc_rsp_send(conn, pdu_ctrl_tx);
	}
	else if (!conn->pause_tx || conn->refresh) {
		if (conn->llcp.encryption.error_code) {
			event_enc_reject_prep(conn, pdu_ctrl_tx);
		}
		else {
			u8_t err;
			err = enc_rsp_send(conn);
			if (err) {
				mem_release(node_tx, &_radio.pkt_tx_ctrl_free);
				return;
			}
			ecb_encrypt(&conn->llcp.encryption.ltk[0],
					&conn->llcp.encryption.skd[0], 
					((void *)0)
					,
					&conn->ccm_rx.key[0]);
			memcpy(&conn->ccm_tx.key[0],
					&conn->ccm_rx.key[0],
					sizeof(conn->ccm_tx.key));
			memcpy(&conn->ccm_tx.iv[0], &conn->ccm_rx.iv[0],
					sizeof(conn->ccm_tx.iv));
			conn->ccm_rx.counter = 0;
			conn->ccm_tx.counter = 0;
			conn->ccm_rx.direction = 1;
			conn->ccm_tx.direction = 0;
			conn->enc_rx = 1;
			pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_ctrl_tx->len = 
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						)
				;
			pdu_ctrl_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_START_ENC_REQ;
		}
	} else {
		start_enc_rsp_send(_radio.conn_curr, pdu_ctrl_tx);
		_radio.conn_curr->pause_rx = 0;
		_radio.conn_curr->pause_tx = 0;
	}
	ctrl_tx_enqueue(conn, node_tx);
	conn->llcp_ack = conn->llcp_req;
}
static inline void event_fex_prep(struct connection *conn)
{
	struct radio_pdu_node_tx *node_tx;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (node_tx) {
		struct pdu_data *pdu_ctrl_tx =
			(struct pdu_data *)node_tx->pdu_data;
		conn->llcp_ack = conn->llcp_req;
		conn->llcp_features = ((1ULL << (0)) | (1ULL << (1)) | (1UL << (2)) | (1UL << (3)) | 0 | 0 | 0 | 0 | 0 | 0 | (1ULL << (14)) | (1ULL << (16)));
		pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
		pdu_ctrl_tx->len = 
			__builtin_offsetof (
					struct pdu_data_llctrl
					, 
					ctrldata
					) 
			+
			sizeof(struct pdu_data_llctrl_feature_req);
		pdu_ctrl_tx->payload.llctrl.opcode =
			!conn->role ?
			PDU_DATA_LLCTRL_TYPE_FEATURE_REQ :
			PDU_DATA_LLCTRL_TYPE_SLAVE_FEATURE_REQ;
		memset(&pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[0],
				0x00,
				sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features));
		pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[0] =
			conn->llcp_features & 0xFF;
		pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[1] =
			(conn->llcp_features >> 8) & 0xFF;
		pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[2] =
			(conn->llcp_features >> 16) & 0xFF;
		ctrl_tx_enqueue(conn, node_tx);
		conn->procedure_expire = conn->procedure_reload;
	}
}
static inline void event_vex_prep(struct connection *conn)
{
	if (conn->llcp_version.tx == 0) {
		struct radio_pdu_node_tx *node_tx;
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (node_tx) {
			struct pdu_data *pdu_ctrl_tx =
				(struct pdu_data *)node_tx->pdu_data;
			conn->llcp_ack = conn->llcp_req;
			conn->llcp_version.tx = 1;
			pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_ctrl_tx->len = 
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						)
				+
				sizeof(struct pdu_data_llctrl_version_ind);
			pdu_ctrl_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_VERSION_IND;
			pdu_ctrl_tx->payload.llctrl.ctrldata.version_ind.version_number =
				9;
			pdu_ctrl_tx->payload.llctrl.ctrldata.version_ind.company_id =
				0xFFFF;
			pdu_ctrl_tx->payload.llctrl.ctrldata.version_ind.sub_version_number =
				0xFFFF;
			ctrl_tx_enqueue(conn, node_tx);
			conn->procedure_expire = conn->procedure_reload;
		}
	} else if (conn->llcp_version.rx != 0) {
		struct radio_pdu_node_rx *radio_pdu_node_rx;
		struct pdu_data *pdu_ctrl_rx;
		conn->llcp_ack = conn->llcp_req;
		radio_pdu_node_rx = packet_rx_reserve_get(2);
		if (!(radio_pdu_node_rx)) { ; ; };
		radio_pdu_node_rx->hdr.handle = conn->handle;
		radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_DC_PDU;
		pdu_ctrl_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
		pdu_ctrl_rx->ll_id = PDU_DATA_LLID_CTRL;
		pdu_ctrl_rx->len = 
			__builtin_offsetof (
					struct pdu_data_llctrl
					, 
					ctrldata
					) 
			+
			sizeof(struct pdu_data_llctrl_version_ind);
		pdu_ctrl_rx->payload.llctrl.opcode =
			PDU_DATA_LLCTRL_TYPE_VERSION_IND;
		pdu_ctrl_rx->payload.llctrl.ctrldata.version_ind.version_number =
			conn->llcp_version.version_number;
		pdu_ctrl_rx->payload.llctrl.ctrldata.version_ind.company_id =
			conn->llcp_version.company_id;
		pdu_ctrl_rx->payload.llctrl.ctrldata.version_ind.sub_version_number =
			conn->llcp_version.sub_version_number;
		packet_rx_enqueue();
	} else {
		if (!(0)) { ; ; };
	}
}
static inline void event_conn_param_req(struct connection *conn,
		u16_t event_counter,
		u32_t ticks_at_expire)
{
	struct pdu_data_llctrl_conn_param_req *p;
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return;
	}
	conn->llcp_conn_param.state = LLCP_CPR_STATE_RSP_WAIT;
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_conn_param_req);
	pdu_ctrl_tx->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ;
	p = (void *)&pdu_ctrl_tx->payload.llctrl.ctrldata.conn_param_req;
	p->interval_min = conn->llcp_conn_param.interval;
	p->interval_max = conn->llcp_conn_param.interval;
	p->latency = conn->llcp_conn_param.latency;
	p->timeout = conn->llcp_conn_param.timeout;
	p->preferred_periodicity = 0;
	p->reference_conn_event_count = event_counter;
	p->offset0 = 0x0000;
	p->offset1 = 0xffff;
	p->offset2 = 0xffff;
	p->offset3 = 0xffff;
	p->offset4 = 0xffff;
	p->offset5 = 0xffff;
	ctrl_tx_enqueue(conn, node_tx);
	_radio.conn_upd = conn;
	conn->procedure_expire = conn->procedure_reload;
	(void)(ticks_at_expire);
}
static inline void event_conn_param_rsp(struct connection *conn)
{
	struct pdu_data_llctrl_conn_param_rsp *p;
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu;
	if (conn->llcp_conn_param.status) {
		struct pdu_data_llctrl_reject_ext_ind *p;
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (!node_tx) {
			return;
		}
		pdu = (struct pdu_data *)node_tx->pdu_data;
		pdu->ll_id = PDU_DATA_LLID_CTRL;
		pdu->payload.llctrl.opcode =
			PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND;
		pdu->len = 
			__builtin_offsetof (
					struct pdu_data_llctrl
					, 
					ctrldata
					) 
			+
			sizeof(struct pdu_data_llctrl_reject_ext_ind);
		p = (void *)
			&pdu->payload.llctrl.ctrldata.reject_ext_ind;
		p->reject_opcode = PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ;
		p->error_code = conn->llcp_conn_param.status;
		ctrl_tx_enqueue(conn, node_tx);
		conn->llcp_conn_param.ack = conn->llcp_conn_param.req;
		_radio.conn_upd = 
			((void *)0)
			;
		return;
	}
	if (!conn->role) {
		if (conn->llcp_req != conn->llcp_ack) {
			return;
		}
		conn->llcp_conn_param.state = LLCP_CPR_STATE_UPD;
		conn->llcp.conn_upd.win_size = 1;
		conn->llcp.conn_upd.win_offset_us = 0;
		conn->llcp.conn_upd.interval = conn->llcp_conn_param.interval;
		conn->llcp.conn_upd.latency = conn->llcp_conn_param.latency;
		conn->llcp.conn_upd.timeout = conn->llcp_conn_param.timeout;
		conn->llcp.conn_upd.state = LLCP_CUI_STATE_SELECT;
		conn->llcp.conn_upd.is_internal = !conn->llcp_conn_param.cmd;
		conn->llcp_type = LLCP_CONN_UPD;
		conn->llcp_ack--;
		return;
	}
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return;
	}
	pdu = (struct pdu_data *)node_tx->pdu_data;
	pdu->ll_id = PDU_DATA_LLID_CTRL;
	pdu->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_conn_param_rsp);
	pdu->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_CONN_PARAM_RSP;
	p = (void *)&pdu->payload.llctrl.ctrldata.conn_param_rsp;
	p->interval_min = conn->llcp_conn_param.interval;
	p->interval_max = conn->llcp_conn_param.interval;
	p->latency = conn->llcp_conn_param.latency;
	p->timeout = conn->llcp_conn_param.timeout;
	p->preferred_periodicity = conn->llcp_conn_param.preferred_periodicity;
	p->reference_conn_event_count =
		conn->llcp_conn_param.reference_conn_event_count;
	p->offset0 = conn->llcp_conn_param.offset0;
	p->offset1 = conn->llcp_conn_param.offset1;
	p->offset2 = conn->llcp_conn_param.offset2;
	p->offset3 = conn->llcp_conn_param.offset3;
	p->offset4 = conn->llcp_conn_param.offset4;
	p->offset5 = conn->llcp_conn_param.offset5;
	ctrl_tx_enqueue(conn, node_tx);
	conn->llcp_conn_param.ack = conn->llcp_conn_param.req;
	_radio.conn_upd = 
		((void *)0)
		;
}
static inline void event_conn_param_app_req(struct connection *conn)
{
	struct pdu_data_llctrl_conn_param_req *p;
	struct radio_pdu_node_rx *node_rx;
	struct pdu_data *pdu;
	if (conn->pause_tx) {
		return;
	}
	node_rx = packet_rx_reserve_get(2);
	if (!node_rx) {
		return;
	}
	conn->llcp_conn_param.state = LLCP_CPR_STATE_APP_WAIT;
	node_rx->hdr.handle = conn->handle;
	node_rx->hdr.type = NODE_RX_TYPE_DC_PDU;
	pdu = (struct pdu_data *)node_rx->pdu_data;
	pdu->ll_id = PDU_DATA_LLID_CTRL;
	pdu->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_conn_param_req);
	pdu->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ;
	p = (void *) &pdu->payload.llctrl.ctrldata.conn_param_req;
	p->interval_min = conn->llcp_conn_param.interval;
	p->interval_max = conn->llcp_conn_param.interval;
	p->latency = conn->llcp_conn_param.latency;
	p->timeout = conn->llcp_conn_param.timeout;
	packet_rx_enqueue();
}
static inline void event_conn_param_prep(struct connection *conn,
		u16_t event_counter,
		u32_t ticks_at_expire)
{
	struct connection *conn_upd;
	conn_upd = _radio.conn_upd;
	if (conn_upd && (conn_upd != conn)) {
		return;
	}
	switch (conn->llcp_conn_param.state) {
		case LLCP_CPR_STATE_REQ:
			event_conn_param_req(conn, event_counter, ticks_at_expire);
			break;
		case LLCP_CPR_STATE_RSP:
			event_conn_param_rsp(conn);
			break;
		case LLCP_CPR_STATE_APP_REQ:
			event_conn_param_app_req(conn);
			break;
		case LLCP_CPR_STATE_APP_WAIT:
		case LLCP_CPR_STATE_RSP_WAIT:
		case LLCP_CPR_STATE_UPD:
			break;
		default:
			if (!(0)) { ; ; };
			break;
	}
}
static inline void event_phy_req_prep(struct connection *conn)
{
	switch (conn->llcp_phy.state) {
		case 0:
			{
				struct pdu_data_llctrl_phy_req_rsp *pr;
				struct radio_pdu_node_tx *node_tx;
				struct pdu_data *pdu_ctrl_tx;
				node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
				if (!node_tx) {
					break;
				}
				conn->llcp_phy.state = 1;
				conn->phy_pref_tx = conn->llcp_phy.tx;
				conn->phy_pref_rx = conn->llcp_phy.rx;
				conn->phy_pref_flags = conn->llcp_phy.flags;
				pdu_ctrl_tx = (struct pdu_data *) node_tx->pdu_data;
				pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
				pdu_ctrl_tx->len = 
					__builtin_offsetof (
							struct pdu_data_llctrl
							, 
							ctrldata
							) 
					+
					sizeof(struct pdu_data_llctrl_phy_req_rsp);
				pdu_ctrl_tx->payload.llctrl.opcode =
					PDU_DATA_LLCTRL_TYPE_PHY_REQ;
				pr = (struct pdu_data_llctrl_phy_req_rsp *)
					&pdu_ctrl_tx->payload.llctrl.ctrldata.phy_req;
				pr->tx_phys = conn->llcp_phy.tx;
				pr->rx_phys = conn->llcp_phy.rx;
				ctrl_tx_enqueue(conn, node_tx);
				conn->procedure_expire = conn->procedure_reload;
			}
			break;
		case 3:
			{
				conn->llcp_phy.ack = conn->llcp_phy.req;
				if (conn->llcp_phy.tx & (1UL << (1))) {
					conn->llcp_phy.tx = (1UL << (1));
				} else if (conn->llcp_phy.tx & (1UL << (0))) {
					conn->llcp_phy.tx = (1UL << (0));
				} else if (conn->llcp_phy.tx & (1UL << (2))) {
					conn->llcp_phy.tx = (1UL << (2));
				} else {
					conn->llcp_phy.tx = 0;
				}
				if (conn->llcp_phy.rx & (1UL << (1))) {
					conn->llcp_phy.rx = (1UL << (1));
				} else if (conn->llcp_phy.rx & (1UL << (0))) {
					conn->llcp_phy.rx = (1UL << (0));
				} else if (conn->llcp_phy.rx & (1UL << (2))) {
					conn->llcp_phy.rx = (1UL << (2));
				} else {
					conn->llcp_phy.rx = 0;
				}
				if (conn->llcp_phy.tx != conn->phy_tx) {
					conn->llcp.phy_upd_ind.tx = conn->llcp_phy.tx;
				} else {
					conn->llcp.phy_upd_ind.tx = 0;
				}
				if (conn->llcp_phy.rx != conn->phy_rx) {
					conn->llcp.phy_upd_ind.rx = conn->llcp_phy.rx;
				} else {
					conn->llcp.phy_upd_ind.rx = 0;
				}
				conn->llcp.phy_upd_ind.initiate = 1;
				conn->llcp.phy_upd_ind.cmd = conn->llcp_phy.cmd;
				conn->llcp_type = LLCP_PHY_UPD;
				conn->llcp_ack--;
			}
			break;
		case 1:
		case 2:
			break;
		default:
			if (!(0)) { ; ; };
			break;
	}
}
static inline void event_phy_upd_ind_prep(struct connection *conn,
		u16_t event_counter)
{
	if (conn->llcp.phy_upd_ind.initiate) {
		struct radio_pdu_node_tx *node_tx;
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (node_tx) {
			struct pdu_data *pdu_ctrl_tx = (struct pdu_data *)
				node_tx->pdu_data;
			struct pdu_data_llctrl_phy_upd_ind *p;
			conn->llcp.phy_upd_ind.initiate = 0;
			if (!((conn->llcp.phy_upd_ind.tx |
							conn->llcp.phy_upd_ind.rx) & 0x07)) {
				conn->llcp_ack = conn->llcp_req;
				conn->llcp.phy_upd_ind.instant = 0;
				if (conn->llcp.phy_upd_ind.cmd) {
					struct radio_pdu_node_rx *node_rx;
					struct radio_le_phy_upd_cmplt *p;
					struct pdu_data *pdu_data;
					node_rx = packet_rx_reserve_get(2);
					if (!(node_rx)) { ; ; };
					node_rx->hdr.handle = conn->handle;
					node_rx->hdr.type =
						NODE_RX_TYPE_PHY_UPDATE;
					pdu_data = (void *)&node_rx->pdu_data;
					p = (void *)&pdu_data->payload;
					p->status = 0;
					p->tx = conn->phy_tx;
					p->rx = conn->phy_rx;
					packet_rx_enqueue();
				}
			} else {
				conn->llcp.phy_upd_ind.instant = event_counter +
					conn->latency +
					6;
			}
			pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_ctrl_tx->len = 
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						)
				+
				sizeof(struct pdu_data_llctrl_phy_upd_ind);
			pdu_ctrl_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_PHY_UPD_IND;
			p = &pdu_ctrl_tx->payload.llctrl.ctrldata.phy_upd_ind;
			p->m_to_s_phy = conn->llcp.phy_upd_ind.tx;
			p->s_to_m_phy = conn->llcp.phy_upd_ind.rx;
			p->instant = conn->llcp.phy_upd_ind.instant;
			ctrl_tx_enqueue(conn, node_tx);
		}
	} else if (((event_counter - conn->llcp.phy_upd_ind.instant) & 0xFFFF)
			<= 0x7FFF) {
		struct radio_pdu_node_rx *node_rx;
		struct radio_le_phy_upd_cmplt *p;
		struct pdu_data *pdu_data;
		u8_t old_tx, old_rx;
		conn->llcp_ack = conn->llcp_req;
		old_tx = conn->phy_tx;
		old_rx = conn->phy_rx;
		if (conn->llcp.phy_upd_ind.tx) {
			conn->phy_tx = conn->llcp.phy_upd_ind.tx;
		}
		if (conn->llcp.phy_upd_ind.rx) {
			conn->phy_rx = conn->llcp.phy_upd_ind.rx;
		}
		conn->phy_flags = conn->phy_pref_flags;
		if (!conn->llcp.phy_upd_ind.cmd && (conn->phy_tx == old_tx) &&
				(conn->phy_rx == old_rx)) {
			return;
		}
		node_rx = packet_rx_reserve_get(2);
		if (!(node_rx)) { ; ; };
		node_rx->hdr.handle = conn->handle;
		node_rx->hdr.type = NODE_RX_TYPE_PHY_UPDATE;
		pdu_data = (struct pdu_data *)&node_rx->pdu_data;
		p = (struct radio_le_phy_upd_cmplt *)&pdu_data->payload;
		p->status = 0;
		p->tx = conn->phy_tx;
		p->rx = conn->phy_rx;
		packet_rx_enqueue();
	}
}
static void event_connection_prepare(u32_t ticks_at_expire,
		u32_t remainder, u16_t lazy,
		struct connection *conn)
{
	u16_t event_counter;
	if (!(!_radio.ticker_id_prepare)) { ; ; };
	_radio.ticker_id_prepare = 7 +
		conn->handle;
	if (conn->role) {
		conn->slave.window_widening_prepare_us +=
			conn->slave.window_widening_periodic_us * (lazy + 1);
		if (conn->slave.window_widening_prepare_us >
				conn->slave.window_widening_max_us) {
			conn->slave.window_widening_prepare_us =
				conn->slave.window_widening_max_us;
		}
	}
	conn->latency_prepare += lazy;
	event_counter = conn->event_counter + conn->latency_prepare;
	if (conn->llcp_ack == conn->llcp_req) {
		if (conn->llcp_conn_param.ack != conn->llcp_conn_param.req) {
			event_stop(0, 0, 0, (void *)STATE_ABORT);
			event_conn_param_prep(conn, event_counter,
					ticks_at_expire);
		}
		if (conn->llcp_phy.ack != conn->llcp_phy.req) {
			event_stop(0, 0, 0, (void *)STATE_ABORT);
			event_phy_req_prep(conn);
		}
	}
	if (conn->llcp_ack != conn->llcp_req) {
		event_stop(0, 0, 0, (void *)STATE_ABORT);
		switch (conn->llcp_type) {
			case LLCP_CONN_UPD:
				if (event_conn_upd_prep(conn, event_counter,
							ticks_at_expire) == 0) {
					return;
				}
				break;
			case LLCP_CHAN_MAP:
				event_ch_map_prep(conn, event_counter);
				break;
			case LLCP_ENCRYPTION:
				event_enc_prep(conn);
				break;
			case LLCP_FEATURE_EXCHANGE:
				event_fex_prep(conn);
				break;
			case LLCP_VERSION_EXCHANGE:
				event_vex_prep(conn);
				break;
			case LLCP_PHY_UPD:
				event_phy_upd_ind_prep(conn, event_counter);
				break;
			default:
				if (!(0)) { ; ; };
				break;
		}
	}
	if (conn->llcp_terminate.ack != conn->llcp_terminate.req) {
		struct radio_pdu_node_tx *node_tx;
		event_stop(0, 0, 0, (void *)STATE_ABORT);
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (node_tx) {
			struct pdu_data *pdu_ctrl_tx =
				(struct pdu_data *)node_tx->pdu_data;
			conn->llcp_terminate.ack = conn->llcp_terminate.req;
			pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_ctrl_tx->len =
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						) 
				+
				sizeof(struct pdu_data_llctrl_terminate_ind);
			pdu_ctrl_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_TERMINATE_IND;
			pdu_ctrl_tx->payload.llctrl.ctrldata.terminate_ind.
				error_code = conn->llcp_terminate.reason_own;
			ctrl_tx_enqueue(conn, node_tx);
			conn->procedure_expire = conn->supervision_reload;
			if (conn->procedure_expire <= 1) {
				conn->procedure_expire++;
			}
		}
	}
	event_common_prepare(ticks_at_expire, remainder,
			&conn->hdr.ticks_xtal_to_start,
			&conn->hdr.ticks_active_to_start,
			conn->hdr.ticks_preempt_to_start,
			(7 + conn->handle),
			conn->role ? event_slave : event_master,
			conn);
	conn->event_counter = event_counter + 1;
}
static void connection_configure(struct connection *conn)
{
	adv_scan_conn_configure();
	radio_aa_set(conn->access_addr);
	radio_crc_configure(((0x5bUL) | ((0x06UL) << 8) | ((0x00UL) << 16)),
			(((u32_t)conn->crc_init[2] << 16) |
			 ((u32_t)conn->crc_init[1] << 8) |
			 ((u32_t)conn->crc_init[0])));
}
static void event_slave_prepare(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	;
	event_connection_prepare(ticks_at_expire, remainder, lazy, context);
	;
}
static void event_slave(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context)
{
	struct connection *conn;
	u8_t data_chan_use = 0;
	u32_t remainder_us;
	u32_t hcto;
	(void)(remainder);
	(void)(lazy);
	;
	if (!(_radio.role == ROLE_NONE)) { ; ; };
	conn = (struct connection *)context;
	if (!(_radio.ticker_id_prepare == (7 + conn->handle))) { ; ; }
	;
	_radio.role = ROLE_SLAVE;
	_radio.state = STATE_RX;
	_radio.ticker_id_prepare = 0;
	_radio.ticker_id_event =
		(7 + conn->handle);
	_radio.ticks_anchor = ticks_at_expire;
	_radio.packet_counter = 0;
	_radio.crc_expire = 0;
	_radio.conn_curr = conn;
	conn->latency_event = conn->latency_prepare;
	conn->latency_prepare = 0;
	connection_configure(conn);
	radio_tmr_tifs_set(150);
	radio_switch_complete_and_tx(conn->phy_rx, 0, conn->phy_tx,
			conn->phy_flags);
	rx_packet_set(conn, (struct pdu_data *)
			_radio.packet_rx[_radio.packet_rx_last]->pdu_data);
	if (conn->data_chan_sel) {
		data_chan_use = chan_sel_2(conn->event_counter - 1,
				conn->data_chan_id,
				&conn->data_chan_map[0],
				conn->data_chan_count);
	} else {
		data_chan_use = chan_sel_1(&conn->data_chan_use,
				conn->data_chan_hop,
				conn->latency_event,
				&conn->data_chan_map[0],
				conn->data_chan_count);
	}
	chan_set(data_chan_use);
	conn->slave.window_widening_event_us +=
		conn->slave.window_widening_prepare_us;
	conn->slave.window_widening_prepare_us = 0;
	if (conn->slave.window_widening_event_us >
			conn->slave.window_widening_max_us) {
		conn->slave.window_widening_event_us =
			conn->slave.window_widening_max_us;
	}
	conn->slave.window_size_event_us +=
		conn->slave.window_size_prepare_us;
	conn->slave.window_size_prepare_us = 0;
	remainder_us =
		radio_tmr_start(0, ticks_at_expire +
				( ((u32_t)(((u64_t) (300) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
				_radio.remainder_anchor);
	radio_tmr_aa_capture();
	radio_tmr_aa_save(0);
	hcto = remainder_us + 16 +
		(16 << 2) +
		(conn->slave.window_widening_event_us << 1) +
		conn->slave.window_size_event_us;
	hcto += radio_rx_ready_delay_get(conn->phy_rx);
	hcto += addr_us_get(conn->phy_rx);
	hcto += radio_rx_chain_delay_get(conn->phy_rx, 1);
	radio_tmr_hcto_configure(hcto);
	{
		u32_t ticker_status;
		ticker_status =
			ticker_job_idle_get(0,
					0,
					ticker_job_disable, 
					((void *)0)
					);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	}
	packet_tx_enqueue(2);
	;
}
static void event_master_prepare(u32_t ticks_at_expire, u32_t remainder,
		u16_t lazy, void *context)
{
	;
	event_connection_prepare(ticks_at_expire, remainder, lazy, context);
	;
}
static void event_master(u32_t ticks_at_expire, u32_t remainder, u16_t lazy,
		void *context)
{
	struct pdu_data *pdu_data_tx;
	struct connection *conn;
	u8_t data_chan_use = 0;
	u32_t remainder_us;
	(void)(remainder);
	(void)(lazy);
	;
	if (!(_radio.role == ROLE_NONE)) { ; ; };
	conn = (struct connection *)context;
	if (!(_radio.ticker_id_prepare == (7 + conn->handle))) { ; ; }
	;
	_radio.role = ROLE_MASTER;
	_radio.state = STATE_TX;
	_radio.ticker_id_prepare = 0;
	_radio.ticker_id_event =
		(7 + conn->handle);
	_radio.ticks_anchor = ticks_at_expire;
	_radio.packet_counter = 0;
	_radio.crc_expire = 0;
	_radio.conn_curr = conn;
	conn->latency_event = conn->latency_prepare;
	conn->latency_prepare = 0;
	packet_tx_enqueue(2);
	prepare_pdu_data_tx(conn, &pdu_data_tx);
	pdu_data_tx->sn = conn->sn;
	pdu_data_tx->nesn = conn->nesn;
	connection_configure(conn);
	radio_tmr_tifs_set(150);
	radio_switch_complete_and_rx(conn->phy_rx);
	tx_packet_set(conn, pdu_data_tx);
	if (conn->data_chan_sel) {
		data_chan_use = chan_sel_2(conn->event_counter - 1,
				conn->data_chan_id,
				&conn->data_chan_map[0],
				conn->data_chan_count);
	} else {
		data_chan_use = chan_sel_1(&conn->data_chan_use,
				conn->data_chan_hop,
				conn->latency_event,
				&conn->data_chan_map[0],
				conn->data_chan_count);
	}
	chan_set(data_chan_use);
	remainder_us = radio_tmr_start(1,
			ticks_at_expire +
			( ((u32_t)(((u64_t) (300) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
			_radio.remainder_anchor);
	radio_tmr_end_capture();
	(void)(remainder_us);
	{
		u32_t ticker_status;
		ticker_status =
			ticker_job_idle_get(0,
					0,
					ticker_job_disable, 
					((void *)0)
					);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	}
	;
}
static void rx_packet_set(struct connection *conn, struct pdu_data *pdu_data_rx)
{
	u16_t max_rx_octets;
	u8_t phy;
	max_rx_octets = 27;
	phy = conn->phy_rx;
	radio_phy_set(phy, 0);
	if (conn->enc_rx) {
		radio_pkt_configure(8, (max_rx_octets + 4), (phy << 1) | 0x01);
		radio_pkt_rx_set(radio_ccm_rx_pkt_set(&conn->ccm_rx, phy,
					pdu_data_rx));
	} else {
		radio_pkt_configure(8, max_rx_octets, (phy << 1) | 0x01);
		radio_pkt_rx_set(pdu_data_rx);
	}
}
static void tx_packet_set(struct connection *conn, struct pdu_data *pdu_data_tx)
{
	u16_t max_tx_octets;
	u8_t phy, flags;
	max_tx_octets = 27;
	phy = conn->phy_tx;
	flags = conn->phy_flags;
	radio_phy_set(phy, flags);
	if (conn->enc_tx) {
		radio_pkt_configure(8, (max_tx_octets + 4), (phy << 1) | 0x01);
		radio_pkt_tx_set(radio_ccm_tx_pkt_set(&conn->ccm_tx,
					pdu_data_tx));
	} else {
		radio_pkt_configure(8, max_tx_octets, (phy << 1) | 0x01);
		radio_pkt_tx_set(pdu_data_tx);
	}
}
static void prepare_pdu_data_tx(struct connection *conn,
		struct pdu_data **pdu_data_tx)
{
	struct pdu_data *_pdu_data_tx;
	if (
			conn->empty ||
			!conn->pkt_tx_head ||
			(conn->pause_tx && (conn->pkt_tx_head != conn->pkt_tx_ctrl))) {
		_pdu_data_tx = empty_tx_enqueue(conn);
	} else {
		u16_t max_tx_octets;
		_pdu_data_tx = (void *)(conn->pkt_tx_head->pdu_data +
				conn->packet_tx_head_offset);
		if (!conn->packet_tx_head_len) {
			conn->packet_tx_head_len = _pdu_data_tx->len;
		}
		if (conn->packet_tx_head_offset) {
			_pdu_data_tx->ll_id = PDU_DATA_LLID_DATA_CONTINUE;
		}
		_pdu_data_tx->len = conn->packet_tx_head_len -
			conn->packet_tx_head_offset;
		_pdu_data_tx->md = 0;
		max_tx_octets = 27;
		if (_pdu_data_tx->len > max_tx_octets) {
			_pdu_data_tx->len = max_tx_octets;
			_pdu_data_tx->md = 1;
		}
		if (conn->pkt_tx_head->next) {
			_pdu_data_tx->md = 1;
		}
		if (!conn->pkt_tx_ctrl &&
				(conn->pkt_tx_head != conn->pkt_tx_data)) {
			conn->pkt_tx_ctrl = conn->pkt_tx_ctrl_last =
				conn->pkt_tx_head;
		}
	}
	_pdu_data_tx->rfu = 0;
	_pdu_data_tx->resv = 0;
	*pdu_data_tx = _pdu_data_tx;
}
static void packet_rx_allocate(u8_t max)
{
	u8_t acquire;
	if (max > _radio.link_rx_data_quota) {
		max = _radio.link_rx_data_quota;
	}
	acquire = _radio.packet_rx_acquire + 1;
	if (acquire == _radio.packet_rx_count) {
		acquire = 0;
	}
	while ((max--) && (acquire != _radio.packet_rx_last)) {
		void *link;
		struct radio_pdu_node_rx *radio_pdu_node_rx;
		link = mem_acquire(&_radio.link_rx_free);
		if (!link) {
			break;
		}
		radio_pdu_node_rx = mem_acquire(&_radio.pkt_rx_data_free);
		if (!radio_pdu_node_rx) {
			mem_release(link, &_radio.link_rx_free);
			break;
		}
		radio_pdu_node_rx->hdr.onion.link = link;
		_radio.packet_rx[_radio.packet_rx_acquire] = radio_pdu_node_rx;
		_radio.packet_rx_acquire = acquire;
		acquire = _radio.packet_rx_acquire + 1;
		if (acquire == _radio.packet_rx_count) {
			acquire = 0;
		}
		_radio.link_rx_data_quota--;
	}
}
static inline u8_t packet_rx_acquired_count_get(void)
{
	if (_radio.packet_rx_acquire >=
			_radio.packet_rx_last) {
		return (_radio.packet_rx_acquire -
				_radio.packet_rx_last);
	} else {
		return (_radio.packet_rx_count -
				_radio.packet_rx_last +
				_radio.packet_rx_acquire);
	}
}
static inline struct radio_pdu_node_rx *packet_rx_reserve_get(u8_t count)
{
	if (count > packet_rx_acquired_count_get()) {
		return 0;
	}
	return _radio.packet_rx[_radio.packet_rx_last];
}
static void packet_rx_callback(void)
{
	radio_event_callback();
}
static void packet_rx_enqueue(void)
{
	struct radio_pdu_node_rx *radio_pdu_node_rx;
	memq_link_t *link;
	u8_t last;
	if (!(_radio.packet_rx_last != _radio.packet_rx_acquire)) { ; ; };
	radio_pdu_node_rx = _radio.packet_rx[_radio.packet_rx_last];
	link = radio_pdu_node_rx->hdr.onion.link;
	radio_pdu_node_rx->hdr.onion.packet_release_last =
		_radio.packet_release_last;
	last = _radio.packet_rx_last + 1;
	if (last == _radio.packet_rx_count) {
		last = 0;
	}
	_radio.packet_rx_last = last;
	link = memq_enqueue(link, radio_pdu_node_rx,
			(void *)&_radio.link_rx_tail);
	if (!(link)) { ; ; };
	packet_rx_callback();
}
static void packet_tx_enqueue(u8_t max)
{
	while ((max--) && (_radio.packet_tx_first != _radio.packet_tx_last)) {
		struct pdu_data_q_tx *pdu_data_q_tx;
		struct radio_pdu_node_tx *node_tx_new;
		struct connection *conn;
		u8_t first;
		pdu_data_q_tx = &_radio.pkt_tx[_radio.packet_tx_first];
		node_tx_new = pdu_data_q_tx->node_tx;
		node_tx_new->next = 
			((void *)0)
			;
		conn = mem_get(_radio.conn_pool, (((u32_t)(sizeof(struct connection))+3) & (~((u32_t)3))),
				pdu_data_q_tx->handle);
		if (conn->handle == pdu_data_q_tx->handle) {
			if (conn->pkt_tx_data == 0) {
				conn->pkt_tx_data = node_tx_new;
				if (conn->pkt_tx_head == 0) {
					conn->pkt_tx_head = node_tx_new;
					conn->pkt_tx_last = 
						((void *)0)
						;
				}
			}
			if (conn->pkt_tx_last) {
				conn->pkt_tx_last->next = node_tx_new;
			}
			conn->pkt_tx_last = node_tx_new;
		} else {
			struct pdu_data *pdu_data_tx;
			pdu_data_tx = (struct pdu_data *)node_tx_new->pdu_data;
			pdu_data_tx->ll_id = PDU_DATA_LLID_RESV;
			pdu_node_tx_release(pdu_data_q_tx->handle, node_tx_new);
		}
		first = _radio.packet_tx_first + 1;
		if (first == _radio.packet_tx_count) {
			first = 0;
		}
		_radio.packet_tx_first = first;
	}
}
static struct pdu_data *empty_tx_enqueue(struct connection *conn)
{
	struct pdu_data *pdu_data_tx;
	conn->empty = 1;
	pdu_data_tx = (struct pdu_data *)radio_pkt_empty_get();
	pdu_data_tx->ll_id = PDU_DATA_LLID_DATA_CONTINUE;
	pdu_data_tx->len = 0;
	if (conn->pkt_tx_head) {
		pdu_data_tx->md = 1;
	} else {
		pdu_data_tx->md = 0;
	}
	return pdu_data_tx;
}
static void ctrl_tx_last_enqueue(struct connection *conn,
		struct radio_pdu_node_tx *node_tx)
{
	node_tx->next = conn->pkt_tx_ctrl_last->next;
	conn->pkt_tx_ctrl_last->next = node_tx;
	conn->pkt_tx_ctrl_last = node_tx;
}
static void ctrl_tx_enqueue(struct connection *conn,
		struct radio_pdu_node_tx *node_tx)
{
	if (
			!conn->empty &&
			conn->pkt_tx_head &&
			!conn->pause_tx) {
		if (conn->pkt_tx_head == conn->pkt_tx_data) {
			conn->pkt_tx_data = conn->pkt_tx_data->next;
		}
		if (!conn->pkt_tx_ctrl) {
			node_tx->next = conn->pkt_tx_head->next;
			conn->pkt_tx_head->next = node_tx;
			conn->pkt_tx_ctrl = node_tx;
			conn->pkt_tx_ctrl_last = node_tx;
		} else {
			ctrl_tx_last_enqueue(conn, node_tx);
		}
	} else {
		if (!conn->pkt_tx_ctrl) {
			node_tx->next = conn->pkt_tx_head;
			conn->pkt_tx_head = node_tx;
			conn->pkt_tx_ctrl = node_tx;
			conn->pkt_tx_ctrl_last = node_tx;
		} else {
			ctrl_tx_last_enqueue(conn, node_tx);
		}
	}
	if (node_tx->next == 0) {
		conn->pkt_tx_last = node_tx;
	}
}
static void ctrl_tx_sec_enqueue(struct connection *conn,
		struct radio_pdu_node_tx *node_tx)
{
	if (conn->pause_tx) {
		if (!conn->pkt_tx_ctrl) {
			node_tx->next = conn->pkt_tx_head;
			conn->pkt_tx_head = node_tx;
		} else {
			node_tx->next = conn->pkt_tx_ctrl_last->next;
			conn->pkt_tx_ctrl_last->next = node_tx;
		}
	} else {
		ctrl_tx_enqueue(conn, node_tx);
	}
}
static void pdu_node_tx_release(u16_t handle,
		struct radio_pdu_node_tx *node_tx)
{
	u8_t last;
	last = _radio.packet_release_last + 1;
	if (last == _radio.packet_tx_count) {
		last = 0;
	}
	if (!(last != _radio.packet_release_first)) { ; ; };
	_radio.pkt_release[_radio.packet_release_last].handle = handle;
	_radio.pkt_release[_radio.packet_release_last].node_tx = node_tx;
	_radio.packet_release_last = last;
	packet_rx_callback();
}
static void connection_release(struct connection *conn)
{
	u32_t ticker_status;
	mayfly_enable(0, 1, 1);
	ticker_status =
		ticker_stop(0,
				0,
				(7 + conn->handle),
				ticker_success_assert, (void *)8744);
	if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
	;
	if ((_radio.state == STATE_ABORT) &&
			(_radio.ticker_id_prepare == (7 +
						      conn->handle))) {
		_radio.ticker_id_prepare = 0;
		ticker_status =
			ticker_stop(0,
					0,
					1,
					ticker_success_assert, (void *)8761);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
		ticker_status =
			ticker_stop(0,
					0,
					0,
					ticker_success_assert, (void *)8768);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	}
	while ((conn->pkt_tx_head != conn->pkt_tx_ctrl) &&
			(conn->pkt_tx_head != conn->pkt_tx_data)) {
		struct radio_pdu_node_tx *node_tx;
		struct pdu_data *pdu_data_tx;
		node_tx = conn->pkt_tx_head;
		pdu_data_tx = (struct pdu_data *)node_tx->pdu_data;
		pdu_data_tx->ll_id = PDU_DATA_LLID_RESV;
		conn->pkt_tx_head = conn->pkt_tx_head->next;
		pdu_node_tx_release(conn->handle, node_tx);
	}
	while ((conn->pkt_tx_head) &&
			(conn->pkt_tx_head != conn->pkt_tx_data)) {
		void *release;
		release = conn->pkt_tx_head;
		conn->pkt_tx_head = conn->pkt_tx_head->next;
		conn->pkt_tx_ctrl = conn->pkt_tx_head;
		mem_release(release, &_radio.pkt_tx_ctrl_free);
	}
	conn->pkt_tx_ctrl = 
		((void *)0)
		;
	conn->pkt_tx_ctrl_last = 
		((void *)0)
		;
	while (conn->pkt_tx_head) {
		struct radio_pdu_node_tx *node_tx;
		struct pdu_data *pdu_data_tx;
		node_tx = conn->pkt_tx_head;
		pdu_data_tx = (struct pdu_data *)node_tx->pdu_data;
		pdu_data_tx->ll_id = PDU_DATA_LLID_RESV;
		conn->pkt_tx_head = conn->pkt_tx_head->next;
		conn->pkt_tx_data = conn->pkt_tx_head;
		pdu_node_tx_release(conn->handle, node_tx);
	}
	conn->handle = 0xffff;
	if (_radio.conn_upd == conn) {
		_radio.conn_upd = 
			((void *)0)
			;
	}
}
static void terminate_ind_rx_enqueue(struct connection *conn, u8_t reason)
{
	struct radio_pdu_node_rx *radio_pdu_node_rx;
	memq_link_t *link;
	radio_pdu_node_rx = (void *)&conn->llcp_terminate.radio_pdu_node_rx;
	if (!(radio_pdu_node_rx->hdr.onion.link)) { ; ; };
	radio_pdu_node_rx->hdr.handle = conn->handle;
	radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_TERMINATE;
	*((u8_t *)radio_pdu_node_rx->pdu_data) = reason;
	link = radio_pdu_node_rx->hdr.onion.link;
	radio_pdu_node_rx->hdr.onion.packet_release_last =
		_radio.packet_release_last;
	link = memq_enqueue(link, radio_pdu_node_rx,
			(void *)&_radio.link_rx_tail);
	if (!(link)) { ; ; };
	packet_rx_callback();
}
static u32_t conn_update(struct connection *conn, struct pdu_data *pdu_data_rx)
{
	if (((pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.instant -
					conn->event_counter) & 0xFFFF) > 0x7FFF) {
		return 1;
	}
	if (!(conn->llcp_req == conn->llcp_ack)) { ; ; };
	if (_radio.conn_upd == 0) {
		if (!(conn->role)) { ; ; };
		_radio.conn_upd = conn;
	}
	conn->llcp.conn_upd.win_size =
		pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.win_size;
	conn->llcp.conn_upd.win_offset_us =
		pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.win_offset *
		1250;
	conn->llcp.conn_upd.interval =
		pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.interval;
	conn->llcp.conn_upd.latency =
		pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.latency;
	conn->llcp.conn_upd.timeout =
		pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.timeout;
	conn->llcp.conn_upd.instant =
		pdu_data_rx->payload.llctrl.ctrldata.conn_update_ind.instant;
	conn->llcp.conn_upd.state = LLCP_CUI_STATE_INPROG;
	conn->llcp.conn_upd.is_internal = 0;
	conn->llcp_type = LLCP_CONN_UPD;
	conn->llcp_ack--;
	if ((conn->llcp_conn_param.req != conn->llcp_conn_param.ack) &&
			(conn->llcp_conn_param.state == LLCP_CPR_STATE_RSP_WAIT)) {
		conn->llcp_conn_param.ack = conn->llcp_conn_param.req;
	}
	return 0;
}
static u32_t chan_map_update(struct connection *conn,
		struct pdu_data *pdu_data_rx)
{
	if (((pdu_data_rx->payload.llctrl.ctrldata.chan_map_ind.instant -
					conn->event_counter) & 0xffff) > 0x7fff) {
		return 1;
	}
	if (!(conn->llcp_req == conn->llcp_ack)) { ; ; };
	memcpy(&conn->llcp.chan_map.chm[0],
			&pdu_data_rx->payload.llctrl.ctrldata.chan_map_ind.chm[0],
			sizeof(conn->llcp.chan_map.chm));
	conn->llcp.chan_map.instant =
		pdu_data_rx->payload.llctrl.ctrldata.chan_map_ind.instant;
	conn->llcp.chan_map.initiate = 0;
	conn->llcp_type = LLCP_CHAN_MAP;
	conn->llcp_ack--;
	return 0;
}
static inline u32_t phy_upd_ind(struct radio_pdu_node_rx *radio_pdu_node_rx,
		u8_t *rx_enqueue)
{
	struct connection *conn = _radio.conn_curr;
	struct pdu_data_llctrl_phy_upd_ind *p;
	struct pdu_data *pdu_data_rx;
	pdu_data_rx = (struct pdu_data *)radio_pdu_node_rx->pdu_data;
	p = &pdu_data_rx->payload.llctrl.ctrldata.phy_upd_ind;
	if (!((p->m_to_s_phy | p->s_to_m_phy) & 0x07)) {
		struct radio_le_phy_upd_cmplt *p;
		if ((conn->llcp_phy.ack == conn->llcp_phy.req) ||
				(conn->llcp_phy.state != 2)) {
			return 0;
		}
		conn->llcp_phy.ack = conn->llcp_phy.req;
		conn->procedure_expire = 0;
		if (!conn->llcp_phy.cmd) {
			return 0;
		}
		radio_pdu_node_rx->hdr.type = NODE_RX_TYPE_PHY_UPDATE;
		p = (struct radio_le_phy_upd_cmplt *)&pdu_data_rx->payload;
		p->status = 0;
		p->tx = conn->phy_tx;
		p->rx = conn->phy_rx;
		*rx_enqueue = 1;
		return 0;
	}
	if (((p->instant - conn->event_counter) & 0xffff) > 0x7fff) {
		return 1;
	}
	if (!(conn->llcp_req == conn->llcp_ack)) { ; ; };
	if ((conn->llcp_phy.ack != conn->llcp_phy.req) &&
			(conn->llcp_phy.state == 2)) {
		conn->llcp_phy.ack = conn->llcp_phy.req;
		conn->llcp.phy_upd_ind.cmd = conn->llcp_phy.cmd;
		conn->procedure_expire = 0;
	}
	conn->llcp.phy_upd_ind.tx = p->s_to_m_phy;
	conn->llcp.phy_upd_ind.rx = p->m_to_s_phy;
	conn->llcp.phy_upd_ind.instant = p->instant;
	conn->llcp.phy_upd_ind.initiate = 0;
	conn->llcp_type = LLCP_PHY_UPD;
	conn->llcp_ack--;
	if (conn->llcp.phy_upd_ind.tx) {
		conn->phy_tx_time = conn->llcp.phy_upd_ind.tx;
	}
	return 0;
}
static void enc_req_reused_send(struct connection *conn,
		struct radio_pdu_node_tx *node_tx)
{
	struct pdu_data *pdu_ctrl_tx;
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				)
		+ sizeof(struct pdu_data_llctrl_enc_req);
	pdu_ctrl_tx->payload.llctrl.opcode = PDU_DATA_LLCTRL_TYPE_ENC_REQ;
	memcpy(&pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.rand[0],
			&conn->llcp.encryption.rand[0],
			sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.rand));
	pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.ediv[0] =
		conn->llcp.encryption.ediv[0];
	pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.ediv[1] =
		conn->llcp.encryption.ediv[1];
	rand_isr_get(sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.skdm),
			pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.skdm);
	rand_isr_get(sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.ivm),
			pdu_ctrl_tx->payload.llctrl.ctrldata.enc_req.ivm);
}
static u8_t enc_rsp_send(struct connection *conn)
{
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return 1;
	}
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				)
		+ sizeof(struct pdu_data_llctrl_enc_rsp);
	pdu_ctrl_tx->payload.llctrl.opcode = PDU_DATA_LLCTRL_TYPE_ENC_RSP;
	rand_isr_get(sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.enc_rsp.skds),
			pdu_ctrl_tx->payload.llctrl.ctrldata.enc_rsp.skds);
	rand_isr_get(sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.enc_rsp.ivs),
			pdu_ctrl_tx->payload.llctrl.ctrldata.enc_rsp.ivs);
	memcpy(&conn->llcp.encryption.skd[8],
			&pdu_ctrl_tx->payload.llctrl.ctrldata.enc_rsp.skds[0], 8);
	memcpy(&conn->ccm_rx.iv[4],
			&pdu_ctrl_tx->payload.llctrl.ctrldata.enc_rsp.ivs[0], 4);
	ctrl_tx_enqueue(conn, node_tx);
	return 0;
}
static u8_t start_enc_rsp_send(struct connection *conn,
		struct pdu_data *pdu_ctrl_tx)
{
	struct radio_pdu_node_tx *node_tx = 
		((void *)0)
		;
	if (!pdu_ctrl_tx) {
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (!node_tx) {
			return 1;
		}
		pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	}
	conn->enc_tx = 1;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				)
		;
	pdu_ctrl_tx->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_START_ENC_RSP;
	if (node_tx) {
		ctrl_tx_enqueue(conn, node_tx);
	}
	return 0;
}
static u8_t pause_enc_rsp_send(struct connection *conn, u8_t req)
{
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	if (req) {
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (!node_tx) {
			return 1;
		}
		conn->refresh = 1;
	} else if (!conn->role) {
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (!node_tx) {
			return 1;
		}
		conn->enc_tx = 0;
	} else {
		conn->enc_tx = 0;
		return 0;
	}
	conn->pause_rx = 1;
	conn->enc_rx = 0;
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				)
		;
	pdu_ctrl_tx->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_RSP;
	ctrl_tx_enqueue(conn, node_tx);
	return 0;
}
static u8_t unknown_rsp_send(struct connection *conn, u8_t type)
{
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return 1;
	}
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				)
		+ sizeof(struct pdu_data_llctrl_unknown_rsp);
	pdu_ctrl_tx->payload.llctrl.opcode = PDU_DATA_LLCTRL_TYPE_UNKNOWN_RSP;
	pdu_ctrl_tx->payload.llctrl.ctrldata.unknown_rsp.type = type;
	ctrl_tx_enqueue(conn, node_tx);
	return 0;
}
static u8_t feature_rsp_send(struct connection *conn,
		struct pdu_data *pdu_data_rx)
{
	struct pdu_data_llctrl_feature_req *req;
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return 1;
	}
	req = &pdu_data_rx->payload.llctrl.ctrldata.feature_req;
	_radio.conn_curr->llcp_features &= feat_get(&req->features[0]);
	_radio.conn_curr->common.fex_valid = 1;
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_feature_rsp);
	pdu_ctrl_tx->payload.llctrl.opcode = PDU_DATA_LLCTRL_TYPE_FEATURE_RSP;
	memset(&pdu_ctrl_tx->payload.llctrl.ctrldata.feature_rsp.features[0],
			0x00,
			sizeof(pdu_ctrl_tx->payload.llctrl.ctrldata.feature_rsp.features));
	pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[0] =
		conn->llcp_features & 0xFF;
	pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[1] =
		(conn->llcp_features >> 8) & 0xFF;
	pdu_ctrl_tx->payload.llctrl.ctrldata.feature_req.features[2] =
		(conn->llcp_features >> 16) & 0xFF;
	ctrl_tx_sec_enqueue(conn, node_tx);
	return 0;
}
static u8_t version_ind_send(struct connection *conn,
		struct pdu_data *pdu_data_rx, u8_t *rx_enqueue)
{
	struct pdu_data_llctrl_version_ind *v;
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	if (!conn->llcp_version.tx) {
		node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
		if (!node_tx) {
			return 1;
		}
		conn->llcp_version.tx = 1;
		pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
		pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
		pdu_ctrl_tx->len = 
			__builtin_offsetof (
					struct pdu_data_llctrl
					, 
					ctrldata
					) 
			+
			sizeof(struct pdu_data_llctrl_version_ind);
		pdu_ctrl_tx->payload.llctrl.opcode =
			PDU_DATA_LLCTRL_TYPE_VERSION_IND;
		v = &pdu_ctrl_tx->payload.llctrl.ctrldata.version_ind;
		v->version_number = 9;
		v->company_id = 0xFFFF;
		v->sub_version_number = 0xFFFF;
		ctrl_tx_sec_enqueue(conn, node_tx);
		empty_tx_enqueue(conn);
	} else if (!conn->llcp_version.rx) {
		conn->procedure_expire = 0;
		*rx_enqueue = 1;
	} else {
		return 0;
	}
	v = &pdu_data_rx->payload.llctrl.ctrldata.version_ind;
	conn->llcp_version.version_number = v->version_number;
	conn->llcp_version. company_id = v->company_id;
	conn->llcp_version.sub_version_number = v->sub_version_number;
	conn->llcp_version.rx = 1;
	return 0;
}
static u8_t reject_ext_ind_send(struct connection *conn,
		u8_t reject_opcode, u8_t error_code)
{
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return 1;
	}
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_reject_ext_ind);
	pdu_ctrl_tx->payload.llctrl.opcode =
		PDU_DATA_LLCTRL_TYPE_REJECT_EXT_IND;
	pdu_ctrl_tx->payload.llctrl.ctrldata.reject_ext_ind.reject_opcode =
		reject_opcode;
	pdu_ctrl_tx->payload.llctrl.ctrldata.reject_ext_ind.error_code =
		error_code;
	ctrl_tx_enqueue(conn, node_tx);
	return 0;
}
static u8_t phy_rsp_send(struct connection *conn, struct pdu_data *pdu_data_rx)
{
	struct pdu_data_llctrl_phy_req_rsp *p;
	struct radio_pdu_node_tx *node_tx;
	struct pdu_data *pdu_ctrl_tx;
	struct pdu_data_llctrl *c;
	node_tx = mem_acquire(&_radio.pkt_tx_ctrl_free);
	if (!node_tx) {
		return 1;
	}
	conn->llcp_phy.state = 2;
	if (conn->llcp_phy.ack ==
			conn->llcp_phy.req) {
		conn->llcp_phy.ack--;
		conn->llcp_phy.cmd = 0;
		conn->llcp_phy.tx =
			conn->phy_pref_tx;
		conn->llcp_phy.rx =
			conn->phy_pref_rx;
		conn->procedure_expire =
			conn->procedure_reload;
	}
	c = &pdu_data_rx->payload.llctrl;
	p = &c->ctrldata.phy_req;
	conn->llcp_phy.tx &= p->rx_phys;
	conn->llcp_phy.rx &= p->tx_phys;
	pdu_ctrl_tx = (struct pdu_data *)node_tx->pdu_data;
	pdu_ctrl_tx->ll_id = PDU_DATA_LLID_CTRL;
	pdu_ctrl_tx->len = 
		__builtin_offsetof (
				struct pdu_data_llctrl
				, 
				ctrldata
				) 
		+
		sizeof(struct pdu_data_llctrl_phy_req_rsp);
	pdu_ctrl_tx->payload.llctrl.opcode = PDU_DATA_LLCTRL_TYPE_PHY_RSP;
	pdu_ctrl_tx->payload.llctrl.ctrldata.phy_rsp.tx_phys =
		conn->phy_pref_tx;
	pdu_ctrl_tx->payload.llctrl.ctrldata.phy_rsp.rx_phys =
		conn->phy_pref_rx;
	ctrl_tx_enqueue(conn, node_tx);
	return 0;
}
void ll_radio_state_abort(void)
{
	event_stop(0, 0, 0, (void *)STATE_ABORT);
}
u32_t ll_radio_state_is_idle(void)
{
	return radio_is_idle();
}
void radio_ticks_active_to_start_set(u32_t ticks_active_to_start)
{
	_radio.ticks_active_to_start = ticks_active_to_start;
}
struct radio_adv_data *radio_adv_data_get(void)
{
	return &_radio.advertiser.adv_data;
}
struct radio_adv_data *radio_scan_data_get(void)
{
	return &_radio.advertiser.scan_data;
}
static struct connection *connection_get(u16_t handle)
{
	struct connection *conn;
	if (handle < _radio.connection_count) {
		conn = mem_get(_radio.conn_pool, (((u32_t)(sizeof(struct connection))+3) & (~((u32_t)3))), handle);
		if ((conn) && (conn->handle == handle)) {
			return conn;
		}
	}
	return 0;
}
static inline void role_active_disable(u8_t ticker_id_stop,
		u32_t ticks_xtal_to_start,
		u32_t ticks_active_to_start)
{
	static memq_link_t s_link;
	static struct mayfly s_mfy_radio_inactive = {0, 0, &s_link, 
		((void *)0)
			,
		mayfly_radio_inactive};
	u32_t volatile ret_cb = 2;
	u32_t ret;
	ret = ticker_stop(0,
			3, 0,
			ticker_if_done, (void *)&ret_cb);
	if (ret == 2) {
		mayfly_enable(3,
				1, 1);
		if (!(ret_cb != 2)) { ; ; };
	}
	if (ret_cb == 0) {
		static memq_link_t s_link;
		static struct mayfly s_mfy_xtal_stop = {0, 0, &s_link, 
			((void *)0)
				,
			mayfly_xtal_stop};
		u32_t volatile ret_cb = 2;
		u32_t ret;
		if (!(_radio.ticker_id_prepare)) { ; ; };
		_radio.ticker_id_prepare = 0;
		ret = ticker_stop(0,
				3,
				1,
				ticker_if_done, (void *)&ret_cb);
		if (ret == 2) {
			mayfly_enable(3,
					1, 1);
			if (!(ret_cb != 2)) { ; ; };
		}
		if (ret_cb == 0) {
			ticks_xtal_to_start &= ~(1UL << (31));
			if (ticks_active_to_start > ticks_xtal_to_start) {
				u32_t retval;
				retval = mayfly_enqueue(
						3,
						0, 0,
						&s_mfy_radio_inactive);
				if (!(!retval)) { ; ; };
			} else {
				u32_t retval;
				retval = mayfly_enqueue(
						3,
						0, 0,
						&s_mfy_xtal_stop);
				if (!(!retval)) { ; ; };
			}
		} else if (ret_cb == 1) {
			u32_t retval;
			retval = mayfly_enqueue(3,
					0, 0,
					&s_mfy_radio_inactive);
			if (!(!retval)) { ; ; };
			retval = mayfly_enqueue(3,
					0, 0,
					&s_mfy_xtal_stop);
			if (!(!retval)) { ; ; };
		} else {
			if (!(0)) { ; ; };
		}
	} else if (ret_cb == 1) {
		if (ticker_id_stop != ((u8_t)((u8_t)0 - 1))) {
			u32_t volatile ret_cb = 2;
			u32_t ret;
			ret = ticker_stop(0,
					3,
					ticker_id_stop, ticker_if_done,
					(void *)&ret_cb);
			if (ret == 2) {
				mayfly_enable(3,
						1, 1);
				if (!(ret_cb != 2)) { ; ; };
			}
			if (!((ret_cb == 0) || (ret_cb == 1))) { ; ; }
			;
		}
		if (_radio.role != ROLE_NONE) {
			static memq_link_t s_link;
			static struct mayfly s_mfy_radio_stop = {0, 0, &s_link,
				((void *)0)
					, mayfly_radio_stop};
			u32_t retval;
			s_mfy_radio_stop.param = (void *)STATE_STOP;
			retval = mayfly_enqueue(3,
					0, 0,
					&s_mfy_radio_stop);
			if (!(!retval)) { ; ; };
			while (_radio.role != ROLE_NONE) {
				cpu_sleep();
			}
		}
	} else {
		if (!(0)) { ; ; };
	}
}
static u32_t role_disable(u8_t ticker_id_primary, u8_t ticker_id_stop)
{
	u32_t volatile ret_cb = 2;
	u32_t ticks_active_to_start = 0;
	u32_t ticks_xtal_to_start = 0;
	u32_t ret;
	switch (ticker_id_primary) {
		case 5:
			ticks_xtal_to_start =
				_radio.advertiser.hdr.ticks_xtal_to_start;
			ticks_active_to_start =
				_radio.advertiser.hdr.ticks_active_to_start;
			ret = ticker_stop(0,
					3, ticker_id_stop,
					ticker_if_done, (void *)&ret_cb);
			if (ret == 2) {
				while (ret_cb == 2) {
					cpu_sleep();
				}
			}
			if (!((ret_cb == 0) || (ret_cb == 1))) { ; ; }
			;
			break;
		case 6:
			ticks_xtal_to_start =
				_radio.scanner.hdr.ticks_xtal_to_start;
			ticks_active_to_start =
				_radio.scanner.hdr.ticks_active_to_start;
			break;
		default:
			if (ticker_id_primary >= 7) {
				struct connection *conn;
				u16_t conn_handle;
				conn_handle = ticker_id_primary -
					7;
				conn = connection_get(conn_handle);
				if (!conn) {
					return 1;
				}
				ticks_xtal_to_start =
					conn->hdr.ticks_xtal_to_start;
				ticks_active_to_start =
					conn->hdr.ticks_active_to_start;
			} else {
				if (!(0)) { ; ; };
			}
			break;
	}
	if (!(!_radio.ticker_id_stop)) { ; ; };
	_radio.ticker_id_stop = ticker_id_primary;
	ret_cb = 2;
	ret = ticker_stop(0,
			3, ticker_id_primary,
			ticker_if_done, (void *)&ret_cb);
	if (ret == 2) {
		if (_radio.ticker_id_event == ticker_id_primary) {
			mayfly_enable(3,
					1, 1);
		}
		while (ret_cb == 2) {
			cpu_sleep();
		}
	}
	if (ret_cb != 0) {
		goto role_disable_cleanup;
	}
	if ((_radio.ticker_id_prepare == ticker_id_primary)
			|| (_radio.ticker_id_event == ticker_id_primary)) {
		role_active_disable(ticker_id_stop,
				ticks_xtal_to_start, ticks_active_to_start);
	}
	if (!_radio.ticker_id_stop) {
		ret_cb = 1;
	}
role_disable_cleanup:
	_radio.ticker_id_stop = 0;
	return ret_cb;
}
u32_t radio_adv_enable(u16_t interval, u8_t chan_map, u8_t filter_policy,
		u8_t rl_idx)
{
	u32_t volatile ret_cb = 2;
	u32_t ticks_slot_offset;
	struct connection *conn;
	struct pdu_adv *pdu_adv;
	u16_t ticks_slot;
	u8_t chan_cnt;
	u32_t ret;
	if (_radio.advertiser.is_enabled) {
		return 0x0c;
	}
	pdu_adv = (struct pdu_adv *)
		&_radio.advertiser.adv_data.data[_radio.advertiser.adv_data.last][0];
	if ((pdu_adv->type == PDU_ADV_TYPE_ADV_IND) ||
			(pdu_adv->type == PDU_ADV_TYPE_DIRECT_IND)) {
		void *link;
		if (_radio.advertiser.conn) {
			return 0x0c;
		}
		link = mem_acquire(&_radio.link_rx_free);
		if (!link) {
			return 0x07;
		}
		conn = mem_acquire(&_radio.conn_free);
		if (!conn) {
			mem_release(link, &_radio.link_rx_free);
			return 0x07;
		}
		conn->handle = 0xFFFF;
		conn->llcp_features = ((1ULL << (0)) | (1ULL << (1)) | (1UL << (2)) | (1UL << (3)) | 0 | 0 | 0 | 0 | 0 | 0 | (1ULL << (14)) | (1ULL << (16)));
		conn->data_chan_sel = 0;
		conn->data_chan_use = 0;
		conn->event_counter = 0;
		conn->latency_prepare = 0;
		conn->latency_event = 0;
		conn->phy_pref_tx = _radio.default_phy_tx;
		conn->phy_tx = (1UL << (0));
		conn->phy_pref_flags = 0;
		conn->phy_flags = 0;
		conn->phy_tx_time = (1UL << (0));
		conn->phy_pref_rx = _radio.default_phy_rx;
		conn->phy_rx = (1UL << (0));
		conn->role = 1;
		conn->connect_expire = 6;
		conn->common.fex_valid = 0;
		conn->slave.latency_enabled = 0;
		conn->slave.latency_cancel = 0;
		conn->slave.window_widening_prepare_us = 0;
		conn->slave.window_widening_event_us = 0;
		conn->slave.ticks_to_offset = 0;
		conn->supervision_expire = 0;
		conn->procedure_expire = 0;
		conn->llcp_req = 0;
		conn->llcp_ack = 0;
		conn->llcp_version.tx = 0;
		conn->llcp_version.rx = 0;
		conn->llcp_terminate.req = 0;
		conn->llcp_terminate.ack = 0;
		conn->llcp_terminate.reason_peer = 0;
		conn->llcp_terminate.radio_pdu_node_rx.hdr.onion.link = link;
		conn->llcp_conn_param.req = 0;
		conn->llcp_conn_param.ack = 0;
		conn->llcp_phy.req = 0;
		conn->llcp_phy.ack = 0;
		conn->sn = 0;
		conn->nesn = 0;
		conn->pause_rx = 0;
		conn->pause_tx = 0;
		conn->enc_rx = 0;
		conn->enc_tx = 0;
		conn->refresh = 0;
		conn->empty = 0;
		conn->pkt_tx_head = 
			((void *)0)
			;
		conn->pkt_tx_ctrl = 
			((void *)0)
			;
		conn->pkt_tx_ctrl_last = 
			((void *)0)
			;
		conn->pkt_tx_data = 
			((void *)0)
			;
		conn->pkt_tx_last = 
			((void *)0)
			;
		conn->packet_tx_head_len = 0;
		conn->packet_tx_head_offset = 0;
		_radio.advertiser.conn = conn;
	} else {
		conn = 
			((void *)0)
			;
	}
	_radio.advertiser.chan_map = chan_map;
	_radio.advertiser.filter_policy = filter_policy;
	(void)(rl_idx);
	_radio.advertiser.hdr.ticks_active_to_start =
		_radio.ticks_active_to_start;
	_radio.advertiser.hdr.ticks_xtal_to_start =
		( ((u32_t)(((u64_t) (1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	_radio.advertiser.hdr.ticks_preempt_to_start =
		( ((u32_t)(((u64_t) (0) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	chan_cnt = util_ones_count_get(&chan_map, sizeof(chan_map));
	if (pdu_adv->type == PDU_ADV_TYPE_DIRECT_IND) {
		ticks_slot = ((300 + 176 + 152 + 40) *
				chan_cnt) - 40 + 352;
	} else if (pdu_adv->type == PDU_ADV_TYPE_NONCONN_IND) {
		ticks_slot = (300 + 376) * chan_cnt;
	} else {
		ticks_slot = (300 + 376 + 152 + 176 +
				152 + 376) * chan_cnt;
	}
	_radio.advertiser.hdr.ticks_slot = ( ((u32_t)(((u64_t) (ticks_slot) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	ticks_slot_offset =
		(_radio.advertiser.hdr.ticks_active_to_start <
		 _radio.advertiser.hdr.ticks_xtal_to_start) ?
		_radio.advertiser.hdr.ticks_xtal_to_start :
		_radio.advertiser.hdr.ticks_active_to_start;
	if ((pdu_adv->type == PDU_ADV_TYPE_DIRECT_IND) &&
			!interval) {
		u32_t ticks_now = ticker_ticks_now_get();
		ret = ticker_start(0,
				3,
				5, ticks_now, 0,
				(ticks_slot_offset +
				 _radio.advertiser.hdr.ticks_slot),
				0, 0,
				(ticks_slot_offset +
				 _radio.advertiser.hdr.ticks_slot),
				radio_event_adv_prepare, 
				((void *)0)
				,
				ticker_if_done, (void *)&ret_cb);
		if (ret == 2) {
			while (ret_cb == 2) {
				cpu_sleep();
			}
		}
		if (ret_cb != 0) {
			goto failure_cleanup;
		}
		ret_cb = 2;
		ret =
			ticker_start(0,
					3,
					3, ticks_now,
					( ((u32_t)(((u64_t) ((u64_t) (1280 * 1000) + 1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
					,
					0, 0,
					0, 0,
					event_adv_stop, 
					((void *)0)
					, ticker_if_done,
					(void *)&ret_cb);
	} else {
		ret =
			ticker_start(0,
					3,
					5,
					ticker_ticks_now_get(), 0,
					( ((u32_t)(((u64_t) ((u64_t) interval * 625) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ),
					0, 0,
					(ticks_slot_offset +
					 _radio.advertiser.hdr.ticks_slot),
					radio_event_adv_prepare, 
					((void *)0)
					,
					ticker_if_done, (void *)&ret_cb);
	}
	if (ret == 2) {
		while (ret_cb == 2) {
			cpu_sleep();
		}
	}
	if (ret_cb == 0) {
		_radio.advertiser.is_enabled = 1;
		if (!_radio.scanner.is_enabled) {
			ll_adv_scan_state_cb((1UL << (0)));
		}
		return 0;
	}
failure_cleanup:
	if (conn) {
		mem_release(conn->llcp_terminate.radio_pdu_node_rx.hdr.
				onion.link, &_radio.link_rx_free);
		mem_release(conn, &_radio.conn_free);
	}
	return 0x0c;
}
u32_t radio_adv_disable(void)
{
	u32_t status;
	status = role_disable(5,
			3);
	if (!status) {
		struct connection *conn;
		_radio.advertiser.is_enabled = 0;
		if (!_radio.scanner.is_enabled) {
			ll_adv_scan_state_cb(0);
		}
		conn = _radio.advertiser.conn;
		if (conn) {
			_radio.advertiser.conn = 
				((void *)0)
				;
			mem_release(conn->llcp_terminate.radio_pdu_node_rx.hdr.onion.link,
					&_radio.link_rx_free);
			mem_release(conn, &_radio.conn_free);
		}
	}
	return status ? 0x0c : 0;
}
u32_t radio_adv_is_enabled(void)
{
	return _radio.advertiser.is_enabled;
}
u32_t radio_adv_filter_pol_get(void)
{
	if (_radio.advertiser.is_enabled) {
		return _radio.advertiser.filter_policy;
	}
	return 0;
}
u32_t radio_scan_enable(u8_t type, u8_t init_addr_type, u8_t *init_addr,
		u16_t interval, u16_t window, u8_t filter_policy,
		u8_t rpa_gen, u8_t rl_idx)
{
	u32_t volatile ret_cb = 2;
	u32_t ticks_slot_offset;
	u32_t ticks_interval;
	u32_t ticks_anchor;
	u32_t us_offset;
	u32_t ret;
	if (_radio.scanner.is_enabled) {
		return 0x0c;
	}
	_radio.scanner.type = type;
	_radio.scanner.init_addr_type = init_addr_type;
	memcpy(&_radio.scanner.init_addr[0], init_addr, 6);
	_radio.scanner.ticks_window =
		( ((u32_t)(((u64_t) ((u64_t) window * 625) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	_radio.scanner.filter_policy = filter_policy;
	_radio.scanner.hdr.ticks_active_to_start =
		_radio.ticks_active_to_start;
	_radio.scanner.hdr.ticks_xtal_to_start =
		( ((u32_t)(((u64_t) (1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	_radio.scanner.hdr.ticks_preempt_to_start =
		( ((u32_t)(((u64_t) (0) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	_radio.scanner.hdr.ticks_slot =
		_radio.scanner.ticks_window +
		( ((u32_t)(((u64_t) (300) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	ticks_interval = ( ((u32_t)(((u64_t) ((u64_t) interval * 625) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF );
	if (_radio.scanner.hdr.ticks_slot >
			(ticks_interval -
			 ( ((u32_t)(((u64_t) (1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ))) {
		_radio.scanner.hdr.ticks_slot =
			(ticks_interval -
			 ( ((u32_t)(((u64_t) (1200) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ));
	}
	ticks_slot_offset =
		(_radio.scanner.hdr.ticks_active_to_start <
		 _radio.scanner.hdr.ticks_xtal_to_start) ?
		_radio.scanner.hdr.ticks_xtal_to_start :
		_radio.scanner.hdr.ticks_active_to_start;
	ticks_anchor = ticker_ticks_now_get();
	if ((_radio.scanner.conn) ||
			!0) {
		us_offset = 0;
	}
	ret = ticker_start(0,
			3, 6,
			(ticks_anchor + ( ((u32_t)(((u64_t) (us_offset) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )), 0,
			ticks_interval,
			( ( ((u64_t) ((u64_t) interval * 625) * 1000000000UL) - ((u64_t) ( ((u32_t)(((u64_t) ((u64_t) interval * 625) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF ) * 30517578125UL) ) / 1000UL ),
			0,
			(ticks_slot_offset +
			 _radio.scanner.hdr.ticks_slot),
			event_scan_prepare, 
			((void *)0)
			, ticker_if_done,
			(void *)&ret_cb);
	if (ret == 2) {
		while (ret_cb == 2) {
			cpu_sleep();
		}
	}
	if (ret_cb != 0) {
		return 0x0c;
	}
	_radio.scanner.is_enabled = 1;
	if (!_radio.advertiser.is_enabled) {
		ll_adv_scan_state_cb((1UL << (1)));
	}
	return 0;
}
u32_t radio_scan_disable(void)
{
	u32_t status;
	status = role_disable(6,
			4);
	if (!status) {
		struct connection *conn;
		_radio.scanner.is_enabled = 0;
		if (!_radio.advertiser.is_enabled) {
			ll_adv_scan_state_cb(0);
		}
		conn = _radio.scanner.conn;
		if (conn) {
			_radio.scanner.conn = 
				((void *)0)
				;
			mem_release(conn->llcp_terminate.
					radio_pdu_node_rx.hdr.onion.link,
					&_radio.link_rx_free);
			mem_release(conn, &_radio.conn_free);
		}
	}
	return status ? 0x0c : 0;
}
u32_t radio_scan_is_enabled(void)
{
	return _radio.scanner.is_enabled;
}
u32_t radio_scan_filter_pol_get(void)
{
	if (_radio.scanner.is_enabled) {
		return _radio.scanner.filter_policy;
	}
	return 0;
}
u32_t radio_connect_enable(u8_t adv_addr_type, u8_t *adv_addr, u16_t interval,
		u16_t latency, u16_t timeout)
{
	struct connection *conn;
	u32_t conn_interval_us;
	u32_t access_addr;
	void *link;
	if (_radio.scanner.conn) {
		return 0x0c;
	}
	link = mem_acquire(&_radio.link_rx_free);
	if (!link) {
		return 0x07;
	}
	conn = mem_acquire(&_radio.conn_free);
	if (!conn) {
		mem_release(link, &_radio.link_rx_free);
		return 0x07;
	}
	_radio.scanner.adv_addr_type = adv_addr_type;
	memcpy(&_radio.scanner.adv_addr[0], adv_addr, 6);
	_radio.scanner.conn_interval = interval;
	_radio.scanner.conn_latency = latency;
	_radio.scanner.conn_timeout = timeout;
	_radio.scanner.ticks_conn_slot =
		( ((u32_t)(((u64_t) (300 + radio_tx_ready_delay_get(0, 0) + 328 + 150 + 328) * 1000000000UL) / 30517578125UL)) & 0x00FFFFFF )
		;
	conn->handle = 0xFFFF;
	conn->llcp_features = ((1ULL << (0)) | (1ULL << (1)) | (1UL << (2)) | (1UL << (3)) | 0 | 0 | 0 | 0 | 0 | 0 | (1ULL << (14)) | (1ULL << (16)));
	access_addr = access_addr_get();
	memcpy(&conn->access_addr[0], &access_addr, sizeof(conn->access_addr));
	memcpy(&conn->crc_init[0], &conn, 3);
	memcpy(&conn->data_chan_map[0], &_radio.data_chan_map[0],
			sizeof(conn->data_chan_map));
	conn->data_chan_count = _radio.data_chan_count;
	conn->data_chan_sel = 0;
	conn->data_chan_hop = 6;
	conn->data_chan_use = 0;
	conn->event_counter = 0;
	conn->conn_interval = _radio.scanner.conn_interval;
	conn->latency_prepare = 0;
	conn->latency_event = 0;
	conn->latency = _radio.scanner.conn_latency;
	conn->phy_pref_tx = _radio.default_phy_tx;
	conn->phy_tx = (1UL << (0));
	conn->phy_pref_flags = 0;
	conn->phy_flags = 0;
	conn->phy_tx_time = (1UL << (0));
	conn->phy_pref_rx = _radio.default_phy_rx;
	conn->phy_rx = (1UL << (0));
	conn->role = 0;
	conn->connect_expire = 6;
	conn->common.fex_valid = 0;
	conn->master.terminate_ack = 0;
	conn_interval_us =
		(u32_t)_radio.scanner.conn_interval * 1250;
	conn->supervision_reload =
		((u16_t)((((_radio.scanner.conn_timeout * 10 * 1000)) + (conn_interval_us) - 1) / (conn_interval_us)))
		;
	conn->supervision_expire = 0;
	conn->procedure_reload =
		((u16_t)((((40 * 1000 * 1000)) + (conn_interval_us) - 1) / (conn_interval_us)));
	conn->procedure_expire = 0;
	conn->llcp_req = 0;
	conn->llcp_ack = 0;
	conn->llcp_version.tx = 0;
	conn->llcp_version.rx = 0;
	conn->llcp_terminate.req = 0;
	conn->llcp_terminate.ack = 0;
	conn->llcp_terminate.reason_peer = 0;
	conn->llcp_terminate.radio_pdu_node_rx.hdr.onion.link = link;
	conn->llcp_conn_param.req = 0;
	conn->llcp_conn_param.ack = 0;
	conn->llcp_phy.req = 0;
	conn->llcp_phy.ack = 0;
	conn->sn = 0;
	conn->nesn = 0;
	conn->pause_rx = 0;
	conn->pause_tx = 0;
	conn->enc_rx = 0;
	conn->enc_tx = 0;
	conn->refresh = 0;
	conn->empty = 0;
	conn->pkt_tx_head = 
		((void *)0)
		;
	conn->pkt_tx_ctrl = 
		((void *)0)
		;
	conn->pkt_tx_ctrl_last = 
		((void *)0)
		;
	conn->pkt_tx_data = 
		((void *)0)
		;
	conn->pkt_tx_last = 
		((void *)0)
		;
	conn->packet_tx_head_len = 0;
	conn->packet_tx_head_offset = 0;
	_radio.scanner.conn = conn;
	return 0;
}
u32_t ll_connect_disable(void)
{
	u32_t status;
	if (_radio.scanner.conn == 0) {
		return 0x0c;
	}
	status = radio_scan_disable();
	return status;
}
u32_t ll_conn_update(u16_t handle, u8_t cmd, u8_t status, u16_t interval,
		u16_t latency, u16_t timeout)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn) {
		return 1;
	}
	if (!cmd) {
		if (conn->common.fex_valid &&
				(conn->llcp_features &
				 (1UL << (1)))) {
			cmd++;
		} else if (conn->role) {
			return 1;
		}
	}
	if (!cmd) {
		if (conn->llcp_req != conn->llcp_ack) {
			return 1;
		}
		conn->llcp.conn_upd.win_size = 1;
		conn->llcp.conn_upd.win_offset_us = 0;
		conn->llcp.conn_upd.interval = interval;
		conn->llcp.conn_upd.latency = latency;
		conn->llcp.conn_upd.timeout = timeout;
		conn->llcp.conn_upd.state = LLCP_CUI_STATE_USE;
		conn->llcp.conn_upd.is_internal = 0;
		conn->llcp_type = LLCP_CONN_UPD;
		conn->llcp_req++;
	} else {
		cmd--;
		if (cmd) {
			if ((conn->llcp_conn_param.req ==
						conn->llcp_conn_param.ack) ||
					(conn->llcp_conn_param.state !=
					 LLCP_CPR_STATE_APP_WAIT)) {
				return 1;
			}
			conn->llcp_conn_param.status = status;
			conn->llcp_conn_param.state = cmd;
			conn->llcp_conn_param.cmd = 1;
		} else {
			if (conn->llcp_conn_param.req !=
					conn->llcp_conn_param.ack) {
				return 1;
			}
			conn->llcp_conn_param.status = 0;
			conn->llcp_conn_param.interval = interval;
			conn->llcp_conn_param.latency = latency;
			conn->llcp_conn_param.timeout = timeout;
			conn->llcp_conn_param.state = cmd;
			conn->llcp_conn_param.cmd = 1;
			conn->llcp_conn_param.req++;
		}
	}
	return 0;
}
u32_t ll_chm_update(u8_t *chm)
{
	u8_t instance;
	memcpy(&_radio.data_chan_map[0], chm,
			sizeof(_radio.data_chan_map));
	_radio.data_chan_count =
		util_ones_count_get(&_radio.data_chan_map[0],
				sizeof(_radio.data_chan_map));
	instance = _radio.connection_count;
	while (instance--) {
		struct connection *conn;
		conn = connection_get(instance);
		if (!conn || conn->role) {
			continue;
		}
		if (conn->llcp_req != conn->llcp_ack) {
			return 1;
		}
		memcpy(&conn->llcp.chan_map.chm[0], chm,
				sizeof(conn->llcp.chan_map.chm));
		conn->llcp.chan_map.initiate = 1;
		conn->llcp_type = LLCP_CHAN_MAP;
		conn->llcp_req++;
	}
	return 0;
}
u32_t ll_chm_get(u16_t handle, u8_t *chm)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn) {
		return 1;
	}
	do {
		conn->chm_update = 0;
		memcpy(chm, conn->data_chan_map, sizeof(conn->data_chan_map));
	} while (conn->chm_update);
	return 0;
}
u32_t ll_enc_req_send(u16_t handle, u8_t *rand, u8_t *ediv, u8_t *ltk)
{
	struct connection *conn;
	struct radio_pdu_node_tx *node_tx;
	conn = connection_get(handle);
	if (!conn || (conn->llcp_req != conn->llcp_ack)) {
		return 1;
	}
	node_tx = radio_tx_mem_acquire();
	if (node_tx) {
		struct pdu_data *pdu_data_tx;
		pdu_data_tx = (struct pdu_data *)node_tx->pdu_data;
		memcpy(&conn->llcp.encryption.ltk[0], ltk,
				sizeof(conn->llcp.encryption.ltk));
		if ((conn->enc_rx == 0) && (conn->enc_tx == 0)) {
			struct pdu_data_llctrl_enc_req *enc_req;
			pdu_data_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_data_tx->len = 
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						)
				+
				sizeof(struct pdu_data_llctrl_enc_req);
			pdu_data_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_ENC_REQ;
			enc_req = (void *)
				&pdu_data_tx->payload.llctrl.ctrldata.enc_req;
			memcpy(enc_req->rand, rand, sizeof(enc_req->rand));
			enc_req->ediv[0] = ediv[0];
			enc_req->ediv[1] = ediv[1];
			bt_rand_c(enc_req->skdm, sizeof(enc_req->skdm));
			bt_rand_c(enc_req->ivm, sizeof(enc_req->ivm));
		} else if ((conn->enc_rx != 0) && (conn->enc_tx != 0)) {
			memcpy(&conn->llcp.encryption.rand[0], rand,
					sizeof(conn->llcp.encryption.rand));
			conn->llcp.encryption.ediv[0] = ediv[0];
			conn->llcp.encryption.ediv[1] = ediv[1];
			pdu_data_tx->ll_id = PDU_DATA_LLID_CTRL;
			pdu_data_tx->len =
				__builtin_offsetof (
						struct pdu_data_llctrl
						, 
						ctrldata
						)
				;
			pdu_data_tx->payload.llctrl.opcode =
				PDU_DATA_LLCTRL_TYPE_PAUSE_ENC_REQ;
		} else {
			radio_tx_mem_release(node_tx);
			return 1;
		}
		if (radio_tx_mem_enqueue(handle, node_tx)) {
			radio_tx_mem_release(node_tx);
			return 1;
		}
		conn->llcp.encryption.initiate = 1;
		conn->llcp_type = LLCP_ENCRYPTION;
		conn->llcp_req++;
		return 0;
	}
	return 1;
}
u32_t ll_start_enc_req_send(u16_t handle, u8_t error_code,
		u8_t const *const ltk)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn) {
		return 1;
	}
	if (error_code) {
		if (conn->refresh == 0) {
			if (conn->llcp_req != conn->llcp_ack) {
				return 1;
			}
			conn->llcp.encryption.error_code = error_code;
			conn->llcp.encryption.initiate = 0;
			conn->llcp_type = LLCP_ENCRYPTION;
			conn->llcp_req++;
		} else {
			if (conn->llcp_terminate.ack !=
					conn->llcp_terminate.req) {
				return 1;
			}
			conn->llcp_terminate.reason_own = error_code;
			conn->llcp_terminate.req++;
		}
	} else {
		memcpy(&conn->llcp.encryption.ltk[0], ltk,
				sizeof(conn->llcp.encryption.ltk));
		if (conn->llcp_req != conn->llcp_ack) {
			return 1;
		}
		conn->llcp.encryption.error_code = 0;
		conn->llcp.encryption.initiate = 0;
		conn->llcp_type = LLCP_ENCRYPTION;
		conn->llcp_req++;
	}
	return 0;
}
u32_t ll_feature_req_send(u16_t handle)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn || (conn->llcp_req != conn->llcp_ack)) {
		return 1;
	}
	conn->llcp_type = LLCP_FEATURE_EXCHANGE;
	conn->llcp_req++;
	return 0;
}
u32_t ll_version_ind_send(u16_t handle)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn || (conn->llcp_req != conn->llcp_ack)) {
		return 1;
	}
	conn->llcp_type = LLCP_VERSION_EXCHANGE;
	conn->llcp_req++;
	return 0;
}
u32_t ll_terminate_ind_send(u16_t handle, u8_t reason)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn || (conn->llcp_terminate.ack != conn->llcp_terminate.req)) {
		return 1;
	}
	conn->llcp_terminate.reason_own = reason;
	conn->llcp_terminate.req++;
	return 0;
}
u32_t ll_tx_power_level_get(u16_t handle, u8_t type, s8_t *tx_power_level)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn) {
		return 1;
	}
	*tx_power_level = 0;
	return 0;
}
void ll_tx_power_get(s8_t *min, s8_t *max)
{
	*min = 0;
	*max = 0;
}
u32_t ll_phy_get(u16_t handle, u8_t *tx, u8_t *rx)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn) {
		return 1;
	}
	*tx = conn->phy_tx;
	*rx = conn->phy_rx;
	return 0;
}
u32_t ll_phy_default_set(u8_t tx, u8_t rx)
{
	_radio.default_phy_tx = tx;
	_radio.default_phy_rx = rx;
	return 0;
}
u32_t ll_phy_req_send(u16_t handle, u8_t tx, u8_t flags, u8_t rx)
{
	struct connection *conn;
	conn = connection_get(handle);
	if (!conn || (conn->llcp_req != conn->llcp_ack) ||
			(conn->llcp_phy.req != conn->llcp_phy.ack)) {
		return 1;
	}
	conn->llcp_phy.state = 0;
	conn->llcp_phy.cmd = 1;
	conn->llcp_phy.tx = tx;
	conn->llcp_phy.flags = flags;
	conn->llcp_phy.rx = rx;
	conn->llcp_phy.req++;
	return 0;
}
static u8_t tx_cmplt_get(u16_t *handle, u8_t *first, u8_t last)
{
	u8_t _first;
	u8_t cmplt;
	_first = *first;
	if (_first == last) {
		return 0;
	}
	cmplt = 0;
	*handle = _radio.pkt_release[_first].handle;
	do {
		struct radio_pdu_node_tx *node_tx;
		struct pdu_data *pdu_data_tx;
		if (*handle != _radio.pkt_release[_first].handle) {
			break;
		}
		node_tx = _radio.pkt_release[_first].node_tx;
		pdu_data_tx = (struct pdu_data *)node_tx->pdu_data;
		if ((!node_tx) || (node_tx == (struct radio_pdu_node_tx *)1) ||
				((((u32_t)node_tx & ~(0x00000003)) != 0) &&
				 (pdu_data_tx) && (pdu_data_tx->len != 0) &&
				 ((pdu_data_tx->ll_id == PDU_DATA_LLID_DATA_START) ||
				  (pdu_data_tx->ll_id == PDU_DATA_LLID_DATA_CONTINUE)))) {
			_radio.pkt_release[_first].node_tx =
				(struct radio_pdu_node_tx *)1;
			cmplt++;
		} else {
			_radio.pkt_release[_first].node_tx =
				(struct radio_pdu_node_tx *)2;
		}
		if (((u32_t)node_tx & ~(0x00000003)) != 0) {
			mem_release(node_tx, &_radio.pkt_tx_data_free);
		}
		_first = _first + 1;
		if (_first == _radio.packet_tx_count) {
			_first = 0;
		}
	} while (_first != last);
	*first = _first;
	return cmplt;
}
u8_t radio_rx_get(struct radio_pdu_node_rx **radio_pdu_node_rx, u16_t *handle)
{
	u8_t cmplt;
	cmplt = 0;
	if (_radio.link_rx_head != _radio.link_rx_tail) {
		struct radio_pdu_node_rx *_radio_pdu_node_rx;
		_radio_pdu_node_rx = _radio.link_rx_head->mem;
		cmplt = tx_cmplt_get(handle,
				&_radio.packet_release_first,
				_radio_pdu_node_rx->hdr.onion.
				packet_release_last);
		if (!cmplt) {
			u16_t handle;
			u8_t first, cmplt_prev, cmplt_curr;
			first = _radio.packet_release_first;
			cmplt_curr = 0;
			do {
				cmplt_prev = cmplt_curr;
				cmplt_curr = tx_cmplt_get(&handle, &first,
						_radio.packet_release_last);
			} while ((cmplt_prev != 0) ||
					(cmplt_prev != cmplt_curr));
			*radio_pdu_node_rx = _radio_pdu_node_rx;
		} else {
			*radio_pdu_node_rx = 
				((void *)0)
				;
		}
	} else {
		cmplt = tx_cmplt_get(handle, &_radio.packet_release_first,
				_radio.packet_release_last);
		*radio_pdu_node_rx = 
			((void *)0)
			;
	}
	return cmplt;
}
void radio_rx_dequeue(void)
{
	struct radio_pdu_node_rx *radio_pdu_node_rx = 
		((void *)0)
		;
	memq_link_t *link;
	link = memq_dequeue(_radio.link_rx_tail, &_radio.link_rx_head,
			(void **)&radio_pdu_node_rx);
	if (!(link)) { ; ; };
	mem_release(link, &_radio.link_rx_free);
	switch (radio_pdu_node_rx->hdr.type) {
		case NODE_RX_TYPE_DC_PDU:
		case NODE_RX_TYPE_REPORT:
		case NODE_RX_TYPE_CONNECTION:
		case NODE_RX_TYPE_CONN_UPDATE:
		case NODE_RX_TYPE_ENC_REFRESH:
		case NODE_RX_TYPE_CHAN_SEL_ALGO:
		case NODE_RX_TYPE_PHY_UPDATE:
			if (!(_radio.link_rx_data_quota < (_radio.packet_rx_count - 1))) { ; ; }
			;
			_radio.link_rx_data_quota++;
			break;
		case NODE_RX_TYPE_TERMINATE:
			break;
		default:
			if (!(0)) { ; ; };
			break;
	}
	if (radio_pdu_node_rx->hdr.type == NODE_RX_TYPE_CONNECTION) {
		struct radio_le_conn_cmplt *radio_le_conn_cmplt;
		struct connection *conn = 
			((void *)0)
			;
		struct pdu_data *pdu_data_rx;
		u8_t bm;
		pdu_data_rx = (void *)radio_pdu_node_rx->pdu_data;
		radio_le_conn_cmplt = (void *)&pdu_data_rx->payload;
		if ((radio_le_conn_cmplt->status == 0x3c) ||
				radio_le_conn_cmplt->role) {
			if (radio_le_conn_cmplt->status == 0x3c) {
				conn = _radio.advertiser.conn;
				_radio.advertiser.conn = 
					((void *)0)
					;
			}
			if (!(_radio.advertiser.is_enabled)) { ; ; };
			_radio.advertiser.is_enabled = 0;
		} else {
			if (!(_radio.scanner.is_enabled)) { ; ; };
			_radio.scanner.is_enabled = 0;
		}
		if (conn) {
			struct radio_pdu_node_rx *node_rx = (void *)
				&conn->llcp_terminate.radio_pdu_node_rx;
			mem_release(node_rx->hdr.onion.link,
					&_radio.link_rx_free);
			mem_release(conn, &_radio.conn_free);
		}
		bm = ((u8_t)_radio.scanner.is_enabled << 1) |
			_radio.advertiser.is_enabled;
		if (!bm) {
			ll_adv_scan_state_cb(0);
		}
	}
}
void radio_rx_mem_release(struct radio_pdu_node_rx **radio_pdu_node_rx)
{
	struct radio_pdu_node_rx *_radio_pdu_node_rx;
	struct connection *conn;
	_radio_pdu_node_rx = *radio_pdu_node_rx;
	while (_radio_pdu_node_rx) {
		struct radio_pdu_node_rx *_radio_pdu_node_rx_free;
		_radio_pdu_node_rx_free = _radio_pdu_node_rx;
		_radio_pdu_node_rx = _radio_pdu_node_rx->hdr.onion.next;
		switch (_radio_pdu_node_rx_free->hdr.type) {
			case NODE_RX_TYPE_DC_PDU:
			case NODE_RX_TYPE_REPORT:
			case NODE_RX_TYPE_CONNECTION:
			case NODE_RX_TYPE_CONN_UPDATE:
			case NODE_RX_TYPE_ENC_REFRESH:
			case NODE_RX_TYPE_CHAN_SEL_ALGO:
			case NODE_RX_TYPE_PHY_UPDATE:
				mem_release(_radio_pdu_node_rx_free,
						&_radio.pkt_rx_data_free);
				break;
			case NODE_RX_TYPE_TERMINATE:
				conn = mem_get(_radio.conn_pool, (((u32_t)(sizeof(struct connection))+3) & (~((u32_t)3))),
						_radio_pdu_node_rx_free->hdr.handle);
				mem_release(conn, &_radio.conn_free);
				break;
			default:
				if (!(0)) { ; ; };
				break;
		}
	}
	*radio_pdu_node_rx = _radio_pdu_node_rx;
	packet_rx_allocate(0xff);
}
static void rx_fc_lock(u16_t handle)
{
	if (_radio.fc_req == _radio.fc_ack) {
		u8_t req;
		_radio.fc_handle[_radio.fc_req] = handle;
		req = _radio.fc_req + 1;
		if (req == 3) {
			req = 0;
		}
		_radio.fc_req = req;
	}
}
u8_t do_radio_rx_fc_set(u16_t handle, u8_t req, u8_t ack)
{
	if (req == ack) {
		if (_radio.link_rx_head == _radio.link_rx_tail) {
			u8_t ack1 = ack;
			if (ack1 == 0) {
				ack1 = 3;
			}
			_radio.fc_handle[--ack1] = handle;
			_radio.fc_ack = ack1;
			if (req != _radio.fc_req) {
				_radio.fc_ack = ack;
				return 1;
			}
		} else {
			return 1;
		}
	} else if (((req == 0) &&
				(_radio.fc_handle[3 - 1] != handle)) ||
			((req != 0) && (_radio.fc_handle[req - 1] != handle))) {
		return 1;
	}
	return 0;
}
u8_t radio_rx_fc_set(u16_t handle, u8_t fc)
{
	if (_radio.fc_ena) {
		u8_t req = _radio.fc_req;
		u8_t ack = _radio.fc_ack;
		if (fc) {
			if (handle != 0xffff) {
				return do_radio_rx_fc_set(handle, req, ack);
			}
		} else if ((_radio.link_rx_head == _radio.link_rx_tail) &&
				(req != ack)
			  ) {
			_radio.fc_ack = req;
			if ((_radio.link_rx_head != _radio.link_rx_tail) &&
					(req == _radio.fc_req)) {
				_radio.fc_ack = ack;
			}
		}
	}
	return 0;
}
u8_t radio_rx_fc_get(u16_t *handle)
{
	u8_t req = _radio.fc_req;
	u8_t ack = _radio.fc_ack;
	if (req != ack) {
		if (handle) {
			*handle = _radio.fc_handle[ack];
		}
		return 1;
	}
	return 0;
}
struct radio_pdu_node_tx *radio_tx_mem_acquire(void)
{
	return mem_acquire(&_radio.pkt_tx_data_free);
}
void radio_tx_mem_release(struct radio_pdu_node_tx *node_tx)
{
	mem_release(node_tx, &_radio.pkt_tx_data_free);
}
static void ticker_op_latency_cancelled(u32_t ticker_status, void *params)
{
	struct connection *conn;
	if (!(ticker_status == 0)) { ; ; };
	conn = (struct connection *)params;
	conn->slave.latency_cancel = 0;
}
u32_t radio_tx_mem_enqueue(u16_t handle, struct radio_pdu_node_tx *node_tx)
{
	u8_t last;
	struct connection *conn;
	struct pdu_data *pdu_data;
	last = _radio.packet_tx_last + 1;
	if (last == _radio.packet_tx_count) {
		last = 0;
	}
	pdu_data = (struct pdu_data *)node_tx->pdu_data;
	conn = connection_get(handle);
	if (!conn || (last == _radio.packet_tx_first)) {
		return 1;
	}
	if (!(pdu_data->len <= (_radio.packet_tx_data_size - 
					__builtin_offsetof (
						struct radio_pdu_node_tx
						, 
						pdu_data
						) 
					- 
					__builtin_offsetof (
						struct pdu_data
						, 
						payload
						)
			       ))) { ; ; }
	;
	_radio.pkt_tx[_radio.packet_tx_last].handle = handle;
	_radio.pkt_tx[_radio.packet_tx_last]. node_tx = node_tx;
	_radio.packet_tx_last = last;
	if (conn->role && conn->latency_event && !conn->slave.latency_cancel) {
		u32_t ticker_status;
		conn->slave.latency_cancel = 1;
		ticker_status = ticker_update(0,
				3,
				7 +
				conn->handle, 0, 0, 0, 0, 1, 0,
				ticker_op_latency_cancelled,
				(void *)conn);
		if (!((ticker_status == 0) || (ticker_status == 2))) { ; ; }
		;
	}
	return 0;
}
void __attribute__((__weak__)) ll_adv_scan_state_cb(u8_t bm)
{
}
