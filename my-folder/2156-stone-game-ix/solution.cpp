class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int z=0,o=0,t=0;
        for(auto &it:stones){
            if(it%3==0) z++;
            else if(it%3==1) o++;
            else t++;
        }
        if(o==0||t==0){
            if(max(o,t)<3) return false;
            return z%2;
        }
        if(abs(o-t)>2) return true;
        return 1-z%2;
    }
};
