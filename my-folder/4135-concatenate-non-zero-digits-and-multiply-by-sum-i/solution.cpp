class Solution {
public:
    long long sumAndMultiply(int n) {
        string x=""; int sum=0;
        while(n>0){
            if(n%10!=0) x+=n%10+'0'; sum+=n%10;
            n/=10; 
        }
        reverse(x.begin(),x.end());
        if(x.size()==0) return 0;
        return stoll(x)*sum;
    }
};
