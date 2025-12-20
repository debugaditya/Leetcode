class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>a,b,c; sort(nums.begin(),nums.end());
        for(auto it:nums){
            if(it%3==0) a.push_back(it);
            if(it%3==1) b.push_back(it);
            if(it%3==2) c.push_back(it);
        }
        int p=0,d=0,e=0,f=0;
        if(a.size()>=3) p=a.back()+a[a.size()-2]+a[a.size()-3];
        if(b.size()>=3) d=b.back()+b[b.size()-2]+b[b.size()-3];
        if(c.size()>=3) e=c.back()+c[c.size()-2]+c[c.size()-3];
        if(c.size()>0&&b.size()>0&&a.size()>0) f=a.back()+b.back()+c.back();
        return max({p,d,e,f});
    }
};
