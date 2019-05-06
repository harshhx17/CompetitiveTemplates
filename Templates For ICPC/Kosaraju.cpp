// This "PRINTS" the strongly connected components of the graph.

void Kosaraju(ll x, vector<ll> rev[], ll v, bool visited[])
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

// In Main
    rep(i,n)
    {
        ll a;
        cin >> a;
        ll b;
        cin >> b;

        rev[b].push_back(a);                      // Stores the transpose graph !
        ed[a].push_back(b);        
    }
    stack<ll> s;
    bool visited[v+1] = {false};

    rep(i,v)
    {
        if(!visited[i+1])
        {
            DFS(i+1, ed, v, visited, s);          
            /** Pushes vertices in stack according to their finishing time of DFS, if vertex 1 finishes after vertex 2, then 1 is pushed after 2 in stack ! */
        }
    }

    rep(i,v+1)
    {
        visited[i] = false;
    }
    ll num = 0;
    while(s.empty()==false)
    {
        ll x = s.top();
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
