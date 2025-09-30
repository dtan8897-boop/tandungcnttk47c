#include <stdio.h>
#include <math.h>
int main() {
    double tienNhan, laiSuat, tienGui;
    int thang;
    printf("Nhap so tien can co: ");
    scanf("%lf", &tienNhan);
    printf("Nhap so thang gui: ");
    scanf("%d", &thang);
    printf("Nhap lai suat 1 thang (%%): ");
    scanf("%lf", &laiSuat);
    tienGui = tienNhan / pow(1 + laiSuat/100.0, thang);
    printf("So tien it nhat phai gui: %.2lf\n", tienGui);
    return 0;
}
