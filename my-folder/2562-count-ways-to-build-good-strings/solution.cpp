#include <unordered_map>
using namespace std;

class Solution {
public:
    long long f(int low, int high, long long s, int zero, int one, unordered_map<long long, long long> &memo) {
        if (s > high) return 0;
        if (memo.count(s)) return memo[s];

        long long count = 0;
        if (s >= low) count = 1;

        count = (count + f(low, high, s + zero, zero, one, memo)) % 1000000007;
        count = (count + f(low, high, s + one, zero, one, memo)) % 1000000007;

        return memo[s] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<long long, long long> memo;
        return f(low, high, 0, zero, one, memo);
    }
};



