class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxi=0,prev=-1;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                if(maxi<(i-prev)/2){
                    if(prev==-1) maxi=i;
                    else maxi=(i-prev)/2;
                }
                prev=i;
            }
        }
        if(seats.back()==0&&maxi<seats.size()-1-prev) maxi=seats.size()-1-prev;
        return maxi;
    }
};
