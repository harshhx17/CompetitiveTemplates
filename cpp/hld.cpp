
// Edge based hld
// for every edge, take the non-parent element as its indicator.
// pos[i] -- position of ith node in segTree
// parentEdge[i] -- weight for the ith node


ll n,  cur_pos = 1, parent[maxn], parentEdge[maxn], a[maxn], heavy[maxn], depth[maxn], head[maxn], pos[maxn];
vector<pii> adj[maxn];
pii edgeIndex[maxn];


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

void decompose(ll v, ll h, ll p){
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
    fil(heavy, -1);
    cur_pos = 1; /// Root Node
    dfs(1); //Root Node
    decompose(1,0,-1); // Root Node
}


ll que(ll l, ll r){
    ll res = -INF; // Iden
    while(head[l] != head[r]){
        if(depth[head[l]] > depth[head[r]]) swap(l, r);
        // note that pos[head[r]] < pos[r]
        res = max(res, query(pos[head[r]], pos[r])); // seg_query, merge function
        r = parent[head[r]];
    }
    if(depth[l] > depth[r]) swap(l,r);
    res = max(res, query(pos[l]+1, pos[r])); // merge function, seg_query
    return res;
}

///Inside main
    fil(seg,0x80); // identity elem
	fil(a, 0x80); // identity elem
	fr(i,1,n+10){
		adj[i].clear();
	}
	fr(i,1,n-1){
		int u,v,c;
		cin>>u>>v>>c;
		edgeIndex[i] = {u,v};
		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}
	hdlUtil();
	fr(i,0,n+10)
		seg[i+maxn] = a[i];
	build();