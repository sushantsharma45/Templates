struct BinaryTrie {
    ll bitLength = 64;
    ll nodeCount = 0;
    vector<ll> child,  passCount;

    BinaryTrie() {newNode();}

    ll newNode() {
        child.pb(-1);
        child.pb(-1);
        passCount.pb(0);
        return nodeCount++;
    }

    bool contains(ll x) {
        ll node = 0;
        for(ll i = bitLength - 1; i >= 0; i--) {
            ll bit = (x >> i) & 1LL;
            ll idx = node * 2 + bit;
            node = child[idx];
            if(node == -1 || passCount[node] == 0) return false;
        }
        return true;
    }

    void insert(ll x) {
        ll node = 0;
        passCount[node]++;
        for(ll i = bitLength - 1; i >= 0; i--) {
            ll bit = (x >> i) & 1LL;
            ll idx = node * 2 + bit;
            if(child[idx] == -1) child[idx] = newNode();
            node = child[idx];
            passCount[node]++;
        }
    }

    bool remove(ll x) {
        if(!contains(x)) return false;
        ll node = 0;
        passCount[node]--;
        for(ll i = bitLength - 1; i >= 0; i--) {
            ll bit = (x >> i) & 1LL;
            ll idx = node * 2 + bit;
            node = child[idx];
            passCount[node]--;
        }
        return true;
    }
};
