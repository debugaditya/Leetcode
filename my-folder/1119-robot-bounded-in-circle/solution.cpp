class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}}; int d=0,x=0,y=0;
        for(auto it:instructions){
            if(it=='L'){d+=3; d%=4;}
            else if(it=='R'){d++; d%=4;}
            else {x+=dir[d][0]; y+=dir[d][1];}
        }
        return (x==0&&y==0)||d!=0;
    }
};
