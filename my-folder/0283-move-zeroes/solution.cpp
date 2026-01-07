class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int>pq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) pq.push(i);
            else{
                if(pq.empty()) continue;
                swap(nums[i],nums[pq.front()]);
                pq.pop(); pq.push(i);
            }
        }
    }
};
