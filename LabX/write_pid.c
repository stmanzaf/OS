#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pids.txt", "a");
    if (!file) {
        perror("File opening failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) { // Child
        fprintf(file, "Child PID: %d\n", getpid());
    } else { // Parent
        fprintf(file, "Parent PID: %d\n", getpid());
    }

    fclose(file);
    return 0;
}
