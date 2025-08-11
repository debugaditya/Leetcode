class Solution {
public:
    int findComplement(int num) {
        int ans=0,p=0;
        while(num>0){
            if(num%2==0) ans+= 1<<p;
            p++;
            num/=2;
        }
        return ans;
    }
};
