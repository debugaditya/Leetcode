class Solution {
public:
    vector<string>ans;
    void f(vector<int>&v,int i,int sum_h,int sum_m,int bit){
        if(bit==0) {
            string time="";
            time+=to_string(sum_h); time+=':';
            if(sum_m<=9) time+='0'; time+=to_string(sum_m);
            ans.push_back(time);
            return;
        }
        if(i==v.size()) return;
        if(i<=3&&sum_h+v[i]<12) f(v,i+1,sum_h+v[i],sum_m,bit-1); 
        if(i>3&&sum_m+v[i]<=59) f(v,i+1,sum_h,sum_m+v[i],bit-1);
        f(v,i+1,sum_h,sum_m,bit);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int>v={1,2,4,8,1,2,4,8,16,32};
        f(v,0,0,0,turnedOn);
        return ans;
    }
};
