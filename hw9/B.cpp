#include <stdio.h>
#include <stdlib.h>

unsigned int xorshift(unsigned int x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

void heapify(unsigned int *heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != i) {
        unsigned int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, n, smallest);
    }
}

void buildHeap(unsigned int *heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

void insertHeap(unsigned int *heap, int *size, unsigned int value) {
    if (*size < 40000000) {
        heap[*size] = value;
        (*size)++;
        buildHeap(heap, *size);
    } else if (value > heap[0]) {
        heap[0] = value;
        heapify(heap, *size, 0);
    }
}

int main() {
    int n; unsigned int x0;
    scanf("%d %u", &n, &x0);
    
    unsigned int *heap = (unsigned int *)malloc(n * sizeof(unsigned int));
    if (!heap) return 1;
    
    int size = 0;
    unsigned int xi = x0;
    
    for (int i = 0; i < n; i++) {
        xi = xorshift(xi);
        insertHeap(heap, &size, xi);
    }
    
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (i + 1) * heap[i];
    }
    
    printf("%llu\n", sum);
    
    free(heap);
    return 0;
}
