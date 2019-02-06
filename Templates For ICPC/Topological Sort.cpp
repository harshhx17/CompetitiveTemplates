void DFS(ll source, vector<ll> ed[], ll v, bool visited[], stack<ll> &s)
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

// In main function
    stack<ll> s;
    bool visited[v+1] = {false};

    rep(i,v)
    {
        if(!visited[i+1])
        {
            DFS(i+1, ed, v, visited, s);
        }
    }

    // Stack s stores the elements in topologically sorted order
    
    
    

