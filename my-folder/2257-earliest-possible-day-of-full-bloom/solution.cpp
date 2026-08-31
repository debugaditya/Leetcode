class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<vector<int>>v; int maxi=0,curr=0;
        for(int i=0;i<p.size();i++) v.push_back({g[i],p[i]});
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            maxi=max(maxi,curr+v[i][0]+v[i][1]);
            curr+=v[i][1];
        }
        return maxi;
    }
};
