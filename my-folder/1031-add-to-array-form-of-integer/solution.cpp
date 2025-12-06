class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            int temp=carry+k%10+num[i];
            num[i]=temp%10; carry=temp/10;
            k/=10; if(k==0&&carry==0) return num;
        }
        while(k>0||carry>0){
            int temp=carry+k%10;
            num.insert(num.begin(),temp%10); carry=temp/10;
            k/=10; if(k==0&&carry==0) return num;
        }
        return num;
    }
};
