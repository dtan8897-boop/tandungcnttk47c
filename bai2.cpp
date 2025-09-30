#include <stdio.h>
int main() {
    char tenkhachhang[100];
    int sodiencu, sodienmoi, soluong;
    long tiendien = 0;
    printf("Nhap ten khach hang: ");
    scanf("%s", tenkhachhang);
    printf("Nhap so dien cu: ");
    scanf("%d", &sodiencu);
    printf("Nhap so dien moi: ");
    scanf("%d", &sodienmoi);
    soluong = sodienmoi - sodiencu;
    if (soluong <= 100) {
        tiendien = soluong * 1418;
    } else if (soluong <= 150) {
        tiendien = 100 * 1418 + (soluong - 100) * 1622;
    } else if (soluong <= 200) {
        tiendien = 100 * 1418 + 50 * 1622 + (soluong - 150) * 2044;
    } else if (soluong <= 300) {
        tiendien = 100 * 1418 + 50 * 1622 + 50 * 2044 + (soluong - 200) * 2210;
    } else if (soluong <= 400) {
        tiendien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + (soluong - 300) * 2361;
    } else {
        tiendien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + 100 * 2361 + (soluong - 400) * 2420;
    }
    printf("\n--- HOA DON TIEN DIEN ---\n");
    printf("Khach hang: %s\n", tenkhachhang);
    printf("So kWh tieu thu: %d\n", soluong);
    printf("Thanh tien: %ld VND\n", tiendien);
    return 0;
}
