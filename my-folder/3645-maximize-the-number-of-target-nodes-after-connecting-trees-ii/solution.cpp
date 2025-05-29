class Solution {
public:
    void f(vector<vector<int>>&adj,int node,unordered_set<int>&even,int level,vector<int>&vis){
        if(vis[node]) return;
        if(level%2==0) even.insert(node);
        vis[node]=1;
        for(auto it:adj[node]) f(adj,it,even,level+1,vis);
        return;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        vector<vector<int>>t1(e1.size()+1); vector<vector<int>>t2(e2.size()+1);
        unordered_set<int>even2; unordered_set<int>even1;
        vector<int>vis1(e1.size()+1,0); vector<int>vis2(e2.size()+1,0);
        for(auto it:e1){
            t1[it[0]].push_back(it[1]);
            t1[it[1]].push_back(it[0]);
        }
        for(auto it:e2){
            t2[it[0]].push_back(it[1]);
            t2[it[1]].push_back(it[0]);
        }
        f(t1,0,even1,0,vis1);
        f(t2,0,even2,0,vis2);
        vector<int>ans(e1.size()+1);
        for(int i=0;i<ans.size();i++){
            ans[i]=max(even2.size(),e2.size()+1-even2.size());
            if(even1.count(i)) ans[i]+=even1.size();
            else ans[i]+=e1.size()+1-even1.size();
        }
        return ans;
    }
};
