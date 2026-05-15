class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
        if(s.back()=='1') return false;
        queue<int>q; q.push(0); int curr=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i==s.size()-1) return true;
            for(int j=max(curr,i+mini);j<=min((int)s.size()-1,i+maxi);j++) if(s[j]=='0') q.push(j);
            curr=min((int)s.size()-1,i+maxi)+1;
        }
        return false;
    }
};
