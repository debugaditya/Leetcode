class Solution {
public:
    string bin(int n){
        string s="";
        while(n>0){
            s+=n%2+'0';
            n/=2;
        }
        return s;
    }
    int dec(string s){
        int n=0;
        for(int i=s.size()-1;i>=0;i--)  if(s[i]=='1') n+=pow(2,31-i);
        return n;
    }
    int reverseBits(int n) {
        string s=bin(n); cout<<s;
        return dec(s);
    }
};
