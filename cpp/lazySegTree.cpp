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
