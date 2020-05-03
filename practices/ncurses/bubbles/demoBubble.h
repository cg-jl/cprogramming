
#pragma once

#include "demoVector.h"
#include <ncurses.h>

typedef struct {
  Vector *pos;
  Vector *direction;
} Bubble;


void MoveBubble (Bubble*, int, int);
void UpdateBubble (Bubble*);
void DisplayBubble (Bubble*);
void InitBubble (Bubble*, int, int);
void FreeBubble (Bubble*);
