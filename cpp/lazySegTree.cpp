void build(ll ind, ll l, ll tr) {
    if (l == tr) {
        stree[ind].set(col[l]);
        // trace(l, ind, stree[ind], col[l], (1<<col[l]));
    } else {
        ll mid = (l + tr) / 2;
        build(ind*2+1, l, mid);
        build(ind*2+2, mid+1, tr);
        stree[ind] = stree[ind*2+1] | stree[ind*2+2];
    }
}

void push(ll ind) {
    if(lazy[ind].none()) return;
        stree[ind*2+1] = lazy[ind];
        lazy[ind*2+1] = lazy[ind];
        stree[ind*2+2] = lazy[ind];
        lazy[ind*2+2] = lazy[ind];
        lazy[ind].reset();
}

void update(ll ind, ll l, ll r, ll ql, ll qr, ll col) {
    if (ql > qr)
        return;
    if (ql == l && qr == r) {
        stree[ind] = bitset<64>(1ll<<col);
        lazy[ind] = stree[ind];
    } else {
        push(ind);
        ll mid = (l + r) / 2;
        update(ind*2+1, l, mid, ql, min(qr, mid), col);
        update(ind*2+2, mid+1, r, max(ql, mid+1), qr, col);
        stree[ind] = stree[ind*2+1] | stree[ind*2+2];
    }
}

bitset<64> query(ll ind, ll l, ll r, ll ql, ll qr) {
    if (ql > qr)
        return (bitset<64>(0));
    if (ql == l && r == qr)
        return stree[ind];
    push(ind);
    ll mid = (l + r) / 2;
    return query(ind*2+1, l, mid, ql, min(qr, mid)) |
               query(ind*2+2, mid+1, r, max(ql, mid+1), qr);
}

////////////////// sum with mod, without build function :p///////////
int lazy[4*maxn];
int stree[4*maxn];
int ans = 0;

void push(ll ind, ll l, ll r) {
	int mid = (l+r)/2;
	int k1 = mid-l+1, k2 = r-mid;
	stree[ind*2+1] = (stree[ind*2+1] + k1*lazy[ind])%mod;
	lazy[ind*2+1] += lazy[ind];
	stree[ind*2+2] =  (stree[ind*2+2] + k2*lazy[ind])%mod;
	lazy[ind*2+2] += lazy[ind];
	lazy[ind] = 0;
}

void update(ll ind, ll l, ll r, ll ql, ll qr, ll val) {
    if (ql > qr)
        return;
    if (ql == l && qr == r) {
        stree[ind] = (val * (r-l+1) + stree[ind])%mod;
        lazy[ind] = (val + lazy[ind])%mod;
    } else {
        push(ind,l,r);
        ll mid = (l + r) / 2;
        update(ind*2+1, l, mid, ql, min(qr, mid), val);
        update(ind*2+2, mid+1, r, max(ql, mid+1), qr, val);
        stree[ind] = (stree[ind*2+1] + stree[ind*2+2])%mod;
    }
}

int query(ll ind, ll l, ll r, ll ql, ll qr) {
    if (ql > qr)
        return 0;
    if (ql == l && r == qr)
        return stree[ind];
    push(ind,l,r);
    ll mid = (l + r) / 2;
    return (query(ind*2+1, l, mid, ql, min(qr, mid)) +
               query(ind*2+2, mid+1, r, max(ql, mid+1), qr))%mod;
}

//////////////////////////////////////

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
        
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};
