class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int>pq; long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(pq.empty()){ans+=nums[i];}
                else if(nums[i]>pq.top()){ans+=nums[i];}
                else {ans+=pq.top(); pq.pop(); pq.push(nums[i]);}
            }
            else pq.push(nums[i]);
        }
        return ans;
    }
};
