class Solution {
public:
    void f(vector<vector<int>>&adj,int start,int node,int target,vector<int>&vis,int&cnt){
        if(target<0||vis[node]) return;
        cnt++;
        vis[node]=1;
        for(auto it:adj[node]) f(adj,start,it,target-1,vis,cnt);
        return;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
        vector<vector<int>>t1(e1.size()+1); vector<vector<int>>t2(e2.size()+1);
        vector<int>vis1(e1.size()+1,0); vector<int>vis2(e2.size()+1,0);
        int cnt1=0,cnt2=0,maxi=0; vector<int>ans;
        for(auto it:e1){
            t1[it[0]].push_back(it[1]);
            t1[it[1]].push_back(it[0]);
        }
        for(auto it:e2){
            t2[it[0]].push_back(it[1]);
            t2[it[1]].push_back(it[0]);
        }
        for(int i=0;i<=e1.size();i++){
            f(t1,i,i,k,vis1,cnt1);
            ans.push_back(cnt1); cnt1=0;
            fill(vis1.begin(),vis1.end(),0);
        }
        for(int i=0;i<=e2.size();i++){
            f(t2,i,i,k-1,vis2,cnt2);
            maxi=max(cnt2,maxi); cnt2=0;
            fill(vis2.begin(),vis2.end(),0);
        }
        for(auto &it:ans) it+=maxi;
        return ans;
    }
};
