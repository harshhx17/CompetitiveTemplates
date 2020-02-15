
const int K = 20;
vi adj[maxn];
bool centroid[maxn];
int dp[K+1][maxn], depth[maxn], par[maxn], sz[maxn];
int n, q;

void dfs2(int u,int p){
    sz[u] = 1;
    for(auto v : adj[u])
        if(v != p && !centroid[v]){
            dfs2(v, u);
            sz[u] += sz[v];
        }
}

int get(int u, int p, int S){
    for(auto v : adj[u])
        if(v != p && !centroid[v] && sz[v] > S / 2)
            return get(v, u, S);
    return u;
}

int solve(int u){
    dfs2(u, 0);
    int c = get(u, 0, sz[u]);
    centroid[c] = 1;
    if(sz[u] == n){
        // we have the root of centroid tree
    }
    for(auto v : adj[c])
        if(!centroid[v])
            par[solve(v)] = c;
    return c;
}

//remove from here if distance is not needed
void lca_dfs(int u,int p){
    dp[0][u] = p;
    depth[u] = depth[p] + 1;
    for(auto v : adj[u])
        if(v != p)
            lca_dfs(v, u);
}

void construct_lca(int n){
    fr(k, 1, K)
        fr(i, 1, n)
            dp[k][i] = dp[k - 1][dp[k - 1][i]];
}

int lca(int u,int v){
    if(depth[u] < depth[v]) swap(u, v);
    for(int k = K; k >= 0; k--)
        if(depth[dp[k][u]] >= depth[v])
            u = dp[k][u];
    if(u == v) return u;
    for(int k = K; k >= 0; k--)
        if(dp[k][u] != dp[k][v]) u = dp[k][u], v = dp[k][v];
    return dp[0][u];
}

int dis(int u,int v){ return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

signed main(){
    lca_dfs(1, 0);
    construct_lca(n);
    solve(1);
    return 0;
}

