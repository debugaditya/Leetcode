class Solution {
public:
    long long dividePlayers(vector<int >& skill) {
        sort(skill.begin(),skill.end());
        int j=skill.size();
        long long  d=skill[0]+skill[j-1];
        long long  l=1;
        long long  r=j-2;
        long long  sum=skill[0]*skill[j-1];
        while(l<r){
            if(skill[l]+skill[r]==d){
                sum+=skill[l]*skill[r];
                l++;
                r--;
            }
            else return -1;
        }
        return sum;
    }
};
