class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt=count(nums.begin(),nums.end(),0); int ans=cnt;
        if(cnt==nums.size()) return 0;
        for(int i=nums.size()-1;i>=nums.size()-cnt;i--){
            if(nums[i]==0) ans--;
        }
        return ans;
    }
};
