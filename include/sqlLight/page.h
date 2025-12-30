#ifndef SQLLIGHT_PAGE_H
#define SQLLIGHT_PAGE_H
#include <stdint.h>

#define TABLE_MAX_PAGES 100

#define PAGE_SIZE 4096
#define ROWS_PER_PAGE (PAGE_SIZE / ROW_SIZE)
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

typedef struct {
  uint32_t num_rows;
  void *pages[TABLE_MAX_PAGES];
} Table;

#endif
