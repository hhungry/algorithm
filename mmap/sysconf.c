#include <unistd.h>
#include <stdio.h>
int main()
{
    long pages_of_physical_memory = sysconf(_SC_PHYS_PAGES);
    printf("pages of physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("page size: %ld\n", sysconf(_SC_PAGE_SIZE));
    printf("avaiable pages: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    printf("processors: %ld\n", sysconf(_SC_NPROCESSORS_CONF));
    printf("processors available: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
    return 0;
}
