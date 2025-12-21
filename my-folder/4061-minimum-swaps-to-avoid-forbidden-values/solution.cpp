class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& f) {
        unordered_map<int,int>mp,unsafe,mp2; vector<pair<int,int>>v; int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==f[i]) unsafe[f[i]]++;
            mp2[nums[i]]++;
            mp[f[i]]++;
        }
        if(unsafe.size()==0) return 0;
        for(auto it:unsafe) v.push_back({it.second,it.first});
        sort(v.begin(),v.end()); int left=v.back().first,prev=v.back().second;
        for(int i=v.size()-2;i>=0;i--){
            if(left<v[i].first) prev=v[i].second;
            ans+=min(left,v[i].first);
            left=abs(left-v[i].first);
        }
        if(left==0) return ans;
        if(nums.size()-mp[prev]-(mp2[prev]-left)<left) return -1;
        return ans+left;
    }
};
