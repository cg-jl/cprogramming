#include "List.h"
#include <stdio.h>


int main (void) {
    Node *head = NULL;
    AppendList (&head, CreateNode ("tomato sauce"));
    AppendList (&head, CreateNode ("berries"));
    PrintList (&head);
    AppendList (&head, CreateNode ("pizza"));
    AppendList (&head, CreateNode ("berries"));
    PrintList (&head);
    FreeList (head);
    return 0;
}
