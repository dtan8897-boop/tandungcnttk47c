#include<stdio.h>
typedef struct{
	float diem_4;
	const char*diem_chu;
}ketquadiem;
ketquadiem chuyendoidiem(float diem_10){
	ketquadiem kq;
	if(diem_10<0||diem_10>10){
		kq.diem_4=-1.0;
		kq.diem_chu="ko hop le";
		return kq;
	}
	if(diem_10>=9.0){
		kq.diem_4=4.0;
		kq.diem_chu="A+";
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
    ketquadiem ket_qua;
    printf("--- CHUONG TRINH CHUYEN DOI THANG DIEM ---\n");
    printf("Nhap diem thang 10 cua sinh vien: ");
    if (scanf("%f", &diem_10) != 1) {
        printf("Loi nhap lieu. Vui long nhap mot so thuc.\n");
        return 1;
    }
     printf("\n--- KET QUA ---\n");
    if (ket_qua.diem_4 == -1.0) {
        printf("Diem nhap vao khong hop le (phai tu 0 den 10).\n");
    } else {
        printf("Diem thang 10: %.2f\n", diem_10);
        printf("Diem thang 4: %.1f\n", ket_qua.diem_4);
        printf("Diem chu: %s\n", ket_qua.diem_chu);
    }
    return 0;
}


