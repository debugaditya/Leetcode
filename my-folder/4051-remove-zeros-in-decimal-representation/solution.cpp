class Solution {
public:
    long long removeZeros(long long n) {
        string s="";
        while(n>0){
            if(n%10!=0)s+=n%10+'0';
            n/=10;
        }
        reverse(s.begin(),s.end());
        return stoll(s);
    }
};
