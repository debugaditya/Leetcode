class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int y=a+b+c-min({a,b,c})-max({a,b,c});int x=min({a,b,c}); int z=max({a,b,c});
        int maxi=z-x-2;
        if(y-x==2||z-y==2) return {1,maxi};
        return {(y-x>1?1:0)+(z-y>1?1:0),maxi};
    }
};
