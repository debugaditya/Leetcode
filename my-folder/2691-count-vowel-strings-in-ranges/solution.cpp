class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>v;
        set<char>st={'a','e','i','o','u'};
        map<int,int>mp;
        int ans=0;
        for(int j=0;j<words.size();j++){
            if(st.find(words[j][0])!=st.end()&&st.find(words[j][words[j].size()-1])!=st.end()) ans++;
            mp[j]=ans;   
        }
        for(int i=0;i<queries.size();i++){
            v.push_back(mp[queries[i][1]]-mp[queries[i][0]-1]);
        }
        return v;
    }
};
