#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    // fork() 호출 전에 파일을 엶
    // test.txt를 쓰고, 없으면 만들고, 있으면 내용을 지우는 플래그 지정
    int fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    if (fd < 0) {
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {
        exit(1);
    } else if (rc == 0) {
        char *child_msg = "자식스딱스\n";
        write(fd, child_msg, strlen(child_msg));
    } else {
        int skrr = wait(NULL);
        char *parent_msg = "부모스딱스\n";
        write(fd, parent_msg, strlen(parent_msg));
    }

    close(fd);
    return 0;
}