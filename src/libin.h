#ifndef LIBIN_H
#define LIBIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * @brief Represents an input buffer and associated metadata
 */
typedef struct
{
	char *buffer;					 /* user input buffer */
	size_t buffer_size;		 /* user input buffer size */
	ssize_t input_size;		 /* user input size */
	FILE *file_descriptor; /* file stream from which to read user input into buffer */
} InputBuffer;

InputBuffer *ib_init(FILE *fd);

InputBuffer *ib_read(InputBuffer *ib);

void ib_free(InputBuffer *ib);

#endif
