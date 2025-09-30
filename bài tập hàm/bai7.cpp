#include <stdio.h>
#include <math.h>
int laNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}
int demNguyenTo(int m, int n) {
    int dem = 0;
    for (int i = m; i <= n; i++)
        if (laNguyenTo(i)) dem++;
    return dem;
}
int main() {
    printf("So nguyen to trong [1,10]: %d\n", demNguyenTo(1,10));
    printf("So nguyen to trong [1,1000]: %d\n", demNguyenTo(1,1000));
    printf("So nguyen to trong [1001,100000]: %d\n", demNguyenTo(1001,100000));
    return 0;
}

