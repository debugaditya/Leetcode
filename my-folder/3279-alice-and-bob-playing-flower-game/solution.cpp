class Solution {
public:
    long long flowerGame(int n, int m) {
        int even1=n/2,even2=m/2,odd1=n/2+n%2,odd2=m/2+m%2;
        long long ans= 1LL*(1LL*even1*odd2+1LL*even2*odd1);
        return ans;
    }
};
