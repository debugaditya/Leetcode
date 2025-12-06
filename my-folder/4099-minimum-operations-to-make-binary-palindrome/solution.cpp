class Solution {
public:
    bool pal(long long n){
        long long r=0,x=n;
        while(x>0){r=(r<<1)|(x&1);x>>=1;}
        return r==n;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int>v,ans; int maxi=*max_element(nums.begin(),nums.end());
        for(auto it:nums){
            long long a=it,d=0;
            while(1){
                long long p=a-d,q=a+d;
                if(p>=1&&pal(p)){ans.push_back(d);break;}
                if(pal(q)){ans.push_back(d);break;}
                d++;
            }
        }
        return ans;
    }
};
