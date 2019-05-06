
const ll maxn = 10005;
ll n,  cur_pos = 0, parent[maxn], parentEdge[maxn], a[maxn], tree[4*maxn], heavy[maxn], depth[maxn], head[maxn], pos[maxn];
vector<pll> adj[maxn];
pll edgeIndex[maxn];



ll dfs(ll s){
    ll sz = 1, high_sz = 0;
    for(auto x: adj[s]){
        ll v_to = x.ff, cost = x.ss;
        if(v_to==parent[s]) continue;
        parent[v_to] = s, parentEdge[v_to] = cost, depth[v_to] = depth[s] + 1;
        ll ch_sz = dfs(v_to);
        sz += ch_sz;
        if(ch_sz > high_sz)
            high_sz = ch_sz, heavy[s] = v_to;
    }
    return sz;
}

ll decompose(ll v, ll h, ll p){
    a[cur_pos] = parentEdge[v];
    head[v] = h, pos[v] = cur_pos++;

    if(heavy[v] != -1) decompose(heavy[v], h, v);
    for(auto x: adj[v]){
        ll v_to = x.ff;
        if(v_to==p || v_to==heavy[v]) continue;
        decompose(v_to,v_to,v);
    }
}

void hdlUtil(){
    fill(heavy, -1);
    cur_pos = 0;
    dfs(0);
    decompose(0,0,-1);
}

void build_seg_tree(ll ind, ll l, ll r){
    if(l == r) {
        tree[ind] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build_seg_tree(ind*2+1, l, mid);
    build_seg_tree(ind*2+2, mid+1, r);
    tree[ind] = max(tree[ind*2+1], tree[ind*2+2]);
}

ll seg_query(ll ind, ll l, ll r, ll ql, ll qr){
    if(ql > qr) 
        return 0;
    if(l == ql && r == qr) return tree[ind];
    ll mid = (l+r)/2;
    ll a = seg_query(ind*2+1, l, mid, ql, min(qr, mid));
    ll b = seg_query(ind*2+2, mid+1, r, max(ql, mid+1), qr);
    return max(a,b);
}

inline ll seg_query(ll a, ll b){
    return seg_query(0, 0, n-1, a, b);
}

void update_seg_tree(ll ind, ll l, ll r, ll pos, ll val){
    if(l == r && l == pos) {
        tree[ind] = val;
        return;
    }
    ll mid = (l+r)/2;
    if(pos <= mid)
        update_seg_tree(ind*2+1, l, mid, pos, val);
    else
        update_seg_tree(ind*2+2, mid+1, r, pos, val);
    tree[ind] = max(tree[ind*2+1], tree[ind*2+2]);
}

ll query(ll l, ll r){
    ll res = -inf;
    while(head[l] != head[r]){
        if(depth[head[l]] > depth[head[r]]) swap(l, r);
        // note that pos[head[r]] < pos[r]
        res = max(res, seg_query(pos[head[r]], pos[r]));
        r = parent[head[r]];
    }
    if(depth[l] > depth[r]) swap(l,r);
    res = max(res, seg_query(pos[l]+1, pos[r]));
    return res;
}


//Inside Main

//for multiple test cases
rep(i,n) {
    adj[i].clear();
}
rep(i,n-1){
    ll x,y,cost;
    cin>>x>>y>>cost; x--; y--;
    edgeIndex[i] = mp(x,y);
    adj[x].pb(mp(y,cost));
    adj[y].pb(mp(x,cost));
}
hdlUtil();
build_seg_tree(0,0,n-1);