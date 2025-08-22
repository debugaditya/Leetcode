class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,bool>mp; int cnt=0,ans=0;
        for(auto it:nums) mp[it]=true;
        for(auto it:mp){
            if(!mp.count(it.first-1)){
                cnt=0; int a=it.first;
                while(mp.count(a)){
                    cnt++;
                    a++;
                }
                ans=max(cnt,ans);
            }
            
        }
        return ans;
    }
};
