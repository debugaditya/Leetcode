class Solution {
public:
    bool isvowel(char ch) { return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u')||(ch == 'A') || (ch == 'E') ||(ch == 'I') ||(ch == 'O') ||(ch == 'U'); }
    string sortVowels(string s) {
        string vow=""; vector<int>idx; 
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])) {idx.push_back(i); vow+=s[i];}
        }
        sort(vow.begin(),vow.end());
        for(int i=0;i<vow.size();i++) s[idx[i]]=vow[i];
        return s;
    }
};
