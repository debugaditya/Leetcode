class Solution {
public:
    int binaryGap(int n) {
        int maxi=0,prev=-1,curr=0;
        while(n>0){
            if(n%2==1){
                if(prev!=-1) maxi=max(maxi,curr-prev);
                prev=curr; 
            }
            n/=2; curr++;
        }
        return maxi;
    }
};
