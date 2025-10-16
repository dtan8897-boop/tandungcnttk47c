#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    char masv[20];
    char hoten[50];
    float diem;
} SinhVien;

typedef struct {
    SinhVien data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, SinhVien sv) {
    if (isFull(s)) {
        printf("Stack day!\n");
        return;
    }
    s->data[++(s->top)] = sv;
}

SinhVien pop(Stack *s) {
    SinhVien sv;
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        strcpy(sv.masv, "");
        strcpy(sv.hoten, "");
        sv.diem = 0;
        return sv;
    }
    sv = s->data[s->top--];
    return sv;
}

void nhapSV(SinhVien *sv) {
    printf("Nhap ma SV: ");
    fflush(stdin);
    gets(sv->masv);
    printf("Nhap ho ten: ");
    gets(sv->hoten);
    printf("Nhap diem: ");
    scanf("%f", &sv->diem);
}

void xuatSV(SinhVien sv) {
    printf("%-10s %-25s %.2f\n", sv.masv, sv.hoten, sv.diem);
}

int main() {
    Stack s;
    init(&s);
    int chon;
    do {
        printf("\n1. Them SV vao Stack");
        printf("\n2. Lay SV khoi Stack");
        printf("\n3. Thoat");
        printf("\nChon: ");
        scanf("%d", &chon);
        if (chon == 1) {
            SinhVien sv;
            nhapSV(&sv);
            push(&s, sv);
        } else if (chon == 2) {
            SinhVien sv = pop(&s);
            if (strlen(sv.masv) > 0) {
                printf("Sinh vien vua lay ra:\n");
                xuatSV(sv);
            }
        }
    } while (chon != 3);
    return 0;
}

