class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        for(auto it:queries){
            int i=0;
            for(auto it1:it){
                if(it1==pattern[i]) i++;
                else if(isupper(it1)&&isupper(pattern[i])&&pattern[i]!=it1) break;
                else if(i==pattern.size()&&isupper(it1)){i--; break;} 
            }
            ans.push_back(i==pattern.size());
        }
        return ans;
    }
};
