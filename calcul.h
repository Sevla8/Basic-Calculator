#ifndef CALCUL_H
#define CALCUL_H

#include "tools.h"

void addition(int*, int*, int*);													//Additionne n1 à n2 dans n selon que n1[i] + n2[i] = n[i] pour i allant de 0 à 399.
void soustraction(int*, int*, int*);												//Soustrait n2 à n1 dans n selon que n1[i] - n2[i] = n[i] pour i allant de 0 à 399. Pour n1 "plus grand" que n2.
void multiplication(int*, int*, int*);												//Multiplie n1 par n2 dans n selon que n1[i] * n2[i] = n[i] pour i allant de 0 à 399.
void division(int*, int*, int*);													//Divise n1 par n2 dans n selon que n1[i] + n2[i] = n[i] pour i allant de 0 à 399. Pour n2 différent de 0.
void modulo(int*, int*, int*);														//Donne le reste de la division de n1 par n2 selon que n1[i] % n2[i] = n[i] pour i allant de 0 à 399.

#endif