ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

ll modPow(ll a, ll b){
    if(b==0) return 1;
    ll x = modPow(a, b/2);
    x = (x*x)%mod;
    return b&1 ? (x*a)%mod : x;
}