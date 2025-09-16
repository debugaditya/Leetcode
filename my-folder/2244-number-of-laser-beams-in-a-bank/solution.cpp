class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,prev=0,sum=0;
        for(auto it:bank){
            for(auto it1:it) sum+=it1-'0';
            if(sum>0) {ans+=sum*prev; prev=sum; sum=0;}
        }
        return ans;
    }
};
