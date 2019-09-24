bool prime[maxn];
void sieve() 
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false; 
    for (ll p=2; p*p<maxn; p++) if (prime[p] == true)
        for (ll i=p*2; i<maxn; i += p) 
            prime[i] = false;
}