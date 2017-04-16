#include<pthread.h>
#include<iostream>
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_barrier_t barrier;

void* func1(void * arg)
{
    while( *(int *)arg < 10)
    {
        pthread_mutex_lock(&mutex);
        while( *(int *)arg %2 != 0)
            pthread_cond_wait(&cond, &mutex);

        cout<<*(int *)arg<<endl;
        (*(int *)arg)++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    pthread_barrier_wait(&barrier);
}
void* func2(void * arg)
{

    while( *(int *)arg < 10)
    {
        pthread_mutex_lock(&mutex);
        while(*(int *)arg %2 == 0)
            pthread_cond_wait(&cond, &mutex);
        cout<<*(int *)arg<<endl;
        (*(int *)arg)++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

    }
    pthread_barrier_wait(&barrier);
}

int main()
{
    int i = 0;
    pthread_t p1;
    pthread_t p2;
    pthread_barrier_init(&barrier, NULL, 3);
    pthread_create(&p1, NULL, func1, &i);
    pthread_create(&p2, NULL, func2, &i);
    pthread_barrier_wait(&barrier);
    return 0;
}
