// QUESTÃO 1
/*
#include <stdio.h>

double calculateFloor(double n) {
    if (n >= 0) {
        return (int)n;
    } else {
        return (int)(n - 1);
    }
}

double calculateCeil(double n) {
    if (n >= 0) {
        return (int)(n + 1);
    } else {
        return (int)n;
    }
}

int main() {
    double num = 6.5;

    printf("O piso de %.2f é %.2f\n", num, calculateFloor(num));
    printf("O teto de %.2f é %.2f", num, calculateCeil(num));
    return 0;
}
*/


// QUESTÃO 2
/*
#include <stdio.h>

double calculatePower(int base, int exponent) {
    double power = 1;

    if (exponent >= 0) {
        for(int i = 0; i < exponent; i++) {
            power = power * base;
        }
    } else {
        for(int i = 0; i > exponent; i--) {
            power = power / base;
        }
    }
    return power;
}

int main() {
    int base1 = 2, exponent1 = 3;
    int base2 = 2, exponent2 = -3;
    int base3 = -3, exponent3 = 2;
    int base4 = -3, exponent4 = -2;

    printf("%d^%d = %.3f\n", base1, exponent1, calculatePower(base1, exponent1));
    printf("%d^%d = %.3f\n", base2, exponent2, calculatePower(base2, exponent2));
    printf("%d^%d = %.3f\n", base3, exponent3, calculatePower(base3, exponent3));
    printf("%d^%d = %.3f", base4, exponent4, calculatePower(base4, exponent4));
    return 0;
}
*/


// QUESTÃO 3
/*
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num = 20;

    if (isPrime(num)) {
        printf("%d é um número primo", num);
    } else {
        printf("%d não é um número primo", num);
    }
    return 0;
}
*/


// QUESTÃO 4
/*
#include <stdio.h>

int calculateFactorial(int n) {
    int factorial = 1;

    if (n < 0) {
        factorial = 0;
    } else if (n == 0 || n == 1) {
        factorial = 1;
    } else {
        while (n > 1) {
            factorial = factorial * n;
            n--;
        }
    }
    return factorial;
}

int main() {
    int num = 5, factorial;

    factorial = calculateFactorial(num);
    if (factorial == 0) {
        printf("Valor inválido");
    } else {
        printf("O fatorial de %d é %d", num, factorial);
    }
    return 0;
}
*/


// QUESTÃO 5
/*
#include <stdio.h>

int calculateFibonacci(int n) {
    int fibonacci = 0;

    if (n == 1) {
        fibonacci = 1;
    } else {
        int x = 0, y = 1;
        for (int i = 2; i <= n; i++) {
            fibonacci = x + y;
            x = y;
            y = fibonacci;
        }
    }
    return fibonacci;
}

int main() {
    int num = 7;

    if (num < 0) {
        printf("Valor inválido");
    } else {
        printf("O %d-ésimo termo da sequência de Fibonacci é %d", num, calculateFibonacci(num));
    }
    return 0;
}
*/


// QUESTÃO 7
#include <stdio.h>

double calculateSquareRoot(double n) {
    double a = 0;
    double b = n;
    double c = (a + b) / 2;
    double error = 1e-6;

    while ((c * c - n) * (c * c - n) > error * error) {
        if (c * c > n) {
            b = c;
        } else {
            a = c;
        }
        c = (a + b) / 2;
    }

    return c;
}

int main() {
    double num = 16;

    if (num < 0) {
        printf("Valor inválido");
    } else {
        printf("A aproximação da raiz quadrada de %.2f é %.4f", num, calculateSquareRoot(num));
    }
    return 0;
}