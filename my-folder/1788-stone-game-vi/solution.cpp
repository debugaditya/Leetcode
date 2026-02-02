class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int,int>>pq; int turn=1,s1=0,s2=0;
        for(int i=0;i<a.size();i++) pq.push({a[i]+b[i],i});
        while(!pq.empty()){
            if(turn==1) s1+=a[pq.top().second];
            else s2+=b[pq.top().second];
            pq.pop();
            turn=1-turn;
        }
        if(s1==s2) return 0;
        return s1>s2?1:-1;
    }
};
