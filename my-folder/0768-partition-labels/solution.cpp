class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>mp(26,-1);
        vector<int>ans;
        for(int i=0;i<s.size();i++) mp[s[i]-'a']=i;
        int index=0;
        int last_index=mp[s[0]-'a'];
        for(int i=0;i<s.size();i++){
            if(i==last_index){
                ans.push_back(last_index-index+1);
                index=last_index+1;
                if(index<s.size()) last_index=mp[s[index]-'a'];
            }
            last_index=max(mp[s[i]-'a'],last_index);
        }
        return ans;
    }
};
