class Solution {
public:
    vector<string> partitionString(string s) {
        set<string>st; string temp=""; vector<string>ans;
        for(auto it:s){
            temp+=it;
            if(!st.count(temp)){
                ans.push_back(temp);
                st.insert(temp); temp="";
            }
        }
        return ans;
    }
};
