#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n < 2) {
        printf("%lld\n", n);
        return 0;
    }

    long long lo = 1, hi = n / 2, ans = 1;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid * mid == n) {
            printf("%lld\n", mid);
            return 0;
        } else if (mid * mid < n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}