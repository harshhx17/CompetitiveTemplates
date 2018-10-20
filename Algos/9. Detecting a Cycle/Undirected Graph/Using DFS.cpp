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

bool DFS(int source, vector<int> ed[], int v, bool visited[], int parent[])
{
    visited[source] = true;
    bool ans = false;

    rep(i,ed[source].size())
    {
        if(!visited[ed[source][i]])
        {
            parent[ed[source][i]] = source;
            ans = ans | DFS(ed[source][i],ed,v,visited,parent);
        }
        else if(parent[source]!=ed[source][i])
        {
            return true;
        }
    }
    return ans;
}

bool detectCycle(vector<int> ed[], int v)
{
    bool visited[v+1];
    int parent[v+1];
    rep(i,v)
    {
        visited[i+1] = {false};
    }
    bool ans = false;
    rep(i,v)
    {
        int source = i+1;
        parent[source] = source;
        if(!visited[i+1])
            ans = ans | DFS(source,ed,v,visited,parent);
    }
    return ans;
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
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    if(detectCycle(ed,v))
        cout << "There is a cycle!" << endl;
    else
        cout << "There is no cycle!" << endl;
}
