class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans=0;
        long long days=pizzas.size()/4;
        sort(pizzas.begin(),pizzas.end());
        int idx=pizzas.size()-1;
        for(int i=1;i<=days;i+=2){
            ans+=pizzas[idx];
            idx--;
        }
        idx--;
        for(int i=2;i<=days;i+=2){
            ans+=pizzas[idx];
            idx-=2;
        }
        return ans;
    }
};
