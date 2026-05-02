class Solution {
public:
    bool f(int n){
        bool ans=false;
        while(n>0){
            int d=n%10;
            if(d==3||d==4||d==7) return false;
            if(d==6||d==9||d==5||d==2) ans=true;
            n/=10;
        }
        return ans;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++) if(f(i)) cnt++;
        return cnt;
    }
};
