class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>ans(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        ans[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int cost=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=row-1;i<=row+1;i++){
                for(int j=col-1;j<=col+1;j++){
                    if(i<0||i>=heights.size()||j<0||j>=heights[0].size()) continue;
                    if(i==row+1&&(j==col+1||j==col-1)) continue;
                    if(i==row-1&&(j==col+1||j==col-1)) continue;
                    if(ans[i][j]>max(cost, abs(heights[i][j] - heights[row][col]))){
                        pq.push({max(cost, abs(heights[i][j] - heights[row][col])),{i,j}});
                        ans[i][j]=max(cost, abs(heights[i][j] - heights[row][col]));
                    }
                }
            }
        }
        return ans[heights.size()-1][heights[0].size()-1];
    }
};
