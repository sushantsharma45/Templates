struct Trie {
    char firstChar;
    ll totalChar, nodes = 0;
    vector<ll> child, prefix, wordEnds;

    Trie(ll tc = 26, char fc = 'a') {
        totalChar = tc;
        firstChar = fc
        newNode();
    }

    ll newNode() {
        child.insert(child.end(), totalChar, -1LL);
        prefix.pb(0); wordEnds.pb(0);
        return nodes++;
    }

    ll childIndex(ll node, ll c) {
        return node * totalChar + c;
    }

    void insert(string &s) {
        ll node = 0;
        prefix[node]++;
        for(char ch : s) {
            ll charIndex = (ll)(ch - firstChar);
            ll idx = childIndex(node, charIndex);
            if(child[idx]==-1) child[idx] = newNode();
            node = child[idx]; prefix[node]++;
        }
        wordEnds[node]++;
    }

    void erase(string &s) {
        ll node = 0; vector<ll> path = {0};
        for(char ch : s) {
            ll charIndex = (ll)(ch - firstChar);
            ll idx = childIndex(node, charIndex);

            if(child[idx]==-1) return;
            node = child[idx]; path.pb(node);
        }
        if(!wordEnds[node]) return;
        
        wordEnds[node]--;
        for(ll vis : path) prefix[vis]--;
    }

    ll countWordsEqualTo(string &s) {
        ll node = 0;
        for(char ch : s) {
            ll charIndex = (ll)(ch - firstChar);
            ll idx = childIndex(node, charIndex);
            if(child[idx]==-1) return 0;
            node = child[idx];
        }
        return wordEnds[node];
    }

    ll totalPrefixWord(string &p) {
        ll node = 0;
        for(char ch : p) {
            ll charIndex = (ll)(ch - firstChar);
            ll idx = childIndex(node, charIndex);
            if(child[idx]==-1) return 0;
            node = child[idx];
        }
        return prefix[node];
    }

    bool anySuchPrefix(string &p) {
        ll node = 0;
        for(char ch : p) {
            ll charIndex = (ll)(ch - firstChar);
            ll idx = childIndex(node, charIndex);
            if(child[idx]==-1) return false;
            node = child[idx];
        }
        return true;
    }
};