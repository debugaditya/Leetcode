class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0,ans=0,cnt=0; 
        for(auto &it:nums) sum+=it;
        for(auto &it:nums) {cnt+=it; if(it==0&&2*cnt==sum) ans+=2; else if(it==0&&abs(sum-2*cnt)==1) ans++;}
        return ans;
    }
};
