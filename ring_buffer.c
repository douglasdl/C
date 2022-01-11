#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * @brief Named Type for a Ring Buffer structure
 */
typedef struct  {
    int capacity;   // Max size of the buffer 
    int size;       // Current size of the buffer
    int head;       // Ring Buffer Head Index. Pop from here (FIFO)
    int tail;       // Ring Buffer Tail Index. Push to here (FIFO)
    int buffer[];   // Array of integers to hold the data 
} RING_BUFFER_T ;

// Ring Buffer instance
RING_BUFFER_T myBuffer;


// Initialize the buffer
RING_BUFFER_T *new_ring(const int capacity);

// Write to the buffer (push tail)
void ring_push(RING_BUFFER_T *pRingBuffer, int data);

// Read from the buffer (pop head)
int ring_pop(RING_BUFFER_T *pRingBuffer);

// Print the buffer
void ring_print(RING_BUFFER_T *pRingBuffer);



// Create a new ring buffer allocating memory for the buffer
RING_BUFFER_T *new_ring(const int capacity) {
    RING_BUFFER_T *pRingBuffer = malloc(sizeof(RING_BUFFER_T) + sizeof(int) * capacity);

    pRingBuffer->capacity = capacity;
    pRingBuffer->size = 0;
    pRingBuffer->head = 0;
    pRingBuffer->tail = 0;
    // Initialize all items to -1
    memset(pRingBuffer->buffer, -1, capacity);

    return pRingBuffer;
}


// Write to the buffer (push tail)
void ring_push(RING_BUFFER_T *pRingBuffer, int data) {
    if(pRingBuffer->tail == pRingBuffer->head && pRingBuffer->size == pRingBuffer->capacity) {
        pRingBuffer->head = ++ pRingBuffer->head % pRingBuffer->capacity;
    }

    pRingBuffer->buffer[pRingBuffer->tail] = data;
    pRingBuffer->tail = ++ pRingBuffer->tail % pRingBuffer->capacity;

    if(pRingBuffer->size < pRingBuffer->capacity) {
        pRingBuffer->size++;
    }
}


// Read from the buffer (pop head)
int ring_pop(RING_BUFFER_T *pRingBuffer) {
    if(pRingBuffer->size < 1) {
        return -1;
    }

    int data = pRingBuffer->buffer[pRingBuffer->head];
    pRingBuffer->buffer[pRingBuffer->head] = -1;
    pRingBuffer->size--;

    pRingBuffer->head = ++ pRingBuffer->head % pRingBuffer->capacity;

    return data;
}


void ring_print(RING_BUFFER_T *pRingBuffer) {
    if (pRingBuffer->size == 0) {
        fprintf(stdout, "[∅]\n");
    } else {
        fprintf(stdout, "[%d", pRingBuffer->buffer[pRingBuffer->head]);

        int i = (pRingBuffer->head + 1) % pRingBuffer->capacity;
        while(i != pRingBuffer->tail) {

            fprintf(stdout, ", %d", pRingBuffer->buffer[i]);
            i = (i + 1) % pRingBuffer->capacity;
        }
        fprintf(stdout, "]\n");
    }
}


int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: ./ringb <ring-capacity>\n", argv[0]);
        return -1;
    }

    fprintf(stdout, "Ring Buffer Test\n");
    srand(time(NULL)); // Seed the random number generator

    const int capacity = atoi(argv[1]);
    RING_BUFFER_T *pRingBuffer = new_ring(capacity);

    for(int i = 0; i < pRingBuffer->capacity * 5; i++) {
        usleep(3000000);
        if(i % 3 == 0) {
            int popped = ring_pop(pRingBuffer);
            fprintf(stdout, "i: %d, Size: %d, Popped: %d\n", i, pRingBuffer->size, popped);
        } else {
            int rand_int = rand() % 1024;
            ring_push(pRingBuffer, rand_int);
            fprintf(stdout, "i: %d, Size: %d, Pushed: %d\n", i, pRingBuffer->size, rand_int);
        }

        ring_print(pRingBuffer);
    }

    fprintf(stdout, "---------");
    
    return 0;
}

// gcc -Wall -o ring_buffer ring_buffer.c