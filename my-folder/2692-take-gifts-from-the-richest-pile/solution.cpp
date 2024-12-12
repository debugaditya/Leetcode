#include <bits/stdc++.h>
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        for(int i=1;i<=k;i++){
            int maxi=pq.top();
            pq.pop();
            pq.push(pow(maxi,0.5));
        }
        long long ans=0;
        for(int j=0;j<gifts.size();j++){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
