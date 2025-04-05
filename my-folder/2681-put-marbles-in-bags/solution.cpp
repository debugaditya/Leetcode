class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        vector<int> pairSums;
        for (int i = 0; i < w.size() - 1; ++i)
            pairSums.push_back(w[i] + w[i + 1]);

        sort(pairSums.begin(), pairSums.end());

        long long mini = 0, maxi = 0;
        for (int i = 0; i < k - 1; ++i) {
            mini += pairSums[i];
            maxi += pairSums[pairSums.size() - 1 - i];
        }

        return maxi - mini;
    }
};


