class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans=0,energy=0;
        for(auto &it:tasks) it.insert(it.begin(),it[1]-it[0]);
        sort(tasks.begin(),tasks.end()); ans+=tasks.back()[2]; energy=tasks.back()[0];
        for(int i=tasks.size()-2;i>=0;i--){
            if(energy<tasks[i][2]) {ans+=abs(tasks[i][2]-energy); energy=tasks[i][0];}
            else energy-=tasks[i][1];
        }
        return ans;
    }
};
