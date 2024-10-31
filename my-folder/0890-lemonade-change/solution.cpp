class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fived=0;
        int tend=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fived++;
            }
            else if(bills[i]==10){
                tend++;
                if(fived<=0){
                    return false;
                }
                else{
                    fived--;
                }
            }
            else if(bills[i]==20){
                if(fived<=0){
                    return false; 
                }
                else if(tend>0){
                    fived--;
                    tend--;
                }
                else{
                    if(fived<3){
                        return false;
                    }
                    else{
                        fived-=3;
                    }
                }
                

            }
        }
        return true;
    }
};
