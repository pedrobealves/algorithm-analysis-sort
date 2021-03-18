#include <stdio.h>

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
    int n = 5;
    int arr[] = { 0, 32, 16, 8, 24 };

    insertion_sort(n, arr);
    print(n, arr);

    return 0;
}
