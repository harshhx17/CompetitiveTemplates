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



///////////// Kactl waala
struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; } //@harshhx17 - can be used as a typecast from K to H
};

// use KK also if want 2 modulo ------ or can keep C in the struct of HashInterval and then do stuff with only one modulo.



struct HashInterval {
	vector<K> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

C = rng32(); ///// No modulo plzz. keep in HashInterval if much modification is not required. Otherwise can use another modulo.

////////////////////////////////
// Note 1: We can multiply K with H, but not H with K
// Note 2: We can't print K, just use K-0 for anything
// Note 3: Can remove static C, add it to the constructor and then use it for two Hashes.
// Note 4: We can use resize and other stuff with K.