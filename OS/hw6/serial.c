#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VECTOR_SIZE 10000
int *vector1, *vector2;

int inner_product = 0;

int main(){
    vector1 = (int *)malloc(sizeof(int)*10000);
    vector2 = (int *)malloc(sizeof(int)*10000);
    for(int i = 0 ; i < VECTOR_SIZE ; i++){
        vector1[i] = 1;
        vector2[i] = 2;
    }

    int time_diff = 0;
    clock_t before = clock();
    
    for(int i = 0 ; i < VECTOR_SIZE ; i++){
        inner_product += vector1[i] * vector2[i];
    }
    
    time_diff = clock() - before;
    printf("Time: %d\n", time_diff);
    printf("Inner Product: %d\n", inner_product);
}