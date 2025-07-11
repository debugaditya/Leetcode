class Solution {
public:
    int sum(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int countBalls(int l, int h) {
        vector<int>mp(h+1,0); int maxi=0;
        for(int i=l;i<=h;i++) mp[sum(i)]++;
        for(int i=1;i<=h;i++) maxi=max(maxi,mp[i]);
        return maxi;
    }
};
