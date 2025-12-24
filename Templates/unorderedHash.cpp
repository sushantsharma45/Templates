using ull = unsigned long long;
struct custom_hash {
    static ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    static const ull FIXED_RANDOM;
    template<class T>
    size_t operator()(T const& x) const {
        return splitmix64((ull)std::hash<T>{}(x) + FIXED_RANDOM);
    }
};
const ull custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
