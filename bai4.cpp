#include <stdio.h>
#include <math.h>
double tienTietKiem(double soTien, int soThang, double laiSuat) {
    return soTien * pow(1 + laiSuat, soThang);
}
int main() {
    double tien;
    int thang;
    double lai;
    printf("Nhap so tien gui: ");
    scanf("%lf", &tien);
    printf("Nhap so thang gui: ");
    scanf("%d", &thang);
    printf("Nhap lai suat 1 thang (vd 0.01 = 1%%): ");
    scanf("%lf", &lai);
    printf("So tien nhan duoc: %.2f\n", tienTietKiem(tien, thang, lai));
    return 0;
}

