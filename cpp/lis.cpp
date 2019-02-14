set<ll> s;
ll a[maxn];
ll n;

ll lis(){
    rep(i,n) {
        s.insert(a[i]);
        auto it = s.upper_bound(a[i]);
        if(it != s.end())
            s.erase(it);
    }
    return s.size();
}