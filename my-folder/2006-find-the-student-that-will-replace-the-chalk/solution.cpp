class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans;
        int sum = 0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
            if(sum>k){
                ans=i;
                break;
            }
        }

        int d= k%sum;
        sum=0;
        for(int j=0;j<chalk.size();j++){
            sum+=chalk[j];
            if(sum>d){
                ans= j;
                break;
            }
        }
        return ans;
        
        
    }
};
