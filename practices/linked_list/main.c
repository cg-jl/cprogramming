#include "List.h"
#include <stdio.h>


int main (void) {
    Node *head = NULL;
    AppendList (&head, CreateNode ("esta lista"));
    AppendList (&head, CreateNode ("no"));
    AppendList (&head, CreateNode ("tiene elementos duplicados"));
    PrintList (&head);
    AppendList (&head, CreateNode ("no"));
    AppendList (&head, CreateNode ("pizza"));
    PrintList (&head);
    FreeList (head);
    return 0;
}
