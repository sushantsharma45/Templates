/*To speed-up traversal in Trees! XOR array initially stores all neighbours xor, but after proccessing (bottom-up order, starting from leaf)
[kind of toposort] it stores parent of node in XOR[node], also "ORD" stores nodes in topological sort order, but in reverse (i.e. leaf --> parent).
For Euler Tour we process nodes in REVERSE order (i.e. from ROOT --> leaf), if : end[node] = "X" ==> this node contains all blocks till "X" for its subtree.
So, whenever we assign place to a node child, it occupies space, starting from : end[node] - sz[child] + 1, TILL "in[child] + sz[child] - 1" OR "directly end[node]",
also then update : end[child] = end[node] and end[node] = in[child] - 1, after this. Similarly, we can also store XOR of weights if edge weights are also given.*/

struct xorLinkedTree {
    ll n, root;
    vector<ll> XOR, deg, sz;
    vector<ll> in, out, ord, nodeAT;
    
    xorLinkedTree(ll n, ll root) {
        this->n = n;
        this->root = root;
        nodeAT.assign(n+5,0);
        sz.assign(n+10,1); in.assign(n+10,0);
        XOR.assign(n+5,0); deg.assign(n+5,0), out.assign(n+5,0);
        
        FOR(i,1,n-1) {
            ll u, v;
            cin >> u >> v;
            deg[u]++; deg[v]++;
            XOR[u] ^= v; XOR[v] ^= u;
        }
        
        deg[root] = 0;
        FOR(i,1,n) {
            ll node = i;
            while(deg[node]==1) {
                deg[node] = 0;
                deg[XOR[node]] -= 1;
                XOR[XOR[node]] ^= node;
                ord.pb(node);
                node = XOR[node];
            }
        }
        
        XOR[root] = 0;
        for(auto &v : ord) {
          sz[XOR[v]] += sz[v];
        }
    }
    
    void EulerTOUR() {
        vector<ll> end(n+5,0);
        in[root] = 1; out[root] = n;
        nodeAT[1] = root; end[root] = n;
        
        ROF(i,ord.size()-1,0) {
            ll node = ord[i], p = XOR[node];
            in[node] = end[p] - sz[node] + 1;
            nodeAT[in[node]] = node; out[node] = end[p];
            end[node] = end[p]; end[p] = in[node] - 1;
        }
    }
};
