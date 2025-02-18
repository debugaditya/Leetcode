class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        int c=0;
        vector<int>v;
        int ans=0;
        int cnt1=0;
        int dup=num1;
        while(num2>0||num1>0){
            if(num2%2==1) cnt++;
            num2/=2;
            if(num1>0){
                if(num1%2==1){
                    v.push_back(1);
                    cnt1++;
                }
                else v.push_back(0);
                num1/=2;
            }
        }
        if(cnt>v.size()){
            for(int i=0;i<cnt;i++){
                ans+=pow(2,i);
            }
        }
        else if(cnt==cnt1) return dup;
        else if(cnt<cnt1&&cnt<=v.size()){
            for(int i=v.size()-1;i>=0;i--){
                if(c==cnt) break;
                if(v[i]==1){
                    ans+=pow(2,i);
                    c++;
                } 
            }
        }
        else if(cnt1<cnt&&cnt<=v.size()){
            for(int i=v.size()-1;i>=0;i--){
                if(c==cnt) break;
                if(v[i]==1){
                    ans+=pow(2,i);
                    c++;
                } 
            }
            for(int j=0;j<v.size();j++){
                if(c==cnt) break;
                if(v[j]==0){
                    ans+=pow(2,j);
                    c++;
                } 
            }
        }
        return ans;
    }
};
