class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans=0;
        for(auto it:commands){
            if(it=="UP") ans-=n;
            else if(it=="DOWN") ans+=n;
            else if(it=="RIGHT") ans++;
            else ans--;
        }
        return ans;
    }
};
