rep(i,m){
            cin>>x; cin>>y;
            que.pb(mp(mp(x,y),i));
        }
        auto cmp = [](const auto &a, const auto &b){
            if(a.ff.ff/333 == b.ff.ff/333) return a.ff.ss < b.ff.ss;
            return a.ff.ff < b.ff.ff;
        };
        sort(que.begin(), que.end(), cmp);