//FOR: n <= 1e9
map<ll,ll> factorize(ll num) {
    map<ll,ll> mpp;
    for(ll i = 2; i*i <= num; i++) {
        while(num%i==0) {mpp[i]++; num /= i;}
    }
    if(num > 1) mpp[num]++;
    return mpp;
}

//FOR: n <= 1e5
ll maxn = 2e5+35;
vector<ll> spf(maxn+1,0), primes;
void fastSPF() {
    for(ll i = 2; i <= maxn; i++) {
        if(spf[i]==0) {spf[i] = i; primes.pb(i);}
        for(ll p : primes) {
            ll num = i*p; if(num > maxn) break;
            spf[num] = p; if(i % p == 0) break;
        }
    }
}

map<ll,ll> factorize(ll num) {
    map<ll,ll> mpp;
    while(num > 1) {
        ll p = spf[num];
        mpp[p]++; num/=p;
    }
    return mpp;
}