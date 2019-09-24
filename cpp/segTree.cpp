const int maxn = 1ll<<20;

struct node{
    int val, rmax, xco;
    node() {val = rmax =  0, xco = -1; }
    node(int x) : val(x), rmax(x) {}
    node(int x, int xco): val(x), rmax(x), xco(xco) {}
};

node merge(const node &a, const node &b){
    node ans;
    ans = b;
    if(a.rmax + b.val > ans.rmax){
        ans.rmax = (a.rmax + b.val);
        ans.xco = a.xco;
    }
    ans.val = a.val + b.val;
    return ans;
}

void update(node &a, const node &b){
    a.val += b.val;
    a.rmax += b.val;
}

node seg[2*maxn + 10];
node iden;
vector<node> base(maxn+10);

void update(int pos, node val, int ind = 1, int l = 1, int r = maxn){
    if(l == r) {
        update(seg[ind], val);
        // seg[ind] = {val, INF};
    } // update function
    else{
        int mid = (l+r)/2;
        if(pos > mid) update(pos, val, ind*2+1, mid+1, r);
        else update(pos, val, ind*2, l, mid);
        seg[ind] = merge(seg[ind*2], seg[ind*2+1]);
    }
}

node query(int ql, int qr, int ind = 1, int l = 1, int r = maxn){
    if(ql > r || qr < l) return iden;// identity value
    if(ql <= l && qr >= r) return seg[ind];
    int mid = (l+r)/2;
    return merge(query(ql, qr, ind*2, l, mid), query(ql, qr, ind*2+1, mid+1, r));
}

void build(int ind=1, int l=1, int r=maxn){
    if(l==r) seg[ind] = base[l];
    else{
        int mid = (l+r)/2;
        build(ind*2, l, mid);
        build(ind*2+1, mid+1, r);
        seg[ind] = merge(seg[ind*2], seg[ind*2+1]);
    }
}

/// max sum of segment ending at r and the coordinate of left point in xco.. AC
// can do the entire thing with dacin's template too...