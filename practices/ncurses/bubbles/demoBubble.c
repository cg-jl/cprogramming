
#include "demoBubble.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern FILE *file;
void UpdateBubble (Bubble *bubble) {
  if (!bubble || bubble->pos->y >= LINES) return;
  if (bubble->pos->x < 0 || bubble->pos->x >= COLS)
    bubble->direction->x *= -1;
  VectorAdd (bubble->pos, bubble->direction);
}

void MoveBubble (Bubble* bubble, int x, int y) {
  bubble->direction->x = x;
  bubble->direction->y = y;
}

void DisplayBubble (Bubble *bubble) {
  if (!bubble) return;
  mvaddch (bubble->pos->y, bubble->pos->x, 'o');
}

void InitBubble (Bubble *bubble, int x, int y) {
  if (!bubble) exit (1);
  bubble->pos = VectorInit (x, y);
  bubble->direction = VectorInit (1, 0);
}

void FreeBubble (Bubble* bubble) {
  free (bubble->pos);
  free (bubble->direction);
}
