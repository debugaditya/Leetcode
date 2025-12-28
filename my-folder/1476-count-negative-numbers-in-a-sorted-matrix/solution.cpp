class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto it:grid) ans+=it.size()-(upper_bound(it.begin(),it.end(),0,greater<int>())-it.begin());
        return ans;
    }
};
