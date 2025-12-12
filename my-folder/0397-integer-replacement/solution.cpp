class Solution {
public:
    int integerReplacement(int tn) {
        int cnt=0; long long n = tn;
        while(n>1){
            if(n%2==0) n/=2;
            else if(n==3) n--;
            else if(n%4==1) n--;
            else n++;
            cnt++;
        }
        return cnt;
    }
};
