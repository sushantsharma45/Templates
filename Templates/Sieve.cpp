//PNT [Prime Number Theorem] : If we need 'K' primes, we need maxn = k*lnk

//liner sieve to generate primes up to maxn
ll maxn = 1e5 + 5;
vector<ll> primes;
vector<char> isPrime(maxn+1,1);

void sieve() {
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i <= maxn; i++) {
        if(isPrime[i]) primes.pb(i);
        for(ll &p : primes) {
            ll num = i * p;
            if(num > maxn) break;
            isPrime[num] = 0;
            if(i % p == 0) break;
        }
    }
}

//primes[x] = All distinct PF's that divides "x" [fine for Ai <= 1e6]
ll maxn = 2e5 + 35;
vector<vector<ll>> primes(maxn+1);
for(ll i = 2; i <= maxn; i++) {
    if(primes[i].size()==0) {
        for(ll j = i; j <= maxn; j+=i) {
            primes[j].pb(i);
        }
    }
}