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
