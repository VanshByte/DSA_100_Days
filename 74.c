#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][50];
    char unique[1000][50];
    int freq[1000] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);

        int found = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(unique[uniqueCount], names[i]);
            freq[uniqueCount++]++;
        } else {
            freq[found]++;
        }
    }

    int maxVotes = 0;
    char winner[50] = "";

    for (int i = 0; i < uniqueCount; i++) {
        if (freq[i] > maxVotes ||
           (freq[i] == maxVotes && strcmp(unique[i], winner) < 0)) {
            maxVotes = freq[i];
            strcpy(winner, unique[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}