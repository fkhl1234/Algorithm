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

int delay[16] = {0, };
int cost[16] = {0, };

int N;
int max_cost = 0;

void DFS(int start, int sum) {
    if(start + delay[start] - 1 > N) return;
    
    // printf("start : %d\n", start);
    sum += cost[start];

    if(sum > max_cost) max_cost = sum;

    for(int i=start + delay[start]; i<=N; i++) {
        DFS(i, sum);
    }

    return;
}


int main() {
    scanf("%d", &N);

    for(int i=1; i<=N; i++) {
        scanf("%d %d", &delay[i], &cost[i]);
    }

    for(int i=1; i<=N; i++) {
        DFS(i, 0);
    }

    printf("%d\n", max_cost);

    return 0;
}