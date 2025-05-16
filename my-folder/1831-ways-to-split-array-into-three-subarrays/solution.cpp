class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int ans=0;
        vector<int>mp(n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[i]=sum;
        }
        for(int i=0;i<n-2;i++){
            if(3*mp[i]>sum) break;
            int l=i+1;
            int r=n-2;
            int ans1=-1,ans2=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(mp[i]>mp[mid]-mp[i]) l=mid+1;
                else{
                    ans1=mid;
                    r=mid-1;
                }
            }
            l=ans1;
            r=n-2;
            while(l<=r){
                int mid=(l+r)/2;
                if(mp[mid]-mp[i]>sum-mp[mid]) r=mid-1;
                else{
                    ans2=mid;
                    l=mid+1;
                }
            }
            if(ans1==-1||ans2==-1||ans2<ans1) continue;
            ans=(ans+ans2-ans1+1)%1000000007;
        }
        return ans;
    }
};
