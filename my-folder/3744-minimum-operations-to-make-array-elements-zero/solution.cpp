class Solution {
public:
    int search(int n){
        int l=0,r=17,ans=-1;
        while(l<=r){
            int mid=(l+r)/2; int k=1<<(2*mid);
            if(k>n){
                ans=k;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto &it:queries){
            int i=it[0]; long long sum=0;
            while(i<=it[1]){
                int k=search(i);
                sum+=1LL*(log2(k)/2)*(min(k-1,it[1])-i+1);
                i=k; 
            }
            ans+=ceil(sum/2.0);
        }
        return ans;
    }
};
