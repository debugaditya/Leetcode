class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>>pq; double ans=0;
        for(auto it:classes) pq.push({1.0*(it[0]+1)/(it[1]+1)-1.0*it[0]/it[1],(double)it[0],(double)it[1]});
        while(extraStudents>0){
            double pass=pq.top()[1];
            double total=pq.top()[2];
            pq.pop();
            pq.push({1.0*(pass+2)/(total+2)-1.0*(pass+1)/(total+1),pass+1,total+1});
            extraStudents--;
        }
        while(!pq.empty()) {ans+=1.0*pq.top()[1]/pq.top()[2]; pq.pop();}
        return ans/classes.size();
    }
};
