class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int cnt=0;
        for(auto it:s) if(j.find(it)!=string::npos) cnt++;
        return cnt;
    }
};
