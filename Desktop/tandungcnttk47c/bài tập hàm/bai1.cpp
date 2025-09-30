#include <stdio.h>
#include <math.h>
float dientichtamgiac(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        return 0.0;
    }
    float p = (a + b + c) / 2.0; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
float Phanloaitamgiac(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("Ba canh nay khong tao thanh tam giac.\n");
        return -1;
    }
    int deu = 0;
    int can = 0;
    int vuong = 0;
    float es = 0.0001;
    if (a == b && a == c) {
        deu = 1;
    } else if (a == b || a == c || c == b) {
        can = 1;
    }
    if (fabs(a * a + b * b - c * c) < es || fabs(a * a + c * c - b * b) < es || fabs(b * b + c * c - a * a) < es) {
        vuong = 1;
    }
    if (deu) {
        printf("tam giac deu\n");
    } else if (vuong && can) { 
        printf("tam giac vuong can\n");
    } else if (vuong) {
        printf("tam giac vuong\n");
    } else if (can) {
        printf("tam giac can\n");
    } else {
        printf("tam giac thuong\n");
    }
    return 0;
}

int main() {
    float a, b, c, dientich;
    
    printf("Nhap a: ");
    scanf("%f", &a);
    printf("Nhap b: ");
    scanf("%f", &b);
    printf("Nhap c: ");
    scanf("%f", &c);
    if (Phanloaitamgiac(a, b, c) == 0) { 
        dientich = dientichtamgiac(a, b, c);
        printf("dien tich tam giac: %.2f\n", dientich);
    }
    return 0;
}
