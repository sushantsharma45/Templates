//PRIMALITY TESTING USING TRIAL DIVISION
bool isPrime(ll n) {
    if(n < 4) return n > 1;
    if(!(n%2) || !(n%3)) return false;
    for(ll i = 5; i*i <= n; i += 6) {
        if(!(n%i) || !(n%(i+2))) return false;
    }
    return true;
}

//PRIMALITY TESTING USING MILLER RABIN
using u128 = __uint128_t;
struct MillerRabin {
    static ull mpow(ull num, ull pow, ull m) {
        ull res = 1; 
        num %= m;
        while(pow) {
            if(pow & 1) res = (u128(res) * num) % m;
            num = (u128(num) * num) % m;
            pow >>= 1;
        }
        return res;
    }

    static bool comp(ull n, ull a, ull d, ll s) {
        ull x = mpow(a, d, n);
        if(x == 1 || x == n - 1) return false;
        for(ll r = 1; r < s; r++) {
            x = (u128(x) * x) % n;
            if(x == n - 1) return false;
        }
        return true;
    }

    static bool isPrime(ll n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0) return false;

        ll s = 0; ull d = n-1;
        while((d & 1) == 0) { d >>= 1; s++; }

        for(ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            if(a % n == 0) continue;
            if(comp(n, a, d, s)) return false;
        }
        return true;
    }
};