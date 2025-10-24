class Solution {
public:
    bool check(int i){
        vector<int>mp(10,0); int cnt=0;
        while(i>0){
            mp[i%10]++;
            if(mp[i%10]>i%10) return false;
            if(mp[i%10]==i%10) cnt--; 
            if(mp[i%10]==1) cnt++;
            i/=10;
        }
        return cnt==0;
    }
    int nextBeautifulNumber(int n) {
        int i=n+1;
        while(true){
            if(check(i)) return i;
            i++;
        }
        return -1;
    }
};
