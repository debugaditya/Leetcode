class Solution {
public:
    string bin(int n){
        string ans="";
        while(n>0){
            ans+=n%2;
            n/=2;
        }
        return ans;
    }
    int minimumFlips(int n) {
        string s=bin(n); int ans=0;
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) ans+=2;
            l++; r--;
        }
        return ans;
    }
};
