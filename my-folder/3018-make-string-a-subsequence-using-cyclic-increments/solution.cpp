class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int cnt=0;
        for(int i=0;i<str1.size();i++){
            char n=str2[cnt]-1;
            if(str2[cnt]=='a'){
                n='z';
            }
            if(str1[i]==str2[cnt]||str1[i]==n){
                cnt++;
                if(cnt==str2.size()){
                    return true;
                }
            }   
        }
        return false;
    }
};
