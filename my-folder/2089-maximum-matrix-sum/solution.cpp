class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0; int mini=INT_MAX; int cnt=0;
        for(auto it:matrix) for(auto it1:it) {sum+=abs(it1); mini=min(mini,abs(it1)); if(it1<=0) {cnt++;}}
        if(cnt%2==1) sum-=2*mini;
        return sum;
    }
};
