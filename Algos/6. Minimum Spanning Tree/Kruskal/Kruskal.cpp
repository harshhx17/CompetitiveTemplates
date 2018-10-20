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

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct dis_set
{
    int parent;
    int rank;
};

int find(dis_set s[], int i)
{
    if(s[i].parent != i)
        s[i].parent = find(s, s[i].parent);

    return s[i].parent;
}

void Union(int x, int y, dis_set s[])
{
    int xroot = find(s, x);
    int yroot = find(s, y);
    if(s[xroot].rank > s[yroot].rank)
    {
        s[yroot].parent = xroot;
    }
    else if(s[yroot].rank > s[xroot].rank)
    {
        s[xroot].parent = yroot;
    }
    else
    {
        s[xroot].parent = yroot;
        s[yroot].rank++;
    }
}

void Kruskal(pair<int, pair<int, int> > edge[], int n, int v)
{
    sort(edge, edge+n);
    dis_set s[v+1];
    rep(i, v)
    {
        s[i+1].rank = 0;
        s[i+1].parent = i+1;
    }
    int num = 0;
    int x = 0;
    pair<int, int> result[v-1];
    while(num!=v-1)
    {
        int a = edge[x].ss.ff;
        int b = edge[x].ss.ss;
        int y = find(s,a);
        int z = find(s,b);
        if(y!=z)
        {
            result[num] = mp(a,b);
            num++;
            Union(y,z,s);
        }
        x++;
    }
    rep(i,v-1)
    {
        cout << result[i].ff << " " << result[i].ss << endl;
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
    pair<int, pair<int, int> > edge[n];
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        int w;
        cin >> w;
        pair<int, int> p = mp(a,b);
        edge[i] = mp(w,p);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    Kruskal(edge, n, v);
}
