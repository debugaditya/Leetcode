class Solution {
public:
    long long f(int t, int mode, const vector<int>* a, const vector<int>* b,
                vector<vector<long long>>& dp) {

        int n = a->size();
        if (t >= n) return 0;

        long long &res = dp[t][mode];
        if (res != -1) return res;

        // local references for speed
        const vector<int>& A = *a;
        const vector<int>& B = *b;

        long long pick = (mode == 0 ? A[t] : B[t]) + f(t + 1, mode, a, b, dp);
        long long notpick = f(t + 1, mode ^ 1, a, b, dp);

        res = (pick > notpick ? pick : notpick);
        return res;
    }

    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return max(
            f(0, 0, &a, &b, dp),
            f(0, 1, &a, &b, dp)
        );
    }
};

