class Solution {
public:
    int minPartitions(string n) {
        int ans=-1;
        for(auto it:n) ans=max(ans,it-'0');
        return ans;
    }
};
