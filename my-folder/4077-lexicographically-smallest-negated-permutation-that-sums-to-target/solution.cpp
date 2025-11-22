class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum=1LL*n*(n+1)/2; long long diff=1LL*(sum-target);
        if(diff<0||(diff)%2!=0||target<-sum) return {};
        vector<int>ans;
        for(int i=n;i>=1;i--){
            if(diff>=2*i){
                diff-=2*i;
                ans.push_back(-i);
            }
            else ans.push_back(i);
        }
        if(diff!=0) return {};
        sort(ans.begin(),ans.end());
        return ans;
    }
};
