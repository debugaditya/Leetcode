class Solution {
public:
    long long calculateScore(vector<string>& in, vector<int>& values) {
        long long ans=0; vector<int>vis(in.size(),0);
        for(int i=0;i<in.size();i++){
            if(vis[i]) return ans;
            vis[i]=1;
            if(in[i]=="add") ans+=values[i];
            else{
                if(values[i]+i>=in.size()||values[i]+i<0) return ans;
                if(vis[values[i]+i]) return ans;
                i+=values[i]-1;
            }
        }
        return ans;
    }
};
