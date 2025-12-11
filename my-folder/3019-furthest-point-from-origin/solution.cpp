class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dash=0,s=0;
        for(auto it:moves){
            if(it=='L') s--;
            else if(it=='R') s++;
            else dash++;
        }
        s=abs(s); return s+dash;
    }
};
