class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k==1) return 1;
        if(k%2==0||k%5==0) return -1;
        int mod=0,ans=1;
        while(true){
            mod=(mod*10+1)%k;
            if(mod==0) return ans;
            ans++; if(ans>k) return -1;
        }
        return -1;
    }
};
