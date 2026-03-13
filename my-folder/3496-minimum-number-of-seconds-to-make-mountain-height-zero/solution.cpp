class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& w) {
        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>>pq;  
        long long ans=0;
        for(int i=0;i<w.size();i++) pq.push({w[i],{1,i}}); 
        while(h>0){
            auto [time,inner] = pq.top();
            auto [k,idx] = inner;
            pq.pop(); h--;
            ans=time;
            pq.push({time+(k+1)*w[idx],{k+1,idx}});
        }
        return ans;
    }
};
