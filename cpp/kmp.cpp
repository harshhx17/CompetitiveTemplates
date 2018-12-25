bool kmp(string pat, string txt){
    ll i = 0, j=0;
    ll l = txt.length(), m=pat.length();
    while(i<l){
        if(j == m){
            if(i!=m && i!=l)
                return true;
            else{
                // i++;
                j = a[j-1];
            }
        }
        else if(txt[i] == pat[j]){
            i++;
            j++;
        }
        else if(txt[i] != pat[j]){
            if(j == 0){
                i++;
            }
            else{
                j = a[j-1];
            }
        }
    }
    return false;
}

void make_lps(string s){
    // a[0] = 0;
    ll n = s.length();
    ll i = 1;
    ll len = 0;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            a[i] = len;
            i++;
        }
        else {
            if(len == 0){
                //a[i]=0; Not needed as already initialised
                i++;
            }
            else{
                len = a[len-1];
            }
        }
    }
}