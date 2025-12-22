//range update
struct LazySegmentTree {
    ll n;
    vector<ll> seg, lazy;

    LazySegmentTree(ll sz) {
        n = sz;
        seg.assign(4*n + 5, 0);
        lazy.assign(4*n + 5, 0);
    }

    void build(ll idx, ll L, ll R, vector<ll> &arr) {
        if(L==R) seg[idx] = arr[L];
        else {
            ll mid = (L + R) >> 1LL;
            build(2*idx, L, mid, arr);
            build(2*idx+1, mid+1, R, arr);
            seg[idx] = seg[2*idx] + seg[2*idx+1];
        }
    }

    void push(ll idx, ll L, ll R) {
        if(lazy[idx]!=0) {
            seg[idx] += lazy[idx]*(R-L+1);
            if(L!=R) {
                lazy[2*idx] += lazy[idx];
                lazy[2*idx+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(ll idx, ll L, ll R, ll ql, ll qr, ll val) {
        push(idx, L, R);
        if(qr < L || ql > R) return;
        if(ql <= L && R <= qr) {
            lazy[idx] += val;
            push(idx, L, R);
        }
        else {
            ll mid = (L + R) >> 1;
            update(2*idx, L, mid, ql, qr, val);
            update(2*idx+1, mid+1, R, ql, qr, val);
            seg[idx] = seg[2*idx] + seg[2*idx+1];
        }
    }

    ll query(ll idx, ll L, ll R, ll ql, ll qr) {
        push(idx, L, R);
        if(qr < L || ql > R) return 0;
        if(ql <= L && R <= qr) return seg[idx];
        ll mid = (L + R) >> 1LL;
        ll left  = query(2*idx, L, mid, ql, qr);
        ll right = query(2*idx+1, mid+1, R, ql, qr);
        return left + right;
    }
};