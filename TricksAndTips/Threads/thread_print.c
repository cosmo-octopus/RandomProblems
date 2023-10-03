/* PROBLEM: Create 10 threads, each
taking a unique prime from the primes
array and print it on the screen. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg)
{
    int idx = *(int *)arg;

    printf("%d ", primes[idx]);
    free(arg);
}

int main()
{
    pthread_t   th[10];
    int         i = 0;

    for (i = 0; i < 10; i++)
    {
        int *a = (int *)malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a))
            perror("Failed to create thread");
    }
    for (i = 0; i < 10; i++)
        if (pthread_join(th[i], NULL))
            perror("Failed to join thread");
    printf("\n");
}
