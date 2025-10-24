class Solution {
public:
    string f(string &s){
        int l=0,r=s.size()-1;
        while(l<=r){
            int temp=s[r]-'0';
            s[r]=1-(s[l]-'0')+'0';
            s[l]=1-temp+'0';
            l++; r--;
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++) s=s+"1"+f(s);
        return s[k-1];
    }
};
