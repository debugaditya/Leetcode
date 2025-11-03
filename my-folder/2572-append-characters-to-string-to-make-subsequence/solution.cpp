class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0;
        for(auto &it:s) {if(it==t[j]) j++; if(j==t.size()) return 0;}
        return t.size()-j;
    }
};
