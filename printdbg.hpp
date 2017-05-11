#ifndef __DBGPRINT_HPP__
#define __DBGPRINT_HPP__

#include <stdint.h>

/*
 * Simple struct to hold each argument for the formatted output.  The size of
 * the struct should be the natural size of the machine or big enough to hold
 * a pointer.
 */
struct _dbgprint_arg
{
    union {
        uintptr_t       val;
        intptr_t        ival;
        void            *p;
        const char      *str;
    };

    /*
     * Construct with an integer type of some sort.  The compiler should
     * complain if any non-convertable type is used.
     */
    template <typename T>
    _dbgprint_arg(T v) : val(v)
    {
    }
};

template <>
_dbgprint_arg::_dbgprint_arg(void *p) : p(p)
{
}

template <>
_dbgprint_arg::_dbgprint_arg(const char *s) : str(s)
{
}

void _dbgprint(const char *fmt, _dbgprint_arg *argarr, uintptr_t argc);

/*
 * Formatted print function.  Generates parameters at compile time and
 * hands a format string and an array of parameters to helper function.
 *
 * Only basic formatting is supported, but very similar to C's printf.
 * Supported format options:
 * %d - signed int
 * %u - unsigned int
 * %x - hex int
 * %p - pointer
 * %0nx - padded hex where 'n' is the number of leading zeros to add.
 * %c - character
 * %s - pointer to C string
 *
 * If used, the 'l' qualifier is ignored.  There is no support for floats
 * or integers bigger than uintptr_t.
 */
template<typename... Args>
void dbgprint(const char *fmt, Args... args)
{
    _dbgprint_arg   argarr[] = {args...};

    _dbgprint(fmt, argarr, sizeof...(Args));
}

#endif


