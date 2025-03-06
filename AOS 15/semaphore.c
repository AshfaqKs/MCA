#include <stdio.h>
#include <stdlib.h>

// Semaphore variable for wait() and signal()
int Semaphore = 1;

// Critical section function
void critical_section(int pid) {
    printf("\nProcess %d is in the critical section", pid);
    printf("\nProcess %d is leaving the critical section\n", pid);
}

void wait(int pid){
    if( Semaphore < 1){
        // wait
    }
    else{
        // enter CS
        Semaphore--;
        critical_section(pid);
    }
}

void signal(){
    if( Semaphore < 1 ){
        Semaphore++;
        // leaves CS
    }
}


int main() {

    int pids[2] = {0, 1};

    //infinite loop to simulate continuous process execution
    while(1){
        for(int i=0;i<2;i++){
            wait(pids[i]);
            signal();
        }
    }
    return 0;
}
