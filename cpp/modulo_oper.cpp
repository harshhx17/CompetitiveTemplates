void mult(int &a, int b){
    a = a*b;
    if(a>MOD) a%=MOD;
}

void add(int &a, int b){
    a = a+b > MOD ? a+b-MOD : a+b;
}

void sub(int &a, int b){
    a = a-b;
    a += a < 0 ? MOD : 0;
}