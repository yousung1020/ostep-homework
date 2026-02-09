#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 100;
    printf("명령어 실행 전 x의 값: %d (pid: %d)\n", x, (int) getpid());

    int rc = fork();

    if(rc < 0) {
        exit(1);
    } else if (rc == 0) {
        printf("자식 프로세스 초기 x의 값: %d\n", x);
        x = 200;
        printf("자식 프로세스 변경 후 x의 값: %d\n", x);
    } else {
        int skrr = wait(NULL);
        printf("부모 프로세스 초기 x의 값: %d\n", x);
        x = 300;
        printf("부모 프로세스 변경 후 x의 값: %d\n", x);
    }

    return 0;
}