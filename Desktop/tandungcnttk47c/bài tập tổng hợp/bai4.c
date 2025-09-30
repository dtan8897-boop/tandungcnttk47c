#include<stdio.h>
int main(){
	char hoten[50];
	float toan,van,tin,dtb;
	printf("Nhap ho ten: ");
	fgets(hoten,sizeof(hoten),stdin);
	printf("Nhap diem Toan: ");
    scanf("%f", &toan);
    printf("Nhap diem Van: ");
    scanf("%f", &van);
    printf("Nhap diem Tin hoc: ");
    scanf("%f", &tin);
    dtb = (toan + van + tin) / 3;
    printf("\n--- Ket qua ---\n");
    printf("Ho ten: %s", hoten);
    printf("Diem trung binh: %.2f\n", dtb);
    if (dtb < 5)
        printf("Xep loai: Yeu\n");
    else if (dtb < 7)
        printf("Xep loai: Trung binh\n");
    else if (dtb < 8)
        printf("Xep loai: Kha\n");
    else
        printf("Xep loai: Gioi\n");

    return 0;
}
