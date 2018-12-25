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

/*
If we apply Dijkstra’s Single Source shortest path algorithm for every vertex, considering every 
vertex as source, we can find all pair shortest paths in O(V*VLogV) time. So using Dijkstra’s single 
source shortest path seems to be a better option than Floyd Warshell, but the problem with Dijkstra’s 
algorithm is, it doesn’t work for negative weight edge.
The idea of Johnson’s algorithm is to re-weight all edges and make them all positive, then apply 
Dijkstra’s algorithm for every vertex.
*/

int findMin(int dist[], bool done[], int v)         
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

void dijkstra(int source, vector<pair<int, int> > ed[], int v, int n, int dist[])
{
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
}

void bellman(int source, vector<pair<int, int> > ed[], int v, int n, int dist[])
{
    dist[source] = 0;
    rep(i,v)                                      
    {
        rep(j,v+1)
        {
            rep(k, ed[j].size())
            {
                int w = ed[j][k].ss;
                int b = ed[j][k].ff;
                int a = j;
                if(dist[a]!=INF && dist[b] > dist[a]+w)   
                {
                    dist[b] = dist[a]+w;
                }
            }
        }
    }
}

void johnson(vector<pair<int, int> > ed[], int v, int n)
{
	int h[v+1];
	rep(i,v)
	{
		h[i+1] = INF;
	}
	rep(i,v)
	{
		ed[0].push_back(mp(i+1,0));          // New vertex added which has 0 distance from all other vertices
	}
	bellman(0,ed,v,n,h);                     // Bellman-Ford run on the new graph to get the h values
	rep(i,v)
	{
		rep(j, ed[i+1].size())
		{
			ed[i+1][j].ss = ed[i+1][j].ss - h[ed[i+1][j].ff] + h[i+1];    // w = w + h[u] - h[v]
		}
	}
	int ans[v+1][v+1];
	rep(i,v)
	{
		dijkstra(i+1,ed,v,n,ans[i+1]);	
	}
	rep(i,v)
	{
		rep(j,v)
		{
			if(ans[i+1][j+1]!=INF)
				ans[i+1][j+1] = ans[i+1][j+1] + h[j+1] - h[i+1];          // ans = ans - h[u] + h[v]
			cout << ans[i+1][j+1] << " ";
		}
		cout << endl;
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
    int n;
	cin >> n;
	vector<pair<int, int> > ed[v+1];
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

    johnson(ed,v,n);

}
