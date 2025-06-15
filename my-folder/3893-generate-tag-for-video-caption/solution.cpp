class Solution {
public:
    string generateTag(string caption) {
        string result="#"; int i=1; 
        if(caption[0]!=' ') result+=tolower(caption[0]);
        while(i<caption.size()&&result.size()<100){
            if(caption[i]==' '&&i!=caption.size()-1&&caption[i+1]!=' '){result+= toupper(caption[i+1]); i++;}
            else if(caption[i]!=' ') result+=tolower(caption[i]);
            i++;
        }
        return result;
    }
};
