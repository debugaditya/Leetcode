class Solution {
public:
    unordered_set<int>st; vector<vector<int>>dp; vector<bool>vis;
    int f(int pos,int &a, int &b,int &x,int last){
        if(pos<0||st.count(pos)||pos>=dp.size()||vis[pos]) return INT_MAX;
        if(pos==x) return 0;
        if(dp[pos][last]!=-1) return dp[pos][last];
        vis[pos]=true;
        int ans=f(pos+a,a,b,x,1);
        if(last==1) ans=min(ans,f(pos-b,a,b,x,0));
        vis[pos]=false;
        return dp[pos][last]=ans==INT_MAX?INT_MAX:ans+1;
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int maxi=-1; for(auto &it:forbidden) {st.insert(it); maxi=max(maxi,it);}
        vis.resize(5998,false);
        dp.resize(5998,vector<int>(2,-1)); int ans=f(0,a,b,x,1);
        return ans==INT_MAX?-1:ans;
    }
};
