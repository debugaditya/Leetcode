class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        for(auto it:queries){
            for(int i=it[0];i<=it[1];i+=it[2]){
                nums[i] = (1LL* nums[i] * it[3]) % (1000000007);
            }
        }
        for(auto it:nums) ans^=it;
        return ans;
    }
};
