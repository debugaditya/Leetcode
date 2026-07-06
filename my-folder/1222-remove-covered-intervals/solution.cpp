class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end()); vector<vector<int>>v;
        for(int p=1;p<i.size();p++) if(i[p][0]!=i[p-1][0]) v.push_back(i[p-1]);
        v.push_back(i.back()); int ans=v.size(),maxi=v[0][1];
        for(int p=1;p<v.size();p++) {
            if(v[p][1]<=maxi) ans--;
            maxi=max(maxi,v[p][1]);
        } 
        return ans;
    }
};
