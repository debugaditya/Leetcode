class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int>v;
        int mini=INT_MAX;
        for(auto it:cost){
            mini=min(mini,it);
            v.push_back(mini);
        }
        return v;
    }
};
