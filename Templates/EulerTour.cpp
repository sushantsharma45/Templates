ll T = 1; //*re-initialize T = 1, under solve() each time
ll maxn = 2e5 + 35;
vector<ll> nodeAtTime(maxn);
vector<ll> in(maxn), out(maxn);

void dfs(ll node, ll parent, vector<vector<ll>> &adj) {
    in[node] = T;
    nodeAtTime[T++] = node;
    for(auto &v : adj[node]) {
        if(v!=parent) dfs(v, node, adj);
    }
    out[node] = T - 1;
}
