#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    if ((fd = open(argv[1], O_RDWR)) < 0)
    {
        err_exit("open");
    }
    /* 获取文件的属性 */
    if ((fstat(fd, &sb)) == -1)
    {
        err_exit("fstat");
    }
    /* 将文件映射至进程的地址空间 */
    /*进程间通信必须指定flag参数为MAP_SHARED，否则对映射区域的写入操作无法写回至文件，则文件内容一直不变*/
    if ((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ |
                               PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1)
    {
        err_exit("mmap");
    }

    /* 映射完后, 关闭文件也可以操纵内存 */
    close(fd);

    printf("%s", mapped);

    /* 修改文件*/
    char replace[]="gogo";
    memcpy(mapped, replace, sizeof(replace));
    if ((msync((void *)mapped, sb.st_size, MS_SYNC)) == -1)
    {
        err_exit("msync");
    }
    /* 释放存储映射区 */
    if ((munmap((void *)mapped, sb.st_size)) == -1)
    {
        err_exit("munmap");
    }
    return 0;
}

