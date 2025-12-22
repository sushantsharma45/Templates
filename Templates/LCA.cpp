//Binary Lifting
struct Tree {
    ll N, LOG;
    vector<vector<ll>> up;
    vector<ll> level;

    Tree(ll n, ll logVal = 20) {
        N = n; LOG = logVal;
        level.assign(N+1, 0);
        up.assign(N+1, vector<ll>(LOG));
    }

    /*Assuming 1 is the ROOT!
    Tree T(n); T.dfs(1, 1, adj);*/
    void dfs(ll v, ll p, vector<vector<ll>> &adj) {
        up[v][0] = p; FOR(j,1,LOG-1)
        up[v][j] = up[up[v][j-1]][j-1];

        for(auto &u : adj[v]) {
            if(u==p) continue;
            level[u] = level[v] + 1;
            dfs(u, v, adj);
        }
    }

    ll kthAncestor(ll v, ll k) {
        FOR(j,0,LOG-1) {
            if(k&(1LL<<j)) v = up[v][j];
        } return v;
    }

    ll LCA(ll a, ll b) {
        if(level[a] < level[b]) swap(a, b);

        ll d = level[a] - level[b];
        a = kthAncestor(a, d);
        
        if(a==b) return a;
        ROF(j,LOG-1,0) {
            if(up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    ll dist(ll a, ll b) {
        return level[a] + level[b] - 2 * level[LCA(a, b)];
    }
    
    bool isAncestor(ll u, ll v) {
        return LCA(u,v)==u;
    }
};