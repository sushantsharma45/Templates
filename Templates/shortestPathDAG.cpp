vector<ll> shortestDAG(ll ST, vector<vector<pair<ll,ll>>> &adj) {
    ll n = adj.size() - 1;
    vector<ll> dp(n+1, INF);
    auto topo = topoSort(adj);

    dp[ST] = 0;
    for(auto &v : topo) {
        for(auto &[u, wt] : adj[v]) {
            dp[u] = min(dp[u], dp[v] + wt);
        }
    }
    return dp;
}