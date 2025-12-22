ll maxn = 2e5+10;
vector<ll> fact(maxn+5), invfact(maxn+5);

ll modexp(ll base, ll pow) {
    ll ans = 1LL;
    while(pow) {
        if(pow & 1LL) ans = ans * base % mod;
        base = base * base % mod; pow >>= 1LL;
    }
    return ans;
}

void PRECOMPUTE() {
    fact[0] = 1;
    for(ll i = 1; i <= maxn; i++) {
        fact[i] = fact[i-1] * i % mod;
    }

    invfact[maxn] = modexp(fact[maxn], mod - 2);
    for(ll i = maxn; i >= 1; i--) {
        invfact[i-1] = invfact[i] * i % mod;
    }
}

ll nCr(ll N, ll R) {
    if(N < 0 || R < 0 || R > N) return 0;
    return fact[N] * invfact[R] % mod * invfact[N - R] % mod;
}

ll nPr(ll N, ll R) {
    if(N < 0 || R < 0 || R > N) return 0;
    return fact[N] * invfact[N - R] % mod;
}

//x1 + x2 + ... + xn = r (xi >= 0) [*combination with repetition]
ll solutions(ll N, ll R) {
    if(N < 0 || R <= 0) return 0;
    return nCr(N + R - 1, R - 1);
}