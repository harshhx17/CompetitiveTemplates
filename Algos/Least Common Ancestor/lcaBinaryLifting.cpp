typedef long long ll;
ll n, l;
vector<ll> adj[maxn];

ll timer = 0;
ll tin[maxn], tout[maxn];
ll up[maxLogN][maxn];

void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[0][v] = p;
    for (ll i = 1; i <= l; ++i)
        up[i][v] = up[i-1][up[i-1][v]];

    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancetor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
    if (is_ancetor(u, v))
        return u;
    if (is_ancetor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancetor(up[i][u], v))
            u = up[i][u];
    }
    return up[0][u];
}

void preprocess(ll root) {
    timer = 0;
    l = ceil(log2(n));
    dfs(root, root);
}
//uses binary lifting