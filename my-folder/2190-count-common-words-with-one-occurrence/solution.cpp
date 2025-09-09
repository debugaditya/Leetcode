class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp1,mp2; int cnt=0;
        for(auto it:words1) mp1[it]++;
        for(auto it:words2) mp2[it]++;
        for(auto it:mp1) if(it.second==1&&mp2[it.first]==1) cnt++;
        return cnt;
    }
};
