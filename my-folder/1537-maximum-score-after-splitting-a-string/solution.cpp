class Solution {
public:
    int maxScore(string s) {
        int sum=0;
        int maxi=INT_MIN;
        map<int,int>mp;
        for(int i=s.size()-1;i>=1;i--){
            sum+=stoi(string(1,s[i]));
            mp[i]=sum;
        }
        sum+=stoi(string(1,s[0]));
        if(sum==s.size()) return sum-1;
        if(sum==0) return s.size()-1;
        for(auto it:mp){
            maxi=max(maxi,(2*it.second)+it.first-sum);
        }
        return maxi;
    }
};
