/*
 *
 * c.h
 *	  Fundamental C definitions. This is included by every .c file 
 *    via either postgres.h or postgres_fe.h, as appropriate).
 *
 */

#ifndef JOINBENCH_SRC_INCLUDE_C_H
#define JOINBENCH_SRC_INCLUDE_C_H

/* System header files that should be available everywhere in Postgres */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------
 * Pointers
 * ----------------------------------------------
 */
 
typedef void *Pointer;

/*-----------------------------------------------
 * <stdint.h> Name Chnages
 * ----------------------------------------------
 */

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

/*
 * Index
 *		Index into any memory resident array.
 *
 * Note:
 *		Indices are non negative.
 */
 
typedef unsigned int Index;


/*
 * Exit Code Status
 */
 
#define STATUS_OK		(0)
#define STATUS_ERROR	(-1)


/*
 * Printing
 */
 
#define print(x) printf(x\n)
 

#define StaticAssertVariableIsOfTypeMacro(varname, typename) \
	((void) sizeof(char[__builtin_types_compatible_p(__typeof__(varname), typename) ? 1 : -1]))

#endif	/* JOINBENCH_SRC_INCLUDE_C_H */
