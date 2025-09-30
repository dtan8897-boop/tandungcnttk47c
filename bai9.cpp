#include <stdio.h>
#include <string.h>
void daoNguocChuoi(char *str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        char tmp = str[l];
        str[l] = str[r];
        str[r] = tmp;
        l++;
        r--;
    }
}
int main() {
    char s[100];
    printf("Nhap chuoi: ");
    scanf("%s", s);

    daoNguocChuoi(s);
    printf("Chuoi dao nguoc: %s\n", s);
    return 0;
}

