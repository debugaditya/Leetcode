class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {
        int maxi=-1,cnt=0;
        sort(p.begin(),p.end());
        for(auto it:p){
            if(it[0]<=maxi) continue;
            cnt++; maxi=it[0]+w;
        }
        return cnt;
    }
};
