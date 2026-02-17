class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(auto it:words){
            int sum=0;
            for(auto it1:it) sum+=weights[it1-'a'];
            sum%=26; s+=(25-sum+'a');
        }
        return s;
    }
};
