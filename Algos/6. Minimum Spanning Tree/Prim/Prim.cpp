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
int findMinKey(int arr[], int v, bool mst[])
{
    int mini = INF;
    int ind = -1;
    rep(i, v)
    {
        if(mst[i+1] == false && mini>arr[i+1])
        {
            mini = arr[i+1];
            ind = i+1;
        }
    }
    return ind;
}

void Prim(vector<pair<int, int> > ed[], int v, int n, int arr[], bool mst[])
{
    int parent[v+1];
    parent[1] = -1;
    rep(j,v)
    {
        int x = findMinKey(arr, v, mst);
        mst[x] = true;
        rep(i, ed[x].size())
        {
            int ver = ed[x][i].ff;
            int wei = ed[x][i].ss;
            if(mst[ver] == false && arr[ver] > wei)
            {
                arr[ver] = wei;
                parent[ver] = x;
            }
        }
    }
    rep(i,v)
    {
        if(parent[i+1]!=-1)
        {
            cout << i+1 << "--" << parent[i+1] << endl;
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
        ed[b].push_back(mp(a,w));
    }
    bool mst[v+1] = {false};
    int arr[v+1];
    rep(i,v)
    {
        arr[i+1] = INF;
    }
    arr[1] = 0;
    Prim(ed,v,n,arr,mst);
}
