class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1,st2,ans;
        for(auto it:nums1) st1.insert(it);
        for(auto it:nums2) st2.insert(it);
        int dup1=nums1.size()-st1.size(); 
        int dup2=nums2.size()-st2.size(); 
        if(dup1>=nums1.size()/2) {
            for(auto it:st1) ans.insert(it);
        }
        else {
            int cnt=0;
            unordered_set<int> toErase;
            for(auto &it:st1){
                if(st2.count(it)) {
                    toErase.insert(it);
                    cnt++; 
                }
                if(cnt==nums1.size()/2-dup1) break;
            }
            for(auto it: toErase) st1.erase(it);
            toErase.clear();
            for(auto &it:st1){
                if(cnt==nums1.size()/2-dup1) break;
                toErase.insert(it);
                cnt++; 
            }
             for(auto it: toErase) st1.erase(it);
            for(auto it:st1) ans.insert(it);
        }
        if(dup2>=nums2.size()/2) {
            for(auto it:st2) ans.insert(it);
        }
        else {
            int cnt=0;
            unordered_set<int> toErase;
            for(auto &it:st2){
                if(st1.count(it)) {
                    toErase.insert(it);
                    cnt++;
                }
                if(cnt==nums2.size()/2-dup2) break;
            }
            for(auto it: toErase) st2.erase(it);
              toErase.clear();
            for(auto &it:st2){
                if(cnt==nums2.size()/2-dup2) break;
                toErase.insert(it);
                cnt++;
            }
             for(auto it: toErase) st2.erase(it);
            for(auto it:st2) ans.insert(it);
        }
        return ans.size();
    }
};

