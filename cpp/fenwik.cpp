int sum[maxn];

void update(int pos, int val){
	for(pos++; pos<maxn; pos += pos & -pos) sum[pos] += val;
}

int query(int pos){
	int ans = 0;
	for(pos++; pos>0; pos-=pos&-pos) ans += sum[pos];
	return ans;
}

// if range update and point query, add this.
void update(int l, int r, int val){
	update(l, val);
	update(r+1, -val);
}

// find kth element, this method finds the largest number whose sum is less than v and then adds 1, no need to add 1 here as we also have to subtract 1 for the indexing.
int query(int v) {
  int ret = 0;
  for (int i = 13; i >= 0; i--) {
    if (ret + (1<<i) < maxn && sum[ret + (1<<i)] < v)
      ret += (1<<i), v -= sum[ret];
  }
  return ret;
}