#ifndef JOINBENCH_SRC_INCLUDE_DB_H
#define JOINBENCH_SRC_INCLUDE_DB_H

/* System header files that should be available everywhere in Postgres */

/* header files that are included */
#include "c.h"


/* A Datum contains either a value of a pass-by-value type or a pointer to
 * a value of a pass-by-reference type
*/

typedef uint64_t Datum;

/* A Nullable Datum is needed were both Datum and its nullness need to be stored
 */
typedef struct NullableDatum{
	Datum	value;
	bool	is_null;
}NullableDatum;




/*
 * Returns boolean value of a datum.
 * Any nonzero value will be considered true.
 */
static inline bool
DatumGetBool(Datum X)
{
	return (X != 0);
}

/*
 * Returns datum representation for a boolean.
 * Any nonzero value will be considered true.
 */
static inline Datum
BoolGetDatum(bool X)
{
    return (Datum) (X ? 1 : 0);
}

/*Returns datum representation for a character.
 */
static inline Datum
CharGetDatum(char X)
{
	return (Datum) X;
}	

/*
 * Returns character value of a datum.
 */
static inline char
DatumGetChar(Datum X)
{
	return (char) X;
}

/* 
 * Returns 8-bit unsigned integer value of a datum.
 */
static inline uint8
DatumGetUInt8(Datum X)
{
	return (uint8) X;
}

/*
 * Returns datum representation for an 8-bit unsigned integer.
 */
static inline Datum
UInt8GetDatum(uint8 X)
{
	return (Datum) X;
}


/*
 *Returns pointer value of a datum.
 */
static inline Pointer
DatumGetPointer(Datum X)
{
	return (Pointer) (uintptr_t) X;
}

/*
 * Returns datum representation for a pointer.
 * The odd-looking "true ? (X) : NULL" conditional expression has the effect
 * of producing a compiler error if X is not a pointer.
 */
#define PointerGetDatum(X) \
	((Datum) (uintptr_t) (true ? (X) : NULL))
	

#endif	/* JOINBENCH_SRC_INCLUDE_DB_H */
