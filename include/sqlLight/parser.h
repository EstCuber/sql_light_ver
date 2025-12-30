#ifndef SQLLIGHT_PARSER_H
#define SQLLIGHT_PARSER_H

#include "sqlLight/input.h"
#include "sqlLight/row.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_SYNTAX_ERROR,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert; // только для insert
} Statement;

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement);

MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table);

#endif
