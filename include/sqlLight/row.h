#ifndef SQLLIGHT_ROW_H
#include "page.h"
#include <stdint.h>
#define SQLLIGHT_ROW_H
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define sizeof_of_attribute(Struct, Attribute) sizeof(((Struct *)0)->Attribute)

#define ID_SIZE sizeof_of_attribute(Row, id)
#define USERNAME_SIZE sizeof_of_attribute(Row, username)
#define EMAIL_SIZE sizeof_of_attribute(Row, email)

#define ID_OFFSET 0
#define USERNAME_OFFSET (ID_OFFSET + ID_SIZE)
#define EMAIL_OFFSET (USERNAME_OFFSET + USERNAME_SIZE)
#define ROW_SIZE (ID_SIZE + USERNAME_SIZE + EMAIL_SIZE)

typedef struct {
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE];
  char email[COLUMN_EMAIL_SIZE];
} Row;

void serialize_row(Row *source, void *destination);
void deserialize_row(void *source, Row *destination);
void *row_slot(Table *table, uint32_t row_num);
void print_row(Row *row);

#endif
