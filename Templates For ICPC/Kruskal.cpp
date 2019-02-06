// edge[] contains vertex 'a' and then vertex 'b' and weight 'w' in a pair
// n is the number of edges
// v is the number of vertices

void Kruskal(pair<ll, pair<ll, ll> > edge[], ll n, ll v)
{
    sort(edge, edge+n);
    dis_set s[v+1];
    rep(i, v)
    {
        s[i+1].rank = 0;
        s[i+1].parent = i+1;
    }
    ll num = 0;
    ll x = 0;
    pair<ll, ll> result[v-1];
    while(num!=v-1)
    {
        ll a = edge[x].ss.ff;
        ll b = edge[x].ss.ss;
        ll y = find(s,a);
        ll z = find(s,b);
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
