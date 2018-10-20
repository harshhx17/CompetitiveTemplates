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

struct dis_set
{
    int parent;
    int rank;
};

int find(dis_set subset[], int x)
{
    if(subset[x].parent!=x)
        subset[x].parent = find(subset,subset[x].parent);
    return subset[x].parent;
}

void Union(dis_set subset[], int a, int b)
{
    int x = find(subset,a);
    int y = find(subset,b);
    if(x!=y)
    {
        if(subset[x].rank < subset[y].rank)
            subset[x].parent = y;
        else if(subset[x].rank > subset[y].rank)
            subset[y].parent = x;
        else
        {
            subset[x].parent = y;
            subset[y].rank++;
        }
    }
}

bool detectCycle(pair<int, int> edges[], int v, int n)
{
    dis_set subset[v+1];
    rep(i,v)
    {
        subset[i+1].parent = i+1;
        subset[i+1].rank = 0;
    }
    rep(i,n)
    {
        int a = edges[i].ff;
        int b = edges[i].ss;
        int x = find(subset,a);
        int y = find(subset,b);
        if(x==y)
        {
            return true;
        }
        else
            Union(subset,x,y);
    }
    return false;
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
    int n;
    cin >> n;
    vector<int> ed[v+1];
    pair<int, int> edges[n];
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        ed[a].push_back(b);
        ed[b].push_back(a);
        edges[i] = mp(a,b);
    }
    if(detectCycle(edges,v,n))
        cout << "There is a cycle!" << endl;
    else
        cout << "There is no cycle!" << endl;
}
