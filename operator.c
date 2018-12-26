#include "operator.h"

void operator(short sign1, int n1[400], char op, short sign2, int n2[400], short* sign, int result[400]){
	if (op == '+'){
		if ((sign1 == 1 && sign2 == -1) || (sign1 == -1 && sign2 == 1)){
			soustraction(upper(n1, n2), lower(n1, n2), result);
			if (sign1 == 1 && sign2 == -1 && negative_difference(n1, n2))
				*sign = -1;
			else if (sign1 == -1 && sign2 == 1 && negative_difference(n2, n1))
				*sign = -1;
		}
		else {
			addition(n1, n2, result);
			if (sign1 == -1 && sign2 == -1)
				*sign = -1;
		}
	}
	else if (op == '-'){
		if ((sign1 == 1 && sign2 == -1) || (sign1 == -1 && sign2 == 1)){
			addition(n1, n2, result);
			if (sign1 == -1 && sign2 == 1)
				*sign = -1;
		}
		else {
			soustraction(upper(n1, n2), lower(n1, n2), result);
			if (sign1 == 1 && sign2 == 1 && negative_difference(n1, n2))
				*sign = -1;
			else if (sign1 == -1 && sign2 == -1 && negative_difference(n2, n1))
				*sign = -1;
		}
	}
	else if (op == '*'){
		multiplication(n1, n2, result);
		if ((sign1 == 1 && sign2 == -1) || (sign1 == -1 && sign2 == 1))
			*sign = -1;
	}
	else if (op == '/'){
		division(n1, n2, result);
		if ((sign1 == 1 && sign2 == -1) || (sign1 == -1 && sign2 == 1))
			*sign = -1;
	}
	else if (op == '%'){
		modulo(n1, n2, result);
		if (sign1 == -1)
			*sign = -1;
	}
}

void calculator(short sign1, int n1[400], char op1, short sign2, int n2[400], char op2, short sign3, int n3[400], short* sign, int result[400]){
	if (op2 == '\0')
		operator(sign1, n1, op1, sign2, n2, sign, result);
	else {
		short signx = 1;
		int nx[400] = {0};
		if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/' || op2 == '%')){
			operator(sign2, n2, op2, sign3, n3, &signx, nx);
			operator(sign1, n1, op1, signx, nx, sign, result);
		}
		else {
			operator(sign1, n1, op1, sign2, n2, &signx, nx);
			operator(signx, nx, op2, sign3, n3, sign, result);
		}
	}
}

void resultor(short sign1, int n1[400], char op1, short sign2, int n2[400], char op2, short sign3, int n3[400], short sign, int result[400]){
	int z = 0;
	for (short i = 0; i < 400; i = i+1){
		z = z + result[i];
	}
	if (z == 0)
		printf("0");
	else {
		if (sign == -1)
			printf("-");
		short i = 0;
		while (result[i] == 0)
			i = i+1;
		while (i < 400){
			printf("%d", result[i]);
			i = i+1;
		}
	}
	printf("\n");
}