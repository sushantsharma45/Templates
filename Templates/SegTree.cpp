//point update
struct segmentTree {
    ll n;
    vector<ll> seg;

    segmentTree(ll sz) {
        n = sz;
        seg.assign(4*n + 5, LLONG_MIN);
    }

    void build(ll idx, ll L, ll R, vector<ll> &arr) {
        if(L==R) seg[idx] = arr[L];
        else {
            ll mid = (L + R) >> 1LL;
            build(2*idx, L, mid, arr);
            build(2*idx+1, mid+1, R, arr);
            seg[idx] = max(seg[2*idx], seg[2*idx+1]);
        }
    }

    ll query(ll idx, ll L, ll R, ll ql, ll qr) {
        if(R < ql || L > qr) return LLONG_MIN;
        if(ql <= L && R <= qr) return seg[idx];
        ll mid = (L + R) >> 1LL;
        ll left  = query(2*idx, L, mid, ql, qr);
        ll right = query(2*idx+1, mid+1, R, ql, qr);
        return max(left, right);
    }

    void update(ll idx, ll L, ll R, ll pos, ll val) {
        if(L==R) seg[idx] = val;
        else {
            ll mid = (L + R) >> 1LL;
            if(pos <= mid) update(2*idx, L, mid, pos, val);
            else update(2*idx+1, mid+1, R, pos, val);
            seg[idx] = max(seg[2*idx], seg[2*idx+1]);
        }
    }
};