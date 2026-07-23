class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right||left==0) return left;
        if((int)log2(left)!=(int)log2(right)) return 0;
        int diff=right-left,pow=1,ans=0;
        for(int i=1;i<=30;i++){
            pow*=2;
            if(diff<pow) ans+=(pow&left&right);
            if(pow>right) return ans;
        }
        return ans;
    }
};
