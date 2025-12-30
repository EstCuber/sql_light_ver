#include "sqlLight/parser.h"
#include "sqlLight/input.h"
#include "sqlLight/page.h"
#include "sqlLight/vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    int args_assigned = sscanf(
        input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id),
        statement->row_to_insert.username, statement->row_to_insert.email);
    if (args_assigned < 3) {
      return PREPARE_SYNTAX_ERROR;
    }
    return PREPARE_SUCCESS;
  }

  // // не понял почему тут strcmp, оставлю еще тут свою реализацию
  // if (strncmp(input_buffer->buffer, "select", 6) == 0) {
  //     char is_last_char = input_buffer->buffer[6];
  //     if (is_last_char == ' ' || is_last_char == '\0') {
  //         statement->type = STATEMENT_SELECT;
  //         return PREPARE_SUCCESS;
  //     }
  // }

  if (strcmp(input_buffer->buffer, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}

// ---------------------------------------------------------
// MetaCommands part
// Тут вводим команды
MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    close_input_buffer(input_buffer);
    free_table(table);
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}
