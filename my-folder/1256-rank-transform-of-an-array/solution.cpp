#include <bits/stdc++.h>
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        map<int,int>mp;
        vector<int>arr2(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        set<int>s1;
        vector<int>temp;
        for(int i=0;i<arr.size();i++){
            if(s1.find(arr[i])==s1.end()){
                s1.insert(arr[i]);
                temp.push_back(arr[i]);
            
            }
        }
        for(int k=0;k<temp.size();k++){
            mp[temp[k]]=k+1;
        }
        for(int j=0;j<arr2.size();j++){
            ans.push_back(mp[arr2[j]]);
        }
        return ans;

        
    }
};
