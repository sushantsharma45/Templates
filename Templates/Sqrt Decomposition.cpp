/*Items having WEIGHTS >= sqrt(MAX_SUM_POSSIBLE) are sent to perform normal bitset subset sum, as such weights are at max. sqrt(MAX_SUM_POSSIBLE)...
Rest weights < sqrt(MAX_SUM_POSSIBLE) are sent to perform binary - decomposition (useful when these light weights have VERY HIGH frequency,
worst case for Binary Decomposition ==> single CHAINING with majority weights having Frequency[WT] = 1) [but still in general very fast]*/

const ll maxn = 200005;
bitset<maxn> dp;

void sqrtDecomposition(vector<ll> &arr) {
    dp.reset();
    dp[0] = 1;

    ll sum = 0;
    map<ll,ll> mpp;
    for(auto &num : arr) {
        mpp[num]++; sum += num;
    }

    ll Limit = sqrtl(sum);
    for(auto [WT, cnt] : mpp) {
        if(WT >= Limit) {
            FOR(i,1,cnt) dp |= (dp << WT);
        }
        else {
            ll p2 = 1;
            while(cnt > 0) {
                ll take = min(p2, cnt);
                dp |= (dp << (take * WT));
                cnt -= take; p2 <<= 1LL;
            }
        }
    }
}
