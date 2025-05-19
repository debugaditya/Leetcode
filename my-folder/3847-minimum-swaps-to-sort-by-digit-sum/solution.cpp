class Solution {
public:
    int sum(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>v;
        vector<int>s;
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){v.push_back({sum(nums[i]),nums[i]}); mp[nums[i]]=i;}
        sort(v.begin(),v.end());
        for(auto it:v){ s.push_back(it.second); cout<<it.second<<" ";}
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=s[i]){
                mp[nums[i]]=mp[s[i]];
                swap(nums[i],nums[mp[s[i]]]);
                cnt++;
            }
        }
        return cnt;
    }
};
