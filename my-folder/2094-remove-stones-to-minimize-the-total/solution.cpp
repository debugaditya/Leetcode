class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq; int sum=0;
        for(auto it:piles){pq.push(it); sum+=it;}
        while(k--){
            int maxi=pq.top();
            sum-=maxi/2;
            pq.pop(); pq.push(maxi-maxi/2);
        }
        return sum;
    }
};
