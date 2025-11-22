class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt=0;
        for(int i=0;i<colors.size();i++) if(colors[i]!=colors[(i+1)%colors.size()]&&colors[i]!=colors[(i-1+colors.size())%colors.size()]) cnt++;
        return cnt;
    }
};
