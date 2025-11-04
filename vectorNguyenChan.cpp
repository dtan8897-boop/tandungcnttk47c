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
void vector_free(Vector *v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}
void test(){
    Vector v_all;
    Vector v_even;
    vector_init(&v_all);
    vector_init(&v_even);
    int num;
    printf("Vector goc (size: %d, capacity: %d): [", v_all.size,v_all.capacity);
    for(int i=0; i<v_all.size; i++){
        printf("%d",v_all.data[i]);
        if(i<v_all.size-1){
            printf(",");
        }
    }
    printf("]\n");
    while(true){
        if(scanf("%d", &num)!=1){
            printf("So vua nhap khong phai la so nguyen");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {};
            continue;
        }
        if(num==-1){
            break;
        }
        vector_push_back(&v_all, num);
    }
    printf("Vector goc (size: %d, capacity: %d): [", v_all.size,v_all.capacity);
    for(int i=0; i<v_all.size; i++){
        printf("%d",v_all.data[i]);
        if(i<v_all.size-1){
            printf(",");
        }
    }
    printf("]\n");
    printf("Loc phan tu chan trong Vector goc\n");
    for(int i=0; i<v_all.size; i++){
        int n=vector_get(&v_all, i);
        if(n%2==0){
            vector_push_back(&v_even, n);
        }
    }
    if(v_even.size==0){
        printf("Khong tim thay so chan");
    }else{
        printf("Vector moi (size: %d, capacity: %d): [", v_even.size,v_even.capacity);
        for(int i=0; i<v_even.size; i++){
            printf("%d",v_even.data[i]);
            if(i<v_even.size-1){
                printf(",");
            }
        }
        printf("]\n");
    }
    vector_free(&v_all);
    vector_free(&v_even);
}
main(){
    test();
    return 0;
}
