#ifndef SQLLIGHT_VM_H
#define SQLLIGHT_VM_H

#include "sqlLight/page.h"
#include "sqlLight/parser.h"
typedef enum { EXECUTE_SUCCESS, EXECUTE_TABLE_FULL } ExecuteResult;
ExecuteResult execute_statement(Statement *statement, Table *table);
ExecuteResult execute_insert(Statement *statement, Table *table);
ExecuteResult execute_select(Statement *statement, Table *table);
Table *new_table();
void free_table(Table *table);
#endif
