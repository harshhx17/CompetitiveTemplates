
struct LiChao_max
{
    struct line
    {
        ll a, b;
        line() { a = 0; b = 0; }
        line(ll _a, ll _b) { a = _a; b = _b; }
        ll eval(ll x) { return a * x + b; }
    };
    struct node
    {
        node *l, *r; line f;
        node() { f = line(); l = NULL; r = NULL; }
        node(ll a, ll b) { f = line(a, b); l = NULL; r = NULL; }
        node(line v) { f = v; l = NULL; r = NULL; }
    };
    typedef node* pnode;
    pnode root; ll sz;
    void init(ll _sz) { sz = _sz + 1; root = NULL; }
    void add_line(ll a, ll b) { line v = line(a, b); insert(v, -sz, sz, root); }
    ll query(ll x) { return query(x, -sz, sz, root); }
    void insert(line &v, ll l, ll r, pnode &nd)
    {
        if(!nd) { nd = new node(v); return; }
        ll trl = nd->f.eval(l), trr = nd->f.eval(r);
        ll vl = v.eval(l), vr = v.eval(r);
        if(trl >= vl && trr >= vr) return;
        if(trl < vl && trr < vr) { nd->f = v; return; }
        ll mid = (l + r) >> 1;
        if(trl < vl) swap(nd->f, v);
        if(nd->f.eval(mid) > v.eval(mid)) insert(v, mid + 1, r, nd->r);
        else swap(nd->f, v), insert(v, l, mid, nd->l);
    }
    ll query(ll x, ll l, ll r, pnode &nd)
    {
        if(!nd) return -inf;
        if(l == r) return nd->f.eval(x);
        ll mid = (l + r) >> 1;
        if(mid >= x) return max(nd->f.eval(x), query(x, l, mid, nd->l));
        return max(nd->f.eval(x), query(x, mid + 1, r, nd->r));
    }
};

//////////////////////
// dyanamic li chao with rollback...
// Submission Link: https://codeforces.com/gym/100377/submission/69772676
/////

struct LiChao
{
    struct line
    {
        ll a, b;
        line() { a = 0; b = 0; }
        line(ll _a, ll _b) { a = _a; b = _b; }
        ll eval(ll x) { return a * x + b; }
    };

    struct node
    {
        node *l, *r; line f;
        node() { f = line(); l = NULL; r = NULL; }
        node(ll a, ll b) { f = line(a, b); l = NULL; r = NULL; }
        node(line v) { f = v; l = NULL; r = NULL; }
    };

    typedef node* pnode;
    pnode root; ll sz;
	stack<vector<pair<pnode*, line>>> roll;
	vector<pair<pnode*, line>> cur;
	bool maxMin; // true for min, false for max

    void init(ll _sz, bool max_min = false) { maxMin = max_min; sz = _sz + 1; root = NULL; }

    void add_line(ll a, ll b) {
		cur = vector<pair<pnode*, line>>();
		if(maxMin) a*=-1, b*=-1;
		line v = line(a, b);
		insert(v, -sz, sz, root); 
		roll.push(cur);
	}

	void rollback(){
		auto lo = roll.top();
		for(auto ch: lo){
			if(ch.ss.a == -INF){
				(*ch.ff) = NULL;
			}
			else{
				(*ch.ff)->f = ch.ss;
			}
		}
		roll.pop();
	}

    ll query(ll x) { 
		int c = maxMin ? -1 : 1;
		return c*query(x, -sz, sz, root);
	}

    void insert(line &v, ll l, ll r, pnode &nd)
    {
        if(!nd) {
			cur.pb(make_pair(&nd, line(-INF, -INF))); 
			nd = new node(v); return; 
		}
        ll trl = nd->f.eval(l), trr = nd->f.eval(r);
        ll vl = v.eval(l), vr = v.eval(r);
        if(trl >= vl && trr >= vr) return;
        if(trl < vl && trr < vr) {
			 cur.pb(make_pair(&nd, nd->f));
			 nd->f = v; 
			 return; 
		}
        ll mid = (l + r) >> 1;
        if(trl < vl){
			cur.pb(make_pair(&nd, nd->f));
			swap(nd->f, v);
		} 
        if(nd->f.eval(mid) > v.eval(mid)) insert(v, mid + 1, r, nd->r);
        else {
			cur.pb(make_pair(&nd, nd->f));
			swap(nd->f, v);
			insert(v, l, mid, nd->l);
		}
    }

    ll query(ll x, ll l, ll r, pnode &nd)
    {
        if(!nd) return -INF;
        if(l == r) return nd->f.eval(x);
        ll mid = (l + r) >> 1;
        if(mid >= x) return max(nd->f.eval(x), query(x, l, mid, nd->l));
        return max(nd->f.eval(x), query(x, mid + 1, r, nd->r));
    }
};