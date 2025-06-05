class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans; string temp;
        for(auto it:target){
            temp.push_back('a');
            ans.push_back(temp);
            while(temp.back()!=target[temp.size()-1]){
                temp.back()=temp.back()-'a'+1+'a';
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
