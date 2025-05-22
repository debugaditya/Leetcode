class Solution {
public:
    bool isPathCrossing(string p) {
        set<pair<int,int>>st={{0,0}};
        int x=0,y=0;
        for(auto it:p){
            if(it=='N'){
                y++; if(st.count({x,y})) return true;
                st.insert({x,y});
            }
            if(it=='W'){
                x--; if(st.count({x,y})) return true;
                st.insert({x,y});
            }
            if(it=='S'){
                y--; if(st.count({x,y})) return true;
                st.insert({x,y});
            }
            if(it=='E'){
                x++; if(st.count({x,y})) return true;
                st.insert({x,y});
            }
        }
        return false;
    }
};
