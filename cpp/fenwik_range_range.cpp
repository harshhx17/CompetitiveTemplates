const int maxn = 1000005;

vi pro(maxn);
vi sub(maxn);

void add(vi &arr, int pos, int val){
	for(; pos < maxn ; pos += (pos & (-pos))) arr[pos] += val;
}

int quer(vi &arr, int pos){
	int val = 0;
	for(; pos > 0; pos -= pos & -pos) val += arr[pos];
	return val; 
}

void update(int l, int r, int val){
	add(pro, l, val);
	add(pro, r+1, -val);
	add(sub, l, val*(l-1));
	add(sub, r+1, -val*(r));
}

int query(int l, int r){
	int	ans = quer(pro, r)*r - quer(sub, r) - (quer(pro,l-1)*(l-1) - quer(sub, l-1));
	return ans;
}