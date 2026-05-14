class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0); queue<int>q;
        q.push(start); vis[start]=1;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(arr[i]==0) return true;
            if(i-arr[i]>=0&&!vis[i-arr[i]]) {vis[i-arr[i]]=1; q.push(i-arr[i]);}
            if(i+arr[i]<arr.size()&&!vis[i+arr[i]]) {q.push(i+arr[i]); vis[i+arr[i]]=1;}
        }
        return false;
    }
};
