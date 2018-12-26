#include "tools.h"

void range(short *sign1, int n1[400], char *op1, short *sign2, int n2[400], char *op2, short *sign3, int n3[400]){
    char caractere;
    short i;
    scanf("%c", &caractere);
    while (caractere == ' '){
        scanf("%c", &caractere);
    }
    if (caractere == '-'){
        *sign1 = -1;
        scanf("%c", &caractere);
    }
    while (caractere == ' '){
        scanf("%c", &caractere);
    }
    i = 0;
    while (caractere <= '9' && caractere >= '0'){
        n1[i] = caractere - 48;
        scanf("%c", &caractere);
        i = i+1;
    }
    n1[i] = 88;
    while (caractere == ' '){
        scanf("%c", &caractere);
    }
    *op1 = caractere;
    scanf("%c", &caractere);
    while (caractere == ' '){
        scanf("%c", &caractere);
    }
    if (caractere == '-'){
        *sign2 = -1;
        scanf("%c", &caractere);
    }
    while (caractere == ' '){
        scanf("%c", &caractere);
    }
    i = 0;
    while (caractere <= '9' && caractere >= '0'){
        n2[i] = caractere - 48;
        scanf("%c", &caractere);
        i = i+1;
    }
    n2[i] = 88;
    while (caractere == ' '){
        scanf("%c", &caractere);
    }
    if (caractere != '\n'){
        *op2 = caractere;
        scanf("%c", &caractere);
        while (caractere == ' '){
            scanf("%c", &caractere);
        }
        if (caractere == '-'){
            *sign3 = -1;
            scanf("%c", &caractere);
        }
        while (caractere == ' '){
            scanf("%c", &caractere);
        }
        i = 0;
        while (caractere <= '9' && caractere >= '0'){
            n3[i] = caractere - 48;
            scanf("%c", &caractere);
            i = i+1;
        }
        n3[i] = 88;
    }
}

void push(int n[400]){
	int z = 0;
	for (short j = 0; j < 400; j = j+1){
		z = z + n[j];
	}
	if (z != 0){
		short save = 0;
		while (n[save] != 88){
			save = save+1;
		}
		for (short i = 0; i < save; i = i+1){
			n[399-i] = n[save-(i+1)];
		}
		for (short i = 0; i < 400-save; i = i+1){
			n[i] = 0;
		}
	}
}

short size(int n[400]){
	int z = 0;
	for (short j = 0; j < 400; j = j+1){
		z = z + n[j];
	}
	if (z != 0){
		short i = 0;
		while (n[i] == 0){
			i = i+1;
		}
		short x = 0;
		while (i < 400){
			x = x+1;
			i = i+1;
		}
		return x;
	}
	else
		return 0;
}

int* upper(int n1[400], int n2[400]){
	int temp[400] = {0};
	for (short j = 0; j < 400; j = j+1){
		if (n1[j] != n2[j])
			temp[j] = 1;
	}
	int z = 0;
	for (short j = 0; j < 400; j = j+1){
		z = z + temp[j];
	}
	if (z != 0){
		short i = 0;
		while (n1[i] == n2[i]){
			i = i+1;
		}
		if (n1[i] > n2[i])
			return n1;
		else
			return n2;
	}
	else
		return n1;
}

int* lower(int n1[400], int n2[400]){
	int temp[400] = {0};
	for (short j = 0; j < 400; j = j+1){
		if (n1[j] != n2[j])
			temp[j] = 1;
	}
	int z = 0;
	for (short j = 0; j < 400; j = j+1){
		z = z + temp[j];
	}
	if (z != 0){
		short i = 0;
		while (n1[i] == n2[i]){
			i = i+1;
		}
		if (n1[i] < n2[i])
			return n1;
		else
			return n2;
	}
	else
		return n2;
}

short negative_difference(int n1[400], int n2[400]){
	if (upper(n1, n2) == n2)
		return 1;
	else
		return 0;
}

void organize(int n[400]){
	for (short i = 0; i < 400; i = i+1){
		if (n[399-i]/10 != 0){
			int temp = n[399-i];
			n[399-i] = n[399-i] % 10;
			for (short j = 0; j < 399-i; j = j+1){
				n[j] = n[j+1];
			}
			n[399-(i+1)] = temp/10;
		}
	}
}