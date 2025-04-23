class Solution {
public:
    void f(vector<int>v,set<pair<int,int>>&st){
        for(int i=0;i<=v[2];i++){
            int y=sqrt(v[2]*v[2]-i*i);
            for(int j=0;j<=y;j++){
                st.insert({v[0]+i,v[1]+j});
                st.insert({v[0]-i,v[1]+j});
                st.insert({v[0]+i,v[1]-j});
                st.insert({v[0]-i,v[1]-j});
            }
        }
        return;
    }
    int countLatticePoints(vector<vector<int>>& c) {
        set<pair<int,int>>st;
        for(auto it:c) f(it,st);
        return st.size();
    }
};
