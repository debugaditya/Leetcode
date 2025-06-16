class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        while(mainTank>0){
            ans+=min(mainTank,5)*10;
            int temp=min(mainTank,5);
            mainTank-=temp;
            if(temp==5){mainTank+=min(1,additionalTank); additionalTank-=min(1,additionalTank);}
        }
        return ans;
    }
};
