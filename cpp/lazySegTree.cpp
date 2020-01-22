// for AP update
const int maxn = 1<<20; //set maxn a power of 2
 
int seg[2*maxn];
pair<int,int> lazy[2*maxn];

//we will always first update lazy and then change the seg by push..
//This means that if lazy is set, it's value is not yet added.
//This is very imp to understand how to initialize the values of lazy ans seg.
void push(int ind, int L, int R) {
    seg[ind] += (R-L+1)*(R-L)*lazy[ind].ss/2 + (R-L+1)*lazy[ind].ff;
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

void pull(int ind) {
    seg[ind] = combine(seg[ind*2], seg[ind*2+1]);
}

//Note that when we use size as power of 2, maxn+i contains the value at node i
void build() { // initialize the values from maxn+i :p
    repr(i,maxn) pull(i);
}

int query(int lo, int hi, int ind = 1, int L = 0, int R = maxn-1) {
    push(ind,L,R);
    if (lo > R || L > hi) return 0; /////Identity element
    if (lo <= L && R <= hi) return seg[ind];
    
    int M = (L+R)/2;
    return combine(query(lo,hi,2*ind,L,M), query(lo,hi,2*ind+1,M+1,R));
}

void upd(int lo, int hi, pii val, int ind = 1, int L = 0, int R = maxn-1) {
    push(ind,L,R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        ///// change lazy according to val
        int st = (L-lo)*val.ss + val.ff;
        lazy[ind].ff += st;
        lazy[ind].ss += val.ss;
        //////
        push(ind,L,R);
        return;
    }
    
    int M = (L+R)/2;
    upd(lo,hi,val,2*ind,L,M); upd(lo,hi,val,2*ind+1,M+1,R);
    pull(ind);
}


///////////////////////////////////
////////////////// Range update & point query
const int maxn = 1<<20; //set maxn a power of 2
 
int seg[2*maxn];

//we will always first update lazy and then change the seg by push..
//This means that if lazy is set, it's value is not yet added.
//This is very imp to understand how to initialize the values of lazy ans seg.
void push(int ind, int L, int R) {
    if (seg[ind] && L != R){
		seg[2*ind] = seg[ind];
		seg[2*ind+1] = seg[ind];
		seg[ind] = 0;
    }
}

int query(int pos, int ind = 1, int L = 0, int R = maxn-1){
    push(ind,L,R);
	if(L == R) return seg[ind];
	int M = (L+R)/2;
	if(pos > M) return query(pos, ind*2+1, M+1, R);
	else return query(pos, ind*2, L, M);
}

void upd(int lo, int hi, int val, int ind = 1, int L = 0, int R = maxn-1) {
    push(ind,L,R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        ///// change seg according to val
		seg[ind] = val;
        return;
    }
    int M = (L+R)/2;
    upd(lo,hi,val,2*ind,L,M); upd(lo,hi,val,2*ind+1,M+1,R);
}