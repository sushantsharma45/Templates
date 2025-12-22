/*auto ans = mul(mpow(T, n-1), base);
base case : ans for smallest case, generally n = 1, Eg. T*(T*(T*B)) == T^3*B
Transition matrix [T] : represents movement from one state to another (generally, deduced manually)*/

using matrix = vector<vector<ll>>;
matrix IDENTITY(ll n) {
    matrix I(n+1,vector<ll>(n+1,0));
    FOR(i,1,n) I[i][i] = 1;return I;
}

matrix mul(matrix &A, matrix &B) {
    ll a = A.size() - 1;
    ll b = B.size() - 1;    
    ll c = B[0].size() - 1;

    matrix C(a+1, vector<ll>(b+1, 0));

    FOR(i,1,a) {
        FOR(k,1,b) {
            FOR(j,1,c) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

matrix mpow(matrix base, ll pow) {
    ll n = base.size - 1;
    matrix res = IDENTITY(n);
    while(pow) {
        if(pow&1) res = mul(res, base);
        base = mul(base, base);
        pow >>= 1LL;
    }
    return res;
}