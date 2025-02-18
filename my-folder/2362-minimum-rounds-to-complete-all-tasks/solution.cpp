class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            if(it.second==1) return -1;
            if(it.second%3==0) cnt+=(it.second/3);
            else cnt+=((it.second/3)+1);
        }
        return cnt;
    }
};
