//Sparse Table
struct SparseTable {
    ll n, LOG;
    vector<vector<pair<ll,ll>>> ans;

    SparseTable(vector<ll> &a) {
        n = (ll)a.size();
        LOG = 64 - __builtin_clzll(n);
        ans.assign(LOG, vector<pair<ll,ll>>(n));

        FOR(i,0,n-1) ans[0][i] = {a[i], a[i]};

        for(ll k = 1; k < LOG; k++) {
            ll len = 1LL << k, half = len >> 1;
            for(ll i = 0; i + len <= n; i++) {
                auto L = ans[k-1][i], R = ans[k-1][i+half];
                ans[k][i] = {min(L.ff, R.ff), max(L.ss, R.ss)};
            }
        }
    }

    ll getMin(ll L, ll R) {
        if(L < 0 || R >= n || L > R) return LLONG_MAX;
        ll k = 63 - __builtin_clzll(R - L + 1);
        auto A = ans[k][L], B = ans[k][R-(1LL<<k)+1];
        return min(A.first, B.first);
    }

    ll getMax(ll L, ll R) {
        if(L < 0 || R >= n || L > R) return LLONG_MIN;
        ll k = 63 - __builtin_clzll(R - L + 1);
        auto A = ans[k][L], B = ans[k][R-(1LL<<k)+1];
        return max(A.second, B.second);
    }
};