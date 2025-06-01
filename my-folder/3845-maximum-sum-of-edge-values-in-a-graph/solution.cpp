class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& e) {
        if(e.size()==1) return 2;
        int i=n-3;
        long long ans=1LL*n*(n-1)+1LL*n*(n-2);
        queue<int>q; q.push(n-1); q.push(n-2);
        while(i>0&&!q.empty()){
            ans+=1LL*i*q.front();
            q.pop(); q.push(i);
            i--;
        }
        if(e.size()==n) ans+=1LL*q.front();
        return ans;
    }
};
