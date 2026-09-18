class Solution {
public:
    void buildMax(int i,int l,int r,vector<int>&v,vector<int>&seg){
        if(l==r){seg[i]=v[l]; return;}
        int mid=(l+r)/2;
        buildMax(2*i+1,l,mid,v,seg);
        buildMax(2*i+2,mid+1,r,v,seg);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
    void buildMin(int i,int l,int r,vector<int>&v,vector<int>&seg){
        if(l==r){seg[i]=v[l]; return;}
        int mid=(l+r)/2;
        buildMin(2*i+1,l,mid,v,seg);
        buildMin(2*i+2,mid+1,r,v,seg);
        seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
    int queryMax(int i,int l,int r,int left,int right,vector<int>&seg){
        if(left<=l&&r<=right) return seg[i];
        if(left>r||l>right) return INT_MIN;
        int mid=(l+r)/2;
        return max(queryMax(2*i+1,l,mid,left,right,seg),queryMax(2*i+2,mid+1,r,left,right,seg));
    }
    int queryMin(int i,int l,int r,int left,int right,vector<int>&seg){
        if(left<=l&&r<=right) return seg[i];
        if(left>r||l>right) return INT_MAX;
        int mid=(l+r)/2;
        return min(queryMin(2*i+1,l,mid,left,right,seg),queryMin(2*i+2,mid+1,r,left,right,seg));
    }
    int getEnd(int left,int right,vector<int>&seg,int n){
        int end=right;
        while(true){
            int idx=queryMax(0,0,n-1,left,end,seg);
            if(idx!=end) end=idx;
            else return end;
        }
    }
    bool isValid(int left,int right,vector<int>&seg,int n){
        return queryMin(0,0,n-1,left,right,seg)==left;
    }
    vector<int> solve(int i,vector<vector<int>>&dp,vector<int>&lastPos,string &s,vector<int>&firstPos,vector<int>&maxSeg,vector<int>&minSeg,int n){
        if(i==n) return {0,0,-1};
        if(!dp[i].empty()) return dp[i];
        int left=i,right=lastPos[s[i]-'a'];
        right=getEnd(left,right,maxSeg,n);
        vector<int> skip=solve(i+1,dp,lastPos,s,firstPos,maxSeg,minSeg,n);
        if(firstPos[s[i]-'a']!=i||!isValid(left,right,minSeg,n)) return dp[i]={skip[0],skip[1],-1};
        vector<int> take=solve(right+1,dp,lastPos,s,firstPos,maxSeg,minSeg,n);
        int takeCount=1+take[0],takeLength=right-left+1+take[1];
        if(takeCount>skip[0]) return dp[i]={takeCount,takeLength,right};
        if(takeCount<skip[0]) return dp[i]={skip[0],skip[1],-1};
        if(takeLength<skip[1]) return dp[i]={takeCount,takeLength,right};
        return dp[i]={skip[0],skip[1],-1};
    }
    vector<string> maxNumOfSubstrings(string s){
        int n=s.size();
        vector<int>firstPos(26,-1),lastPos(26,-1);
        for(int i=0;i<n;i++){
            if(firstPos[s[i]-'a']==-1) firstPos[s[i]-'a']=i;
            lastPos[s[i]-'a']=i;
        }
        vector<int>firstAt(n),lastAt(n);
        for(int i=0;i<n;i++){
            firstAt[i]=firstPos[s[i]-'a'];
            lastAt[i]=lastPos[s[i]-'a'];
        }
        vector<int>maxSeg(4*n),minSeg(4*n);
        buildMax(0,0,n-1,lastAt,maxSeg);
        buildMin(0,0,n-1,firstAt,minSeg);
        vector<vector<int>>dp(n);
        solve(0,dp,lastPos,s,firstPos,maxSeg,minSeg,n);
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(firstPos[s[i]-'a']!=i) continue;
            if(dp[i][2]!=-1){
                int end=dp[i][2];
                ans.push_back(s.substr(i,end-i+1));
                i=end;
            }
        }
        return ans;
    }
};
