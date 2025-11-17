class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt=k;
        for(auto it:nums){
            if(it==1){
                if(cnt<k) return false;
                cnt=0;
            }
            else cnt++;
        }
        return true;
    }
};
