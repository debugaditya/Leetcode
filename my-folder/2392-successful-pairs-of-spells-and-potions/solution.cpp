class Solution {
public:
    int search(vector<int>& p, long long s){
        int l=0,r=p.size()-1,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(p[mid]>=s){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans==-1?0:p.size()-ans;
    }
    vector<int> successfulPairs(vector<int>& sp, vector<int>& p, long long s) {
        sort(p.begin(),p.end()); vector<int>ans(sp.size());
        for(int i=0;i<sp.size();i++){
            long long t=ceil(1.0*s/sp[i]);
            ans[i]=search(p,t);
        }
        return ans;
    }
};
