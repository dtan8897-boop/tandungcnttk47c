#include <stdio.h>
int main() {
    double tienGui, tienNhan, laiSuat;
    int thang = 0;
    printf("Nhap so tien gui ban dau: ");
    scanf("%lf", &tienGui);
    printf("Nhap so tien mong muon nhan duoc: ");
    scanf("%lf", &tienNhan);
    printf("Nhap lai suat 1 thang (%%): ");
    scanf("%lf", &laiSuat);
    while (tienGui < tienNhan) {
        thang++;
        tienGui = tienGui + tienGui * laiSuat / 100.0;
    }
    printf("So thang it nhat phai gui: %d\n", thang);
    return 0;
}
