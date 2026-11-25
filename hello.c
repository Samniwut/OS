#include <stdio.h> 
#include <unistd.h> 
  
int main(void) 
{ 
    printf("Hello, ENGCE125!\n"); 
    printf("PID = %d, parent PID = %d\n", 
           (int)getpid(), (int)getppid()); 
    return 0; 
} 
