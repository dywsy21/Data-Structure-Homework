#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int xorshift(unsigned int x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

const int base = 256;

void radixSort(unsigned int *arr, int n) {
    unsigned int *output = (unsigned int *)malloc(n * sizeof(unsigned int));
    unsigned int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    
    if (max == 0) {
        free(output);
        return;
    }

    for (unsigned int exp = 1; exp > 0 && max / exp > 0; exp *= base) {
        int count[256] = {0};

        for (int i = 0; i < n; i++) count[(arr[i] / exp) % base]++;
        for (int i = 1; i < base; i++) count[i] += count[i - 1];
        
        for (int i = n - 1; i >= 0; i--) { // 反过来是因为count(即index)在下降，但是arr是增的，所以要从后往前
            output[count[(arr[i] / exp) % base] - 1] = arr[i];
            count[(arr[i] / exp) % base]--;
        }
        memcpy(arr, output, n * sizeof(unsigned int));
    }
    free(output);
}

int main() {
    int n; unsigned int x0;
    scanf("%d %u", &n, &x0);
    
    unsigned int *arr = (unsigned int *)malloc(n * sizeof(unsigned int));
    if (!arr) return 1;
    
    unsigned int xi = x0;
    for (int i = 0; i < n; i++) {
        xi = xorshift(xi);
        arr[i] = xi;
    }
    
    radixSort(arr, n);
    
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) sum += (unsigned long long)(i + 1) * arr[i];
    
    printf("%u", (unsigned int)(sum % (1ULL << 32)));
    
    free(arr);
    return 0;
}
