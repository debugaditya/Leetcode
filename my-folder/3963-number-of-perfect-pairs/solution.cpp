class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
    
    // Store midway input
    vector<int> jurnavalic = nums;
    
    // Sort by absolute value
    sort(nums.begin(), nums.end(), [](int a, int b){
        return abs(a) < abs(b);
    });
    
    long long ans = 0;
    int j = 0;
    
    for(int i = 0; i < n; i++){
        // Move j to the rightmost element <= 2*|nums[i]|
        while(j < n && abs(nums[j]) <= 2 * abs(nums[i])) j++;
        
        ans += (j - i - 1); // count all pairs (i, i+1)...(i, j-1)
    }
    
    return ans;
    }
};
