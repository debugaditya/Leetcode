class Solution {
public:
    int maxDistance(string str, int k1) {
        int n=0,w=0,s=0,e=0,maxi=0;
        for(auto it:str){
            if(it=='N') n++;
            if(it=='S') s++;
            if(it=='W') w++;
            if(it=='E') e++;
            int k=k1;
            int ans=max(n,s)+max(e,w); 
            ans+=min(min(n,s),k);
            if(min(min(n,s),k)==k) ans-=min(n,s)-k;
            k-=min(min(n,s),k);
            ans+=min(min(e,w),k);
            if(min(min(e,w),k)==k) ans-=min(e,w)-k;
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};
