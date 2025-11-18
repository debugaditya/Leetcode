class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum=0,ans=INT_MIN;
        unordered_map<int,int>st;
        for(auto it:nums){sum+=it; st[it]++;}
        for(auto it:nums){
            sum-=it; st[it]--;
            if(sum%2==0&&st[sum/2]>0) ans=max(ans,it);
            sum+=it; st[it]++;
        }
        return ans;
    }
};
