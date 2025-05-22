class Solution {
public:
    char slowestKey(vector<int>& r, string k) {
        int prev=0; int maxi=0; char ans='a';
        for(int i=0;i<r.size();i++){
            if(maxi<r[i]-prev) ans=k[i];
            if(maxi==r[i]-prev) ans=max(ans,k[i]);
            maxi=max(maxi,r[i]-prev);
            prev=r[i];
        }
        return ans;
    }
};
