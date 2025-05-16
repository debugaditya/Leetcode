class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(n>f.size()/2+1) return false;
        for(int i=0;i<f.size();i++){
            if(f[i]==1) continue;
            if((i==0||f[i-1]==0)&&(i==f.size()-1||f[i+1]==0)){
                n--;
                f[i]=1;
            }
        }
        return n<=0;
    }
};
