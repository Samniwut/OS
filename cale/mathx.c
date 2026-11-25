#include "mathx.h" 
  
unsigned long long factorial(int n) 
{ 
    unsigned long long r = 1; 
  
    for (int i = 2; i <= n; i++) 
        r *= i; 
    return r; 
} 
  
unsigned long long fib(int n) 
{ 
    unsigned long long a = 0, b = 1; 
  
    for (int i = 0; i < n; i++) { 
        unsigned long long t = a + b; 
        a = b; 
        b = t; 
    } 
    return a; 
} 
