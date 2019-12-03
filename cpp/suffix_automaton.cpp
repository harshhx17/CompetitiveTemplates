/**
 * Description: Suffix Automaton
 * Source: https://cp-algorithms.com/string/suffix-automaton.html
 * Verification: https://www.spoj.com/problems/SUBLEX/
 */

 template<int SZ> struct sa {
    struct state {
        int len, link, firstPos;
        map<char, int> next;
    };
    //firstPos is -1 for clones(or not equal to len// don't remember ki iss  template mein kyaa daala tha) and is the first occurence of that substring for others.
    state st[SZ * 2]; 
    int sz, last;
    ll ans[SZ * 2]; // number of distinct substrings from current pos
    vi adjOfLinks[SZ*2];
 
    void extend(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].firstPos = st[cur].len;
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone] = st[q]; st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    
    void init(string s) { 
        st[0].len = 0, st[0].link = -1; sz ++; last = 0; 
        trav(x,s) extend(x); 
    }
    
    ll gen(int x) {
        if (ans[x]) return ans[x];
        ans[x] = 1; trav(y,st[x].next) ans[x] += gen(y.s);
        return ans[x];
    }
 
    void calcAdjOfLinks(){
        rep(i,sz){
          adjOfLinks[st[i].link].pb(i);
        }
    }
 
};

sa<maxn> sa1, sa2;
vi cnt1, cnt2;

void calcCount(vi &cnt, sa<maxn> &s){
	vi ind;
	rep(i,s.sz){
		ind.pb(i);
		if(s.st[i].firstPos != s.st[i].len) cnt.pb(0);
		else cnt.pb(1);
	}
	auto cmp = [&](auto const &a, auto const &b){
		return s.st[a].len > s.st[b].len;
	};
	sort(all(ind), cmp);
	rep(i,ind.size()-1){
		cnt[s.st[ind[i]].link] += cnt[ind[i]];
	}
}

//////////////////////// dacin  waala
struct SuffixAutomaton {
  vector<map<char,int>> next; 
  vector<int> link;            
  vector<int> len;
  vector<int> fPos; // 1 indexing... equal to len for non-cloned states.
  int last;                    

  SuffixAutomaton(string const& s) {
    next.pb(map<char,int>());
    link.pb(-1);
    len.pb(0);
    last = 0;
    fPos.pb(0);
    for(int i=0;i<sz(s);i++) {
      next.pb(map<char,int>());
      len.pb(i+1);
      link.pb(0);
      fPos.pb(len.back());
      int r = next.size() - 1;
      int p = last;
      while(p >= 0 && next[p].find(s[i]) == next[p].end()) {
        next[p][s[i]] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = next[p][s[i]];
        if(len[p] + 1 == len[q]) {
          link[r] = q;
        } else {
          next.pb(next[q]); 
          len.pb(len[p] + 1);
          link.pb(link[q]); 
          fPos.pb(fPos[q]);
          int qq = next.size()-1;
          link[q] = qq;
          link[r] = qq;
          while(p >= 0 && next[p][s[i]] == q) {
            next[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};

void build_adj(SuffixAutomaton sa){
    fr(i,1,sz(sa.link)-1){ // root(0) has parent -1
        adj[sa.link[i]].pb(i);
    }
}