class LCA {
public:
    LCA(const vector<vector<int>>& edges, const int root = 1) {
        n = edges.size() + 1;
        m = (log(n) / log(2)) + 1;
        e.resize(n + 1);
        d.resize(n + 1);
        f.resize(n + 1, vector<int>(m, 0));
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(root, 0);
        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }
    void dfs(int x, int fa) {
        f[x][0] = fa;
        for (auto& y : e[x]) {
            if (y == fa) {
                continue;
            }
            d[y] = d[x] + 1;
            dfs(y, x);
        }
    }

    int lca(int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }
    int dis(int x, int y) { return d[x] + d[y] - d[lca(x, y)] * 2; }

    

private:
    int n;
    int m;
    vector<int> d;
    vector<vector<int>> e;
    vector<vector<int>> f;
};
class Solution {
public:
    const int mod=1e9+7;
    long long power(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        long long temp=power(n/2);
        long long ans=1LL*(temp*temp)%mod;
        if(n%2==1) ans=(2*ans)%mod;
        return ans;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCA l(edges, 1);
        int i=0; vector<int>ans(queries.size());
        for(auto &it:queries){
            int u=it[0],v=it[1];
            int dist=l.dis(u,v);
            ans[i++]=power(dist-1);
        }
        return ans;
    }
};
