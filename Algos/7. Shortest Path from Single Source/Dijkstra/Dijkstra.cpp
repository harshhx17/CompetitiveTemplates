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

int findMin(int dist[], bool done[], int v)              // Acts as a priority queue!
                                                         // We can also use map as a priority queue!!
{
    int mini = INF+1;
    int ind = -1;
    rep(i,v)
    {
        if(!done[i+1] && dist[i+1]<mini)
        {
            mini = dist[i+1];
            ind = i+1;
        }
    }
    return ind;
}

void dijkstra(int source, vector<pair<int, int> > ed[], int v, int n)
{
    int dist[v+1];
    bool done[v+1];
    rep(i,v)
    {
        dist[i+1] = INF;
        done[i+1] = false;
    }
    dist[source] = {0};
    rep(i,v)
    {
        int minKey = findMin(dist, done, v);
        rep(j, ed[minKey].size())
        {
            int a = minKey;
            int b = ed[a][j].ff;
            int w = ed[a][j].ss;
            if(!done[b] && dist[a]+w < dist[b])
            {
                dist[b] = dist[a]+w;
            }
        }   
        done[minKey]=true; 
    }
    rep(i,v)
    {
        cout << dist[i+1] << endl;
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
    int source;
    cin >> source;
    dijkstra(source,ed,v,n);
}
