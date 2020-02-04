https://codeforces.com/contest/613/submission/70209008

auto cmp = [&](auto a, auto b){
                return tin[a] < tin[b];
            };
            sort(all(sp), cmp);
            vi b;
            for(int i=0; i<cnt-1; i++){
                int lc = lca(sp[i], sp[i+1]);
                b.pb(lc);
            }
            for(auto ch: b){
                sp.pb(ch);
            }
            sort(all(sp), cmp);
            sp.resize(unique(all(sp)) - sp.begin());
            stack<int> stac;
            for(auto ch: sp){
                while(!stac.empty() &&  !isAnc(stac.top(), ch)){
                    stac.pop();
                }
                if(!stac.empty()){
                    adj_temp[ch].pb(stac.top());
                    adj_temp[stac.top()].pb(ch);
                }
                stac.push(ch);
            }
