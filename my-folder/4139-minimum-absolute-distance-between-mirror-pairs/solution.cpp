class Solution {
public:
    int mirror(int n){
        while(n%10==0) n/=10;
        int ans=0;
        while(n>0){ans*=10; ans+=n%10; n/=10;}
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp; int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])) ans=min(ans,i-mp[nums[i]]);
            mp[mirror(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};
