class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        for(auto &it:c) swap(it[0],it[1]);
        sort(c.begin(),c.end());
        priority_queue<int>pq;
        int start=1,ans=0;
        for(auto &it:c){
            if(it[0]-start+1<it[1]){
                if(pq.empty()||pq.top()<=it[1]) continue;
                start-=pq.top(); 
                start+=it[1]; pq.pop();
                pq.push(it[1]);
            }
            else{ans++; pq.push(it[1]); start+=it[1];}
        }
        return ans;
    }
};
