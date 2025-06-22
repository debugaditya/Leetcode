class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        queue<pair<int,int>>q; vector<int>dist(arr.size(),INT_MAX);
        for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);
        q.push({0,0}); dist[0]=0;
        while(!q.empty()){
            int i=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(i+1<arr.size()&&dist[i+1]>steps+1){
                dist[i+1]=steps+1;
                q.push({i+1,steps+1});
            }
            if(i-1>=0&&dist[i-1]>steps+1){
                dist[i-1]=steps+1;
                q.push({i-1,steps+1});
            }
            for(auto it:mp[arr[i]]){
                if(dist[it]>steps+1){
                    dist[it]=steps+1;
                    q.push({it,steps+1});
                }
            }
            mp[arr[i]].clear();
        }
        return dist[arr.size()-1];
    }
};
