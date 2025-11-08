class Solution {
public:
    long long findnumberofelementsmallerthen(int sum, vector<int>& mp) {
        return upper_bound(mp.begin(), mp.end(), sum - 1) - mp.begin();
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0;
        vector<int> mp;  
        int sum = 0;
        mp.push_back(0); 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) sum++;
            else sum--;
            ans += findnumberofelementsmallerthen(sum, mp);
            mp.insert(upper_bound(mp.begin(), mp.end(), sum), sum);
        }
        return ans;
    }
};

