#include <stdio.h>

typedef struct {
    float diem_4;
    const char *diem_chu;
} KetQua;

KetQua chuyenDoiDiem(float diem_10) {
    KetQua kq;
    if (diem_10 >= 9.0) {
        kq.diem_4 = 4.0;
        kq.diem_chu = "A+";
    } else if (diem_10 >= 8.0) {
        kq.diem_4 = 3.5;
        kq.diem_chu = "A";
    } else if (diem_10 >= 7.0) {
        kq.diem_4 = 3.0;
        kq.diem_chu = "B+";
    } else if (diem_10 >= 6.0) {
        kq.diem_4 = 2.5;
        kq.diem_chu = "B";
    } else if (diem_10 >= 5.0) {
        kq.diem_4 = 2.0;
        kq.diem_chu = "C";
    } else if (diem_10 >= 4.0) {
        kq.diem_4 = 1.5;
        kq.diem_chu = "D";
    } else {
        kq.diem_4 = 1.0;
        kq.diem_chu = "F";
    }
    return kq;
}

int main() {
    float diem_10;
    printf("Nhap diem thang 10: ");
    scanf("%f", &diem_10);

    KetQua kq = chuyenDoiDiem(diem_10);

    printf("Diem thang 4: %.1f\n", kq.diem_4);
    printf("Diem chu: %s\n", kq.diem_chu);

    return 0;
}
