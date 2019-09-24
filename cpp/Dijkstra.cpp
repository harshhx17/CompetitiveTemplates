ll n,m;
const ll MAXN = 100005;
vector<pii> adj[MAXN];
ll d[MAXN];
ll p[MAXN];

void dijkstra(ll s) {
    fr(i,0,n+1) d[i] = inf;
    fr(i,0,n+1) p[i] = -1;

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}