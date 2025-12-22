inline bool isPowerOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

inline ll bitlen(ll  x) {
    return x==0 ? 0 : 64 - __builtin_clzll(x);
}

inline ll countBits(ll n) {
    return __builtin_popcountll(n);
}

inline ll leadingZeros(ll n) {
    return __builtin_clzll(n);
}

inline ll trailingZeros(ll n) {
    return __builtin_ctzll(n);
}