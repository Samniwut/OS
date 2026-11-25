#include <stdio.h> 
#include <sys/utsname.h> 
#include <unistd.h> 
  
int main(void) 
{ 
    struct utsname u; 
  
    if (uname(&u) == -1) { 
        perror("uname"); 
        return 1; 
    } 
    printf("OS name     : %s\n", u.sysname); 
    printf("Host name   : %s\n", u.nodename); 
    printf("Kernel      : %s\n", u.release); 
    printf("Machine     : %s\n", u.machine); 
    printf("CPUs online : %ld\n", sysconf(_SC_NPROCESSORS_ONLN)); 
    printf("Page size   : %ld bytes\n", sysconf(_SC_PAGESIZE)); 
    return 0; 
} 
