/*
 * jb_error.c
 *	  support for the error handing
 */

#include "utils/jb_error.h"


static const char *level_name(uint8 level)
{
    switch (level) {
        case WARNING: return "WARNING";
        case ERROR:   return "ERROR";
        case FATAL:   return "FATAL";
    }
    return "?";
}

void JbElogImp(uint8 level,
               const char *file, int line, const char *func,
               const char *fmt, ...)
{
    int saved_errno = errno;              /* save FIRST */
    va_list ap;

    fprintf(stderr, "%s: ", level_name(level));
    
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    
    fprintf(stderr, "  (%s:%d, %s)\n", file, line, func);

    if (level == ERROR)
        exit(1);
    if (level == FATAL)
        abort();
}
