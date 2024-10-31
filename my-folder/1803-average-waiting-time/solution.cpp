class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double w=customers.size();
        double sum=customers[0][1];
        double start =customers[0][0]+customers[0][1];
        for(int i=1;i<customers.size();i++){
            if(start<=customers[i][0]){
                sum+=customers[i][1];
                start=customers[i][0]+customers[i][1];
            }
            else{
                sum+=customers[i][1]+(start-customers[i][0]);
                start+=customers[i][1];
            }

        }
        return sum/w;
    }
};
