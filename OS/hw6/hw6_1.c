#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

int THREAD_MAX = 2; // Split two threads
int thread = 0; // current thread
int size = 0; // size of input integer array
int arr[10001]; // array to store input testcase

// Regular merge
void merge(int low, int mid, int high){
    int n_left = mid - low + 1;
    int n_right = high - mid;

    int *left = malloc(sizeof(*left) * n_left);
    int *right = malloc(sizeof(*right) * n_right);

    for(int i = 0 ; i < n_left ; i++) left[i] = arr[low + i];
    for(int i = 0 ; i < n_right ; i++) right[i] = arr[mid+1 + i];

    int idx = low;
    int i = 0, j = 0;

    while(i < n_left && j < n_right){
        if(left[i] < right[j]) arr[idx++] = left[i++];
        else arr[idx++] = right[j++];
    }

    while(i < n_left) arr[idx++] = left[i++];
    while(j < n_right) arr[idx++] = right[j++];

    free(left);
    free(right);
    
    return;
}

// Regular merge sort
void merge_sort(int low, int high){
    int mid = (low + high) / 2;
    if(low < high){
        merge_sort(low, mid);
        merge_sort(mid+1 ,high);
        merge(low, mid, high);
    }
    return;
}

// Thread function
void* merge_sort_thread(void* data){
    // Get current thread(first or second half of the list)
    int now_thread = thread++;

    // Determine the low and high of first/second half array by now_thread
    int low, high;
    if(now_thread == 0){
        low = 0; high = size / 2;
    }else{
        low = size / 2 + 1; high = size - 1;
    }

    // Regular merge sort
    merge_sort(low, high);

    // Exit the current thread
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    // Open input/output files from command line
    FILE* fpin = fopen(argv[1], "r");
    FILE* fpout = fopen(argv[2], "w");

    size_t len;
    char *buffer = NULL;
    // Get testcase from testcase.txt and store it in buffer
    while(getdelim(&buffer, &len, '\n', fpin) != -1){
        // Reset variables
        size = 0;
        thread = 0;

        // Get integer array from buffer
        FILE *my_stream = fmemopen(buffer, strlen(buffer), "r");
        while(fscanf(my_stream, "%d", &arr[size]) == 1) size++;
        fclose(my_stream);

        // Create two threads and do a merge sort individualy
        pthread_t threads[THREAD_MAX];
        for(int i = 0 ; i < THREAD_MAX ; i++) pthread_create(&threads[i], NULL, merge_sort_thread, NULL);
        for(int i = 0 ; i < THREAD_MAX ; i++) pthread_join(threads[i], NULL);

        // Combine two sorted array
        merge(0, (size - 1) / 2 , size - 1);

        // Output the sorted array into output.txt
        for(int i = 0 ; i < size ; i++) fprintf(fpout, "%d ", arr[i]);
        fprintf(fpout, "\n");
    }

    // Close input/output files
    fclose(fpin);
    fclose(fpout);
    
    return 0;
}