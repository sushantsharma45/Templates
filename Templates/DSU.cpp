struct DSU {
    ll n;
    vector<ll> P, CNT;

    DSU(ll N) {
        n = N;
        P.resize(N+1);
        CNT.assign(N+1, 1);
        for(ll i = 1; i <= N; i++) P[i] = i;
    }

    inline ll find(ll x) {
        if(P[x] == x) return x;
        return P[x] = find(P[x]);
    }

    inline bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(CNT[a] < CNT[b]) swap(a, b);
        P[b] = a; CNT[a] += CNT[b];
        return true;
    }

    inline bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    ll len(ll x) {
        return CNT[find(x)];
    }

    vector<vector<ll>> groups() {
        vector<ll> leader(n+1);
        for(ll i = 1; i <= n; i++) {
            leader[i] = find(i);
        }

        vector<vector<ll>> result(n+1);
        for(ll i = 1; i <= n; i++) {
            result[leader[i]].push_back(i);
        }

        vector<vector<ll>> ans;
        for(ll i = 1; i <= n; i++) {
            if(!result[i].empty()) {
                ans.push_back(result[i]);
            }
        }
        return ans;
    }

};
