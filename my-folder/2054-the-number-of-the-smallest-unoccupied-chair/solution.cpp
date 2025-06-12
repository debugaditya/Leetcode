class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int f) {
        int start = times[f][0]; 
        int maxi = 1; 
        unordered_map<int, vector<int>> dep;
        unordered_map<int, int> arr; 
        for (int i = 0; i < times.size(); i++) arr[times[i][0]] = i;
        priority_queue<int, vector<int>, greater<int>> pq; 
        pq.push(0);
        for (int i = 0; i < start; i++) {
            if (dep.count(i)) for(auto it:dep[i]) pq.push(it);
            if (arr.count(i)) {
                dep[times[arr[i]][1]].push_back(pq.top());
                pq.pop();
                if (pq.empty()) pq.push(maxi++);
            }
        }
        if(dep.count(start)) for(auto it:dep[start]) pq.push(it);
        return pq.top();
    }
};

