#include "demoBubble.h"
#include "demoLoop.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



Bubble* bubbles;
Bubble* temp;
FILE *file;
int i;

extern int drawLoopMax;

void setup (void) {
  drawLoopMax = 100;
  bubbles = (Bubble *) malloc (sizeof (Bubble) * LINES - 1);
  for (i = 0; i < LINES; i++) {
    InitBubble (bubbles + i, i % LINES, i);
  }
}
void loop (void) {
  clear();
  for (i = 0; i < LINES; i++) {
    temp = bubbles + i;
    UpdateBubble (temp);
    DisplayBubble (temp);
  }
  usleep (30);
}

void clean (void) {
  for (i = 0; i < LINES; i++)
    FreeBubble (bubbles + i);
  free (bubbles);
}
