#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int n, int* arr){
    int j, i, key;

    for (j = 1; j < n; j++){
        key = *(arr + j);
        i = j - 1;
        while((i >= 0) && (*(arr + i) >= key)){
            *(arr + (i + 1)) = *(arr + i);
            i--;
        }
        *(arr + (i + 1)) = key;
    }
}

void selection_sort(int n, int* arr){
    int j, i, m;

    for(j = 0; j < (n - 1); j++){
        m = j;
        for(i = (j + 1); i < n; i++){
            if(*(arr + i) < *(arr + m)) {
                m = i;
            }
        }
        int temp = *(arr + j);
        *(arr + j) = *(arr + m);
        *(arr + m) = temp;
    }
}

void print(int n, const int* arr){
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
}

int main(){

    int *arr;
    int i, k;
    int size = 1000;
    clock_t start, end;
    double cpu_time_used;

    for (k = 0; k < 5; k++){
        arr = malloc(sizeof(int) * size);

        for (i = 0; i < size; i++ )
            *(arr + i) = size - i;

        start = clock();
        selection_sort(size, arr);
        end = clock();
        cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
        printf("selection\t\t%d\t%lf\n", size, cpu_time_used);

        start = clock();
        insertion_sort(size, arr);
        end = clock();
        cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
        printf("best insertion\t%d\t%lf\n", size, cpu_time_used);

        for (i = 0; i < size; i++ )
            *(arr + i) = size - i;

        start = clock();
        insertion_sort(size, arr);
        end = clock();
        cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
        printf("worst insertion\t%d\t%lf\n", size, cpu_time_used);

        size = size * 2;
        free(arr);

    }

    return 0;
}
