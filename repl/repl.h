#ifndef SQL_REPL_SIMPLE_H
#define SQL_REPL_SIMPLE_H

#include <stdlib.h>
#define db_malloc(size) malloc(size)
#define db_free(ptr) free(ptr)
#define db_realloc(ptr, size) realloc(ptr, size)

#endif
