//String hashing used for patter matching is called rabin karp
//use for multiple p's
ll count_unique_substrings(string const& s) {
    ll n = s.size();

    const ll p = 31;
    const ll m = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (ll i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i]) * p_pow[i]) % m;

    ll cnt = 0;
    for (ll l = 1; l <= n; l++) {
        set<ll> hs;
        for (ll i = 0; i <= n - l; i++) {
            ll cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}