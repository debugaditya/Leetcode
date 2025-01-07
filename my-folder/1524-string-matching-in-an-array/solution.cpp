class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>ans;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].find(words[j])!=string::npos){
                    ans.insert(words[j]);
                }
                if(words[j].find(words[i])!=string::npos){
                    ans.insert(words[i]);
                }
            }
        }
        vector<string>ans2(ans.begin(),ans.end());
        return ans2;
    }
};
