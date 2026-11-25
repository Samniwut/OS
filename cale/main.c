#include <stdio.h> 
#include <stdlib.h> 
#include "mathx.h" 
  
int main(int argc, char *argv[]) 
{ 
    if (argc != 2) { 
        fprintf(stderr, "usage: %s n\n", argv[0]); 
        return 1; 
    } 
    int n = atoi(argv[1]); 
    printf("%d! = %llu\n", n, factorial(n)); 
    printf("fib(%d) = %llu\n", n, fib(n)); 
    return 0; 
} 
