class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans=0,dec=0;
        sort(h.begin(),h.end());
        for(int i=h.size()-1;i>=0;i--){
            ans+=max(1LL*0,h[i]-dec);
            dec++; k--; if(h[i]-dec<=0||k==0) return ans;
        }
        return ans;
    }
};
