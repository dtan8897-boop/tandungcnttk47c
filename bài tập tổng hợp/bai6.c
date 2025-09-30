#include<stdio.h>
int main(){
	double tienGui,laiSuat;
	int thang, i;
	printf("nhap so tien gui: ");
	scanf("%lf",&tienGui);
	printf("Nhap so thang gui: ");
    scanf("%d", &thang);
    printf("Nhap lai suat 1 thang (%%): ");
    scanf("%lf", &laiSuat);
    i = 1;
    while (i <= thang) {
        tienGui = tienGui + tienGui * laiSuat / 100.0;
        i++;
    }
    printf("So tien co duoc sau %d thang: %.2lf\n", thang, tienGui);
    return 0;
}
