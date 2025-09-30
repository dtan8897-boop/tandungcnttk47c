#include <stdio.h>
long long giaiThuaKep(int n) {
    long long gt = 1;
    int i = n;
    while (i > 1) {
        gt *= i;
        i -= 2;
    }
    return gt;
}
int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    printf("%d!! = %lld\n", n, giaiThuaKep(n));
    return 0;
}

