#include <stdio.h>
#include <dlfcn.h>

int main(int argc,char *argv[])
{
    if (argc != 4) {
        printf("Error: no correct param! Example: main 3 5\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    void *lib_handle;
    int (*add)();
    char *error;

    lib_handle = dlopen(argv[3], RTLD_LAZY);
    if (!lib_handle) 
    {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    add = dlsym(lib_handle, "add");

    printf("%d + %d = %d\n", a, b, add(a,b));

    return 0;
}
