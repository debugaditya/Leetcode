class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int>ans={-1,-1}; int maxi=-1;
        for(auto it:towers){
            int dist=abs(it[0]-center[0])+abs(it[1]-center[1]);
            if(dist>radius) continue;
            if(it[2]>maxi){maxi=it[2]; ans={it[0],it[1]};}
            else if(it[2]==maxi){
                if(it[0]<ans[0]) ans={it[0],it[1]};
                else if(it[0]==ans[0]&&it[1]<ans[1]) ans={it[0],it[1]};
            }
        }
        return ans;
    }
};
