#include "List.h"

#include <stdlib.h>
#include <stdio.h>

Node *CreateNode (char *str) {
  Node *n = malloc (sizeof (Node));
  if (n == NULL) return NULL;
  n->data = malloc (strlen (str) + 1);
  strcpy (n->data, str);
  n->next = NULL;
  return n;
}

void AppendList (Node **head, Node *n) {
  Node **ref = head;
  if (ref == NULL) return;
  int cmp;
  /* Traverse until on right place */
  while (*ref) {
    if ((cmp = strcmp ((*ref)->data, n->data)) == 0)
      return;
    else if (cmp > 0)
      break;
    ref = &(*ref)->next;
  }
  /* Insert before *ref */
  if (*ref)
    n->next = *ref;
  *ref = n;
}

void PrintList (Node **head) {
  Node **ref = head;
  printf ("List status: \n");
  while (*ref) {
    printf ("%s", (*ref)->data);
    if ((*ref)->next)
      printf (" -> ");
    ref = &(*ref)->next;
  }
  printf ("\n");
}

void FreeList (Node *head) {
  Node *ref = head;
  Node *last = NULL;
  while (ref && ref != last) {
    last = ref;
    if (last)
      free (last);
    ref = ref->next;
  }
}
