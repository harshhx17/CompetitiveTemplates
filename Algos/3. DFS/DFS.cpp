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

void DFS(int source, vector<int> ed[], int v, int dist[], int parent[], bool visited[])
{
    visited[source] = true;
    // cout << source << endl;
    rep(i, ed[source].size())
    {
        if(!visited[ed[source][i]])
        {
            dist[ed[source][i]] = dist[source]+1;
            parent[ed[source][i]] = source;
            DFS(ed[source][i], ed, v, dist, parent, visited);
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
    vector<int> ed[v+1];
    int n;
    cin >> n;

    int parent[v+1] = {0};
    int dist[v+1] = {0};
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;

        ed[a].push_back(b);
        ed[b].push_back(a);
    }

    bool visited[v+1] = {false};

    rep(i,v)
    {
        if(!visited[i+1])
        {
            parent[i+1] = -1;
            DFS(i+1, ed, v, dist, parent, visited);
        }
    }
    
    // dist[] stores distance from source 
    // parent[] stores parent for each vertex in BFS

    /*
    rep(i,v)
    {
        cout << dist[i+1] << " " << parent[i+1] << " " << endl;
    }
    */
    
}
