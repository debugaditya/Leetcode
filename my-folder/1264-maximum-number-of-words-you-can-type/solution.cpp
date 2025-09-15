class Solution {
public:
    int canBeTypedWords(string text, string b) {
        unordered_set<char>st(b.begin(),b.end());
        bool d=true; int cnt=0;
        for(auto it:text){
            if(it==' '&&d) cnt++;
            else if(it==' '&&!d) d=true;
            else if(st.count(it)) d=false; 
        }
        if(d) cnt++;
        return cnt;
    }
};
