class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>pq(nums.begin(),nums.end());
        while(pq.size()>1){
            int maxi1=pq.top(); pq.pop();
            int maxi2=pq.top(); pq.pop();
            if(maxi1!=maxi2) pq.push(maxi1-maxi2);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
