// Description:
// B -> stores the nodes in a bcc
// bcc[u] -> which bcc u is in.
// cmpno -> number of bcc's
// to just get bridges call get_bridge
struct BCC{
    #define N 100005
    vector<int> tree[N], g[N], B[N];
    int U[N], V[N], temp[N], bcc[N], ind[N], T, cmpno, m, n;
    bitset<N> vis, bridge;
    vector<int> Q[N];
    void init(int _n){ n = _n, cmpno = 0, T = 0, m = 0; }
    void reset(int n){
        fr(i, 1, n){
            g[i].clear(), tree[i].clear(), B[i].clear();
            ind[i] = 0;
        }
        bridge.reset();
    }
    int adj(int u,int e){ return U[e] == u ? V[e] : U[e]; }
    void addedge(int u,int v){
        U[m] = u, V[m] = v;
        g[u].pb(m), g[v].pb(m);
        m++;
    }
    void get_bridges(){
        fr(i, 1, n)
            if(!vis[i])
                dfs1(i, -1);
        vis.reset();
    }
    void go(){
        get_bridges();
        fr(i, 1, n)
            if(!vis[i]){
                cmpno++; dfs2(i);
            }
        vis.reset();
    }
    int dfs1(int u,int e){
        vis[u] = 1;
        temp[u] = T++;
        int t = temp[u];
        for(int id: g[u]){
            int v = adj(u, id);
            if(!vis[v]) t = min(t, dfs1(v, id));
            else if(id != e) t = min(t, temp[v]);
        }
        if(t == temp[u] && e != -1) bridge[e] = 1;
        return t;
    }
    void dfs2(int u){
        int cur_cmp = cmpno;
        Q[cur_cmp].pb(u);
        bcc[u] = cur_cmp;
        B[cur_cmp].pb(u);
        vis[u] = 1;
        while(Q[cur_cmp].size() != ind[cur_cmp])
        {
            int u = Q[cur_cmp][ind[cur_cmp]];    
            ind[cur_cmp]++;
            for(int e: g[u])
            {
                int v = adj(u, e);
                if(vis[v]) continue;
                if(bridge[e])
                {
                    cmpno++;
                    tree[cur_cmp].pb(cmpno);
                    tree[cmpno].pb(cur_cmp);
                    dfs2(v);
                }
                else
                {
                    Q[cur_cmp].pb(v);
                    vis[v] = 1;
                    bcc[v] = cur_cmp;
                    B[cur_cmp].pb(v);
                }
            }
        }
    }
    #undef N
}B;

