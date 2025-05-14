class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt=1;
        unordered_set<int>st;
        sort(pick.begin(),pick.end());
        if(pick[0][0]==0) st.insert(0);
        for(int i=1;i<pick.size();i++){
            if(pick[i][0]==0) continue;
            if(pick[i-1][0]!=pick[i][0]) cnt=1;
            else if(pick[i-1][1]==pick[i][1]){
                cnt++;
                if(cnt==pick[i][0]+1) st.insert(pick[i][0]);
            }
            else cnt=1;
            
        }   
        return st.size();
    }
};
