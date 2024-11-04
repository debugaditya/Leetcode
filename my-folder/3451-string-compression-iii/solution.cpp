class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int check;
        if(word.size()==1){
            comp+='1';
            comp+=word[0];
            return comp;
        }
        int cnt=1;
        for(int i=0;i<word.size()-1;i++){
            if(word[i]==word[i+1]){
        
                cnt++;
                if(cnt==9){
                    cnt=1;
                    comp+='9';
                    comp+=word[i];
                    i++;
                }
            }
            else{
                comp+=to_string(cnt);
                comp+=word[i];
                cnt=1;
            }
            check=i+1;
        }
        if(word[word.size()-1]!=word[word.size()-2]){
            comp+='1';
            comp+=word[word.size()-1];
        }
        else{
            if(check==word.size()-1){
                comp+=to_string(cnt);
                comp+=word[word.size()-1];
            }
            
        }

        return comp;
    }
};
