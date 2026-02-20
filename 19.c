#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int absVal(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    int left = 0, right = n - 1;
    int minSum = arr[left] + arr[right];
    int a = arr[left], b = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (absVal(sum) < absVal(minSum)) {
            minSum = sum;
            a = arr[left];
            b = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", a, b);
    return 0;
}