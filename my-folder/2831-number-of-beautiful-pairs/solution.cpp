class Solution {
public:
    bool gcd(int x,int y){
        if(x==1||y==1) return true; 
        if(min(x,y)==0) return false;
        return gcd(max(x,y)%min(x,y),min(x,y));
    }
    int countBeautifulPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int x; int t=nums[i];
                while(t>0){
                    x=t%10;
                    t/=10;
                }
                if(gcd(x,nums[j]%10)) cnt++;
            }
        }
        return cnt;
    }
};
