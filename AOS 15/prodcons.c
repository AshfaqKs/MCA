#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 5  // Size of the buffer

int buffer[BUFFER_SIZE];
int in = 0, out = 0;  // `in` points to the next position for producer to insert, `out` for consumer to consume

int empty = BUFFER_SIZE;  // Number of empty slots in the buffer
int full = 0;             // Number of filled slots in the buffer

int mutex = 1;  // Mutex is 1 when it is unlocked, 0 when locked

int produce_item() {
    return rand() % 100;  // Produce a random item between 0 and 99
}

void consume_item(int item) {
    printf("Consumed item: %d\n", item);
}


void wait(int* semaphore) {
    while (*semaphore <= 0);  // Busy-wait 
    (*semaphore)--;  // Decrement the semaphore value
}

void signal(int* semaphore) {
    (*semaphore)++;  // Increment the semaphore value
}

void *producer(void* arg) {
    int item;
    while (1) {
        item = produce_item();  // Produce a new item

        // Simulate wait on 'empty' semaphore (ensure there is space in the buffer)
        wait(&empty);

        // Simulate wait on 'mutex' (enter critical section)
        wait(&mutex);

        // Produce the item and put it in the buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        printf("Produced item: %d\n", item);

        // Simulate signal on 'mutex' (exit critical section)
        signal(&mutex);

        // Simulate signal on 'full' semaphore (inform consumer that an item is available)
        signal(&full);

        sleep(1);  // Simulate the time taken to produce the item
    }
}

void *consumer(void* arg) {
    int item;
    while (1) {
        // Simulate wait on 'full' semaphore (ensure there is something to consume)
        wait(&full);

        // Simulate x);

        // Consume the item from the buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        // Simulate signal on 'mutex' (exit critical section)
        signal(&mutex);

        // Simulate signal on 'empty' semaphore (inform producer that space is available)
        signal(&empty);

        consume_item(item);  // Consume the item
        sleep(2);  // Simulate the time taken to consume the item
    }
}

int main() {

    pthread_t producer_thread, consumer_thread;

    // Create the producer thread
    if (pthread_create(&producer_thread, NULL, producer, NULL)) {
        printf("Error creating producer thread\n");
        return 1;
    }

    // Create the consumer thread
    if (pthread_create(&consumer_thread, NULL, consumer, NULL)) {
        printf("Error creating consumer thread\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    printf("Both producer and consumer have finished.\n");

    return 0;
    
}