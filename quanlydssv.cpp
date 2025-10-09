#include <stdio.h>
#include <string.h>

typedef struct {
    char masv[20];
    char hoten[50];
    int tuoi;
    float dtb;
} SinhVien;

void nhapds(SinhVien *sv) {
    getchar();
    printf("Nhap ma sinh vien: ");
    gets(sv->masv);
    
    printf("Nhap ho va ten: ");
    gets(sv->hoten);
    
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->dtb);
}

void xuatds(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("MSV: %s\n", ds[i].masv);
        printf("Ho va ten: %s\n", ds[i].hoten);
        printf("Tuoi: %d\n", ds[i].tuoi);
        printf("Diem trung binh: %.2f\n", ds[i].dtb);
        printf("\n");
    }
}

void diemtbmax(SinhVien ds[], int n) {
    int imax = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].dtb > ds[imax].dtb) {
            imax = i;
        }
    }
    printf("Sinh vien co diem trung binh cao nhat:\n");
    printf("MSV: %s\n", ds[imax].masv);
    printf("Ho va ten: %s\n", ds[imax].hoten);
    printf("Tuoi: %d\n", ds[imax].tuoi);
    printf("Diem trung binh: %.2f\n", ds[imax].dtb);
}

void sapxepGiam(SinhVien ds[], int n) {
    SinhVien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].dtb < ds[j].dtb) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("\nDanh sach sau khi sap xep theo diem trung binh (giam dan):\n");
    xuatds(ds, n);
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    SinhVien ds[n];

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        nhapds(&ds[i]);
    }

    printf("\nDanh sach sinh vien vua nhap:\n");
    xuatds(ds, n);

    diemtbmax(ds, n);
    sapxepGiam(ds, n);

    return 0;
}

