#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    // Ignore SIGKILL and SIGSTOP
    if (signal(SIGKILL, SIG_IGN) == SIG_ERR) {
        perror("CAN't execute CTRL + Z");
	perror("CAN't execute CTRL + Z");
        return 1;
    }
    if (signal(SIGSTOP, SIG_IGN) == SIG_ERR) {
        perror("Unable to ignore SIGSTOP");
        return 1;
    }

    // Handle other signals
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("Unable to set SIGINT handler");
        return 1;
    }
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        perror("Unable to set SIGTERM handler");
        return 1;
    }

    printf("Ignoring SIGKILL and SIGSTOP. Press Ctrl+C to exit.\n");
    while (1) {
        sleep(1);
    }

    return 0;
}

