class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int>mp(26,0);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:s) mp[it-'a']++;
        for(auto it:mp) if(it>0) pq.push(it);
        int uni=pq.size();
        if(uni<=k) return 0; int ans=0;
        for(int i=1;i<=uni-k;i++) {ans+=pq.top(); pq.pop();}
        return ans;
    }
};
