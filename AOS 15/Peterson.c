#include <stdio.h>
#include <stdlib.h>

// #include <unistd.h>
// #include <pthread.h>

#define TRUE 1
#define FALSE 0

// Shared variables
int flag[2] = {FALSE, FALSE}; // flag[0] and flag[1] for P0 and P1
int turn;                      // Indicates whose turn it is (0 or 1)

// Critical section function
void critical_section(int process_id) {
    printf("\nProcess %d is in the critical section\n", process_id);
    printf("Performing some process in critical section");
    // sleep(1);  // Simulating some work in the critical section
    printf("\nProcess %d is leaving the critical section\n", process_id);
}

// Peterson's algorithm for mutual exclusion
void peterson(int process_id) {
    int other = 1 - process_id;  // The other process

    // Indicate desire to enter the critical section
    flag[process_id] = TRUE;

    // Set the turn to the other process
    turn = other;

    // Wait until the other process either does not want to enter or it is our turn
    while (flag[other] == TRUE && turn == other) {
        // Busy-waiting
    }

    // Enter the critical section
    critical_section(process_id);

    // Exit the critical section
    flag[process_id] = FALSE;
}

// Function simulating each process
// here arg is taken as void because only void arguments can be used in case of thread creation

// void* process(void* arg) {

//     int process_id = *((int*)arg);  // convertion of void pointer to int

//     // Infinite loop to simulate continuous process execution
//     while (1) {
//         peterson(process_id); // Try to enter the critical section
//     }
//     return NULL;
// }

int main() {

    // pthread_t threads[2];

    int process_ids[2] = {0, 1};

    // creating thread
    // for(int i=0;i<2;i++){
    //     pthread_create(&threads[i], NULL, process ,(void*)&process_ids[i]);
    // }

    // joining thread to ensure main part runs after the exexution of threads
    // for(int i=0;i<2;i++){
    //     pthread_join(threads[i], NULL);
    // }

    //infinite loop to simulate continuous process execution
    while(1){
        for(int i=0;i<2;i++){
            peterson(process_ids[i]);
        }
    }
    return 0;
}
