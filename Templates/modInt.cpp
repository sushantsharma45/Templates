struct mll {
    ll num;
    mll(ll x = 0) { num = x % mod; if (num < 0) num += mod; }
 
    mll& operator+=(mll o){ num += o.num; if (num >= mod) num -= mod; return *this; }
    mll& operator-=(mll o){ num -= o.num; if (num < 0) num += mod; return *this; }
    mll& operator*=(mll o){ num = (ll)((__int128)num * o.num % mod); return *this; }
    mll& operator/=(mll o){ return *this *= o.inv(); }
 
    mll operator+(mll o) const { return mll(*this) += o; }
    mll operator-(mll o) const { return mll(*this) -= o; }
    mll operator*(mll o) const { return mll(*this) *= o; }
    mll operator/(mll o) const { return mll(*this) /= o; }
 
    mll& operator++()  { if (++num == mod) num = 0; return *this; }
    mll& operator--()  { if (num == 0) num = mod; --num; return *this; }
    mll operator++(int){ mll r = *this; ++*this; return r; }
    mll operator--(int){ mll r = *this; --*this; return r; }
 
    static inline mll modexp(mll b, ll e){ mll r = 1; while (e){ if (e & 1) r *= b; b *= b; e >>= 1; } return r; }
    mll pow(ll e) const { return modexp(*this, e); }
    mll inv() const { assert(num != 0); return modexp(*this, mod - 2); }
 
    explicit operator bool() const { return num != 0; }
    explicit operator ll() const { return num; }
 
    bool operator==(mll o) const { return num == o.num; }
    bool operator!=(mll o) const { return num != o.num; }
    bool operator< (mll o) const { return num <  o.num; }
    bool operator> (mll o) const { return num >  o.num; }
    bool operator<=(mll o) const { return num <= o.num; }
    bool operator>=(mll o) const { return num >= o.num; }
 
    friend mll operator+(ll lhs, mll rhs){ return mll(lhs) + rhs; }
    friend mll operator-(ll lhs, mll rhs){ return mll(lhs) - rhs; }
    friend mll operator*(ll lhs, mll rhs){ return mll(lhs) * rhs; }
    friend mll operator/(ll lhs, mll rhs){ return mll(lhs) / rhs; }
 
    friend ostream& operator<<(ostream& os, const mll& m){ return os << m.num; }
    friend istream& operator>>(istream& is, mll& m){ ll x; is >> x; m = mll(x); return is; }
};