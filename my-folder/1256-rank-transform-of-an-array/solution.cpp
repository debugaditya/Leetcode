class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return arr;
        vector<int>temp=arr; unordered_map<int,int>mp;
        sort(temp.begin(),temp.end());
        mp[temp[0]]=1;
        for(int i=1;i<temp.size();i++) mp[temp[i]]=mp[temp[i-1]]+(temp[i]>temp[i-1]);
        for(auto &it:arr) it=mp[it];
        return arr;
    }
};
