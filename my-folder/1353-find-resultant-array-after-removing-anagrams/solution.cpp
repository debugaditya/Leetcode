class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]); sort(words[0].begin(),words[0].end()); 
        for(int i=1;i<words.size();i++){
            string temp1=words[i];
            sort(temp1.begin(),temp1.end());
            if(temp1!=words[i-1]) ans.push_back(words[i]);
            words[i]=temp1;
        }
        return ans;
    }
};
