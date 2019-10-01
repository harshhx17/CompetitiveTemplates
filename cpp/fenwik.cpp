
int sum[maxn];

void update(int pos, int val){
	for(;pos<maxn;pos += pos & -pos) sum[pos] += val;
}

int query(int pos){
	int ans = 0;
	for(;pos>0;pos-=pos&-pos) ans += sum[pos];
	return ans;
}

// if range update and point query, add this.
void update(int l, int r, int val){
	update(l, val);
	update(r+1, -val);
}
