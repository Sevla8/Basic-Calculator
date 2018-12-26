#include "calcul.h"

void addition(int n1[400], int n2[400], int result[400]){
    for (short i = 0; i < 200; i = i+1){
        int temp = result[399-i];
        result[399-i] = (result[399-i] + n1[399-i] + n2[399-i]) % 10;
        result[399-(i+1)] = (n1[399-i] + n2[399-i] + temp) / 10;
    }
}

void soustraction(int n1[400], int n2[400], int result[400]){
    for (short i = 0; i < 200; i = i+1){
    	int temp = result[399-i];
        result[399-i] = (result[399-i] + n1[399-i] + 10 - n2[399-i]) % 10;
        if (n1[399-i] - n2[399-i] + temp < 0)
        	result[399-(i+1)] = -1;
    }
}

void multiplication(int n1[400], int n2[400], int result[400]){
    for (short i = 0; i < 200; i = i+1){
        for (short j = 0; j < 200; j = j+1){
            int temp = result[399-j-i];
            result[399-j-i] = (result[399-j-i] + n1[399-j] * n2[399-i]) % 10;
            result[399-(j+1)-i] = result[399-(j+1)-i] + (temp + n1[399-j] * n2[399-i]) / 10 ;
        }
    }
}

void division(int n1[400], int n2[400], int result[400]){
	int copy_n1[400];
	for (short j = 0; j < 400; j = j+1){
		copy_n1[j] = n1[j];
	}
	short size_n1 = size(n1);
	for (short i = 399-size_n1+size(n2)+1; i < 400; i = i+1){
		int temp1[400] = {0};
		if (size(n2) < size_n1){
			for (short j = 0; j <= size(n2); j = j+1){
				temp1[399-size(n2)+j] = copy_n1[399-size_n1+1+j];
			}
		}
		else {
			for (short j = 0; j < 400; j = j+1){
				temp1[j] = copy_n1[j];
			}
		}
		while (!negative_difference(temp1, n2)){
			int temp[400] = {0};
			soustraction(temp1, n2, temp);
			for (short j = 0; j < 400; j = j+1){
				temp1[j] = temp[j];
				temp[j] = 0;
			}
			result[i] = result[i] + 1;
		}
		for (short j = 0; j <= size(n2); j = j+1){
			copy_n1[399-size_n1+1+j] = temp1[399-size(n2)+j];
		}
		for (short j = 0; j < 400; j = j+1){
			temp1[j] = 0;
		}
		size_n1 = size_n1 - 1;
	}
	organize(result);
}

void modulo(int n1[400], int n2[400], int result[400]){
	for (short j = 0; j < 400; j = j+1){
		result[j] = n1[j];
	}
	short size_n1 = size(n1);
	for (short i = 399-size_n1+size(n2)+1; i < 400; i = i+1){
		int temp1[400] = {0};
		if (size(n2) < size_n1){
			for (short j = 0; j <= size(n2); j = j+1){
				temp1[399-size(n2)+j] = result[399-size_n1+1+j];
			}
		}
		else {
			for (short j = 0; j < 400; j = j+1){
				temp1[j] = result[j];
			}
		}
		while (!negative_difference(temp1, n2)){
			int temp[400] = {0};
			soustraction(temp1, n2, temp);
			for (short j = 0; j < 400; j = j+1){
				temp1[j] = temp[j];
				temp[j] = 0;
			}
		}
		for (short j = 0; j <= size(n2); j = j+1){
			result[399-size_n1+1+j] = temp1[399-size(n2)+j];
		}
		for (short j = 0; j < 400; j = j+1){
			temp1[j] = 0;
		}
		size_n1 = size_n1 - 1;
	}
}