#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <utility>
#include <deque>
#include <list>
#include <sstream>
#include <fstream>
#include <complex>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <utility>
#include <iterator>
#include <numeric>
#include <climits>
#include <iomanip>

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
#define INF 1000000

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

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
