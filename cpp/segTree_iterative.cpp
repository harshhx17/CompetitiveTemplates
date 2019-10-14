template<typename T>
struct segTree{
    T idVal;
    int N;
    vector<T> data;

	T combine(const T &a, const T &b){
		return a+b;
	}

	void leafMod(T &a, T const&b){
		a = b; // or add, max, min
	}

    segTree(int N, T idVal): idVal(idVal), N(N) {
        data.resize(2*N);
    }

	//before build add values of index i to data[N+i] from 0 to N
	void build(){
		for(int i=N-1;i>=0;--i){
            data[i]=combine(data[i<<1], data[i<<1|1]);
        }
	}

    void update(int pos, T val){
        for(leafMod(data[pos+=N], val);pos>>=1;){
            data[pos]=combine(data[pos<<1], data[pos<<1|1]);
        }
    }

    // in range [l, r)
    T query(int l, int r){
        T retL=idVal, retR=idVal;
        for(l+=N, r+=N;l<r;l>>=1, r>>=1){
            if(l&1)retL=combine(retL, data[l++]);
            if(r&1)retR=combine(data[--r], retR);
        }
        return combine(retL, retR);
    }
};
