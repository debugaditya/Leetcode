class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1000000007;

        if (n == 1) {
            return r - l + 1;
        }

        vector<long long> up_counts(r + 1, 1);
        vector<long long> down_counts(r + 1, 1);
        
        for (int i = 0; i < l; ++i) {
            up_counts[i] = 0;
            down_counts[i] = 0;
        }

        for (int k = 2; k <= n; ++k) {
            vector<long long> new_up(r + 1, 0);
            vector<long long> new_down(r + 1, 0);
            
            long long prefix_sum_down = 0;
            for (int i = l; i <= r; ++i) {
                new_up[i] = prefix_sum_down;
                prefix_sum_down = (prefix_sum_down + down_counts[i]) % MOD;
            }

            long long suffix_sum_up = 0;
            for (int i = r; i >= l; --i) {
                new_down[i] = suffix_sum_up;
                suffix_sum_up = (suffix_sum_up + up_counts[i]) % MOD;
            }

            up_counts = new_up;
            down_counts = new_down;
        }

        long long total_count = 0;
        for (int i = l; i <= r; ++i) {
            total_count = (total_count + up_counts[i] + down_counts[i]) % MOD;
        }

        return static_cast<int>(total_count);
    }
};
