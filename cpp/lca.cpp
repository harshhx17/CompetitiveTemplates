const maxn = 100005, K;
ll tin[maxn], tout[maxn];
ll up[K+1][maxn];
ll timer = 1;
vector<ll> adj[maxn];


void dfs(ll s, ll p){ // call with root, root (if calling with root, 0... set tout[0] = INF && tin[0] = -1)
    tin[s] = timer++;
    up[0][s] = p;
    fr(i,1,K){
        up[i][s] = up[i-1][up[i-1][s]];
    }
    for(auto ch: adj[s]) if(ch!=p){
        dfs(ch, s);
    }
    tout[s] = timer++;
}

bool isAnc(ll u, ll v){
    return tin[u] < tin[v] && tout[u] > tout[v];
}

int lca(ll u, ll v){
    if(isAnc(u,v)) return u;
    if(isAnc(v,u)) return v;
    frr(i,K,0){
        if(!isAnc(up[i][u], v))
            u = up[i][u];
    }
    return up[0][u];
}


/////////////////////////
//Jo dugar, spj wagera use karte hain
/////////////////////////
int dp[21][maxn];

void construct(){
    fr(i,1,20){
        rep(j,maxn){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

ll lca(ll x, ll y){
    if(depth[x] < depth[y]) swap(x,y);
    repr(i,21)
        if(depth[dp[i][x]] >= depth[y]) x = dp[i][x];
    if(x == y) return x;
    repr(i,21){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x], y = dp[i][y];
        }
    }
    return dp[0][x];
}
