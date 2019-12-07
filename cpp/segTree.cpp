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

//problem... its function parameter can match with the other update.
const int maxn = 1ll<<20;
struct node{
    int ind, val;
};

node merge(node a, node b){
    if(a.val < b.val){
		return a;
	}
	else return b;
}

void upd(node &a, int val, int x){
    a.val = val;
	a.ind = x;
}

node seg[2*maxn + 10];
node iden;

void update(int pos, int val, int ind = 1, int l = 0, int r = maxn-1){
    if(l == r) {
        upd(seg[ind], val, pos);
    }
    else{
        int mid = (l+r)/2;
        if(pos > mid) update(pos, val, ind*2+1, mid+1, r);
        else update(pos, val, ind*2, l, mid);
        seg[ind] = merge(seg[ind*2], seg[ind*2+1]);
    }
}

node query(int ql, int qr, int ind = 1, int l = 0, int r = maxn-1){
    if(ql > r || qr < l) return iden;// identity value
    if(ql <= l && qr >= r) return seg[ind];
    int mid = (l+r)/2;
    return merge(query(ql, qr, ind*2, l, mid), query(ql, qr, ind*2+1, mid+1, r));
}

void build() { // initialize the values from maxn+i :p
    repr(i,maxn) seg[i] = merge(seg[i*2], seg[i*2+1]);
}

/// max sum of segment ending at r and the coordinate of left point in xco.. AC
// can do the entire thing with dacin's template too...


/////////////////////
piii query(int sum, int ind = 1, int l = 0, int r = maxn - 1) {
    if (l == r) {
        if (sum >= seg[ind].ff) {
            return {seg[ind], r};
        } else {
            // trace(ind, l, r, l-1, seg[ind]);
            return {{0, 0}, l - 1};
        }
    }
    if (seg[ind].ff <= sum) { return {seg[ind], r}; }
    int mid = (l + r) / 2;
    if (seg[ind * 2].ff > sum) { ////// Not >= as that will not ensure the rightmost index for sum is less
        return query(sum, ind * 2, l, mid);
    } else {
        int val = sum - seg[ind * 2].ff;
        auto res = query(val, ind * 2 + 1, mid + 1, r);
        // assert(sum == (seg[ind*2].ff + res.ff.ff));
        return {{seg[ind * 2].ff + res.ff.ff, res.ff.ss + seg[ind * 2].ss},
                res.ss};
    }
}