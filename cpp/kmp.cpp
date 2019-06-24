ll lps[maxn];

bool kmp(string pat, string txt){
    ll i = 0, j=0;
    ll l = txt.length(), m=pat.length();
    while(i<l){
        if(txt[i] == pat[j]){
            i++;
            j++;
            if(j == m){
                j = lps[j-1];
              	cout<<i-m<<"\n";
                //found one
            }
        }
        else if(txt[i] != pat[j]){
            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    return false;
}

void make_lps(string s){
    lps[0] = 0; //Not needed as already initialised
    ll n = s.length();
    ll i = 1;
    ll len = 0;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len == 0){
                lps[i]=0; //Not needed as already initialised
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
}
