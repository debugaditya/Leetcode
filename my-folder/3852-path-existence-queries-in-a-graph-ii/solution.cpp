class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int d, vector<vector<int>>& q) {
        vector<pair<int,int>>v; vector<int>mp(n),res;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) mp[v[i].second]=i;
        int r=0; int LOG = log2(n)+1;
        vector<vector<int>>up(n,vector<int>(LOG));
        for(int i=0;i<n;i++){
            r=max(r,i);
            while(r<n&&v[r].first-v[i].first<=d) r++;
            up[i][0]=r-1;
        }
        for(int j=1;j<LOG;j++) for(int i=0;i<n;i++) up[i][j]=up[up[i][j-1]][j-1];
        for(auto it:q){
            int src=min(mp[it[0]],mp[it[1]]);
            int des=max(mp[it[0]],mp[it[1]]);
            if(src==des) {res.push_back(0); continue;}
            int ans=0;
            for(int j=LOG-1;j>=0;j--) if(up[src][j]<des) {ans+=(1<<j); src=up[src][j];}  
            if(up[src][0]>=des) res.push_back(ans+1);
            else res.push_back(-1);
        }
        return res;
    }
};
