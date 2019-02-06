ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll modexp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}