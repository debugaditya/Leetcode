class Solution {
public:
    long long countOfSubstrings(string w, int k) {
        vector<int>mp(26,0),cons(w.size(),0),idx(w.size(),-1); long long ans=0,cnt=0;
        idx[0]=w.size();
        for(int i=w.size()-1;i>=0;i--){
            if(w[i]!='a'&&w[i]!='e'&&w[i]!='i'&&w[i]!='o'&&w[i]!='u'){
                cnt++;
                idx[cnt]=i;
            }
            cons[i]=cnt;
        }
        int l=0,r=0; mp[w[0]-'a']++;
        while(r<w.size()){
            int sum=mp[0]+mp[4]+mp[8]+mp[14]+mp[20];
            if(mp[0]==0||mp[4]==0||mp[8]==0||mp[14]==0||mp[20]==0){
                r++;
                if(r<w.size()) mp[w[r]-'a']++;
            }
            else{
                int req=k-(r-l+1-sum);
                if(cons[r]>=req&&req>=0){
                    int num=cons[r]-req;
                    ans+=idx[num]-max(r,idx[num+1]);
                }
                mp[w[l]-'a']--; l++;
                if(l>r) {r=l; if(r<w.size()) mp[w[r]-'a']++;}
            }
        }
        return ans;
    }
};
