#ifndef SQLLIGHT_COMMON_H
#define SQLLIGHT_COMMON_H
#include <stdlib.h>

// потом попробую с моим маллоком позапускать
#define db_malloc(size) malloc(size)
#define db_free(ptr) free(ptr)
#define db_realloc(ptr, size) realloc(ptr, size)

#endif
