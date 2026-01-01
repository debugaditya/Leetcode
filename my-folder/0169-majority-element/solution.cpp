class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0; int cand=0;
        for(auto it:nums){
            if(cnt==0) cand=it;
            cnt+=cand==it?1:-1;
        }
        return cand;
    }
};
