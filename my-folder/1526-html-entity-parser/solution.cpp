class Solution {
public:
    string entityParser(string text) {
        string ans=""; 
        for(int i=0;i<text.size();i++){
            if(text[i]=='&'){
                if(i+5<text.size()){
                    string s=text.substr(i,6);
                    if(s=="&quot;") {ans+='"'; i+=5; continue;}
                    if(s=="&apos;") {ans+="'"; i+=5; continue;}
                }
                if(i+4<text.size()){
                    string s=text.substr(i,5);
                    if(s=="&amp;") {ans+='&'; i+=4; continue;}
                }
                if(i+3<text.size()){
                    string s=text.substr(i,4);
                    if(s=="&gt;") {ans+='>'; i+=3; continue;}
                    if(s=="&lt;") {ans+='<'; i+=3; continue;}
                }
                if(i+6<text.size()){
                    string s=text.substr(i,7);
                    if(s=="&frasl;") {ans+='/'; i+=6; continue;}
                }
                ans+='&';
            }
            else ans+=text[i];
        }
        return ans;
    }
};
