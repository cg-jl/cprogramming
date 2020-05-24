#include <string.h>

typedef struct _node {
  char *data;
  struct _node* next;
} Node;

Node *CreateNode (char *);
void AppendList (Node **, Node*);
void PrintList (Node **);
void FreeList (Node *);
