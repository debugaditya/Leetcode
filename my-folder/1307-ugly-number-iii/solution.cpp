class Solution {
public:
    typedef long long ll;
    
    ll gcd(ll a, ll b){
        return b==0 ? a : gcd(b,a%b);
    }
    
    ll lcm(ll a, ll b){
        return a/gcd(a,b)*b;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a,b), bc = lcm(b,c), ca = lcm(c,a);
        ll abc = lcm(a,bc);
        
        ll low = 1, high = 2e18, ans = 1;
        
        while(low <= high){
            ll mid = (low + high)/2;
            ll cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ca + mid/abc;
            if(cnt >= n){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

