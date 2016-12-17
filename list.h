#ifndef LIST_H_
#define LIST_H_

typedef struct list {
  char* value;
  struct list* next;
} List;

List* list_new(void);
void list_free(List* l);
void list_append(List* l, const char* value);
size_t list_length(List* l);
char* list_at(List* l, size_t index);

#endif
