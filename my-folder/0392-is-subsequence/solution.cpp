class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(auto it:t){
            if(it==s[i]) i++;
            if(i==s.size()) return true;
        }
        return i==s.size();
    }
};
