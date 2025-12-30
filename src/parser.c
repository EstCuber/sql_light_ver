#include "sqlLight/parser.h"
#include "sqlLight/input.h"
#include <stdlib.h>
#include <string.h>

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
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
MetaCommandResult do_meta_command(InputBuffer *input_buffer) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}
