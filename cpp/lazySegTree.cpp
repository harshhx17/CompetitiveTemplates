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
const int maxn = 1<<20; //set maxn a power of 2
 
int sum[2*maxn];
pair<int,int> lazy[2*maxn];

//we will always first update lazy and then change the sum by push..
//This means that if lazy is set, it's value is not yet added.
void push(int ind, int L, int R) {
    sum[ind] += (R-L+1)*(R-L)*lazy[ind].ss/2 + (R-L+1)*lazy[ind].ff;
    if (L != R){
        int mid = (R+L)/2;
        lazy[2*ind].ff += lazy[ind].ff;
        lazy[2*ind].ss += lazy[ind].ss;
        lazy[2*ind+1].ff += lazy[ind].ff + (lazy[ind].ss)*(mid-L+1);
        lazy[2*ind+1].ss += lazy[ind].ss;
    }
    lazy[ind] = {0,0};
}


int combine(int val1, int val2){
    return val1 + val2;
}

//need another pull maybe so that queries can also be handeled (sort of combine)
void pull(int ind) {
    sum[ind] = combine(sum[ind*2], sum[ind*2+1]);
}
//Note that when we use size as power of 2, maxn+i contains the value at node i
void build() { // initialize the values from maxn+i :p
    repr(i,maxn) pull(i);
}

int qsum(int lo, int hi, int ind = 1, int L = 0, int R = maxn-1) {
    push(ind,L,R);
    if (lo > R || L > hi) return 0;
    if (lo <= L && R <= hi) return sum[ind];
    
    int M = (L+R)/2;
    ////might need to change this to use pull or combine
    return combine(qsum(lo,hi,2*ind,L,M), qsum(lo,hi,2*ind+1,M+1,R));
}

void upd(int lo, int hi, pii inc, int ind = 1, int L = 0, int R = maxn-1) {
    push(ind,L,R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        ///// change lazy according to inc
        int st = (L-lo)*inc.ss + inc.ff;
        lazy[ind].ff += st;
        lazy[ind].ss += inc.ss;
        push(ind,L,R);
        return;
    }
    
    int M = (L+R)/2;
    upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
    pull(ind);
}
