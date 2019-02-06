//For sum in one-dimentional array
struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    void init(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }
    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
    void init(vector<ll> a) {
        init(a.size());
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
};
