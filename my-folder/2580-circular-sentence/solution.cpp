class Solution {
public:
    bool isCircularSentence(string sentence) {
        char s=sentence[0];
        char e=sentence[sentence.size()-1];
        if(s!=e){
            return false;
        }
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                if(sentence[i+1]!=sentence[i-1]){
                    return false;
                }
            }
        }
        return true;
        
    }
};
