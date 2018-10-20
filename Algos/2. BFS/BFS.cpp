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

void BFS(int source, vector<int> ed[], int v, int dist[], int parent[], bool visited[])
{
	queue<int> q;
	q.push(source);
	visited[source] = true;
	parent[source] = -1;
	while(q.empty()==false)
	{
		int x = q.front();
		// cout << x << endl;
		rep(i, ed[x].size())
		{
			if(!visited[ed[x][i]])
			{
				dist[ed[x][i]] = dist[x] + 1;
				parent[ed[x][i]] = x;
				visited[ed[x][i]] = true;
				q.push(ed[x][i]);
			}
		}
		q.pop();
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
            BFS(i+1, ed, v, dist, parent, visited);

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
