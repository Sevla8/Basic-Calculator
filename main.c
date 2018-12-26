#include "tools.h"
#include "operator.h"

int main(int argc, char* argv[]) {

    short sign1 = 1; int n1[400] = {0}; char op1; short sign2 = 1; int n2[400] = {0}; char op2 ; short sign3 = 1; int n3[400] = {0};

    range(&sign1, n1, &op1, &sign2, n2, &op2, &sign3, n3);

    push(n1); push(n2); push(n3);

    short sign = 1; int result[400] = {0};

    calculator(sign1, n1, op1, sign2, n2, op2, sign3, n3, &sign, result);

    resultor(sign1, n1, op1, sign2, n2, op2, sign3, n3, sign, result);

    return 0;
}
