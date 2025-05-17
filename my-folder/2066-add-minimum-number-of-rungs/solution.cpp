class Solution {
public:
    int addRungs(vector<int>& r, int d) {
        int ans=0;
        int curr=0;
        for(int i=0;i<r.size();i++){
            ans+=(r[i]-curr)/d;
            if((r[i]-curr)%d==0) ans--;
            curr=r[i];
        }
        return ans;
    }
};
