class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int a=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                a++;
                if(a==3){
                    return true;
                }
            }
            else{
                a=0;
            }
        }
        return false;

        
    }
};
