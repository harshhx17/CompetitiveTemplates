// Tested in https://vjudge.net/contest/274564#problem/H
#define rsz(x, n) x.resize(n)
#define clr(x) x.clear()
class SCC
{
public:
  int n, cnt; // cnt -> number of scc's formed
  vector<vector<int>> g, rg, sg, comp; // sg -> dag with all nodes compressed.
  vector<int> scc, order;
  vector<bool> vis;
  void reset(){
    clr(g), clr(rg), clr(sg), clr(comp), clr(scc), clr(order), clr(vis);
  }
  void init(int _n)
  {
    reset();
    n = _n, cnt = 0;
    _n += 2;
    rsz(g, _n), rsz(rg, _n), rsz(sg, _n), rsz(comp, _n);
    scc.resize(_n, 0);
    vis.resize(_n, 0);
  }
  void add(int u,int v){
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  void compute(){
    fr(i, 1, n)
      if(!vis[i]) dfs1(i);
    fill(all(vis), 0);
    for(int i = n - 1; i >= 0; i--)
      if(!vis[order[i]])
        dfs2(order[i],++cnt);
  }
  void dfs1(int u){
    vis[u] = 1;
    for(int v: g[u])
      if(!vis[v]) dfs1(v);
    order.pb(u);
  }
  void dfs2(int u,int c){
    vis[u] = 1;
    scc[u] = c;
    comp[c].pb(u);
    for(int v: rg[u]){
      if(!vis[v])
        dfs2(v,c);
      if(vis[v] && c != scc[v])
        sg[scc[v]].pb(c);
    }
  }
};
class TwoSAT{
public:
    vector<int> ans;
    SCC sc;
    int n;
    void reset(){
        ans.clear(), sc.reset();
    }
    void init(int nn){
        reset();
        n = nn;
        ans.resize(2 * n + 1, -1);
        sc.init(2 * n);
    }
    int NOT(int u){
        return (u <= n) ? u + n : u - n;
    }
    void OR(int u,int v){
        sc.add(NOT(u), v);
        sc.add(NOT(v), u);
    }
    void XOR(int u,int v){
        OR(u, v);
        OR(NOT(u), NOT(v));
    }
    bool solve(){
        sc.compute();
        fr(i, 1, n){
            if(ans[i] == -1){
                if(sc.scc[i] == sc.scc[NOT(i)]) return 0;
                if(sc.scc[i] < sc.scc[NOT(i)]){
                    ans[i] = 0;
                    ans[NOT(i)] = 1;
                }
                else{
                    ans[i] = 1;
                    ans[NOT(i)] = 0;
                }
            }
        }
        return 1;
    }
};
