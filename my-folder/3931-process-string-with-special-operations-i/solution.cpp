class Solution {
public:
    string processStr(string s) {
        string result="";
        for(auto it:s){
            if(it=='*'&&result.size()>0) result.pop_back();
            else if(it=='*'&&result.size()==0) continue;
            else if(it=='#') result+=result;
            else if(it=='%') reverse(result.begin(),result.end());
            else result+=it;
        }
        return result;
    }
};
