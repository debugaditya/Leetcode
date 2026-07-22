class Solution {
public:
    void create(int i,int l,int r,vector<int>&seg,vector<int>&maxi){
        if(l==r) {seg[i]=maxi[l]; return;}
        int mid=(l+r)/2;
        create(2*i+1,l,mid,seg,maxi);
        create(2*i+2,mid+1,r,seg,maxi);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
    int get(int i,int l,int r,int &left,int &right,vector<int>&seg){
        if(l>r||r<left||l>right) return INT_MIN;
        if(l>=left&&r<=right) return seg[i];
        int mid=(l+r)/2;
        return max(get(2*i+1,l,mid,left,right,seg),get(2*i+2,mid+1,r,left,right,seg));
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int>subs,maxi,sum,ans; int ones=s[0]-'0',zeroes=1-ones,cnt=s[0]-'0';
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                if(s[i-1]=='1') {subs.push_back(ones); ones=0;}
                zeroes++;
            }
            else{
                if(s[i-1]=='0') {subs.push_back(-zeroes); zeroes=0;}
                ones++; cnt++;
            }
        }
        if(s.back()=='0') subs.push_back(-zeroes);
        else subs.push_back(ones);
        sum.push_back(abs(subs[0]));
        for(int i=1;i<subs.size();i++) sum.push_back(sum.back()+abs(subs[i]));
        for(int i=(s[0]=='0'?0:1);i+2<subs.size();i+=2) maxi.push_back(abs(subs[i]+subs[i+2]));
        if(maxi.size()==0){
            for(auto &it:queries) ans.push_back(cnt);
            return ans;
        }
        vector<int>seg(4*maxi.size());
        create(0,0,maxi.size()-1,seg,maxi);
        for(auto &it:queries){
            int l=it[0],r=it[1],left=upper_bound(sum.begin(),sum.end(),l)-sum.begin(),right=upper_bound(sum.begin(),sum.end(),r)-sum.begin();
            if(subs[left]>0) {l=sum[left]; left++;} 
            if(subs[right]>0) {right--; if(right<=0){ans.push_back(cnt); continue;} r=sum[right]-1;}
            if(left>=right) {ans.push_back(cnt); continue;}
            int l1=left/2,r1=right/2-1,temp_l=maxi[l1],temp_r=maxi[r1];
            int val_l=temp_l-(l-(left>0?sum[left-1]:0)),val_r=temp_r-(sum[right]-r-1); 
            if(l1==r1){ans.push_back(maxi[l1]-(l-(left>0?sum[left-1]:0))-(sum[right]-r-1)+cnt); continue;}
            l1++; r1--; ans.push_back(cnt+max({val_l,val_r,get(0,0,maxi.size()-1,l1,r1,seg)}));
        }
        return ans;
    }
};
