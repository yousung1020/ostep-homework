#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        exit(1);
    } else if (rc == 0) {
        printf("자식 프로세스 실행중 (pid: %d)\n", (int) getpid());
        sleep(1); // 1초가 걸리는 작업 중..
        printf("자식스 종료!!\n");
    } else {
        int wc = wait(NULL);
        printf("부모 프로세스: 자식(pid: %d)이 종료됨을 확인 (wait의 반환값: %d)\n", rc, wc);
    }

    return 0;
}