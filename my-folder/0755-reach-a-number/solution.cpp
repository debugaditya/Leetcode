class Solution {
public:
    int reachNumber(int target) {
        long long sum=0; int i=0; target=abs(target);
        while(true){
            sum+=i;
            if(sum>=target&&(sum-target)%2==0) return i;
            i++;
        }
        return i;
    }
};
