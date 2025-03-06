class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        int i=1;
        int add=4;
        while(i<n){
            ans+=add;
            add+=4;
            i++;
        }
        return ans;
    }
};
