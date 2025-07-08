class Solution {
public:
    string concatHex36(int n) {
        int sq=n*n; int cube=pow(n,3);
        string s1="",s2="";
        while(sq>0){
            if(sq%16<=9) s1+=(sq%16)+'0';
            else s1+=(sq%16)-10+'A';
            sq/=16;
        }
        while(cube>0){
            if(cube%36<=9) s2+=(cube%36)+'0';
            else s2+=(cube%36)-10+'A';
            cube/=36;
        }
        reverse(s1.begin(),s1.end()); reverse(s2.begin(),s2.end());
        return s1+s2;
    }
};
