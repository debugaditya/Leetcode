class Solution {
public:
    int maxCandies(vector<int>& s,vector<int>& c,vector<vector<int>>& keys,vector<vector<int>>& cb,vector<int>&ib) {
        int n=s.size(); int ans=0;
        vector<int>vis(n,0);queue<int>q;
        for(auto it:ib){
            vis[it]=1;
            q.push(it);
        }
        while(!q.empty()){
            int box=q.front();
            q.pop();
            if(s[box]){
                for(auto it:cb[box]){
                    q.push(it);
                    vis[it]=1;
                }
                for(auto it:keys[box]){
                    if(!s[it]&&vis[it]) q.push(it);
                    s[it]=1;
                }
            }
        }
        for(int i=0;i<n;i++) if(s[i]&&vis[i]) ans+=c[i];
        return ans;
    }
};
