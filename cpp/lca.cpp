const ll maxLogN = 20, maxn = 100005;
ll tin[maxn], tout[maxn];
ll up[maxLogN][maxn];
ll timer = 0, n, l;
vector<ll> adj[maxn];


void dfs(ll s, ll p){
    tin[s] = timer++;
    up[0][s] = p;
    fr(i,1,l){
        up[i][s] = up[i-1][up[i-1][s]];
    }
    for(auto ch: adj[s]){
        if(s!=p) dfs(ch, s);
    }
    tout[s] = timer++;
}

bool is_ancestor(ll u, ll v){
    return tin[u] < tin[v] && tout[u] > tout[v];
}

bool lca(ll u, ll v){
    if(is_ancestor(u,v)) return u;
    else if(is_ancestor(v,u)) return v;
    for(ll i=l; i>=0; i--){
        if(!is_ancestor(up[i][u], v))
            u = up[i][u];
    }
    return up[0][u];
}

void preprocess(ll root){
    l = ceil(log2(n));
    dfs(root, root);
}