ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

void modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) {
        // Modular inverse doesn't exist
        return -1;
    }
    else
    { 
        ll res = (x%m + m) % m; 
        return res;
    } 
} 

//////////When you fking know that it will exist
ll gcdE(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcdE(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll modInverse(ll a, ll m) 
{ 
    ll x, y;
    gcdE(a, m, x, y);
    return (x%m + m) % m; 
} 
