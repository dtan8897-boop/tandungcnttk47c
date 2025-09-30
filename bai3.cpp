#include <stdio.h>

int tinhTienDien(int chiSoTruoc, int chiSoSau) {
    int soKWh = chiSoSau - chiSoTruoc;
    int tien = 0;

    if (soKWh <= 100) {
        tien = soKWh * 1418;
    } else if (soKWh <= 150) {
        tien = 100 * 1418 + (soKWh - 100) * 1622;
    } else if (soKWh <= 200) {
        tien = 100 * 1418 + 50 * 1622 + (soKWh - 150) * 2044;
    } else if (soKWh <= 300) {
        tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + (soKWh - 200) * 2210;
    } else if (soKWh <= 400) {
        tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + (soKWh - 300) * 2361;
    } else {
        tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + 100 * 2361 + (soKWh - 400) * 2420;
    }

    return tien;
}

int main() {
    int chiSoTruoc, chiSoSau;
    printf("Nhap chi so dien thang truoc: ");
    scanf("%d", &chiSoTruoc);
    printf("Nhap chi so dien thang sau: ");
    scanf("%d", &chiSoSau);

    int tien = tinhTienDien(chiSoTruoc, chiSoSau);
    printf("So tien dien phai tra: %d VND\n", tien);

    return 0;
}

