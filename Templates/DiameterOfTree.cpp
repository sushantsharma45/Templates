/*Here, start DFS from any arbitary node (lets say, 1), then find dist(1,v) for every node, then **THE NODE HAVING MAX DIST(1,v), IS ONE END OF THE DIAMETER FOR SURE!**
Store it in "x", then DO THE DFS AGAIN from "x", the max dist(x,v) will give the other end of the diameter, as we started our dfs from one end i.e. "x" itself.
Also, now "dx" stores dist(x,v) and "dy" stores dist(y,v), this can be used to calculate ECC[node] (i.e. the MAX. DISTANCE from this node to any other node), given by
ECC[node] = max(dx[node], dy[node]) as, in a tree, the farthest node from any vertex is always one of the two diameter endpoints.*/

void dfs(ll v, ll p, ll len, vector<ll> &dep, vector<vector<ll>> &adj) {
    dep[v] = len;
    for(auto &u : adj[v]) {
        if(u!=p) {
            dfs(u,v,len+1,dep,adj);
        }
    }
}

vector<ll> dx(n+1), dy(n+1);
dfs(1, -1, 0, dx, adj);
ll x = max_element(all(dx)) - dx.begin();
dfs(x, -1, 0, dx, adj);
ll y = max_element(all(dx)) - dx.begin();
dfs(y, -1, 0, dy, adj);

vector<ll> ecc(n+1);
FOR(i,1,n) ecc[i] = max(dx[i], dy[i]);
