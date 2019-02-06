#ifndef bhartiya
    // #pragma GCC optimize("Ofast")
    // #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
// not that imp
typedef pair<pll, ll> plll;
typedef vector<ll> vl;
typedef vector<pll> vll;

#define pb push_back
#define bitc  __builtin_popcountl
#define mp make_pair
#define ff first
#define ss second

#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)

#ifdef bhartiya
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
					  cout << "\n\nTime elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
}
#else
#define endl '\n'
#define trace(...)
#define start_routine()
#define end_routine()
#endif

#define inf 200000000000000ll
#define mod 1000000007ll
#define eps 1e-7

ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

const ll maxn = 205;
double dp[maxn][maxn][maxn];
ll p[maxn];
ll a[maxn];

int main() 
{ 
    start_routine();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.precision(10);
    cin.exceptions(cin.failbit);
    #ifdef bhartiya
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        ll n,l,k;
        cin>>n>>l>>k;
        rep(i,n) cin>>p[i];
        rep(i,n) cin>>a[i];
        dp[0][0][k] = 1;
        rep(i,n){
            rep(j,n){
                rep(k,n){
                    dp[i+1][j][k] = (dp[i+1][j][k])*(100-p[i])/100; 
                    if(k+a[i] <= 200)
                        dp[i+1][j+1][k+a[i]] = (dp[i+1][j][k])*(100-p[i])/100; 
                    else{
                        dp[i+1][j+1][200] = (dp[i+1][j][k])*(100-p[i])/100; 
                    }
                }
            }
        }
    }
    end_routine();
}