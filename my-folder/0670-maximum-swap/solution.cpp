class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        int ans=0;
        int b=num;
        int j=0;
        while(num>0){
            v.push_back(num%10);
            num/=10;
            j++;
            
        }
        vector<int>v1(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        int t =v.size()-1;
        for(int i=0;i<v.size();i++){
            if(v1[t]==v[t]){
                t--;
                continue;
            }
            else{
                break;
            }
        }
        if(t==-1){
            return b;
        }
        int d;
        for(int p=0;p<t;p++){
            if(v[p]==v1[t]){
                d=p;
                break;
            }
        }
        swap(v[t],v[d]);
        for(int r=0;r<v.size();r++){
            ans+= v[r]*pow(10,r);
        }
        return ans;

        
        
    }
};
