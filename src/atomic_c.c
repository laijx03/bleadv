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
unsigned int irq_lock(void);
void irq_unlock(unsigned int key);
int atomic_cas(atomic_t *target, atomic_val_t old_value,
		atomic_val_t new_value)
{
	unsigned int key;
	int ret = 0;
	key = irq_lock();
	if (*target == old_value) {
		*target = new_value;
		ret = 1;
	}
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_add(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target += value;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_sub(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target -= value;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_inc(atomic_t *target)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	(*target)++;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_dec(atomic_t *target)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	(*target)--;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_get(const atomic_t *target)
{
	return *target;
}
atomic_val_t atomic_set(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target = value;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_clear(atomic_t *target)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target = 0;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_or(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target |= value;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_xor(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target ^= value;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_and(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target &= value;
	irq_unlock(key);
	return ret;
}
atomic_val_t atomic_nand(atomic_t *target, atomic_val_t value)
{
	unsigned int key;
	atomic_val_t ret;
	key = irq_lock();
	ret = *target;
	*target = ~(*target & value);
	irq_unlock(key);
	return ret;
}
