#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)

#define ll long long
#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

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

    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;

        /* For Undirected
        ed[a].push_back(b);
        ed[b].push_back(a);
        */
        
        /* For Directed
        v[a].push_back(b);
        */
    }
}
