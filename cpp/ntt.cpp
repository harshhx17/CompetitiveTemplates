const ll mod = 7340033;
const ll root = 5;
const ll root_1 = 4404020;
const ll root_pw = 1 << 20;

ll modPow(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll x = modPow(a, b/2);
    x = (x*x)%mod;
    return b&1 ? (x*a)%mod : x;
}


void fft(vector<ll> & a, bool invert) {
    ll n = a.size();

    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (wlen * wlen % mod);

        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (w * wlen % mod);
            }
        }
    }

    if (invert) {
        ll n_1 = modPow(n, mod-2);
        for (ll & x : a)
            x = ( x * n_1 % mod);
    }
}


void multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll x = a.size();
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i]%mod;
    fft(fa, true);

    for (ll i = 0;i<2*x-1; i++)
        cout<<(fa[i]+mod)%mod<<" ";
}



////////////////////
///////////////////
///////////////////
///////////////////// WITH CHINESE REMAINDER THEOREM AND USING TWO MODULUS


ll mod = 65537, mod1 = 65537, mod2 = 163841;
ll root = 9, root1=9, root2=243;
ll root_1 = 7282, root_11 = 7282, root_12 = 47197;
ll root_pw = 1 << 15;
ll inv_mod2, inv_mod1;

ll modPow(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll x = modPow(a, b/2);
    x = (x*x)%mod;
    return b&1 ? (x*a)%mod : x;
}

void fft(vector<ll> & a, bool invert) {
    ll n = a.size();
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (wlen * wlen % mod);

        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (w * wlen % mod);
            }
        }
    }

    if (invert) {
        ll n_1 = modPow(n, mod-2);
        for (ll & x : a)
            x = ( x * n_1 % mod);
    }
}


void multiply(vector<ll> const& a, vector<ll> const& b) {
    mod = mod1, root = root1, root_1 = root_11;
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll x = a.size();
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i]%mod;
    fft(fa, true);
    mod = mod2;
    root = root2;
    root_1 = root_12;
    vector<ll> fa2(a.begin(), a.end()), fb2(b.begin(), b.end());
    fa2.resize(n);
    fb2.resize(n);
    fft(fa2, false);
    fft(fb2, false);
    for (ll i = 0; i < n; i++)
        fa2[i] = fa2[i]*fb2[i]%mod;
    fft(fa2, true);
    for (ll i = 0;i<2*x-1; i++){
        while(fa[i]<0) fa[i] += mod1;
        while(fa2[i]<0) fa2[i] += mod2;
        fa[i] %= mod1;
        fa2[i] %= mod2;
        ll co1 = (mod2*inv_mod2); // coefficient while using chinese remainder theorem
        ll co2 = (mod1*inv_mod1);
        ll ans = ((fa[i]*co1) + (fa2[i]*co2))%(mod1*mod2);
        // trace(fa[i], fa2[i], ans);
        // trace(fa[i] , fa2[i], backup[i]/*, ans */);
        cout<<ans<<" ";
        // cout<<fa[i]<<" ";
    }

}
