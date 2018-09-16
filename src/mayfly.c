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
static struct {
	memq_link_t *head;
	memq_link_t *tail;
	u8_t enable_req;
	u8_t enable_ack;
	u8_t disable_req;
	u8_t disable_ack;
} mft[4][4];
static memq_link_t mfl[4][4];
void mayfly_init(void)
{
	u8_t callee_id;
	callee_id = 4;
	while (callee_id--) {
		u8_t caller_id;
		caller_id = 4;
		while (caller_id--) {
			memq_init(&mfl[callee_id][caller_id],
					&mft[callee_id][caller_id].head,
					&mft[callee_id][caller_id].tail);
		}
	}
}
void mayfly_enable(u8_t caller_id, u8_t callee_id, u8_t enable)
{
	if (enable) {
		if (mft[callee_id][caller_id].enable_req ==
				mft[callee_id][caller_id].enable_ack) {
			mft[callee_id][caller_id].enable_req++;
		}
		mayfly_enable_cb(caller_id, callee_id, enable);
	} else {
		if (mft[callee_id][caller_id].disable_req ==
				mft[callee_id][caller_id].disable_ack) {
			mft[callee_id][caller_id].disable_req++;
			mayfly_pend(caller_id, callee_id);
		}
	}
}
u32_t mayfly_enqueue(u8_t caller_id, u8_t callee_id, u8_t chain,
		struct mayfly *m)
{
	u8_t state;
	u8_t ack;
	chain = chain || !mayfly_prio_is_equal(caller_id, callee_id) ||
		!mayfly_is_enabled(caller_id, callee_id) ||
		(mft[callee_id][caller_id].disable_req !=
		 mft[callee_id][caller_id].disable_ack);
	ack = m->_ack;
	state = (m->_req - ack) & 0x03;
	if (state != 0) {
		if (chain) {
			if (state != 1) {
				m->_req = ack + 1;
				mayfly_pend(caller_id, callee_id);
				return 0;
			}
			return 1;
		}
		m->_req = ack + 2;
	}
	if (!chain) {
		m->fp(m->param);
		return 0;
	}
	m->_req = ack + 1;
	memq_enqueue(m->_link, m, &mft[callee_id][caller_id].tail);
	mayfly_pend(caller_id, callee_id);
	return 0;
}
void mayfly_run(u8_t callee_id)
{
	u8_t disable = 0;
	u8_t enable = 0;
	u8_t caller_id;
	caller_id = 4;
	while (caller_id--) {
		memq_link_t *link;
		struct mayfly *m = 0;
		link = memq_peek(mft[callee_id][caller_id].head,
				mft[callee_id][caller_id].tail,
				(void **)&m);
		while (link) {
			u8_t state;
			u8_t req;
			req = m->_req;
			state = (req - m->_ack) & 0x03;
			if (state == 1) {
				m->_ack--;
				m->fp(m->param);
			}
			req = m->_req;
			if (((req - m->_ack) & 0x03) != 1) {
				memq_dequeue(mft[callee_id][caller_id].tail,
						&mft[callee_id][caller_id].head,
						0);
				m->_link = link;
				m->_ack = req;
			}
			link = memq_peek(mft[callee_id][caller_id].head,
					mft[callee_id][caller_id].tail,
					(void **)&m);
			if (state == 1) {
				if (caller_id || link) {
					mayfly_pend(callee_id, callee_id);
					return;
				}
			}
		}
		if (mft[callee_id][caller_id].disable_req !=
				mft[callee_id][caller_id].disable_ack) {
			disable = 1;
			mft[callee_id][caller_id].disable_ack =
				mft[callee_id][caller_id].disable_req;
		}
		if (mft[callee_id][caller_id].enable_req !=
				mft[callee_id][caller_id].enable_ack) {
			enable = 1;
			mft[callee_id][caller_id].enable_ack =
				mft[callee_id][caller_id].enable_req;
		}
	}
	if (disable && !enable) {
		mayfly_enable_cb(callee_id, callee_id, 0);
	}
}
