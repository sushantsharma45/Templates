/*Weights having frequency > sqrt(MAX_SUM_POSSIBLE) are sent to perform normal bitset subset sum, as such weights are at max sqrt(MAX_SUM_POSSIBLE)...
Rest weights < sqrt(MAX_SUM_POSSIBLE) are sent to perform binary - decomposition (useful when frequency is VERY HIGH, worst case Binary Decomp.
==> single CHAINING with Frequency[WT] = 1, for most of the weights)... done for lighter block (in general fast) */

const ll maxn = 200005;
bitset<maxn> dp;

void sqrtDecomposition(vector<ll> &arr) {
    dp.reset();
    dp[0] = 1;

    map<ll,ll> mpp;
    for(auto &num : arr) mpp[num]++;

    ll Limit = sqrtl(maxn);
    for(auto [WT, cnt] : mpp) {
        if(cnt > Limit) {
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
