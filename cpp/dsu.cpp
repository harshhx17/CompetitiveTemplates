ll parent[maxn];
ll siz[maxn];

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

//run this for the entire array
void make_set(ll v) {
    parent[v] = v;
    // sizeRank[v] = 0;
    siz[v] = 1;//
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(siz[a] < siz[b])//
        // if (sizeRank[a] < sizeRank[b])
            swap(a, b);
        parent[b] = a;
        // if (sizeRank[a] == sizeRank[b])
            // sizeRank[a]++;
        siz[a] += siz[b];//
    }
}



int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}

void merge(int x,int y){	//	x and y are some tools (vertices)
    if((x = root(x)) == (y = root(y))) return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}