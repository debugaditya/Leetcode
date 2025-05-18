class Solution {
public:
    bool isValid(string w) {
        if(w.size()<3) return false;
        bool v=false,c=false;
        unordered_set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        for(auto it:w){
            if(it=='@'||it=='#'||it=='$') return false;
            if(isdigit(it)) continue;
            if(st.find(it)!=st.end()) v=true;
            else c=true;
        }
        return c&&v;
    }
};
