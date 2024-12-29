class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int index=-1;
        map<int,int>mp;
        for(int i=nums.size()-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                index=i;
                break;
            }
        }
        int ans=index/3;
        if(index==-1) return 0;
        return ans+1;
    }
};
