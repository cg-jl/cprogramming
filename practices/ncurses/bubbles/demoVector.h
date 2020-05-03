#pragma once

typedef struct {
  int x;
  int y;
} Vector;


void VectorAdd (Vector*, Vector*);              /* add two vectors */
void VectorSub (Vector*, Vector*);              /* subtract two vectors */
void VectorMult (Vector*, int);                 /* multiply a vector by a scalar */
void VectorDiv (Vector*, int);                  /* divide a vector by a scalar */
/* void VectorNegate (Vector*);                    /1* same as multiplying vector by -1 *1/ */
/* void VectorCrossProduct (Vector*, Vector*);          /1* cross product of two vectors *1/ */
/* int VectorDotProduct (Vector*, Vector*);        /1* dot product of two vectors *1/ */
/* int VectorMod (Vector*);                        /1* modulus of a vector *1/ */
/* int VectorAngleBetween (Vector*, Vector*);      /1* angle between two vectors. */ 
/*                                                    same as acos (VectorCosAngleBetween) *1/ */
/* int VectorCosAngleBetween (Vector*, Vector*);   /1* cosin of the angle between two vectors. *1/ */
Vector* VectorInit (int, int);                  /* Initialize a vector pointer. includes malloc() */
