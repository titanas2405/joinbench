/*
 *
 * jb_error.h
 *		Error handling 
 * 
 */

#include "c.h"

#ifndef JOINBENCH_INCLUDE_UTILS_JBERROR_H
#define JOINBENCH_INCLUDE_UTILS_J		BERROR_H

#define WARNING		1   /* user warning - continue transaction */

#define ERROR		2	/* user error - abort transaction; return to
						 * known state */
								 
#define FATAL		3	/* fatal error - abort process */
					
extern void JbElogImp(uint8 level,
               const char *file, int line, const char *func,
               const char *fmt, ...)	
                __attribute__((format(printf, 5, 6)));	 
               

  

#define Elog(level, ...) \
    JbElogImp(level, __FILE__, __LINE__, __func__, __VA_ARGS__)
								 
#endif /*JOINBENCH_INCLUDE_UTILS_JBERROR_H*/
