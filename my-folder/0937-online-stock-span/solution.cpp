class StockSpanner {
public:
    stack<pair<int,int>>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        while(!v.empty()&&v.top().first<=price){cnt+=v.top().second; v.pop();}
        v.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
