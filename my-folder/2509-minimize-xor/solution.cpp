class Solution {
public:
    int fn(int n){
        int c=0;
        while(n) n&=n-1,c++;
        return c;
    }
    int minimizeXor(int a, int b) {
        int c=fn(b);
        int x=0;
        for(int i=29; i>=0 && c; i--){
            if(a&(1<<i)) x^=(1<<i),c--;
        }
        if(c){
            for(int i=0; i<30 && c; i++){
                if(x&(1<<i)) continue;
                x^=(1<<i);
                c--;
            }
        }
        return x;
    }
};
