struct RollingHash {
    vector<ll> h1, h2, r1, r2, p1, p2;
    ll base1, base2, n, mod1 = 1000000007LL, mod2 = 1000000009LL;

    template<typename T>
    RollingHash(T &arr, bool isString = 0) {
        base1 = uniform_int_distribution<ll>(256, 1000000000LL)(rng);
        base2 = uniform_int_distribution<ll>(256, 1000000000LL)(rng);

        n = arr.size();
        h1.assign(n+1, 0); h2.assign(n+1, 0);
        r1.assign(n+1, 0); r2.assign(n+1, 0);
        p1.assign(n+1, 1); p2.assign(n+1, 1);

        for(ll i = 0; i < n; i++) {
            ll val = isString ? arr[i] - 'a' + 1 : arr[i];
            h1[i+1] = (h1[i] * base1 + val) % mod1;
            h2[i+1] = (h2[i] * base2 + val) % mod2;
            p1[i+1] = (p1[i] * base1) % mod1;
            p2[i+1] = (p2[i] * base2) % mod2;
        }

        for(ll i = n-1; i >= 0; i--) {
            ll val = isString ? arr[i] - 'a' + 1 : arr[i];
            r1[n-i] = (r1[n-i-1] * base1 + val) % mod1;
            r2[n-i] = (r2[n-i-1] * base2 + val) % mod2;
        }
    }

    pair<ll,ll> hashCode(ll l, ll r) {
        ll x1 = (h1[r+1] - h1[l] * p1[r-l+1] % mod1 + mod1) % mod1;
        ll x2 = (h2[r+1] - h2[l] * p2[r-l+1] % mod2 + mod2) % mod2;
        return {x1, x2};
    }

    pair<ll,ll> reverseCode(ll L, ll R) {
        ll l = n-1-R, r = n-1-L;
        ll x1 = (r1[r+1] - r1[l] * p1[r-l+1] % mod1 + mod1) % mod1;
        ll x2 = (r2[r+1] - r2[l] * p2[r-l+1] % mod2 + mod2) % mod2;
        return {x1, x2};
    }

    bool isPalindrome(ll i, ll j) {
        return hashCode(i, j) == reverseCode(i, j);
    }
};
