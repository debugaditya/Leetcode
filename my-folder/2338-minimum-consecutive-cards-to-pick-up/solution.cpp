class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int mini=INT_MAX;
        int maxi=*max_element(c.begin(),c.end());
        vector<int>mp(maxi+1,-1);
        for(int i=0;i<c.size();i++){
            if(mp[c[i]]!=-1) mini=min(mini,i-mp[c[i]]+1);
            mp[c[i]]=i;
        }
        return mini==INT_MAX?-1:mini;
    }
};
