#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefds[2];
    pipe(pipefds);
    pid_t pid = fork();

    if (pid == 0) { // Child
        close(pipefds[1]);
        char buffer[100];
        read(pipefds[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefds[0]);
    } else { // Parent
        close(pipefds[0]);
        char message[] = "Hello from Parent";
        write(pipefds[1], message, strlen(message) + 1);
        close(pipefds[1]);
    }
    return 0;
}
