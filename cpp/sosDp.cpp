rep(i, (1<<21)) b[i] = a[i];
rep(i,21) rep(mask, (1<<21)) {
    if(mask & (1<<i)) // if(~mask & (1<<i)) for sum over supersets
        b[mask] += b[mask^(1<<i)];
}

