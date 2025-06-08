class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string>pq;
        vector<int>ans(n); int k=n-1;
        for(int i=1;i<=n;i++) pq.push(to_string(i));
        while(!pq.empty()){
            ans[k]=stoi(pq.top());
            pq.pop(); k--;
        }
        return ans;
    }
};
