class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp="";
        for(auto it:s){
            temp+=it;
            if(it==' '){if(temp!=" ") for(int i=temp.size()-1;i>=0;i--) ans.insert(ans.begin(),temp[i]); temp="";}
        }
        temp+=' ';
        if(temp!=" ") for(int i=temp.size()-1;i>=0;i--) ans.insert(ans.begin(),temp[i]); 
        ans.pop_back();
        return ans;
    }
};
