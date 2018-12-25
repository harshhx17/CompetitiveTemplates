ll query(ll ind, ll l, ll r, ll ql, ll qr) {
    if (ql > qr)
        return 0;//return inf;
    if (ql == l && qr == r) {
        return tree[ind];
    }
    ll mid = (l + r) / 2;
    return query(ind*2+1, l, mid, ql, min(qr, mid)) + query(ind*2+2, mid+1, r, max(ql, mid+1), qr);
    /* return min(query(ind*2+1, l, mid, ql, min(qr, mid)),
     query(ind*2+2, mid+1, r, max(ql, mid+1), qr));*/
}


void update(ll ind, ll l, ll r, ll pos, ll new_val) {
    if (l == r) {
        tree[ind] = new_val;
    } else {
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(ind*2+1, l, mid, pos, new_val);
        else
            update(ind*2+2, mid+1, r, pos, new_val);
        tree[ind] = tree[ind*2+1] + tree[ind*2+2];
        //tree[ind] = min(tree[ind*2+1], tree[ind*2+2]);
    }
}


void build(ll ind, ll l, ll r) {
    if (l == r) {
        tree[ind] = a[l];
    } else {
        ll mid = (l + r) / 2;
        build(a, ind*2+1, l, mid);
        build(a, ind*2+2, mid+1, r);
        tree[ind] = tree[ind*2+1] + tree[ind*2+2];
        //tree[ind] = min(tree[ind*2+1] + tree[ind*2+2]);
    }
}