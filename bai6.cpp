#include <stdio.h>
int soThangCan(double tienGoc, double tienCan, double laiSuat) {
    int thang = 0;
    double tien = tienGoc;
    while (tien < tienCan) {
        tien *= (1 + laiSuat);
        thang++;
    }
    return thang;
}
int main() {
    double goc, can, lai;
    printf("Nhap so tien gui: ");
    scanf("%lf", &goc);
    printf("Nhap so tien can co: ");
    scanf("%lf", &can);
    printf("Nhap lai suat 1 thang: ");
    scanf("%lf", &lai);
    printf("Can gui it nhat %d thang\n", soThangCan(goc, can, lai));
    return 0;
}

