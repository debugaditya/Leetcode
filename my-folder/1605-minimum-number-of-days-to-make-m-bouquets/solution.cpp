class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxe = INT_MIN, mine = INT_MAX;
        int n = bloomDay.size(), ans = INT_MAX;
        for(int i=0; i<n; i++){
            maxe = max(maxe, bloomDay[i]);
            mine = min(mine, bloomDay[i]);
        }
        int low = mine, high = maxe;
        while(low <= high){
            int day = (low + high) / 2;
            int cnt = 0, c = 0;
            for(int i=0; i<n; i++){
                if(bloomDay[i] <= day){
                    c++;
                }
                else{
                    cnt += c / k;
                    c = 0;
                }
                if(cnt >= m) break;
            }
            cnt += c / k; // Add this line
            if(cnt >= m) {
                high = day - 1;
                ans = day;
            }
            else {
                low = day + 1;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;

    }
};
