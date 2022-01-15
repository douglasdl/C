#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h> // uint8_t
#include <assert.h>


// Circular buffer structure
typedef struct circular_buf_t circular_buf_t;

// Handle type for circular buffer API
typedef circular_buf_t* cbuf_handle_t;

// Circular buffer initialization
cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size);

// Free a circular buffer structure (Destroys the buffer)
void circular_buf_free(cbuf_handle_t cbuf);

// Reset a circular buffer structure to empty (head = tail = 0)
void circular_buf_reset(cbuf_handle_t cbuf);

// Put a byte into the circular buffer (old data is overwritten)
void circular_buf_put(cbuf_handle_t cbuf, uint8_t data);

// Put a byte into the circular buffer (rejects new data if buffer is full)
int circular_buf_put2(cbuf_handle_t cbuf, uint8_t data);

// Get a byte from the circular buffer
int circular_buf_get(cbuf_handle_t cbuf, uint8_t * data);

// Check if the circular buffer is empty
bool circular_buf_empty(cbuf_handle_t cbuf);

// Check if the circular buffer is full
bool circular_buf_full(cbuf_handle_t cbuf);

// Get the maximum number of bytes that can be stored in the circular buffer
size_t circular_buf_capacity(cbuf_handle_t cbuf);

// Get the number of bytes stored in the circular buffer
size_t circular_buf_size(cbuf_handle_t cbuf);