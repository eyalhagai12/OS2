/* cannot be changed
SIGKILL – which kills the process
SIGSTOP – stops a process. Used for breakpoints while
*/
/*
SIGSEGV segmentation fault
SIGFPE for dividing by zero
SIGABRT core dumped for example
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 12

void signal_handler(int signal)
{
    int i=0;
    unsigned int k;
    int *j = malloc(1);
    switch (signal)
    {
    case SIGSEGV:
        printf("seg fault not the real one\n");
        i = 5/i;
        break;
    case SIGFPE:
        printf("don't divide by 0\n");
        free(j);
        free(j);
        break;
    case SIGABRT:
        printf("core was dumped \n");
        if (!fork())
        {
            exit(17);
        }
        wait(NULL);
        break;
    case SIGCHLD: 
        printf("child was killed\n");
        kill(getpid(),SIGTERM);
        break;
    case SIGTERM:
        printf("SIGTERM was generated\n");
        alarm(1);
        sleep(1);
        break;
    
    case SIGALRM:
        printf("SIGALARM was generated\n");
        break;

    default:
        break;
    }
    exit(1);
}

int main()
{
    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGCHLD, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGALRM, signal_handler);
    int *arr;
    arr[5] = 5;
    return 0;
}