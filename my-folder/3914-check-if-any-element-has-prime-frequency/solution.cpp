class Solution {
public:
    bool check(int n){
        int i=n-1;
        while(i>1){
            if(n%i==0) return false;
            i--;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int>mp(101,0);
        for(auto it:nums) mp[it]++;
        for(auto it:mp){
            if(it==0||it==1) continue;
            if(check(it)) return true;
        }
        return false;
    }
};
