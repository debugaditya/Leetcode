class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq; long long ans=1;
        for(auto it:nums) pq.push(it);
        while(k--) {int top=pq.top(); top++; pq.pop(); pq.push(top);}
        while(!pq.empty()){
            ans=(1LL*ans*pq.top())%1000000007;
            pq.pop();
        }
        return ans;
    }
};
