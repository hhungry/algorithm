/**
* @file 通过共享映射的方式修改文件
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define MMAP_FILE_NAME "a.txt"//指定文件名

void err_exit(const char *err_msg)
{
    printf("error:%s\n", err_msg);
    exit(1);
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("usage:%s text\n", argv[0]);
        exit(1);
    }

    char *mapped;
    struct stat sb;
    int file_fd, text_len;
    long int sys_pagesize;

    if ((file_fd = open(MMAP_FILE_NAME, O_RDWR)) == -1)
        err_exit("open()");
    if((fstat(file_fd,&sb))==-1)
        err_exit("fstat()");

    //mmap函数中指定flag为MAP_PRIVATE,则对映射区域的修改不会写回至文件中
    //指定为MAP_SHARED,则可以通过msync函数同步映射区数据
    mapped = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, file_fd, 0);
    if (mapped == MAP_FAILED)
        err_exit("mmap()");

    /* 原始数据 */
    printf("old text:%s\n", mapped);

    /* 拷贝新数据 */
    text_len = strlen(argv[1]);
    memcpy(mapped, argv[1], text_len);

    /* 同步映射区数据 */
    if (msync((void*)mapped, sb.st_size, MS_SYNC) == -1)
        err_exit("msync()");

    /* 打印新数据 */
    printf("new text:%s\n", mapped);

    /* 解除映射区域 */
    if (munmap(mapped, sb.st_size) == -1)
        err_exit("munmap()");

    return 0;
}
