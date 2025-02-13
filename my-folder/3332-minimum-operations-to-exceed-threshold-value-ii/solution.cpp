class Solution {
public:
    int minOperations(vector<int>& nums, long long k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(),nums.end());
        int cnt=0;
        while(pq.top()<k){
            long long num1=2*pq.top();
            pq.pop();
            long long num2=pq.top();
            pq.pop();
            pq.push(num1+num2);
            cnt++;
        }
        return cnt;
    }
};
