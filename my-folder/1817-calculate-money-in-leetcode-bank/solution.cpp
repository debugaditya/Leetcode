class Solution {
public:
    int totalMoney(int n) {
        int deposit=1;
        int ans=0;
        int dmon=1;
        for(int i=1;i<=n;i++){
            ans+=deposit;
            deposit++;
            if(i%7==0){
                deposit=dmon+1;
                dmon=deposit;
            }
        }  
        return ans;
    }
};
