#include "circular_buffer.h"


// Circular buffer structure
struct circular_buf_t {
    uint8_t* buffer;
    size_t head;
    size_t tail;
    size_t max;
    bool full;
};



// Circular buffer initialization
cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size) {
    assert(buffer && size);
    
    cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));
    assert(cbuf);

    cbuf->buffer = buffer;
    cbuf->max = size;
    
    circular_buf_reset(cbuf);

    assert(circular_buf_empty(cbuf));

    return cbuf;
}


// Reset a circular buffer structure to empty (head = tail = 0)
void circular_buf_reset(cbuf_handle_t cbuf) {
    assert(cbuf);

    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->full = false;
}


// Free a circular buffer structure (Destroys the buffer)
void circular_buf_free(cbuf_handle_t cbuf) {
    assert(cbuf);
    free(cbuf);
}


// Check if the circular buffer is full
bool circular_buf_full(cbuf_handle_t cbuf) {
    assert(cbuf);
    return cbuf->full;
}


// Check if the circular buffer is empty
bool circular_buf_empty(cbuf_handle_t cbuf) {
    assert(cbuf);
    return (!cbuf->full && (cbuf->head == cbuf->tail));
}


// Get the maximum number of bytes that can be stored in the circular buffer
size_t circular_buf_capacity(cbuf_handle_t cbuf) {
    assert(cbuf);
    return cbuf->max;
}


// Get the number of bytes stored in the circular buffer
size_t circular_buf_size(cbuf_handle_t cbuf) {
    assert(cbuf);

    size_t size = cbuf->max;

    if (!cbuf->full) {
        if (cbuf->head >= cbuf->tail) {
            size = (cbuf->head - cbuf->tail);
        } else {
            size = (cbuf->max + cbuf->head - cbuf->tail);
        }
    }

    return size;
}

// MARK: - Private Functions -

// Advance the pointer (Helper function)
static void advance_pointer(cbuf_handle_t cbuf) {
    assert(cbuf);

    if(cbuf->full) {
        if(++(cbuf->tail) == cbuf->max) {
            cbuf->tail = 0;
        }
    }
    
    if(++(cbuf->head) == cbuf->max) {
        cbuf->head = 0;
    }

    cbuf->full = (cbuf->head == cbuf->tail);
}


// Retreat the pointer (Helper function)
static void retreat_pointer(cbuf_handle_t cbuf) {
    assert(cbuf);

    cbuf->full = false;

    if(++(cbuf->tail) == cbuf->max) {
        cbuf->tail = 0;
    }
}


// Put a byte into the circular buffer (old data is overwritten)
void circular_buf_put(cbuf_handle_t cbuf, uint8_t data) {
    assert(cbuf && cbuf->buffer);

    cbuf->buffer[cbuf->head] = data;
    
    advance_pointer(cbuf);
}


// Put a byte into the circular buffer (rejects new data if buffer is full)
int circular_buf_put2(cbuf_handle_t cbuf, uint8_t data) {
    assert(cbuf && cbuf->buffer);

    if(circular_buf_full(cbuf)) {
        return -1;
    }

    circular_buf_put(cbuf, data);
    return 0;
}


// Get a byte from the circular buffer
int circular_buf_get(cbuf_handle_t cbuf, uint8_t * data) {
    assert(cbuf && data && cbuf->buffer);

    if(circular_buf_empty(cbuf)) {
        return -1;
    }

    *data = cbuf->buffer[cbuf->tail];
    retreat_pointer(cbuf);

    return 0;
}

/*
int main(int argc, char *argv[]) {

    // Buffer usage example
    #define BUFFER_SIZE 10
    uint8_t buffer = malloc(BUFFER_SIZE * sizeof(uint8_t));
    cbuf_handle_t cbuf = circular_buf_init(buffer, BUFFER_SIZE);

    bool full = circular_buf_full(cbuf);
    bool empty = circular_buf_empty(cbuf);
    printf("Buffer size: %zu\n", circular_buf_size(cbuf));


    // Make all the readings and writings
    // ...

    // Free memories
    free(buffer);
    circular_buf_free(cbuf);
   

    
    return 0;
}
*/

// gcc -Wall -o ring_buffer ring_buffer3.c
