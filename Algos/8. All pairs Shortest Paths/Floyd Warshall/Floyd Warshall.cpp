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
    int mat[v+1][v+1];                          // Used when there is adjacency matrix representation of the graph!
    rep(i,v)
    {
        rep(j,v)
        {
            mat[i+1][j+1] = INF;
        }
        mat[i+1][i+1] = 0;
    }
    rep(i,n)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        int w;
        cin >> w;
        mat[a][b] = w;
    }
    int dp[v+1][v+1];
    rep(i,v)
    {
        rep(j,v)
        {
            dp[i+1][j+1] = mat[i+1][j+1];                   // dp = mat initially 
        }
    }
    rep(k,v)
    {
        rep(i,v)
        {
            rep(j,v)
            {
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][k+1] + dp[k+1][j+1]);    // main recursion!
            }
        }
    }
    rep(i,v)
    {
        rep(j,v)
        {
            cout << dp[i+1][j+1] << " ";
        }
        cout << endl;
    }
}