class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(n>3*limit) return 0;
        long long total = 1LL * (n + 1) * (n + 2) / 2;
        if(n<limit) return total;
        int over = limit + 1;
        if (n - over >= 0) total -= 3LL * (1LL * (n - over + 1) * (n - over + 2) / 2);
        if (n - 2 * over >= 0) total += 3LL * (1LL * (n - 2 * over + 1) * (n - 2 * over + 2) / 2);
        return total;
    }
};

