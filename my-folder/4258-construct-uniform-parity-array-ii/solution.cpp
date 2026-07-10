class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        bool odd=false; 
        for(auto &it:nums1){
            if(it%2) odd=true;
            mini=min(mini,it);
        }
        if(mini%2||!odd) return true;
        return false;
    }
};
