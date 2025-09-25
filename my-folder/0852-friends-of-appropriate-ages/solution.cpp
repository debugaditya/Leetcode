class Solution {
public:
    int f(vector<int>& ages,int n,int i){
        int l=0,r=i,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(ages[mid]>n) {ans=mid; r=mid-1;}
            else l=mid+1;
        }
        return ans;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end()); vector<int>mp(1001,0); int ans=0;
        for(int i=0;i<ages.size();i++){
            if(ages[i]<=14) continue;
            int idx=f(ages,ages[i]/2+7,i); mp[ages[i]]++;
            if(idx!=-1) ans+=i-idx;
        }
        for(auto it:mp) ans+=it*(it-1)/2;
        return ans;
    }
};
