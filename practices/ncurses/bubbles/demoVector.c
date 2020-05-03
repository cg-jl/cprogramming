

#include "demoVector.h"
#include <math.h>
#include <stdlib.h>


Vector* VectorInit (int x, int y) {
  Vector *newvector = (Vector*) malloc (sizeof (Vector));
  newvector->x = x;
  newvector->y = y;
  return newvector;
}

void VectorAdd (Vector *a, Vector *b) {
  a->x += b->x;
  a->y += b->y;
}

void VectorSub (Vector *a, Vector *b) {
  a->x -= b->x;
  a->y -= b->y;
}

void VectorMult (Vector *v, int x) {
  v->x *= x;
  v->y *= x;
}

void VectorDiv (Vector *v, int x) {
  v->x /= x;
  v->y /= x;
}




