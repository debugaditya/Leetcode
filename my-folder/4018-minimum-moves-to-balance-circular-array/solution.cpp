class Solution {
public:
    long long minMoves(vector<int>& b) {
        long long sum=accumulate(b.begin(),b.end(),0LL);
        if(sum<0) return -1; long long ans=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<0){
                int j=(i-1+b.size())%b.size(),k=(i+1)%b.size(); int dist=1;
                b[i]*=-1;
                while(b[i]>0){
                    ans+=1LL*min(b[i],b[j])*dist;
                    b[i]-=min(b[i],b[j]);
                    if(b[i]==0) break;
                    ans+=1LL*min(b[i],b[k])*dist;
                    b[i]-=min(b[i],b[k]);
                    j=(j-1+b.size())%b.size(); k=(k+1)%b.size(); dist++;
                }
                return ans;
            }
        }
        return 0;
    }
};
