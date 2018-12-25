//for segment addition and query on maximum
void build(ll a[], ll ind, ll l, ll tr) {
    if (l == tr) {
        tree[ind] = a[l];
    } else {
        ll mid = (l + tr) / 2;
        build(a, ind*2+1, l, mid);
        build(a, ind*2+2, mid+1, tr);
        tree[ind] = 0;
    }
}

void push(ll ind) {
    tree[ind*2+1] += lazy[ind];
    lazy[ind*2+1] += lazy[ind];
    tree[ind*2+2] += lazy[ind];
    lazy[ind*2+2] += lazy[ind];
    lazy[ind] = 0;
}

void update(ll ind, ll l, ll r, ll ql, ll qr, ll add) {
    if (ql > qr)
        return;
    if (ql == l && qr == r) {
        tree[ind] += add;
        lazy[ind] += add;
    } else {
        push(ind);
        ll mid = (l + r) / 2;
        update(ind*2+1, l, mid, ql, min(qr, mid), add);
        update(ind*2+2, mid+1, r, max(ql, mid+1), qr, add);
    }
}

ll query(ll ind, ll l, ll r, ll ql, ll qr) {
    if (ql > qr)
        return 0-inf;
    if (ql <= l && r <= qr)// (ql == l && r == qr) I think is better
        return tree[ind];
    push(ind);
    ll mid = (l + r) / 2;
    return max(query(ind*2+1, l, mid, ql, min(qr, mid)), 
               query(ind*2+2, mid+1, r, max(ql, mid+1), qr));
}
