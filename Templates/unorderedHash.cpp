using ull = unsigned long long;
struct custom_hash {
    static ull splitmix64(ull x) noexcept {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x^(x>>30))*0xbf58476d1ce4e5b9ULL;
        x = (x^(x>>27))*0x94d049bb133111ebULL;
        return x^(x>>31);
    }

    static const ull FIXED_RANDOM;
    template<class T>
    size_t operator()(T const& x) const noexcept {
        return (size_t)splitmix64((ull)hash<T>{}(x) + FIXED_RANDOM);
    }

    template<class T1, class T2>
    size_t operator()(pair<T1,T2> const& p) const noexcept {
        ull h1 = (ull)hash<T1>{}(p.first);
        ull h2 = (ull)hash<T2>{}(p.second);
        return (size_t)splitmix64(
            h1 + FIXED_RANDOM ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2))
        );
    }

    template<class T>
    size_t operator()(vector<T> const& v) const noexcept {
        ull seed = (ull)v.size();
        for (auto& val : v) {
            ull h = (ull)hash<T>{}(val);
            seed ^= h + 0x9e3779b97f4a7c15ULL + (seed<<6) + (seed>>2);
        }
        return (size_t)splitmix64(seed + FIXED_RANDOM);
    }

    template<class T, size_t N>
    size_t operator()(array<T,N> const& a) const noexcept {
        ull seed = (ull)N;
        for (auto& val : a) {
            ull h = (ull)hash<T>{}(val);
            seed ^= h + 0x9e3779b97f4a7c15ULL + (seed<<6) + (seed>>2);
        }
        return (size_t)splitmix64(seed + FIXED_RANDOM);
    }
};
const ull custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();