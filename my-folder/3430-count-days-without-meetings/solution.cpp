class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end()); int ans=m[0][0]-1; int maxi=m[0][1];
        for(int i=1;i<m.size();i++){
            if(m[i][0]>maxi) ans+=m[i][0]-maxi-1;
            maxi=max(maxi,m[i][1]);
        }
        ans+=days-maxi;
        return ans;
    }
};
