class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>mp1;
        for(int i=0;i<values.size();i++) mp[values[i]].push_back(labels[i]);
        sort(values.begin(),values.end());
        int cnt=0;
        int sum=0;
        for(int i=values.size()-1;i>=0;i--){
            if(cnt==numWanted) break;
            if(mp1[mp[values[i]][0]]<useLimit){
                sum+=values[i];
                cnt++;
                mp1[mp[values[i]][0]]++;
            }
            mp[values[i]].erase(mp[values[i]].begin());
        }
        return sum;

    }
};
