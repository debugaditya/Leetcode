class Solution {
public:
    int minimumPushes(string word) {
        int ans=0,n=word.size(),add=1;
        while(n>0){
            ans+=add*min(n,8);
            n-=min(n,8); add++;
        }
        return ans;
    }
};
