class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int>f(arr.size(),-1);
        unordered_map<int,int>mp,mp1; int sum=0,mini1=INT_MAX,mini2=INT_MAX,ans=INT_MAX; mp[0]=-1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mp.count(sum-target))mini1=min(mini1,i-mp[sum-target]);
            f[i]=mini1; mp[sum]=i;
        }
        sum=0; mp1[0]=arr.size();
        for(int i=arr.size()-1;i>0;i--){
            sum+=arr[i];
            if(mp1.count(sum-target)) mini2=min(mini2,mp1[sum-target]-i);
            if(f[i-1]!=INT_MAX&&mini2!=INT_MAX) ans=min(ans,mini2+f[i-1]); 
            mp1[sum]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};
