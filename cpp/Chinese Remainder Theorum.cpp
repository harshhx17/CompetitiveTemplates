int findMinX(int num[], int rem[], int k) 
{ 
    int prod = 1; 
    for (int i = 0; i < k; i++) 
        prod *= num[i]; 
  
    int result = 0; 
  
    for (int i = 0; i < k; i++) 
    { 
        int pp = prod / num[i]; 
        result += rem[i] * inv(pp, num[i]) * pp; 
    } 
  
    return result % prod; 
} 