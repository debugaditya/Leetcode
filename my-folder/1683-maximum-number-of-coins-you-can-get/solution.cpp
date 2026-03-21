class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end()); int i=0,j=piles.size()-1,ans=0;
        while(j-i+1>=3){
            ans+=piles[j-1];
            j-=2; i++;
        }
        return ans;
    }
};
