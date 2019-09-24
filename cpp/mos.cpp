const int N = 333;

        rep(i,m){
            int x,y;
            cin>>x; cin>>y;
            que.pb(mp(mp(x,y),i));
        }
        auto cmp = [](const auto& a, const auto& b) {
            if (a.ff.ff / N != b.ff.ff / N) return a.ff.ff < b.ff.ff;
            return ((a.ff.ff / N) & 1) ? a.ff.ss > b.ff.ss : a.ff.ss < b.ff.ss;
        };
        sort(que.begin(), que.end(), cmp);