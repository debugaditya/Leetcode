class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(auto it:s) if(it=='a'||it=='e'||it=='o'||it=='u'||it=='i') cnt++;
        if(cnt==0) return false;
        return true;
    }
};
