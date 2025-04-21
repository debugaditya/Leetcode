class Solution {
public:
    int numberOfArrays(vector<int>& d, long long lower, long long upper) {
        long long l=lower;
        long long u=upper;
        for(auto it:d){
            l=max(lower,l+it);
            u=min(upper,u+it);
        }
        return u-l+1<0?0:u-l+1;
    }
};
