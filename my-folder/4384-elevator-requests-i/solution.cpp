class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int cur=0,ans=0;
        for(auto &it:requests){
            ans+=abs(it-cur);
            cur=it;
        }
        return ans;

            
    }
};
