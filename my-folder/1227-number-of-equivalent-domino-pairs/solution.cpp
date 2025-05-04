class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        vector<vector<int>>mp(10,vector<int>(10,0));
        int ans=0;
        for(auto it:d){
            int mini=min(it[0],it[1]);
            int maxi=max(it[0],it[1]);
            ans+=mp[mini][maxi];
            mp[mini][maxi]++;
        }
        return ans;
    }
};
