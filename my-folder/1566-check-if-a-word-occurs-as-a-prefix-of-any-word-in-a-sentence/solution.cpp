class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt =1;
        string s=sentence.substr(0,searchWord.size());
        if(s==searchWord){
            return 1;
        }
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                cnt++;
                string t=sentence.substr(i+1,searchWord.size());
                if(t==searchWord){
                    return cnt;
                }
            }
        }
        return -1;
        
    }
};
