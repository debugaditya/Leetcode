class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX||x<=INT_MIN){
            return 0;
        }
        int y=x;
        int z=x;
        int cnt=0;
        long long ans=0;
        if(y>0){
            while(x>0){
                x/=10;
                cnt++;
            }
            for(int i=cnt-1;i>=0;i--){
                ans+=(y%10)*pow(10,i);
                y/=10;

            }
        }
        else if(y<0){
            y=y*(-1);
            x=x*(-1);
            while(x>0){
                x/=10;
                cnt++;
            }
            for(int i=cnt-1;i>=0;i--){
                ans+=(y%10)*pow(10,i);
                y/=10;

            }
            ans=ans*(-1);
        }
        else{
            return 0;
        }
        if(ans>=INT_MAX||ans<=INT_MIN){
            return 0;
        }
        
        return ans;
        
    }
};
