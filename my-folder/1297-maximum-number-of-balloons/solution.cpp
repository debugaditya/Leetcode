class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>mp(5,0);
        for(auto &it:text){
            if(it=='b') mp[0]++;
            if(it=='a') mp[1]++;
            if(it=='l') mp[2]++;
            if(it=='o') mp[3]++;
            if(it=='n') mp[4]++;
        }
        return min({mp[0],mp[1],mp[2]/2,mp[3]/2,mp[4]});
    }
};
