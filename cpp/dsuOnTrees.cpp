const ll maxn = 100005, maxc = 100005;
ll bigC[maxn];
vector<ll> adj[maxn];
ll cnt[maxc];
ll col[maxn];
ll ans[maxn];
ll maxCount = 0;
ll queryValue = 0;

void inc(ll color, ll add){
    cnt[color] += add;
    if(cnt[color] > maxCount)
        queryValue = color, maxCount = cnt[color];
    else if(cnt[color] == maxCount)
        queryValue += color;
}

ll calcBigC(ll s, ll p){
    ll sum = 1, highC = 0;
    for(auto x: adj[s]){
        if(x==p) continue;
        ll siz = calcBigC(x, s);
        if(siz > highC)
            bigC[s] = x, highC = siz;
        sum += siz;
    }
    return sum;
}

void dfsAdd(ll s, ll p, ll add){
    for(auto x: adj[s]){
        if(x==p) continue;
        dfsAdd(x,s,add);
    }
    inc(col[s], add);
}



void dsuDfs(ll s, ll p, bool keep){
    for(auto x: adj[s]){
        if(x == p || x == bigC[s]) continue;
        dsuDfs(x,s,0);
    }
    if(bigC[s] != -1) dsuDfs(bigC[s], s, 1);
    for(auto x: adj[s]){
        if(x == p || x == bigC[s]) continue;
        dfsAdd(x,s,1);
    }
    inc(col[s], 1);
    /**
     * Answer queries
    */
    ans[s] = queryValue;
    if(!keep){
        dfsAdd(s,p,-1);
        maxCount = 0;
        queryValue = 0;
    }
}


void dsuUtil(){
    rep(i,maxn) bigC[i] = -1;
    calcBigC(0,-1);
    dsuDfs(0,-1,1);
}