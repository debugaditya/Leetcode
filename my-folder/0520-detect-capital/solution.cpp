class Solution {
public:
    bool detectCapitalUse(string word) {
        bool cap=false,small=false; if(word[0]-'a'>=-6) small=true;
        for(int i=1;i<word.size();i++){
            if(word[i]-'a'<-6) cap=true;
            else small=true;
            if(small&&cap) return false;
        }
        return true;
    }
};
