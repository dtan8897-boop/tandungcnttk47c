#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n, i;
    bool isNT; 
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n < 2) {
        isNT = false;
    } else {
        isNT = true;
        i = 2;
        while (i <= sqrt(n)) {
            if (n % i == 0) {
                isNT = false;
                break;
            }
            i = i + 1;
        }
    }
    if (isNT) {
        printf("%d la so nguyen to\n", n);
    } else {
        printf("%d khong phai so nguyen to\n", n);
    }
    return 0;
}

