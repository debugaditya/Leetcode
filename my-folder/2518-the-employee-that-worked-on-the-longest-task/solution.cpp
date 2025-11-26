class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxi=logs[0][1],emp=logs[0][0];
        for(int i=1;i<logs.size();i++){
            if(logs[i][1]-logs[i-1][1]>=maxi){
                if(maxi==logs[i][1]-logs[i-1][1]) emp=min(emp,logs[i][0]);
                else emp=logs[i][0];
            }
            maxi=max(maxi,logs[i][1]-logs[i-1][1]);
        }
        return emp;
    }
};
