class Solution {
public:
    int d(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int>mp(37,0);
        int cnt=0;
        int maxi=1;
        for(int i=1;i<=n;i++){
            int w=d(i);
            mp[w]++;
            if(mp[w]==maxi) cnt++;
            if(mp[w]>maxi) cnt=1;
            maxi=max(maxi,mp[w]);
        }
        return cnt;
    }
};
