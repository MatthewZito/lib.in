# lib.in

## Dynamic Linking

Linking to `lib.in`:

```bash
# 1) include and use lib.in in your project
# 2) generate object file for your project
gcc -I ../path/to/lib.in -c main.c -o main.o
# 3) generate shared object file
make
# 4) link your project to lib.in
gcc -o main main.o -L../path/to/lib.in -llibin
# you may need to add the lib location to your PATH
```

Linking to `lib.in` on Windows:

```bash
# 1) include and use lib.in in your project
# 2) generate object file for your project
gcc -I ../path/to/lib.in -c main.c -o main.o
# 3) generate shared object file
make win
# 3) link your project to lib.in
gcc -o main.exe main.o -L /path/to/lib.in -llib_in.dll
# you may need to add the lib location to your PATH
```

## API and Documentation

### InputBuffer

Input buffer management and control

#### InputBuffer Structure

Represents an input buffer and associated metadata

```c
typedef struct {
  char* buffer; /* user input buffer */
  size_t buffer_size; /* user input buffer size */
  ssize_t input_size; /* user input size */
  FILE* file_descriptor; /* file stream from which to read user input into buffer */
} InputBuffer;
```

#### ib_init

Initialize and allocate an input buffer; caller expected to invoke `ib_free`

```c
InputBuffer* ib_init(FILE* fd);
```

#### ib_read

Read user input stream into buffer; returns `NULL` if an error occurs

```c
InputBuffer* ib_read(InputBuffer* ib);
```

#### ib_free

Deallocate dynamic memory used by an input buffer

```c
void ib_free(InputBuffer* ib);
```
