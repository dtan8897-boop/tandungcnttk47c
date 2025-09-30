#include<stdio.h>
int main(){
	float diem10,diem4;
	char diemChu[3];
	printf("nhap diem(thang10): ");
	scanf("%f",&diem10);
	if (diem10 >= 9.0) {
        diem4 = 4.0; 
        printf(diemChu, "A+");
    } else if (diem10 >= 8.0) {
        diem4 = 3.5; 
        sprintf(diemChu, "A");
    } else if (diem10 >= 7.0) {
        diem4 = 3.0; 
        sprintf(diemChu, "B+");
    } else if (diem10 >= 6.0) {
        diem4 = 2.5; 
        sprintf(diemChu, "B");
    } else if (diem10 >= 5.0) {
        diem4 = 2.0; 
        sprintf(diemChu, "C");
    } else if (diem10 >= 4.0) {
        diem4 = 1.5; 
        sprintf(diemChu, "D");
    } else {
        diem4 = 1.0; 
        sprintf(diemChu, "F");
    }
    printf("\n--- Ket qua ---\n");
    printf("Thang diem 10: %.2f\n", diem10);
    printf("Thang diem 4: %.1f\n", diem4);
    printf("Thang diem chu: %s\n", diemChu);
    return 0;
}
