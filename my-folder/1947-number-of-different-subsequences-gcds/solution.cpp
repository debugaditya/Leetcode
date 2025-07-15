class Solution {
public:
    int gcd(int x,int y){
        if(min(x,y)==0) return max(x,y);
        return gcd(max(x,y)%min(x,y),min(x,y));
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<bool> present(maxNum + 1, false);
        for (int num : nums) present[num] = true;
        
        int ans = 0;
        for (int i = 1; i <= maxNum; i++) {
            int g = 0;
            for (int j = i; j <= maxNum; j += i) {
                if (present[j]) {
                    g = gcd(g, j);
                    if (g == i) break; // already confirmed
                }
            }
            if (g == i) ans++;
        }
        return ans;
    }
};
