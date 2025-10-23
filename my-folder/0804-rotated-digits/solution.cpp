class Solution {
public:
    bool check(int num){
        int it=num; bool d=false;
        while(it>0){
            int rem=it%10;
            if(rem!=0&&rem!=1&&rem!=8&&rem!=6&&rem!=9&&rem!=2&&rem!=5) return false;
            if(rem==6||rem==9||rem==2||rem==5) d=true;
            it/=10;
        }
        return d;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++) if(check(i)) cnt++;
        return cnt;
    }
};
