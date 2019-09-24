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


/////////////////////////
//Jo dugar, spj wagera use karte hain
/////////////////////////
ll construct(){
    fr(i,1,17){
        rep(j,maxn){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

ll lca(ll x, ll y){
    if(depth[x] < depth[y]) swap(x,y);
    repr(i,18){
        if(depth[dp[i][x]] >= depth[y]) x = dp[i][x];
    } 
    if(x == y) return x;
    repr(i,18){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x], y = dp[i][y];
        }
    }
    return dp[0][x];
}