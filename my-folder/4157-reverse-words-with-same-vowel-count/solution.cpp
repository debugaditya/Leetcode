class Solution {
public:
    string reverseWords(string s) {
        int cnt=0,cnt1=0; int i=-1; bool d=false;
        for(auto it:s){
            i++;
            if(it==' ') {d=true; break;}
            if(it=='a'||it=='e'||it=='i'||it=='o'|it=='u') cnt++; 
        }
        cout<<i;
        if(!d) return s; string ans="",temp="";
        for(int j=0;j<=i;j++) ans+=s[j];
        for(int j=i+1;j<s.size();j++){
            if(s[j]==' '){
                if(cnt1==cnt) reverse(temp.begin(),temp.end());
                ans+=temp; ans+=' ';
                temp=""; cnt1=0;
            }
            else temp+=s[j];
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'|s[j]=='u') cnt1++;
        }
        if(cnt1==cnt) reverse(temp.begin(),temp.end()); 
        ans+=temp;
        return ans;
    }
};
