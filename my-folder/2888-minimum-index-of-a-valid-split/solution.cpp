class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq1, freq2;
        vector<int> mp1(nums.size(), -1), mp2(nums.size(), -1);
        int dom1 = -1, dom2 = -1;

        // Left to Right Pass (Find dominant elements at each index)
        for (int i = 0; i < nums.size(); i++) {
            freq1[nums[i]]++;
            if (freq1[nums[i]] > (i + 1) / 2) dom1 = nums[i];
            if (freq1[dom1] > (i + 1) / 2) mp1[i] = dom1;
        }

        // Right to Left Pass (Find dominant elements at each index)
        for (int i = nums.size() - 1; i >= 0; i--) {
            freq2[nums[i]]++;
            if (freq2[nums[i]] > (nums.size() - i) / 2) dom2 = nums[i];
            if (freq2[dom2] > (nums.size() - i) / 2) mp2[i] = dom2;
        }

        // Finding the Minimum Index where Dominant Elements Match
        for (int i = 0; i < nums.size() - 1; i++) {
            if (mp1[i] != -1 && mp2[i + 1] != -1 && mp1[i] == mp2[i + 1])
                return i;
        }
        return -1;
    }
};

