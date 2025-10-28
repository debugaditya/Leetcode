class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>v(n,1);
        for(int i=1;i<=k;i++){
            int sum=0;
            for(auto &it:v){
                sum=(sum+it)%1000000007;
                it=sum;
            }
        }
        return v.back();
    }
};
