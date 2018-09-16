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
typedef uint32_t ret_code_t;
typedef enum
{
	NRF_FSTORAGE_EVT_READ_RESULT,
	NRF_FSTORAGE_EVT_WRITE_RESULT,
	NRF_FSTORAGE_EVT_ERASE_RESULT
} nrf_fstorage_evt_id_t;
typedef struct
{
	nrf_fstorage_evt_id_t id;
	ret_code_t result;
	uint32_t addr;
	uint32_t len;
	void * p_param;
} nrf_fstorage_evt_t;
typedef void (*nrf_fstorage_evt_handler_t)(nrf_fstorage_evt_t * p_evt);
typedef struct
{
	uint32_t erase_unit;
	uint32_t program_unit;
	_Bool 
		rmap;
	_Bool 
		wmap;
} const nrf_fstorage_info_t;
struct nrf_fstorage_api_s;
typedef struct
{
	struct nrf_fstorage_api_s const * p_api;
	nrf_fstorage_info_t * p_flash_info;
	nrf_fstorage_evt_handler_t evt_handler;
	uint32_t start_addr;
	uint32_t end_addr;
} nrf_fstorage_t;
typedef struct nrf_fstorage_api_s
{
	ret_code_t (*init)(nrf_fstorage_t * p_fs, void * p_param);
	ret_code_t (*uninit)(nrf_fstorage_t * p_fs, void * p_param);
	ret_code_t (*read)(nrf_fstorage_t const * p_fs, uint32_t src, void * p_dest, uint32_t len);
	ret_code_t (*write)(nrf_fstorage_t const * p_fs, uint32_t dest, void const * p_src, uint32_t len, void * p_param);
	ret_code_t (*erase)(nrf_fstorage_t const * p_fs, uint32_t addr, uint32_t len, void * p_param);
	uint8_t const * (*rmap)(nrf_fstorage_t const * p_fs, uint32_t addr);
	uint8_t * (*wmap)(nrf_fstorage_t const * p_fs, uint32_t addr);
	_Bool 
		(*is_busy)(nrf_fstorage_t const * p_fs);
} const nrf_fstorage_api_t;
ret_code_t nrf_fstorage_init(nrf_fstorage_t * p_fs,
		nrf_fstorage_api_t * p_api,
		void * p_param);
ret_code_t nrf_fstorage_uninit(nrf_fstorage_t * p_fs, void * p_param);
ret_code_t nrf_fstorage_read(nrf_fstorage_t const * p_fs,
		uint32_t addr,
		void * p_dest,
		uint32_t len);
ret_code_t nrf_fstorage_write(nrf_fstorage_t const * p_fs,
		uint32_t dest,
		void const * p_src,
		uint32_t len,
		void * p_param);
ret_code_t nrf_fstorage_erase(nrf_fstorage_t const * p_fs,
		uint32_t page_addr,
		uint32_t len,
		void * p_param);
uint8_t const * nrf_fstorage_rmap(nrf_fstorage_t const * p_fs, uint32_t addr);
uint8_t * nrf_fstorage_wmap(nrf_fstorage_t const * p_fs, uint32_t addr);
_Bool 
nrf_fstorage_is_busy(nrf_fstorage_t const * p_fs);
typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef unsigned int wchar_t;
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
extern nrf_fstorage_t * __start_fs_data; extern void * __stop_fs_data;
static 
_Bool 
addr_within_bounds(nrf_fstorage_t const * p_fs, uint32_t addr, uint32_t len);
static 
_Bool 
addr_is_aligned32(uint32_t addr);
ret_code_t nrf_fstorage_init(nrf_fstorage_t * p_fs,
		nrf_fstorage_api_t * p_api,
		void * p_param)
{
	if ((p_fs == 
				((void *)0)
	    ) || (p_api == 
		    ((void *)0)
		 ))
	{
		return ((0x0) + 14);
	}
	p_fs->p_api = p_api;
	return (p_fs->p_api)->init(p_fs, p_param);
}
ret_code_t nrf_fstorage_uninit(nrf_fstorage_t * p_fs,
		void * p_param)
{
	ret_code_t rc;
	if (p_fs == 
			((void *)0)
	   )
	{
		return ((0x0) + 14);
	}
	if (p_fs->p_api == 
			((void *)0)
	   )
	{
		return ((0x0) + 8);
	}
	rc = (p_fs->p_api)->uninit(p_fs, p_param);
	p_fs->p_api = 
		((void *)0)
		;
	p_fs->p_flash_info = 
		((void *)0)
		;
	return rc;
}
ret_code_t nrf_fstorage_read(nrf_fstorage_t const * p_fs,
		uint32_t src,
		void * p_dest,
		uint32_t len)
{
	if ((p_fs == 
				((void *)0)
	    ) || (p_dest == 
		    ((void *)0)
		 ))
	{
		return ((0x0) + 14);
	}
	if (p_fs->p_api == 
			((void *)0)
	   )
	{
		return ((0x0) + 8);
	}
	if (len == 0)
	{
		return ((0x0) + 9);
	}
	if ( !addr_is_aligned32(src)
			|| !addr_within_bounds(p_fs, src, len))
	{
		return ((0x0) + 16);
	}
	return (p_fs->p_api)->read(p_fs, src, p_dest, len);
}
ret_code_t nrf_fstorage_write(nrf_fstorage_t const * p_fs,
		uint32_t dest,
		void const * p_src,
		uint32_t len,
		void * p_context)
{
	if ((p_fs == 
				((void *)0)
	    ) || (p_src == 
		    ((void *)0)
		 ))
	{
		return ((0x0) + 14);
	}
	if (p_fs->p_api == 
			((void *)0)
	   )
	{
		return ((0x0) + 8);
	}
	if ((len == 0) || ((len % p_fs->p_flash_info->program_unit) != 0))
	{
		return ((0x0) + 9);
	}
	if ( !addr_is_aligned32(dest)
			|| !addr_is_aligned32((uint32_t)p_src)
			|| !addr_within_bounds(p_fs, dest, len))
	{
		return ((0x0) + 16);
	}
	return (p_fs->p_api)->write(p_fs, dest, p_src, len, p_context);
}
ret_code_t nrf_fstorage_erase(nrf_fstorage_t const * p_fs,
		uint32_t page_addr,
		uint32_t len,
		void * p_context)
{
	if (p_fs == 
			((void *)0)
	   )
	{
		return ((0x0) + 14);
	}
	if (p_fs->p_api == 
			((void *)0)
	   )
	{
		return ((0x0) + 8);
	}
	if (len == 0)
	{
		return ((0x0) + 9);
	}
	if ( ((page_addr & (p_fs->p_flash_info->erase_unit - 1)) != 0)
			|| !addr_within_bounds(p_fs, page_addr, (len * p_fs->p_flash_info->erase_unit)))
	{
		return ((0x0) + 16);
	}
	return (p_fs->p_api)->erase(p_fs, page_addr, len, p_context);
}
uint8_t const * nrf_fstorage_rmap(nrf_fstorage_t const * p_fs, uint32_t addr)
{
	if (p_fs == 
			((void *)0)
	   )
	{
		return 
			((void *)0)
			;
	}
	return (p_fs->p_api)->rmap(p_fs, addr);
}
uint8_t * nrf_fstorage_wmap(nrf_fstorage_t const * p_fs, uint32_t addr)
{
	if (p_fs == 
			((void *)0)
	   )
	{
		return 
			((void *)0)
			;
	}
	return (p_fs->p_api)->wmap(p_fs, addr);
}
	_Bool 
nrf_fstorage_is_busy(nrf_fstorage_t const * p_fs)
{
	if ((p_fs == 
				((void *)0)
	    ) || (p_fs->p_api == 
		    ((void *)0)
		 ))
	{
		for (uint32_t i = 0; i < ((size_t)&__stop_fs_data - (size_t)&__start_fs_data) / sizeof(nrf_fstorage_t); i++)
		{
			p_fs = ((nrf_fstorage_t*)&__start_fs_data + ((i)));
			if (p_fs->p_api != 
					((void *)0)
			   )
			{
				if (p_fs->p_api->is_busy(p_fs))
				{
					return 
						1
						;
				}
			}
		}
		return 
			0
			;
	}
	return p_fs->p_api->is_busy(p_fs);
}
static 
	_Bool 
addr_within_bounds(nrf_fstorage_t const * p_fs,
		uint32_t addr,
		uint32_t len)
{
	return ((addr >= p_fs->start_addr) &&
			(addr + len - 1 <= p_fs->end_addr));
}
static 
	_Bool 
addr_is_aligned32(uint32_t addr)
{
	return !(addr & 0x03);
}
