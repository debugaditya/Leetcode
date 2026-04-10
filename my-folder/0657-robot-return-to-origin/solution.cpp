class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(auto it:moves){
            if(it=='L') x--;
            else if(it=='R') x++;
            else if(it=='D') y--;
            else y++;
        }
        return x==0&&y==0;
    }
};
