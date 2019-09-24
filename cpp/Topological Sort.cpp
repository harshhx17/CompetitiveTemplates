ll n; // number of vertices
vector<ll> adj[maxn]; // adjacency list of graph
bool vis[maxn];
stack<ll> s;

void dfs(ll v){
    vis[v] = true;
    for (ll u : adj[v]){
        if (!vis[u])
            dfs(u);
    }
    s.pb(v);
}
//Only for acyclic directed graph
void topological_sort(){
    rep(i,n){
        if (!vis[i]) dfs(i);
    }
}