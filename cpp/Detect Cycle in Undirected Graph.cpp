// Detects whether an undirected graph contains a cycle or not!
bool DFS(ll source, vector<ll> ed[], ll v, bool visited[], ll parent[])
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

bool detectCycle(vector<ll> ed[], ll v)
{
    bool visited[v+1];
    ll parent[v+1];
    rep(i,v)
    {
        visited[i+1] = {false};
    }
    bool ans = false;
    rep(i,v)
    {
        ll source = i+1;
        parent[source] = source;
        if(!visited[i+1])
            ans = ans | DFS(source,ed,v,visited,parent);
    }
    return ans;
}
