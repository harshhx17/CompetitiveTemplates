int fact[maxn], inv[maxn];


void pre(){
    fact[0] = 1;
    fr(i,1,maxn-1){
        fact[i] = i * fact[i-1] % MOD;
    }
    inv[maxn-1] = modpow(fact[maxn-1], MOD-2);
    frr(i,maxn-2,0){
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
}

int nCr(int n, int r){
    if(n<0 || r<0 || r>n) return 0;
    return fact[n] * inv[n-r] % MOD * inv[r] % MOD;
}