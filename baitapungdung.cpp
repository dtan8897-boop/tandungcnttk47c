#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = (int*) malloc(v->capacity * sizeof(int));
}

void vector_push_back(Vector *v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*) realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_get(Vector *v, int index) {
    if (index >= 0 && index < v->size)
        return v->data[index];
    else
        return -1;
}

void vector_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main() {
    Vector v;
    vector_init(&v);
    int diem;

    while (1) {
        scanf("%d", &diem);
        if (diem == -1) break;
        if (diem < 0 || diem > 100) continue;
        vector_push_back(&v, diem);
    }

    if (v.size == 0) {
        vector_free(&v);
        return 0;
    }

    int tong = 0;
    int max = vector_get(&v, 0);
    int min = vector_get(&v, 0);

    for (int i = 0; i < v.size; i++) {
        int val = vector_get(&v, i);
        tong += val;
        if (val > max) max = val;
        if (val < min) min = val;
    }

    double tb = (double)tong / v.size;

    printf("%d\n", v.size);
    printf("%.2f\n", tb);
    printf("%d\n", max);
    printf("%d\n", min);

    vector_free(&v);
    return 0;
}

