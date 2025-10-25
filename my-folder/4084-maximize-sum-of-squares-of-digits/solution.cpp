class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        for(int i=1;i<=num;i++){
            ans+=min(9,sum)+'0';
            sum-=min(9,sum);
        }
        if(sum!=0) return "";
        return ans;
    }
};
