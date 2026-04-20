class Solution {
public:
    int maxDistance(vector<int>& c) {
        int ans=0,first_diff=-1;
        for(int i=0;i<c.size();i++){
            if(c[i]!=c[0]&&first_diff==-1) first_diff=i;
            if(c[i]!=c[0]) ans=max(ans,i);
            else ans=max(ans,i-first_diff);
        }
        return ans;
    }
};
