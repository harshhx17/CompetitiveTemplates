/*
V^3 complexity
Can be used for directed graphs
*/

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
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define debug(x) cout<<#x<<": "<<x<<endl;

#define inf 200000000000000ll
#define mod 1000000007ll
 
const ll MAXN = 505;
ll adjMin[MAXN][MAXN];
ll adj[MAXN][MAXN];

int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll x,y,z;
        //initialise adj matrix
        rep(i,n){
            rep(j,n){
                adj[i][j] = inf;
            }
            adj[i][i] = 0;
        }
        //take input edges for undirected graph
        rep(i,m){
            cin>>x>>y>>z;
            x--;y--;
            adj[x][y] = z;
            adj[y][x] = z; //comment out this line for directed graph
        }
        //copy adj to adjMin if you want to preserve adj for some reason
        rep(i,n){
            rep(j,n){
                adjMin[i][j] = adj[i][j];
            }
        }
        //the main loop taking each vertex as intermediate vertex one by one
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        //print the adj matrix
        rep(i,n){
            rep(j,n){
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}