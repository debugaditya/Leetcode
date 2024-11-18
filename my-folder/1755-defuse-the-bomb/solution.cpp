class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans;
        for(int i=0;i<code.size();i++){
            if(k>0){
                int sum=0;
                for(int j=i+1;j<=i+k;j++){
                    int t;
                    if(j>=code.size()){
                        t=j%code.size();
                    }
                    else{
                        t=j;
                    }
                    sum+=code[t];
                }
                ans.push_back(sum);
            }
            else if(k<0){
                int sum=0;
                for(int j=i-1;j>=i+k;j--){
                    int t;
                    if(j<0){
                        t=(j+code.size())%code.size();
                    }
                    else{
                        t=j;
                    }
                    sum+=code[t];
                }
                ans.push_back(sum);
            }
            else if(k==0){
                ans.push_back(0);
            }
        }
        return ans;
    }
};

