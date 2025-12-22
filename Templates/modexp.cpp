ll modexp(ll base, ll pow) {
    ll ans = 1LL;
    while(pow) {
        if(pow & 1LL) ans = (ans * base) % mod;
        base = (base * base) % mod; pow >>= 1LL;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}