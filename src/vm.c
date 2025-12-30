#include "sqlLight/parser.h"
void execute_statement(Statement *statement) {
  switch (statement->type) {
  case (STATEMENT_INSERT):
    printf("Doing Insert Now! WIP");
    break;
  case (STATEMENT_SELECT):
    printf("Doing Select Now! WIP");
    break;
  }
}
