#include <stdio.h>
#include <string.h>

#define MAX 10005

int main() {
    int arr[MAX], n = 0;

    while (scanf("%d", &arr[n]) == 1)
        n++;

    int prefSum[MAX], prefIdx[MAX];
    int mapSize = 0;

    prefSum[mapSize] = 0;
    prefIdx[mapSize++] = -1;

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int found = -2;
        for (int j = 0; j < mapSize; j++) {
            if (prefSum[j] == sum) {
                found = prefIdx[j];
                break;
            }
        }

        if (found != -2) {
            int len = i - found;
            if (len > maxLen) maxLen = len;
        } else {
            prefSum[mapSize] = sum;
            prefIdx[mapSize++] = i;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}