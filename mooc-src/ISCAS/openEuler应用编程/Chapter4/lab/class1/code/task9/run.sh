gcc -static main9.c -o main_static
gcc main9.c -o main_dynamic
file main_static
file main_dynamic
