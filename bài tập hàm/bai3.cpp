#include <stdio.h>
double tinhTienDien(int chiSoTruoc, int chiSoSau) {
    int soKWh = chiSoSau - chiSoTruoc;
    double tien = 0;

    if (soKWh <= 100)
        tien = soKWh * 1418;
    else if (soKWh <= 150)
        tien = 100 * 1418 + (soKWh - 100) * 1622;
    else if (soKWh <= 200)
        tien = 100 * 1418 + 50 * 1622 + (soKWh - 150) * 2044;
    else if (soKWh <= 300)
        tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + (soKWh - 200) * 2210;
    else if (soKWh <= 400)
        tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + (soKWh - 300) * 2361;
    else
        tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + 100 * 2361 + (soKWh - 400) * 2420;

    return tien;
}
int main() {
    int truoc, sau;
    printf("Nhap chi so thang truoc: ");
    scanf("%d", &truoc);
    printf("Nhap chi so thang sau: ");
    scanf("%d", &sau);
    printf("Tien dien phai tra: %.0f VND\n", tinhTienDien(truoc, sau));
    return 0;
}

