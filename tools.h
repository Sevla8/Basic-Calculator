#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>

void range(short*, int*, char*, short*, int*, char*, short*, int*);					//Range les caractère saisies sur l'entree standard dans sign1, n1, op1, sign2, n2, op2, sign3, n3.
void push(int*);																	//"Pousse" les n[i] de n qui constituent le nombre tel que le dernier se retrouve en n[399].
short size(int*);																	//Renvoie le nombre de chiffre qui constitue le nombre rangé dans n.
int* upper(int*, int*);																//Renvoie l'adresse de n1 si n1 "plus grand" que n2. Si n1 = n2 renvoie n1.
int* lower(int*, int*);																//Renvoie l'adresse de n1 si n1 "plus petit" que n2. Si n1 = n2 renvoie n2.
short negative_difference(int*, int*);												//Renvoie 1 si upper renvoie n2. Renvoie 0 sinon.
void organize(int*);																//Décompose les les nombres des n[i] de n en chiffres sans perdre d'information.

#endif