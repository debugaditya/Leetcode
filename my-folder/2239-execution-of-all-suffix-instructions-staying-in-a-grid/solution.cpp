class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& start, string s) {
        int r=start[0],c=start[1],cnt=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                char it=s[j];
                if(it=='R') c++;
                if(it=='L') c--;
                if(it=='U') r--;
                if(it=='D') r++;
                if(c==n||r==n||c<0||r<0){ans.push_back(cnt); cnt=0; r=start[0]; c=start[1]; break;}
                else cnt++;
            }
            if(cnt>0) ans.push_back(cnt);
            cnt=0; r=start[0]; c=start[1];
        }
        return ans;
    }
};
