class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn=min(x,y);
        return 2*z+4*mn+2*min(x-mn,1)+2*min(y-mn,1);
    }
};
