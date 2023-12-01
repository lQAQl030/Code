#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int SIZE = 0;
int arr[10000];

void* merge_sort(void* data){
    int *mid = (int*) data;
    pthread_t left, right;
    pthread_create()
}

int main(int argc, char **argv){
    FILE* fpin = fopen(argv[1], "r");
    FILE* fpout = fopen(argv[2], "w");
    while(fscanf(fpin, "%d", &arr[SIZE]) == 1) SIZE++;

    int mid = SIZE / 2;

    pthread_t t;
    pthread_create(t, NULL, merge_sort, mid);

    return 0;
}