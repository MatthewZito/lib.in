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
