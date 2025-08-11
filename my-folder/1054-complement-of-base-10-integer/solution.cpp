class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0) return 1;
        int ans=0,p=0;
        while(num>0){
            if(num%2==0) ans+= 1<<p;
            p++;
            num/=2;
        }
        return ans;
    }
};
