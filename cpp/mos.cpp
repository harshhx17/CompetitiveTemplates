const int N = 333;
        vector<piii> que;
        fr(i,1,m){
            int x,y;
            cin>>x; cin>>y;
            que.pb({{x,y},i});
        }
        auto cmp = [](const auto& a, const auto& b) {
            if (a.ff.ff / N != b.ff.ff / N) return a.ff.ff < b.ff.ff;
            return ((a.ff.ff / N) & 1) ? a.ff.ss > b.ff.ss : a.ff.ss < b.ff.ss;
        };
        sort(all(que), cmp);

        //always expand the range first.