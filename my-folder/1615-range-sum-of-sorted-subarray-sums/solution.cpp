class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int>s;
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                s.push_back(sum);
            }
        }
        sort(s.begin(),s.end());
        for(int i=l-1;i<=r-1;i++) ans=(ans+s[i])%1000000007;
        return ans;
    }
};
