class Solution {
public:
    int strStr(string haystack, string needle) {
        int c=-1;
        int d=needle.size();
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                c=i;
                for(int j=c;j<c+d;j++){
                    if(needle[j-c]!=haystack[j]){
                        c=-1;
                        break;
                    }
                
                }
                if(c!=-1){
                    break;
                }

            }

        }
        return c;
        
    }
};
