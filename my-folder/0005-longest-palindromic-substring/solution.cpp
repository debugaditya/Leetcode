class Solution {
public:
    string t(int i,string s){
        string ans(1, s[i]); 
        int i1=i-1;
        int i2=i+1;
        while(i1>=0&&i2<s.size()&&s[i1]==s[i2]){
            ans.push_back(s[i2]);
            ans.insert(ans.begin(),s[i1]);
            i1--;
            i2++;
        }
        return ans;
    }
    string f(int i,string s){
        string ans="";
        int i1=i+1;
        int i2=i;
        while(i2>=0&&i1<s.size()&&s[i2]==s[i1]){
            ans.push_back(s[i1]);
            ans.insert(ans.begin(),s[i2]);
            i2--;
            i1++;
        }
        return ans;
    }
    int maxi=1;
    string longestPalindrome(string s) {
        if(s.size()==1) return  s;
        string ans="";
        for(int i=1;i<s.size();i++){
            if(t(i,s).size()>ans.size()) ans=t(i,s); 
            if(f(i,s).size()>ans.size()) ans=f(i,s);  
        }
        if(f(0,s).size()>ans.size()) ans=f(0,s);
        return ans;
    }
};
