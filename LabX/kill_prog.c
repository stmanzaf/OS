#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Child received signal: %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child
        signal(SIGUSR1, handler);
        pause(); // Wait for signal
    } else { // Parent
        sleep(1);
        kill(pid, SIGUSR1);
        printf("Parent sent signal to child\n");
    }
    return 0;
}
