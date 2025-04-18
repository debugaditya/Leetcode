class Solution {
public:
    string RLE(string s){
        int size=1;
        string ans="";
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]) size++;
            else{
                ans += to_string(size);
                ans+=s[i];
                size=1;
            }
        }
        ans+=to_string(size);
        ans+=s[s.size()-1];
        return ans;
    }
    string countAndSay(int n) {
        string  temp="1";
        for(int i=1;i<n;i++) temp=RLE(temp);
        return temp;
    }
};
