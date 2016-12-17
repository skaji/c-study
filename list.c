#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static List* list_edge(List* l) {
  for (;;) {
    if (!l->next) {
      List* new = list_new();
      l->next = new;
      if (!l->value) {
        return l;
      } else {
        new->next = list_new();
        return new;
      }
    }
    l = l->next;
  }
}

List* list_new(void) {
  List* l = (List*)malloc(sizeof(List));
  l->value = NULL;
  l->next = NULL;
  return l;
}

void list_free(List* l) {
  List* current = l;
  List* temp;
  for (;;) {
    if (!current) {
      break;
    }
    if (current->value) {
      free(current->value);
      current->value = NULL;
    }
    temp = current->next;
    free(current);
    current = temp;
  }
}

void list_append(List* l, const char* value) {
  List* edge = list_edge(l);
  char* new_v = (char*)malloc(sizeof(char) * (strlen(value) + 1));
  strcpy(new_v, value);
  edge->value = new_v;
}

size_t list_length(List* l) {
  size_t length = 0;
  for (List* current = l; current->next; current = current->next) {
    length++;
  }
  return length;
}

char* list_at(List* l, size_t index) {
  size_t j = 0;
  for (List* current = l; current->next; current = current->next) {
    if (j == index) {
      return current->value;
    }
    j++;
  }
  return NULL;
}
