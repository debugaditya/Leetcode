class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>v(nums.size()+1,0);
        int sum=0;
        for(auto &it:q){
            v[it[0]]++;
            v[it[1]+1]--;
        }
        for(int i=0;i<nums.size();i++){
            sum+=v[i]; 
            if(sum<nums[i]) return false;
        }
        return true;
    }
};
