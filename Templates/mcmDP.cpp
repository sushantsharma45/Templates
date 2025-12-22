ll mcm(vector<ll> &A) {
    ll n = A.size()-1;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    
    FOR(i,1,n) dp[i][i] = 0;
    FOR(len,2,n) {
        FOR(l,1,n-len+1) {
            ll r = l+len-1;
            FOR(k,l,r-1) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + A[l-1]*A[k]*A[r]);
            }
        }
    }
    
    return dp[1][n];
}