class Solution {
public:
    bool isPalindrome(int x) {
        long long y=0;
        long long z=x;
        while(x>0){
            y=(10*y)+x%10;
            x/=10;
        }
        if(z==y){
            return true;
        }
        return false;
        
        
    }
};
