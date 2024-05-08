#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGKILL)
        printf("received SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}

int main(void)
{
    struct sigaction act;
    act.sa_handler = sig_handler;

    // Initialize the signal set to empty
    sigemptyset(&act.sa_mask);

    // Set the flags to 0
    act.sa_flags = 0;

    if (sigaction(SIGUSR1, &act, NULL) < 0)
        printf("\ncan't catch SIGUSR1\n");
    if (sigaction(SIGKILL, &act, NULL) < 0)
        printf("\ncan't catch SIGKILL\n");
    if (sigaction(SIGSTOP, &act, NULL) < 0)
        printf("\ncan't catch SIGSTOP\n");

    // A long long wait so that we can easily issue a signal to this process
    while(1)
        sleep(1);

    return 0;
}
