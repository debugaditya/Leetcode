class Solution {
public:
    int countKeyChanges(string s) {
        char prev=tolower(s[0]); int cnt=0;
        for(auto it:s){
            if(prev!=tolower(it)) cnt++;
            prev=tolower(it);
        }
        return cnt;
    }
};
