#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// 신호를 받았을 때 실행될 비어있는 함수 (부모를 깨우는 역할)
void sig_handler(int sig) {

}

int main() {
    signal(SIGUSR1, sig_handler);

    int rc = fork();

    if (rc < 0) {
        exit(0);
    } else if (rc == 0) {
        printf("hello\n");
        kill(getpid(), SIGUSR1);
    } else {
        pause();
        printf("goodbye\n");
    }

    return 0;
}