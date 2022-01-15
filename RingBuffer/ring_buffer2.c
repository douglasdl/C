#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Circular Buffer, Ring Buffer, Cyclic Buffer, Circular Queue
// Indexes: Head and Tail, Front and Rear, Write and Read
// typedef struct  {
//     int size;
//     int count;
//     int *pHead;
//     int *pTail;
//     int *pBuffer;
//     bool isFull;
// } RING_BUFFER_T;


// // Init Function
// init_buffer(RING_BUFFER_T *pRingBuffer, int size) {
//     pRingBuffer->size = size;
//     pRingBuffer->count = 0;
//     pRingBuffer->pHead = 0;
//     pRingBuffer->pTail = 0;
//     pRingBuffer->pBuffer = (int *) malloc(size * sizeof(int));
//     pRingBuffer->isFull = 0;
// }

// // Write Function
// write_buffer(RING_BUFFER_T *pRingBuffer, int data) {

//     // Check if buffer is full
//     if(pRingBuffer->count == pRingBuffer->size) {
//         // Bufer is full, new element cannot be added
//         return -1;
//     } else {
//         // Buffer is not full, add element
//         pRingBuffer->pBuffer[pRingBuffer->pHead] = data;
//         //Increment Head Pointer
//         pRingBuffer->pHead ++;
//         // Check if Head Pointer is at the end of the buffer
//         if(pRingBuffer->pHead == pRingBuffer->pTail) {
//             isFull = 1;
//         }


//     }
// }

//typedef enum {false, true} bool;

/**
 * @brief Named Type for a Ring Buffer structure
 */
typedef struct  {
    int capacity;   // Max size of the buffer 
    int size;       // Current size of the buffer
    int *pHead;     // Ring Buffer Head Index. Pop from here (FIFO)
    int *pTail;     // Ring Buffer Tail Index. Push to here (FIFO)
    int buffer[];   // Array of integers to hold the data 
} RING_BUFFER_T ;

// Ring Buffer instance
RING_BUFFER_T myBuffer;



#define BUFFER_SIZE 6;
bool isFull = false;
RING_BUFFER_T *pRingBuffer;


// Functions Declaration
void API_InitBuffer(RING_BUFFER_T *pRingBuffer, char *pBuffer, int size);
void API_WriteToBuffer(RING_BUFFER_T *pRingBuffer, char data);
void API_ReadFromBuffer(RING_BUFFER_T *pRingBuffer, char *data);
bool IsBufferFull(void);
bool IsBufferEmpty(void);


void API_InitBuffer(RING_BUFFER_T *pRingBuffer, char *pBuffer, int size) {
    pRingBuffer->pBuffer = pBuffer;
    pRingBuffer->size = size;
    pRingBuffer->count = 0;
    pRingBuffer->pHead = 0;
    pRingBuffer->pTail = 0;
}




void API_WriteToBuffer(RING_BUFFER_T *pRingBuffer, char data) {
    // Check if buffer is full
    if(IsBufferFull()) {
        // Buffer is full, new element cannot be added
        printf("Buffer is full\n");
    } else {
        // Buffer is not full, add element
        pRingBuffer[pRingBuffer->pHead] = data;
        printf("\nAPI_WriteToBuffer: %d\n", pRingBuffer->pHead);
        //Increment Head Pointer
        pRingBuffer->pHead = (pRingBuffer->pHead + 1) % BUFFER_SIZE;
        // Check if Head Pointer is at the end of the buffer
        if(pRingBuffer->pHead == pRingBuffer->pTail) {
            isFull = true;
        }
    }
}


void API_ReadFromBuffer(RING_BUFFER_T *pRingBuffer, char *data) {
    // Check if the buffer is empty
    if(IsBufferEmpty()) {
        // Buffer is empty, nothing to read
        printf("Buffer is empty\n");
    } else {
        // Buffer is not empty, read element
        *data = *(pRingBuffer->pTail);
        printf("\nAPI_ReadFromBuffer: %d\n", pRingBuffer->pTail);
        //Increment Tail Pointer
        pRingBuffer->pTail = (pRingBuffer->pTail + 1) % BUFFER_SIZE;
        // Check if Tail Pinter is at the start of the buffer
        if(pRingBuffer->pTail == pRingBuffer->pHead) {
            isFull = false;
        }
    }
}


// Is Buffer Full API
bool IsBufferFull(void) {
    return isFull;
}

// Is Buffer Empty API
bool IsBufferEmpty(void) {
    bool temp = false;
    if((pRingBuffer->pHead == pRingBuffer->pTail) && (isFull != true)) {
        temp = true;
    } 
    return temp;
}

// Initialize the buffer
RING_BUFFER_T *new_ring(const int capacity);

// Write to the buffer (push tail)
void ring_push(RING_BUFFER_T *pRingBuffer, int data);

// Read from the buffer (pop head)
int ring_pop(RING_BUFFER_T *pRingBuffer);

// Print the buffer
void ring_print(RING_BUFFER_T *pRingBuffer);




int main() {
    
    

    API_InitBuffer(myBuffer, 6);
    
    // Write to buffer Test
    // API_WriteToBuffer(10);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);
    // API_WriteToBuffer(20);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);
    // API_WriteToBuffer(30);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);
    // API_WriteToBuffer(40);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);
    // API_WriteToBuffer(50);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);
    // API_WriteToBuffer(60);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);

    // API_WriteToBuffer(70);
    // printf("Head: %d Tail: %d isFull: %d\n", Head, Tail, isFull);

    // Read from buffer Test
    API_ReadFromBuffer(myBuffer, &myBuffer->pBuffer[0]);
    printf("Head: %d Tail: %d isFull: %d\n", pRingBuffer->pHead, pRingBuffer->pTail, isFull);

    API_WriteToBuffer(myBuffer, 'A');
    printf("Head: %d Tail: %d isFull: %d\n", pRingBuffer->pHead, pRingBuffer->pTail, isFull);
    API_WriteToBuffer(myBuffer, 'B');
    printf("Head: %d Tail: %d isFull: %d\n", pRingBuffer->pHead, pRingBuffer->pTail, isFull);

    API_ReadFromBuffer(myBuffer, &myBuffer->pBuffer[0]);
    printf("Head: %d Tail: %d isFull: %d\n", pRingBuffer->pHead, pRingBuffer->pTail, isFull);

    return 0;
}

// gcc -Wall -o ring_buffer ring_buffer.c
