#include "sqlLight/input.h"
#include "sqlLight/common.h"
#include <stdio.h>
#include <stdlib.h>

InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = (InputBuffer *)db_malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}
void read_input(InputBuffer *input_buffer) {
  ssize_t bytes_read =
      getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }
  // убираем лишний \n
  input_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer *input_buffer) {
  db_free(input_buffer->buffer);
  db_free(input_buffer);
}
