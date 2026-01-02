vector<ll> topoSort(vector<vector<ll>> &adj) {
    ll n = adj.size() - 1;
    vector<ll> deg(n+1); queue<ll> qu;

    FOR(v,1,n) {
        for(auto &u : adj[v]) {
            deg[u]++;
        }
    }

    FOR(v,1,n) {
        if(!deg[v]) qu.push(v);
    }

    vector<ll> topo;
    while(!qu.empty()) {
        ll v = qu.front();
        qu.pop(); topo.pb(v);
        for(auto &u : adj[v]) {
            deg[u]--;
            if(!deg[u]) qu.push(u);
        }
    }
    
    if((ll)topo.size() < n) return {-1};
    return topo;

}
