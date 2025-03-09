class Solution {
    private: 
    void f(vector<vector<int>>& i,vector<int>&visited,queue<int>q,int node){
        q.push(node);
        while(!q.empty()){
            for(int j=0;j<i.size();j++) if(i[q.front()][j]==1&&visited[j]==0) q.push(j);
            visited[q.front()]=1;
            q.pop();
        }
        return;
    }
public:
    
    int findCircleNum(vector<vector<int>>& i) {
        queue<int>q;
        int cnt=0;
        vector<int>visited(i.size(),0);
        for(int k=0;k<i.size();k++){
            if(visited[k]==0){
                cnt++;
                f(i,visited,q,k);
            }
        }
        return cnt;
    }
};
