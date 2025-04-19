class Solution {
public:
    bool judgeSquareSum(int c) {
        int l=0;
        int r=sqrt(c);
        while(l<=r){
            long long sq=pow(r,2);
            long long z=pow(l,2);
            if(z+sq==c) return true;
            if(z+sq<c) l++;
            else r--;
        }   
        return false;
    }
};
