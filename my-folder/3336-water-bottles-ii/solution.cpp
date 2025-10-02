class Solution {
public:
    int maxBottlesDrunk(int b, int e) {
        int empty=0,ans=0;
        while(b>0||empty>=e){
            if(empty>=e){
                empty-=e;
                b++; e++;
            }
            else{
                ans+=b;
                empty+=b;
                b=0;
            }
        }
        return ans;
    }
};
