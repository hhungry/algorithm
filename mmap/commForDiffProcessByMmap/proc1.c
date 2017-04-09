/**
* @file 共享内存实现进程通信
*/

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

void err_exit(const char *err_msg)
{
    printf("error:%s\n", err_msg);
    exit(1);
}

int main(int argc, char **argv)
{
    int fd, nread, i;
    struct stat sb;
    char *mapped;

    /* 打开文件 */
    if ((fd = open(argv[1], O_RDWR)) < 0) {
        err_exit("open");
    }
    /* 获取文件的属性 */
    if ((fstat(fd, &sb)) == -1) {
        err_exit("fstat");
    }
    /* 将文件映射至进程的地址空间 */
    if ((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ |
                    PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1) {
        err_exit("mmap");
    }

    /* 文件已在内存, 关闭文件也可以操纵内存 */
    close(fd);

    /* 每隔两秒查看存储映射区是否被修改 */
    while (1) {
        printf("%s\n", mapped);
        sleep(2);
    }
    return 0;
}
