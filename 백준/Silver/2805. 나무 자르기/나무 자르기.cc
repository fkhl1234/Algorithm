#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);

    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int tree[1000000];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int max = 0;
    int max_idx = 0;

    for(int i=0; i<N; i++) {
        scanf("%d", &tree[i]);
        if(max < tree[i]) {
            max = tree[i];
        }
    }

    // quickSort(tree, 0, N-1);

    // for(int i=0; i<N; i++) {
    //     printf("%d ", tree[i]);
    // }

    int low = 0;
    int high = max;

    while(low <= high) {
        int pi = (low + high)/2;
        long long int sum = 0;

        for(int i=0; i<N; i++) {
            sum += (tree[i] > pi) ? tree[i] - pi : 0;
        }

        // printf("su : %d\n", high);

        if(sum >= M) low = pi+1;
        else high = pi-1;
    }

    printf("%d\n",high);

    return 0;
}