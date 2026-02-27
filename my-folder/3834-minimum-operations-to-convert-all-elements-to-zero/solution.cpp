class SegTree {
public:
    int n;
    vector<int> st;

    SegTree(vector<int>& a) {
        n = a.size();
        st.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) return st[node];
        int mid = (l + r) >> 1;
        return min(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }

    int getMin(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int f(vector<int>& nums,int s,int e,SegTree &seg){
        if(s>e||s>=nums.size()) return 0;
        if(s==e) return nums[s]==0?0:1;
        int mini = seg.getMin(s, e),sum=0,dup=s;
        for(auto it:mp[mini]){
            if(it<s||it>e) continue;
            sum+=f(nums,dup,it-1,seg);
            dup=it+1;
        }
        sum+=f(nums,dup,e,seg);
        return sum+(mini==0?0:1);
    }
    int minOperations(vector<int>& nums) {
        SegTree seg(nums);
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        return f(nums,0,nums.size()-1,seg);
    }
};
struct FastIOS {
    FastIOS() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;
