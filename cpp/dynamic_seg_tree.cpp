#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif


typedef int ll;
typedef pair<ll, ll> pll;
typedef gp_hash_table<long long, long long> umap;
// not that imp
typedef pair<pll, ll> plll;
typedef vector<ll> vl;
typedef vector<pll> vll;

#define inf 200000000000000ll
#define mod 1000000007ll
#define eps 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fill(ar,val) memset(ar, val, sizeof(ar))

#ifdef bhartiya
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) {return fabs(a - b) < 1e-9;}
ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

ll n;

struct Node
{
    Node* right;
    Node* left;
    ll val;
    ll lazy;
    Node(ll value){
        right = NULL;
        left = NULL;
        val = value;
        lazy = 0;
    }
};

Node *root;

void init(){
    root = new Node(n);
}

void push(Node* base,ll l,ll r){
    ll mid = (l+r)/2;
    if(base->left == NULL && base->right == NULL){
        base->left = new Node(mid-l+1);
        base->right = new Node(r-mid);
        if(base->lazy == 1){
            base->right->val = 0;
            base->left->val = 0;
            base->right->lazy = 1;
            base->left->lazy = 1;
        }
    }
    else{
        if(base->lazy == 1){
            base->left->val = 0;
            base->left->lazy = 1;
            base->right->val = 0;
            base->right->lazy = 1;
        }
        else if(base->lazy == 2){
            base->left->val = mid-l+1;
            base->right->val = r-mid;
            base->left->lazy = 2; 
            base->right->lazy = 2;
        }
    }
    base->lazy = 0;
}

void update(Node* base, ll l, ll r,  ll ql, ll qr, ll val){
    if(ql>qr) return;
    if(l == ql && r == qr){
        base->lazy = val;
        if(val == 1)
            (*base).val = 0;
        else if(val == 2)
            base->val = qr-ql+1;
    }
    else{
        push(base, l , r);
        ll mid = (l+r)/2;
        update(base->left, l, mid, ql, min(qr,mid), val);
        update(base->right, mid+1, r, max(ql,mid+1), qr, val);
        base->val = base->left->val + base->right->val;
    }
}


int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
    #ifdef bhartiya
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        cin>>n;
        init();
        ll m; cin>>m;
        rep(i,m){
            ll a,b,c; cin>>a>>b>>c; a--; b--;
            update(root,0,n-1,a,b,c);
            cout<<root->val<<endl;
        }
    }
    end_routine();
}