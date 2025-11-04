#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INITIAL_CAPACITY 4
#define GROWTH_FACTOR 2
typedef struct{
    int *data;
    int size;
    int capacity;
}Vector;
void vector_init(Vector *v){
    v->size=0;
    v->capacity=INITIAL_CAPACITY;
    v->data=(int*)malloc(sizeof(int)*v->capacity);
    if (v->data == NULL) {
        perror("Loi cap phat bo nho");
        exit(EXIT_FAILURE);
    }
}
void vector_free(Vector *v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}
void vector_resize(Vector *v){
    if(v->size>=v->capacity){
        v->capacity*=GROWTH_FACTOR;
        v->data=(int*)realloc(v->data, sizeof(int)*v->capacity);
        printf("Vector da mo rong dung luong len %d\n", v->capacity);
    }
}
void vector_push_back(Vector *v, int value){
    vector_resize(v);
    v->data[v->size]=value;
    v->size++;
}
int vector_get(Vector *v, int index){
    if(index<0||index>=v->size){
        printf("Loi: Index %d nam ngoai pham vi Vector\n",index);
        return -1;
    }
    return v->data[index];
}
void vector_set(Vector *v, int index, int value){
    if(index<0||index>=v->size){
        printf("Loi: Vector rong\n");
        return;
    }
    v->data[index]=value;
}
void vector_pop_back(Vector *v) {
    if(v->size==0) {
        printf("Loi: Vector rong");
        return;
    }
    v->size--;
}
void vector_remove_at(Vector *v, int index){
    if(index<0||index>=v->size){
        printf("Loi: Index %d nam ngoai pham vi Vector\n",index);
        return;
    }
    for(int i=index; i<v->size-1; i++){
        v->data[i]=v->data[i+1];
    }
    v->size--;
}
int vector_size(Vector *v){
    return v->size;
}
void vector_print(Vector *v){
    printf("Vector (size: %d, capacity: %d): [", v->size,v->capacity);
    for(int i=0; i<v->size; i++){
        printf("%d",v->data[i]);
        if(i<v->size-1){
            printf(",");
        }
    }
    printf("]\n");
}
void testVector(){
    Vector myVector;
    vector_init(&myVector);
    vector_print(&myVector);
    vector_push_back(&myVector, 10);
    vector_push_back(&myVector, 20);
    vector_push_back(&myVector, 30);
    vector_push_back(&myVector, 40);
    vector_print(&myVector);
    vector_push_back(&myVector, 50);
    vector_print(&myVector);
    printf("vector_get(2): %d\n", vector_get(&myVector, 2));
    printf("vector_get(10): %d\n", vector_get(&myVector, 10));
    vector_set(&myVector, 1, 22);
    printf("Sau vector_set(1, 22): ");
    vector_print(&myVector);
    vector_pop_back(&myVector);
    printf("Sau vector_pop_back(): ");
    vector_print(&myVector);
    vector_remove_at(&myVector, 1);
    printf("Sau vector_remove_at(1): ");
    vector_print(&myVector);
    printf("Kich thuoc hien tai: %d\n", vector_size(&myVector));
    printf("\n---Giai phong bo nho---\n");
    vector_free(&myVector);
    printf("Sau khi giai phong bo nho(data = %p)\n", (void*)myVector.data);
    return 0;
}
main(){
    testVector();
    return 0;
}
