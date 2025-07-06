class Solution {
public:
    bool digitCount(string num) {
        vector<int>mp(10,0);
        for(auto it:num) mp[it-'0']++;
        cout<<mp[0]<<" "<<num[0]<<endl;
        for(int i=0;i<num.size();i++) if(mp[i]!=num[i]-'0') return false;
        return true;
    }
};
