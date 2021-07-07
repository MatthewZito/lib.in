/**
 * @file ib.c
 * @author Matthew Zito (goldmund@freenode)
 * @brief Input buffer management and ctrl
 * @version 0.1
 * @date 2021-07-06
 *
 * @copyright Copyright (c) 2021 Matthew Zito (goldmund)
 *
 */

#include "libin.h"

/**
 * @brief Initialize and allocate an input buffer; caller expected to invoke `ib_free`
 *
 * @param fd
 * @return InputBuffer*
 */
InputBuffer* ib_init(FILE* fd) {
	InputBuffer* ib = malloc(sizeof(InputBuffer));

	ib->buffer = NULL;
	ib->buffer_size = 0;
	ib->input_size = 0;
	ib->file_descriptor = fd;
}

/**
 * @brief Read user input stream into buffer; returns `NULL` if an error occurs
 *
 * @param ib
 * @return InputBuffer*
 */
InputBuffer* ib_read(InputBuffer* ib) {
	ssize_t bytes;

	if ((bytes = getline(
		&(ib->buffer),
		&(ib->buffer_size),
		ib->file_descriptor
	)) <= 0) {
		return NULL;
	}

	ib->buffer[bytes - 1] = '\0';
	ib->input_size = bytes - 1;

	return ib;
}

/**
 * @brief Deallocate dynamic memory used by an input buffer
 *
 * @param ib
 */
void ib_free(InputBuffer* ib) {
	free(ib->buffer);
	free(ib);
}
