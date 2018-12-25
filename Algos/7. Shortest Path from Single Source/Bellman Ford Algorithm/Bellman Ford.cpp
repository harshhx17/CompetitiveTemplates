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
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;

#define inf 200000000000000ll
#define mod 1000000007ll

void bellman(int source, vector<pair<int, int> > ed[], int v, int n)
{
    int dist[v+1];
    rep(i,v)
    {
        dist[i+1] = INF;
    }
    dist[source] = 0;
    bool neg_cycle = false;
    rep(i,v-1)                                      // We run it 'k' times, where length of the shortest path has at most 'k' edges! If this k is given then we can replace v-1 with k.
    {
        rep(j,v)
        {
            rep(k, ed[j+1].size())
            {
                int w = ed[j+1][k].ss;
                int b = ed[j+1][k].ff;
                int a = j+1;
                if(dist[a]!=INF && dist[b] > dist[a]+w)    // Relaxing an edge!
                {
                    dist[b] = dist[a]+w;
                }
            }
        }
    }
    rep(j,v)                                     // For finding out which nodes are affected by negative cycle, run the loop again for v-1 times and see which distances got changed!
    {
        rep(k, ed[j+1].size())
        {
            int w = ed[j+1][k].ss;
            int b = ed[j+1][k].ff;
            int a = j+1;
            if(dist[a]!=INF && dist[b] > dist[a]+w)
            {
                neg_cycle = true;
            }
        }
    }
    if(neg_cycle)
        cout << "There is a negative cycle in the graph!" << endl;
    else
    {
        rep(i,v)
        {
            cout << dist[i+1] << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int v;
    cin >> v;
    vector<pair<int, int> > ed[v+1];
    int n;
    cin >> n;
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        int w;
        cin >> w;
        ed[a].push_back(mp(b,w));
    }
    int source;
    cin >> source;
    bellman(source, ed,v,n);
}
