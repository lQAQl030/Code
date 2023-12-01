#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* merge_sort(void* data){
    
}

int main(int argc, char **argv){
    FILE* fpin = fopen(argv[1], "r");
    FILE* fpout = fopen(argv[2], "w");

    pthread_t left, right;
    pthread_create(left, NULL, merge_sort, );

    return 0;
}