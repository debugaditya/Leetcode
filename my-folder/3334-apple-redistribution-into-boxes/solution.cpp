class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end()); int sum=accumulate(apple.begin(),apple.end(),0);
        for(int i=capacity.size()-1;i>=0;i--){
            sum-=capacity[i];
            if(sum<=0) return capacity.size()-i;
        }
        return -1;
    }
};
