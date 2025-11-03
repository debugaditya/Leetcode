class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unordered_set<char>>mp(words.size()); int ans=0;
        for(int i=0;i<words.size();i++) for(auto it1:words[i]) mp[i].insert(it1);
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                bool d=false;
                for(auto it:mp[i]) if(mp[j].count(it)) {d=true; break;}
                if(!d) ans=max(ans,(int)words[i].size()*(int)words[j].size());
            }
        }
        return ans;
    }
};
