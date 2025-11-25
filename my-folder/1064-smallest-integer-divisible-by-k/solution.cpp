class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0) return -1;
        int prev=0,ans=0;
        while(true){
            ans++; prev*=10; prev++; prev%=k;
            if(prev==0) return ans; 
        }
        return -1;
    }
};
