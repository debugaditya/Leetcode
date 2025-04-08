class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>mp(101,0);
        int ind=-1;
        for(int i=nums.size()-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                ind=i+1;
                break;
            }
        }
        return ceil(ind/3.0);
    }
};
