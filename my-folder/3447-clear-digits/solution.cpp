class Solution {
public:
    string clearDigits(string s) {
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                s.erase(s.begin()+i);
                if(i>0){
                    s.erase(s.begin()+i-1);
                    i-=2;
                }
                else i--;
            }
        }
        return s;
    }
};
