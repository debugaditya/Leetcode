class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int maxi=0,ans=0;
        for(auto it:d){
            int dia=it[0]*it[0]+it[1]*it[1];
            if(dia>=maxi){
                if(dia==maxi) ans=max(ans,it[0]*it[1]);
                else ans=it[0]*it[1];
                maxi=dia;
            }
        }
        return ans;
    }
};
