class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool v=false,c=false;
        for(auto it:word){
            if(!isalpha(it)&&!isdigit(it)) return false;
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'||it=='A'||it=='E'||it=='I'||it=='O'||it=='U') v=true;
            else if(isalpha(it)) c=true;
        }
        return v&&c;
    }
};
