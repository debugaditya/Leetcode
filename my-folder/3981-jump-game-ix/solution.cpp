class Solution {
public:
    int f(vector<int>& nums,vector<int>& v,int i,vector<int>&mx,vector<int>&ans){
        if(ans[i]!=-1) return ans[i];
        int l=0,r=v.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[v[mid]]>=nums[i]) l=mid+1;
            else r=mid-1;
        }
        if(l==v.size()) return nums[i];
        if(nums[mx[v[l]]]==nums[i]) return nums[i];
        return f(nums,v,mx[v[l]],mx,ans);
    }
    vector<int> maxValue(vector<int>& nums) {
        vector<int>mx(nums.size()),ans(nums.size(),-1),v;
        int mini=INT_MAX,maxi=INT_MIN,idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) {maxi=nums[i]; idx=i;}
            mx[i]=idx;
        }
        for(int i=nums.size()-1;i>=0;i--){
            //if(nums[i]==nums[mx[i]]&&mini==nums[i]) ans[i]=nums[mx[i]];
            if(nums[i]<mini){
                //ans[i]=f(nums,v,mx[i],mx,ans);
                mini=nums[i];
                v.push_back(i);
            }
            ans[i]=f(nums,v,mx[i],mx,ans);
        }
        return ans;
    }
};
