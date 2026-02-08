class Solution {
public:
    int countMonobit(int n) {
        if(n==1) return 2;
        int ans=1,pow=1; 
        while(pow<=n){
            ans++;
            pow++;
            pow*=2;
            pow--;
        }
        return ans;
    }
};
