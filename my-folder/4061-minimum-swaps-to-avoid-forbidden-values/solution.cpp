class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        unordered_map<int,int> freqNums, freqForb, bad;

        int B = 0;
        for (int i = 0; i < n; i++) {
            freqNums[nums[i]]++;
            freqForb[forbidden[i]]++;
            if (nums[i] == forbidden[i]) {
                bad[nums[i]]++;
                B++;
            }
        }

        // Feasibility check (THIS was missing earlier)
        for (auto &[x, c] : freqNums) {
            if (c > n - freqForb[x]) return -1;
        }

        if (B == 0) return 0;

        int mx = 0;
        for (auto &[_, c] : bad)
            mx = max(mx, c);

        return max(mx, (B + 1) / 2);
    }
};

