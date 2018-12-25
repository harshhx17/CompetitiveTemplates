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

void Kosaraju(int x, vector<int> rev[], int v, bool visited[])
{
    visited[x]=true;
    cout << x << " ";
    rep(i,rev[x].size())
    {
        if(!visited[rev[x][i]])
        {
            Kosaraju(rev[x][i], rev, v, visited);
        }
    }
}

void DFS(int source, vector<int> ed[], int v, bool visited[], stack<int> &s)
{
    visited[source] = true;
    rep(i, ed[source].size())
    {
        if(!visited[ed[source][i]])
        {
            DFS(ed[source][i], ed, v, visited, s);
        }
    }
    s.push(source);        // The vertex is added to stack only when its DFS is complete
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
    vector<int> rev[v+1];
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;

        rev[b].push_back(a);                      // Stores the transpose graph !
        ed[a].push_back(b);        
    }
    stack<int> s;
    bool visited[v+1] = {false};

    rep(i,v)
    {
        if(!visited[i+1])
        {
            DFS(i+1, ed, v, visited, s);          // Pushes vertices in stack according to their 
                                                  // finishing time of DFS, if vertex 1 finishes 
                                                  // after vertex 2, then 1 is pushed after 2 
                                                  // in stack !
        }
    }

    rep(i,v+1)
    {
        visited[i] = false;
    }
    int num = 0;
    while(s.empty()==false)
    {
        int x = s.top();
        if(visited[x]==false)
        {
            num++;
            cout << "SCC " << num << " -> "; 
            Kosaraju(x,rev,v,visited);           // Does DFS in the order of pops occuring in the 
                                                 // stack to obtain the SCCs !
            cout << endl;
        }
        s.pop();
    }
}
