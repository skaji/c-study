#include <stdio.h>
#include "list.h"

int main(void) {
  List* l = list_new();
  list_append(l, "foo");
  list_append(l, "bar");
  for (List* current = l; current->next; current = current->next) {
    printf("-> %s\n", current->value);
  }
  list_free(l);
  return 0;
}
