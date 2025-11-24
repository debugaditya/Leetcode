class Solution {
public:
    bool isPalindrome(string s) {
        string p="";
        for(auto it:s){
            if(isalpha(it)) p+=max((char)it,(char)(it-'A'+'a'));
            if(it>='0'&&it-'0'<=9) p+=it;
        }
        int l=0,r=p.size()-1;
        while(l<r){
            if(p[l]!=p[r]) return false;
            l++; r--;
        }
        return  true;
    }
};
