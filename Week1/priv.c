/* priv.c - try a privileged instruction from user mode. 
 * On x86-64, hlt is allowed only in kernel mode, so the CPU raises 
 * a trap; the OS turns it into SIGSEGV for this process. */ 
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
static void handler(int sig) 
{ 
    /* write() is async-signal-safe; printf() is not */ 
    const char msg[] = "caught signal: instruction blocked by CPU\n"; 
    (void)sig; 
    write(STDOUT_FILENO, msg, sizeof msg - 1); 
    _exit(1); 
} 
  
int main(void) 
{ 
    signal(SIGSEGV, handler); 
    printf("executing a privileged instruction...\n"); 
    fflush(stdout); 
#if defined(__x86_64__) || defined(__i386__) 
    __asm__ volatile("hlt"); 
#else 
    printf("(this demo needs an x86 CPU; skipped)\n"); 
#endif 
    printf("this line is never printed on x86\n"); 
    return 0; 
}

