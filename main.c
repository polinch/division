#include <stdio.h>
#include <stdlib.h>

const int BASE = 10;

void basecaseDiv(unsigned int *a, unsigned int *b, unsigned int *quotient, unsigned int *remainder);

int main() {

    unsigned int a[] = {4, 6, 3, 2, 5};
    unsigned int b[] = {5, 5};

    unsigned int quotient[(sizeof(a) - sizeof(b)) / sizeof(int)];
    unsigned int remainder[sizeof(b) / sizeof(int)];

    basecaseDiv(a, b, quotient, remainder);

    return 0;
}

void basecaseDiv(unsigned int *a, unsigned int *b, unsigned int *quotient, unsigned int *remainder) {

    int n = sizeof(b) / sizeof(int);
    int m = (sizeof(a) - sizeof(b)) / sizeof(int);
    int tempQ = 0;

    for (int i = n - 1; i--; i < 0) {
        if (a[m + i] >= b[i]) {
             quotient[m] = 1;
             break;
        }
        else {
            quotient[m] = 0;
        }
    }

    if (quotient[m] == 1) {
        for (int i = n - 1; i--; i < 0) {
            a[m + i] -= b[i];
        }
    }

    for (int i = m - 1; i--; i < 0) {
        tempQ = (a[n + i] * BASE + a[n + i - 1]) / b[n - 1];
        quotient[i] = min(tempQ, BASE - 1);
        for (int j = m - 1; j--; j < 0) {
            a[n + j] = a[n + j] - quotient[i] *
        }
    }

    return;
}
