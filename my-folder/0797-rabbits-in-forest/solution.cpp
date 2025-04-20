class Solution {
public:
    int numRabbits(vector<int>& a) {
        vector<int>mp(1001,0);
        int sum=0;
        for(auto it:a){
            if(mp[it]==0) sum+=it+1;
            mp[it]++;
            if(mp[it]==it+1) mp[it]=0;
        }
        return sum;
    }
};
