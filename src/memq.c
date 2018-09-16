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
inline memq_link_t *memq_peek(memq_link_t *head, memq_link_t *tail, void **mem);
memq_link_t *memq_init(memq_link_t *link, memq_link_t **head, memq_link_t **tail)
{
	*head = *tail = link;
	return link;
}
memq_link_t *memq_enqueue(memq_link_t *link, void *mem, memq_link_t **tail)
{
	(*tail)->next = link;
	(*tail)->mem = mem;
	*tail = link;
	return link;
}
memq_link_t *memq_peek(memq_link_t *head, memq_link_t *tail, void **mem)
{
	if (head == tail) {
		return 
			((void *)0)
			;
	}
	if (mem) {
		*mem = head->mem;
	}
	return head;
}
memq_link_t *memq_dequeue(memq_link_t *tail, memq_link_t **head, void **mem)
{
	memq_link_t *link;
	link = memq_peek(*head, tail, mem);
	if (!link) {
		return link;
	}
	*head = link->next;
	return link;
}
