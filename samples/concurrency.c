#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <semaphore.h>

int count = 0;
void fork_demo() {
    __pid_t pid = fork();
    while (1) {
        printf("Hello, PID is: %d - count is: %d\n", pid, count++);
        sleep(1);
    }
}

void * run_thread(void *thread_num) {
    while (1) {
        printf("Hello, thread %d, count is: %d\n", (int) thread_num, count++);
        sleep(1);
    }
}

void pthread_demo() {

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, run_thread, 1);


    pthread_create(&tid2, NULL, run_thread, 2);
    pthread_join(tid2, NULL);

}

pthread_mutex_t lock;
char buffer[1000];
void * run_thread_char_buff(void *thread_num) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (thread_num == 1) {
            strcpy(buffer, "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman.");
        } else {
            strcpy(buffer, "It is a general popular error to suppose the loudest complainers for the public to be the most anxious for its welfare.");
        }
        printf("Hello, thread %d, buffer is: %s\n", (int) thread_num, buffer);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void locking_demo() {

    pthread_mutex_init(&lock, NULL);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, run_thread_char_buff, 1);

    pthread_create(&tid2, NULL, run_thread_char_buff, 2);
    pthread_join(tid2, NULL);

}

void select_demo() {
    fd_set rfds;
    struct timeval tv;
    int retval;

    /* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    /* Wait up to five seconds. */
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don’t rely on the value of tv now! */

    if (retval == -1)
        perror("select()");
    else if (retval)
        printf("Data is available now.\n");
        /* FD_ISSET(0, &rfds) will be true. */
    else
        printf("No data within five seconds.\n");
}

sem_t semaphore;

void wait_for_sem(int thread) {
    printf("Thread %d - Waiting on the semaphore\n", thread);
    sem_wait(&semaphore);
    printf("Thread %d - Waited on the semaphore\n", thread);
}

void post_to_sem(int thread) {
    printf("Thread %d - Sleeping for a bit\n", thread);
    sleep(3);
    printf("Thread %d - Posting to the semaphore\n", thread);
    sem_post(&semaphore);
    printf("Thread %d - Posted to the semaphore\n", thread);
}

void semaphore_demo() {
    sem_init(&semaphore, 0, 0);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, wait_for_sem, 1);

    pthread_create(&tid2, NULL, post_to_sem, 2);
    pthread_join(tid2, NULL);

    sem_destroy(&semaphore);
}

int main() {

    semaphore_demo();

}

