#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define INITIAL_CAPACITY 4
#define GROWTH_FACTOR 2
typedef struct{
    double *data;
    int size;
    int capacity;
}VectorDiem;
void vector_init(VectorDiem *v){
    v->size=0;
    v->capacity=INITIAL_CAPACITY;
    v->data=(double*)malloc(sizeof(double)*v->capacity);
}
void vector_free(VectorDiem *v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}
void vector_push_back(VectorDiem *v, double index){
    if(v->size>=v->capacity){
        v->capacity*=GROWTH_FACTOR;
        v->data=(double*)realloc(v->data, sizeof(double)*v->capacity);
        printf("Vector da mo rong dung luong len %d\n", v->capacity);
    }
    v->data[v->size]=index;
    v->size++;
}
double vector_get(VectorDiem *v, int index){
    if(index<0||index>=v->size){
        printf("Loi: Index %d nam ngoai pham vi Vector\n",index);
        return -1;
    }
    return v->data[index];
}
void testVector(){
    VectorDiem v;
    vector_init(&v);
    printf("Vector (size: %d, capacity: %d): [", v.size,v.capacity);
    printf("]\n");
    vector_push_back(&v, 5.5);
    vector_push_back(&v, 6.5);
    vector_push_back(&v, 7.0);
    vector_push_back(&v, 8.5);
    vector_push_back(&v, 9.0);
    printf("Vector (size: %d, capacity: %d): [", v.size,v.capacity);
    for(int i=0; i<v.size; i++){
        printf("%.2lf",v.data[i]);
        if(i<v.size-1){
            printf(",");
        }
    }
    printf("]\n");
    int tong=v.size;
    printf("Tong so sinh vien da nhap: %d\n", tong);
    double sum=0.0;
    double max=-1.0;
    double min=11.0;
    for(size_t i=0; i<tong; i++) {
        double current=vector_get(&v, i);
        sum += current;
        if (current>max){
            max=current;
        }
        if (current<min){
            min=current;
        }
    }
    double dtb=sum/tong;
    printf("2. Diem trung binh: %.2lf\n", dtb);
    printf("3. Diem cao nhat: %.2lf\n", max);
    printf("4. Diem thap nhat: %.2lf\n", min);
}
main(){
    testVector();
    return 0;
}
