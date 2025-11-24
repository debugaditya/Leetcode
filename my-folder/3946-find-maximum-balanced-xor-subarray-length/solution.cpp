class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>mp; mp[{0,0}]=-1; int sum=0,j=0,ans=0;
        for(int i=0;i<nums.size();i++){
            j^=nums[i]; sum+=nums[i]%2==0?1:-1;
            if(mp.count({j,sum})) ans=max(i-mp[{j,sum}],ans);
            else mp[{j,sum}]=i;
        }
        return ans;
    }
};
