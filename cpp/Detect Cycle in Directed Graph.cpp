// Prints whether a directed graph contains a cycle or not!
bool DFS(ll source, vector<ll> ed[], ll v, bool visited[], bool inQueue[])
{
    visited[source] = true;
    inQueue[source] = true;

    bool ans = false;

    rep(i,ed[source].size())
    {
        if(!visited[ed[source][i]])
        {
            ans = ans | DFS(ed[source][i],ed,v,visited,inQueue);
        }
        else if(inQueue[ed[source][i]])
        {
            return true;
        }
    }
    inQueue[source] = false;
    return ans;
}

bool detectCycle(vector<ll> ed[], ll v)
{
    bool visited[v+1];
    bool inQueue[v+1];
    rep(i,v)
    {
        visited[i+1] = {false};
        inQueue[i+1] = {false};
    }
    bool ans = false;
    rep(i,v)
    {
        ll source = i+1;
        if(!visited[i+1])
            ans = ans | DFS(source,ed,v,visited,inQueue);
    }
    return ans;
}
