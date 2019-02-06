void process()
{
    int i, j; 
    //initialize M for the intervals with length 1
    for (i = 0; i < n; i++)
        hcf[i][0] = a[i];
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= n; j++){
        for (i = 0; i + (1 << j) - 1 < n; i++) {
                hcf[i][j] = gcd(hcf[i + (1 << (j - 1))][j - 1], hcf[i][j - 1]) ;
        }
    }
}

ll query_gcd(ll i, ll j){
    return gcd(hcf[i][(ll)log2(j-i+1)], hcf[j-(1<<(ll)log2(j-i+1))+1][(ll)log2(j-i+1)]);
}

void process_low()
{
    int i, j; 
    //initialize M for the intervals with length 1
    for (i = 0; i < n; i++)
        small[i][0] = a[i];
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= n; j++){
        for (i = 0; i + (1 << j) - 1 < n; i++) {
                small[i][j] = min(small[i + (1 << (j - 1))][j - 1], small[i][j - 1]) ;
        }
    }
}

ll query_low(ll i, ll j){
    return min(small[i][(ll)log2(j-i+1)], small[j-(1<<(ll)log2(j-i+1))+1][(ll)log2(j-i+1)]);
}
