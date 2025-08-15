class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a'); k-=n; int i=n-1;
        while(k>0){
            ans[i]=min(k,25)+'a';
            k-=min(k,25);
            i--;
        }
        return ans;
    }
};
