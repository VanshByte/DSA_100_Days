#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    scanf("%s", s);

    int freq[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        freq[idx]++;
        if (freq[idx] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}