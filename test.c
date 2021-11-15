#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

pthread_mutex_t *m = NULL;

void *test(void *i) {
    int *p = (int *)i;
    pthread_mutex_lock(m);
    printf("start: %d\n", *p);
    usleep(1000000);
    printf("end = %d\n", *p);
    pthread_mutex_unlock(m);
    return (NULL);
}

int main() {
    pthread_t t[2];
    m = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
    pthread_mutex_init(m, NULL);
    for (int i = 0; i < 2; i++) {
        pthread_create(&t[i], NULL, test, (void *)&i);
        pthread_detach(t[i]);
    }
}