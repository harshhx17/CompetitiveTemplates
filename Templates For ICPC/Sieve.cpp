// Please write the value of MAXN before
bool prime[MAXN];
void sieve() 
{
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 