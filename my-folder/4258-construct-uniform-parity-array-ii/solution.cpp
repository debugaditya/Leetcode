class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd=INT_MAX,min_eve=INT_MAX;
        for(auto it:nums1){
            if(it%2) min_odd=min(it,min_odd);
            else min_eve=min(it,min_eve);
        }
        if(min_odd==INT_MAX||min_eve==INT_MAX) return true;
        return min_eve-min_odd>=1;
    }
};
