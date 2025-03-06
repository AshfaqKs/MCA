#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_READERS 5
#define MAX_WRITERS 3

int read_count = 0;       // Number of readers currently accessing the resource
int resource = 0;         // Shared resource
int writer_waiting = 0;   // Flag to check if a writer is waiting

void read_resource(int reader_id) {
    printf("Reader %d is reading the resource: %d\n", reader_id, resource);
}

void write_resource(int writer_id) {
    resource++;
    printf("Writer %d is writing to the resource. New value: %d\n", writer_id, resource);
}

void *reader(void *arg) {
    int reader_id = *(int *)arg;
    
    while (1) {
        // Simulate thinking
        sleep(1);

        // Read phase
        if (writer_waiting == 0) {
            read_count++;
            read_resource(reader_id);
            read_count--;

            // Only print once all readers have finished reading
            if (read_count == 0 && writer_waiting > 0) {
                printf("Reader %d finished, notifying waiting writer\n", reader_id);
            }
        }
    }
}

void *writer(void *arg) {
    int writer_id = *(int *)arg;

    while (1) {
        // Simulate thinking
        // sleep(rand() % 2);

        // Wait until no readers are reading
        writer_waiting = 1;
        if (read_count == 0) {
            write_resource(writer_id);
            writer_waiting = 0;
        } else {
            printf("Writer %d is waiting as there are readers reading.\n", writer_id);
        }
    }
}

int main() {
    int readers[MAX_READERS];
    int writers[MAX_WRITERS];

    // Simulate readers and writers
    for (int i = 0; i < MAX_READERS; i++) {
        readers[i] = i + 1;
    }

    for (int i = 0; i < MAX_WRITERS; i++) {
        writers[i] = i + 1;
    }

    for (int i = 0; i < MAX_READERS; i++) {
        reader(&readers[i]); // Reader simulation
    }

    for (int i = 0; i < MAX_WRITERS; i++) {
        writer(&writers[i]); // Writer simulation
    }

    return 0;
}
