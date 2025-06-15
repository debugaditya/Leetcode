class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int mini=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<c.size();i++){
            if(mp.count(c[i])) mini=min(mini,i-mp[c[i]]+1);
            mp[c[i]]=i;
        }
        return mini==INT_MAX?-1:mini;
    }
};
